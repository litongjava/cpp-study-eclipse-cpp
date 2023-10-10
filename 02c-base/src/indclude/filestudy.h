/*
 * filestudy.h
 *
 *  Created on: 2019��10��17��
 *      Author: Administrator
 */

#ifndef INDCLUDE_FILESTUDY_H_
#define INDCLUDE_FILESTUDY_H_

#include <stdio.h>

int study001() {
  FILE *fp = NULL;
  //���ļ�
  fp = fopen("tmp/test.txt", "w+");
  if (fp == NULL) {
    printf("���ļ�ʧ��:\n");
    return 1;
  }
  int status = fputs("This is testing for fprintf...\n", fp);
  printf("д���ļ����:%d\n" + status);
  status = fprintf(fp, "This is testing for fputs...\n");
  printf("д���ļ����:%d\n", status);
  //�ر��ļ�
  status = fclose(fp);
  if (status != 0) {
    printf("�ر��ļ�ʧ��\n");
  }
  return 0;
}

int study002() {
  FILE *fp = NULL;
  char buf[255];
  fp = fopen("tmp/test.txt", "r");
  fscanf(fp, "%s", buf);
  printf("1 %s\n", buf);
  fgets(buf, 255, (FILE*) fp);
  printf("2 %s\n", buf);
  fgets(buf, 255, (FILE*) fp);
  printf("3 %s\n", buf);
  fclose(fp);
  return 0;
}
#endif /* INDCLUDE_FILESTUDY_H_ */
