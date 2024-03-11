#!/bin/bash

g++ -c Parser.cpp -o parser.o
g++ -c main.cpp -o main.o

g++ main.o parser.o -o main
./main
