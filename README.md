**Petrache Gabriela**

## Now you see me

### Description:

* The program will recieve multiple card decks and will store them in a doubly linked list.
* Each individual deck is a doubly linked list itself.
* The program will be able to perform various tricks using the decks of cards that it has stored.

### Possible commands:

ADD_DECK <number_of_cards>

* followed by <number_of_cards> cards (value, symbol)
* it will store a new deck of cards in the list

DEL_DECK <index>

* will delete the deck located at index from the list

DEL_CARD <index_deck> <index_card>

* will delete the <index_card> card from the <index_deck> deck

ADD_CARDS <index_deck> <number>

* will add <number> cards to the <index_deck> deck, followed by the cards (value, symbol)

DECK_NUMBER

* shows number of decks currently in the list

DECK_LEN <index_deck>

* shows number of cards in <index_deck> deck

SHUFFLE_DECK <index_deck>

* reverses the first and the second half of the deck

MERGE_DECKS <index1> <index2>

* merges the two decks with the given indexes, taking cards from each deck one by one

SPLIT_DECK <index_deck> <index_split>

* splits <index_deck> deck by the <index_split> index
* the first deck remains at <index_deck>, the rest of the deck moves to <index_deck> + 1

REVERSE_DECK <index_deck>

* reverses the deck of cards at the given index

SHOW_DECK <index_deck>

* prints the deck of cards at the given index

SHOW_ALL

* prints the whole list of decks

SORT_DECK <index_deck>

* sorts the deck by the value of the cards and the priority of the symbols
* the priority of the symbols is HEART, SPADE, DIAMOND, CLUB

EXIT

* this command will stop the execution of the program