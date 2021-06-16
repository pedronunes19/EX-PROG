#include <iostream>
using namespace std;

int main() {
    long int a, b;
    cin >> a >> b;
    long int sum = a+b;
    if (!cin){
        cerr << "invalid input" << endl;
        return 0;
    }
    if(a < 0 && b < 0 && sum > 0)
        cout << "sum underflow";
    
    else if (sum < 0 && a > 0 && b > 0) 
        cout << "sum overflow";
    else 
        cout << sum;
    
    
    return 0;
}