#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q)
{
  	assert(q != 0);

	/*make the sentinel*/
    q->Sentinel = _createLink(0);
    assert(q->Sentinel != 0);

	/*assign sentinel pointers and set list size*/
    q->Sentinel->next = q->Sentinel->prev = q->Sentinel;
    q->size = 0;

}

/*
 create a new circular list deque

 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/*make the new link*/
    struct DLink *newL = malloc(sizeof(struct DLink));
    assert(newL != 0);

	/*set it's value and temporary next/prev pointers*/
    newL->value = val;
    newL->prev = NULL;
    newL->next = NULL;

    return(newL);
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	assert(q != 0);
	assert(lnk != 0);

    struct DLink *newL = _createLink(v);
    assert(newL != 0);

    newL->prev = lnk;
    newL->next = lnk->next;
    lnk->next->prev = newL;
    lnk->next = newL;

    q->size++;
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
    assert(q != 0);
	_addLinkAfter(q, q->Sentinel->prev, val);

}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	assert(q != 0);
	_addLinkAfter(q, q->Sentinel, val);

}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));

    return q->Sentinel->next->value;

}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));

    return q->Sentinel->prev->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));

    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;

    free(lnk);

    q->size--;

}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));

	_removeLink(q, q->Sentinel->next);

}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	assert(q != 0);
	assert(!isEmptyCirListDeque(q));

	_removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	do
    {
        removeFrontCirListDeque(q);
    } while(q->Sentinel->next != q->Sentinel);

    free(q->Sentinel);

}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	assert(q != 0);
    return q->size == 0;

}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));

    struct DLink *jumper = q->Sentinel->next;

    do
    {
        printf("%f\n", jumper->value);
        jumper = jumper->next;
    } while(jumper != q->Sentinel);


}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	assert(q != 0);
	assert(!isEmptyCirListDeque(q));

    struct cirListDeque* newList = createCirListDeque();

    while(!isEmptyCirListDeque(q))
    {
        addBackCirListDeque(newList, backCirListDeque(q));
        removeBackCirListDeque(q);
    }
    q->Sentinel = newList->Sentinel;
    q->size = newList->size;
    free(newList);

}
