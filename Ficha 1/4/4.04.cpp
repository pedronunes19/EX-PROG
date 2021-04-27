#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int binarySearch(const vector<int> &v, int value){
    int first = 0, last = v.size() - 1, result;
    bool found = false;
    while(!found){
        int middle = (int)floor((last - first) / 2);
        if (value == v[middle]){
            result = middle;
            found = true;
        }
        else if (value < v[middle]){
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
        if (last < first){
            return -1;
        }
    }
    return result;
}

int main() {
    vector<int> v;
    int size, value;
    cout << "Pick vector size: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    cout << "Value to search: ";
    cin >> value;
    int searchRes = binarySearch(v, value);
    if (searchRes == -1){
        cerr << "value not found" << endl;
        return 0;
    }
    else{
        cout << "value was found at index " << searchRes;
    }
    
    
    return 0;
}