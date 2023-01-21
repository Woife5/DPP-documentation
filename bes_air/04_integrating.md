---
title: Integrating the different parts
layout: default
parent: BesAir
nav_order: 4
---

# Integrating the different parts

After testing all components on their own and integrating them in some initial tests, we decided to make a very rough prototype containing all aspects of the final product in one package.

## ESP32 code

The different parts of the software running on the ESP have been coded by different people, each using their own chip.
This resulted in a lot of blocking code in the different parts of the application for timing and communication.
The code was split up into the webserver, the sound controller and the last part controlling the motor and reading from the sensors.
To integrate all the different parts, a lot of the code had to be refactored to not block the execution of the other parts, which meant getting rid of all `delay()` and similar calls.
Timing things had to be converted to store timestamps for different events and checking them every loop iteration.
A workaround also had to be found for the sound-driver, which only supported blocking code on the version of the chip we were using.
This was because the specific chip we were using did not support the required interrupts for the sound library.
The workaround was to check the sound buffer every loop iteration and add new samples if the buffer was running low.

## Hardware

We decided to make the prototype portable and to power everything from batteries for the first version.
This was achieved by using two 18.5V batteries for the motor and the speaker, and a USB powerbank for the ESP.
Because we used a hairdryer motor, we had to use a step-down converter to avoid the motor, burning out when turning on.
The motor was controlled by a relay, which was connected to one of the ESP's GPIO pins.

![Testing if the ESP can drive the motor relay](assets/prototype-1/ba_measure-esp.jpg){: width="500" }

The speaker was connected to an amplifier, which was also powered by an 18.5V battery.
All the components were stuck onto a plastic pipe and a cardboard box was used to direct the airflow.

![First working, portable prototype](assets/prototype-1/ba_proto-final-1.jpg){: width="300" }

In this version the accelerometer was also already working as intended and the motor could be controlled by moving the device faster than a certain threshold.

<iframe width="560" height="315" src="https://www.youtube.com/embed/fMgb1iOq1RA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

## App

Activating or deactivating the device using the app was also already possible:

<iframe width="560" height="315" src="https://www.youtube.com/embed/-DQ8Hcarxg4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
