# CMPT373 Course Project - Team Donair

#### A gaming platform that allows users to communicate, play games together and build custom-made games from a provided JSON spec.
#### Built with C++17 and CMake

## Features
* Messaging System that manages messaged between the clients and server.
* JSON Parsing that turns a user-provided JSON into a playable game

## How to build and use project
- ## Prerequisites

  - Boost 1.68
  - Ncurses
  - CMake
  - C++17

- ## Building

  - Download the repository, extract the folder to a location you have access to

  - Create a build folder

    - ```
      mkdir build
      cd build
      ```

  - Cmake to the location of the repository folder

    - ```
      sudo cmake PATH_TO_REPOSITORY_FOLDER
      
      Ex.
      sudo cmake /mnt/d/Dropbox/Dropbox/Courses/SPRING2020/CMPT373/social-gaming
      ```

  - Final step

    - ```
      sudo make GameServer
      ```

- ## Using

  - Go to the directory of where you built the project

    - ```
      ./bin/GameServer
      ```

  - Open the .html file and connect using "localhost:4000" or "localhost:4000"

## Project Structure

- ## src/

  - Contains source code and header files that are for internal use

- ## include/

  - Headers that are exposed publicly

- ## lib/

  - Third party libraries

- ## test/

  - Unit testing
  
## Usage
1. Create a .json "game" inside of /src/Games/...
2. Build and launch the server with the instructions above
3. Open the "socialapp.html" web client to connect into the server
4. Type in the IP address and click "connect"
5. You can type "/help" for the commands available
6. "/createsession Game.json" where "Game" is the name of your .json file
7. You should see an invite code be generated, type "/join invitecode"
8. Once in a gamesession, you can chat with other users, or start the game
9. Start the game by typing "/startgame invitecode"
10. The game will now run!

## Team Members
- Phan Bui
- Daniel Jui-Che Lin
- Hunsar Sekhon
- Joshua Deans
- Jimmy Zhong
- Matthew Zegar
- Lam Nguyen
- Yuheng Wu

## Build Requirements for Networking Libaries
- C++17 or newer
- Boost >= 1.66 and < 1.72
- CMake >= 3.12
- NCurses (only tested with 6.1)
