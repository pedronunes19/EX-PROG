#include <iostream>
#include <iomanip>
#include <cmath>

double heron(int n, int nMaxIter, int delta){
    int i = 0;
    double rq = 1, rqn, dif;
    do{
        rqn = (rq + n / rq) / 2;
        dif = n - pow(rqn, 2);
        i++;
        rq = rqn;
    }while (abs(dif) > delta && i <= nMaxIter);
    return rqn;
}

int main(){
    int n, nMaxIter = 10;  // different nMaxIter and delta values will result in a different precision
    double delta = 0.00001;
    std::cout << "Select a number to calculate the square root\n";
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(5);
    std::cout<< "Result = " << heron(n, nMaxIter, delta) << " Real sqrt = " << sqrt(n);
    return 0;
}