/*******
*	feistel.c
*/
#include <stdlib.h>
#include <string.h>
#include "xcryptor.h"

/*
	xcryptorADT
		subkey(i);
		f(R,K_i);
		blocksize;
		n_rounds;
		
*/
int calc_padded_message_size(int, int);
char *copy_n_pad_message(char *, char *, int, int);
char *memxor(char *, char *, char *, int );
char *feistel(char *, char *, int, char *);

void encrypt_example()
{
	int n_padding;
	int message_size;
	int padded_message_size;
	char *padded_message;
	char *message;


	//	Get padded_input_size.
	//	Determine n_padding.
	//	Allocate length of padded_input_size(=input_size + n_padding), 
	//	once for padded_message.
	//	Copy input to padded_input and pad it with the value of n_padding.
	padded_message_size = calc_padded_message_size(message_size, 8);
	n_padding = padded_message_size - message_size;
	padded_message = malloc(padded_message_size);
	copy_n_pad_message(padded_message, message, message_size, n_padding);
}

char *feistel(char *out, char *in, int input_size, char *key)
{
	//	copy R to Lnew
	//	copy L xor F(R,K_i) to Rnew

	//	copy Lnew to L
	//	copy Rnew to R
	int i;
	int part_size;
	struct xcryptorADT *xc;
	char *Lnew;
	char *Rnew;
	char *L;
	char *R;
	char *K;
	char *fx;	

	xc = xc_init(key, XC_ENCRYPT);

	part_size = xc->blocksize / 2;

	
	

	for(i = 0; i < xc->n_rounds; ++i) {

		memcpy(Lnew, R, part_size);
		memxor(Rnew, L, xc_f(xc, fx,  R, xc_next_subkey(xc,K)), part_size);
	}

	return out;
}


int calc_padded_message_size(int input_size, int block_size)
{
	int padded_size;


	//	
	if(input_size % block_size == 0) {

		padded_size = input_size;
	}
	else {

		padded_size = (input_size / block_size) * block_size + block_size;
	}

	return padded_size;
}


char *copy_n_pad_message(char *padded_message, char *message, int message_size, int n_padding)
{
	int i;
	
	memcpy(padded_message, message, message_size);

	for(i = message_size; i < message_size + n_padding; ++i) {

		padded_message[i] = n_padding;
	}

	return padded_message;
}


char *memxor(char *out, char *in, char *mask, int length)
{
	int i;

	for(i = 0; i < length; ++i) {

		 out[i] = in[i] ^ mask[i];

	}
	return out;
}

