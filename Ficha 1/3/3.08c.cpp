#include <iostream>
using namespace std;

int gcd(int n0, int n1){
    if (n0 == n1) return n0;
    if (n0 == 0) return n1;
    if (n1 == 0) return n0;
    do{
        if (n0 < n1) n1 -= n0;
        else n0 -= n1;
    }while (n0 != n1);
    return n0;
}

void reduceFraction(int &numerator, int &denominator){
    int g = gcd(numerator, denominator);
    while (g != 1){
        numerator /= g;
        denominator/= g;
        g = gcd(numerator, denominator);
    }
}

bool readFraction(int &numerator, int &denominator){
    if (denominator == 0)
        return false;
    return true;
}

int main() {
    int numerator, denominator, numerator1, denominator1;
    char c, op;
    cout << "Write a fraction: ";
    cin >> numerator >> c >> denominator;
    if (c != '/'){
        cerr << "Invalid Format";
        return 0;
    }
    else if (!readFraction(numerator, denominator))
        cout << "That's not a valid fraction";
    else{
        cout << "Chose an operation (+, -, *, /): ";
        cin >> op;
        cout << "Write another fraction: ";
        cin >> numerator1 >> c >> denominator1;
        if (c != '/'){
            cerr << "Invalid Format";
            return 0;
        }
        else if (!readFraction(numerator1, denominator1))
            cout << "That's not a valid fraction";
        else{
            int temp = denominator;
            switch(op){
                case '+':
                    if (denominator == denominator1)
                        numerator += numerator1;
                    else{
                        numerator *= denominator1;
                        denominator *= denominator1;
                        numerator1 *= temp;
                        numerator += numerator1;
                    }
                    break;
                case '-':
                    if (denominator == denominator1)
                        numerator -= numerator1;
                    else{
                        numerator *= denominator1;
                        denominator *= denominator1;
                        numerator1 *= temp;
                        numerator -= numerator1;
                    }
                    break;
                case '*':
                    numerator *= numerator1;
                    denominator *= denominator1;
                    break;
                case '/':
                    numerator *= denominator1;
                    denominator *= numerator1;
                    break;

            }
        reduceFraction(numerator, denominator);
        cout << numerator << c << denominator;
        }
    }
    
    
    return 0;
}