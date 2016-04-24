#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
    /*allocate memory for first and last sentinels and check it succeeded*/
    lst->firstLink = malloc(sizeof(struct DLink));
    assert(lst->firstLink != 0);
    lst->lastLink = malloc(sizeof(struct DLink));
    assert(lst->lastLink != 0);

    /*point sentinels to each other and set size*/
    lst->firstLink->next = lst->lastLink;
    lst->lastLink->prev = lst->firstLink;
    lst->size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
    assert(lst != 0);
    assert(l != 0);

    /*make new link*/
    struct DLink *newL = malloc(sizeof(struct DLink));
    assert(newL != 0);

    /*assign newL members*/
    newL->value = v;
    newL->next = l;
    newL->prev = l->prev;

    /*reassign neighbor's pointers*/
    l->prev = newL;
    newL->prev->next = newL;

    /*increment lst size*/
    lst->size++;
}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
    assert(lst != 0);
    _addLinkBefore(lst, lst->firstLink->next, e);

}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {

    assert(lst != 0);
    _addLinkBefore(lst, lst->lastLink, e);

}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {

    /*lst is not empty or null*/
    assert(lst != 0);
    assert(!isEmptyList(lst));

    /*return first value*/
    return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
    /*lst is not empty or null*/
    assert(lst != 0);
    assert(!isEmptyList(lst));

    /*return last value*/
    return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
    /*lst and l are not null*/
    assert(lst != 0);
    assert(l != 0);

    /*adjust pointers - l prev's next = l's next*/
    l->prev->next = l->next;
    /*l next's prev = l's prev*/
    l->next->prev = l->prev;
    /*free l*/
    free(l);
    l = l->next = l->prev = 0;

    /*decrement size*/
    lst->size--;
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
    assert(!isEmptyList(lst));
    _removeLink(lst, lst->firstLink->next);

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
    assert(!isEmptyList(lst));
    _removeLink(lst, lst->lastLink->prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
    assert(lst != 0);
    return lst->size == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
    assert(lst != 0);
    assert(!isEmptyList(lst));

    struct DLink *lnk = malloc(sizeof(struct DLink));
    assert(lnk != 0);

    do
    {
        lnk = lnk->next;
        TYPE val = lnk->value;
        printf("%d\n", val);
    } while(lnk != lst->lastLink);


}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    assert(lst != 0);

    /*make new link*/
    struct DLink *newL = malloc(sizeof(struct DLink));
    assert(newL != 0);

    /*set link data members and rearrange pointers*/
    newL->value = v;
    newL->next = lst->lastLink;
    newL->prev = lst->lastLink->prev;
    newL->prev->next = newL;
    lst->lastLink->prev = newL;

    /*increment size*/
    lst->size++;
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
    assert(lst != 0);
    assert(!isEmptyList(lst));

    /*make temporary link to loop through bag*/
    struct DLink *tempL = malloc(sizeof(struct DLink));
    assert(tempL != 0);
    tempL = lst->firstLink->next;

    /*return 1 if match is found*/
    while(tempL != lst->lastLink)
    {
        if(tempL->value == e)
        {
			free(tempL);
            return 1;
        }

        tempL = tempL->next;
    }

    /*free tempL*/
    free(tempL);

    /*otherwise return 0*/
    return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
    assert(lst != 0);
    assert(!isEmptyList(lst));

    /*make temporary link to loop through bag*/
    struct DLink *tempL = malloc(sizeof(struct DLink));
    assert(tempL != 0);
    tempL = lst->firstLink->next;

    /*return 1 if match is found*/
    while(tempL != lst->lastLink)
    {
        if(tempL->value == e)
        {
            tempL->next->prev = tempL->prev;
            tempL->prev->next = tempL->next;
            free(tempL);
        }
    }

    /*decrement size*/
    lst->size--;
}
