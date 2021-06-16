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
    int num, i = 2;
    cout << "Insert a number: ";
    cin >> num;
    while(!isPrime(num)){
        if(!isPrime(i)){
            i++;
            continue;
        }
        else if(num%i == 0){
            cout << i << endl;
            num /= i;
        }
        else i++;

    }
    cout << num;
    return 0;
}