# ArduinoTempMonitor

Arduino Temperature Monitoring System

## Overview

This repository will include the code samples for an ongoing series of Arduino experiments, starting with some really basic circuits and building up over time into a more advanced system.

The topic will be temperature monitoring, with the eventual goal being a distributed Internet of Things (IoT) system with multiple monitoring "nodes", a centralised communications hub for logging and display, and a web-accessible interface.

## Parts List

The parts list will evolve over time as the project progresses, but for the initial few experiments you will need just a few items:

* Arduino Uno or similar (Duemilanove or Nano also work)
* DHT11 Temperature Sensor
* 10K Resistor
* Hookup Wires

## Experiments

### 1. Serial DHT11

> TBC: Wiring Diagram

Code available in `_01-dht11-serial`

Reads the temperature and heat index (feels like) in Celcius, relative humidity in %.

Sample output:

```
DHT11 Serial
Temperature: 19.00c 	Humidity: 88.00% 	Feels Like: 18.68c
Temperature: 19.00c 	Humidity: 88.00% 	Feels Like: 18.68c
Temperature: 19.00c 	Humidity: 88.00% 	Feels Like: 18.68c
Temperature: 19.00c 	Humidity: 87.00% 	Feels Like: 19.00c
Temperature: 19.00c 	Humidity: 87.00% 	Feels Like: 19.00c```