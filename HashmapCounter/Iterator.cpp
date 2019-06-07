#include "HashMap.h"

Iterator::Iterator(int index, Node **hashArray, int sizeOfArray)
{
	this->index = index;
	this->hashArray = hashArray;
	this->sizeOfArray = sizeOfArray;
	current = hashArray[index];

}

Iterator::Iterator() {

}

//it may need to return something different!!!!!!!!!!!!!!!!
string Iterator::operator*() {
	string junk = "junk!";
	if (current == nullptr) {
		return junk;
	}
	else {
		return current->key;
	}
}
void Iterator::operator++() {
	//if the index is null go to the first one that isnt
	while(current == nullptr){
		index++;
		current = hashArray[index];
		return;
	}
	//if the next element is null go to the next index that isnt
	while (current->next == nullptr) {
		index++;
		current = hashArray[index];
		return;
	}
	//else just go to the next linked node
	current = current->next;
}

bool Iterator::operator!=(Iterator& other) {
	return (current != other.current);
}

bool Iterator::is_item() {
	bool val = (current != nullptr);
		return val;
	}

