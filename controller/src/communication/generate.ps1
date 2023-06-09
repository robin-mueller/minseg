# This scripts translates the defined communication interfaces to C++ code.
# The generated structs should be used for reading and writing data.
# JsonDocument instances from the ArduinoJson library may only be used for deserialization and serialization.

Set-Location $PSScriptRoot

Write-Output "Running C++ interface code generation ..."

function CalculateJsonDocSize($interfaceDef, $allKeysConstCharPointers)  # Includes the size for storing copies char array values and assumes no deduplication and reading and writing from and to Stream.
{
    $jsonMemberSize = 8  # Size in bytes that is needed by a single member in a json object on an AVR microchip architecture as used in Arduino MEGA
    $size = 0
    foreach ($prop in $interfaceDef.psobject.Properties)
    {
        if ($prop.Value.GetType().Name -eq "String")
        {
            $valueCharSize = 0
            if ($prop.Value -match "(?i)char")
            {
                if ($prop.Value -match "\[(\d+)\]")
                {
                    $valueCharSize = [int]$Matches[1]
                }
                else
                {
                    $valueCharSize = 2  # Single null terminated char
                }
            }
            $size += $valueCharSize
        }
        elseif ($prop.Value.GetType().Name -eq "PSCustomObject")
        {
            $size += CalculateJsonDocSize $prop.Value $allKeysConstCharPointers
        }

        $keyCharSize = $prop.Name.Length + 1  # Word length + null terminal
        if ($allKeysConstCharPointers)
        {
            $keyCharSize = 0
        }
        $size += $keyCharSize + $jsonMemberSize
    }
    return $size
}
function CreateInterfaceStruct($interfaceDef)
{
    $string = ""
    foreach ($prop in $interfaceDef.psobject.Properties)
    {
        if ($prop.Value.GetType().Name -eq "String")
        {
            if ($prop.Value -match "\[(\d+)\]")
            {
                # Type is an array
                $size = [int]$Matches[1]
                $type = ($prop.Value -split "\[")[0]
                $string += "$type $( $prop.Name )[$size];"
            }
            else
            {
                $string += "$( $prop.Value ) $( $prop.Name );"
            }
        }
        elseif ($prop.Value.GetType().Name -eq "PSCustomObject")
        {
            $string += "struct {`n$( CreateInterfaceStruct $prop.Value )} $( $prop.Name );"
        }
        $string += "`n"
    }
    return $string
}
function CreateInterfaceStructFromDoc($interfaceDef)
{
    function AssignStructMember($val, $accessor, [ref]$counter)
    {
        $string = ""
        if ($val.GetType().Name -eq "String")
        {
            if ($val -match "\[(\d+)\]")
            {
                # char arrays must be assigned using strlcpy
                $size = [int]$Matches[1]
                $string += "JsonVariant var$($counter.value) = doc[`"$($accessor.Replace('.', '`"][`"') )`"];`nif (!var$($counter.value).isNull()) strlcpy(this->$accessor, doc[`"$($accessor.Replace('.', '`"][`"') )`"] | `"`", $size);`n"
            }
            else
            {
                $string = "JsonVariant var$($counter.value) = doc[`"$($accessor.Replace('.', '`"][`"') )`"];`nif (!var$($counter.value).isNull()) this->$accessor = var$($counter.value).as<$val>();`n"
            }
        }
        elseif ($val.GetType().Name -eq "PSCustomObject")
        {
            foreach ($prop in $val.psobject.Properties)
            {
                $string += AssignStructMember $prop.Value "$accessor.$( $prop.Name )" $counter
                $counter.value++
            }
        }
        return $string
    }

    $counter = 0
    $string = ""
    foreach ($prop in $interfaceDef.psobject.Properties)
    {
        $string += AssignStructMember $prop.Value $prop.Name ([ref] $counter)
        $counter++
    }
    return $string
}
function CreateInterfaceStructToDoc($interfaceDef)
{
    function AssignDocMember($val, $objName, $accessor, [ref]$counter)
    {
        $key = $accessor.Split(".")[-1]
        $string = ""
        if ($val.GetType().Name -eq "String")
        {
            $string = "$objName[`"$key`"] = this->$accessor;`n"
        }
        elseif ($val.GetType().Name -eq "PSCustomObject")
        {
            $nested_obj_name = "obj$($counter.value)"
            $string = "JsonObject $nested_obj_name = $objName.createNestedObject(`"$key`");`n"
            $counter.value++
            foreach ($prop in $val.psobject.Properties)
            {
                $string += AssignDocMember $prop.Value $nested_obj_name "$accessor.$( $prop.Name )" $counter
            }
        }
        return $string
    }

    $counter = 0
    $string = ""
    foreach ($prop in $interfaceDef.psobject.Properties)
    {
        $string += AssignDocMember $prop.Value "doc" $prop.Name ([ref] $counter)
    }
    return $string
}

$interfaceJsonContentString = Get-Content -Path "..\..\..\interface.json"
$interfaceJsonObject = $interfaceJsonContentString | ConvertFrom-Json

$HPPfileString = "// This file is automatically generated. Any changes will be overwritten.

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <ArduinoJson.h>

#define JSON_DOC_SIZE_RX $( CalculateJsonDocSize $interfaceJsonObject.TO_DEVICE $false )
#define JSON_DOC_SIZE_TX $( CalculateJsonDocSize $interfaceJsonObject.FROM_DEVICE $true )

struct ReceiveInterface {
$( CreateInterfaceStruct $interfaceJsonObject.TO_DEVICE )
void from_doc(StaticJsonDocument<JSON_DOC_SIZE_RX> &doc);
};

struct TransmitInterface {
$( CreateInterfaceStruct $interfaceJsonObject.FROM_DEVICE )
StaticJsonDocument<JSON_DOC_SIZE_TX> to_doc();
};

#endif
"

$CPPfileString = "// This file is automatically generated. Any changes will be overwritten.

#include `"interface.hpp`"

void ReceiveInterface::from_doc(StaticJsonDocument<JSON_DOC_SIZE_RX> &doc) {
$( CreateInterfaceStructFromDoc $interfaceJsonObject.TO_DEVICE )}

StaticJsonDocument<JSON_DOC_SIZE_TX> TransmitInterface::to_doc() {
StaticJsonDocument<JSON_DOC_SIZE_TX> doc;
$( CreateInterfaceStructToDoc $interfaceJsonObject.FROM_DEVICE )
return doc;
}
"

Set-Content -NoNewline -Path "interface.hpp" -Value $HPPfileString
Set-Content -NoNewline -Path "interface.cpp" -Value $CPPfileString

Write-Output "C++ interface code generation finished!"
