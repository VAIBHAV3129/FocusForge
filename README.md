# FocusForge
FocusForge is designed to be a ESP32 powered which basically helps you focus( as in the name itself) it helps users to maintain a state of flow and creates a dedicated environment for deep work.

# Key Features
- It has an integrated VL53L0X ToF Sensor automatically pauses the session if you leave your desk.
- High-quality KY-040 Rotary Encoder to toggle between different focus intensities.
- OLED Display for session progress and an RGB LED Ring that changes color based on focus depth
- Battery-powered via a LiPo cell with integrated TP4056 charging.
Safe Logic: TXS0108E Level Shifter ensures stable communication between 3.3V and 5V components.

# Technical Details
- Microcontroller: ESP32 (Dual-core for simultaneous UI and Sensor management).
- Communication: I2C Bus for display and distance sensing.
- Firmware: Written in C++/Arduino (optimized for low power).
- Hardware: Parametric enclosure designed in Onshape.

- 
