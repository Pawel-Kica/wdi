char charToHex(char singleCharacter){
    
    if(singleCharacter > 9){
        return singleCharacter + '7'; // 55
    }else{
        return singleCharacter + '0'; // 48
    }
}