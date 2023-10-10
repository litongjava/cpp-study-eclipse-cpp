#include <iostream>
#include <oop.h>
using namespace std;
class Rectangle {
public:
  int breadth;
  int height;
  int getBreadth();
  int getPtr();
  Rectangle(int b);
  Rectangle(const Rectangle &obj);
  ~Rectangle();
private:
  int *ptr;
};
int Rectangle::getBreadth() {
  return breadth;
}

int Rectangle::getPtr() {
  return *ptr;
}
Rectangle::Rectangle(int a) { // @suppress("Class members should be properly initialized")
  cout << "���ù��캯��,Ϊָ������ڴ�" << endl;
  ptr = new int;
  *ptr = a;
}
Rectangle::Rectangle(const Rectangle &obj) { // @suppress("Class members should be properly initialized")
  cout << "����copy���캯��Ϊָ������ڴ�" << endl;
  ptr = new int;
  *ptr = *obj.ptr;
}
Rectangle::~Rectangle() {
  cout << "������������" << endl;
  delete ptr;
}
void testCopyConstructor() {
  Rectangle rec1(10);
  Rectangle rec2(rec1);
  cout << rec1.getPtr() << endl;
  cout << rec2.getPtr() << endl;
}
