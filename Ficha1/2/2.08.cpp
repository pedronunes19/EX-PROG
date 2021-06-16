#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double rad;
    cout << "ang    sin       cos       tan" << endl;
    for (int i = 0; i <= 90; i += 15){
        rad = i * M_PI /180;
        cout << fixed << setprecision(6);
        cout << i << "  " << sin(rad) << "   " << cos(rad) << "   ";
        if (i == 90) cout << "infinite" << endl;
        else cout << tan(rad) << endl;

    }
    
    return 0;
}