#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Employee{
    string name;
    double salary;

    public:
    int id;

    //declaring constructor

    Employee(string n,int id,double s) : name(n),id(id),salary(s){
        //constructor body
        cout<<"A new employee is created"<<endl;
    }
    double getSalary(){
        return salary;
    }
    void display(){
        cout<<"name:"<<name<<" id:"<<id<<" salary:"<<salary<<endl;
    }
    void Increment(double percentage){
        salary+= salary * percentage/100;
    }

};

void Print(vector<Employee> employees){ //here employees-> the name of parameter
       //for-each loop
    //    for(Employee e: employees)
    //    e.display();

    //using index
    for(int i = 0; i < employees.size(); i++){
         employees[i].display();
    }
}

bool CompareID(Employee e1, Employee e2){
    return e1.id < e2.id; //ascending order
}
bool CompareSalary(Employee e1, Employee e2){
     return e1.getSalary() > e2.getSalary();
}
int main(){
    //creating vector
    vector<Employee> emp = {Employee("Rahim",2,8000), Employee("Karim",1,15000)};

    //another method for creating vector
     Employee e1("Abir",4,9000);
     emp.push_back(e1);
     //another method
     emp.push_back(Employee("Roni",3,18000));
     cout<<"Printing employees:"<<endl;
     Print(emp);

     //change the id of the employee at index 2
     emp[2].id = 6;
     cout<<"after updating the id:"<<endl;
     emp[2].display();
      
     //salary checking
     cout<<"Employees with the salary >= 10000: "<<endl;
     for(Employee e:emp){
        if(e.getSalary() >= 10000){
            e.display();
        }
     }

     //salary increasing
     for(Employee &e: emp){
        if(e.getSalary()>=15000){
            e.Increment(15);
        }
        else{
            e.Increment(10);
        }
     }

    cout<<"\nAfter increment: "<<endl;
    Print(emp);

    //sorting id (ascending)
    sort(emp.begin(), emp.end(), CompareID);
    cout<<"After sorting in ascending order of id:"<<endl;
    Print(emp);

    //sorting salary (decsending)
    sort(emp.begin(),emp.end(), CompareSalary);
    cout<<"\nAfter sorting in desecending order of salary:"<<endl;
    Print(emp);
    //highest salary
    cout<<"employee with the highest salary:"<<endl;
    emp[0].display();
    //lowest salary
    cout<<"employee with the lowest salary:"<<endl;
    int n = emp.size();
    emp[n-1].display();
     




    return 0;
}