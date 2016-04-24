############################################
# Program Filename: makefile
# Author: Nicholas Brown
# Date: 11/22/2015
# Description: makefile 
############################################

# my standard variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


# source file variables
SRC1 = mainTest.cpp
SRC2 = Barbarian.cpp
SRC3 = BlueMen.cpp
SRC4 = Creature.cpp
SRC5 = Goblin.cpp
SRC6 = LineupQueue.cpp
SRC7 = LoserStack.cpp
SRC8 = ReptilePeople.cpp
SRC9 = Shadow.cpp
SRCS = $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5) $(SRC6) $(SRC7) $(SRC8) $(SRC9)


# header file variables
HEADER1 = Shadow.hpp
HEADER2 = Barbarian.hpp
HEADER3 = BlueMen.hpp
HEADER4 = Creature.hpp
HEADER5 = Goblin.hpp
HEADER6 = LineupQueue.hpp
HEADER7 = LoserStack.hpp
HEADER8 = ReptilePeople.hpp
HEADER9 = 
HEADERS = $(HEADER1) $(HEADER2) $(HEADER3) $(HEADER4) $(HEADER5) $(HEADER6) $(HEADER7) $(HEADER8) $(HEADER9)


# executable variable
PROG = assign8

##########
# BUILDS #
##########
default:
	${CXX} ${SRCS} ${HEADERS} -o $(PROG)


all:
	${CXX} $(CXXFLAGS) ${SRCS} ${HEADERS} -o $(PROG)


clean:
	rm -f $(PROG) *.o *~

