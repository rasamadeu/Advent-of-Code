#include <stdio.h>
#include <string.h>

int main(){

	FILE *fd = NULL;

	if((fd = fopen("input/2015_8_input.dat", "rt")) == NULL){
		printf("Failed to read file\n");
		return -1;
	}
	
	int n_literal = 0;
	int n_memory = 0;
	int n_encoded = 0;
	int state = 0;
	char c;

	for(n_literal = 0; (c = fgetc(fd)) != EOF; ++n_literal){
		switch(c){
			case '\\':
				state = !state;
				n_encoded++;
				if(state)
					n_memory -= 1;
				break;
			case '\"':
				n_encoded++;
				if(!state)
					n_memory--;
				state = 0;
				break;
			case 'x':
				if(state){
					n_memory -= 2;
					state = 0;
				}
				break;
			case '\n':
				n_encoded += 2;
				break;
		}
		n_memory++;
		n_encoded++;
	}

	printf("%d\n", n_literal - n_memory);
	printf("%d\n", n_encoded - n_literal);
	return 0;
}
