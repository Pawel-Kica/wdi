struct Term{
    int hour;
    int minute;
    int duration;
};

void Term__init(struct Term *term_obj, int hour, int minute, int duration){
    term_obj->minute = minute;
    term_obj->hour = hour;
    term_obj->duration = duration;
}
struct Term* Term__create(int hour,int minute, int duration){
    struct Term *term_obj = malloc(sizeof(struct Term));
    Term__init(term_obj,hour,minute,duration);
    return term_obj;
}
void Term__destroy(struct Term *term_obj){
    free(term_obj);
}
char *Term__toString(struct Term *term_obj){
    char *result = malloc(20*sizeof(*result));

    int counter = 0;
    int hour = term_obj->hour;
    int minute = term_obj->minute;
    int duration = term_obj->duration;

    if(hour < 10){
        result[counter++] = '0';
        result[counter++] = hour;
    }
    else{
        result[counter++] = hour/10;
        result[counter++] = hour%10;
    }
    // printf("%i value \n",result[0]);
    // printf("%i value \n",result[1]);
    // printf("%s val\n",result);

    return result;
}

bool Term__earlierThan(struct Term *term1,struct Term *term2){
    if(term1->hour==term2->hour){
        if(term1->minute<term2->minute) return true;
    }
    return term1->hour<term2->hour;
}
bool Term__laterThan(struct Term *term1,struct Term *term2){
    return !Term__earlierThan(term1,term2);
}
bool Term__equals(struct Term *term1,struct Term *term2){
    return (term1->hour==term2->hour && term1->minute==term2->minute);
}
struct Term* Term__endTerm(struct Term *term1,struct Term *term2){
    int duration = 0;
    duration = duration + (term2->hour-term1->hour)*60;
    duration = duration + term2->minute-term1->minute;

    return Term__create(term1->hour,term1->minute,duration);
}