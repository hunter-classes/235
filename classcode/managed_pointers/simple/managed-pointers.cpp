#include <iostream>
#include <memory>

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
  // 1. make a new pt
  // 2. embed it into a new shared_ptr to a pt
  // std::shared_ptr<pt> p(new pt(100,200));
  // std::cout << p->toString() << "\n";
  
  auto p = std::make_shared<pt>(50,78);
  std::cout << p->toString() << "\n";
  auto p2 = std::make_shared<pt>();
  std::cout << p2->toString() << "\n";
}

int main()
{
  std::cout << "Beginning\n";
  f();
  std::cout << "End\n";
  
  return 0;
}
