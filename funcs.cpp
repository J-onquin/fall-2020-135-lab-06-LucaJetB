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
  if(isupper(c))
    {
      int changeChar = ((int)c - 65 + rshift) % 26 + 65;
      return (char)changeChar;
    }
  else if(islower(c)) 
    {
      int changeChar = ((int)c - 97 + rshift) % 26 + 97;
      return (char)changeChar;
    }

  else
    {
      return c;
    }
}

std::string encryptCaesar(std::string plaintext,int rshift)
{
  std::string result = "";

  for (int i = 0; i < plaintext.length(); i++)
    {
      result += shiftChar(plaintext[i],rshift);
    }
  return result;
}

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
  std::string encryption = "";
  int num = 0;

  for (int i = 0; i < plaintext.length(); i++)
    {
      char current = plaintext[i];

      if(isupper(current))
	{
	  int shiftNum = keyword[num] - 'a';
	  num = (num + 1) % keyword.length();
	  int newPosition = (current - 'A' + shiftNum) % 26;
	  current = 'A' + newPosition;
	}
      else if (islower(current))
	{
	  int shiftNum = keyword[num]-'a';
	  num = (num + 1) % keyword.length();
	  int newPosition = (current - 'a' + shiftNum) % 26;
	  current = 'a' + newPosition;
	}
      encryption += current;
    }
  return encryption;
}

std::string decryptCaesar(std::string ciphertext, int rshift)
{
  int shift = rshift * -1;
  std::string decrypt;
  decrypt = encryptCaesar(ciphertext, shift);
  return decrypt;
}

std::string decryptVigenere(std::string cipheredtext, std::string keyword)
{
  std::string decrypted = "";
  int num = 0;
  int shiftNum;

  for (int i = 0;i < cipheredtext.length(); i++)
    {
      char current = cipheredtext[i];

      if (isupper(current))
	{
	  shiftNum = keyword[num] - 'a';
	  num = (num + 1) % keyword.length();
	  current = 'A' + (current - 'A' - shiftNum + 26) % 26;
	}
      else if (islower(current))
	{
	  shiftNum = keyword[num]-'a';
	  num = (num + 1) % keyword.length();
	  current = 'a' + (current - 'a' - shiftNum + 26) % 26;
	}
      decrypted += current;

    }
  return decrypted;
}

#define NUM_LETTERS ('Z' - 'A' + 1)

int argmax(int arr[], int size)
{
	if(size == 0)
		return -1;
	
	int index = 0;
	int max = arr[0];
	for(int i = 0; i < size; i++)
	{	
		if(arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}

	return index;
}

std::string decrypt(std::string text)
{
	int freq[NUM_LETTERS] = {};
	for(int i = 0; i < text.length(); i++)
	{
		char c = text[i];
		c = tolower(c);
		c = c - 'a';
		freq[c] += 1;
	}
	int freqMaxIndex = argmax(freq, NUM_LETTERS);
	char mostFreqChar = 'a' + freqMaxIndex;
	int shift = 'e' - mostFreqChar;
	return encryptCaesar(text, shift);
}		
//not doing the lab 6 assignment
