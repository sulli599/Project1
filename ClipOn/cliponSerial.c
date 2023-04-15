#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>


int main() {
	
	//Open reference genome
	FILE *f = fopen("pi.txt", "rb");
	fseek(f, 0, SEEK_END);
	long pos = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *gnm = malloc(pos);
	fread(gnm, pos, 1, f);
	fclose(f);

	//Open reads
	FILE *fp;
	char con[1001];
	
	fp = fopen("reads.txt", "r"); 
	char start[11];	
		

	while (fgets(con,sizeof(con), fp)!=NULL) {
		memset(start,0,11);	
		int pos = -1;
		int dobreak = 0;
		strncat(start, con, 10);
		for (int i = 0; i<strlen(gnm); i++) {
			if (dobreak == 1)
				break;
			for (int j = 0; j<strlen(start); j++) {
				if (j==(strlen(start)-1)) {
					pos = i;
					dobreak = 1;
					printf("%i,", pos);
					}
				if (gnm[i+j] != start[j]) 
					break;
			}
		}	
	}
	

	fclose(fp);
    	return 0;
}
