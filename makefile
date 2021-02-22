lab2: main.o linkedList.o student.o hashTable.o
	g++ main.o linkedList.o student.o hashTable.o -o lab2

main.o: main.cpp linkedList.h student.h hashTable.h
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

linkedList.o: linkedList.cpp linkedList.h student.h
	g++ -c linkedList.cpp

hashTable.o: hashTable.cpp hashTable.h linkedList.h
	g++ -c hashTable.cpp

clean:
	rm -f lab2 *.o
