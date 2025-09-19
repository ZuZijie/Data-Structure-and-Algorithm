#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct StackNode {
    char bracket;
    struct StackNode* next;
} StackNode;
void push(StackNode** top, char bracket) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->bracket = bracket;
    newNode->next = *top;
    *top = newNode;
}
char pop(StackNode** top) {
    if (*top == NULL) return '\0';
    StackNode* temp = *top;
    char bracket = temp->bracket;
    *top = (*top)->next;
    free(temp);
    return bracket;
}
int isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return 1;
    if (opening == '[' && closing == ']') return 1;
    if (opening == '{' && closing == '}') return 1;
    return 0;
}
int main() {
    char input[256];
    fgets(input, sizeof(input), stdin);
    StackNode* stack = NULL;
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            push(&stack, input[i]);
        } else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
            if (stack == NULL) {
                printf("Wrong\n");
                return 0;
            }
            char top = pop(&stack);
            if (!isMatchingPair(top, input[i])) {
                printf("Wrong");
                return 0;
            }
        }
        i++;
    }
    if (stack == NULL) {
        printf("OK\n");
    } else {
        printf("Wrong\n");
        while (stack != NULL) {
            pop(&stack);
        }
    }
    return 0;
}
