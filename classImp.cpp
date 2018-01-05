//the class implemntaion cpp file


#include <iostream>
#include <string>
#include <fstream>



#include "hashDef.h"




//constructor function
Hash::Hash()
{
	for(int i = 0; i < tablesize; i++)
	{
		hashTable [i] = new words;
		hashTable [i] -> word = "EMPTY";
		hashTable [i] -> next = NULL;
	}
}


//hash function will add up the ASCI numbers of each letter in the word and 
// divide the number by the table number and give us the reminder to use as the nmber of the
// index
//the best way for hash function is to multiply by 37 the lenegth.
int Hash:: hash( string key)
{
	int indexNum = 0;
	int hash = 0;

	for(int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key [i];

	}
	indexNum = hash% tablesize;

	return indexNum;
}

//function would call the hash function to get the number of the index and then insert the word
//in the word in the index number of the array(hash table) and if 
// two words have the same index it will use linked list to add 
void Hash::addWords (string word)
{
	int index = hash(word);

	if(hashTable[index] -> word == "EMPTY")
	{
		hashTable[index] -> word = word;
	}
	else
	{
		words* temp = hashTable [index];
		words* curr = new words;
		curr -> word = word;
		curr -> next = NULL;

		while ( temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = curr;


	}

}

//function will call the hash function and get the index number and then check if there is
//the same word in the linked list or the index itself and if not then it is mispelled word
string Hash :: compare (string word)
{
	int index = hash(word);
	words* n = hashTable [index];


	if(n ->word == "EMPTY")
	{
		return word;

	}
	else
	{
		while (n!= NULL)
		{
			if( n ->  word == word)
			{
				return " ";
			}
			else
			{
				n = n->next;
			}
			
		}
		
	}
	return word;

}
//helper function to check if the hash table of the dictionary is right
void Hash::print()
{
	int number1= 0;
	int number2 = 0;
	for(int i = 0; i < tablesize; i++)
	{
		number1 = number(i);
		cout << hashTable [i] -> word << " " << number1 << endl;
		number2 = number2 + number1;
	
		
	}
	cout << number2 << endl;
	
}
//this function will calculate the linked list number in every index
int Hash :: number (int index)
{
	int count = 0;

	if(hashTable[index] -> word == "EMPTY")
	{
		return count;
	}
	else 
	{
		count++;
		words* current = hashTable [index];
		while(current -> next != NULL)
		{
			count ++;
			current = current -> next;
		}
	}
	return count;
}
//i need deconstructor