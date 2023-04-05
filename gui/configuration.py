from pathlib import Path
from PySide6.QtCore import QObject, Property
from PySide6.QtQml import qmlRegisterSingletonType


class Parameters(QObject):
    @Property(int)
    def refresh_rate_hz(self):
        return 10

    @Property(str)
    def default_recording_dir(self):
        return str(Path.cwd() / "recording")
    

class Theme(QObject):
    @Property(str, constant=True)
    def foreground(self):
        return "#e4e7eb"

    @Property(str, constant=True)
    def dark_foreground(self):
        return "#b9c1Cb"
    
    @Property(str, constant=True)
    def background(self):
        return "#181e25"

    @Property(str, constant=True)
    def border(self):
        return "#505153"

#    @Property(str, constant=True)
#    def primary(self):
#        return "#ffd4a3"

    @Property(str, constant=True)
    def primary(self):
        return "#8cdacc"
    
    
# noinspection PyTypeChecker
qmlRegisterSingletonType(Parameters, "Configuration", 1, 0, "Parameters")
# noinspection PyTypeChecker
qmlRegisterSingletonType(Theme, "Configuration", 1, 0, "Theme")

PARAMETERS = Parameters()
THEME = Theme()


