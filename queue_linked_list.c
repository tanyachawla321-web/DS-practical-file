#include <stdio.h>
#include <stdlib.h>
// Structure for each node of the queue
struct Node {
 int data;
 struct Node* next;
};
// Front and Rear pointers for Queue
struct Node* front = NULL;
struct Node* rear = NULL;
// Function to enqueue (insert element)
void enqueue(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (!newNode) {
 printf("Memory allocation failed!\n");
 return;
 }
 newNode->data = value;
 newNode->next = NULL;
 if (rear == NULL) {
 front = rear = newNode;
 } else {
 rear->next = newNode;
 rear = newNode;
 }
 printf("%d enqueued to the queue.\n", value);
}
// Function to dequeue (remove element)
void dequeue() {
    if (front == NULL) {
 printf("Queue Underflow! Queue is empty.\n");
 return;
 }
 struct Node* temp = front;
 printf("%d dequeued from the queue.\n", front->data);
 front = front->next;
 if (front == NULL) rear = NULL; // If queue becomes empty
 free(temp);
}
// Function to peek at the front element
void peek() {
 if (front == NULL) {
 printf("Queue is empty.\n");
 } else {
 printf("Front element is: %d\n", front->data);
 }
}
// Function to display the queue
void display() {
 if (front == NULL) {
 printf("Queue is empty.\n");
 return;
 }
 struct Node* temp = front;
 printf("Queue elements: ");
 while (temp != NULL) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("\n");
}
// Main function to demonstrate queue operations
int main() {
 int choice, value;
 while (1) {
 printf("\n--- Queue Menu (Linked List) ---\n");
 printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to enqueue: ");
 scanf("%d", &value);
 enqueue(value);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 peek();
 break;
 case 4:
 display();
 break;
 case 5:
 printf("Exiting...\n");
 return 0;
 default:
 printf("Invalid choice! Try again.\n");
 }
 }
}
