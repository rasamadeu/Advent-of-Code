#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILELINES 339

/* THERE WAS A MISTAKE THAT COST ME A LOT OF TIME!
 * THE BEHAVIOUR OF strcpy(origin str, dest str) IS
 * UNDEFINED IF THE dest str HAS LESS LENGTH THAN origin str.
 * IS BETTER TO ALLOCATE MORE SPACE TO STRINGS, SINCE strcpy
 * ALSO COPIES THE NULL TERMINATING CHARACTER!*/

typedef struct {
	unsigned short int value;
	int control;
} wire;

typedef struct {
	char operator[10];	
	char input1[10];	
	char input2[10];	
	char output[10];
	int done;
} operation;

int position(char *wire){

	int j = 0;
	j += (wire[0]-96);
	if(strlen(wire) == 2){
		j += (wire[1]-96)*26;
	}	
	return j;
}

int doAssembly(wire *circuit, operation* assembly, int j){

	if(assembly[j].done){
		return 0;
	}

	int position_input2 = position(assembly[j].input2); 
	int position_output = position(assembly[j].output); 
	if(isdigit(assembly[j].input1[0])){
		switch(assembly[j].operator[0]){
			case 'A':
				if(circuit[position_input2].control){
					unsigned short int x2 = circuit[position_input2].value;
					circuit[position_output].value = (unsigned short int)atoi(assembly[j].input1) & x2;
					circuit[position_output].control = 1; 
					assembly[j].done = 1;
				}
				break;
			case '-':
				circuit[position_output].value = (unsigned short int)atoi(assembly[j].input1);
				circuit[position_output].control = 1; 
				assembly[j].done = 1;
				break;
		}
	return assembly[j].done;
	}
	
	int position_input1 = position(assembly[j].input1); 
	if(circuit[position_input1].control){
		unsigned short int x1 = circuit[position_input1].value;	
		switch(assembly[j].operator[0]){
			case 'A':
				if(circuit[position_input2].control){
					unsigned short int x2 = circuit[position_input2].value;
					circuit[position_output].value = x1 & x2;
					circuit[position_output].control = 1; 
					assembly[j].done = 1;
				}
				break;
			case 'O':
				if(circuit[position_input2].control){
					unsigned short int x2 = circuit[position_input2].value;
					circuit[position_output].value = x1 | x2;
					circuit[position_output].control = 1; 
					assembly[j].done = 1;
				}
				break;
			case 'R':
				circuit[position_output].value = x1 >> atoi(assembly[j].input2); 
				circuit[position_output].control = 1; 
				assembly[j].done = 1;
				break;
			case 'L':
				circuit[position_output].value = x1 << atoi(assembly[j].input2);
				circuit[position_output].control = 1; 
				assembly[j].done = 1;
				break;
			case 'N':
				circuit[position_output].value = ~x1;
				circuit[position_output].control = 1; 
				assembly[j].done = 1;
				break;
			case '-':
				circuit[position_output].value = x1;
				circuit[position_output].control = 1; 
				assembly[j].done = 1;
				break;
		}
	}
	return assembly[j].done;
}

int main(){

	FILE *fd;
	char a[10], b[10], c[10], d[10], e[10];
	char *buffer = (char *) malloc(sizeof(char));
	size_t length;
	int readline = 1;
	wire *circuit = (wire*) calloc(27*26+1, sizeof(wire));
	operation assembly[FILELINES];
	int i = 0, done = 0;

	fd = fopen("input/2015_7_input.dat", "rt");

	while(getline(&buffer, &length, fd) != -1){
		switch(sscanf(buffer, "%s %s %s %s %s\n", a, b, c, d, e)){
			case 0:
				readline = 0;
				break;
			case 3: 
				strcpy(assembly[i].operator, b);
				strcpy(assembly[i].input1, a);
				strcpy(assembly[i].output, c);
				assembly[i].done = 0;
				break;
			case 4:
				strcpy(assembly[i].operator, a);
				strcpy(assembly[i].input1, b);
				strcpy(assembly[i].output, d);
				assembly[i].done = 0;
				break;
			case 5:
				strcpy(assembly[i].operator, b);
				strcpy(assembly[i].input1, a);
				strcpy(assembly[i].input2, c);
				strcpy(assembly[i].output, e);
				assembly[i].done = 0;
				break;
		}	
		i++;
	}

	while(done < FILELINES){
		for(int j = 0; j < FILELINES; j++){
			if(doAssembly(circuit, assembly, j)){
				done++;
			}
		}
	}

	printf("FIRST PART\n");
	printf("%d\n", circuit[position("a")].value);

	circuit[position("b")].value = circuit[position("a")].value;
	circuit[position("b")].control = 1;
	for(int i = 0; i < 27*26+1; i++){
		if(i == position("b"))
			continue;
		circuit[i].value = 0;
		circuit[i].control = 0;
	}
	
	for(int i = 0; i < FILELINES; i++){
		if(strcmp(assembly[i].output, "b") == 0)
			continue;
		assembly[i].done = 0;
	}
	
	done = 0;
	while(done < FILELINES-1){
		for(int j = 0; j < FILELINES; j++){
			if(doAssembly(circuit, assembly, j)){
				done++;
			}
		}
	}
	
	printf("SECOND PART\n");
	printf("%d\n", circuit[position("a")].value);

	return 0;
}
