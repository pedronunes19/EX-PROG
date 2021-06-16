#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned int num;
    bool isPalindrome = true;
    cout << "Insert a number: ";
    cin >> num;
    if (num < 100){
        cerr << num << " is not a valid number" << endl;
        return 0;
    }
    unsigned int temp = num;
    while (temp > 9){
        int n1 = temp%10, temp2 = temp, next = 0;
        int i = 0;
        while(temp2 > 9){
            if (i>0) next += temp2%10 * pow(10, i);
            else next += temp2%10;
            temp2 = (temp2-temp2%10)/10;
            i++;
        }
        if (n1 != temp2){
            isPalindrome = false;
            break;
        }
        temp = (next-next%10)/10;
        // cout << temp << endl;
    }
    

    
    
    if (isPalindrome) cout << num << " is a palindrome";
    else cout << num << " is not a palindrome";


    return 0;
}