---
title: BesAir
layout: home
has_children: true
---

# BesAir

Project documentation for the **Design for Physical Prototyping** course 2022/23 focusing on the topic of **Uncomfortable Devices**.

## Team

-   Felix Rader
-   Tobias Wagner
-   Valentin Postl
-   Daniel Flockert
-   Wolfgang Schwendtbauer

## Abstract

This project aims to create an extremely overengineered, futuristic broom.
The broom does not include any bristles or brushes, but instead uses an air stream to relocate dust and dirt.
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

The final idea we decided on can be found in the [project proposal section](01_proposal).

## Implementation

For the most part of the semester, we worked on each component of the final project individually.
All components were tested on their own first and then in combination with the others they have to interact with.
Only after the christmas break, we started integrating all different hardware and software-parts into a final prototype.
The different stages of the implementation are described more detailed in the dedicated subpages, starting with the [initial testing](02_initial_testing).

## Materials and tools

Used materials:

-   3x hair dryer (from Willhaben and ASZ Hagenberg)
-   18.5V batteries
-   step-down converter
-   relay
-   amplifier (Sanwu TDA7498)
-   speaker (Visaton FR7)
-   Feather ESP32 plus sound-module FeatherWing
-   accelerometer
-   LED ring
-   LED strip
-   2x PVC pipe
-   a **LOT** of tape, glue and 3D printing filament

Besides the "standard" tools present in an electronic lab, we used a 3D printer to print enclosures for the batteries and a nozzle for the broom.

## Final interaction videos

<iframe width="560" height="315" src="https://www.youtube.com/embed/ef_SeeZ1vMo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/J4gtbVzL-OM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/Qpq8d5d9OnU" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

## Conclusion

The Project has taken on a life of its own and has far surpassed our initial expectations. The freedom in this lecture has provided us with a very unique and effective learning opportunity.

The project has deepened our understanding of engineering, design, and the refinement process. Although we encountered some challenges along the way, they did not compromise the planned outcome at all. The power requirements for the LEDs exceeded the capabilities of the USB power supply, which limited the number of LEDs we could include in the design. Additionally, the ESP32 was not quite powerful enough to support a fully-featured web application, which led us to host the application on a separate web server. Despite these challenges, we were able to polish and improve our design through iterative prototyping. Finishing the first integration test early allowed us to really make the final prototype presentable and we are more than happy with the result.

Furthermore, we gained experience of power management and the limitations and unexpected problems it can present when merging separate parts with deviating power demands. Overall, this project was a great opportunity to apply our knowledge and skills in a real-world setting, and we are proud of what we accomplished.

The character of the assignment also allowed us to embrace many unintentional or unavoidable problems, like the signal interference between the ESP and audio amplifier, which now significantly adds to the charm of the final product.
