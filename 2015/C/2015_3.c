#include <stdio.h>
#include <stdlib.h>

void positions(int (*position)[2], char *line, int length){

	position[0][0] = 0;
	position[0][1] = 0;
	for(int i = 1; i < length+1; i++){
		switch(line[i-1]){
			case '^':
				position[i][0] = position[i-1][0]; 
				position[i][1] = position[i-1][1] + 1;
				break;
			case '>': 
				position[i][0] = position[i-1][0] + 1; 
				position[i][1] = position[i-1][1];
				break;
			case 'v': 
				position[i][0] = position[i-1][0]; 
				position[i][1] = position[i-1][1] - 1;
				break;
			case '<': 
				position[i][0] = position[i-1][0] - 1; 
				position[i][1] = position[i-1][1];
				break;
		}
	}
	return;
}

void swap(int path[][2], int i, int j){

	int temp[2]; 
	temp[0] = path[j][0];
	temp[1] = path[j][1];
	path[j][0] = path[i][0];
	path[j][1] = path[i][1];
	path[i][0] = temp[0];
	path[i][1] = temp[1];
	return ;
}

int partition(int path[][2], int start, int end, int length){
	
	int pivot = start;

	for(int i = start; i < end; i++){
		if (path[i][0] * length + path[i][1] < path[end][0] * length + path[end][1]){
			swap(path, i, pivot);
			pivot++;
		}
	}
	swap(path, end, pivot);

	return pivot;	
}

void quicksort(int path[][2], int start, int end, int length){

	if (start < end){	
		int pivot = partition(path, start, end, length);
		quicksort(path, start, pivot - 1, length);
		quicksort(path, pivot + 1, end, length);
	}
	return ;	
}

int count_houses(int path[][2], int length){

	int	i = 1;
	int houses = 0;
	while(i < length+1){
		while(path[i][0] ==  path[i-1][0]
			  && path[i][1] == path[i-1][1]){
			i++;
		}
		houses++;
		i++;
	}
	return houses;
}

int main(int argc, char const *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t length; 
	ssize_t actual_length; 

	fp = fopen("input/2015_3_input.dat", "rt");
	if((actual_length = getline(&line, &length, fp)) == -1){
		return EXIT_FAILURE;
	}
	// getline returns a null terminated buffer including
	// the newline character if it is found.
	// In this case, length = actual_length + 2 because of null
	// terminated char. It is better to use return value
	// of getline.

	length = actual_length / sizeof(char);
	int path[length+1][2];
	positions(path, line, length);
	quicksort(path, 0, length-1, length-1);

	printf("%d\n", count_houses(path, length));
	
	// SECOND PART OF THE PROBLEM
	int length_santa = length/2 + length%2;
	int length_robot = length/2;
	int path_santa[length_santa][2];
	int path_robot[length_robot][2];
	char line_santa[length_santa];
	char line_robot[length_robot];

	for(int i = 0; i < length; i++){
		if(i % 2 == 0){
			line_santa[i/2] = line[i];
		}
		else{
			line_robot[i/2] = line[i];
		}
	}
	positions(path_santa, line_santa, length_santa);
	positions(path_robot, line_robot, length_robot);

	for(int i = 0; i < length_santa; i++){
		path[i][0] = path_santa[i][0];	
		path[i][1] = path_santa[i][1];	
	}

	for(int i = length_santa; i < length; i++){
		path[i][0] = path_robot[i-length_santa][0];	
		path[i][1] = path_robot[i-length_santa][1];	
	}
	
	quicksort(path, 0, length-1, length-1);

	printf("%d\n", count_houses(path, length));

	if(fp){
		fclose(fp);
	}

	return 0;
}