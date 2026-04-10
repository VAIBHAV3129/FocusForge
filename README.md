
<img width="700" height="600" alt="FocusForge" src="https://github.com/user-attachments/assets/1ff15a3e-58cb-427a-81d6-03f622fbc2e4" />


# FocusForge
FocusForge is designed to be a ESP32 powered which basically helps you focus( as in the name itself) it helps users to maintain a state of flow and creates a dedicated environment for deep work.

# Key Features
- It has an integrated VL53L0X ToF Sensor automatically pauses the session if you leave your desk.
- High-quality KY-040 Rotary Encoder to toggle between different focus intensities.
- OLED Display for session progress and an that changes color based on focus depth
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




## Wiring 

<img width="1099" height="843" alt="1774971280608-ixl5uo" src="https://github.com/user-attachments/assets/506b9f7b-ab72-4b65-84b7-1d0842e8b58c" />


# Power & Ground 

- 3.3V Rail: Connect the ESP32 3V3 pin to the VCC/VIN pins of the OLED display, the VL53L0X sensor, and the Rotary Encoder.

- Ground Rail: Connect any GND pin on the ESP32 to the GND/COM pins of the OLED, VL53L0X, RGB LED, Buzzer, Rotary Encoder, and the standalone Pushbutton.

# I2C Communication (Shared Bus)

- Data (SDA): Connect ESP32 GPIO 21 to the SDA pin on the OLED and the SDA pin on the VL53L0X sensor.

- Clock (SCL): Connect ESP32 GPIO 22 to the SCL pin on the OLED and the SCL pin on the VL53L0X sensor.

# User Inputs 

- Rotary Clock: Connect ESP32 GPIO 18 to the CLK pin of the encoder.

- Rotary Data: Connect ESP32 GPIO 19 to the DT pin of the encoder.

- Encoder Switch: Connect ESP32 GPIO 4 to the SW pin of the encoder.

- Main Button: Connect ESP32 GPIO 32 to one side of your Pushbutton.

# Feedback System 

- Red Channel: Connect ESP32 GPIO 25 to the Red pin of the RGB LED.

- Green Channel: Connect ESP32 GPIO 26 to the Green pin of the RGB LED.

- Blue Channel: Connect ESP32 GPIO 27 to the Blue pin of the RGB LED.

- Buzzer Alert: Connect ESP32 GPIO 13 to the positive terminal (Pin 2) of the Buzzer.
