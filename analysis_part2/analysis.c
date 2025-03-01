// L. Kiser Nov. 9, 2023 updated to version 2

// Document Analysis project functions for Part 2

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "analysis.h"
#include "unit_tests.h"

// Helper function for read_file to validate inputs.
// Returns NULL if there is an error
static FILE *validate_read_file_parameters(struct linked_list *p_list, char *file_name)
{
    if (p_list == NULL || file_name == NULL || *file_name == '\0')  // if NULL list or if a bad or empty file name string return 0
        return NULL;

    return fopen(file_name, "r");  // Attempt to open file in read mode
}

// Optional helper function.
// returns 1 if pointers are OK, returns 0 if either is NULL.
/*
comment out not used

static int check_linked_list(struct linked_list *p_list)
{
    // Helper function to check if linked list is properly initialized (stub for optional use)
    return (p_list != NULL) ? 1 : 0;
}
*/

// First checks that p_list is not NULL. Returns 0 if p_list is a NULL pointer.
// Then checks that word pointer is not NULL and word is not any empty string.
// Returns 0 if either of the above tests on the passed word fails.
//
// Creates the list if starting a fresh list.
// Searches existing list for a match on the word. Increments word count
// if found. If not found adds the word in alphabetic order.
// Returns 1 if the word was added successfully.
// Returns 0 on failure.
// NOTE -- this function makes no assumption on upper or lower case. That is handled by read_file.
// For simplicity all words passed from the unit tests are all lower case only.
int process_word(struct linked_list *p_list, char *word)
{
    if (p_list == NULL || word == NULL || word[0] == '\0')
        return 0;

    // If the list is empty, create the first node.
    if (p_list->p_head == NULL) {
        add_node_at_head(p_list, word);  // Add first word to the list
        return 1;
    }

    // Search for the word in the list
    if (find_word(p_list, word)) {  // Word found, increment count
        p_list->p_current->word_count++;
        return 1;
    }

    // Word not found, insert it in sorted order.
    add_node_after_current(p_list, word);  // Add the word in sorted order
    return 1;
}

// First checks that the passed string with the file name is not a NULL pointer and is not an empty string.
// Also checks that the passed pointer to the linked_list struct is not a NULL pointer.
// Returns 0 if any of the above tests fail.
// returns 0 if the file cannot be read or if the file does not contain any words as defined for this project.
// returns the number of words if the file was found, opened successfully, and it contained at least one valid word.
// NOTE -- this function MUST convert all words read to lower case only! e.g "First" becomes "first"
int read_file(struct linked_list *p_list, char *file_name)
{
    if (p_list == NULL || file_name == NULL || *file_name == '\0')
        return 0;

    FILE *file = validate_read_file_parameters(p_list, file_name);
    if (file == NULL)
        return 0;

    char word[100];
    int word_count = 0;

    while (fscanf(file, "%99s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Process the word
        if (!process_word(p_list, word))
            return 0;
        word_count++;
    }

    fclose(file);
    return word_count;
}

// Returns the first unique word in the list and its number of occurrences in the text file.
// You must update the current pointer (p_current) to the node containing the first word.
struct word_entry get_first_entry(struct linked_list *p_list)
{
    struct word_entry entry = { NULL, 0 };

    if (p_list != NULL && p_list->p_head != NULL) {
        entry.unique_word = p_list->p_head->unique_word;
        entry.word_count = p_list->p_head->word_count;
        p_list->p_current = p_list->p_head;  // Set current to the first node
    }

    return entry;
}

// Returns the next unique word after the current node and its number of occurrences.
// You must update the current pointer (p_current) to the node containing the next word.
struct word_entry get_next_entry(struct linked_list *p_list)
{
    struct word_entry entry = { NULL, 0 };

    if (p_list != NULL && p_list->p_current != NULL && p_list->p_current->p_next != NULL) {
        p_list->p_current = p_list->p_current->p_next;

        // Strip punctuation from the unique_word
        int length = strlen(p_list->p_current->unique_word);
        while (length > 0 && ispunct(p_list->p_current->unique_word[length - 1])) {
            p_list->p_current->unique_word[length - 1] = '\0';
            length--;
        }

        entry.unique_word = p_list->p_current->unique_word;  // Now the word is without punctuation
        entry.word_count = p_list->p_current->word_count;
    }

    return entry;
}

// Returns the previous unique word before the current node and its number of occurrences.
// You must update the current pointer (p_current) to the node containing the previous word.
struct word_entry get_prev_entry(struct linked_list *p_list)
{
    struct word_entry entry = { NULL, 0 };

    if (p_list != NULL && p_list->p_current != NULL && p_list->p_current->p_previous != NULL) {
        p_list->p_current = p_list->p_current->p_previous;

        // Strip punctuation from the unique_word
        int length = strlen(p_list->p_current->unique_word);
        while (length > 0 && ispunct(p_list->p_current->unique_word[length - 1])) {
            p_list->p_current->unique_word[length - 1] = '\0';
            length--;
        }

        entry.unique_word = p_list->p_current->unique_word;  // Now the word is without punctuation
        entry.word_count = p_list->p_current->word_count;
    }

    return entry;
}


// Returns the last unique word in the list and its number of occurrences.
// You must update the current pointer (p_current) to the node containing the last word.
struct word_entry get_last_entry(struct linked_list *p_list)
{
    struct word_entry entry = { NULL, 0 };

    if (p_list != NULL && p_list->p_tail != NULL) {
        entry.unique_word = p_list->p_tail->unique_word;
        entry.word_count = p_list->p_tail->word_count;
        p_list->p_current = p_list->p_tail;
    }

    return entry;
}

// Writes the sorted unique word list to a CSV file.
// Receives the linked list pointer and the name of the file to be created.
// Returns 1 on a successful write of the file.
// Returns 0 on any failure.
int write_unique_word_list_to_csv_file(struct linked_list *p_list, char *file_name)
{
    if (p_list == NULL || file_name == NULL || *file_name == '\0' || p_list->p_head == NULL)
        return 0;

    FILE *file = fopen(file_name, "w");
    if (file == NULL)
        return 0;

    fprintf(file, "word,count\n");

    struct node *temp = p_list->p_head;
    while (temp != NULL) {
        fprintf(file, "%s,%d\n", temp->unique_word, temp->word_count);
        temp = temp->p_next;
    }

    fclose(file);
    return 1;
}
