# wavgat-rotary-encoder
Using wavgat 20 pulse rotary encoder with arduino

There is many different solution to use many different rotary encoder. I choise the WAVGAT Rotary Encoder Module for Arduino Brick Sensor Development Round Audio Rotating Potentiometer Knob Cap EC11. Why? Because its coming in set with everything that need to build in and use.

Product Introduction:
* Operating Voltage: 5V
* Pulse Number for One Circle: 20
* Operating Principle: Incremental encoder is a kind of rotary sensor which transforms the rotation displacement into a series of digital pulse signal. These pulses are used to control angular displacement. In Eltra encoder, the transformation of angular displacement adopts photoelectric scaning principle. The reading system is based on the radial dividing plate's rotation of alternative light window and non-light window, and it will be exposed to infrared light source at the same time. The light will reflect the picture of plate on the surface of receiver. The receiver is covered by a diffraction grating, and it has the same window width with the plate. The operation of receiver is to detect the change of light plate rotation, then transform the light change into electric change. Increase the low level signal into high level and generate square pulse without any interference. 

My code is simple, I do not use interrupt because I will use this encoder in a larger project and I do not need to using it. I just write into the Serial Monitor what happened. Possible events:
* Key push
* Key release
* Knob turn left (CCW)
* Know turn right (CW)

_Connection scheme:_ rotary encoder => Arduino
* GND	=> GND
* 5V =>	VCC / 5V
* S1 =>	any digital PIN (example: 4)
* S2 =>	any digital PIN (example: 3)
* KEY =>	any digital PIN  (example: 2)
