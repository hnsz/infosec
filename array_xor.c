#include "array_xor.h"

void array_xor(char *out, char *in, char *mask, int length)
{
	int i;

	for(i = 0; i < length; ++i) {

		 out[i] = in[i] ^ mask[i];

	}
}

