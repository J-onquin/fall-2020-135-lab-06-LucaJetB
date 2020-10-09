#pragma once


void test_ascii(std::string str);
char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);
std::string encryptVigenere(std::string plaintext, std::string keyword);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ct, std::string k);
