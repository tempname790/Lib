#ifndef LIB_CHAIN_LIST_H
#define LIB_CHAIN_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct list list;
typedef struct sl_node sl_node;

struct list {
	// addr of first node
	void *prime;

	// size of list
	unsigned int size;
};

struct sl_node {
	// addr of data
	void *data;

	// addr of next node
	sl_node *next;
};

// return a new dynamically list set to 0
list *new_list();
// return a new dynamically sl_node set to params
sl_node *sl_new_node(void *data, sl_node *next);

// return a ptr to the last sl_node in list
sl_node *sl_get_last_node(list *l);

// print list structure
#define SL_MAP_CANAL stderr
void sl_map(list *l);

// add data to begin of l
void *sl_push(list *l, void *data);
void *sl_push_last(list *l, void *data);

// delete first node and return data
void *sl_pop(list *l);
void *sl_pop_last(list *l);

// delete first node and free(data);
void sl_free_pop(list *l);
void sl_free_pop_last(list *l);

// call sl_pop for all node, data are ignored
void sl_clean(list *l);

// same sl_clean but call free for data
void sl_fclean(list *l);

#endif
