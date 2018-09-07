# Master Slaves

A simple program to understand how to use MPI’s broadcast functions.

## Tutorial
[mpitutorial](http://mpitutorial.com/tutorials/mpi-broadcast-and-collective-communication/)

## How to run
Copy the master_slaves.c program to your computer, and compile it using this command.
```sh
$ mpicc -o master_slaves master_slaves.c
```

Unless there are any errors, you will see the master_slaves binary in the current working directory.

To run the binary, use the following command.
```sh
$ mpirun -n 2 ./master_slaves
```
