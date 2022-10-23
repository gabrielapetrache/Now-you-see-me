#ifndef __DOUBLY_LINKED_LIST_H_
#define __DOUBLY_LINKED_LIST_H_
#define MAX_STRING_SIZE 256

typedef struct dll_node_t dll_node_t;
struct dll_node_t
{
    void* data; 
    dll_node_t *prev, *next;
};

typedef struct doubly_linked_list_t doubly_linked_list_t;
struct doubly_linked_list_t
{
    dll_node_t* head;
    unsigned int data_size;
    unsigned int size;

};

dll_node_t *create_node(const void *new_data, unsigned int data_size);

doubly_linked_list_t*
dll_create(unsigned int data_size);

dll_node_t*
dll_get_nth_node(doubly_linked_list_t* list, unsigned int n);

void
dll_add_nth_node(doubly_linked_list_t* list, unsigned int n, const void* new_data);

dll_node_t*
dll_remove_nth_node(doubly_linked_list_t* list, unsigned int n);

unsigned int
dll_get_size(doubly_linked_list_t* list);

void
dll_free(doubly_linked_list_t** pp_list);


#endif /* __DOUBLY_LINKED_LIST_H_*/
