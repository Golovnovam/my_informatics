
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
struct node
{
	int value;
	struct node* left;
	struct node* right;
};
typedef struct node node;
struct queue
{
	struct queue* next;
	struct node* tree;
};
typedef struct queue queue;
void add_new(struct node** root, int value);
void dfs(struct node* node);
void enqueue(struct queue** head, struct queue** tail, struct node* value);
struct node* dequeue(struct queue** head, struct queue** tail);
void bfs(struct node* root);
void search(struct node* root, const int num);

int max_tree(struct node *root); 
int count_of_value(node *root, int value);
#endif 