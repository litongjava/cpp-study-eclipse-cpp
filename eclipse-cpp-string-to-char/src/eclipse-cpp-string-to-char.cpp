//============================================================================
// Name        : eclipse-cpp-string-to-char.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;

int main() {
  string str;
  str = "world";

  char y[20];
  //Ŀ��,����,��ʼλ��
  str.copy(y, 5, 0);
  //�ƶ�ָ��,�����ý�����
  *(y + 5) = '\0';

  cout << "strǰ5��Ԫ�ص�ֵֵΪ��" << y << endl;

  return 0;
}

/**
 * ʹ��data()������stringתΪchar*
 */
//#include<iostream>
//#include<string>
//using namespace std;
//int main() {
//  string str;
//  str = "hello world";
//  //����һ������Ϊconst char *��ʽ,char * p = (char*)str.data()
//  const char *y = str.data();
//
//  cout << "str��ֵΪ��" << y << endl;
//
//  return 0;
//}
/**
 * ʹ��c_str()����,��stringתΪchar*
 */
//#include<iostream>
//#include<string>
//using namespace std;
//int main() {
//  string str;
//  str = "hello world";
//
//  //����һ������Ϊconst char *��ʽ��char * p = (char*)str.data()
//  const char *y = str.c_str();
//  cout << "str��ֵΪ��" << y << endl;
//
//  return 0;
//}
/**
 * char[],char* תString
 */
//#include <iostream>
//#include <string>
//
//using namespace std;
//int main() {
//  string str;
//  char x[] = "hello";
//  char *y = "Hello";
//  str = x;
//  cout << "x��ֵΪ��" << str << endl;
//  str = y;
//  cout << "y��ֵΪ��" << str << endl;
//  return 0;
//}
