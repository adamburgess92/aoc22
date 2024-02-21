#!/bin/bash

g++ -c main.cpp -o main.o
g++ -c parser.cpp -o parser.o
g++ main.o parser.o -o main
./main
