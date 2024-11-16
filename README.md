Mã hóa AES 128 
Chế độ mã hóa ECB
Padding: None

Ngôn ngữ sử dung C++

Run code:
Mở terminal:
- Window:
    > > gcc -o run ./main.cpp ./handle_encrypt.cpp ./handle_decrypt.cpp ./aes.cpp

    > >./run

- Linux:
    > $ gcc -o run main.cpp handle_encrypt.cpp handle.decrypt.cpp aes.cpp

    > $ ./run

Hàm:
 > void handleDataEncrypt(const char *input_str, char *data_sent, uint8_t *key)  //Mã hóa chuỗi ký tự

 > void handleDataDecrypt(const char* data_encrypt, char* data_decrypt, uint8_t* key) //Giải mã chuỗi ký tự

Ở đây chúng ta đọc file:
> std::string filename_input = "input_file/input5.txt"; //Chuỗi ký tự ban đâu

> std::string filename_encrypt = "encrypt_file/encrypt5.txt"; //Chuỗi ký tự được mã hóa
 
> std::string filename_decrypt = "decrypt_file/decrypt5.txt"; //Chuỗi ký tự được giải mã


