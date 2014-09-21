#include "xcryptor.h"
#include <openssl/sha.h> 
#include <stdio.h>


int main()
{
	char key[5] = "hell";
	char subkey[5];
	struct xcryptorADT *xcrypt;

	xcrypt = xc_init(key, XC_ENCRYPT);

	xc_next_subkey(xcrypt, subkey);
	subkey[4] = '\0';
	puts(subkey);
	xc_next_subkey(xcrypt, subkey);
	puts(subkey);


	return 0;
}
