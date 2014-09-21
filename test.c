#include "/usr/include/openssl/sha.h" 
//#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	unsigned char hash[SHA_DIGEST_LENGTH];
	unsigned char in[] = {0x1e,0xfe,0xba,0x22,0xe7,0x70,0xe9,0x5f} ;

	SHA1(in, strlen((char *) in), hash);



	for(i = 0; i < SHA_DIGEST_LENGTH; ++i) {

		printf("%d", i % 10);
	}
	putchar('\n');
	for(i = 0; i < SHA_DIGEST_LENGTH; ++i) {

		printf("%x", hash[i]);
	}
	putchar('\n');


	return 0;
}
