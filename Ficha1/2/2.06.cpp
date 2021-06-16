#include <iostream>
using namespace std;

int main() {
    int n, q;
    int amount = 0;
    double j;
    
    cout << "Input the values for years, amount and interest rate: ";
    cin >> n >> q >> j;
    for (int i = 1; i <= n; i++){
        amount += q;
        amount = amount + (j/100)*amount;
    }
    cout << "You can withdraw " << amount;
    return 0;
}