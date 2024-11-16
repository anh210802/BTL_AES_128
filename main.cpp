#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "aes.hpp"  
#include "handle_encrypt.hpp"  
#include "handle_decrypt.hpp" 
#include <fstream>



int main() {
    // Đọc dữ liệu từ file
    std::string filename_input = "input_file/input5.txt";
    std::string filename_encrypt = "encrypt_file/encrypt5.txt";
    std::string filename_decrypt = "decrypt_file/decrypt5.txt";
    std::ifstream file(filename_input, std::ios::in);
    std::string line;
    std::getline(file, line);
    file.close();
    char data_input[160] = {0};
    strcpy(data_input, line.c_str());
    std::cout << "Data input: " << data_input << std::endl;
    char data_encrypt[320] = {0};
    char data_decrypt[160] = {0};
    // Khóa AES
    uint8_t key[16] = { 0x4b, 0x65, 0x79, 0x2d, 0x4d, 0x61, 0x48, 0x6f,
            			0x61, 0x41, 0x45, 0x53, 0x2d, 0x31, 0x32, 0x38 };

    handleDataEncrypt(data_input, data_encrypt, key);
    std::cout << "Data encrypted: " << data_encrypt << std::endl;
    
    std::ofstream file_out(filename_encrypt, std::ios::out | std::ios::trunc);
    file_out << data_encrypt;
    file_out.close();

    handleDataDecrypt(data_encrypt, data_decrypt, key);
    std::cout << "Data decrypted: " << data_decrypt << std::endl;
    file_out.open(filename_decrypt, std::ios::out | std::ios::trunc);
    file_out << data_decrypt;
    file_out.close();

    return 0;
}
