#include <iostream>
#include <cmath>
using namespace std;

bool leapYear(int year){
    if(year % 400 == 0)
        return true;
    else if (year % 4 == 0 && year % 100 != 0)
        return true;
    else 
        return false;
}

int nDays(int month, int year){
    if (month == 2){           // february
        if (leapYear(year))
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

int getFirst2 (int year){
    while (year > 99){
        year = (year - year%10)/10;
    }
    return year;
}

int weekDay (int day, int month, int year){
    int s, a, c, ds;
    int monthCode[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

    if (leapYear(year)){
        monthCode[0] =  6;
        monthCode[1] = 2;
    }

    c = monthCode[month - 1];
    cout << c;
    a = year % 100;
    s = getFirst2(year);

    int f = floor((5*a)/4);

    ds = (f + c + day - 2*(s%4)+ 7) % 7;

    return ds;
}

int main() {
    int year, month, day;
    string months [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string week [7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    cout << "day, month and year: ";
    cin >> day >> month >> year;

    // checking inputs
    if (month > 12 || month < 0){                      
        cerr << "That month just doesn't exist" << endl;
        return 0;
    }
    if (year < 10){                                                        
        cerr << "The formula does not work for that year" << endl;
        return 0;
    }
    if (day < 1 || day > nDays(month, year)){
        cerr << "Please choose another day" << endl;
        return 0;
    }

    cout << week[weekDay(day, month, year) - 1] << ", " << day << " of " << months[month - 1] << ", " << year;
    
    
    return 0;
}