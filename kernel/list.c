#include "lris/list.h"

void list_add (struct list_head *new, struct list_head *head)
{
	if (head->next)
	{
		new->next = head->next;
		new->prev = head;
		head->next->prev = new;
		head->next = new;
		return ;
	}
	head->next = new;
	new->prev = head;
}

void list_del (struct list_head *entry)
{
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;
}