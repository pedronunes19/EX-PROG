#include <iostream>
using namespace std;

int main() {
    float a, b, c, d, e, f;
    cout << "Input the values a, b, c, d, e, f for the equations: a*x + b*y = c\n"
            "                                                     d*x + e*y = f" << endl;
    cin >> a >> b >> c >> d >> e >> f;
    float nx, ny ,den;
    

    den = (a * e - b * d);
    nx = (c * e - b * f);
    ny = (a * f - c * d);
    cout << nx/den << endl;
    cout << ny/den << endl;
    if (nx == 0 && ny == 0)
        cout << "This system is inconsistent" << endl;
    else if (den == 0 )
        cout << "This system is impossible" << endl;
    else

        cout << "x = " << nx/den << endl
             << "y = " << ny/den << endl;
        
    
    
    return 0;
}