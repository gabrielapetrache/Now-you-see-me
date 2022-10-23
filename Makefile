all: build

build:
	gcc -Wall -Wextra -g main.c DoublyLinkedList.c cards.c -o cards

clean:
	rm *.o cards

run:
	./cards
