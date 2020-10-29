#include <iostream>


#include "funcs.h"

int main()
{
  test_ascii("Hello World");
  char c;
  c = shiftChar('a', 3);
  std::cout << c << std::endl;
  std:: string str;
  str = encryptCaesar("Evel Knievel", 10);
  std::cout << str << std::endl;
  str = encryptVigenere("Hello, World!", "cake");
  std::cout << str << std::endl;
  str = decryptCaesar("Rovvy, Gybvn!", 10);
  std::cout << str << std::endl;
  str = decryptVigenere("ACEDFHG", "abc");
  std::cout << str << std::endl;
}
