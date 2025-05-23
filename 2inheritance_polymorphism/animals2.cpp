#include <iostream>
#include <vector>
using namespace std;

class Animal{
  private:
    string name;
  public:
  Animal() {
    name = "";
  }
  Animal(string n) {
    name = n;
  }
  void virtual sleep(){
    cout<<"Animal sleep" <<endl;
  }
  void eat(){
    cout<<"Animal eat"<<endl;
  }
};
class Bird: public Animal{
  public:
  Bird(){ }
  Bird(string n): Animal(n){ }
  void sleep(){
    cout<<"Bird sleep"<<endl;
  }
  void eat(){
    cout<<"Bird eat"<<endl;
  }
};
class Cat: public Animal{
  public:
  Cat(){}
  Cat(string n): Animal(n){}
  void sleep(){
    cout<<"Cat sleep"<<endl;
  }
  void meow(){
    cout<<"Meow!!"<<endl;
  }
};

int main(){
  Animal a;
  Bird b;
  Cat c;


  
/*
  vector<Animal> animals;
  animals.push_back(a);
  animals.push_back(b); 
  animals.push_back(c);
  for (auto x: animals) {//What type will auto be?
    x.sleep(); 
  }     
*/



  Animal* ap = new Animal();
  Bird* bp = new Bird();
  Cat* cp = new Cat();

  cout << "bp: " << bp << endl;
  Animal* bp2 = bp;
  cout << "(Animal*) bp: " << bp2 << endl; // same as bp

  vector<Animal*> vp;
  vp.push_back(ap);
  vp.push_back(bp);
  //equivalent: vp.push_back((Animal*)bp);
  vp.push_back(cp);
  for (Animal* x: vp) {
    x->sleep();
  }
  
}
