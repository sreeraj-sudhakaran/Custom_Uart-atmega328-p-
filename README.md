
# UART Code with Internal Voltage & Temperature Information for ATmega328/P (Pure C)

This project demonstrates how to use the UART (Universal Asynchronous Receiver-Transmitter) on the ATmega328/P microcontroller to transmit internal voltage and temperature information over a serial interface. The code includes functions to send integers, floating-point values, and characters to a serial terminal.

## Features:
- **UART Communication**: Configures USART for serial communication at a baud rate of 9600.
- **Transmit Data**: Supports transmitting integers, floating-point numbers, and characters.
- **Internal Temperature**: Provides an example of sending a float (modifiable for sensor data).
- **Voltage**: Can be extended to include voltage readings from ADC.

## Code Overview

### Main Function
- Initializes serial communication using `Serial_begin()`.
- Sends the following data to the serial terminal:
  - An integer: `105`
  - A floating-point number: `12.054`
  - A character: `Q`
  
Each value is separated by a newline character (`0x0A`).

### Custom USART Functions

#### `Serial_begin()`
Sets up USART with the correct baud rate, enabling transmit and receive functionality.

#### `Serial_write(unsigned char data)`
Sends a single byte of data over USART.

#### `Serial_int(unsigned int f_data)`
Converts an integer to a string and transmits it via USART.

#### `Serial_float(float f_data)`
Sends a floating-point number over USART, displaying up to 4 decimal places.

## Hardware Setup
- **Microcontroller**: ATmega328/P
- **Baud Rate**: 9600
- **Pins**: TXD (Pin 3), RXD (Pin 2) for serial communication.

## Requirements
- **AVR Toolchain** for compiling and uploading code to the ATmega328/P.
- **Serial Terminal** (e.g., PuTTY, Arduino Serial Monitor) to view the output.

## How to Use
1. Compile and upload the code to your ATmega328/P using an appropriate programmer (e.g., USBasp).
2. Open a serial terminal (e.g., PuTTY or Arduino Serial Monitor) with the correct COM port and baud rate (9600).
3. After uploading, you should see the following output:
   ```
   105
   12.054
   Q
   ```

## Customization
- Modify the `main()` function to send different values or sensor data.
- Extend the code to send additional information like internal voltage using ADC or other peripherals.
