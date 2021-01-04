#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfVowels(char* str){
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' ||
           str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' ||
           str[i] == 'u' || str[i] == 'U'){
            count++;
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    int numInput = argc;
    int sizeOfInput = 0;
    for(int i = 1; i < numInput; i++){
      sizeOfInput += strlen(argv[i]);
      //printf("%s\n", argv[i]);
    }
    //printf("%d\n", sizeOfInput);
    char str[sizeOfInput];
    str[0] = '\0';
    //int index = 0;
    for(int i = 1; i < numInput; i++){
      strncat(str, argv[i], strlen(argv[i]));
    }
    //printf("%s\n", str);
    int size = numberOfVowels(str);
    char finalStr[size];
    finalStr[0] = '\0';
    //int count = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' ||
           str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' ||
           str[i] == 'u' || str[i] == 'U'){
            //printf("%c\n", str[i]);
            //char copy = str[i];
            strncat(finalStr, &str[i], 1);
            //printf("%s\n", finalStr);
            //count++;
        }
    }
    printf("%s", finalStr);
    return 0;
}

