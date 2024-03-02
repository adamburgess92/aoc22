#!/bin/bash

g++ -c coord.cpp -o coord.o
g++ -c main.cpp -o main.o
g++ -c parser.cpp -o parser.o
g++ main.o parser.o coord.o -o main
./main
