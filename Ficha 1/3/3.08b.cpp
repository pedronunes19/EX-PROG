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
    int numerator, denominator;
    char c;
    cout << "Write a fraction: ";
    cin >> numerator >> c >> denominator;
    if (c != '/'){
        cerr << "Invalid Format";
        return 0;
    }
    else if (!readFraction(numerator, denominator))
        cout << "That's not a valid fraction";
    else{
        reduceFraction(numerator, denominator);
        cout << numerator << c << denominator;
    }
    
    
    return 0;
}