#include <stdio.h>

/**
 * ʵ�ֺ�Ĳ�������
 */
#define call(NAME) say##NAME();
void sayHI() {
  printf("hi\n");
}
void sayHELLO() {
  printf("hello\n");
}
int main_macro(void) {
  call(HI);
  call(HELLO);
  return 0;
}
