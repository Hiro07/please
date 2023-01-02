/*========================================
 *    please.c: please command version 1.0.1
 *        Copyright 2023
 *                  Hiroyuki Kikuchi (hjfk07@gmail.com)
 *        Last Modified: 2023/01/02
 *========================================
 */
/* please version 1.0.0 : the first release.                                    */
/*                                              by Hiroyuki Kikuchi  2023/01/02 */
/* please version 1.0.1 : Enabled to handle pipeline input.                     */
/*                        Changed versioning number from v1.00 to v1.0.0        */
/*                                              by Hiroyuki Kikuchi  2023/01/03 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <err.h>
#define BUF_SIZE 1024

int main(int argc, const char *argv[]) {
    int i;

    // debug args
    /*
    printf("argc: %d¥r¥n", argc);
    for(i=0; i<argc; i++) {
        printf("argv[%d]: %s¥n", i, argv[i]);
    }
    */

    if(argc < 2) {
        if (!isatty(STDIN_FILENO)) {
            // pipeline input
            char line[BUF_SIZE];
            while(fgets(line, sizeof(line), stdin)) {
                printf("%s", line);
            }
        } else {
            // not pipeline input
            printf("OK.");
        }
    } else {
        FILE *fp;
        int cmdSize = 0;

        for(i=1; i<argc; i++) {
            cmdSize += strlen(argv[i]) + 1;
        }

        char cmd[cmdSize];

        /* make command */
        for(i=1; i<argc; i++) {
            strcat(cmd, argv[i]);
            strcat(cmd, " ");
        }
        //printf("cmd: %s¥r¥n", cmd);

        /* show welcom randomly */
        /*
        srand((unsigned int)time(NULL));
        int rnd = rand();
        if(rnd % 2 == 0) {
            printf("You're welcome. The execution result is below.");
        }
        */

	    if ( (fp=popen(cmd,"r")) ==NULL) {
		    perror ("please: popen failure.");
		    exit(EXIT_FAILURE);
	    }

	    char buf[BUF_SIZE];
	    while (!feof(fp)) {
		    fgets(buf, sizeof(buf), fp);
		    printf("%s", buf);
	    }
 
	    (void) pclose(fp);
 
    }
	exit (EXIT_SUCCESS);
}
