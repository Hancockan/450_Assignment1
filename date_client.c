/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "date.h"


void
date_prog_1(host, info_num)
char *host;
int info_num;
{
	CLIENT *clnt;
	char * *result_1;
	long  date_1_arg = info_num;

#ifndef	DEBUG
	clnt = clnt_create (host, DATE_PROG, DATE_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = date_1(&date_1_arg, clnt);
//	printf("The response was %s\n", *result_1);
	if (result_1 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (argc, argv)
int argc;
char *argv[];
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	if (argc < 3) {
		printf("Need more arguments. Quitting...\n");
		exit(1);
	}

	//get the number that corresponds to the data that the client wants
	int num = atoi(argv[2]);
	printf("the number requested was %d\n", num);	


	date_prog_1 (host, num);
exit (0);
}