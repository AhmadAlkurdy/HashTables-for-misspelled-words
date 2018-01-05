//header file for the class and declare the variables


#include <iostream>
#include <string>
#include <fstream>

using namespace std;


#ifndef hashDef_h
#define hashDef_h

class Hash
{
	//declare the linked list and the array for the hash table
private:
	static const int  tablesize = 10000;
	struct words
	{
		string word;
		words* next;

	};
	words* hashTable [tablesize];



//declare the function of the program
public:
	Hash();
	int hash( string key);
	void addWords ( string word);
	string compare (string word);
	void print ();
	int number ( int index);


};

#endif