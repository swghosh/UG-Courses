#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_char(char symbol) {
    return (symbol == 'a') || (symbol == 'b'); 
}

bool parse_string(char *string, int len) {
    short state = 0;
    int idx; char symbol;

    for(idx = 0; idx < len; idx++) {
        symbol = *(string + idx);
        
        if(is_valid_char(symbol) == false) {
            printf("Invalid character found.\n");
            return false;
        }

        if(state == 0 && symbol == 'a') {
            state = 1;
        }
        else if(state == 0 && symbol == 'b') {
            state = 0;
        }
        else if(state == 1 && symbol == 'a') {
            state = 2;
        }
        else if(state == 1 && symbol == 'b') {
            state = 0;
        }
        else if(state == 2) {
            break;
        }
    }
    return state == 2;
}


int main() {
    char *input_string; bool valid; int len;

    printf("Input string: ");
    scanf("%s", input_string);

    len = strlen(input_string);
    valid = parse_string(input_string, len);

    puts(valid ? "String accepted by DFA.": "String not accepted by DFA.");
    return 0;
}