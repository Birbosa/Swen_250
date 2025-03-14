/*
 * hashmap - Implementation of a lookup table as a hashmap. The table maintains key/value
 *           pairs in an array of linked lists. Each key gets mapped to an array index (i.e. hash)
 *			 and the lookups go sequentially from there.
 *
 *           Example:   The pair "#f00" is a key for the color "RED" (aka the hex value for the color red)
 *           The bin number (or array index) is computed based on combining the string values of "#f00" via ASCII numbers
 *           To retrieve a value from the lookup table, the key "#f00" would be used to yield the
 *           the number 0. If a new pair with the same key is inserted ("#f00", "Red" for example),
 *           the new value replaces the existing value in the hashmap.
 *
 *           If two keys hash to the same bin number, a 'collision' occurs. The (key, value) pair which
 *           created the collision is then inserted at the START of a linked list for that bin number - i.e. each
 *           bin number points to a unique list of (key, value) pairs.
 *
 *  		Implementation note: we are using a doubly-linked list this time. This makes drops a little easier.
 *
 *			Note: a "hashmap" is the same thing as a "hashtable"
 *
 * 			YOUR EXERCISE:
 * 				- Fill out hash()
 * 				- Fill out lookup(...)
 *				- Fill out drop()
 * 			OPTIONAL STUDY:
 *				- To practice your dynamic C skills, remove the code for lookup() and implement it yourself
 *				- For a tougher exercise, remove the code for set() and implement it yourself
 *
 *			You should not need to modify the tests in main(), but feel free to add to them as you see fit.
 *
 *			Submit this to your pushbox under the directory hashmap
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINSIZE 7      /* number of hashmap bins (intentionally small to create collisions) */

struct binEntry {
	struct binEntry *next;    /* next entry in the list */
	struct binEntry *prev;    /* previous entry in the list */
	char *key;                /* defined key name */
	char *value;              /* value associated with the key */
};

static struct binEntry *hashtable[BINSIZE];     /* table of binEntry pointers */
/* this array is visible to all functions in this file */

/************************************************************
  hash - Create an unsigned integer hashvalue for a string

  Ths number must be from 0 to BINSIZE-1, as it will be used
  as an index to hashtable

  Compute this value by adding up the ASCII values of each
  character in key, then mod by BINSIZE
 ************************************************************/
unsigned int hash(char *key) {
    unsigned int hashvalue = 0;
    while (*key) {
        hashvalue += (unsigned int) *key;  // Add ASCII value of the character
        key++;  // Move to the next character in the key
    }
    return hashvalue % BINSIZE;  // Return the modulus of the sum to map to a bin
}


/********************************************************************
  lookup  - Given a key string, return a binEntry. Return NULL if not found

  This is accomplished by computing the hash value for the given key,
  then traversing the linked list at that hashtable location and
  returning the pointer to the binEntry when the given key is the same
  as the binEntry's key.

Hint: use strcmp to compare two strings. Returns 0 when they are the same
e.g. strcmp('abc','abc') == 0 //would evaluate to true
 *******************************************************************/
struct binEntry *lookup(char *key) {
    unsigned int hashvalue = hash(key);
    struct binEntry *entry = hashtable[hashvalue];  // Start at the head of the linked list in the bin

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {  // If keys match, return the entry
            return entry;
        }
        entry = entry->next;  // Move to the next entry in the linked list
    }

    return NULL;  // If no match found, return NULL
}


/****************************************************************
  insert  - Inserts a key/value pair into the hashmap. Existing keys
  are updated with the new value. A pointer to the new entry is returned.
  DO NOT MODIFY THIS CODE
 ***************************************************************/
struct binEntry *insert(char *key,  char *value)
{
	struct binEntry *entry;
	unsigned int hashvalue;

	if (( entry=lookup(key)) == NULL ) {   	/* key not found, create new entry  */
		entry = (struct binEntry*) malloc( sizeof (struct binEntry));
		entry->key = strdup(key);     /* create a duplicate of this key */
		hashvalue = hash(key);
		entry->next = hashtable[hashvalue];   /* new entries become the start of the chain */
		entry->prev = NULL;
		if(hashtable[hashvalue] != NULL)
			hashtable[hashvalue]->prev = entry;
		hashtable[hashvalue] = entry;         /* this entry becomes the head of the list for this bin */
	} else {                                    /* key exists, just update value */
		free( (void*) entry->value);          /* release memory for current value being replaced */
	}
	entry->value = strdup( value);              /* create a duplicate of the value for this entry */
	return entry;
}

/****************************************************************
  drop - Deletes a key/value entry from the hashmap. Delete
  request is ignored if the key is not found.

  Don't forget to free!
 ***************************************************************/
void drop(char *key) {
    struct binEntry *entry = lookup(key);  // Look for the entry with the given key
    if (entry == NULL) {
        return;  // If the key doesn't exist, do nothing
    }

    // Remove the entry from the linked list
    if (entry->prev != NULL) {
        entry->prev->next = entry->next;  // Update the previous entry's next pointer
    } else {
        unsigned int hashvalue = hash(key);
        hashtable[hashvalue] = entry->next;  // If it's the first entry in the list, update the head of the list
    }
    if (entry->next != NULL) {
        entry->next->prev = entry->prev;  // Update the next entry's previous pointer
    }

    free(entry->key);  // Free the memory for the key
    free(entry->value);  // Free the memory for the value
    free(entry);  // Free the memory for the entry itself
}


/**************************************************************************
  printHashtable - Print the contents of the hashmap
 ***************************************************************************/
void printHashtable() {
	unsigned int bin;
	struct binEntry *entry;

	printf("BIN [key: value] --> [key: value]\n");
	printf("--- -----------------------------\n");
	for( bin=0 ; bin < BINSIZE ; bin++ )
	{
		printf( "%2d  ", bin);
		if ( hashtable[bin] == NULL )
			printf( "NULL");
		else {
			for( entry = hashtable[bin] ; entry != NULL ; entry = entry->next) {
				printf("[%s: %s]", entry->key, entry->value);
				if( entry->next != NULL)
					printf(" --> ");
			}
		}
		printf("\n");
	}
	return;
}

/**************************************************************************
  main - function main begins program execution - no command line parameters
 ***************************************************************************/
int main() {
	struct binEntry tmpEntry;
	struct binEntry *entry = &tmpEntry;
	int i;

	for( i = 0 ;  i < BINSIZE ; i++ )               /* initialize each bin to point to an empty list */
		hashtable[ i ] = NULL;

	printf("=== TESTING hash ===\n");
	printf("'#FFF' hashes to 0: %d\n", hash("#FFF"));
	printf("'#FF0' hashes to 6: %d\n", hash("#FF0"));
	printf("'#0F0' hashes to 5: %d\n", hash("#0F0"));
	printf("'#F00' hashes to 5: %d\n", hash("#F00"));
	printf("'#999' hashes to 3: %d\n", hash("#999"));
	printf("====================\n\n");

	printf("=== SOME BASIC SETS ===\n");
	insert("#FFF","White");
	insert("#FF0", "Yellow");
	insert("#0F0", "GREEN!");
	insert("#999", "Gray");
	printf("Should be showing four colors in each of 0, 3, 5, 6\n");
	printHashtable();
	printf("====================\n\n");

	printf("=== HASH COLLISION ===\n");
	insert("#F00", "Red");
	printf("Now we have Red at the head of the list with GREEN\n");
	printHashtable();
	printf("====================\n\n");

	printf("=== SET REPLACE ===\n");
	insert("#0F0", "Green");
	printf("Green should now be replaced as not capitalized\n");
	printHashtable();
	printf("====================\n\n");

	printf("=== DROP ONE ===\n");
	drop("#F00");
	printf("Dropping Red means the list now just has Green\n");
	printHashtable();
	printf("====================\n\n");

	printf("=== DROP GRAY ===\n");
	drop("#999");
	printf("Dropping Gray means the list now has White, Green, Yellow\n");
	printHashtable();
	printf("====================\n\n");

	printf("=== CLEAR ALL ===\n");
	drop("#FFF");
	drop("#FF0");
	drop("#0F0");
	drop("#999");
	printf("Should be empty now\n");
	printHashtable();
	printf("====================\n\n");
	return 0; /* indicates successful termination */

} /* end main */
