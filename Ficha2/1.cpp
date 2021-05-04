#include <iostream>
using namespace std;

class Date{
    public:
        Date(unsigned int year, unsigned int month,unsigned int day);
        Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
        void setYear(unsigned int year) ;
        void setMonth(unsigned int month) ;
        void setDay(unsigned int day) ;
        void setDate(unsigned int year, unsigned int month, unsigned int day) ;
        unsigned int getYear() const;
        unsigned int getMonth() const;
        unsigned int getDay() const;
        string getDate() const; // returns the date in format "yyyy/mm/dd"
        void show() const; // shows the date on the screen in format "yyyy/mm/dd"
        bool isValid();
    private:
        unsigned int year;
        unsigned int month;
        unsigned int day;
        unsigned int nDays(unsigned int year, unsigned int month) const;
}; 

Date::Date(unsigned int year, unsigned int month, unsigned int day){
    this -> year = year;
    this -> month = month;
    this -> day = day;
}

Date::Date(string yearMonthDay){
    year = stoi(yearMonthDay.substr(0, 4));
    month = stoi(yearMonthDay.substr(5, 2));
    day = stoi(yearMonthDay.substr(8, 2));
}

unsigned int Date::nDays(unsigned int year, unsigned int month) const{
    bool leap;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        leap = true;
    }
    else{
        leap = false;
    }
    if (month == 2){           // february
        if (leap)
            return 29;
        else
            return 28;
    }
    if (month <= 7){           // up to july
        if (month % 2 == 0)
            return 30;
        else
            return 31;
    }
    else{                      // august and forward
        if (month % 2 == 0)
            return 31;
        else
            return 30;
    }
}

void Date::setYear(unsigned int year){
    this -> year = year;
}

void Date::setMonth(unsigned int month){
    this -> month = month;
}

void Date::setDay(unsigned int day){
    this -> day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day){
    this -> year = year;
    this -> month = month;
    this -> day = day;
}

unsigned int Date::getYear() const{
    return year;
}

unsigned int Date::getMonth() const{
    return month;
}

unsigned int Date::getDay() const{
    return day;
}

string Date::getDate() const{
    return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}

void Date::show() const{
    cout << year << "/" << month << "/" << day << endl;
}

bool Date::isValid(){
    if (day < 0 || day > nDays(year, month)){
        return false;
    }
    else if (month < 0 || month > 12){
        return false;
    }
    return true;
}


int main() {
    Date d1(2021, 5, 4), d2("2050/05/03");
    d1.setDate(2022, 6, 32);
    d2.setYear(2021);
    d2.setMonth(2);
    d2.setDay(28);
    cout << d1.getDate() << endl;
    cout << d2.getYear() << ' ' << d2.getMonth() << ' ' << d2.getDay() << endl;
    d1.show();
    cout << d1.isValid() << endl;
    d2.show();
    cout << d2.isValid() << endl;
    
    return 0;
}