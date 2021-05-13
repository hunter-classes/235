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
    this->x =x;
    this->y = y;
  }
  ~pt() {
    std::cout << "In the pt destructor for " << this->toString() << "\n";
  }

  std::string toString(){
    return "<" + std::to_string(x) + "," + std::to_string(y) + ">";
  }
};


void f(){
   
  // pt *p  = new pt(1,2);
  std::shared_ptr<pt> p(new pt(100,200));
  std::cout << p->toString() <<   "\n";

  // another notation that I find a bit cleaner

  auto p2 = std::make_shared<pt>(20,30);

  auto p3 = std::make_shared<pt>();
  
  std::cout << p2->toString() <<   "\n";
  std::cout << p3->toString() <<   "\n";

  
  // we have to free the memory that we allocated to
  // p before we return to avoid a memory leak
  //  delete p;
  // since p is now a managed pointer (std::shared_ptr)
  // we don't have to delete it
}


int main()
{
  f();

  return 0;
}
