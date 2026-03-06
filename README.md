# Development of an Automated Switch Valve for a Flow Reactor

## Author
Simon Hein (supervised by Hannah Mehringer)

## Description
This repository contains the software and datasets for an automated 6-port switch valve system used in a flow reactor. The system continuously monitors in-line UV-Vis spectra to automatically separate water from reaction products. Additionally, the scripts allow generating both 2D time-intensity plots and 3D spectral plots for data visualization and analysis. <br>
Valve switching is achieved via a stepper motor controlled by an Arduino UNO Q. The Arduino signals to an A4988 motor driver, which regulates the motor’s rotation with precise angular steps.

## Structure
- `code/` contains jupyter notebooks used for analysis and monitoring, and contains Arduino code
- `data/` contains data sets from two test series
- `results/` ...... 

## Usage
### Arduino Code
Upload the `code/Motor_Control.ino` sketch to the Arduino UNO Q once.
### Monitoring
1. Ensure that one spectrum per second is recorded and that the spectrum is saved as a txt-file in monitored folder.
2. Connect Arduino with computer.
3. Connect Arduino with driver and stepper motor.
4. Run `code/Automated_Motor_Switching.ipynb` to start real-time monitoring of UV-Vis spectra.
5. The script automatically triggers motor actuation when a defined threshold is crossed.

## Installation and Requirements
Python version: 3.14.0

### Python Packages
- matplotlib: 3.10.7
- numpy: 2.3.5
- pandas: 2.3.3
- plotly: 6.5.0
- pyserial: 3.5
- watchdog: 6.0.0

### System Requirements
Code was written and executed on a MacBook Pro.
- CPU: Intel Core i5
- Graphics: Intel Iris Graphics
- macOS: 26.3
- Memory: 16 GB
- Serial number: C02DDDPYML7H
  
### Software Requirements
- Arduino IDE: 2.3.7
- AvaSoft: 8.15
- Visual Studio Code: 1.109.4

### Hardware Requirements
- Computer: MacBook Pro, 13", 2020
- Microcontroller board: Arduino UNO Q
- Motor driver: A4988
- Spectrometer: Avantes AvaSpec-ULS2048XL-EVO
- Stepper motor: NEMA17-04
