#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struttura della pila
typedef struct {
    char data[100];
    int top;
} Stack;

// Crea una pila vuota
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Aggiungi un elemento alla pila
void push(Stack* stack, char value) {
    if (stack->top < 99) {
        stack->data[++(stack->top)] = value;
    }
}

// Togli un elemento dalla pila
char pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return '\0';
}

// Guarda il top senza toglierlo
char peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return '\0';
}

// Controlla se la pila è vuota
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Controlla se è un operando (numero o lettera)
int isoperand(char c) {
    return isalnum(c);  // CORRETTO: isalnum controlla se è lettera o numero
}

// Ritorna la precedenza dell'operatore
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '^') {
        return 3;
    }
    return 0;
}

// Controlla se un operatore è associativo a destra
int isRightAssociative(char op) {
    if (op == '^') {
        return 1;  // ^ è associativo a destra
    }
    return 0;  // tutti gli altri sono associativi a sinistra
}

// Converti da Infix a Postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack();  // CORRETTO: dichiarare stack
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        // Ignora gli spazi
        if (c == ' ') {
            continue;
        }
        
        // Se è un operando, aggiungilo a postfix
        if (isoperand(c)) {
            postfix[j++] = c;
            postfix[j++] = ' ';
        }
        
        // Se è '(', aggiungilo allo stack
        else if (c == '(') {
            push(stack, c);
        }
        
        // Se è ')', togli fino a trovare '('
        else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            
            // CORRETTO: controlla se c'è '(' corrispondente
            if (isEmpty(stack)) {
                printf("Errore: parentesi non bilanciate!\n");
                return;
            }
            
            pop(stack);  // Scarta la '('
        }
        
        // Se è un operatore
        else {
            // Togli operatori con precedenza maggiore
            while (!isEmpty(stack) && 
                   peek(stack) != '(' && 
                   precedence(peek(stack)) > precedence(c)) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            
            // Caso speciale per operatori non destri associativi
            if (!isEmpty(stack) && 
                peek(stack) != '(' && 
                precedence(peek(stack)) == precedence(c) && 
                !isRightAssociative(c)) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            
            push(stack, c);
        }
    }
    
    // Aggiungi gli operatori rimasti
    while (!isEmpty(stack)) {
        char op = pop(stack);
        
        if (op == '(') {
            printf("Errore: parentesi non bilanciate!\n");
            return;
        }
        
        postfix[j++] = op;
        postfix[j++] = ' ';
    }
    
    postfix[j] = '\0';  // Termina la stringa
    free(stack);
}

// MAIN
int main() {
    char infix[100];
    char postfix[100];
    
    printf("Inserisci l'espressione infix: ");
    scanf("%99[^\n]", infix);  // CORRETTO: limite di caratteri
    
    infixToPostfix(infix, postfix);
    
    printf("Espressione postfix: %s\n", postfix);
    
    return 0;
}