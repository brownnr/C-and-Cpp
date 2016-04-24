/*******************************************************************
*	File: main.c
*	Author: Nicholas Brown
*	Description: main file to play animal guessing game. asks
*		questions until a guess is made, if the guess is wrong it
*		prompts the user to enter the animal they were thinking of
*		and saves it to a text file to be used in the next games.
*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "animal.h"

struct Node {
	char *str;
	struct Node *left;
	struct Node *right;
};

int main() {
	/*read from animal-kingdom.txt to build tree*/
	FILE *fp = fopen("animal-kingdom.txt", "r");
	if (fp == NULL)
    {
		printf("Cannot open file!\n");
		printf("Press Enter to exit.\n");
		getchar();
	}
    else
    {
        struct Tree *tree= malloc(sizeof(struct Tree));
        assert(tree != 0);
        tree->root = read(fp);
        fclose(fp);

        printf("%s","                    Welcome to my animal game!\n\n");
        printf("%s","         Please answer questions by typing 'yes' or 'no'.\n\n");

        struct Node *current = tree->root;
        char yesno[3];

        /*while the current node is not NULL*/
        while (current != 0)
        {
            /*as long as there are left or right children, keep traversing the tree*/
            if (current->left != 0 || current->right != 0)
            {
                printf("%s", current->str);
                scanf("%s", yesno);

                if (strcmp(yesno,"y") == 0 || strcmp(yesno,"Y") == 0 || strcmp(yesno,"yes") == 0
                    || strcmp(yesno,"Yes") == 0 || strcmp(yesno,"YES") == 0)
                {
                    current = current->left;
                }
                else if (strcmp(yesno,"n") == 0 || strcmp(yesno,"N") == 0 || strcmp(yesno,"no") == 0
                    || strcmp(yesno,"No") == 0 || strcmp(yesno,"NO") == 0)
                {
                    current = current->right;
                }
            }
            /*try and guess the animal if a leaf node is reached*/
            else
            {
                printf("Is it a %sYes or No ? ", current->str);
                scanf("%s", yesno);

                /*if the program has guessed the animal*/
                if (strcmp(yesno,"y") == 0 || strcmp(yesno,"Y") == 0 || strcmp(yesno,"yes") == 0
                    || strcmp(yesno,"Yes") == 0 || strcmp(yesno,"YES") == 0)
                {
                    printf("Success! Thank you for playing!\n\n");
                    printf("Press Enter to exit.\n");
                    getchar();
                    return 0;
                }
                /*if guess was wrong, learn a new animal*/
                else if (strcmp(yesno,"n") == 0 || strcmp(yesno,"N") == 0 || strcmp(yesno,"no") == 0
                    || strcmp(yesno,"No") == 0 || strcmp(yesno,"NO") == 0)
                {
                    printf("Please teach me, what animal were you thinking of? ");

                    /*read in animal name from user*/
                    char temp[80];
                    getchar();
                    fgets(temp, 80, stdin);
                    char *tmp1 = malloc(strlen(temp) + 1);
                    strcpy(tmp1, temp);

                    /*make new left and right nodes*/
                    current->left = malloc(sizeof(struct Node));
                    current->right = malloc(sizeof(struct Node));

                    /*set new left node's string to the new animal*/
                    current->left->str = tmp1;

                    /*set new right node's string to the wrongly guessed animal*/
                    current->right->str = current->str;

                    /*set the four children of the 2 new nodes to NULL*/
                    current->left->left = current->left->right = current->right->left = current->right->right = 0;

                    /*get new question to distinguish the new animal from the wrongly guessed one*/
                    printf("\nGive me a question that will be true for a %sbut false for a %s",
                        current->left->str, current->right->str);
                    fgets(temp, 80, stdin);
                    char *tmp2 = malloc(strlen(temp) + 1);
                    strcpy(tmp2, temp);

                    /*set the current node to the new question*/
                    current->str = tmp2;
                    printf("Thanks, I have learned a new animal!\n\n");

                    /*overwrite old animal-kingdom.txt with new information*/
                    fp = fopen("animal-kingdom.txt", "w");
                    /*if we can't find the file*/
                    if (fp == NULL)
                    {
                        printf("Cannot save file!\n");
                        printf("Press Enter to exit.\n");
                        getchar();
                    }
                    else
                    {
                        write(fp, tree->root);
                        fclose(fp);
                        printf("Press Enter to exit.\n");
                        getchar();
                    }

                    return 0;
                }
            }
        }
    }

	return 0;
}
