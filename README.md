# Development of an Automated Switch Valve for a Flow Reactor

## Author
Simon Hein

## Description
This repository contains the software and datasets for an automated 6-port switch valve system used in a flow reactor. The system continuously monitors in-line UV-Vis spectra to automatically separate water from reaction products. Additionally, the scripts allow generating both 2D time-intensity plots and 3D spectral plots for data visualization and analysis.
Valve switching is achieved via a stepper motor controlled by an Arduino UNO Q. The Arduino signals to an A4988 motor driver, which regulates the motor’s rotation with precise angular steps.

## Structure
- code/ contains jupyter notebooks used for analysis/monitoring and Arduino code
- data/ contains data sets from two test series
- results/ ......

## Usage
### Arduino Code
- Upload the `code/Motor_Control.ino` sketch to the Arduino UNO Q once.
### Monitoring
- Ensure that one spectrum per second is recorded and that the spectrum is saved as a txt-file in monitored folder.
- Connect Arduino with computer.
- Connect Arduino with driver and stepper motor.
- Run `code/Automated_Motor_Switching.ipynb` to start real-time monitoring of UV-Vis spectra.
- The script automatically triggers motor actuation when a defined threshold is crossed.

## Installation and System Requirements
Python version: 3.14.0
### Python Packages
numpy                     2.3.5
pandas                    2.3.3
plotly                    6.5.0
pyserial                  3.5
watchdog                  6.0.0
matplotlib                3.10.7
### System requirements
Code was written on a MacBook Pro and execuded on a MacBook Pro and an Acer Nitro 5.
### Installation Instructions?
All python packages should be easily being installed via pip [https://pypi.org/project/pip/]  
e.g. pip install <package_name>  
Typically time to install all packages should be less than 30min depending on the amount of previously installed packages.
### Code Execution Time?
