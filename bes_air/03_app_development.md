---
title: App development
layout: default
parent: BesAir
nav_order: 3
---

# App Development

Try out the [_BesAir_ app](http://bes-air.😡🤖.ml/){:target="\_blank"} now!

## Introduction

The idea is to extend the _BesAir_ experience by developing an app that remotely controls the _Bes Air_ device. Features like turning the device on and off are a must. Other interactions like changing the LED lighting or playing a sound are planned. Only the future will tell how far we will reach into the bag of absurdity.

## Development Documentation

The web app is optimized for mobile but works on all devices.

### Cookie Disclaimer Dialogue

Every uncomfortable app needs an awfully long cookie disclaimer with no obvious decline button. Literally every time a user opens the app, a cookie disclaimer is shown. It explains exactly how we don't use any cookie data. While the big accept button is visible at the top, the small decline button is located at the very bottom.

| Cookie Disclaimer (Dark) |
| :-----: |
| ![de-AT_Dark_Cookie](assets/app-screenshots/disclaimers/de-AT_Dark_Cookie.png){: width="300"  } |

### Big Fat Button

This clearly important button turns the device on or off. It also communicates to the user when the _Bes Air_ lost connection.

| Turn On (Light) | Turn Off (Light) |
| :-----: | :-----: |
| ![On_Light](assets/app-screenshots/home/On_Light.png){: width="300" } | ![Off_Light](assets/app-screenshots/home/Off_Light.png){: width="300" } |

| Turn Off (Dark) | Reconnect (Dark) |
| :-----: | :-----: |
| ![Home_Off_Dark_iPhone](assets/app-screenshots/home/Off_Dark.png){: width="300" } | ![Reconnect_Dark](assets/app-screenshots/home/Reconnect_Dark.png){: width="300" } |

### App Settings

#### Language

The app language can be switched with radio buttons. Besides `German` and `English` we also included `Austrian German` for a good laugh. For persistency between reloads, the selected language is stored in `LocalStorage`.

|                                Dark Mode German                                 |                               Dark Mode English                               |
| :-----------------------------------------------------------------------------: | :---------------------------------------------------------------------------: |
| ![en-GB_Light](assets/app-screenshots/settings/en-GB_Light.png){: width="300" } | ![de-DE_Dark](assets/app-screenshots/settings/de-DE_Dark.png){: width="300" } |

#### Audio Language

As the _Bes Air_ device speaks to the user, we also provide the option to change the audio language. All options are an English version with a specific accent. So, naturally, you can let the device talk as a child.

![en-GB_Light_Presentation](assets/app-screenshots/settings/en-GB_Light_Presentation.jpg){: width="500" }

## Publishing

The App is automatically built by a _GitHub Action_ everytime the source code is changed.
The build is then copied into a standard _Nginx_ docker image and pushed to _Docker Hub_.
Afterwards the container running on a server can easily be restarted with the new version of the app.
