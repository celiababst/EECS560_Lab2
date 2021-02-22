#include "student.h"
#include <string>
#include <iostream>

using namespace std;

student::student(string name, int id)
{
  m_name = name;
  m_id = id;
  next = nullptr;
}

student::~student()
{

}

string student::getName()
{
  return m_name;
}

int student::getId()
{
  return m_id;
}

bool student::hasNext()
{
  if(next==nullptr)
  {
    return false;
  }
  return true;
}

student* student::getNext()
{
  return next;
}

void student::setNext(student* newStudent)
{
  /*
  if(newStudent == NULL)
  {
    next = NULL;
  }
  */
  next=newStudent;
}
