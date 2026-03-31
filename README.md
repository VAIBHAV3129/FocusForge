# FocusForge
FocusForge is designed to be a ESP32 powered which basically helps you focus( as in the name itself) it helps users to maintain a state of flow and creates a dedicated environment for deep work.

# Key Features
- It has an integrated VL53L0X ToF Sensor automatically pauses the session if you leave your desk.
- High-quality KY-040 Rotary Encoder to toggle between different focus intensities.
- OLED Display for session progress and an RGB LED Ring that changes color based on focus depth
- Battery-powered via a LiPo cell with integrated TP4056 charging.
Safe Logic: TXS0108E Level Shifter ensures stable communication between 3.3V and 5V components.

# Technical Details
- Microcontroller: ESP32 
- Communication: I2C Bus for display and distance sensing.
- Firmware: Written in C++/Arduino.
- Hardware: Parametric enclosure designed in Onshape.


# Bill of Materials

| Name                         | Purpose                                                       | Quantity |   | Link                                                                                                                                          | Distributor       |
|------------------------------|---------------------------------------------------------------|----------|---|-----------------------------------------------------------------------------------------------------------------------------------------------|-------------------|
| TXS0108E                     | to protect my esp32 from the 5v logic and provide stable 3.3v | 1        |   | https://robu.in/product/txs0108e-high-speed-full-duplex-8-channel-logic-level-converter/                                                      | robu.in           |
| USB to MicroUSB cable        | to develop the esp32                                          | 1        |   | https://robu.in/product/usb-to-micro-usb-cable-wire-1m-for-nodemcu/                                                                           | robu.in           |
| TP4056                       | for charging the battery                                      | 1        |   | https://robu.in/product/tp4056-1a-li-ion-lithium-battery-charging-module-with-current-protection-type-c/                                      | robu.in           |
| KY-040 Rotary Encoder Module | Dial for selecting focus modes                                | 1        |   | https://quartzcomponents.com/products/rotary-encoder-module-ky-040?srsltid=AfmBOopxXBTpBqneVJaEdN7vQ4OiGTnYDaTKpH-wTV9qdaz7HG_W8Mu_           | Quartz Components |
| 1.3" I2C OLED                | for displaying info                                           | 1        |   | https://robu.in/product/128x64-i2c-communication-interface-oled-display/                                                                      | robu.in           |
| LiPo Battery (3.7V)          | to power the device                                           | 1        |   | https://quartzcomponents.com/products/3-7v-10000mah-li-po-rechargeable-battery?_pos=1&_sid=b1bf49bca&_ss=r                                    | Quartz Components |
| ToF Sensor (VL53L0X)         | Presence Detection                                            | 1        |   | https://robu.in/product/vl53l0x-tof-based-lidar-laser-distance-sensor/                                                                        | robu.in           |
| ESP32 Expansion Board 38PIN  | To expand the pins in esp32                                   | 1        |   | https://robu.in/product/esp32-development-board-type-c-micro-usb-esp32-expansion-board-38pin-female-header/                                   | Robu.in           |
| ESP32 Development Board      | Main microcontroller (controls inputs, display, LEDs)         | 1        |   | https://quartzcomponents.com/products/esp32-development-board-wifi-bluetooth?srsltid=AfmBOop5SbXRiRc-WjiRxyPXG12NK5DHwPdszQunlr1lx-TGsmn70tve | Quartz Components |
| Other minor components     | Breadboard, Jumperwires etc for prototyping         | as necessary        |   | 
