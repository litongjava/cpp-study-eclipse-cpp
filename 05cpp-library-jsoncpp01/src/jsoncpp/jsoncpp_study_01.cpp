/*
 * jsoncpp_study_01.cpp
 *
 *  Created on: 2019��8��21��
 *      Author: litong
 */
#include <iostream>
#include <string>
#include <string.h>
#include <json/json.h>
#include "jsoncpp-study.h"
using namespace std;
using namespace Json;
void testReaderParse() {
  const char* jsonString = "{\"name\": \"litong\",\"age\": 20,}";
  Reader reader;
  Value root;
  reader.parse(jsonString, root); // reader��Json�ַ���������root��root������Json��������Ԫ��
  string name = root["name"].asString();  // ���ʽڵ㣬upload_id = "UP000000"
  int age = root["age"].asInt();    // ���ʽڵ㣬code = 100
  cout << root << endl;
  cout << "name:" << name << endl;
  cout << "age:" << age << endl;
}
//����ṹ��
struct Student {
  char ID[20];
  char name[10];
  int age;
  int gender;
  char major[10];
};
string serializeToJson(const Student& student);
Student deserializeToObj(const string& strJson);

void testWrite() {
  Student student;
  strcpy(student.ID, "312822199204085698");
  strcpy(student.name, "dablelv");
  student.age = 18;
  student.gender = 0;
  strcpy(student.major, "math");

  string strJson = serializeToJson(student);
  cout << "strJson:" << strJson << endl;

  string strJsonNew =
      "{\"ID\":\"201421031059\",\"name\":\"lvlv\",\"age\":18,\"gender\":0}";
  Student resStudent = deserializeToObj(strJsonNew);
  cout << "resStudent:" << endl;
  cout << "ID:" << resStudent.ID << endl;
  cout << "name:" << resStudent.name << endl;
  cout << "age:" << resStudent.age << endl;
  cout << "gender:" << resStudent.gender << endl;
  cout << "major:" << resStudent.major << endl;
}
/**
 * ��������ѧ���������л�Ϊjson�ַ���
 */
string serializeToJson(const Student& student) {
}
/**
 * ��������json�ַ��������л�Ϊѧ������
 */
Student deserializeToObj(const string& strJson) {
  Json::Reader reader;
  Json::Value value;
  Student student;
  memset(&student, 0, sizeof(Student));

  if (reader.parse(strJson, value)) {
    strcpy(student.ID, value["ID"].asString().c_str());
    strcpy(student.name, value["name"].asString().c_str());
    student.age = value["age"].asInt();
    student.gender = value["gender"].asInt();
    strcpy(student.major, value["major"].asString().c_str());
  }
  return student;
}
