#ifdef CMAKE_CONFIG
#include "cmake_config.h"
#else
#include "autoconf_config.h"
#endif
#if HAVE_STDIO_H
#include<stdio.h>
#endif
#if HAVE_UNISTD_H
#include<unistd.h>
#endif
#if HAVE_IO_H
#include<io.h>
#endif
#if HAVE_FCNTL_H
#include<fcntl.h>
#endif
#if HAVE_STDLIB_H
#include<stdlib.h>
#endif
#if HAVE_MALLOC_H
#include<malloc.h>
#endif
#if HAVE_STRING_H
#include<string.h>
#endif
#if !HAVE_PRINTF_S
#define printf_s printf
#endif

int create_pipe(int fildes[2], unsigned int mem) {
#if HAVE__PIPE
#if !HAVE_DECL_O_BINARY
#define O_BINARY 0x8000
#endif
    return _pipe(fildes, mem, O_BINARY);
#elif HAVE_PIPE
    return pipe(fildes);
#endif
}

int read_pipe(int fildes, void *buf, size_t nbyte) {
#if HAVE__READ
    return _read(fildes, buf, nbyte);
#elif HAVE_READ
    return read(fildes, buf, nbyte);
#endif
}

int write_pipe(int fildes, const void *buf, size_t nbyte) {
#if HAVE__PIPE
	return _write(fildes, buf, nbyte);
#elif HAVE_PIPE
	return write(fildes, buf, nbyte);
#endif
}

enum PIPES { READ, WRITE };

int main() {
    int f[2];
    if (create_pipe(f, 10240)) {
        return -1; 
    }
	char *s = "Hello World!";
	int l = strlen(s);
	int bw = write_pipe(f[WRITE], s, l);
	printf_s("Write %d bytes to pipe.\n", bw);
	char *s2 = (char*)malloc(l);
	int lw = read_pipe(f[READ], s2, l);
	printf_s("Read %d bytes from pipe.\n", lw);
	free(s2);
    return 0;
}
