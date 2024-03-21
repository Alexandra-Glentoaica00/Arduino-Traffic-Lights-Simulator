==<img width="1195" alt="Screenshot 2024-03-21 at 10 08 51" src="https://github.com/Alexandra-Glentoaica00/Arduino-Traffic-Lights-Simulator/assets/111219179/8bc11524-2839-474f-b9c5-b7c94a82122f">

![5CDF8555-9539-4642-B122-1D1AAAF84E54_1_206_a](https://github.com/Alexandra-Glentoaica00/Arduino-Traffic-Lights-Simulator/assets/111219179/069d7301-995f-4e2d-8d36-bbf4af54c420)

**Components andpplies:**
1 Arduino UNO
1 Breadboard - 830 contacts
7 Resistor 330 Ohm
6 LEDs
1 Push Button
1 Active Buzzer
1 7-Segment Display
1 74HC595 Shift Register
jumper wires (as needed)

**Project Description**
In this project I want to simulate how traffic lights work in an intersection. I built two traffic lights, one for cars and the other for pedestrians. The first traffic light will continue to be green until a pedestrian presses the button. After that, the green color will change to yellow and then red. In that moment, the pedestrian traffic light will switch to green for 7 seconds and yellow for 3 seconds. During this time an audible sound will be emitted to alert people they are allowed to cross.
I used a 7-segment display to show the remaining seconds until the pedestrian light shows red.
Since the Arduino don't have enough I/O pins to connect all these components, I wired the 7-segment display with a 74HC595 shift register in order to use only 3 pins instead of 8.
