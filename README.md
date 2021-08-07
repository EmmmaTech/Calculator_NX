![Icon photo for Calculator_NX](./resources/Calculator_NX.jpg)

# Calculator_NX

### Currently under a rewrite. All features may not be implemented or work correctly.

## Features

Calculator_NX can calculate any expression with the addition, subtraction, multiplication, division and exopoint operators.
Calculator_NX includes a homebrew app which has full support for all the features, and a Tesla menu overlay, which can only calculate expressions (no updating or about tab).

## Compile

In order to compile, you need to setup a development environment.
[Refer to the Getting Started guide](https://devkitpro.org/wiki/Getting_Started) to start.

After it's fully installed, please install the dependencies below.
```bash
(sudo) (dkp-)pacman -S switch-glfw switch-mesa switch-glm switch-curl
```

Finally, run the `build.sh` file which will build the cnx_forwarder, the Calculator_NX app, and the Calculator_NX overlay.

## License

Calculator_NX uses the MIT License. Read the license for more details.