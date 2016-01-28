#ifndef __ANSI_UTILS_H__
#define __ANSI_UTILS_H__
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
void my_pause();

void ansi_copy_str(char *dest, char *src);

extern int THRESHOLD;

extern void (*showLog)(int level, const char *data, int len);

#define UNUSED(x) \
    (void)(x)

#define SET_LOG_LEVEL(level) \
    if (level >= 1 && level <=5) THRESHOLD = level

void SHOW_LOG(int level, const char *format, ...);

#define ANSI_CHECK(f, op) \
    do { \
        if ( 0 != op ) { \
            fprintf(stderr, "%s - %s error: %s\n", f, #op, strerror(errno)); \
            exit(-1); \
        } \
    }  while(0)

#define ANSI_PANIC(f, msg) \
    fprintf(stderr, "%s - %s\n", f, msg);\
    exit(-1)

#define EXIT_IF_TRUE(clause, message) if(clause) { \
    fprintf(stderr, message); \
    exit(-1); \
}

#define PERROR_IF_TRUE(clause, message) if(clause) { \
    SHOW_LOG(3, "ERROR:: %s - %d - %s\n", message, errno, strerror(errno)); \
}

#define RETURN_IF_TRUE(clause, message) if(clause) { \
    fprintf(stderr, message); \
    exit(-1); \
}

void extract_ip(char *source, char *des);
void extract_port(char *des, char *source);

uint32_t get_ts();
int ts2str(uint32_t ts, char *sts);
#endif
