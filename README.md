# Calculator_NX

This is my C++ Calculator program, ported to the Nintendo Switch.

This is a console type application, so no GUI. This is my first program so I didn't want to mess around with GUIs yet. I might add a GUI in the future.
You can now download this app with the up-to-date version on the HB App Store! If it is not updated right away, come here to get a new version.

## COMPLATION INSTRUCTIONS

Compiling this program requires the libnx library and any other libraries required by libnx. These can be installed via [devkitpro.](https://devkitpro.org/wiki/Getting_Started)

You can then `git clone` this repo to any folder on your computer. To compile on Unix-based distros (these instructions are mostly for macOS & Linux), run `make` while in the root of the repo. To compile on Windows is unknown to me, so feel free to change this for instructions on Windows.

### Complation troubleshooting

When you ran the command `make` and it gives an error like: `Please set DEVKITPRO in your environment`, this means you have to edit the .bash_profile file (this file differs from versions of macOS/Linux) to add the following:
`
export DEVKITPRO=/opt/devkitpro
export DEVKITA64=/opt/devkitpro/devkitA64
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPPC=/opt/devkitpro/devkitPPC
export PATH=$DEVKITPPC/bin:$DEVKITPRO/tools/bin:$PATH
`

## CREDITS

Switchbrew for making libnx

The people on the ReSwitched server for helping me

The people on the Switchroot server for helping me on my original Calculator program (this is based on that)
