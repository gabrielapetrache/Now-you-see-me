// Copyright 2021 - 2022 - 312CA - Petrache Gabriela Andreea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./DoublyLinkedList.h"
#include "./cards.h"

#define MAX_STRING_SIZE 256
#define MAX_CARD_NAME 8

void add_deck(doubly_linked_list_t *decks_array)
{
	int nr_cards, value;
	doubly_linked_list_t *new_deck;
	char buff[MAX_CARD_NAME], line[MAX_STRING_SIZE], nr[MAX_STRING_SIZE];

	fgets(nr, sizeof(nr), stdin);
	sscanf(nr, "%d", &nr_cards);

	new_deck = dll_create(sizeof(card_t));
	int i = 0;

	while (i < nr_cards) {
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d %s", &value, buff);

		int err = 1;

		if(strcmp(buff, "HEART") == 0 || strcmp(buff, "CLUB") == 0 ||
		strcmp(buff, "DIAMOND") == 0 || strcmp(buff, "SPADE") == 0) {
			err = 0;
		}

		if(value < 1 || value > 14 || err == 1) {
			printf("The provided card is not a valid one.\n");
		} else {
			card_t *new_card = (card_t *)calloc(1, sizeof(card_t));

			new_card->value = value;
			memcpy(new_card->symbol, buff, sizeof(buff));
			dll_add_nth_node(new_deck, i, new_card);
			free(new_card);
			i++;
		}
	}

	int index = dll_get_size(decks_array);
	dll_add_nth_node(decks_array, index, new_deck);

	if(new_deck && new_deck->size) {
		printf("The deck was successfully created with %d cards.\n", nr_cards);
	}
	free(new_deck);
}

void delete_deck(doubly_linked_list_t *decks_array)
{
	unsigned int index;
	dll_node_t *deck_removed;
	doubly_linked_list_t *removed;
	scanf("%d", &index);

	if (index >= decks_array->size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	deck_removed = dll_remove_nth_node(decks_array, index);
	printf("The deck %d was successfully deleted.\n", index);

	removed = ((doubly_linked_list_t *) deck_removed->data);

	dll_free(&removed);
	free(deck_removed);
}

void delete_card(doubly_linked_list_t *decks_array)
{
	unsigned int idx_card, idx_deck;
	dll_node_t *curr_card, *curr_deck;

	scanf("%d", &idx_deck);
	scanf("%d", &idx_card);
	unsigned int size = dll_get_size(decks_array);

	if(idx_deck > size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	curr_deck = dll_get_nth_node(decks_array, idx_deck);
	unsigned int size_deck = ((doubly_linked_list_t*)(curr_deck->data))->size;

	if(idx_card >= size_deck) {
		printf("The provided index is out of bounds for deck %d.\n", idx_deck);
		return;
	}
	curr_card = dll_remove_nth_node(((doubly_linked_list_t*)(curr_deck->data)),
																	idx_card);

	size_deck = ((doubly_linked_list_t*)(curr_deck->data))->size;

	if(!size_deck) {
		curr_deck = dll_remove_nth_node(decks_array, idx_deck);
		free(curr_deck->data);
		free(curr_deck);
	}
	free(curr_card->data);
	free(curr_card);
	printf("The card was successfully deleted from deck %d.\n", idx_deck);
}

void add_cards(doubly_linked_list_t *decks_array)
{
	unsigned int index, nr_cards, value;
	unsigned int size = dll_get_size(decks_array);
	char line[MAX_STRING_SIZE], buff[MAX_CARD_NAME], nr[MAX_STRING_SIZE];

	fgets(nr, sizeof(nr), stdin);
	sscanf(nr, "%d %d", &index, &nr_cards);

	if(index > size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}
	dll_node_t *curr_deck;

	curr_deck = dll_get_nth_node(decks_array, index);
	unsigned int size1 = ((doubly_linked_list_t*) curr_deck->data)->size;
	unsigned int i = 0;
	while (i < nr_cards) {
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d %s", &value, buff);

		int err = 1;

		if(strcmp(buff, "HEART") == 0 || strcmp(buff, "CLUB") == 0 ||
		strcmp(buff, "DIAMOND") == 0 || strcmp(buff, "SPADE") == 0) {
			err = 0;
		}

		if(value < 1 || value > 14 || err == 1) {
			printf("The provided card is not a valid one.\n");
		} else {
			card_t *new_card = (card_t *)calloc(1, sizeof(card_t));
			new_card->value = value;
			memcpy(new_card->symbol, buff, sizeof(buff));
			dll_add_nth_node(((doubly_linked_list_t*) curr_deck->data), size1, new_card);
			size1++;
			i++;
			free(new_card);
		}
	}
	printf("The cards were successfully added to deck %d.\n", index);
}

void merge_decks(doubly_linked_list_t *decks_array)
{
	int index1, index2;
	scanf("%d %d", &index1, &index2);
	int size_array = decks_array->size;
	if(index1 > size_array || index2 > size_array) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_node_t *first, *second;
	doubly_linked_list_t *merged, *removed1, *removed2;
	merged = dll_create(sizeof(card_t));
	first = dll_get_nth_node(decks_array, index1);
	second = dll_get_nth_node(decks_array, index2);
	unsigned int size_first = ((doubly_linked_list_t*) first->data)->size;
	unsigned int size_sec = ((doubly_linked_list_t*) second->data)->size;
	dll_node_t *curr1, *curr2;
	curr1 = ((doubly_linked_list_t*)first->data)->head;
	curr2 = ((doubly_linked_list_t*)second->data)->head;

	for(unsigned int i = 0; i < size_first; i++) {
		dll_add_nth_node(merged, i , curr1->data);
		curr1 = curr1->next;
	}

	for(unsigned int j = 0; j < size_sec; j++) {
		dll_add_nth_node(merged, 2*j + 1, curr2->data);
		curr2 = curr2->next;
	}

	first = dll_remove_nth_node(decks_array, index1);
	removed1 = ((doubly_linked_list_t *) first->data);
	dll_free(&removed1);
	free(first);
	second = dll_remove_nth_node(decks_array, index2);
	removed2 = ((doubly_linked_list_t *) second->data);
	dll_free(&removed2);
	free(second);

	printf("The deck %d and the deck %d were successfully merged.\n", index1,
				index2);
	unsigned int new_size = decks_array->size;
	dll_add_nth_node(decks_array, new_size, merged);
	free(merged);
}

void split_deck(doubly_linked_list_t *decks_array)
{
	unsigned int index, split_index;
	scanf("%d %d", &index, &split_index);
	unsigned int size = dll_get_size(decks_array);
	if(index > size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}
	if(!split_index) {
		printf("The deck %d was successfully split by index 0.\n", index);
		return;
	}

	dll_node_t *deck = dll_get_nth_node(decks_array, index);
	unsigned int size_deck = ((doubly_linked_list_t*)(deck->data))->size;
	doubly_linked_list_t *split = dll_create(sizeof(card_t));
	unsigned int start = size_deck / split_index;
	dll_node_t *curr = dll_get_nth_node(((doubly_linked_list_t*)deck->data),
																			start);

	for(unsigned int j = 0; j < start; j++) {
		dll_add_nth_node(split, j, curr->data);
		curr = curr->next;
	}

	for (unsigned int i = start; i < size_deck; i++) {
		dll_node_t *removed = 
		dll_remove_nth_node(((doubly_linked_list_t*)deck->data), i);
		free(removed);
	}

	dll_add_nth_node(decks_array, index + 1, split);
	free(split);

	printf("The deck %d was successfully split by index %d.\n", index,
				split_index);
}

void shuffle_deck(doubly_linked_list_t *decks_array)
{
	unsigned int index;
	scanf("%d", &index);
	if(index > decks_array->size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}
	dll_node_t *deck = dll_get_nth_node(decks_array, index);
	doubly_linked_list_t *new_deck = dll_create(sizeof(card_t));
	unsigned int size_deck = ((doubly_linked_list_t*)(deck->data))->size;
	dll_node_t *first_half = ((doubly_linked_list_t*)deck->data)->head;
	dll_node_t *second_half = dll_get_nth_node(((doubly_linked_list_t*)deck->data)
														, size_deck / 2);
	unsigned int half = size_deck / 2;
	if(size_deck % 2) {
		half++;
	}

	for(unsigned int i =  0; i < half ; i++) {
		dll_add_nth_node(new_deck, i, second_half->data);
		second_half = second_half->next;
	}

	for(unsigned int i = half; i < size_deck; i++) {
		dll_add_nth_node(new_deck, i, first_half->data);
		first_half = first_half->next;
	}
	dll_node_t *removed = dll_remove_nth_node(decks_array, index);
	dll_add_nth_node(decks_array, index, new_deck);
	dll_free(((doubly_linked_list_t **)&(removed->data)));
	free(removed);
	free(new_deck);
	printf("The deck %d was successfully shuffled.\n", index);
}

void reverse_deck(doubly_linked_list_t *decks_array)
{
	unsigned int index;
	scanf("%d", &index);
	if(index > decks_array->size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}
	dll_node_t *deck = dll_get_nth_node(decks_array, index);
	doubly_linked_list_t *new_deck = dll_create(sizeof(card_t));
	int size_deck = ((doubly_linked_list_t*)(deck->data))->size;
	dll_node_t *curr = ((doubly_linked_list_t*)deck->data)->head->prev;
	for(int i = 0; i < size_deck; i++) {
		dll_add_nth_node(new_deck, i, curr->data);
		curr = curr->prev;
	}
	dll_node_t *removed = dll_remove_nth_node(decks_array, index);
	dll_add_nth_node(decks_array, index, new_deck);
	dll_free(&new_deck);
	free(removed);
	printf("The deck %d was successfully reversed.\n", index);
}

void swap(card_t *a, card_t *b) {
	card_t temp = *a;
	*a = *b;
	*b = temp;
}

void sort_deck(doubly_linked_list_t *decks_array)
{
	unsigned int index;
	scanf("%d", &index);
	if(index > decks_array->size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}
	dll_node_t *deck = dll_get_nth_node(decks_array, index);
	dll_node_t *curr = ((doubly_linked_list_t*)deck->data)->head;
	unsigned int size = ((doubly_linked_list_t*)deck->data)->size;
	for (unsigned int i = 0; i < size; i++) {
		if(((card_t*)curr->data)->value <= ((card_t*)curr->next->data)->value) {
			swap((card_t*)curr->data, (card_t*)curr->next->data);
		}
		curr = curr->next;
	}

	int priority[MAX_STRING_SIZE];
	dll_node_t *curr2 = ((doubly_linked_list_t*)deck->data)->head;
	for (unsigned int i = 0; i < size; i++) {
		if(strcmp(((card_t*)curr2->data)->symbol, "HEART") == 0) {
			priority[i] = 1;
		}
		if(strcmp(((card_t*)curr2->data)->symbol, "SPADE") == 0) {
			priority[i] = 2;
		}
		if(strcmp(((card_t*)curr2->data)->symbol, "DIAMOND") == 0) {
			priority[i] = 3;
		}
		if(strcmp(((card_t*)curr2->data)->symbol, "CLUB") == 0) {
			priority[i] = 4;
		}
		curr2 = curr2->next;
	}
	dll_node_t *curr3 = ((doubly_linked_list_t*)deck->data)->head;
	for (unsigned int i = 0; i < size - 1; i++) {
		if(priority[i] < priority[i+1]) {
			swap((card_t*)curr->data, (card_t*)curr->next->data);
		}
		curr3 = curr3->next;
	}
	printf("The deck %d was successfully sorted.\n", index);
}

void deck_number(doubly_linked_list_t *decks_array)
{
	unsigned int size = dll_get_size(decks_array);
	printf("The number of decks is %d.\n", size);
}

void deck_len(doubly_linked_list_t *decks_array)
{
	unsigned int index;
	scanf("%d", &index);
	if(index > decks_array->size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}
	dll_node_t *curr;
	curr = dll_get_nth_node(decks_array, index);
	unsigned int s = ((doubly_linked_list_t*)(curr->data))->size;

	printf("The length of deck %d is %d.\n", index, s);
}

void show_deck(doubly_linked_list_t *decks_array)
{
	unsigned int index;
	dll_node_t *curr_card, *curr;
	scanf("%d", &index);

	if(!decks_array->size || index >= decks_array->size) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	curr = dll_get_nth_node(decks_array, index);
	printf("Deck %d:\n", index);

	curr_card = ((doubly_linked_list_t*) curr->data)->head;
	unsigned int size = ((doubly_linked_list_t*)(curr->data))->size;
	for(unsigned int i = 0; i < size; i++) {
		printf("\t%d %s\n", ((card_t *)curr_card->data)->value,
		((card_t *)curr_card->data)->symbol);
		curr_card = curr_card->next;
	}
}

void show_all(doubly_linked_list_t *decks_array)
{
	dll_node_t *curr_card, *curr;
	unsigned int index = dll_get_size(decks_array);

	for(unsigned int i = 0; i < index; i++) {
		curr = dll_get_nth_node(decks_array, i);
		printf("Deck %d:\n", i);

		curr_card = ((doubly_linked_list_t*) curr->data)->head;
		int size = ((doubly_linked_list_t*)(curr->data))->size;
		for(int j = 0; j < size; j++) {
			printf("\t%d %s\n", ((card_t *)curr_card->data)->value,
			((card_t *)curr_card->data)->symbol);
			curr_card = curr_card->next;
		}
	}
}

void free_all(doubly_linked_list_t **decks_array)
{
	dll_node_t *node = (*decks_array)->head;
	unsigned int size = (*decks_array)->size;
	if(!decks_array)
		return;
	for (unsigned int i = 0; i < size; i++) {
		doubly_linked_list_t *deck;
		deck = ((doubly_linked_list_t *)node->data);
		dll_free(&deck);
		node->data = NULL;
		node = node->next;
	}
	dll_free(decks_array);
}
