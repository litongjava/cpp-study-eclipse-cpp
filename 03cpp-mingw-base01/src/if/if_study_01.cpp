/*
 * if_study_01.cpp
 *
 *  Created on: 2019��8��23��
 *      Author: Administrator
 */
#include <iostream>
#include "if.h"
using namespace std;

static struct {
  int auto_reload;
} global;
void testif1() {
  if (global.auto_reload) {
    cout << "ִ��" << endl;
  } else {
    cout << "û��ִ��" << endl;
  }
}
