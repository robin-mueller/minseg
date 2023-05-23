# MinSeg Project
Source code for the MiniSeg Real-Time Systems course project of Lund University. 
It enables the MinSeg robot ([Visit website](https://minseg.com/)) to balance itself and to follow translational position setpoints.
Additionally, a graphical user interface to communicate with the robot and to tune the controller is provided.

Have a look at the [wiki](https://github.com/robin-mueller/minseg/wiki) for a detailed explanation of the achievements of this work.

## To everyone working on this project
This repository contains both the controller code and the graphical user interface. If you're an LTH student taking the FRTN01/FRTN60 project course or you're working on stabilizing the MinSeg for another reason, feel free to take the code presented here as a guide. It is worth mentioning that the controller was tested with an internal measurement unit called [MPU9250](https://invensense.tdk.com/products/motion-tracking/9-axis/mpu-9250/). So if your MinSeg comes for instance with a [MPU6050](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/) you will have to use a different approach for reading the sensor values.

The possibility to visualize real-time data and communicate with the Arduino is very useful reagrding the development process. If you've understood how to define a communication interface and how to use the GUI and the Arduino communication API, you can accelerate the development process significantly. So feel encouraged to make use of the user interface during your work.

# Communication
The communication between both instances takes place using Bluetooth and is defined in a global [interface file](interface.json) according to the JSON format.
In case the communication interface needs to be changed, this file needs to be updated.

## Changing the Interface
The C++ communication interface code generation is automated by [this script](controller/src/communication/generate.ps1).
The controller can make use of the updated interface after the code generation.

The GUI reloads the interface definition dynamically on every bootup, so nothing has to be changed manually.

# Controller
The code for the controller is located under [controller](controller) and can be compiled and uploaded to an Arduino (Tested with Arduino Mega 2560).

# GUI
The graphical user interface is built using the Qt framework and its python bindings. The python environment can be 
built using Python 3.10 ([download](https://www.python.org/downloads/)) by 
typing:
```powershell
cd gui  # Source directory should be miniseg/gui!
<Python 3.10 install dir>\python.exe -m venv venv
venv\Scripts\pip.exe install -r requirements.txt
cd ..
```
Before being able to run the GUI for the first time, graphical resources must be generated by running the [resource generation sctipt](gui/resources/generate.ps1).
```powershell
# Make sure to run this in a Windows Powershell terminal!
.\gui\resources\generate.ps1
```
If Windows doesn't allow you to run Powershell scripts, then you might have to set the execution policy according to
```powershell
# Make sure to run this in a Windows Powershell terminal!
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

## Run the GUI
When the above has been followed correctly, the GUI can be run from the repository root by typing
```powershell
# Make sure to run this in a Windows Powershell terminal
# and the current directory is the repo root
.\run.ps1
```
