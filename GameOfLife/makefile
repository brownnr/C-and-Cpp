#######################################################
# Program Filename:	makefile
# Author:		Nicholas Brown
# Date:			10/2/2015
# Description:		makefile for Assignment 1
#######################################################

# the standard variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


# the source file variables
SRC1 = mainGofL.cpp
SRC2 = Shape.cpp
SRCS = $(SRC1) $(SRC2)


# the header file variables
HEADER1 = Shape.hpp


# the executable name variable
PROG = Life


##############
# THE BUILDS #
##############
default:
	$(CXX) $(SRCS) $(HEADER1) -o $(PROG)

all:
	$(CXX) $(CXXFLAGS) $(SRCS) $(HEADER1) -o $(PROG)

clean:
	rm -f $(PROG) *.o *~





