# fk

**(WIP)** A Brainfuck compiler based on LLVM.

## Table of contents

* [Introduction](#introduction)
* [Planned features](#planned-features)
* [Getting started](#getting-started)
    * [Dependencies](#dependencies)
    * [Building from source](#building-from-source)
    * [Running](#running)
* [License](#license)

## Introduction

fk is a Brainfuck compiler based on LLVM.

Brainfuck source is compiled to LLVM Intermediate Representation, which is then compiled and linked to binary objects.

## Planned features

* Report syntax errors and warnings
    * unmatched brackets
    * cell pointer out of bounds
* Peephole optimizations
    * combine successive increments/decrements
    * simplify [-] loop, set the cell to zero instead
    * remove loops at the beginning of the program
    * remove successive loops
    * skip loops at known zeroes
    * remove increments/decrements overwritten by `,`
* Cell usage analysis
    * determine how many cells a Brainfuck program requires
    * don't allocate/zero-initialize more cells than needed
* Compile-time evaluation
    * input-independent evaluations may be performed at compile time

## Getting started

### Dependencies

- A compiler with C++11 support (gcc >= 4.8.1, clang >= 3.3)
- CMake (>= 3.1.0)
- llvm (>= 3.9.0)

### Buiding from source

Please [report any problems](https://github.com/bozbalci/fk/issues/new) you run into when building the project.

    $ git clone https://github.com/bozbalci/fk
    $ mkdir fk/build
    $ cd fk/build
    $ cmake ..
    $ sudo make install

### Running

Currently, fk cannot create and link objects, but you can run Brainfuck programs directly using the `fk` command:

    $ fk hello.b
    Hello, World!

## License

fk is licensed under the BSD 2-clause license. See [LICENSE](https://github.com/bozbalci/fk/blob/master/LICENSE) for more information.
