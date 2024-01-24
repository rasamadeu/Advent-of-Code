#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int surface_area(int l, int w, int h){

	int a = l*w;
	int b = l*h;
	int c = h*w;

	if(a <= b && a <= c){
		return 2*(a+b+c) + a;
	}
	if(b <= c && b <= a){
		return 2*(a+b+c) + b;
	}
	if(c <= b && c <= a){
		return 2*(a+b+c) + c;
	}
	return EXIT_FAILURE;
}

int ribbon(int l, int w, int h){

	if(l <= w){
		if(w <= h){
			return 2*(l+w) + l*w*h;
		}
		return 2*(l+h) + l*w*h;
	}
	else{
		if(l <= h){
			return 2*(l+w) + l*w*h;
		}
		return 2*(w+h) + l*w*h;
	}
	return EXIT_FAILURE;
}

int main(){

	int total_area = 0, total_ribbon = 0;
	int l, w, h;
	FILE *fid;
	char *line = malloc(sizeof *line);
	size_t length;

	fid = fopen("input/2015_2_input.dat", "rt");
	while(getline(&line, &length, fid) != -1){
		l = atoi(strtok(line, "x"));
		w = atoi(strtok(NULL, "x"));
		h = atoi(strtok(NULL, "x"));
		total_area += surface_area(l, w, h);
		total_ribbon += ribbon(l, w, h);
	}
	
	printf("%d\n", total_area);	
	printf("%d\n", total_ribbon);	
	fclose(fid);

	if(line){
		free(line);
	}

	return EXIT_FAILURE;
}