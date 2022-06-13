enum Day {MON = 0, TUE, WED, THU, FRI, SAT, SUN, numberOfDays};
enum Action {DAY_EARLIER = 0, DAY_LATER, TIME_EARLIER, TIME_LATER = 3};

const char days[numberOfDays][20] = {"poniedziałek", "wtorek", "środa", "czwartek", "piątek", "sobota", "niedziela"};

const char* dayToString(enum Day day){
    return (char*)days[day];
}

enum Action* parse(int arr_size, char *arr[]){
    enum Action *action_types = malloc(arr_size*sizeof(enum Action));
    int counter = 0;

    for(int i = 0; i < arr_size; i++){
        char* value = arr[i];
        if(!strcmp(value,"d-"))
            action_types[counter++] = DAY_EARLIER;
        else if(!strcmp(value,"d+"))
            action_types[counter++] = DAY_LATER;
        else if(!strcmp(value,"t-"))
            action_types[counter++] = TIME_EARLIER;
        else if(!strcmp(value,"t+"))
            action_types[counter++] = TIME_LATER;
        else
            action_types[counter++]=5;
    }
    // if(arr_size != counter)
        // action_types = realloc(action_types, counter*sizeof(enum Action)));

    return action_types;
}

enum Day getEnumNextDay(enum Day day){
    return day == SUN ? MON : day+1;
}
enum Day getEnumPrevDay(enum Day day){
    return day == MON ? SUN : day-1;
}
enum Day getEnumFromStr(char *str_day){
    if(!strcmp(str_day, "Mon"))
        return MON;
    if(!strcmp(str_day, "Tue"))
        return TUE;
    if(!strcmp(str_day, "Wed"))
        return WED;
    if(!strcmp(str_day, "Thu"))
        return THU;
    if(!strcmp(str_day, "Fri"))
        return FRI;
    if(!strcmp(str_day, "Sat"))
        return SAT;
    if(!strcmp(str_day, "Sun"))
        return SUN;
}
