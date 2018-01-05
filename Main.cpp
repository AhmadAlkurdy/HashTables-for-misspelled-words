///Ahmad Alkurdy
// 7/17/2016
// Hash Tables program
//hash program that will find all the misspelled words in an input file called "check.txt" 




#include <iostream>
#include <string>
#include <fstream>
#include "hashDef.h"


using namespace std;



//the program will be called from the command line
int main(int argc, char* argv[])
{
	Hash object;	
	ifstream input1;
	ifstream input2;
	string word1;
	string word2;
	string misp;
	int tableSize = 0;
	//if the argument does not conatain 3 parts then the program would give error
	if(argc != 3)
	{
		cout << "Error, insert programName File1 File2 " << endl;
	}

	else
	{


	input1.open(argv[1]);


//	while (input1.good())
	//{
		//input1 >> word1;
		//tableSize++;
	//} to count how many words in the dictionary
	

	//read the first file and apply the hash function and add item to the hash table
	while (input1.good())
	{
		input1 >> word1;
		object.addWords(word1);
	}
	//object.print();this print function just to make sure that the words are in the hash tables and 
	// to count how many words to compare to the words in the folder
	input2.open(argv[2]);
	

	//read the second file to check the mispelled words
	while(input2.good())
	{
		input2 >> word2;
		misp = object.compare(word2);
		if(misp != " ")
		{
		cout << "Misspelled word: "<< misp << endl;
		}
		
	}

	}
	input1.close();
	input2.close();
	system("pause");
	return 0;

}