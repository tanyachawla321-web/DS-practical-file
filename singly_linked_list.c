#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at Beginning */
void insertBeginning(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("%d inserted at beginning.\n", value);
}

/* Insert at End */
void insertEnd(int value) {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("%d inserted at end.\n", value);
}

/* Insert at a Particular Position */
void insertPosition(int value, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("%d inserted at position %d.\n", value, position);
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("%d inserted at position %d.\n", value, position);
}

/* Delete from Beginning */
void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("%d deleted from beginning.\n", temp->data);

    free(temp);
}

/* Delete from End */
void deleteEnd() {
    struct Node *temp;
    struct Node *previous;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    previous = NULL;

    while (temp->next != NULL) {
        previous = temp;
        temp = temp->next;
    }

    previous->next = NULL;

    printf("%d deleted from end.\n", temp->data);

    free(temp);
}

/* Delete from Particular Position */
void deletePosition(int position) {
    struct Node *temp;
    struct Node *previous;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        temp = head;
        head = head->next;

        printf("%d deleted from position %d.\n",
               temp->data, position);

        free(temp);
        return;
    }

    temp = head;
    previous = NULL;

    for (i = 1; i < position && temp != NULL; i++) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    previous->next = temp->next;

    printf("%d deleted from position %d.\n",
           temp->data, position);

    free(temp);
}

/* Display List */
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("\nSingly Linked List:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Search an Element */
void search(int value) {
    struct Node *temp;
    int position = 1;
    int found = 0;

    temp = head;

    while (temp != NULL) {

        if (temp->data == value) {
            printf("%d found at position %d.\n",
                   value, position);
            found = 1;
            break;
        }

        temp = temp->next;
        position++;
    }

    if (found == 0) {
        printf("%d not found in the list.\n", value);
    }
}

/* Count Nodes */
void countNodes() {
    struct Node *temp;
    int count = 0;

    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes = %d\n", count);
}

/* Main Function */
int main() {

    printf("SINGLY LINKED LIST\n");
    printf("==================\n\n");

    /* Insertion */
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    insertBeginning(5);
    display();

    insertPosition(15, 3);
    display();

    /* Searching */
    printf("\nSearching:\n");
    search(20);
    search(50);

    /* Count Nodes */
    printf("\nCounting Nodes:\n");
    countNodes();

    /* Deletion */
    printf("\nDeletion:\n");

    deleteBeginning();
    display();

    deleteEnd();
    display();

    deletePosition(2);
    display();

    printf("\nFinal List:\n");
    display();

    return 0;
}