#include <stdio.h>

int THRESHOLD = 3;

void my_pause() {
    char temp[4];
    if(fgets(temp, sizeof(temp), stdin) == NULL) {
        printf("Error Null pointer return.\n");
    }
}
