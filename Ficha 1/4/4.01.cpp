#include <iostream>
using namespace std;

int findValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2){
    if ((pos2 - pos1 +1) < nElem)
        nElem = pos2 - pos1 + 1;
    for (int i = pos1; i < pos1 + nElem; i++){
        if (a[i] == value)
            return i;
    }
    return -1;
}

void readArray(int a[], size_t nElem){
    for (int i = 0; i < nElem; i++){
        cout << "[" << i << "] = ";
        cin >> a[i]; 
    }
}

int main() {
    int a [1000];
    int pos1, pos2, value;
    size_t n;
    cout << "How many elements of the array do you want to write? ";
    cin >> n;
    if (n > 1000){
        cerr << "Too many values" << endl;
        return 0;
    }
    readArray(a, n);

    cout << "Choose an interval of indexes to search: ";
    cin >> pos1 >> pos2;
    if(pos1 < 0 || pos1 > 999 || pos2 < 0 || pos2 > 999 || pos2 < pos1){
        cerr << "Invalid interval" << endl;
        return 0;
    }
    cout << "How many elements do you want to search? ";
    cin >> n;
    cout << "What value are you loking for? ";
    cin >> value;

    cout << findValueInArray(a, n, value, pos1, pos2);

    

    return 0;
}