#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class student
{
private:
  string m_name;
  int m_id;
  student* next;

public:
  student(string name, int id);
  ~student();
  string getName();
  int getId();
  bool hasNext();
  student* getNext();
  void setNext(student*);

};
#endif
