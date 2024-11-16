#include "handle_encrypt.hpp"
#include <iostream>

void splitTo16ByteChunks16(const char* string_input, char chunks[][17], size_t* chunk_count) {
    size_t length = strlen(string_input);
    *chunk_count = 0;

    for (size_t i = 0; i < length; i += 16) {
        strncpy(chunks[*chunk_count], string_input + i, 16);
        chunks[*chunk_count][16] = '\0'; // Đảm bảo kết thúc chuỗi
        (*chunk_count)++;
    }
}

void convertTo128BitBlock(const char* data_input, uint8_t* block) {
    for (size_t i = 0; i < 16; ++i) {
        block[i] = (uint8_t)data_input[i];
    }
}

void changeToHex(uint8_t* data, size_t size, char* hexOutput) {
    for (size_t i = 0; i < size; i++) {
        sprintf(hexOutput + (i * 2), "%02x", data[i]);
    }
    hexOutput[size * 2] = '\0'; 
}

void handleDataEncrypt(const char *input_str, char *data_encrypt, uint8_t *key) {
    struct AES ctx;
    AES_init_ctx(&ctx, key);
    char chunks[10][17]; 
    size_t chunk_count = 0;
    splitTo16ByteChunks16(input_str, chunks, &chunk_count);
    for (size_t i = 0; i < chunk_count; i++) {
        uint8_t blocks[16]; 
        convertTo128BitBlock(chunks[i], blocks);
        AES_encrypt(&ctx, blocks);
        char hex_output[33];
        changeToHex(blocks, 16, hex_output);
        strcat(data_encrypt, hex_output); 
    }
}
