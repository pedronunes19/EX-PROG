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

int main() {
    int a, b;
    cout << "Input 2 numbers: ";
    cin >> a >> b;
    if (a == 0 && b == 0){
        cerr << "Invalid input" << endl;
        return 0;
    }
    cout << "GCD = " << gcd(a, b);
    
    return 0;
}