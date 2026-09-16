#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display() {
    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteNode() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    printf("%d deleted\n", temp->data);
    free(temp);
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    deleteNode();

    display();

    return 0;
}