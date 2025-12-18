# Outdoor 16-channel interactive sound and light installation
The goal was to create a system for an interactive outdoor installation. When a participant grabs an object at the trail entrance, sound and light start to follow him. When this person moves around and looks into the forest, a separate sound recording follows independently of these movements. 

### Overview
parts:
- 2 Arduino Uno
- 2 NRF24L01
- 1 Adafruit Ultimate GPS PA1616S
- 1 GY-271 compass module

software:
- [Arduino IDE](https://www.arduino.cc/en/software)
- [PureData 64-bit](https://puredata.info/)
- [loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html)
- [MIDI-OX](https://www.midiox.com/)
- [grandMA3](https://www.malighting.com/grandma3/) (or other software that your light artist uses and can receive MIDI)

equipment:
- PC (Windows)
- 16-channel sound interface
- 16 speakers
- DMX light system with 16+ lights
- cables

place for improvement:
- Some parts in PureData code can be optimised and simplified 
- more advanced GPS transmitter for precision

### Electronics
The wiring system is simple and can be seen in the folder [Documentation](https://github.com/RihardsVitols/16-chnannel-outdoor-light-and-sound-installation/tree/main/Documentation).
The code is prepared for particular GPS and compos breakout boards. If you are using different ones, you might need to write your own code. All the codes are in this [folder](https://github.com/RihardsVitols/16-chnannel-outdoor-light-and-sound-installation/tree/main/code).

### Starting the system
After installing all the softwares metioned above in the list. We can start the setup process and run the system.

1. Upload Arduino codes:
   - transmitter.ino to the Arduino that has GPS and compos connected
   - receiver.ino to the Arduino that will stay connected to the PC and will recive date from the other one
2. Next, open loopMIDI. In the bottom left bottom corne,r there is a + sign. Click and create 2 instances: pdS and maR. These will mimic midi signal. pdS will be used in pure data for seding, and maR will be used in grandMA to recive the data.
3. Run the PureData code. In the blue interface named Iteraction, select the Arduino port. If you don't know your port number, click pd plastic-bottle-magic. A new window will appear, click on the devices available ports will appear in the terminal window. If everything is connected, you should see i the same blue square numbers changing.
4. In PureData, open Media->MIDI settings under MIDI Output, select pdS.
5. Run MIDI-OX. Click Options->MIDI Devices. In the input section, select pdS and in the output section maR. You should be able to see data running through in the Monitor windows.
6. Run grandMA. I had a light artist for this and did ot have time to get deep in to it, so my help ends here.

### References
- [NRF24L01](https://www.electronicwings.com/arduino/nrf24l01-interfacing-with-arduino-uno)
- [Adafruit Ultimate GPS PA16165](https://www.circuitbasics.com/how-to-setup-a-gps-sensor-on-the-arduino/)
