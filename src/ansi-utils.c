#include <stdio.h>
#include <string.h>

int THRESHOLD = 3;

void my_pause() {
    char temp[4];
    if(fgets(temp, sizeof(temp), stdin) == NULL) {
        printf("Error Null pointer return.\n");
    }
}
void ansi_copy_str(char *dest, char *source) {
    int len = strlen(source);
    strncpy(dest, source, len);
    dest[len] = '\0';
}

void extract_ip(char *source, char *des) {
    char *temp, *temp2;
    temp = strchr(source, ':');
    temp++;
    temp2 = strchr(temp, ':');
   // memset(des, 0, sizeof(des));
    strncpy(des, temp, temp2 -temp);
    des[temp2-temp] = '\0';
}

void extract_port(char *des, char *source) {
    char *temp, *temp2;
    temp = strchr(source, ':');
    temp++;
    temp2 = strchr(temp, ':');
    temp2++;

    strncpy(des, temp2, strlen(temp2));
    des[strlen(temp2)] = '\0';
}
