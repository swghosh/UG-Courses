#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_char(char symbol) {
    /** Marks as valid if given character is either 'a' or 'b'.
     * char symbol: character to be tested for validity
     */
    return (symbol == 'a') || (symbol == 'b'); 
}

bool parse_string(char *string, int len) {
    /** Accepts a string that ends in "aaa".
     * char string: pointer to char array holding the string
     * int len: length of the string
     */
    short state = 0;
    int idx; char symbol;

    for(idx = 0; idx < len; idx++) {
        symbol = *(string + idx);
        
        if(is_valid_char(symbol) == false) {
            printf("Invalid character found.\n");
            return false;
        }

        if(state == 0 && symbol == 'a') state = 1;
        else if(state == 0 && symbol == 'b') state = 0;
        else if(state == 1 && symbol == 'a') state = 2;
        else if(state == 1 && symbol == 'b') state = 0;
        else if(state == 2 && symbol == 'a') state = 3;
        else if(state == 2 && symbol == 'b') state = 0;
        else if(state == 3 && symbol == 'a') state = 3;
        else if(state == 3 && symbol == 'b') state = 0;
    }
    return state == 3;
}


int main() {
    /** Main function that is executed at runtime.
     * User inputs a string which is passed to 
     * an automaton and is only accepted if
     * the string ends in "aaa". Valid characters
     * are only 'a', 'b'.
     */
    char *input_string; bool valid; int len;

    printf("Input string: ");
    scanf("%s", input_string);

    len = strlen(input_string);
    valid = parse_string(input_string, len);

    puts(valid ? "String accepted by DFA.": "String not accepted by DFA.");
    return 0;
}
