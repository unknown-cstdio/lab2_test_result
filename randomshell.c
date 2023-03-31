#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

int
main(int argc, char **argv)
{
    char buf[TERMINAL_MAX_LINE];
    char *cmd_argv[TERMINAL_MAX_LINE];  /* An overkill for expediency */
    char *prompt = "yalnix> ";
    char separators[4];
    int termno;

    separators[0] = ' ';
    separators[1] = '\t';
    separators[2] = '\n';
    separators[3] = '\0';

    char *tests[23] = {"bigstack", "blowstack", "brktest", "forktest0", "forktest1b", "forktest2b", "forktest3", "forkwait0c", 
                    "forkwait0p", "forkwait1", "forkwait1b", "forkwait1c", "forkwait1d", "init1", "init2", "init3", "trapillegal", "trapmath", "trapmemory",
                    "ttywrite1", "ttywrite2", "ttywrite3", "nonexistent"};

    if (argc < 2) {
	TtyPrintf(TTY_CONSOLE, "usage: shell termno\n");
	Exit(1);
    }
    termno = atoi(argv[1]);
    srand(time(NULL) + termno);
    if ((termno < 0) || (termno >= NUM_TERMINALS)) {
	TtyPrintf(TTY_CONSOLE, "shell: invalid terminal number %d\n", termno);
	Exit(1);
    }

    TtyPrintf(termno, "Starting shell....\n");

    while (1)
    {
	int n, pid, pid2;
	int status;
    int arg = 0;

	TtyPrintf(termno, prompt);


	n = rand() % 23;
    cmd_argv[0] = tests[n];
    cmd_argv[1] = NULL;

	if (n == 1) {
        arg = rand() % 50;
        sprintf(cmd_argv[1], "%d\n", arg);
    }


	pid = Fork();


	if (pid < 0) {
	    TtyPrintf(termno, "Cannot Fork process\n");
	    continue;
	}

	if (pid == 0) {
        TtyPrintf(termno, "Executing %s %d\n", cmd_argv[0]);
        TracePrintf(5, "Executing %s %d\n", cmd_argv[0]);
	    Exec(tests[n], cmd_argv);
	    TtyPrintf(termno, "Could not Exec `%s'\n", cmd_argv[0]);
	    Exit(1);
	}

	pid2 = Wait(&status);
	if (pid2 < 0) {
	    TtyPrintf(termno, "Wait returned error!\n");
	    continue;
	}
	if (pid2 == pid) {
	    TtyPrintf(termno, "Pid %d exited with status %d\n",
		pid2, status);
	}
	else {
	    TtyPrintf(termno, "Mystery pid %d exited with status %d\n",
		pid2, status);
	}
    }
    (void) separators;
    (void) buf;
}
