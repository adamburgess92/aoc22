#!/bin/bash

g++ -c main.cpp -o main.o
g++ -c parser.cpp -o parser.o
g++ -c hand.cpp -o hand.o
g++ main.o parser.o hand.o -o main
./main
