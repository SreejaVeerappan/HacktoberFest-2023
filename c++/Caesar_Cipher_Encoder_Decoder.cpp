#include <iostream>
#include <string>

using namespace std;

void caesarCipher(string& str, long long key, bool isEncryption) {
    for (long long i = 0; i < (long long)str.length(); i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            long long t = (long long)str[i] + (isEncryption ? key : -key);
            if (isEncryption && t > 'Z') {
                str[i] = 'A' - 1 + (t - 'Z') % 26;
            } else if (!isEncryption && t < 'A') {
                str[i] = 'Z' + 1 - ('A' - t) % 26;
            } else {
                str[i] = t;
            }
        } else if (str[i] <= 'z' && str[i] >= 'a') {
            long long t = (long long)str[i] + (isEncryption ? key : -key);
            if (isEncryption && t > 'z') {
                str[i] = 'a' - 1 + (t - 'z') % 26;
            } else if (!isEncryption && t < 'a') {
                str[i] = 'z' + 1 - ('a' - t) % 26;
            } else {
                str[i] = t;
            }
        }
    }
}

int main() {
    cout << "Caesar Cipher Encoder and Decoder" << endl;
    long long option;
    cout << "Modes:\n1.Decode\n2.Encode\n3.Exit\nChosen Mode: ";
    cin >> option;

    if (option == 1 || option == 2) {
        string str;
        long long key;

        if (option == 1) {
            cout << "Enter the string to decode: ";
        } else {
            cout << "Enter the string to encode: ";
        }
        cin >> str;

        cout << "Enter key: ";
        cin >> key;

        if (key < 0) {
            cout << "Key has to be positive!" << endl;
            return 1; // Indicate an error
        }

        caesarCipher(str, key, option == 2);

        if (option == 1) {
            cout << "Decoded string is --> " << str << endl;
        } else {
            cout << "Encoded string is --> " << str << endl;
        }
    } else if (option == 3) {
        cout << "Thanks for using! Exiting now." << endl;
    } else {
        cout << "Invalid option. Please try again." << endl;
    }

    return 0;
}
