
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}node;
typedef struct queue
{
	struct queue* next;
	struct node* tree;
}queue;
add_new(struct node** root, int value);
dfs(struct node* node);
enqueue(struct queue** head, struct queue** tail, struct node* value);
struct node* dequeue(struct queue** head, struct queue** tail);
bfs(struct node* root);
search(struct node* root, const int num);
max_on_stage(struct node* node);
#endif 