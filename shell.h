#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <fnctl.h>
#include <errno.h>


/* used for reading/writing buffers */
#define WRITE_BUFFER_SIZE	1024
#define READ_BUFFER_SIZE	1024
#define BUFFER_FLUSH		-1

