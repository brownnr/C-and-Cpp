#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
	int x;

	struct hashLink* curr;
	struct hashLink* garbage;

	for(x = 0; x < ht->tableSize; x++){
        garbage = ht->table[x];
		while(garbage != NULL){
			/*make new link to hold the garbage while rearranging other links*/
			curr = garbage->next;
			/*free the old link*/
			garbage->key = NULL;
			free(garbage->key);
			garbage = NULL;
			free(garbage);

			garbage = curr;
		}
	}
	/*free the table*/
	free(ht->table);
	ht->tableSize = 0;
	ht->count = 0;
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	int end = ht->tableSize,
		count = ht->count,
		x;
	struct hashLink **old = ht->table;

	_initMap(ht, newTableSize);

	/*loop through the old table*/
	for(x = 0; x < end; x++){
		struct hashLink* looper = old[x];
		struct hashLink* next;

		/*as long as the link is not NULL*/
		while(looper != NULL){
			/*insert it into the new table*/
			insertMap(ht, looper->key, looper->value);
			/*advance to next link and trash the old link*/
			next = looper;
			looper = looper->next;

			next->key = NULL;
			free(next->key);
			next = NULL;
			free(next);
		}
	}

	/*reset the table count and free the old table*/
	ht->count = count;
	free(old);
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.

 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	int index;
	/*get value of index based on constant in header file*/
	if(HASHING_FUNCTION == 1)
		index = stringHash1(k) % ht->tableSize;
	else
		index = stringHash2(k) % ht->tableSize;

	/*make sure index isn't negative*/
	if(index < 0)
		index += ht->tableSize;

	/*go to the position in the array where the key belongs*/
	struct hashLink* head = ht->table[index];

	/*if the key is already in the table*/
	if(containsKey(ht, k)){
		/*find the link and increment the value*/
		while(strcmp(head->key, k)){
			head = head->next;
		}
		head->value++;
	}
	/*otherwise...*/
	else{
		/*make a new link*/
		struct hashLink* newLink = malloc(sizeof(struct hashLink*));
		assert(newLink != 0);
		/*initialize the values*/
		newLink->key = k;
		newLink->value = v;
		newLink->next = NULL;

		/*if there are no links already at the index*/
		if(head == NULL){
			/*insert new link*/
			ht->table[index] = newLink;
		}
		/*otherwise...*/
		else{
			/*advance to last link and insert new one*/
			while(head->next != NULL){
				head = head->next;
			}
			head->next = newLink;
		}
	}

	/*increment the count*/
	ht->count++;

	/*resize if necessary*/
	if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
		_setTableSize(ht, 2 * ht->tableSize);

}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{
	int index;
	/*get value of index based on constant in header file*/
	if(HASHING_FUNCTION == 1)
		index = stringHash1(k) % ht->tableSize;
	else
		index = stringHash2(k) % ht->tableSize;

	/*make sure index isn't negative*/
	if(index < 0)
		index += ht->tableSize;

	/*go to the position in the array where the key should be*/
	struct hashLink* curr = ht->table[index];

	/*while curr link is not NULL*/
	while(curr != NULL){
		/*if match is found, return value*/
		if(strcmp(curr->key, k) == 0){
			ValueType* v = &curr->value;
			return v;
		}
		/*otherwise, go to the next link*/
		else{
			curr = curr->next;
		}
	}

	/*if we get here, key is not in the table*/
	return NULL;
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
	int index;
	/*get value of index based on constant in header file*/
	if(HASHING_FUNCTION == 1)
		index = stringHash1(k) % ht->tableSize;
	else
		index = stringHash2(k) % ht->tableSize;

	/*make sure index isn't negative*/
	if(index < 0)
		index += ht->tableSize;

	/*go to the position in the array where the key should be*/
	struct hashLink* curr = ht->table[index];

	/*while the curr link is not NULL*/
	while(curr != NULL){
		/*if key is found, return true*/
		if(strcmp(curr->key, k) == 0){
			return 1;
		}
		/*otherwise, go to next link*/
		else{
			curr = curr->next;
		}
	}

	/*if we get here, the key was not found in table*/
	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
	int index;
	/*get value of index based on constant in header file*/
	if(HASHING_FUNCTION == 1)
		index = stringHash1(k) % ht->tableSize;
	else
		index = stringHash2(k) % ht->tableSize;

	/*make sure index isn't negative*/
	if(index < 0)
		index += ht->tableSize;

	/*go to the position in the array where the key should be*/
	struct hashLink* curr = ht->table[index];
	struct hashLink* prev;

	/*if first link is the one to be removed...*/
    if(curr != NULL && strcmp(ht->table[index]->key, k) == 0){
		/*shift the links up in the table*/
        ht->table[index] = curr->next;
		/*subtract key's value from count*/
        ht->count -= curr->value;
		/*free the link*/
        curr->key = NULL;
        free(curr->key);
        curr = NULL;
        free(curr);
        return;
    }
	/*otherwise...*/
    else{
		/*while the curr link is not NULL*/
        while(curr != NULL){
			/*if the key is found*/
            if(strcmp(curr->key, k) == 0){
				/*shift links*/
                prev->next = curr->next;
				/*subtract key's value from count*/
                ht->count -= curr->value;
				/*free the link*/
                curr->key = NULL;
                free(curr->key);
                curr = NULL;
                free(curr);
                return;
            }
			/*otherwise...*/
            else{
				/*go to next link*/
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	/*return count*/
	return ht->count;

}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	/*return tableSize*/
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
	int x,
		tally = 0;

	/*for each bucket in the table*/
	for(x = 0; x < ht->tableSize; x++){
		/*if the bucket is empty, add to tally*/
		if(ht->table[x] == NULL)
			tally++;
	}

	return tally;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	return (float)size(ht) / capacity(ht);
}


void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}


