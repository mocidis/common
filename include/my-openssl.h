#ifndef __MY_OPENSSL__
#define __MY_OPENSSL__

#include <openssl/evp.h>

void generate_otp(unsigned char *otp, char *pph, char *timestamp);
void do_encrypt(unsigned char *ciphertext, int *ciphertext_len, unsigned char *plaintext, int plaintext_len, char *otp);
void do_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext, int *plaintext_len, char *otp);

#endif
