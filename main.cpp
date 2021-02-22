#include "student.h"
#include "linkedList.h"
#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

ifstream infile;
string fileName = "data.txt";
infile.open(fileName);

hashTable hashTable(11);

if(infile.is_open())
{
int id;
string name;
while(infile >> id >> name)
{
student newStudent(name, id);
hashTable.insert(newStudent);
}
}
else
{
cout<<"File could not be opened!\n";
}

cout<<"Choose one operation from the options below:\n";
cout<<"1. Add Student\n";
cout<<"2. Remove Student\n";
cout<<"3. Print Student List\n";
cout<<"4. Find Student\n";
cout<<"5. Exit\n";

int choice;
cin>>choice;

if(choice==1)
{
  int givenId;
  string givenName;

  cout<<"Enter the id to be inserted:\n";
  cin>>givenId;
  cout<<"Enter the name to be inserted:\n";
  cin>>givenName;

  student insertedStudent(givenName, givenId);
  hashTable.insert(insertedStudent);
  cout<<"Record inserted successfully!\n";
}

else if(choice==2)
{
  int givenId;
  string givenName;

  cout<<"Enter the id to be deleted:\n";
  cin>>givenId;
  cout<<"Enter the name to be deleted:\n";
  cin>>givenName;

  hashTable.deletion(givenName, givenId);

  hashTable.printTable();
}

else if(choice==3)
{
  cout<<"\n";
  hashTable.printTable();
}

else if(choice==4)
{
  string givenName;

  cout<<"Enter the name to be searched for:\n";
  cin>>givenName;
  bool found = hashTable.findStudent(givenName);
  if(found)
  {
    int index = hashTable.hashFunc(givenName, 11);
    cout<<"Student was found at index "<<index<<"\n";
  }
  else
  {
    cout<<"Student was not found.\n";
  }
}

else if(choice==5)
{
  return 0;
}

else
{
  cout<<"That was not in the list of options!\n";
}

}
