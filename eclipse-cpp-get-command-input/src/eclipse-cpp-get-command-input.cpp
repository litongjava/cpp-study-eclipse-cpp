#include <stdio.h>

int main(int argc, char* argv[]) {
  //���argc
  printf("argc:%d \n", argc);
  //���argv
  for (int i = 0; i < argc; i++) {
    char* buf = argv[i];
    printf("%d:%s \n", i, buf);
  }
  return 0;
}
