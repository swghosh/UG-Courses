#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 8
#define FLAG '~'
#define ESC '^'

struct frames {
    char **frames;
    int len_frames;
};
#define FRAMES struct frames

FRAMES byte_stuff(char *input, int len_input) {
    FRAMES f;
    int iter_index, another_index, frame_index;
    
    f.len_frames = (len_input / FRAME_SIZE) + ((len_input % FRAME_SIZE == 0) ? 0 : 1);
    f.frames = malloc(sizeof(char*) * f.len_frames);

    for(iter_index = 0; iter_index < f.len_frames; iter_index++) {
        f.frames[iter_index] = malloc(sizeof(char) * FRAME_SIZE * 2);
        for(another_index = 0; another_index < FRAME_SIZE * 2; another_index++) {
            f.frames[iter_index][another_index] = '\0';
        }
    }

    frame_index = another_index = 0;
    for(iter_index = 0; iter_index < len_input; iter_index++) {
        if((iter_index - 1) % FRAME_SIZE == 0) {
            frame_index = iter_index / FRAME_SIZE;
            another_index = 0;
        }
        switch(input[iter_index]) {
            case FLAG:
                f.frames[frame_index][another_index++] = ESC;
                f.frames[frame_index][another_index++] = FLAG;
                break;
            case ESC:
                f.frames[frame_index][another_index++] = ESC;
                f.frames[frame_index][another_index++] = ESC;
                break;
            default:
                f.frames[frame_index][another_index++] = input[iter_index];
        }
    }

    return f;
}


int main() {
    char *input, *output;
    int len, iter_index;

    printf("How many bytes of data? (integer expected): ");
    scanf("%d", &len);

    input = malloc(sizeof(char) * len);

    printf("Input data bytes? (%u characters expected): \n", len);
    for(iter_index = 0; iter_index < len; iter_index++) {
        scanf("%c", input + iter_index);
    }

    FRAMES f;
    f = byte_stuff(input, len);
    for(iter_index = 0; iter_index < f.len_frames; iter_index++) {
        printf("%s\n", f.frames[iter_index]);
    }
}