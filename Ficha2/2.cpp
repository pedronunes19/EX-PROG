#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Student {
    public:
        Student();
        Student(const string &code, const string &name);
        void setGrades(double shortExam, double project, double exam);
        string getCode() const;
        string getName() const;
        int getFinalGrade() const;
        // other get and set methods
        bool isApproved() const; // is the student approved or not ?
        static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
    private:
        string code; // student code
        string name; // student complete name
        double shortExam, project, exam; // grades obtained by the student in the different components
        int finalGrade;
};

int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;

Student::Student(){

}

Student::Student(const string &code, const string &name){
    this -> code = code;
    this -> name = name;
}

string Student::getCode() const{
    return code;
}

string Student::getName() const{
    return name;
}

int Student::getFinalGrade() const{
    return finalGrade;
}

void Student::setGrades(double shortExam, double project, double exam){

    this -> shortExam = shortExam;
    this -> project = project;
    this -> exam = exam;

    int rawFinal = (weightExam*exam + weightProject*project + weightShortExam*shortExam)/100;
    if (rawFinal - floor(rawFinal) >= 0.5){
        finalGrade = ceil(rawFinal);
    }
    else{
        finalGrade = floor(rawFinal);
    }
}

bool Student::isApproved() const{
    if (finalGrade < 10){
        return false;
    }
    return true;
}

Student readStudentData(){
    string code, name;
    int sExam, p, exam;
    cout << "Student code? ";
    getline(cin, code);
    cout << "Student name? ";
    getline(cin, name);
    Student s(code, name);
    cout << "Short exam grade? ";
    cin >> sExam;
    cout << "Project grade? ";
    cin >> p;
    cout << "Exam grade? ";
    cin >> exam;
    s.setGrades(sExam, p, exam);
    return s;
}

void showAboveAverageStudents(vector <Student> v){
    int average;
    for (int i = 0; i < v.size(); i++){
        average += v[i].getFinalGrade();
    }
    average = average/v.size();
    for (int i = 0; i < v.size(); i++){
        if (v[i].getFinalGrade() > average){
            cout << v[i].getName() << endl;
        }
    }

}

int main(){
    Student s2("1234", "nome"), s1;
    s1 = readStudentData();
    s2.setGrades(14, 16, 12.3);
    cout << s1.getFinalGrade() << " - " << s1.isApproved() << " ||||| " << s2.getFinalGrade() << " - " << s2.isApproved() << endl;
    vector <Student> v = {s1, s2};
    showAboveAverageStudents({s1, s2});
   


    return 0;
}