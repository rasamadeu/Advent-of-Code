#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isVowel(char c){
	switch(c){
		case 'a':
			return true;
		case 'e':
			return true;
		case 'i':
			return true;
		case 'o':
			return true;
		case 'u':
			return true;
	}
	return false;
}

bool isNiceString2(char *string, int length){
	
	bool repeting_pattern = false;
	bool palindrome = false;
	
	for(int i = 0; i < length - 2; i++){
		if(string[i] == string[i+2] && string[i] != string[i+1]){
			palindrome = true;
			if(repeting_pattern){
				return true;	
			}
		}
		for(int j = i+2; j < length-1; j++){
			if(string[i] == string[j] && string[i+1] == string[j+1]){
				repeting_pattern = true;
				if(palindrome){
				return true;	
				}
			}
		}
	}
	return repeting_pattern && palindrome;
}

bool isNiceString1(char *string, int length){
	
	int n_vowels = 0;
	bool consecutive_letters = false;
	bool forbidden_sequence = false;
	for(int i = 0; i < length - 1; i++){
	
		if(isVowel(string[i])){
			n_vowels++;
		}
	
		if(string[i] == string[i+1]){
			consecutive_letters = true;
		}

		if((string[i] == 'a' && string[i+1] == 'b')
		|| (string[i] == 'c' && string[i+1] == 'd')
		|| (string[i] == 'p' && string[i+1] == 'q')
		|| (string[i] == 'x' && string[i+1] == 'y')
			){
			forbidden_sequence = true;
		}
	}

	if(isVowel(string[length-1])){
		n_vowels++;
	}

	if(n_vowels > 2){
		return true & consecutive_letters & !forbidden_sequence;
	}
	return false & consecutive_letters & !forbidden_sequence;
}

int main(){

	FILE *fd;
	char *line = malloc(sizeof *line);
	size_t s;
	ssize_t length;
	int counter = 0;

	fd = fopen("input/2015_5_input.dat", "rt");
	// Attemp to redo this with regex.h
	// U WERE DOING length = getline(&line, &s, fd) != -1
	// This would compare getline with -1 and would write
	// true or false to length
	while((length = getline(&line, &s, fd)) != -1){
		if(isNiceString2(line, length)){
			counter++;
		}
	}
	printf("%d\n", counter);
	free(line);
	if(fd){
		fclose(fd);
	}

	return 0;
}
