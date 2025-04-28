#include <iostream>
#include <vector>
using namespace std;

class Animal{
  public:
  Animal() {
    cout<<"New Animal"<<endl;
  }
  void sleep(){
    cout<<"Animal sleep"<<endl;
  }
  void eat(){
    cout<<"Animal eat"<<endl;
  }
};
class Bird: public Animal{
  public:
  Bird(){
    cout<<"New Bird!"<<endl;
  }
  void sleep(){
    cout<<"Bird sleeps"<<endl;
  }
};
class Cat: public Animal{
  public:
  Cat(){
    cout<<"New Cat!"<<endl;
  }
  void sleep(){
    Animal::sleep();//Call Animal's sleep method
    cout<<"Cat sleeps"<<endl;
  }
  void meow(){
    cout<<"Meow"<<endl;
  }
};
int main(){
  /*
  Animal a;
  Bird b;
  Cat c;

  a.eat();
  b.eat();
  c.eat();

  a.sleep();
  b.sleep();
  c.sleep();

  //a.meow();
  //b.meow();
  c.meow();
*/






  Animal a1, a2;
  Bird b1, b2;
  a1=b1; 
  //b2=a2; 

  Animal a; Bird b; Cat c;

  vector<Animal> animals;
  animals.push_back(a);
  animals.push_back(b);//animals.push_back((Animal)b);
  animals.push_back(c);

  for (auto x : animals) {//x has type Animal
    x.sleep();
  }
}
