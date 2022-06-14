#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct stack {
    int size;
    int no_elements;
    int *data;
} stack;

stack *Stack_create(int size) {
    if (size<1) {
        fprintf(stderr, "Stack create - nie udało się utworzyć stosu\n");
        exit(EXIT_FAILURE);
    }
    stack *st = malloc(sizeof(stack));
    st->size = size;
    st->no_elements = 0;
    st->data = malloc(st->size * sizeof(int));
    if (st==NULL || st->data == NULL) {
        fprintf(stderr, "Stack create - nie udało się utworzyć stosu\n");
        exit(EXIT_FAILURE);
    }
    return st;
}

void Stack_destroy(stack **st) {
    if ((*st) == NULL) {
        fprintf(stderr, "Stack_destroy - stos nie istnieje\n");
    }else{
        free((*st)->data);
        free(*st);
        (*st)=NULL;
    }
}

void Stack_push(stack *st, int number) {
    if ((st) == NULL) {
        fprintf(stderr, "Stack_push - stos nie istnieje\n");
    }else{
        if (st->no_elements + 1 > st->size) {
            fprintf(stderr, "Stack_push - przekraczamy rozmiar stosu\n");
        }else{
            st->data[st->no_elements] = number;
            st->no_elements++;
        }
    }
}

int Stack_pop(stack *st) {
    if ((st) == NULL) {
        fprintf(stderr, "Stack_pop - stos nie istnieje\n");
    }else{
        if(st->no_elements == 0){
            fprintf(stderr, "Stack_pop - stos posiada 0 elementów\n");
            return INT_MIN;
        }else{
            return st->data[--st->no_elements];
        }
    }
}

void Stack_print(stack *st) {
    if ((st) == NULL) {
        fprintf(stderr, "Stack_print - stos nie istnieje\n");
    }else{
        if(st->no_elements == 0){
            printf("Stack_print - Stos posiada 0 elementow\n");
        }else{
            for(int i=0;i<st->no_elements;i++){
                printf("%d \n", st->data[st->no_elements-i-1]);
            }
        }
    }
}

int main(void),
{
    stack *my_stack = NULL;

    Stack_print(my_stack);
    Stack_destroy(&my_stack); // Wypisuje: "Stos nie istnieje"
    my_stack = Stack_create(3); // Utworzenie stosu o rozmiarze 3
    Stack_push(my_stack, 3); // Dodanie liczby 3 na stos
    Stack_push(my_stack, 5);
    Stack_push(my_stack, 2);
    Stack_push(my_stack, 4); // Przekraczamy rozmiar stosu — funkcja nie powinna na to pozwolić
    Stack_print(my_stack); // Funkcja powinna wypisać:
                         // 2
                         // 5
                         // 3
    printf("%d\n", Stack_pop(my_stack)); // Wypisuje 2
    printf("Stack print \n");
    Stack_print(my_stack); // Funkcja powinna wypisać:
    //                      // 5
    //                      // 3
    printf("Stack pop \n");
    printf("%d\n", Stack_pop(my_stack)); // Wypisuje 5
    printf("%d\n", Stack_pop(my_stack)); // Wypisuje 3

    int liczba = Stack_pop(my_stack); // Próbujemy zdjąć wartość z pustego stosu  — funkcja nie powinna na to pozwolić — powinna zwrócić wartość specjalną, na przykład INT_MIN
    printf("%i \n",liczba);

    Stack_destroy(&my_stack); // Likwidacja stosu
    Stack_destroy(&my_stack); // Wypisuje: "Stos nie istnieje"
    return 0;
}