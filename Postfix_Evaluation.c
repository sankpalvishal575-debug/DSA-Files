#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val);
int pop();
int evaluatePostfix(char postfix[]);
int isOperator(char c);
int performOperation(int op1, int op2, char operator);

int main() {
    char postfix[MAX];
    int result;
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    result = evaluatePostfix(postfix);
    
    printf("Result: %d\n", result);
    
    getch();
    return 0;
}

void push(int val) {
    if(top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if(top < 0) {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int performOperation(int op1, int op2, char operator) {
    switch(operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if(op2 == 0) {
                printf("Division by zero error\n");
                return 0;
            }
            return op1 / op2;
        case '^': return (int)pow(op1, op2);
        default: return 0;
    }
}

int evaluatePostfix(char postfix[]) {
    int i, operand1, operand2, result;
    char c;
    
    for(i = 0; i < strlen(postfix); i++) {
        c = postfix[i];
        
        // If operand (digit), push to stack
        if(isdigit(c)) {
            push(c - '0');  // Convert char digit to int
        }
        
        // If operator, pop two operands and perform operation
        else if(isOperator(c)) {
            if(top < 1) {  // Need at least 2 operands
                printf("Invalid expression\n");
                return 0;
            }
            
            operand2 = pop();  // Second operand (top of stack)
            operand1 = pop();  // First operand
            
            result = performOperation(operand1, operand2, c);
            push(result);
        }
    }
    
    // Final result should be the only element in stack
    if(top == 0) {
        return pop();
    }
    else {
        printf("Invalid expression\n");
        return 0;
    }
}