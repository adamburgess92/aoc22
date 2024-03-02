#!/bin/bash

g++ -std=c++20 -c Parser.cpp -o parser.o
g++ -std=c++20 -c Item.cpp -o item.o
g++ -std=c++20 -c Monkey.cpp -o monkey.o
g++ -std=c++20 -c main.cpp -o main.o

g++ main.o parser.o item.o monkey.o -o main
./main
