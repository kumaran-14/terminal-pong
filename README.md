## Terminal-Pong
Classic ping-pong game written in c++17 and played in terminal

<p align="center">
<a href="https://asciinema.org/a/ZYCHw19s9rX6d3oS23vDkBDIc" target="_blank"><img src="https://asciinema.org/a/ZYCHw19s9rX6d3oS23vDkBDIc.svg" /></a>
</p>

> OS=Linux SHELL=zsh TERM=xterm-256color

#### Requirements
  - UTF-8 enabled terminal-emulator
  - UTF friendly font.
  - ncurses
  - Clang/GCC
  - CMake / Ninja / Meson

##### Install Packages
**Arch**
```
pacman -S ncurses
pacman -S ninja
```
**Ubuntu**
```
sudo apt-get install libncurses5-dev libncursesw5-dev
sudo apt-get install ninja-build
```

**Install Ninja**

    pip3 install --user meson

#### Build from source
##### Using Meson
```
git clone https://github.com/kumaran-14/terminal-pong.git
cd terminal-pong
meson build
cd build
ninja
./pong
```
##### Using CMake
```
git clone https://github.com/kumaran-14/terminal-pong.git
cd terminal-pong
mkdir build && cd build
cmake ..
make
./pong
```

##### Download
Download the binary from [releases](https://github.com/kumaran-14/terminal-pong/releases) page to play without any fuss.

**Todo**
 - Add video playback option by storing game states (use a data serialization library)  

