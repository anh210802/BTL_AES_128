/*
 * handle_data_LoRa.h
 *
 *  Created on: Oct 30, 2024
 *      Author: anhxa
 */

#ifndef INC_HANDLE_ENCRYPT_HPP_
#define INC_HANDLE_ENCRYPT_HPP_

#include "aes.hpp"
#include <stdio.h>
#include <string.h>

void handleDataEncrypt(const char *input_str, char *data_sent, uint8_t *key);

#endif /* INC_HANDLE_ENCRYPT_HPP_ */
