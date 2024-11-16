#ifndef INC_HANDLE_DECRYPT_HPP_
#define INC_HANDLE_DECRYPT_HPP_

#include "aes.hpp"
#include <stdio.h>
#include <string.h>

void handleDataDecrypt(const char* data_encrypt, char* data_decrypt, uint8_t* key);

#endif /* INC_HANDLE_DECRYPT_HPP_ */
