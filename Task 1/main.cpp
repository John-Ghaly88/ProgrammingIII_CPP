#include <iostream>

using namespace std;

string encrypt (string s, string p);
string decrypt (string s, string p);

int main()
{
    string text;
    cout << "Enter the text please" << endl;
    getline(cin, text);

    string pass;
    cout << "Enter the password please" << endl;
    getline(cin, pass);

    cout << "The encrypted text is: " << encrypt(text, pass) << endl;
    //cout << "The decrypted text is: " << decrypt(text, pass) << endl;

    return 0;
}

string encrypt (string s, string p){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ')
            continue;
        else{
            int x = (int) s[i];
            for (int n = p[i]-'A'; n>0; n--){
                if (x==122)
                    x=96;
                x++;
            }
            s[i] = (char) x;
        }
    }
    return s;
}

string decrypt (string s, string p){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ')
            continue;
        else{
            int x = (int) s[i];
            for (int n = p[i]-'A'; n>0; n--){
                if (x==97)
                    x=123;
                x--;
            }
            s[i] = (char) x;
        }
    }
    return s;
}
