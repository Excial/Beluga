# Beluga
1. Created a sensor board for Beluga robotics platform
2. Contains PCB, Arduino Code

## Project description
A biosensor designed for microbial auditing, which is mounted onboard an autonomous robot as a payload. The PCB in this sensor helps to initiate helps to reduce the streamline the electronics due to space constraints to initiate the sampling sequence / processes of the biosensor.

### V1
[✓] 3.3V LDO

[✓] 12V Buck Converter

[✓] ESP32 Module 

[✓] Bootloader

[✓] Troubleshooting LEDs

[X] Motor Driver LEDs

  - Too bright, need to increase resistance from 1K to 10K.

[✓] Motor Drivers

[X] Circuit Protection

  - Circuit Protection LED mounted wrongly, refer to schematic.
  - Source and Drain of Mosfet is mounted wrongly, needs to be switched.

[✓] M2 Mounting holes

#### Improvements
1. Add a stepper Motor driver
2. Add a buzzer
3. Add a USB Port
4. Add a FDTI chip
5. Increase Resistance for LEDs from 1k to 10K
	5a. Might Remove the LEDs altogether

### V2




