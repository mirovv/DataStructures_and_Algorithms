#include <stdio.h>

struct elem {
	void *val;
	struct elem *next, *prev;
};

struct list { struct elem *first, *curr; };

void func(struct list *listA, void* p) {
	struct elem* newElem;
	if (listA->curr == NULL) return;
	newElem = malloc(sizeof(struct elem));
	newElem->val = p;
	newElem->prev = listA->curr;
	newElem->next = listA->curr->next;
	if (newElem->next) { ???? }
	listA->curr->next = newElem;
	listA->curr = newElem;
}
