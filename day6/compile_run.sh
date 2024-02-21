#!/bin/bash

g++ -std=c++20 -c main.cpp -o main.o
g++ -std=c++20 -c parser.cpp -o parser.o
g++ main.o parser.o -o main
./main
