/*
 * main.c
 *
 *  Created on: 2019��11��11��
 *      Author: litong
 */

#include <arpa/inet.h>
#include <cygwin/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  struct in_addr addr1;
  ulong l1 = inet_addr("192.168.0.74");
  //��ֵ���������ݵ�ַ
  memcpy(&addr1, &l1, 4);
  //ת�ɳɵ��ʮ�������
  printf("%s\n", inet_ntoa(addr1));
  return 0;
}
