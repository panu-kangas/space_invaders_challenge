# 👾 Space Invaders Code Challenge 👾

I took part in a 10 hour coding challenge, where I first got a base code for a simple version of the classic Space Invaders game, and then I had 10 hours to turn it into something cool.  

I was also the facilitator of the event 👾

## Video of the base game

![Demo of the project](video/space_invaders_base_gif.gif)

## Video of my version after 10 hours

![Demo of the project](video/space_invaders_base_gif.gif)

## Features of my game

On top of the base game features I added:

- Game state system that allowed me to display starting screen, the game itself and an ending screen smoothly.  
- Score system for the player.  
- I changed the moving and spawning pattern of the aliens, so that they charge towards the player (bottom of screen)
- Added a ability system, so that the player has extra abilities (Speed Boost and Power Shot) to fight against the aliens.

## Setup information

1. You need to have Git and CMake installed in order to use this program.

2. **If you use Linux**, install SFML's dependencies using your system package manager. On Ubuntu and other Debian-based distributions you can use the following commands:
   ```
   sudo apt update
   sudo apt install \
       libxrandr-dev \
       libxcursor-dev \
       libxi-dev \
       libudev-dev \
       libfreetype-dev \
       libflac-dev \
       libvorbis-dev \
       libgl1-mesa-dev \
       libegl1-mesa-dev \
       libfreetype-dev
   ```


3. To build the game, use CMake from the command line with these commands:

   ```
   cmake -B build
   cmake --build build
   ```
   
   After running these commands, run the game executable with  

    ```./build/bin/space_invaders```

