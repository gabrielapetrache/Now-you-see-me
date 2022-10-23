#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./DoublyLinkedList.h"
#include "./cards.h"

#define MAX_COMMAND 64

int main(void)
{
	doubly_linked_list_t *decks_array;
	char command[MAX_COMMAND] = {'\0'};
	decks_array = (doubly_linked_list_t *) dll_create(sizeof(doubly_linked_list_t));


	while (strcmp(command, "EXIT")) {
		scanf("%s", command);

		if (strcmp(command, "ADD_DECK") == 0) {
			add_deck(decks_array);
		} else if (strcmp(command, "DEL_DECK") == 0) {
			delete_deck(decks_array);
		} else if (strcmp(command, "DEL_CARD") == 0) {
			delete_card(decks_array);
		} else if (strcmp(command, "ADD_CARDS") == 0) {
			add_cards(decks_array);
		} else if (strcmp(command, "DECK_NUMBER") == 0) {
			deck_number(decks_array);
		} else if (strcmp(command, "DECK_LEN") == 0) {
			deck_len(decks_array);
		} else if (strcmp(command, "SHUFFLE_DECK") == 0) {
			shuffle_deck(decks_array);
		} else if (strcmp(command, "MERGE_DECKS") == 0) {
			merge_decks(decks_array);
		} else if (strcmp(command, "SPLIT_DECK") == 0) {
			split_deck(decks_array);
		} else if (strcmp(command, "REVERSE_DECK") == 0) {
			reverse_deck(decks_array);
		} else if (strcmp(command, "SHOW_DECK") == 0) {
			show_deck(decks_array);
		} else if (strcmp(command, "SHOW_ALL") == 0) {
			show_all(decks_array);
		} else if (strcmp(command, "SORT_DECK") == 0) {
			sort_deck(decks_array);
		} else if (strcmp(command, "EXIT") != 0){
			printf("Invalid command. Please try again.\n");
		}
	}

	free_all(&decks_array);

	return 0;
	
}