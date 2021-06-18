#include <iostream>
#include <set>
#include <random>
#include <ctime>

class Bet{
    public:
        Bet();
        void show();
    private:
        std::set<int> mainN;
        std::set<int> starN;
};


Bet::Bet(){
    while (mainN.size() != 5){
        int r = rand() % 50 + 1;
        mainN.insert(r);
    }
    while (starN.size() != 2){
        int r = rand() % 10 + 1;
        starN.insert(r);
    }
}


void Bet::show(){
    for (auto it = mainN.begin(); it != mainN.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for (auto it = starN.begin(); it != starN.end(); it++){
        std::cout << *it << " ";
    }
}





int main(){
    srand(time(NULL));
    Bet b1, b2;
    b1.show();
    return 0;
}