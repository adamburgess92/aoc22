#!/bin/bash

g++ -std=c++20 -c Parser.cpp -o parser.o
g++ -std=c++20 -c Register.cpp -o register.o
g++ -std=c++20 -c main.cpp -o main.o

g++ main.o parser.o register.o -o main
./main
