#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Caesar")
{
  CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
  CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
  CHECK(encryptCaesar("Hello, World!", -5) == "Czggj, Rjmgy!");
  
}


TEST_CASE("Vigenere")
{
  CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
  CHECK(encryptVigenere("ATTACKATDAWN", "LEMON") == "LXFOPVEFRNHR");
  CHECK(encryptVigenere("Testing Vigenere!", "KEY") == "Dimdmhq Zcqihovc!");
}

TEST_CASE("Decrypt Caesar")
{
  CHECK(decryptCaesar("Gki dy Qy!", 10) == "Way to Go!");
  CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
  CHECK(decryptCaesar("Czggj, Rjmgy!", -5) == "Hello, World!");
}

TEST_CASE("Decrypt Vigenere")
{
  CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
  CHECK(decryptVigenere("ACEDFHG", "abc") == "ABCDEFG");
}

TEST_CASE("Decrypt Caesar no shift")
{
  CHECK(decrypt("Ofov Uxsofov") == "Evel Knievel");
}
