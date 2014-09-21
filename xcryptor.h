struct xcryptorADT {
        char *key;
        int round;
        int encrypt;
        int blocksize;
        int n_rounds;
};


#define XC_ENCRYPT 1
#define XC_DECRYPT 0


//	key, encrypt (1=encrypt,0=decrypt)
struct xcryptorADT *xc_init(char *, int);
//	xcryptor instance, buffer to store subkey
char *xc_next_subkey(struct xcryptorADT *, char *);
//	xcryptor instance, buffer to store output, R (right size of block), K (subkey)
char *xc_f(struct xcryptorADT *, char *, char *, char *);
