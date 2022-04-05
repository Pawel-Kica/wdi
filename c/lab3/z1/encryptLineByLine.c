char* encryptLineByLine(){
    
    char* output = NULL;
    size_t useless1 = sizeof(NULL);
    
    int length = 0;

	length = getline(&output, &useless1, stdin);

    if(length == -1)
        return NULL;

    encryptCaeser(output);

    return output;
}