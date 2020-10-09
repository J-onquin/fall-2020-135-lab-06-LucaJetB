#include <iostream>
#include "funcs.h"

void test_ascii(std::string str)
{
  for(int i = 0; i < str.length(); i++)
    {
      char c;
      c = str[i];
      std::cout << str[i] << ": " << (int)c << std::endl;
    }
}

char shiftChar(char c, int rshift)
{
  c = c + rshift;
  return c;
}

std::string encryptCaesar(std::string plaintext, int rshift)
{
  std::string ceaserText;
  char c;
  int shift = 0;
  for(int i = 0; i < plaintext.length(); i++)
    {
      c = plaintext[i];

      if((c < 123) && (c > 96))
	{
	  if((c + rshift) > 127)
	    {
	    shift = (c + rshift) - 122;
	    c = 96 + shift;
	    }
	  else
	    c = c + rshift;

	  if(rshift > -1)
	    {
	      if(c > 122)
		c = c - 26;
	    }
	  
	  if(rshift < 0)
	    {
	      if(c < 97)
		{
		  c = c - 97;
		  c = 123 + c;
		}
	    }
	}
  
      if((c < 91) && (c > 64))
	{
	  c = shiftChar(c, rshift);
	  if(rshift > -1)
	    {
	      if(c > 90)
		c = c - 26;
	    }
	  if(rshift < 0)
	    {
	      if(c < 65)
		{
		  c = c - 64;
		  c = 90 + c;
		}
	    }
	}
      ceaserText += c;
    }
  return ceaserText;
}


std::string encryptVigenere(std::string plaintext, std::string keyword)
{
  std::string vigenere;
  char c;
  int k = 0;
  int shift = 0;
  for(int j = 0; j < keyword.length(); j++)
    keyword[j] = std::tolower(keyword[j]);

  for(int i = 0; i < plaintext.length(); i++)
    {
      if(k > keyword.length() - 1)
	k = 0;
      int rshift = (int)keyword[k] - 97;
      c = plaintext[i];

      if((c < 123) && (c > 96))
	{
	  if((int)c + rshift > 127)
	    {
	      shift = ((int)c + rshift) - 127;
	      c = 97 + shift;
	    }
	  else
	    c = c + rshift;

	  if(c > 122)
	    c = c - 26;

	  k++;
	}
      if((c < 91) && (c > 64))
	{
	  c = c + rshift;
	  if(c > 90)
	    c = c - 26;
	  k++;
	}
 
      vigenere += c;
    }
  return vigenere;
}

std::string decryptCaesar(std::string ciphertext, int rshift)
{
  int shift = rshift * -1;
  std::string decrypt;
  decrypt = encryptCaesar(ciphertext, shift);
  return decrypt;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword)
{
  std::string vigenere;
  char c;
  int k = 0;
  int shift = 0;
  for(int j = 0; j < keyword.length(); j++)
    keyword[j] = std::tolower(keyword[j]);

  for(int i = 0; i < ciphertext.length(); i++)
    {
      if(k > keyword.length() - 1)
	k = 0;
      
      int rshift = (int)keyword[k] - 97;
      rshift = rshift * -1;
      c = ciphertext[i];
     
      if((c < 123) && (c > 96))
	{
	  c = c + rshift;
	  if(c < 97)
	    c = c + 26;

	  k++;
	}
      if((c < 91) && (c > 64))
	{
	  if((int)c + rshift < 64)
	    {
	      shift = 64 - ((int)c + rshift);
	      c = 90 -  shift;
	    }
	  else
	    c = c + rshift;
	  
	  if(c > 90)
	    c = c - 26;
	  k++;
	}
      
      vigenere += c;
    }
  return vigenere;
}

