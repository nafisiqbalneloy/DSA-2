// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// using namespace std;

// class Student{
//     string name;
//     string department;

//     public:
//     int id;

//     Student(string name,string department,int id) : name(name),department(department),id(id){
//         cout<<"creating student"<<endl;
//     }

//     string getDepartment(){
//         return department;
//     }

//     void display(){
//         cout<<"name: "<<name<<" department : "<<department<<" id : "<<id<<endl;
//     }

// };

// void Printstudents(vector<Student>students){
//     for(Student s : students){
//         s.display();
//     }

// }

// int main(){
//     vector<Student> stud={
//        Student{"Rahim", "CSE", 101},
//        Student{"Karim", "EEE", 102},
//        Student{"Lima", "CSE", 103},
//        Student{"Sadia", "BBA", 104},
//        Student{"Rafi", "EEE", 105},
//        Student{"Tuli", "CSE", 106}
//     };
    
//     cout<<"\nAll students: "<<endl;
//     Printstudents(stud);

//     // map for department frequency
//     map<string, int> deptCount;

//     for(Student s : stud) {
//         string dept = s.getDepartment();
//         deptCount[dept]++;
//     }

//     cout << "\nDepartment-wise student count:\n";
//     for(auto entry : deptCount) {
//         cout << entry.first << " --> " << entry.second << endl;

//     return 0;
// }
// }

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Student{
    string name;
    string department;

    public:
    int id;

    Student(string name,string department,int id) : name(name),department(department),id(id){
        cout<<"creating student"<<endl;
    }

    string getDepartment(){
        return department;
    }

    void display(){
        cout<<"name: "<<name<<" department : "<<department<<" id : "<<id<<endl;
    }

};

void Printstudents(vector<Student>students){
    for(Student s : students){
        s.display();
    }
}

int main(){
    vector<Student> stud={
       Student{"Rahim", "CSE", 101},
       Student{"Karim", "EEE", 102},
       Student{"Lima", "CSE", 103},
       Student{"Sadia", "BBA", 104},
       Student{"Rafi", "EEE", 105},
       Student{"Tuli", "CSE", 106}
    };
    
    cout<<"\nAll students: "<<endl;
    Printstudents(stud);
    
    // map for department frequency
    map<string, int> deptCount;

    for(Student s : stud) {
        string dept = s.getDepartment();
        deptCount[dept]++;
    }

    cout << "\nDepartment-wise student count:\n";
    for(auto entry : deptCount) {
        cout << entry.first << " --> " << entry.second << endl;
    }

    return 0;
}
