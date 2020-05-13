#include <iostream>

class pt{
private:
  int x,y;
public:
  pt(){
    this->x = 0;
    this->y = 0;
  }
  pt(int x, int y){
    this->x = x;
    this->y = y;
  }
  ~pt(){
    std::cout << "In the pt destructor\n";
  }
  std::string toString(){
    return "<"+std::to_string(x)+","+std::to_string(y)+">";
  }
};

void f(){
  pt *p = new pt();
  std::cout << p->toString() << "\n";
  pt *p2 = new pt(5,10);
  std::cout << p2->toString() << "\n";
  delete p;
  delete p2;
}

int main()
{
  std::cout << "Beginning\n";
  f();
  std::cout << "End\n";
  
  return 0;
}
