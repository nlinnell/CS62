#include <iostream>
#include <string>

using namespace std;

class Person{
  private: 
    string name;

  public:
    Person() {
      name = "";
      cout << "New Person" << endl;
    }
    Person(string n) {
      name = n;
      cout << "New Person: " << n<< endl;
    }
    void foo () {
      cout << "Person foo" << endl;
    }
    void bar () {
      cout << "Person bar" << endl;
    }
    string toString(){
      return name;
    }
};
class Employee: public Person{
  private:
    int id;
  public:
    Employee(){ 
      cout << "New Employee" << endl;
    }
    Employee(string n, int i) : Person(n){ 
      //name = n;//Can't access private members of parent
      id = i;
      cout << "New Employee " << n << endl;
    }
    void foo () {
      cout << "Employee foo" << endl;
    }
    void pay () {
      cout << "Employee pay" << endl;
    }
    string toString(){
      string s = Person::toString()+" "+to_string(id);
      return s;
    }

};


int main(){
  Person p0;
  Employee e0; 


  Person p1("Alice in Wonderland");
  Employee e1("Spongebob Squarepants",1994825);

  p0.foo();
  e0.foo();

  p0.bar();
  e0.bar(); // we can still call this

  //p0.pay();
  e0.pay();

  cout << p1.toString() << endl;
  cout << e1.toString() << endl;
  cout << e1.Person::toString()<<endl;




/*
  
  // which one compiles?
  p0 = e0;
  e0 = p0;
  */
}
