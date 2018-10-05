#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node *get_new_node() {
    return (struct Node *)malloc(sizeof(struct Node));
}

void insertNode(struct Node **start, int x) {
    struct Node *temp = *start;
    struct Node *new_node = get_new_node();

    if(temp == NULL) {
        new_node->value = x;
        new_node->next = NULL;
        *start = new_node;
    } else {
        if(temp->value > x) {
            new_node->value = x;
            new_node->next = temp;
            *start = new_node;
        } else {
            while(temp->next != NULL && temp->next->value < x) {
                temp = temp->next;
            }
            new_node->value = x;
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

int deleteNode(struct Node **start, int x) {
    struct Node *temp = *start;
    if(temp == NULL) return -1;
    if(temp->value == x) {
        if(temp->next == NULL) {
            *start = NULL;
            free(temp);
        } else {
            struct Node *toDelete = temp;
            *start = temp->next;
        }        
        return x;
    }
    while(temp != NULL && temp->next != NULL) {
        if(temp->next->value == x) {
            struct Node *toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
            return x;
        }
        temp = temp->next;
    }
    return -1;
}

void printList(struct Node *start) {
    struct Node *temp = start;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *start = NULL;
    insertNode(&start, 10);
    insertNode(&start, 15);
    insertNode(&start, 16);
    printList(start);
    deleteNode(&start, 10);
    deleteNode(&start, 5);
    printList(start);
    return 0;
}