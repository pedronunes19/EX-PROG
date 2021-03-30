#include <iostream>
#include <vector>
using namespace std;

void readVector(vector<int> &v){
    int n;
    while (true){
        cin >> n;
        if (cin.eof())
            break;
        v.push_back(n);
    }

    
}

int findValueInVector(const vector<int> v, int value, size_t pos1, size_t pos2){
    for (int i = pos1; i <= pos2; i++){
        if (v[i] == value)
            return i;
    }
    return -1;
}


int main() {
    vector<int> v;
    int pos1, pos2, value;
    cout << "Start by defining your vector\n";
    readVector(v);
    cin.clear();
    cout << "Choose an interval of indexes to search: ";
    cin >> pos1 >> pos2;
    if(pos1 < 0 || pos1 > v.size() - 1 || pos2 < 0 || pos2 > v.size() - 1 || pos2 < pos1){
        cerr << "Invalid interval" << endl;
        return 0;
    }
    cout << "What value are you loking for? ";
    cin >> value;

    cout << findValueInVector(v, value, pos1, pos2);
    
    
    
    return 0;
}