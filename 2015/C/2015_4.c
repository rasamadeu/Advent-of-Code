#include <openssl/md5.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){

	char input[] = "bgvyzdsv";
	char buffer[32];
	unsigned char hash[16] = "";
	ssize_t n_bytes;
	unsigned long n = 0;
	int n_input = strlen(input);

	// MD5 hashes consist of 128 bits = 16 bytes
	// Each hexadecimal number corresponds to 4 bits since 2^4 = 16
	// Thus, each byte corresponds to 2 hex algarisms.
	// 5 zeros consists of first two bytes = 0 and the 3rd byte must be
	// > 16 = 0x10
	do{
		n++;
		n_bytes = snprintf(buffer, n_input + n, "%s%ld", input, n);
		MD5(buffer, n_bytes, hash);
	} while(hash[0] || hash[1] || hash[2] > 0x10);

	printf("%d\n", n);

	n = 0;
	do{
		n++;
		n_bytes = snprintf(buffer, n_input + n, "%s%ld", input, n);
		MD5(buffer, n_bytes, hash);
	} while(hash[0] || hash[1] || hash[2]);

	printf("%d\n", n);

	return 0;
}