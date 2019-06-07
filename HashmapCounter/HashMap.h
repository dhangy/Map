#ifndef __HASHMAP__
#define __HASHMAP__

#include <string>
#include <cassert>
#include "Node.h"

using namespace std;

// external iterator to iterate over the HashMap
class Iterator
{
public:
	Iterator(int index, Node **hashArray, int sizeOfArray);
	Iterator();
	~Iterator() = default;

	// these next three functions are often found in an external iterator
	string operator*();
	void operator++();
	bool operator!=(Iterator& other);
	bool is_item();

private:
	int index;
	Node *current;
	Node **hashArray;
	int sizeOfArray;
};


// HashMap to store Key-Value pairs of "string"-int
class HashMap
{
public:
	HashMap(int size);	// size of array
	~HashMap();
	bool IsKeyPresent(string const &key) const;		// return true if key is in map
	void SetKeyValue(string const &key, int value);	// if key is not present, add to map and then set value
													// NOTE: GetKeyValue() returns a bool (true if the key was present in the map) and it ALSO "returns"
													// the value of that key through the parameter "value". Notice that "value" is a "pass by reference" parameter
	bool GetKeyValue(string const &key, int& value);// if key is not present, return false

	Iterator begin();
	Iterator end();

private:
	Node **hashArray;	// holds the array pointers for the chained array of Nodes
	int sizeOfArray;

	int GenerateHash(string key) const; // converts the key to an value used to index into the array
};

#endif
