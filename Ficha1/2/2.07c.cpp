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
    int i = 2, count = 0;
    do{
        if(isPrime(i)){ count+=1;
        cout << i << endl;}
        i++;
    }while(count<100);
    return 0;
}