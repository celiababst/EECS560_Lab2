#include "hashTable.h"
#include "linkedList.h"
#include <string>

using namespace std;

hashTable::hashTable(int size)
{
  table = new linkedList[size];
  m_size = size;
}

hashTable::~hashTable()
{

}

void hashTable::insert(student newStudent)
{
  int hashNum;
  hashNum = hashFunc(newStudent.getName(), m_size);
  bool found = findStudent(newStudent.getName());
  if(found)
  {
    cout<<"That student is already in the hash table!\n";
  }
  else
  {
    table[hashNum].insert(newStudent); //this is calling the insert function of linkedList
  }
}

void hashTable::deletion(string givenName, int givenId)
{
  int hashNum;
  hashNum = hashFunc(givenName, m_size);
  table[hashNum].deletion(givenName, givenId); //this is calling the deletion function of linkedList
}

int hashTable::hashFunc(string name, int size)
{
  int totalAsciiVal = 0;
  for(int i=0; i<name.length(); i++)
  {
    totalAsciiVal = totalAsciiVal + int(name[i]);
  }
  int index	=	totalAsciiVal % size;
  return index;
}

void hashTable::printTable()
{
  student* temp;
  for(int i=0;i<m_size;i++)
  {
    cout<<i<<": ";
    temp = table[i].head;
    if(temp==nullptr)
    {
      cout<<"\n";
    }
    else
    {
      cout<<temp->getId()<<" "<<temp->getName();
      while(temp->hasNext())
      {
        temp = temp->getNext();
        cout<<" -> "<<temp->getId()<<" "<<temp->getName();
      }
      cout<<"\n";
    }
  }
}

bool hashTable::findStudent(string givenName)
{
  int bucketNum = hashFunc(givenName, m_size);
  bool found = table[bucketNum].find(givenName);
  return found;
}
