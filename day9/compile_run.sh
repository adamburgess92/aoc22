#!/bin/bash

g++ -std=c++20 -c main.cpp -o main.o
g++ -std=c++20 -c Parser.cpp -o parser.o
g++ -std=c++20 -c Coord.cpp -o Coord.o
g++ -std=c++20 -c Rope.cpp -o Rope.o
g++ main.o Parser.o Coord.o Rope.o -o main
./main
