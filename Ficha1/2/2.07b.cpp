#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    bool prime = true;
    
    for (int i = 2; i <= ceil(sqrt(n)); i++){
        if (n == 2) break;
        if (n%i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}

int main() {
    for(int i = 2; i <= 1000; i++){
        if (isPrime(i)) cout << i << endl;
    }
    
    return 0;
}