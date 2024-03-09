# fract-ol
This project is about creating graphically beautiful fractals

The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based
it on the Latin word fractus which means "broken" or "fractured".

A fractal is an abstract mathematical object, like a curve or a surface, which pattern
remains the same at every scale.

Koch snowflake

Even though a fractal is, by definition, an infinite pattern and cannot be measured, the Koch snowflake lets us see that even though the perimeter of a fractal is infinite, the area is not. As you zoom into the edges of the snowflake, you would find that there are ever new emergence of the pattern, but the size of the snowflake itself doesn’t change.

![image](https://github.com/Simpli-Code/fract-ol/assets/74283859/a0446cd7-79b6-4644-8a8b-ee9ec182916e)


This kind of fractal is commonly found in nature when we observe coastlines. You can’t really get an exact measurement of the land mass on Earth because the edges are not smooth, they are rough and variable, the Koch snowflake is a way of showing how the infinite irregularities can still be contained within an approximation of the whole.

What are some fractals that you have observed in nature? Have you ever seen fractals in art?

Now, it’s your turn to generate some magnificent fractals!

# 🛠️ Usage
Requirements

This program is written in C language for Linux distributions and thus needs the clang compiler and some standard C libraries to run.

Compiling the program

```
$ make
```

Execute either julia or mandelbrot

```
$ ./fractol julia
```

Execute a specific julia set pass a valid julia set parameter

```
$ ./fractol julia -0.4 0.6
```

# 📑 Index

@root

📁 inc: contains the program's headers.

📁 src: contains the source code of the program.

Makefile - contains instructions for compiling the program and testing it.
