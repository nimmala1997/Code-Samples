#include<iostream>
#include<string>
using namespace std;


class Student
{

 protected:
string Name;
string Branch;

public:
int CPI;
void setname(string name){
   Name = name;
}
void getname(){
   cout<<Name;
}
/*Student(string name,string branch,int cpi)
 {
    Name = name;
    Branch = branch;
    CPI = cpi;
 }
*/
void Introduceyourself()
 {
 cout<<"Hello"<<" "<<Name<<" "<<Branch<<CPI<<endl;
 }
void CompulCourse()
   {
    if(CPI < 7){
        cout<<Name<<" "<<"You should improve your CPI"<<endl;
    }
  }
};
class Courses:public Student
{
  public:
  string allcourses;
  /*Courses(string name,string branch,int cpi,string Allcourses):Student(name,branch,cpi){
     allcourses = Allcourses;
  }*/
};

int main(){
/*Student student1 = Student("Pavan","PE",7);
Student student2 = Student("Dev","PE",9);
student1.Introduceyourself() ;
student2.Introduceyourself() ;
student1.CompulCourse();*/
//Courses power = Courses("Abhijeet","ps",10,"twocourse");
//power.Introduceyourself();
//power.CPI = 11;
//power.Introduceyourself();
Courses power;
power.setname("Pavan");
power.getname();
return 0;
}