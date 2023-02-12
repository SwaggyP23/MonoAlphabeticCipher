#pragma once

/*
 * The Keyword that should be provided should not contain any numbers and symbols since encrypting numbers and symbols
 * is not supported yet.
 * TODO: For the future maybe add numbers and symbols encrypting...
 */

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace AlphaCipherer {

	class Cipherer
	{
	public:
		Cipherer() noexcept = default;
		
		Cipherer(const std::string& keyWord)
			: m_Keyword(keyWord)
		{
			UpdateSettings();
		}

		~Cipherer() = default;

		const std::string& GetKeyWord() const { return m_Keyword; }
		void SetKeyWord(const std::string& keyWord)
		{
			m_Keyword = keyWord;
			UpdateSettings();
		}

		// These return a new string of the newly Encrypted/Decrypted string...
		std::string Encrypt(const std::string& string)
		{
			std::string result;
			result.reserve(string.size());

			for (size_t i = 0; i < string.size(); i++)
			{
				if (IsCapital(string[i]))
				{
					result.push_back(m_AlphabeticMapping[string[i]]);
				}
				else if(IsLower(string[i]))
				{
					result.push_back(m_LowerAlphabeticMapping[string[i]]);
				}
				else // In case the character in talk is not a character (number, symbol..)
				{
					result.push_back(string[i]); // Here we could use either of the inverse mappings
				}
			}

			return result;
		}

		std::string Decrypt(const std::string& string)
		{
			std::string result;
			result.reserve(string.size());

			for (size_t i = 0; i < string.size(); i++)
			{
				if (IsCapital(string[i]))
				{
					result.push_back(m_InverseAlphabeticMapping[string[i]]);
				}
				else if (IsLower(string[i]))
				{
					result.push_back(m_InverseLowerAlphabeticMapping[string[i]]);
				}
				else
				{
					result.push_back(string[i]); // Here we could use either one of the inverse maps...
				}
			}

			return result;
		}

	private:
		Cipherer(const Cipherer&) = delete;
		Cipherer& operator=(const Cipherer&) = delete;

	// Private helpers...
	private:
		std::string LowerString(const std::string& string)
		{
			std::string newString;
			newString.resize(string.size());

			for (int i = 0; i < string.size(); i++)
				newString[i] = std::tolower(string[i]);

			return newString;
		}

		void LowerStringRef(std::string& string)
		{
			for (int i = 0; i < string.size(); i++)
				string[i] = std::tolower(string[i]);
		}

		std::string UpperString(const std::string& string)
		{
			std::string newString;
			newString.resize(string.size());

			for (int i = 0; i < string.size(); i++)
				newString[i] = std::toupper(string[i]);

			return newString;
		}
		
		void UpperStringRef(std::string& string)
		{
			for (int i = 0; i < string.size(); i++)
				string[i] = std::toupper(string[i]);
		}
		
		void RemoveDuplicates(std::string& string)
		{
			std::unordered_set<char> duplicates;
			duplicates.reserve(6); // Reserving an expected amount for the duplicates to reduce the allocation overhead

			for (char character : string)
				duplicates.insert(character);

			string.resize(duplicates.size());
			int i = 0;
			for (char character : duplicates)
			{
				string[i] = character;
				i++;
			}
		}
		
		bool IsCapital(const char c) const
		{
			return int(c) >= int('A') && int(c) <= int('Z');
		}
		
		bool IsLower(const char c) const
		{
			return int(c) >= int('a') && int(c) <= int('z');
		}

		bool IsANumber(const char c) const
		{
			return int(c) >= int('0') && int(c) <= int('9');
		}

		void UpdateSettings()
		{
			m_AlphabeticMapping.clear();
			m_LowerAlphabeticMapping.clear();
			m_InverseAlphabeticMapping.clear();
			m_InverseLowerAlphabeticMapping.clear();

			std::string alphabetic = REFERNCE_ALPHABET;
			std::string lowerAlphabetic = REFERNCE_ALPHABET_LOWER;

			UpperStringRef(m_Keyword);
			RemoveDuplicates(m_Keyword);

			// Removing keyword characters from alphabet
			for (char character : m_Keyword)
				std::erase(alphabetic, character);

			std::string newAlphabet;
			newAlphabet.resize(26);
			uint8_t i = 0;
			for (i; i < m_Keyword.size(); i++)
				newAlphabet[i] = m_Keyword[i];

			const uint8_t temp = i;
			for (i; i < alphabetic.size() + temp; i++)
				newAlphabet[i] = alphabetic[i - temp];

			alphabetic = newAlphabet;
			lowerAlphabetic = LowerString(alphabetic);

			for (uint8_t i = 0; i < 26; i++)
			{
				m_AlphabeticMapping[REFERNCE_ALPHABET[i]] = alphabetic[i];
				m_LowerAlphabeticMapping[REFERNCE_ALPHABET_LOWER[i]] = lowerAlphabetic[i];
				m_InverseAlphabeticMapping[alphabetic[i]] = REFERNCE_ALPHABET[i];
				m_InverseLowerAlphabeticMapping[lowerAlphabetic[i]] = REFERNCE_ALPHABET_LOWER[i];
			}
		}

	private:
		std::string m_Keyword;
		std::unordered_map<char, char> m_AlphabeticMapping; // normal Alphabet -> coded Alphabet
		std::unordered_map<char, char> m_LowerAlphabeticMapping; // normal lower Alphabet -> coded lower Alphabet
		std::unordered_map<char, char> m_InverseAlphabeticMapping; // coded Alphabet -> normal Alphabet
		std::unordered_map<char, char> m_InverseLowerAlphabeticMapping; // coded lower Alphabet -> normal lower Alphabet

		static inline const char* REFERNCE_ALPHABET{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
		static inline const char* REFERNCE_ALPHABET_LOWER{ "abcdefghijklmnopqrstuvwxyz" };
	};

}