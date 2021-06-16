#include <iostream>
using namespace std;

int main() {
    unsigned int num, n1, n2;
    cout << "Insert a number: ";
    cin >> num;
    if (num > 999 || num < 100){
        cerr << num << " is not a 3 digit number" << endl;
        return 0;
    }
    n1 = num%10;
    n2 = (((num - num%10)/10)-((num - num%10)/10)%10)/10;
    bool isPalindrome = (n1 == n2);
    if (isPalindrome) cout << num << " is a palindrome";
    else cout << num << " is not a palindrome";


    return 0;
}