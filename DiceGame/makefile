############################################
# Program Filename: makefile
# Author: Nicholas Brown
# Date: 10/14/2015
# Description: makefile for Lab3
############################################

# my standard variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


# source file variables
SRC1 = Die.cpp
SRC2 = LoadedDie.cpp
SRC3 = Game.cpp
SRC4 = WarGame.cpp
SRCS = $(SRC1) $(SRC2) $(SRC3) $(SRC4)


# header file variables
HEADER1 = Die.hpp
HEADER2 = LoadedDie.hpp
HEADER3 = Game.hpp
HEADERS = $(HEADER1) $(HEADER2) $(HEADER3)


# executable variable
PROG = war

##########
# BUILDS #
##########
default:
	${CXX} ${SRCS} ${HEADERS} -o $(PROG)


all:
	${CXX} $(CXXFLAGS) ${SRCS} ${HEADERS} -o $(PROG)


clean:
	rm -f $(PROG) *.o *~

