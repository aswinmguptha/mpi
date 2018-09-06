# Master Slave

A simple program to understand how to use MPI’s sending and receiving functions. The number provided the slave

## Tutorial
[mpitutorial](http://mpitutorial.com/tutorials/mpi-send-and-receive/)

## How to run
Copy the master_slave.c program to your computer, and compile it using this command.
```sh
$ mpicc -o master_slave master_slave.c
```

Unless there are any errors, you will see the master_slave binary in the current working directory.

To run the binary, use the following command.
```sh
$ mpirun -n 2 ./master_slave
```
