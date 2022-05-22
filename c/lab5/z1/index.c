#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions.c"

int main(int argc, char**argv){
    if(argc < 2){
		printf("Invalid data type\n");
        return 1;
    }

    enum Day day = getEnumFromStr(argv[1]);
    enum Action *action_types = parse(argc - 2, argv + 2);

    for(int i = 0; i < argc - 2; ++i){
        switch(action_types[i]){
            case DAY_EARLIER:
                printf("Dzień w tył\n");
                day = getEnumPrevDay(day);
                break;
            case DAY_LATER:
                printf("Dzień w przód\n");
                day = getEnumNextDay(day);
                break;
            case TIME_EARLIER:
                printf("Termin w tył\n");
                break;
            case TIME_LATER:
                printf("Termin w przód\n");
                break;
        }
    }
    printf("Wynik przesunięcia: %s\n", dayToString(day));
}