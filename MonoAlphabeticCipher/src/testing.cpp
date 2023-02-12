#include "Cipherer.h"

#include <iostream>

int main()
{
	AlphaCipherer::Cipherer cipherer;
	std::string TEST_STRING = "My name is SwaggyP and I like playing the piano!";
	cipherer.SetKeyWord("Swaggy");

	std::cout << "Keyword: Swaggy ----------------------------" << std::endl;
	std::string encryptedString = cipherer.Encrypt(TEST_STRING);
	std::cout << encryptedString << std::endl;
	std::string decryptedString = cipherer.Decrypt(encryptedString);
	std::cout << decryptedString << std::endl;
	std::cout << "---------------------------------" << std::endl;

	cipherer.SetKeyWord("Wassupp");

	std::cout << "Keyword: Wassup ----------------------------" << std::endl;
	encryptedString = cipherer.Encrypt(TEST_STRING);
	std::cout << encryptedString << std::endl;
	decryptedString = cipherer.Decrypt(encryptedString);
	std::cout << decryptedString << std::endl;
	std::cout << "--------------------------------" << std::endl;

	cipherer.SetKeyWord("Piano");

	std::cout << "Keyword: Piano ----------------------------" << std::endl;
	encryptedString = cipherer.Encrypt(TEST_STRING);
	std::cout << encryptedString << std::endl;
	decryptedString = cipherer.Decrypt(encryptedString);
	std::cout << decryptedString << std::endl;
	std::cout << "--------------------------------" << std::endl;
}