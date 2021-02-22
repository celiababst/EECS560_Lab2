#include "linkedList.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

linkedList::linkedList()
{
  head = nullptr;
}

linkedList::~linkedList()
{
  student* temp = head;
  while(temp!=nullptr)
  {
    student* next = temp->getNext();
    delete temp;
    temp = next;
  }
  head = nullptr;
}

bool linkedList::isEmpty()
{
  if(head==nullptr)
  {
    return true;
  }
  return false;
}

int linkedList::length()
{
  if(head==nullptr)
  {
    return 0;
  }
  student* temp = head;
  int count = 1;
  while((temp->getNext())!=nullptr)
  {
    temp = temp->getNext();
    count++;
  }
  return count;
}

void linkedList::insert(student newStudent)
{
  student* studentPtr = new student(newStudent.getName(), newStudent.getId());

  if(head==nullptr)
  {
    head=studentPtr;
    head->setNext(nullptr);
  }
  else
  {
    student* temp = head;
    while(temp->getNext()!=nullptr)
    {
      temp = temp->getNext();
    }
    temp->setNext(studentPtr);
  }
  //delete studentPtr;
}


void linkedList::deletion(string givenName, int givenId)
{
  if(isEmpty())
  {
    cout<<"List is empty.\n";
    return;
  }

  if(find(givenName)==false)
  {
    cout<<"Student could not be found in the list.\n";
    return;
  }

  student* temp = head;
  while(temp!=nullptr)
  {
  if(temp->getName()==givenName)
  {
    if(temp->getId()==givenId)
    {
      if(temp==head)
      {
        head = temp->getNext();
      }
      temp->setNext(nullptr);
      cout<<givenName + " has been deleted from the list.\n";
      delete temp;
      return;
    //NOW HOW DO I DELETE THE student THAT'S FLOATING IN SPACE?
    }
    else
    {
      "Id didn't match student name; no record deleted.\n";
    }
  }
  temp = temp->getNext();
  }
}



bool linkedList::find(string givenName)
{
  if(isEmpty()) return false;
  student* temp = head;
  if(temp->getName()==givenName) return true;
  while(temp->getNext()!=NULL)
  {
    temp = temp->getNext();
    if(temp->getName()==givenName) return true;
  }
  return false;
}
