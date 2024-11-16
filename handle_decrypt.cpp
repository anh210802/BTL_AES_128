#include "handle_decrypt.hpp"
#include <iostream>


void splitTo16ByteChunks(const char* data_input, char chunks[][33], size_t* chunk_count) {
    size_t length = strlen(data_input);
    for (size_t i = 0; i < length; i += 32) {
        strncpy(chunks[*chunk_count], data_input + i, 32);
        chunks[*chunk_count][32] = '\0';
        (*chunk_count)++;
    }
}

void hexToBlock128(const char* hex, uint8_t block[16]) {
    unsigned int byte;
    for (int i = 0; i < 16; i++) {
        sscanf(hex + i * 2, "%2x", &byte);
        block[i] = (uint8_t)byte;
    }
}

void handleDataDecrypt(const char* data_encrypt, char* data_decrypt, uint8_t* key) {
    struct AES ctx;
    AES_init_ctx(&ctx, key);
    char chunks[10][33];
    size_t chunk_count = 0;
    splitTo16ByteChunks(data_encrypt, chunks, &chunk_count);

    for (size_t i = 0; i < chunk_count; i++) {
        uint8_t data[16];
        hexToBlock128(chunks[i], data); 
        AES_decrypt(&ctx, data); 
        strncat(data_decrypt, (char*)data, 16);
    }
}





