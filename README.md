# Arduino Morse Code Transmitter

An Arduino-based Morse Code transmitter that converts text into International Morse Code using an LED and buzzer.

## Features

- Converts letters (A–Z) and numbers (0–9) into Morse Code.
- Supports uppercase and lowercase input.
- Uses an LED and buzzer to transmit Morse signals simultaneously.
- Follows standard International Morse Code timing.
- Identifies unsupported characters.
- Accepts text through the Arduino Serial Monitor.

## Hardware Requirements

- Arduino board (e.g. Arduino Uno)
- LED (built-in LED supported)
- Buzzer
- Jumper wires (if using external components)

## Pin Configuration

| Component | Arduino Pin |
|---|---|
| LED | LED_BUILTIN |
| Buzzer | Digital Pin 9 |

## How to Use

1. Connect your buzzer to digital pin 9.
2. Upload the Arduino sketch.
3. Open the Arduino Serial Monitor.
4. Set the baud rate to **9600**.
5. Enter a message and send it using the newline option.
6. Watch and listen as the Arduino translates your message into Morse Code!

## Morse Code Timing

The transmitter uses a basic timing unit of 200 milliseconds.

| Signal | Duration |
|---|---:|
| Dot | 200 ms |
| Dash | 600 ms |
| Gap between symbols | 200 ms |
| Gap between letters | 600 ms |
| Gap between words | 1400 ms |

## Supported Characters

- Letters: A–Z
- Numbers: 0–9
- Spaces between words

Unsupported characters are reported through the Serial Monitor.

## Technologies Used

- C++
- Arduino
- Serial Communication
- International Morse Code

## Future Improvements

- Add support for punctuation.
- Implement non-blocking transmission using `millis()`.
- Add the ability to receive and decode Morse Code.
- Allow adjustable transmission speed.

## License

This project is open-source and available under the MIT License.
