#!/bin/bash

g++ -c Parser.cpp -o parser.o
g++ -c Point.cpp -o point.o
g++ -c Crawler.cpp -o crawler.o
g++ -c main.cpp -o main.o

g++ main.o point.o crawler.o parser.o -o main
./main
