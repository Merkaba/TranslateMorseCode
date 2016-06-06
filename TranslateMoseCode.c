#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void translateAlpha(char * s){
    int counter;
    counter = 0;
    while(s[counter] != '\0'){
        alphaToMorse(s[counter]);
        counter++;
    }
    printf("\n");
}


void translateLetter(char * input){
    char * a[30];
    a[0] = ".-";
    a[1] = "-...";
    a[2] = "-.-." ;
    a[3] = "-..";
    a[4] = "."; //E
    a[5] = "..-." ;
    a[6] = "--.";
    a[7] = "....";
    a[8] = "..";
    a[9] = ".---";//J
    a[10] = "-.-";
    a[11] = ".-..";
    a[12] = "--";
    a[13] = "-.";
    a[14] = "---";//O
    a[15] = ".--.";
    a[16] = "--.-";
    a[17] = ".-.";
    a[18] = "...";
    a[19] = "-";//T
    a[20] = "..-";
    a[21] = "...-";
    a[22] = ".--";
    a[23] = "-..-";
    a[24] = "-.--";//Y
    a[25] = "--.-";
    char * alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int i = 0;
    for(; i < 26; i++){
        if( strcmp(input, a[i]) == 0){
            printf("%c", alphabet[i]);
        }
    }
}

char * moveToBuffer(char * buffer, char * input, int * inputCounter, int * printflag){
    int counter = 0;
    while(input[*inputCounter]){
        if(input[*inputCounter] == ' ' || input[*inputCounter] == '\n' || input[*inputCounter] == '\0'){
            if(input[*inputCounter] == ' '){
                int newCounter = 0;
                for(; newCounter < 7; newCounter++){
                    if(input[*inputCounter + newCounter] != ' '){
                        *printflag = 0;
                        break;
                    }
                    *printflag = 1;
                }
            }
            (*inputCounter)++;
            buffer[counter] = '\0';
            return buffer;
        }
        buffer[counter] = input[*inputCounter];
        counter++;
        (*inputCounter)++;
    }
    return NULL;
}

void translateMorse(char * input){
    char buffer[100];
    int inputCounter = 0;
    while(input[inputCounter]){
        int printflag = 0;
        moveToBuffer(buffer, input, &inputCounter, &printflag);
        
        translateLetter(buffer);
    }
    printf("\n"); 
}


void morseOrAlpha(char * s){
    char c;
    c = s[0];
    switch(c)
    {
        case '.':
        case '-':
            translateMorse(s);
            break;
        default:
            translateAlpha(s);
            break;
    }
}

void alphaToMorse(char c){
    switch(toupper(c)){
        case 'A':
            printf(".-");
            break;
        case 'B':
            printf("-...");
            break;
        case 'C':
            printf("-.-.");
            break;
        case 'D':
            printf("-..");
            break;
        case 'E':
            printf(".");
            break;
        case 'F':
            printf("..-.");
            break;
        case 'G':
            printf("--.");
            break;
        case 'H':
            printf("....");
            break;
        case 'I':
            printf("..");
            break;
        case 'J':
            printf(".---");
            break;
        case 'K':
            printf("-.-");
            break;
        case 'L':
            printf(".-..");
            break;
        case 'M':
            printf("--");
            break;
        case 'N':
            printf("-.");
            break;
        case 'O':
            printf("---");
            break;
        case 'P':
            printf(".--.");
            break;
        case 'Q':
            printf("--.-");
            break;
        case 'R':
            printf(".-.");
            break;
        case 'S':
            printf("...");
            break;
        case 'T':
            printf("-");
            break;
        case 'U':
            printf("..-");
            break;
        case 'V':
            printf("...-");
            break;
        case 'W':
            printf(".--");
            break;
        case 'X':
            printf("-..-");
            break;
        case 'Y':
            printf("-.--");
            break;
        case 'Z':
            printf("--..");
            break;
        case '1':
            printf(".----");
            break;
        case '2':
            printf("..---");
            break;
        case '3':
            printf("...--");
            break;
        case '4':
            printf("....-");
            break;
        case '5':
            printf(".....");
            break;
        case '6':
            printf("-....");
            break;
        case '7':
            printf("--...");
            break;
        case '8':
            printf("---..");
            break;
        case '9':
            printf("----.");
            break;
        case '0':
            printf("-----");
            break;
        case ' ':
            printf("    "); //only 4 spaces because already printing
            break;          //3 spaces inbetween each letter
    }         
    printf("   ");//print 3 spaces between letters
 
}   

int main(){
    char input[200];
    while(1){
        fgets( input, 100, stdin );
        morseOrAlpha( input );
        strcpy(input, "");
    }
    
    return 0;
}

