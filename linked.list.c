#include "linked.list.h"


LinkedList *create_linked_list() {
    LinkedList *new_list;
    new_list = (LinkedList *) calloc(DEFAULT_LIST_SIZE, sizeof(LinkedList));
    if (new_list == NULL) {
        exit(1);
    }
    new_list->size = 0;
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

LinkedListDouble *create_double_linked_list() {
    LinkedListDouble *new_list;
    new_list = (LinkedListDouble *) calloc(DEFAULT_LIST_SIZE, sizeof(LinkedListDouble));
    if (new_list == NULL) {
        exit(1);
    }
    new_list->size = 0;
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

Node *create_node(int content) {
    Node *new_node = (Node *) calloc(DEFAULT_NODE_SIZE, sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->content = content;
    new_node->next_node = NULL;
    return new_node;
}

NodeDouble *create_node_double(int content) {
    NodeDouble *new_node = (NodeDouble *) calloc(DEFAULT_NODE_SIZE, sizeof(NodeDouble));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->content = content;
    new_node->next_node = NULL;
    new_node->prev_node = NULL;
    return new_node;
}

int push_back(LinkedList *linked_list, int content) {
    Node *new_node = create_node(content);

    if (!linked_list->size) {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
    } else {
        linked_list->tail->next_node = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
    }
    return 0;
}

int push_back_double(LinkedListDouble *linked_list_double, int content) {
    NodeDouble *new_node = create_node_double(content);

    if (!linked_list_double->size) {
        linked_list_double->head = new_node;
        linked_list_double->tail = new_node;
        linked_list_double->size++;
    } else {
        linked_list_double->tail->next_node = new_node;
        new_node->prev_node = linked_list_double->tail;
        linked_list_double->tail = new_node;
        linked_list_double->size++;
    }
    return 0;
}


int push_front(LinkedList *linked_list, int content) {
    Node *new_node = create_node(content);

    if (!linked_list->size) {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
    } else {
        new_node->next_node = linked_list->head;
        linked_list->head = new_node;
        linked_list->size++;
    }
    return 0;
}


int push_front_double(LinkedListDouble *linked_list_double, int content) {
    NodeDouble *new_node = create_node_double(content);

    if (!linked_list_double->size) {
        linked_list_double->head = new_node;
        linked_list_double->tail = new_node;
        linked_list_double->size++;
    } else {
        linked_list_double->head->prev_node = new_node;
        new_node->next_node = linked_list_double->head;
        linked_list_double->head = new_node;
        linked_list_double->size++;
    }
    return 0;
}


int insert(LinkedList *linked_list, int content, int position) {
    if (position < 0 || position > linked_list->size) {
        return 1;
    }
    Node *new_node = create_node(content);

    if (!linked_list->size) {
        linked_list->head = new_node;
        linked_list->size++;
        linked_list->tail = new_node;
    } else if (!position) {
        push_front(linked_list, content);
    } else if (position < linked_list->size) {
        Node *current_node = linked_list->head;
        for (int idx = 0; idx < position - 1; idx++) {
            current_node = current_node->next_node;
        }
        new_node->next_node = current_node->next_node;
        current_node->next_node = new_node;
        linked_list->size++;
    } else if (position == linked_list->size) {
        push_back(linked_list, content);
    } else {
        return 1;
    }
    return 0;
}


int insert_double(LinkedListDouble *linked_list_double, int content, int position) {
    if (position < 0 || position > linked_list_double->size) {
        return 1;
    }
    NodeDouble *new_node = create_node_double(content);

    if (!linked_list_double->size) {
        linked_list_double->head = new_node;
        linked_list_double->tail = new_node;
        linked_list_double->size++;
    } else if (!position) {
        push_front_double(linked_list_double, content);
    } else if (position == linked_list_double->size) {
        push_back_double(linked_list_double, content);
    } else if (position <= linked_list_double->size / 2) {
        NodeDouble *current_node = linked_list_double->head;
        for (int idx = 0; idx < position - 1; idx++) {
            current_node = current_node->next_node;
        }
        new_node->next_node = current_node->next_node;
        new_node->prev_node = current_node;
        current_node->next_node->prev_node = new_node;
        current_node->next_node = new_node;
        linked_list_double->size++;
    } else if (position > linked_list_double->size / 2 && position < linked_list_double->size) {
        NodeDouble *current_node = linked_list_double->tail;
        for (size_t idx = linked_list_double->size; idx > position; idx--) {
            current_node = current_node->prev_node;
        }
        new_node->next_node = current_node->next_node;
        new_node->prev_node = current_node;
        current_node->next_node = new_node;
        linked_list_double->size++;
    }
    return 0;
}


int remove_head(LinkedList *linked_list) {
    if (!linked_list->size) {
        return 1;
    } else if (linked_list->size == 1) {
        free(linked_list->head);
        linked_list->tail = NULL;
        linked_list->head = NULL;
        linked_list->size--;
    } else {
        Node *ptr_help = linked_list->head->next_node;
        free(linked_list->head);
        linked_list->head = ptr_help;
        linked_list->size--;
    }
    return 0;
}


int remove_head_double(LinkedListDouble *linked_list_double) {
    if (!linked_list_double->size) {
        return 1;
    } else if (linked_list_double->size == 1) {
        free(linked_list_double->head);
        linked_list_double->tail = NULL;
        linked_list_double->head = NULL;
        linked_list_double->size--;
    } else {
        NodeDouble *ptr_help = linked_list_double->head->next_node;
        free(linked_list_double->head);
        linked_list_double->head = ptr_help;
        linked_list_double->head->prev_node = NULL;
        linked_list_double->size--;
    }
    return 0;
}


int remove_tail(LinkedList *linked_list) {
    if (!linked_list->size) {
        return 1;
    } else if (linked_list->size == 1) {
        free(linked_list->head);
        linked_list->tail = NULL;
        linked_list->head = NULL;
        linked_list->size--;
    } else {
        Node *current_node = linked_list->head;
        for (int idx = 0; idx < linked_list->size - 2; idx++) {
            current_node = current_node->next_node;
        }
        linked_list->tail = NULL;
        current_node->next_node = NULL;
        linked_list->tail = current_node;
        linked_list->size--;
    }
    return 0;
}


int remove_tail_double(LinkedListDouble *linked_list_double) {
    if (!linked_list_double->size) {
        return 1;
    } else if (linked_list_double->size == 1) {
        free(linked_list_double->head);
        linked_list_double->tail = NULL;
        linked_list_double->head = NULL;
        linked_list_double->size--;
    } else {
        NodeDouble *ptr_help = linked_list_double->tail->prev_node;
        ptr_help->next_node = NULL;
        linked_list_double->tail = ptr_help;
        linked_list_double->size--;
    }
    return 0;
}


int remove_node(LinkedList *linked_list, int position) {
    if (!linked_list->size || position > linked_list->size || position < 1) {
        return 1;
    } else if (position == 1) {
        remove_head(linked_list);
    } else if (position == linked_list->size) {
        remove_tail(linked_list);
    } else {
        Node *help_prev = linked_list->head;
        for (int idx = 0; idx < position - 2; idx++) {
            help_prev = help_prev->next_node;
        }
        Node *help_next = linked_list->head;
        for (int idx = 0; idx < position; idx++) {
            help_next = help_next->next_node;
        }
        free(help_prev->next_node);
        help_prev->next_node = help_next;
        linked_list->size--;
    }
    return 0;
}


int remove_node_double(LinkedListDouble *linked_list_double, int position) {
    if (!linked_list_double->size || position > linked_list_double->size || position < 1) {
        return 1;
    } else if (position == 1) {
        remove_head_double(linked_list_double);
    } else if (position == linked_list_double->size) {
        remove_tail_double(linked_list_double);
    } else if (position <= linked_list_double->size / 2) {
        NodeDouble *help_prev = linked_list_double->head;
        for (int idx = 0; idx < position - 2; idx++) {
            help_prev = help_prev->next_node;
        }
        NodeDouble *help_next = help_prev->next_node->next_node;
        free(help_prev->next_node);
        help_prev->next_node = help_next;
        help_next->prev_node = help_prev;
        linked_list_double->size--;
    } else if (position > linked_list_double->size / 2) {
        NodeDouble *help_next = linked_list_double->tail;
        for (size_t idx = linked_list_double->size; idx > position + 2; idx--) {
            help_next = help_next->prev_node;
        }
        NodeDouble *help_prev = help_next->prev_node->prev_node;
        free(help_next->prev_node);
        help_prev->next_node = help_next;
        help_next->prev_node = help_prev;
        linked_list_double->size--;
    }
    return 0;
}


int delete_list(LinkedList *linked_list) {
    size_t temp = linked_list->size;
    for (int idx = 0; idx < temp; idx++) {
        remove_head(linked_list);
    }
    return 0;
}


int delete_list_double(LinkedListDouble *linked_list_double) {
    size_t temp = linked_list_double->size;
    for (int idx = 0; idx < temp; idx++) {
        remove_head_double(linked_list_double);
    }
    return 0;
}