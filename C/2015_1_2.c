#include <stdio.h>

int main(){

	int floor = 0, counter = 0;
	char c;
	FILE *fid;

	fid = fopen("input/2015_1_input.dat", "rt");
	while(fscanf(fid, "%c", &c) == 1 && floor > -1){
		if(c == '('){
			floor += 1;
		}
		if(c == ')'){
			floor -= 1;
		}
		counter++;
	}
	fclose(fid);
	printf("%d\n", counter);

	return 0;
}