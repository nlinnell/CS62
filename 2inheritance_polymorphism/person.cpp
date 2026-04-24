#include <iostream>
#include <string>

using namespace std;

class Person{
  private: 
    string name;//Can't access private fields of parent from child

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
class Employee: public Person{//Makes Employee inherit from Person
  private:
    int id;
  public:
    Employee(){ //If we don't explicitly call the parent constructor
      //from a child constructor the parent's default constructor is called
      cout << "New Employee" << endl;
    }
    Employee(string n, int i): Person(n){ //We call the parent's constructor to set parent private fields
      //name = n; Can't access private field of parent from child
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
  e0.bar(); // can we can still call this? Yes

  //p0.pay(); //Doesn't work
  e0.pay();

  cout << p1.toString() << endl;
  cout << e1.toString() << endl;




/*
  
  // which one compiles?
  p0 = e0;
  e0 = p0;
  */
}
