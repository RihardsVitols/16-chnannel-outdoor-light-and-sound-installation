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
- PureData 64 bit
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

### Starting the system
After installing all the softwares metioned above in the list. We can start the setup process and run the system.

1. Upload Arduino codes:
   - transmitter.ino to the Arduino that has GPS and compos connected
   - receiver.ino to the Arduino that will stay connected to the PC and will recive date from the other one
2. Next, open loopMIDI. In the bottom left bottom corne,r there is a + sign. Click and create 2 instances: pdS and maR.
3. Run the PureData code. In the blue interface named Iteraction, select the Arduino port. If you don't know your port number, click pd plastic-bottle-magic. A new window will appear, click on devices available ports will appear in the terminal window. If everything is connected, you should see i the same blue square numbers changing.
