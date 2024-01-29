#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LINESIZE 50

void getInstruction(char line[],
					char *instruction,
					int initial_point[2],
					int end_point[2]){

	char *token = NULL;
	token = strtok(line, " \n");
	char *sinitial_point, *send_point;
	*instruction = '0';

	if(strcmp(token, "turn") == 0){
		token = strtok(NULL, " ");
		*instruction = '1';	
		if(strcmp(token, "on") == 0){
			*instruction = '2'; 
		}
	}
	sinitial_point = strtok(NULL, " ");
	token = strtok(NULL, " ");
	send_point = strtok(NULL, " \n");

	initial_point[0] = atoi(strtok(sinitial_point, ","));
	initial_point[1] = atoi(strtok(NULL, ","));
	end_point[0] = atoi(strtok(send_point, ","));
	end_point[1] = atoi(strtok(NULL, ","));

	return ;	
}	

void toggleGrid(int *grid[1000], int initial_point[2], int end_point[2], bool first_part){

	for(int i=initial_point[0]; i <= end_point[0]; i++){
		for(int j=initial_point[1]; j <= end_point[1]; j++){
			if(first_part){
				grid[i][j] = !grid[i][j];
			}
			else{
				grid[i][j] += 2;
			}
		}
	}
	return ;
}

void onGrid(int *grid[1000], int initial_point[2], int end_point[2], bool first_part){

	for(int i=initial_point[0]; i <= end_point[0]; i++){
		for(int j=initial_point[1]; j <= end_point[1]; j++){
			if(first_part){
				grid[i][j] = 1;
			}
			else{
				grid[i][j] += 1;
			}
		}
	}
	return ;
}

void offGrid(int *grid[1000], int initial_point[2], int end_point[2], bool first_part){

	for(int i=initial_point[0]; i <= end_point[0]; i++){
		for(int j=initial_point[1]; j <= end_point[1]; j++){
			if(first_part){
				grid[i][j] = 0;
			}
			else{
				grid[i][j] == 0 ? : grid[i][j]--;
			}

		}
	}
	return ;
}


int main(){

	FILE *fd;
	fd = fopen("input/2015_6_input.dat", "rt");
	if (fd == NULL) {
	    perror("ficheiro");
    	exit(1);
  	}
	int **grid;
	grid = (int **)calloc(1000, sizeof(int *));
	for(int i = 0; i < 1000; i++){
		grid[i] = (int *)calloc(1000, sizeof(int ));
	}
	// There was a segmentation fault because i was passing an
	// unitialized char* as an argument to getInstruction. An
	// unitilized pointer has no memory address.
	char instruction = 's';
	char line[LINESIZE];
	size_t length;
	int initial_point[2], end_point[2];
	unsigned int lights_on = 0, brightness = 0;
	bool first_part = false;

	while(fgets(line, LINESIZE, fd) != NULL){
		getInstruction(line, &instruction, initial_point, end_point);
		switch (instruction){
			case '0':
				toggleGrid(grid, initial_point, end_point, first_part);
				break;
		       	case '1':
				offGrid(grid, initial_point, end_point, first_part);
				break;
			case '2':
				onGrid(grid, initial_point, end_point, first_part);
				break;
		}
	}

	for(int i=0; i<1000; i++){
		for(int j=0; j<1000; j++){
			if(grid[i][j]){
				lights_on++;
				brightness+=grid[i][j];
			}
		}
	}

	printf("%d\n", lights_on);
	printf("%d\n", brightness);

	for(int i = 0; i < 1000; i++){
		free(grid[i]);
	}
	free(grid);

	return 0;
}	
