/*
 * study_str.h
 *
 *  Created on: 2019��10��18��
 *      Author: Administrator
 */

#ifndef INDCLUDE_STUDY_STR_H_
#define INDCLUDE_STUDY_STR_H_

#include <stdio.h>

void study_len() {
  char s[] = "\\1234";
  int len = strlen(s);
  int size = sizeof(s);
  printf("%d,%d", len, size);
}

void study_strcat() {
  char src[50], dest[50];
  strcpy(src, "this is source");
  strcpy(dest, "this is dest");
  strcat(dest, src);
  printf("���յ��ַ�����:%s", dest);
}

#endif /* INDCLUDE_STUDY_STR_H_ */
