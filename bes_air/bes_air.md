---
title: BesAir
layout: home
has_children: true
---

# BesAir

Project documentation for the **Design for Physical Prototyping** course 2022/23 focusing on the topic of **Uncomfortable Devices**.

## Abstract

This project aims to create an extremely overengineered, futuristic broom.
This broom does not include any bristles or brushes, but instead uses an air stream to relocate dust and dirt.
It should only be active when it is in motion, and the user is using it like a normal broom.
Otherwise the device should be turned off.

## Concept

We considered a lot of different possible project ideas before converging onto this one.
Here is a list of some of the best ideas we came up with:

-   A voice activated faucet, the water flow would be controlled by the loudness and the temperature by the pitch of the voice.
-   A tissue recycling bin, which would take used tissues and recycle them into new ones.
-   A "cockroach" tabletop cleaning device. It would crawl around the table and clean it with a brush.
-   A wastebin that would detect and throw back any wrongfully thrown away items.
-   A toilet seat cleaning device which would use toilet water to clean the toilet seat.
-   A wastebin which would generate and display personalized shock-images based on the items thrown away.
-   A device which would press a lot of hair into a sponge which can be used for cleaning.

The final idea we decided on can be found in the [project proposal section](01_proposal.md).

## Implementation

For the most part of the semester, we worked on each component of the final project individually.
All components were tested on their own first and then in combination with the others they have to interact with.
Only after the christmas break, we started integrating all different hardware and software-parts into a final prototype.
The different stages of the implementation are described more detailed in the dedicated subpages, starting with the [initial testing](02_initial_testing.md).

## Materials and tools

Used materials:

-   2x hair dryer (from Willhaben and ASZ Hagenberg)
-   2x 18.5V batteries
-   USB powerbank
-   step-down converter
-   relay
-   amplifier
-   speaker
-   ESP32 plus sound-module
-   accelerometer
-   plastic pipe
-   a **LOT** of tape

Besides the "standard" tools present in an electronic lab, we used a 3D printer to print enclosures for the batteries and a nozzle for the broom.

## Conclusion

Shortly summarize your project implementation process and the resulting outcome.
What problems and limitations did you face? What experiences did you make
