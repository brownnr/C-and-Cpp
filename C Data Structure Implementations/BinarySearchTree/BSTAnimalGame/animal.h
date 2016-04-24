/*******************************************************************
*	File: animal.h
*	Author: Nicholas Brown
*	Description: Interface of the animal guessing game
*******************************************************************/

#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

struct Tree {
	struct Node *root;
	int size;
};

/*read from file to populate Tree*/
struct Node *read(FILE *fp);

/*write current Tree structure to file(saving any new animals learned)*/
void write(FILE *fp, struct Node *current);


#endif // ANIMAL_H_INCLUDED
