#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <time.h>

int THRESHOLD = 3;

void log_function_default(int level, const char *data, int len) {
    fprintf(stdout, "%.*s", len, data);
}
void (*log_f)(int level, const char *data, int len) = &log_function_default;

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

void SHOW_LOG(int level, const char *format, ...) {
    va_list arg;
    char buffer[200];
    int len;
    if (level <= THRESHOLD) {
        va_start(arg, format);
        len = vsprintf(buffer, format, arg);
        log_f(level, buffer, len);
        va_end(arg);
    }
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

uint32_t get_ts() {
    time_t ts;
    ts = time(NULL);
    return (uint32_t) ts;
}

int ts2str(uint32_t ts, char *sts) {
    int n = sprintf(sts, "%u", ts);
    sts[n] = '\0';
    return n;
}
