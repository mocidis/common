#ifndef __ANSI_UTILS_H__
#define __ANSI_UTILS_H__
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void my_pause();

void ansi_copy_str(char *dest, char *src);

extern int THRESHOLD;

#define UNUSED(x) \
    (void)(x)

#define SET_LOG_LEVEL(level) \
    if (level >= 1 && level <=5) THRESHOLD = level

#define SHOW_LOG(level, print_op) \
    if (level <= THRESHOLD) print_op

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
    SHOW_LOG(3, fprintf(stdout, "ERROR:: %s - %d - %s\n", message, errno, strerror(errno))); \
}

#define RETURN_IF_TRUE(clause, message) if(clause) { \
    fprintf(stderr, message); \
    exit(-1); \
}

void extract_ip(char *source, char *des);

#endif
