/*
 * main.c
 *
 *  Created on: 2019��7��28��
 *      Author: Administrator
 */
int count;
extern void writeExtern();
int main_extern(int argc,char* argv[]){
  count=5;
  writeExtern();
  return 0;
}
