#include <iostream>
#include <string>
#include <memory>

class pt{
private:
  int x,y;
public:
  pt() {
    this->x = 0;
    this->y = 0;
  }
  
  pt(int x, int y){
    this->x = x;
    this->y = y;
  }
  ~pt() {
    std::cout << "In the destructor for " << this->toString() << "\n";

  }

  std::string toString(){
    return "<" + std::to_string(x) + ","+std::to_string(y)+">";
  }
  
};

std::shared_ptr<pt> f(){
  pt mypoint(10,20);

  //  pt *p = new pt(1,2);
  std::shared_ptr<pt> p(new pt(100,200));
  
  std::cout << p->toString() << "\n";
  std::cout << mypoint.toString() << "\n";

  auto p2 = std::make_shared<pt>(20,30);
  auto p3 = std::make_shared<pt>();

  std::cout << p2->toString() << "\n";
  std::cout << p3->toString() << "\n";
  
  //  delete p;
  std::cout<< "About to return from f\n";
  return p;
}
int main()
{
  std::shared_ptr<pt> p;
  p = f();
  std::cout<< "returned from  f\n";

  return 0;
}
