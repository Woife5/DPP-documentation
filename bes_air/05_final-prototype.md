---
title: Final prototype
layout: default
parent: BesAir
nav_order: 5
---

# Final prototype

## Reducing and Components

The first integration test relied on two large LiPo 18.5V batteries and an additional powerbank to power the ESP. One battery was used to power the motor and one for powering the amplifier and speaker. This was convenient for prototyping as the different components were isolated and could be easily disconnected, independent from each other. For our final prototype we wanted to build _BesAir_ as compact as possible. The LiPo batteries were reduced to one single battery pack and the powerbank was swapped with a Battery to USB charging converter, which is connected to the same battery pack.

## Cosmetics

For the final prototype a number of parts were modelled in CAD. The base houses the hair dryer fan and channels the air stream out the front. The PVC pipe of the last iteration is reused and attached to the top. For the electronics two housings were designed. The main housing holds the core electronics. THe top housing holds the down firing speaker.

For the design language a slightly retro-esque style was chosen with simple core shapes, lots of chamfers and decorative ridges. Modelling was done in Fusion 360 with 3D printing already in mind. Due to the limited print volume the parts had to be split into roughly a dozen individual parts. Total printing time was roughly 70 hours.
The electronics casings were printed in transparent PLA to show off the electronics and blinking components inside.

![Sketch render of the Fusion360 model](assets/final-prototype/design/BesAir-Drawing-v2.png){: width="300" }

![printing the base part](assets/final-prototype/design/printing.jpg){: width="300" }

Significant sanding and gluing work was needed to finalize the 3D Prints, especially for the base part, which warped after printing.

![All the printed and glued 3D printed parts](assets/final-prototype/design/glued-parts.jpg){: width="300" }

The main electronics casing was glued to the side of the PVC pipe, with some slots cut out to make room for electronics and routing cables. The motor and pipe mounts simply work by friction to enable easy disassembly during prototyping.

![Gluing the electronics casing to the PVC pipe](assets/final-prototype/design/gluing.jpg){: width="300" }

## Safety

The biggest safety hazard in this project were definitely the LiPo batteries, so the battery packs were always treated with care and preventative measures were taken to prevent overdischarging or other damage to the batteries. For the discharging protection an off the shelf alarm was used that would sound when the voltage of the battery pack dropped below a certain threshold with a large safety margin. Disconnecting and charging has to be done manually.

For the final prototype the biggest risk would be short circuiting the battery pack, while the electronics casing is screwed closed. An external safety switch was added, that completely disconnects the batty from all components.

Officially _BesAir_ does not have any external buttons, so the safety switch is hidden behind the _BesAir_ logo, that is glued to the front of the PVC pipe.

## Adding LEDs

LEDs were planned early on, but later completely disregarded from the development process. They were only added again once all of the components were successfully integrated and mounted within the casing.

One LED strip was added internally along the long side of the main electronics casing and an LED ring was mounted in the top speaker housing. For the casing only one side received an LED strip as using any more LEDs would overshoot the power budget of the USB power delivery. For this reason the LEDs could also not be turned to their full brightness.

## Audio Signal Interference

## Final Assembly
