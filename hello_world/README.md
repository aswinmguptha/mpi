# Hello World

A simple Hello World program to understand basics of initializing MPI and running an MPI job across several processes.

## Tutorial
[mpitutorial](http://mpitutorial.com/tutorials/mpi-hello-world/)

## How to run
Copy the hello_world.c program to your computer, and compile it using this command.
```sh
$ mpicc -o hello_world hello_world.c
```

Unless there are any errors, you will see the hello_world binary in the current working directory.

To run the binary in 10 processes, use the following command.
```sh
$ mpirun -n 10 ./hello_world
```
