/*******
*	feistel.c
*/


/*
	out: encrypted/decrypted ciphertext/message
	in:  message/ciphertext
	blocksize: size of the blocks
	key:	key
	F:	round function of the encryption
	KS:	function that contains the key scheme algorithm
	
*/
void feistel(char *out, char *in, int blocksize, char *key, void (F)(char *, char *), void (*KS)(char *,char *))
{
	//	placeholder, for x number of rounds do
	//	Lnew = R
	//	Rnew = L xor F(R,KS(key))
	//	where KS(key) is the current iteration of the key scheme
}
