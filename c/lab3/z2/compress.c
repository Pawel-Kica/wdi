void compress(char** tekst)
{
    char *output;

    int resultLen = 0;
    
    char current = tekst[0];

    int tekstLen = strlen(tekst);
    
    int currentLen = 1;
    
    for(int j=1; j< tekstLen; j++)
    {    
        bool flag = true;
        
        if(j == tekstLen-1){
            currentLen++;
            flag = false;  
        }
        
        if(tekst[j] == current || flag)
        {
            currentLen++; 
        }
        else{
            if (currentLen>4 | current == '(' || current == ')' || current == '%'){
                if(currentLen>4){
                    output[resultLen] = "%";
                    resultLen++;
                    
                    output[resultLen] = charToHex(current/16);
                    resultLen++;
                    
                    output[resultLen] = charToHex(current%16);
                    resultLen++;
                    
                    
                }else{
                    output[resultLen] = current;
                    resultLen++;
                }
                
                output[resultLen] = "(";
                resultLen++;
        
                output[resultLen] = currentLen;
                resultLen++;
                    
                output[resultLen] = ")";
                resultLen++;
            }else{
                for(int z=0;z<current;z++){
                    output[resultLen] = current;
                    resultLen++;
                }
            }
            
            currentLen = 0;
            current = tekst[j];
        }
    }
    
}