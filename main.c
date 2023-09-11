/*
Katherine Larsen  
Vignere cipher This homework problem encyrpts messages given a Vignere cipher key. I have coded this problem to be user friendly (i.e the user enters the message, key length, and key values. (These values are not hardcoded in). This allows for the program to be more versitile and adatable if different messages wanted to be encrypted. When running the program, please ensure you write the message, key length, and key values carefully.
*/

//Included proper libraries: 
#include <iostream>
#include <string>
#include <vector>
#include <limits> 
#include <sstream>

using namespace std;

//Function to ensure user entered iteger
int validateInputInteger(const string& prompt);

//Function to parse message into indivual characters
vector<char> parseIntoArray(const string& input);
/*Using a vector bc vectors allow us to store a collection of elements (in this case, characters) of varying sizes.
Unlike arrays, vectors can grow or shrink in size dynamically, which is incredibly useful since we don't know the exact size of message

Using const string& as the variable type bc const indicates that the function will not modify the content of the string,
which provides higher saftey features. Using a reference (&) is more efficient because it avoids making a copy of the input string, especially important for large messages.
*/

//Function that takes a message and a key, and for each character in the message, it shifts the character by a certain amount
//determined by the key. This process creates an encrypted message where the original characters are substituted with new ones
void vignereEncrypt(vector<char>& message, const vector<int>& key);

int main() 
{
    //Define variables
    //Ct represents what part of the problem we are on. Part A, B, or C. It simply controls what message to print to increase readability
    int ct = 1;

    //Loop through main twice for parts A, B since the encryption process is the same
for (int i = 0; i < 2; i++) 
{
        
    if (ct == 1) 
    {
        cout << "Part A: “Explanation” using the key (11, 4, 6) (key length = 3)\n";
    }//end of if
    
        else if (ct == 2)
        {
        cout << "\nPart B: Encrypt the plaintext “sendmoremoney” with the key stream (9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9) (key length = 13)\n";
        }//end of if 
    
    //Get user inputed message
    string text;
    cout << "Enter the message: ";
    cin >> text;

  // Convert the message to lowercase before encryption
    for (int i = 0; i < text.length(); i++) 
    {
    text[i] = tolower(text[i]);
    }//end of for loop 
  
  int keyLength; 
  string input;

  //Validating input that user only enters a positive number, and if they were to enter more than one number, the program will only accept the first value
 do {
        keyLength = validateInputInteger("Enter the key length: ");
        if (keyLength <= 0) {
            cout << "Invalid key length. Please enter a positive integer: ";
        }
        getline(cin, input); // Read and discard any extra input
    } while (keyLength <= 0 || !input.empty());

//Asking user to enter x key values which are put into the key vector
    vector<int> key;
    for (int i = 0; i < keyLength; i++) 
    {
        int keyValue = validateInputInteger("Enter key value " + to_string(i + 1) + ": ");
        key.push_back(keyValue);
    }

 
//Call parseIntoArray function so it will be easier to perform encrpytion. Store results in lettersArray
    vector<char> lettersArray = parseIntoArray(text);

//Call vignereEncrypt functino to perform the encryption
    vignereEncrypt(lettersArray, key);
    
    //Loop through the letters array and print out the message character by character
    cout << "Encrypted Message: ";
    for (size_t i = 0; i < lettersArray.size(); i++)
    {
    cout << lettersArray[i];
    }//end of for loop

    cout << endl;
    
    //Increment ct so it may print the appropriate message for what part we are (A, B, or C.)
ct++;
if (ct == 3)
 {
     cout << "\nPart 3. Using the ciphertext produced in part (b), find a key so that the ciphertext decrypts to the plaintext “cashnotneeded”\n";
 
    //Finding key to decrypt the encrypted message to "cashnotneeded"
    string targetPlaintext = "cashnotneeded";
        
    vector<char> ciphertext = lettersArray; // Copy the encrypted message

    for (int i = 0; i < keyLength; i++) 
    {
      //difference represents the shift needed to convert the target plaintext character to its corresponding position in the alphabet
        int targetShift = targetPlaintext[i] - 'a';

      //ciphertext[i] - 'a' calculates the position of the ciphertext character in the alphabet by subtracting ASCII value 'a'.
      //Then, we subtract the previously calculated targetShift, which is the shift applied to the target plaintext character.
      //Adding 26 and taking % 26 ensures that the result remains within the range of valid alphabet positions (0 to 25).
        int currentShift = (ciphertext[i] - 'a' - targetShift + 26) % 26;

        key[i] = currentShift;
    }//end of for loop 

     // Print out the key that was found
    cout << "Key to decrypt to 'cashnotneeded': ";
    for (int i = 0; i < key.size(); i++) {
        cout << key[i] << " ";
    }
 }//end of if 
} //end of for loop
    return 0;
}//end of main 

// Function for input validation
int validateInputInteger(const string& prompt) {
    int value;
    cout << prompt;

  //Ensuring that only an integer is entered and not anything else 
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}

//Function to parse message into ind. char
vector<char> parseIntoArray(const string& input)
{
    vector<char> outputArray;
    
    //Loop through og message 
    for (size_t i = 0; i < input.length(); i++) 
    {
        //Take the character at index i from the og message and add that character to the end of the outputArray vector.
        //Basically each character from the input string is stored as an individual element in the vector so arthimetic can later be performed to encrypt each letter
        outputArray.push_back(input[i]);
        
    }// end of for loop 
    return outputArray;
    
} //end of function 


//Function that encrypts message
void vignereEncrypt(vector<char>& message, const vector<int>& key) {
   
    //Array called alphabet that contains all the letters of the English alphabet. 
    //This array is used as a reference for the encryption process
    char alphabet[26] = {
        'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x',
        'y', 'z'
    };
    
    //iterates through each character in the provided message.
    for (size_t i = 0; i < message.size(); i++) 
    {
        char originalLetter = tolower(originalLetter);
        originalLetter = message[i];
        
        //For each character, calculates the index of that character in the alphabet array. This index represents 
        //the position of the character in the alphabet, with 'a' being index 0, 'b' being index 1, etc.
        int alphabetIndex = originalLetter - 'a';
        
        //It retrieves the corresponding key value for the current iteration
        //Bc the key can be shorter than the message --> (i % key.size()) to repeat the key values as needed
        int shift = key[i % key.size()];
        
        //The character in the message is shifted by the value of the key 
        //The shifted position is calculated by adding the alphabetIndex and shift together 
        //The result might be larger than the size of the alphabet, so % 26 is used to ensure that the index stays within the
        //range of the alphabet
        message[i] = alphabet[(alphabetIndex + shift) % 26];
    }//end of for loop
}//end of function



