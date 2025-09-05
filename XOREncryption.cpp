#include <iostream>
#include <string>
using namespace std;

// Function to XOR encrypt or decrypt
string xorEncryptDecrypt(const string &input, const string &key)
{
  string output = input;
  for (size_t i = 0; i < input.size(); ++i)
  {
    output[i] = input[i] ^ key[i % key.size()]; // XOR each character with the key
    cout << " Key: " << key[i % key.size()] << " Input: " << input[i] << " Output: " << output[i] << endl;
  }
  return output;
}

int main()
{
  string plaintext;
  cout << "Enter string to encrypt: ";
  getline(cin, plaintext);
  string key = "XMCKL";

  // Encrypt
  string ciphertext = xorEncryptDecrypt(plaintext, key);
  cout << "Ciphertext: " << ciphertext << endl;

  // Decrypt (using the same function)
  string decrypted = xorEncryptDecrypt(ciphertext, key);
  cout << "Decrypted: " << decrypted << endl;

  return 0;
}
