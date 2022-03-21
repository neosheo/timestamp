#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
	FILE *fp;
	FILE *fpw;
	char c;
	char msg[100];
	int index = 0;

	fp = fopen("./last_run.json", "r");
	if (fp == NULL) {
		printf("Cannot open file\n");
		exit(0);
	}

	// Read last_run.json and print when last run
	c = fgetc(fp);
	while (1) {
		int c = fgetc(fp);
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

	fclose(fp);
	printf("%s\n", msg);	

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
//	printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	char date[1024];
	snprintf(date, sizeof(date), "%d/%02d/%02d %02d:%02d", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

	fpw = fopen("./last_run.json", "w");
	fprintf(fpw, "{\"last run\": \"%s\"}", date);
	fclose(fpw);

	return 0;
}