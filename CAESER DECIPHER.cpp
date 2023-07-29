#include <iostream>
#include <string>

using namespace std;

string caesarEncrypt(string plaintext, int key) {
    string ciphertext = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char encryptedChar = ((ch - base + key) % 26) + base;
            ciphertext += encryptedChar;
        }
        
        else if (isdigit(ch)) {
            // Handle numeric characters
            char encryptedChar = ((ch - '0' + key) % 10) + '0';
            ciphertext += encryptedChar;
        } 

        
         else {
            ciphertext += ch;
        }
    }

    return ciphertext;
}

string caesarDecrypt(string ciphertext, int key) {
    string decryptedText = "";
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char decryptedChar = ((ch - base - key + 26) % 26) + base;
            decryptedText += decryptedChar;
        } 
        
        else if (isdigit(ch)) {
            char decryptedChar = ((ch - '0' - key + 10) % 10) + '0';
            decryptedText += decryptedChar;
        } 
        
        else {
            decryptedText += ch;
        }
    }
    return decryptedText;
}

int main() {
    int key;
    string message;

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter the key (shift value): ";
    cin >> key;

    string encryptedMessage = caesarEncrypt(message, key);
    string decryptedMessage = caesarDecrypt(encryptedMessage, key);

    cout << "Encrypted Message: " << encryptedMessage << endl;
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
