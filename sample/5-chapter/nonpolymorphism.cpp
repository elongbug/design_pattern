#include <iostream>
using namespace std;

class Base {
  public :
    void print() {
      cout << "I'm Base" << endl;
    }
};

class Derived : public Base {
  public :
    void print() {
      cout << "I'm Derived" << endl;
    }
};

int main()
{
  Base *pObj = new Derived;
  pObj->print();
}
