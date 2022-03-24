#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int timestamp(void) {
	FILE *fp;
	FILE *fpw;
	FILE *fpc;
	FILE *fpr;
	char msg[100];
	int index = 0;
	
	fp = fopen("./last_run.json", "r");
	
	// Create last_run.json if it doesn't exist
	if (fp == NULL) {
		fpc = fopen("./last_run.json", "w");
		fprintf(fpc, "{\"last run\": \"0\\00\\0000 00:00\"}");
		fclose(fpc);		
	}
	fclose(fp);

	fpr = fopen("./last_run.json", "r");

	// Read last_run.json and print when last run
	while (1) {
		int c = fgetc(fpr);
		if (c == EOF) {
			msg[index] = '\0';
			break;
		}
		switch(c) {
			case '\\': case '{': case '}': case '"':
				break;
			default:
				msg[index] = c;
				index++;
		}
	}

	fclose(fpr);
	printf("%s\n", msg);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	char date[1024];
	snprintf(date, sizeof(date), "%d/%02d/%02d %02d:%02d", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

	fpw = fopen("./last_run.json", "w");
	fprintf(fpw, "{\"last run\": \"%s\"}", date);
	fclose(fpw);

	return 0;
}
