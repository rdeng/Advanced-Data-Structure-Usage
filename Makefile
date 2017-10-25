#simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g

all: benchdict benchtrie util.o

benchtrie: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

DictionaryTrie.o: DictionaryTrie.hpp main.cpp

DictionaryBST.o: DictionaryBST.hpp

DictionaryHashtable.o: DictionaryHashtable.hpp

benchdict:util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

util.o: util.hpp

clean:
	rm -f benchtrie *.o core* *~

