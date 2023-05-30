#include<iostream>
#include<cstring>

using namespace std;

class Student{
    int age;
    char *name;

    public:
    Student(int age,char *name){
        this->age = age;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    void Display(){
        cout<<"Age is "<<age<<" Name is "<<name;
    }
};

int main(){
    char c[] = "Pavan";
    Student s1 = Student(23,c);
    c[4] = 'K';
    Student s2 = Student(23,c);
    s1.Display();
    cout<<endl;
    s2.Display();
    cout<<endl;
    s1.Display();

return 0;
}