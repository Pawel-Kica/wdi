#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum{
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
    numberOfDays
}Day;
const char days[numberOfDays][20] = {"poniedziałek", "wtorek", "środa", "czwartek", "piątek", "sobota", "niedziela"};

typedef struct{
    char *className;
    Day day;
    int hour;
    int minute;
    int duration;
}Lesson;
typedef struct Node{
    Lesson lesson;
    struct Node *next;
}Node;

void List_insert(Node **list, Lesson lesson, bool begin){
    if(list==NULL){
        fprintf(stderr,"List_insert - lista nie istnieje \n");
    }else{
        Node *wezel = malloc(sizeof(Node));
        wezel->lesson=lesson;

        if(begin){
            wezel->next = *list;
            *list=wezel;
        }else{
            wezel->next=NULL;
            Node *iterator = *list;
            while(iterator->next) iterator=iterator->next;
            iterator->next=wezel;
        }
    }
}

void List_print(Node **list) {
    if (list == NULL) {
        fprintf(stderr, "List_print - lista nie istnieje\n");
    }else{
        Node *iterator = *list;
        while(iterator) {
            printf("Przedmiot: \e[31m%s\e[0m\nDzień tygodnia: \e[31m%s\e[0m\nGodzina rozpoczęcia [Czas trwania]: \e[31m%02d:%02d [%d]\e[0m\n\n", iterator->lesson.className, days[iterator->lesson.day], iterator->lesson.hour, iterator->lesson.minute, iterator->lesson.duration);
            iterator=iterator->next;
        }
    }

}
bool If_lessons_are_the_same(Lesson lesson_1, Lesson lesson_2) {
    if(lesson_1.day != lesson_2.day){
        return false;
    }
    if(lesson_1.duration != lesson_2.duration) {
        return false;
    }
    if(lesson_1.hour != lesson_2.hour){
        return false;
    }
    if(lesson_1.minute != lesson_2.minute){
        return false;
    }
    if(strcmp(lesson_1.className, lesson_2.className)){
        return false;
    }
    return true;
}
void List_remove(struct Node **list, Lesson lesson){
    if (list == NULL) {
        fprintf(stderr, "List_remove - lista nie istnieje\n");
    }else{
        Node *iterator = *list;
        if(If_lessons_are_the_same(lesson,iterator->lesson)){
            *list=iterator->next;
            free(iterator);
        }
        while(iterator->next) {
            if(If_lessons_are_the_same(lesson,iterator->next->lesson)){
                iterator=iterator->next->next;
                // free(iterator->next->lesson.className);
                free(iterator->next);
                break;
            }
            iterator=iterator->next;
        }
    }
}
void List_destroy(struct Node **list){
    if (list==NULL || *list == NULL) {
        fprintf(stderr, "List_remove - lista nie istnieje\n");
    }else{
        Node *current_element = *list;
        Node *next_element = current_element->next;
        while(current_element) { 
            free(current_element); 
            current_element = next_element;
            if(next_element!=NULL){
                next_element=next_element->next; 
            }
        }
        *list=NULL;
    }
}

int main(void)
{
    Node *list = NULL;
    Lesson lesson;

    lesson.className = "Podstawy Programowania";
    lesson.day = WED;
    lesson.hour = 12;
    lesson.minute = 50;
    lesson.duration = 90;
    List_insert(&list, lesson, true);

    lesson.className = "Wychowanie fizyczne";
    lesson.day = MON;
    lesson.hour = 8;
    lesson.minute = 00;
    lesson.duration = 90;
    List_insert(&list, lesson, true);

    List_print(&list); // Funkcja powinna wypisać:
                       // Wychowanie fizyczne, Poniedziałek 8:00 [90]
                       // Podstawy programowania, Środa 12:50 [90]
    List_remove(&list, lesson);
    printf("Po usunieciu \n\n");
    List_print(&list); // Funkcja powinna wypisać:
                       // Podstawy programowania, Środa 12:50 [90]

    List_destroy(&list); // Likwidacja listy
    List_destroy(&list); // Wypisuje: "Lista nie istnieje"

    return 0;
}