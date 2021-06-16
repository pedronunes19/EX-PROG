#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    bool prime = true;
    cout << "insert a number: "; cin >> n;
    
    for (int i = 2; i <= ceil(sqrt(n)); i++){
        if (n == 2) break;
        if (n%i == 0){
            prime = false;
            break;
        }
    }

    if(prime) cout << n << " is prime";
    else cout << n << " is not prime";

    return 0;
}