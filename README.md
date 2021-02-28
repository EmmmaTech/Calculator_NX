![Icon photo for Calculator_NX](resources/Calculator_NX.jpg)

# Calculator_NX
This is my C++ Calculator program, ported to the Nintendo Switch.

Note: This branch will no longer be getting any updates due to the recent merge of the code here and the main branch code. If you have git cloned this branch, git clone the other branch.

## COMPLATION INSTRUCTIONS

Compiling this program requires the libnx library and any other libraries required by libnx. These can be installed via [devkitpro.](https://devkitpro.org/wiki/Getting_Started)
It also requires installing required libraries needed for borealis, by running `sudo (dkp-)pacman -S switch-glfw switch-mesa switch-glm`.

You can then `git clone` this repo to any folder on your computer. To compile on Unix-based distros (these instructions are mostly for macOS & Linux), run `make` while in the root of the repo. To compile on Windows is unknown to me, so feel free to change this for instructions on Windows.

### Complation troubleshooting

When you ran the command `make` and it gives an error like: `Please set DEVKITPRO in your environment`, this means you have to edit the .bash_profile file (this file differs from versions of macOS/Linux) to add the following:
```bash
export DEVKITPRO=/opt/devkitpro
export DEVKITA64=/opt/devkitpro/devkitA64
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPPC=/opt/devkitpro/devkitPPC
export PATH=$DEVKITPPC/bin:$DEVKITPRO/tools/bin:$PATH
```

Any errors relating to borealis should be reported.

## PLANNED FEATURES

Planned features include making an GUI, making an updater inside of the app, and making a credits screen. Check the projects tab for the progress on these.

## CREDITS

Switchbrew for making libnx

The people on the ReSwitched server for helping me

The people on the Switchroot server for helping me on my original Calculator program (this is based on that)

The people on the RetroNX server for helping me with the GUI

natinusala and any contributors for creating the borealis library

## LICENSE

Calculator_NX uses the MIT License. Read the license for more details.

Borealis uses the Apache V2.0 License. Read the license contained in the borealis folder for more details.
