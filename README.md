# fk

**(WIP)** A Brainfuck compiler based on LLVM.

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
