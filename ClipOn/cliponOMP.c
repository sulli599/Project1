#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>


int main() {
	
	//
	int poss[5];	

	//Open reference genome
	FILE *f = fopen("pi.txt", "r");
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
	
	char **reads = NULL;
	char start[11];
	int i = 0;
	while (fgets(con,sizeof(con), fp)!=NULL) {
                memset(start,0,11);	
		strncat(start, con, 10);
		
		i++;			
		reads = (char**)realloc(reads, (i+1)*sizeof(*reads));
		reads[i-1] = (char*)malloc(sizeof(start));
    		strcpy(reads[i-1], start);
		
	}
	fclose(fp);
	//Find Alignment
	#pragma omp parallel num_threads(5) private(start)
	{
	int id = omp_get_thread_num();

	strcat(start, reads[id]);
		
	int dobreak = 0;

	for (int i = 0; i<strlen(gnm); i++) {
		if (dobreak == 1)
			break;
		for (int x = 0; x<strlen(start); x++) {
			if (x==(strlen(start)-1)) {
				dobreak = 1;
				#pragma omp critical 
				{
				poss[id] = i;
				}
			}
			if (gnm[i+x] != start[x]) 
				break;
		}
	}	
	}
	
	
	for (int c = 0; c<5; c++)
		printf("%i ", poss[c]);
    	return 0;
}
