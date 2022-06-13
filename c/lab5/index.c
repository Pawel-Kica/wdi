#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "helpers.c"

int main(int argc, char **argv)
{
    Lesson *lesson_obj = create_lesson(12, 29, 90, THU, "Podstawy programowania");
    printf("Przed uwzglednieniem przesunięciem:");
    printf("\n\t%s\n", Lesson__toString(lesson_obj));
    Action *action_types = parse(argc - 1, argv + 1);

    for (int i = 0; i < argc - 1; ++i)
    {
        switch (action_types[i])
        {
        case DAY_EARLIER:
            printf("Dzień w tył\n");
            Lesson__earlierDay(lesson_obj);
            break;
        case DAY_LATER:
            printf("Dzień w przód\n");
            Lesson__laterDay(lesson_obj);
            break;
        case TIME_EARLIER:
            printf("Termin w tył\n");
            Lesson__earlierTime(lesson_obj);
            break;
        case TIME_LATER:
            printf("Termin w przód\n");
            Lesson__laterTime(lesson_obj);
            break;
        }
    }
    printf("Po uzwlednieciu przesunięc:");
    printf("\n\t%s\n", Lesson__toString(lesson_obj));
}
