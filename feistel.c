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
void feistel(char *out, char *in, int blocksize, char *key, void (*F)(char *, char *), void (*KS)(char *,char *))
{
	//	placeholder, for x number of rounds do
	//	KS(subkey, key)
	//	Lnew = R
	//	Rnew = L xor F(R,subkey)
	//	where KS(subkey, key) creates current iteration of the key scheme and puts it into subkey
}
