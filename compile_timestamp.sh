#!/bin/bash

echo -n "Enter the file name you wish to compile: "
read my_file

gcc -Wall -c timestamp.c
gcc -Wall -c $my_file

gcc -o ${my_file%.*} timestamp.c $my_file

rm *.o
