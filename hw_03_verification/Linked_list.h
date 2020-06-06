#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct list
{
	int value;
	struct list* next;
}list;
print_linked_list(const list*head);
add_first(list** head, int a);
add_last(list* head, int a);
add_N(list** head, int n, int a);
delete_first(list** head);
delete_last(list** head);
delete_n(list** head, int n);
list* get_end(list** head);
#endif
