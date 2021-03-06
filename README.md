# CHIP-8 C++ Cross-Platform Emulator
It's a simple emulator of the CHIP-8 written in C++ using OpenGL. The purpose of the project is to be able to run old games with good performance and lots of customizations to make the process of gaming better.

## Table of contents
* [Guide](#guide)
	* [Libraries](#libraries)
		* [Debian-like Linux distributions](#debian)
		* [Archlinux-like Linux distributions](#arch)
		* [Windows](#windows)
	* [Compilation process](#compilation)
		* [Linux](#linux)
		* [Windows](#windows-1)
	* [Example](#example_of_use)
		* [Linux](#linux-1)
		* [Windows](#windows-2)
* [Project Structure](#project_structure)
	* [Folders description](#folders)
	* [Folders description](#files)
* [Class Hierarchy](#class_hierarchy)
* [CHIP-8 Opcode Table](#opcodes)

## Guide
### Libraries
The emulator requires `boost`, `OpenGL`, `OpenAL` and other libraries to be installed on your machine.

#### Debian
```
$ sudo apt-get install libboost-all-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev libopenal-dev cmake libgtest-dev
```

#### Arch
```
$ sudo pacman -S boost opengl openal cmake gtest
```

#### Windows 
* `Boost Library` : [link](https://www.boost.org/)
* `GTest Framework` : [link](https://github.com/google/googletest)
* `OpenGL Library` : [link](https://www.khronos.org/opengl/wiki/Getting_Started)

### Compilation
To build the project from source follow the steps described below, using the guide for your type of OS.

#### Linux
```
$ cd <project_folder>
$ mkdir builld && cd build
$ cmake ..
$ make
```

#### Windows
Click on the 'Build' tab in MSVS, then chose 'Build' or 'Rebild' option.

### Example of use
This section describes in detail how to use the built executable and make it work with the game you want.

#### Linux
The compiled program will be in `(your_folder)/build/` with the title chip8. To run it type :
```
./chip8 filename=<path_to_a_game>
```

#### Windows
In progress...

## Project Structure
```
├── include
│   ├── hw
│   │   ├── cpu.hpp
│   │   ├── gpu.hpp
│   │   ├── keyboard.hpp
│   │   └── soundcard.hpp
│   ├── ui
│   │   └── window.hpp
│   ├── utils
│   │   └── settings.hpp
│   ├── application.hpp
│   ├── constants.hpp
│   ├── exceptions.hpp
│   └── version.hpp
├── scripts
│   ├── push_project.py
│   └── update_build.py
├── src
│   ├── hw
│   │   ├── cpu.cpp
│   │   ├── gpu.cpp
│   │   └── keyboard.cpp
│   ├── ui
│   │   └── window.cpp
│   ├── utils
│   │   └── settings.cpp
│   ├── application.cpp
│   └── main.cpp
├── tests
│   ├── fakes
│   │   ├── fake_application.hpp
│   │   └── fake_cpu.hpp
│   ├── mocks
│   │   ├── mock_application.hpp
│   │   └── mock_cpu.hpp
│   ├── program
│   │   └── demo.ch8
│   ├── app_test.cpp
│   └── cpu_test.cpp
├── CHANGELOG.md
├── CMakeLists.txt
├── LICENSE
├── NOTICE
└── README.md
```
### Folders
* `include` : pubic headers of the project
* `src` : private headers and sourcefiles of the project
* `tests` : GTest-powered unit tests for the project

### Files
* `*.cpp` : source code files with program's algorithm
* `*.hpp` : public/private headers, that contain class structures, method declarations and constants
* `CHANGELOG.md` : description of the changes made in a certain build
* `TODO.md` : list of changes to be made in the next builds
* `CMakeLists.txt` : CMake build system instructions on how to build the project
* `README.md` : this file

## Class Hierarchy
In progress...

## Opcodes:
The emulator processes native opcodes for the original CHIP-8. The list of implemented opcodes can be seen below.

| Implemented | Opcode | Description |
| --- | --- | --- |
| ❌ | `0x0NNN` | Calls RCA 1802 program at address 0xNNN. |
| ✅ | `0x00E0` | Clear the screen |
| ✅ | `0x00EE` | Return from subroutine |
| ✅ | `0x1NNN` | Jump to 0xNNN |
| ✅ | `0x2NNN` | Call subroutine at 0xNNN  |
| ✅ | `0x3XNN` | Skip next instruction if `VX == NN` |
| ✅ | `0x4XNN` | Skip next instruction if `VX != NN` |
| ✅ | `0x5XY0` | Skip next instruction if `VX == VY` |
| ✅ | `0x6XNN` | Set `VX` to `NN` |
| ✅ | `0x7XNN` | Add `NN` to `VX` (carry flag is not changed) |
| ✅ | `0x8XY0` | Set `VX` to the value of `VY` |
| ✅ | `0x8XY1` | Set `VX` to `VX \| VY` (bitwise OR) |
| ✅ | `0x8XY2` | Set `VX` to `VX & VY` (bitwise AND)|
| ✅ | `0x8XY3` | Set `VX` to `VX xor VY` |
| ✅ | `0x8XY4` | Add `VY` to `VX`. `VF` is set to 1 when there's a carry, and 0 when there isn't. |
| ✅ | `0x8XY5` | Subtract `VY` from `VX`. `VF` is set to 0 when there's a borrow and 1 when there isn't. |
| ✅ | `0x8XY6` | Shift `VY` right by one and copy the result to `VX`. `VF` is set to the value of the least significant bit of `VY` before the shift. |
| ✅ | `0x8XY7` | Set `VX` to `VY - VX`. `VF` is set to 0 when there's a borrow and 1 when there isn't. |
| ✅ | `0x8XYE` | Shift `VY` left by one and copy the result to `VX`. `VF` is set to the value of the least significant bit of `VY` before the shift. |
| ✅ | `0x9XY0` | Skip the next instruction if `VX` doesn't equal `VY`. |
| ✅ | `0xANNN` | Set index register to 0xNNN |
| ✅ | `0xBNNN` | Jump to the address `NNN` plus `V0` |
| ✅ | `0xCXNN` | Set `VX` to the result of a bitwise and operation on a random number and `NN` |
| ❌ | `0xDXYN` | Draw a sprite at coordinate (`VX`, `VY`) that has a width of 8 pixels and a height of `N` pixels. Each row is read as bit-coded starting from the index register, I. I doesn't change after the execution of this instruction. `VF` is set to 1 if any screen pixels are flipped from set to unset when the sprite is drawn, and to 0 if that doesn't happen. |
| ❌ | `0xEX9E` | Skip the next instruction if the key stored in `VX` is pressed. |
| ❌ | `0xEXA1` | Skip the next instruction if the key stored in `VX` is not pressed. |
| ✅ | `0xFX07` | Set `VX` to the value of the delay timer. |
| ❌ | `0xFX0A` | A key press is awaited and then stored in `VX` (blocking operation - all instructions are halted until the next key event) |
| ✅ | `0xFX15` | Set the delay timer to the value of `VX` |
| ✅ | `0xFX18` | Set the sound timer to the value of `VX` |
| ✅ | `0xFX1E` | Add the value of `VX` to the index register |
| ❌ | `0xFX29` | Set `I` to the location of the sprite for the character in `VX`. Characters 0-F (in hex) are represented by a 4x5 font. |
| ❌ | `0xFX33` | Stores the binary-coded decimal representation of `VX`, with the most significant of three digits at the address in `I`, the middle digit at `I` plus 1, and the least significant digit at `I` plus 2. (In other words, take the decimal representation of VX, place the hundreds digit in memory at location in `I`, the tens digit at location `I+1`, and the ones digit at location `I+2`.) |
| ✅ | `0xFX55` | Stores `V0` to `VX` (including `VX`) in memory starting at address `I`. `I` is increased by 1 for each value written. |
| ✅ | `0xFX65` | Fills `V0` to `VX` (including `VX`) with values from memory starting at address `I`. `I` is increased by 1 for each value written. |

## Links
* [How to write an emulator (CHIP-8 interpreter)](http://www.multigesture.net/articles/how-to-write-an-emulator-chip-8-interpreter/)
* [Wikipedia: CHIP-8](https://en.wikipedia.org/wiki/CHIP-8)
* [Cowgod's CHIP-8 tech reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)