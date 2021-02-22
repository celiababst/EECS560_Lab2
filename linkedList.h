#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "student.h"

class linkedList {
public:
  linkedList();
  ~linkedList();
  bool isEmpty();
  int length();
  void insert(student newStudent);
  void deletion(string givenName, int givenId);
  bool find(string givenName);

student* head;

private:

};

#endif
