#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "xcryptor.h"
#include <openssl/sha.h>




struct xcryptorADT *xc_init(char *key, int encrypt)
{
	struct xcryptorADT *xc = malloc(sizeof(struct xcryptorADT));

	xc->key = malloc(strlen(key)+1);
	strcpy(xc->key, key);
	
	xc->encrypt = encrypt;
	xc->round = 0;

	xc->blocksize = 8;
	xc->n_rounds = 10;

	return xc;
}

char *xc_next_subkey(struct xcryptorADT *xcryptor, char *K)
{
	char hash[SHA_DIGEST_LENGTH];	


	char str[5];
	sprintf(str,"%d%d%d%d",
		xcryptor->round,
		xcryptor->round,
		xcryptor->round,
		xcryptor->round);

	xcryptor->round++;

	SHA1((unsigned char *)str, 4, (unsigned char *)hash);
	puts(hash);

	memcpy(K, str, 4);
	return K;
}

char *xc_f(struct xcryptorADT *xcryptor, char *out, char *R, char *K)
{
	memcpy(out, R, 4);

	return out;
}


void xc_destroy(struct xcryptorADT *xcryptor)
{
	free(xcryptor);
}
