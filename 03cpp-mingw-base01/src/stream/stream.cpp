#include <iostream>
#include <fstream>
using namespace std;
int main_stream(int argc, char* argv[]) {
  char data[100];
  //��дģʽ���ļ�
  ofstream outfile;
  outfile.open("afile.data");
  //���������л�ȡ����
  cout << "input your name:" << endl;
  cin.getline(data, 100);
  //���ļ���д������
  outfile << data << endl;

  //�ٴλ�ȡ�û�����,���ļ���д������
  cout << "input your age" << endl;
  cin.getline(data, 100);
  outfile << data << endl;
  //�ر��ļ�
  outfile.close();

  //�Զ�ģʽ���ļ�
  ifstream infile;
  infile.open("afile.data");
  //��ȡ�ļ��е�����
  infile >> data;
  //�������
  cout << data << endl;
  //�ٴζ�ȡ�����
  infile >> data;
  cout << data << endl;
  //�ر��ļ�
  infile.close();
  return 0;
}
