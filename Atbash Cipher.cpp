#include <iostream>
#include <string>
using namespace std;

void cipherEncryption() {
    string message;
    cout << "Enter Message: ";
    getline(cin, message);
    //cin.ignore();

    //message to upper case
    for (int i = 0; i < message.length(); i++) {
        message[i] = toupper(message[i]);
    }

    string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlphabet = "";
    for (int i = Alphabet.length() - 1; i > -1; i--) {
        reverseAlphabet += Alphabet[i];
    }

    string encryText = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == 32) {
            encryText += " ";
        }
        else {
            for (int j = 0; j < Alphabet.length(); j++) {
                if (message[i] == Alphabet[j]) {
                    encryText += reverseAlphabet[j];
                    break;
                }
            }
        }
    }

    cout << "Encrypted Text: " << encryText;
}

void cipherDecryption() {
    string message;
    cout << "Enter Encrypted Message: ";
    getline(cin, message);
    cin.ignore();

    //message to upper case
    for (int i = 0; i < message.length(); i++) {
        message[i] = toupper(message[i]);
    }

    string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlphabet = "";
    for (int i = Alphabet.length() - 1; i > -1; i--) {
        reverseAlphabet += Alphabet[i];
    }

    string dencryText = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == 32) {
            dencryText += " ";
        }
        else {
            for (int j = 0; j < reverseAlphabet.length(); j++) {
                if (message[i] == reverseAlphabet[j]) {
                    dencryText += Alphabet[j];
                    break;
                }
            }
        }
    }

    cout << "Decrypted Text: " << dencryText;
}


int main()
{
    string x = "0";
    while (x != "x")
    {
        int choice;
        cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Encryption" << endl;
            cipherEncryption();
        }
        else if (choice == 2) {
            cout << "Decryption" << endl;
            cipherDecryption();
        }
        else {
            cout << "Wrong Choice" << endl;
        }

        cout << "\nIf you want to continue, press anything, and if you want to exit, press 'x' : \n\n";
        cin >> x;
    }


}