# plant minigame using godot-cpp template (4.4)
This is a brief demo of building a C++ game for Godot using GDExtension. It's starting point was the provided godot-cpp template at version 4.4 stable.

## Contents
* Godot C++ Library
* Source code for a mini game

## The mini game

The mini game was built with a strict time restriction of 10 hours, and with the aim to learn how to make C++ game for the Godot engine as quickly as possible. 
The mini game is centered around a plant, which grows over the course of some data-defined time. As it grows, the plant becomes bigger.
The plant needs to be watered every so often. When it is time to water it, a message will appear, and the player has a limited time to water the plant. If the plant is watered, it's growth trajectory continues. If the plant is not watered in time, it's growth trajectory slows down.

## Code decisions

Due to the strict-time restriction and the simplicity of the final design, the engineering of the game was kept really simple. The goal was to drive as much of the plant's behaviour and looks via Resources so that new gameplay could emerge. 
A basic factory pattern creates PlantNeeds from PlantDataResources, allowing for a future where there might be a hierarchy of PlantNeed classes.

## Dev environment

The configuration of GDExtension was done by following the instructions in the provided godot-cpp template. I used MSYS2 as the C++ compiler. I used VS Code as the IDE for this project since it had a couple of useful extensions I could install to debug C++ code while the application was running (CodeLLDB and C++ Helper).
