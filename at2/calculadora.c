#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct {
    double itens[MAX];
    int topo;
} Pilha;

void init(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, double valor) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Erro: Stack Overflow\n");
    }
}

double pop(Pilha *p) {
    if (!isEmpty(p)) {
        return p->itens[(p->topo)--];
    }
    printf("Erro: Expressão malformada\n");
    return 0;
}

double calcularRPN(char *expressao) {
    Pilha p;
    init(&p);
    
    char *token = strtok(expressao, " ");
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&p, atof(token));
        } else {
            double op2 = pop(&p);
            double op1 = pop(&p);
            
            switch (token[0]) {
                case '+': push(&p, op1 + op2); break;
                case '-': push(&p, op1 - op2); break;
                case '*': push(&p, op1 * op2); break;
                case '/': push(&p, op1 / op2); break;
                case '^': push(&p, pow(op1, op2)); break;
                default: printf("Operador desconhecido: %s\n", token);
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&p);
}

int main() {
    char expressao[100] = "10 2 / 3 +";
    printf("Expressão: %s\n", expressao);
    printf("Resultado: %.2f\n", calcularRPN(expressao));
    
    return 0;
}