/*******************************************************************
*	File: animal.c
*	Author: Nicholas Brown
*	Description: Implementation of the animal guessing game
*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "animal.h"

struct Node {
	char *str;
	struct Node *left;
	struct Node *right;
};

/*******************************************************************
*	function to read questions and animal names from file and 
*		recursively assign to nodes in the tree.
*	paramaters: pointer to FILE
*	preconditions: FILE is not NULL
*	postconditions: tree is populated
*******************************************************************/
struct Node *read(FILE *fp) {
	char ch = fgetc(fp);
	char temp[80];
	struct Node *current = malloc(sizeof(struct Node));
	
	/*if first character is not a ? the line is an animal*/
	if (ch != '?')
	{
		fgets(temp, 80, fp);
		char *tmp = malloc(strlen(temp) + 1);
		strcpy(tmp, temp);
		current->str = tmp;
		current->left = 0;
		current->right = 0;
	}
	/*otherwise it's a question*/
	else
	{
		fgets(temp, 80, fp);
		char *tmp = malloc(strlen(temp) + 1);
		strcpy(tmp, temp);
		current->str = tmp;
		current->left = read(fp);
		current->right = read(fp);
	}
	
	return current;
}

/*******************************************************************
*	function to write questions and animal names from file and 
*		recursively assign to nodes in the tree.
*	paramaters: pointer to FILE and tree's root node
*	preconditions: FILE is not NULL, current is not NULL
*	postconditions: the file is populated with the tree's structure
*		including any new animals/questions learned during the game.
*******************************************************************/
void write(FILE *fp, struct Node *current) {
	/*as long as current is not NULL*/
	if (current != 0)
	{
		/*if current has children, mark line with ?*/
		if (current->left != 0 || current->right != 0)
			fputc('?', fp);
		/*otherwise, mark line with -, because it's an animal*/
		else
			fputc('-', fp);
		
		/*print current's str to file*/
		fprintf(fp, "%s", current->str);
		/*recursively call function throughout tree*/
		write(fp, current->left);
		write(fp, current->right);
	}
}

