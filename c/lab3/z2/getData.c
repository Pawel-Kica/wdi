char** getData(){

    // general
    int length = 0;
    char** output = malloc(3 * sizeof(char*));
    
    // getline
    char* input = NULL;
    size_t useless = sizeof(NULL);
    size_t line_counter = 0;
    
    while(1){

        length = getline(&input, &useless, stdin);
        if(length == -1){
            break;
        }

        if(line_counter > 2){
            output = (char**)realloc(output, line_counter * sizeof(char*));
        }

        *(output + line_counter) = malloc(length * sizeof(char));   
        memcpy(*(output + line_counter), input, length * sizeof(char)); 
        line_counter++;    
    }

    return output;
}