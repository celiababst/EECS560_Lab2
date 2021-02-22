#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "student.h"
#include "linkedList.h"
#include <string>

using namespace std;

class hashTable
{
public:
  hashTable(int size);
  ~hashTable();
  int hashFunc(string name, int size);
  void insert(student newStudent);
  void deletion(string givenName, int givenId);
  void printTable();
  bool findStudent(string givenName);



private:
  int m_size;
  linkedList* table;

};
#endif
