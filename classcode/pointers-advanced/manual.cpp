#include <iostream>
#include <string>


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
  pt mypoint(10,20);
  
  pt *p  = new pt(1,2);
  std::cout << p->toString() <<   "\n";

  std::cout << mypoint.toString() <<   "\n";

  // we have to free the memory that we allocated to
  // p before we return to avoid a memory leak
  delete p;
}


int main()
{
  f();

  return 0;
}
