#include "my-openssl.h"
#include <string.h>
#include <openssl/md5.h>


void generate_otp(unsigned char *otp, char *pph, char *timestamp) {
    int n = sprintf(otp, "%s-%s", pph, timestamp);
    otp[n] = '\0';
}

void do_encrypt(unsigned char *ciphertext, int *ciphertext_len, unsigned char *plaintext, int plaintext_len, char *otp) {
    EVP_CIPHER_CTX ctx;
    int i = 0, len;
    int temp;

    EVP_CIPHER_CTX_init(&ctx);
    EVP_EncryptInit(&ctx, EVP_aes_128_cbc(), otp, NULL);
    EVP_EncryptUpdate(&ctx, ciphertext, &len, plaintext, plaintext_len);
    temp = len;
    EVP_EncryptFinal_ex(&ctx, ciphertext + len,  &len);
    temp += len;

    *ciphertext_len = temp;
    
    EVP_CIPHER_CTX_cleanup(&ctx);
}

void do_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext, int *plaintext_len, char *otp) {
    EVP_CIPHER_CTX ctx;
    int i, len;
    int temp;

    EVP_CIPHER_CTX_init(&ctx);
    
    EVP_DecryptInit(&ctx, EVP_aes_128_cbc(), otp, NULL);
    EVP_DecryptUpdate(&ctx, plaintext, &len, ciphertext, ciphertext_len);
    temp = len;
    EVP_DecryptFinal(&ctx, plaintext + len,  &len);
    temp += len;

    *plaintext_len = temp;

    EVP_CIPHER_CTX_cleanup(&ctx);
}

