from typing import Literal
from PySide6.QtCore import QObject, Qt
from PySide6.QtWidgets import QFrame, QHBoxLayout, QSizePolicy
from application.qml.pybackend import QMLWidgetBackend, QMLProperty, QMLPropertyMeta
        
        
class StatusSection(QMLWidgetBackend):
    SOURCE = "qrc:/qml/application/qml/Status.qml"

    connection_state = QMLProperty(int)
    calibration_state = QMLProperty(int)
    control_switch_state = QMLProperty(bool)
    loaded_param_state = QMLProperty(int)
    param_file_name = QMLProperty(str)
    
    def __init__(self, widget_frame: QFrame, connection_state: Literal[0, 1, 2], calibration_state: Literal[0, 1, 2], control_switch_state: bool, loaded_param_state: Literal[0, 1]):
        super().__init__(widget_frame, self.SOURCE)
        self.connection_state = connection_state
        self.calibration_state = calibration_state
        self.control_switch_state = control_switch_state
        self.loaded_param_state = loaded_param_state
        self.param_file_name = "Nothing Loaded"


class ParameterSection(QObject, metaclass=QMLPropertyMeta):
    SOURCE = "qrc:/qml/application/qml/Parameters.qml"

    # Two signals are used to respect the Qt Quick Property uni-directional implementation.
    loaded = QMLProperty(dict)  # Outgoing
    last_change = QMLProperty(dict)  # Incoming

    def __init__(self, widget_frame: QFrame, **available_parameters: list[str]):
        super().__init__()
        self.groups = {}
        layout = QHBoxLayout(widget_frame)
        layout.setContentsMargins(0, 0, 18, 0)
        layout.setAlignment(Qt.AlignmentFlag.AlignRight)
        layout.setSpacing(25)
        initial_parameters = {key: 0 for key in available_parameters.keys()}
        self.loaded = initial_parameters
        for key, param_names in available_parameters.items():
            frame = QFrame(widget_frame)
            frame.setSizePolicy(QSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Expanding))
            frame.setFrameShape(QFrame.Shape.NoFrame)
            widget = QMLWidgetBackend.create(frame, self.SOURCE, self, title=key, param_names=param_names)
            self.groups[key] = widget
            layout.addWidget(frame)


class SetpointSlider(QMLWidgetBackend):
    SOURCE = "qrc:/qml/application/qml/SetpointSlider.qml"
    value = QMLProperty(int)

    def __init__(self, widget_frame: QFrame, value: int):
        super().__init__(widget_frame, self.SOURCE)
        self.value = value
        
