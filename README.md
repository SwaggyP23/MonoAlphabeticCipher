# MonoAlphabeticCipher
## An implentation of a mono-alphabetic cipher

# Mono-Alphabetic Cipher?
A mono-alphabetic cipher is a well-defined way to encrypt messages using a simple substitution technique that each letter in the original text is substituted by an another letter from the alphabet to form the ciphertext. However, each occurance of that letter will be substituted by the same letter in the ciphertext. An example of a mono-alphabetic cipher is the `Caeser cipher`, where each letter of the original text is shifted by a certain value along the alphabet in order to form the ciphertext. For example, if the shift value was set to, say 4, each letter **'A'** in the original text would be replaced by the letter **'E'** and every letter **'F'** would be replaced by the letter **'J'** and as such to form the ciphertext.

# Problems with Caeser?
A problem that rises with a `Caeser cipher` is that anyone with the ability to apply [*Frequency Analysis*](#References-anchor) can crack the cipher of a Caeser ciphered message since the frequency of occurence of a certain letter in the original text will be the same also in the ciphered text. So a person can perform a frequency analysis in order to determine the shift value used and retrieve the original text

# Solution?
A `mono-alphabetic cipher` works sort of the same as the `Caeser cipher` in terms of using the shifting of alphbet technique, however it adds an extra layer of complexity on top by adding the use of a **Keyword** in order to create a new ordering of the alphabet.
For example, We all know the standard alphabet that we studied back in kindergarten class:
> ABCDEFGHIJKLMNOPQRSTUVWXYZ

Okay, now lets say the ciphering keyword for today is `Basketball`.
1. Change the word to be in all capital or small letters (depends on the implementation), I used full caps for this one
    - Basketball -> BASKETBALL
2. Remove all duplicates from the word BASKETBALL
    - BASKETBALL -> BASKETL
3. Now we remove all the letters in `BASKETL` from the original alhabet and place them in the beginning and shift all the other letters forward. So then the new alphabet would be:
> BASKETLCDFGHIJMNOPQRSUVWXYZ

And now, every letter **'A'** in the original text is substituted by a **'B'** and every letter **'J'** is replaced by an **'F'**.

As you can hopefully notice that this type of ciphering technique is powerful as much as the keyword can be spanned to contain different letters, because in the above examples a letter **'Z'** will remain a **'Z'** in the ciphertext and so is the case to some other letters. Keywords such as *Ball* or *Mississippi* are bad keywords to use and other words like *Pseudonym* or something like *KDWYMLOTFIQHVCSBUNPZEJRAXG*, which is a random ordering of the alphabet, are perfect keywords to use!

# TODO:
- Expand on the encryption to also consider numbers and symbols by shifting the numbering digits (0 -> 9) also by applying the same technique

<a id="References-anchor"></a>
# References:
- [Wikipedia (Caeser cipher)](https://en.wikipedia.org/wiki/Caesar_cipher)
- [101computing.net (Frequency Analysis)](https://www.101computing.net/frequency-analysis/)
- [Cihangir Tezcan (Frequency Analysis)](https://www.youtube.com/watch?v=opqgXvGsk6U)
- [101computing.net (mono-alphabetic cipher)](https://www.101computing.net/mono-alphabetic-substitution-cipher/)
- [Crypto Corner (mono-alphabetic cipher)](https://crypto.interactive-maths.com/monoalphabetic-substitution-ciphers.html)