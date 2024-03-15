# fract-ol
This project is about creating graphically beautiful fractals by using the MiniLibX!

The MiniLibX Library was developed internally at ecole 42 and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events.

The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based
it on the Latin word fractus which means "broken" or "fractured".

A fractal is an abstract mathematical object, like a curve or a surface, which pattern
remains the same at every scale.

Various natural phenomena – like the romanesco cabbage – have some fractal features.

![image](https://github.com/Simpli-Code/fract-ol/assets/74283859/a3765201-a2c5-4a07-95aa-5751f4e58c00)

This kind of fractal is commonly found in nature. What are some fractals that you have observed in nature? Have you ever seen fractals in art?

# 🛠️ Usage
Requirements:

This program is written in C language for Linux distributions and Mac OS thus needs the clang compiler and some standard C libraries to run.

Compiling the program

```
$ make
```

Execute either julia set or mandelbrot set

```
$ ./fractol julia
```

or

```
$ ./fractol mandelbrot
```

Execute a specific julia set by passing a set ( c = -0.835 0.2321i ) as parameter for more julia sets see the link below

https://en.wikipedia.org/wiki/Julia_set

```
$ ./fractol julia -0.835 0.2321
```

# 📑 Index

@root

📁 inc: contains the program's headers.

📁 src: contains the source code of the program.

Makefile - contains instructions for compiling the program and testing it.

USEFUL RESOURCES:

https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf
https://acko.net/blog/how-to-fold-a-julia-fractal/
https://harm-smits.github.io/42docs/
https://en.wikipedia.org/wiki/Julia_set
https://rgbacolorpicker.com/
