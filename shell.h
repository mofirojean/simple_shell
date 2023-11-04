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

/* ### DEFINING SIMPLE_SHELL MACROS ### */

/* use for reading/writing buffers */
#define WRITE_BUFFER_SIZE	1024
#define READ_BUFFER_SIZE	1024
#define BUFFER_FLUSH		-1

/* use for converting numbers in convert_number() */
#define CONVERSION_LOWERCASE	1
#define CONVERSION_UNSIGNED	2

/* it's 1 if using the system getline() */
#define USE_SYS_GETLINE		0
#define USE_STRTOK_FUNC		0

/* use for command chaining */
#define COMMAND_NORMAL		0
#define COMMAND_OR		1
#define COMMAND_AND		2
#define	COMMAND_CHAIN		3

/* use for shell history files and size */
#define SHELL_HIST_FILE		".ss_history"
#define SHELL_HIST_MAX_ENTRIES	4096

#endif
