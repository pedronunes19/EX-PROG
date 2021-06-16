#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n0, n1, guess;
    long long tim;
    srand(time(NULL));
    
    n0 = (rand()%8) + 2;
    n1 = (rand()%8) + 2;

    cout << "What's the product of " << n0 << " and " << n1 << "? ";
    long long start = time(NULL);
    cin >> guess;
    long long end = time(NULL);
    tim = end-start;

    if (guess == n0*n1){
        if (tim < 5) 
            cout << "Good" << endl;
        else if (tim <= 10) 
            cout << "Satisfactory" << endl;
        else 
            cout << "Insufficient" << endl;
        
    } 
    else 
        cout << "Very bad" << endl;
        
    

    
    return 0;
}