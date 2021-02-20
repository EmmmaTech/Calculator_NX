![Icon photo for Calculator_NX](Calculator_NX.jpg)

# Calculator_NX
This is my C++ Calculator program, ported to the Nintendo Switch.

This branch (main) contains the code for the Command-Line version of the app, while the GUI branch contains the code for the GUI version of the app.

Once the GUI version of the app is finished, this branch (main) will no longer have binaries in Releases.

## COMPLATION INSTRUCTIONS

Compiling this program requires the libnx library and any other libraries required by libnx. These can be installed via [devkitpro.](https://devkitpro.org/wiki/Getting_Started)

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
