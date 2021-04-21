#include <iostream>
#include <vector>
using namespace std;

bool ascending(int x, int y){
    if (x < y)
        return true;
    return false;
}

bool descending(int x, int y){
    if (x > y)
        return true;
    return false;
}

void bubbleSort(vector<int> &v){
    bool lastSort;
    int iter = 0;
    char order;
    cout << "Ascending (a) or Descending(d)? ";
    cin >> order;
    do{
        lastSort = true;
        for(int i = 0; i < v.size() - iter; i++){
            if ((!ascending(v[i], v[i+1]) && order == 'a')||(!descending(v[i], v[i+1]) && order == 'd')){
                lastSort = false;                                   
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                
            }
        }
        iter += 1;
    }while(!lastSort);
}

int main() {
    vector<int> v;
    int size;
    cout << "Pick vector size: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    bubbleSort(v);
    cout << "Rearranged:" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    
    return 0;
}
