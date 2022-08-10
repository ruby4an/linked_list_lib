#include <malloc.h>

#define DEFAULT_LIST_SIZE 1
#define DEFAULT_NODE_SIZE 1


typedef struct Node {
    struct Node *next_node;
    int content;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

typedef struct NodeDouble {
    struct NodeDouble *next_node;
    struct NodeDouble *prev_node;
    int content;
} NodeDouble;

typedef struct LinkedListDouble {
    NodeDouble *head;
    NodeDouble *tail;
    size_t size;
} LinkedListDouble;

LinkedList *create_linked_list();

LinkedListDouble *create_double_linked_list();

Node *create_node(int content);

NodeDouble *create_node_double(int content);

int push_back(LinkedList *linked_list, int content);

int push_back_double(LinkedListDouble *linked_list_double, int content);

int insert(LinkedList *linked_list, int content, int position);

int insert_double(LinkedListDouble *linked_list_double, int content, int position);

int push_front(LinkedList *linked_list, int content);

int push_front_double(LinkedListDouble *linked_list_double, int content);

int remove_node(LinkedList *linked_list, int position);

int remove_node_double(LinkedListDouble *linked_list_double, int position);

int remove_head(LinkedList *linked_list);

int remove_head_double(LinkedListDouble *linked_list_double);

int remove_tail(LinkedList *linked_list);

int remove_tail_double(LinkedListDouble *linked_list_double);

int delete_list(LinkedList *linked_list);

int delete_list_double(LinkedListDouble *linked_list_double);