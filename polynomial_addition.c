#include <stdio.h>
#include <stdlib.h>
// Define a structure for a polynomial term
struct Term {
 int coefficient;
 int exponent;
 struct Term* next;
};
// Function to create a new term
struct Term* createTerm(int coef, int exp) {
 struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
 newTerm->coefficient = coef;
 newTerm->exponent = exp;
 newTerm->next = NULL;
 return newTerm;
}
// Function to insert a term into a polynomial
void insertTerm(struct Term** poly, int coef, int exp) {
 struct Term* newTerm = createTerm(coef, exp);
 if (*poly == NULL) {
 *poly = newTerm;
 } else {
 struct Term* current = *poly;
 struct Term* prev = NULL;
 while (current != NULL && current->exponent > exp) {
 prev = current;
 current = current->next;
 }
 if (current != NULL && current->exponent == exp) {
 current->coefficient += coef;
 free(newTerm);
 } else {
 newTerm->next = current;
 if (prev != NULL) {
 prev->next = newTerm;
 } else {
 *poly = newTerm;
 }
 }
 }
}
// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
 if (poly == NULL) {
 printf("0\n");
 return;
 }
 while (poly != NULL) {
printf("%dx^%d", poly->coefficient, poly->exponent);
 if (poly->next != NULL) {
printf(" + ");
 }
 poly = poly->next;
 }
 printf("\n");
}
// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
 struct Term* result = NULL;
 while (poly1 != NULL || poly2 != NULL) {
 int coef1 = 0, coef2 = 0;
 int exp1 = -1, exp2 = -1;
 if (poly1 != NULL) {
    coef1 = poly1->coefficient;
 exp1 = poly1->exponent;
 poly1 = poly1->next;
 }
 if (poly2 != NULL) {
 coef2 = poly2->coefficient;
 exp2 = poly2->exponent;
 poly2 = poly2->next;
 }
 int sum = coef1 + coef2;
insertTerm(&result, sum, exp1); // Add the terms to the result polynomial
 }
 return result;
}
int main() {
 struct Term* poly1 = NULL;
 struct Term* poly2 = NULL;
 struct Term* result = NULL;
 int coef, exp, terms;
printf("Enter the number of terms in the first polynomial: ");
scanf("%d", &terms);
printf("Enter the terms (coefficient exponent) for the first polynomial:\n");
 for (int i = 0; i < terms; i++) {
scanf("%d %d", &coef, &exp);
insertTerm(&poly1, coef, exp);
 }
printf("Enter the number of terms in the second polynomial: ");
scanf("%d", &terms);
printf("Enter the terms (coefficient exponent) for the second polynomial:\n");
 for (int i = 0; i < terms; i++) {
scanf("%d %d", &coef, &exp);
insertTerm(&poly2, coef, exp);
 }
printf("First polynomial: ");
 displayPolynomial(poly1);
printf("Second polynomial: ");
 displayPolynomial(poly2);
 result = addPolynomials(poly1, poly2);
printf("Result of addition: ");
 displayPolynomial(result);
 // Free memory
 struct Term* temp;
 while (poly1 != NULL) {
 temp = poly1;
 poly1 = poly1->next;
 free(temp);
 }
 while (poly2 != NULL) {
 temp = poly2;
 poly2 = poly2->next;
 free(temp);
 }
 while (result != NULL) {
 temp = result;
 result = result->next;
 free(temp);
 }
 return 0;
}