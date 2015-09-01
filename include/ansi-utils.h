#ifndef __ANSI_UTILS_H__
#define __ANSI_UTILS_H__
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void my_pause();
#define CHECK(f, op) \
do { \
			if ( 0 != op ) { \
				fprintf(stderr, "%s - %s error: %s\n", f, #op, strerror(errno)); \
				exit(-1); \
			} \
}  while(0)

#define PANIC(f, msg) \
    fprintf(stderr, "%s - %s\n", f, msg);\
    exit(-1)

#define EXIT_IF_TRUE(clause, message) if(clause) { \
    fprintf(stderr, message); \
    exit(-1); \
}
#define RETURN_IF_TRUE(clause, message) if(clause) { \
    fprintf(stderr, message); \
    exit(-1); \
}

#endif
