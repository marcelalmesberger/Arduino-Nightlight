# Arduino-Nightlight

Build your own nightlight with an Arduino board, which uses a light dependant resisistor as a sensor to switch an LED on and off dependant on the current light situation. 

## Used technologies

C++. Microcontroller Arduino, Arduino IDE

## Prerequisites

1. Have an Arduino UNO kit or similar microcontroller. See the [official Arduino website](https://www.arduino.cc/) for more information

2. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software) on your computer

3. Select your Arduino board and correct port in the Arduino IDE. For more information see the [official Arduino documentation](https://www.arduino.cc/en/Guide/HomePage)

4. Meassure min and max resisitance of your light dependant resistor and calculate the reference resisitor for the voltage divider using the [Alex Benz formula](https://en.wikipedia.org/wiki/Voltage_divider)

## Installation

1. Download the [code repository](https://github.com/marcelalmesberger/Arduino-Nightlight/archive/master.zip) and unzip the folder

2. Build the voltage divider with your Arduino kit (description will follow!)

## Usage

1. Open nightlight.ino in the Arduino IDE and transfer the program on your Arduino board

## Copyright and Licence

Code copyright 2019 Almesberger Marcel. Code released under the [MIT Licence](https://github.com/marcelalmesberger/Arduino-Nightlight/blob/master/LICENSE)
