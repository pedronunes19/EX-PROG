#include <iostream>

namespace myfuncs{
    void cout(const std::string &s){
        std::cout << s;  // I'm pretty sure it's supposed to do something else but it doesn't matter much 
    }
    bool endl(const std::string &s){
        if (s[s.length()-1] >= 'a' && s[s.length()-1] <= 'z')
            return true;
        return false;
    }
}

int main(){
    std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    myfuncs::cout(s);
    std::cout << std::endl << myfuncs::endl(s);
    return 0;
}