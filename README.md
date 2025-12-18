# Outdoor 16-channel interactive sound and light installation
The goal was to create a system for an interactive outdoor installation. When a participant grabs an object at the trail entrance, sound and light start to follow him. When this person moves around and looks into the forest, a separate sound recording follows independently of these movements. 

### Overview
parts:
- 2 Arduino Uno
- 2 NRF24L01
- 1 Adafruit Ultimate GPS PA1616S
- 1 GY-271 compass module

software:
- Arduino IDE
- PureData
- loopMIDI
- MIDI-OX
- grandMA3 (or other software that your light artist uses and can receive MIDI)

equipment:
- PC (Windows)
- 16-channel sound interface
- 16 speakers
- DMX light system with 16+ lights
- cables

place for improvement:
- Some parts in PureData code can be optimized and simplified 
- more advanced GPS transmitter for precision

### Electronics
The wiring system is simple and can be seen in the folder [Documentation](https://github.com/RihardsVitols/16-chnannel-outdoor-light-and-sound-installation/tree/main/Documentation).
The code is prepared for particular GPS and compos breakout boards. If you are using different ones, you might need to write your own code. All the codes are in this [folder](https://github.com/RihardsVitols/16-chnannel-outdoor-light-and-sound-installation/tree/main/code).
