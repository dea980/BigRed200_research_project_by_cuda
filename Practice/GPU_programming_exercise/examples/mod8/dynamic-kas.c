

void main(void {

    char * myWord;

    myFunc()

    for (int i = 0; i < 1000000; i++)
       myWord = myFunc();
}

char * myFunc(void) {
    char * aPtr;
    aPtr = malloc(30);
    //do something with aPtr
    free(aPtr);
    aPtr = NULL;
    return aPtr;
}