#include <iostream>
#include <ctime>
using namespace std;
int main_date(int argc,char* argv[]){
  //���ڵ�ǰϵͳ������ʱ��,����ʱ���
  time_t now=time(0);
  cout << "now:"<<now<<endl;
  //��nowתΪ�ַ�����ʽ
  char* dt=ctime(&now);
  cout <<"dt:"<<dt<<endl;
  //��nowתΪtm�ṹ
  tm* gmtm=gmtime(&now);
  cout <<"gmtm:"<<gmtm<<endl;
  //תΪutcʱ��
  dt=asctime(gmtm);
  cout <<"utcʱ��:"<<dt<<endl;
  return 0;
}
