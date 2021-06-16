#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float min, max, increment;
    cout << "Define the range: " ; cin >> min >> max;
    cout  << "Define the increment: " ; cin >> increment;
    double rad;
    cout << "ang    sin       cos       tan" << endl;
    for (int i = min; i <= max; i += increment){
        rad = i * M_PI /180;
        cout << fixed << setprecision(6);
        cout << i << "  " << sin(rad) << "   " << cos(rad) << "   ";
        if (i == 90 || i%180 == 90) cout << "infinite" << endl;
        else cout << tan(rad) << endl;

    }
    
    return 0;
}