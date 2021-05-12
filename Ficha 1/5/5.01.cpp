#include <iostream>
using namespace std;

char encryptChar(char c, int key){
    if(c == ' '){
        return c;
    }
    const int LL = (int) 'a', UL = (int) 'z', LU = (int) 'A', UU = (int) 'Z';
    int charInt = (int) c;
    if (charInt <= UL && charInt >= LL){
        if (key > 0){
            for (int i = 0; i < key; i++){
                if (charInt == UL)
                    charInt = LL;
                else
                    charInt += 1;
            }

        }
        else{
            for (int i = 0; i > key; i--){
                if (charInt == LL)
                    charInt = UL;
                else
                    charInt -= 1;
            }
        }
    } 
    else{
        if (key > 0){
            for (int i = 0; i < key; i++){
                if (charInt == UU)
                    charInt = LU;
                else
                    charInt += 1;
            }

        }
        else{
            for (int i = 0; i > key; i--){
                if (charInt == LU)
                    charInt = UU;
                else
                    charInt -= 1;
            }
        }
    }
    return (char) charInt;
}

string encryptString(string s, int key){
    for (int i = 0; i < s.length(); i++){
        s[i] = encryptChar(s[i], key);
    }
    return s;
}

int main() {
    cout << encryptString("A lot of Text and WORDS", 40);
    
    return 0;
}