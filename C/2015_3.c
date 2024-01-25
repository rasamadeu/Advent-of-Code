#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	char *line = NULL, c;
	size_t length; 

	fp = fopen("input/2015_3_input.dat", "rt");

	if(getline(&line, &length, fp) == -1){
		return EXIT_FAILURE;
	}
	
	int position[length + 1][2];
	position[0] = {0, 0};
	for(int i = 1; i < length + 1; i++){
		fscanf(line, "%c", c);
		switch(c){
			case "^": position[i][1] = position[i-1][1] + 1;
			case ">": position[i][0] = position[i-1][0] + 1;
			case "v": position[i][1] = position[i-1][1] - 1;
			case "<": position[i][0] = position[i-1][0] - 1;
		}		
	}

	if(fp){
		fclose(fp);
	}

	return 0;
}