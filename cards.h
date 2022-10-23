#ifndef  CARDS_H_
#define  CARDS_H_
#define MAX_CARD_NAME 8

typedef struct card_t card_t;
struct card_t
{
	int value;
	char symbol[MAX_CARD_NAME];
};


void add_deck(doubly_linked_list_t *decks_array);
void delete_deck(doubly_linked_list_t *decks_array);
void delete_card(doubly_linked_list_t *decks_array);
void add_cards(doubly_linked_list_t *decks_array);
void merge_decks(doubly_linked_list_t *decks_array);
void split_deck(doubly_linked_list_t *decks_array);
void shuffle_deck(doubly_linked_list_t *decks_array);
void reverse_deck(doubly_linked_list_t *decks_array);
void sort_deck(doubly_linked_list_t *decks_array);
void deck_number(doubly_linked_list_t *decks_array);
void deck_len(doubly_linked_list_t *decks_array);
void swap(card_t *a, card_t *b);
void show_deck(doubly_linked_list_t *decks_array);
void show_all(doubly_linked_list_t *decks_array);
void free_all(doubly_linked_list_t **decks_array);


#endif  // CARDS_H_
