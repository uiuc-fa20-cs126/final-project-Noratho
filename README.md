This game is called Geltin and is a demo for the movement of a platform fighting game.

The main thing required for the setup is a C++ Cinder directory with Box2D and the nlohmann JSON library. 
Once you get that squared away use the commands:

make antares

and ./cmake-build-debug/Debug/antares/antares.app/Contents/MacOS/antares
to run the project

The game lacks hitbox collision and enemies but uses the nlohmann JSON library for character data storage and JSON deserialization via the usage of the new macros added in the Summer of 2020. It also uses Box2D for collisions and physic and cinder for the game loop logic. It has a frame-sensitive input system that can do up to 2 combo inputs in the form of a direction and a command. 
