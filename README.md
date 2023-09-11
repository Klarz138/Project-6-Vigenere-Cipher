# Project-6-Vigenere-Cipher
Project 6 baby! Here in this project, I worked to learn more about cryptography because I recognize its fundamental role in securing data and communications in today's digital world. This program, specifically designed for Vigenère cipher encryption, demonstrates the practical application of cryptographic techniques.

Here's a breakdown of what this code does:

User Input and Initialization:

The program begins by prompting the user to input a message.
The message is converted to lowercase to ensure uniformity.
The user is then asked to provide the key length and the key values.
Vigenère Encryption (Parts A and B):

The Vigenère encryption process is applied to the message using the provided key. The key values are applied cyclically, allowing for keys shorter than the message.
The encrypted message is displayed character by character.
Part C: Decrypting to "cashnotneeded":

In Part C, the program aims to decrypt the previously encrypted message to "cashnotneeded."
It calculates the required key to perform the decryption based on the target plaintext.
The key used for decryption is printed.

Functions and Their Purposes:

int validateInputInteger(const string& prompt): This function ensures that the user enters a valid positive integer. It repeatedly prompts the user until a valid input is received.

vector<char> parseIntoArray(const string& input): This function takes a string as input and parses it into individual characters. It returns a vector of characters, which makes it easier to perform encryption.

void vignereEncrypt(vector<char>& message, const vector<int>& key): This function performs the Vigenère encryption on the message using the provided key. It shifts each character in the message by the corresponding key value to create the encrypted message.

Project Goals and Learning:
This project is a valuable learning experience in cryptography. It covers aspects such as user input validation, character manipulation, and encryption techniques. By working on this code, I have gained practical insights into the world of cryptography and its importance in ensuring data security. Understanding encryption algorithms like the Vigenère cipher enhances my skills and knowledge as a developer, enabling me to contribute to the field of cybersecurity.

In summary, Project 6 has been an exciting journey into cryptography, equipping me with the knowledge and skills to better appreciate and apply encryption techniques for securing data and communication.
