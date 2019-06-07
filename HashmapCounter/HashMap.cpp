#include "stdafx.h"
#include "HashMap.h"
#include <iostream>

using namespace std;

HashMap::HashMap(int size)
{
	hashArray = new Node*[size];
	for (int i = 0; i < size; i++) {
		hashArray[i] = nullptr;
	}
	sizeOfArray = size;

}


HashMap::~HashMap()
{
	for (int i = 0; i < sizeOfArray; i++) {
		if (hashArray[i] != nullptr){
			delete hashArray[i];
		}
	}
}

bool HashMap::IsKeyPresent(string const &key) const {
	//check to see if the key is in the map
	int index = GenerateHash(key);
	if(hashArray[index] == nullptr) {
		return false;
	}
	else if (hashArray[index]->key == key) {
		return true;
	}
	else {
		Node * n;
		n = hashArray[index];
		while (n->key != key) {
			if (n == nullptr) {
				return false;
			}
			if (n->next == nullptr) {
				return false;
			}
			n = n->next;
		}
		return true;
	}
}


void HashMap::SetKeyValue(string const &key, int value) {
	int index = GenerateHash(key);
	Node * n;
	Node * temp;
	n = hashArray[index];
	if (IsKeyPresent(key)) {
		while (n->key != key) {
			n = n->next;
		}
		if (value == -1) {
			n->value = value;
		}
	//	else {
			n->value += 1;
		//}
			//increment if the key is present
	}
	else {
		if (n == nullptr) {
			temp = new Node(key, value);
			temp->next = nullptr;
			hashArray[index] = temp;
		}
		else { 
			temp = new Node(key, value);
			temp->next = n;
			hashArray[index] = temp;
		}
	}
}

bool HashMap::GetKeyValue(string const &key, int& value) {
	if (IsKeyPresent(key)) {
		int index = GenerateHash(key);
		Node * n;
		n = hashArray[index];
		while (n->key != key) {
			n = n->next;
		}
		value = n->value;
		return true;
	}
	else {
		return false;
	}
}
//also no idea
Iterator HashMap::begin() {
	for (int i = 0; i < sizeOfArray; i++) {
		if (hashArray[i] != nullptr) {
			return Iterator(i, hashArray, sizeOfArray);
		}
	}
}
//probably bad
Iterator HashMap::end() {
	Node * temp = nullptr;
	int c = 0;
	for (int i = 0; i < 500; i++) {
		if (hashArray[i] != nullptr) {
			temp = hashArray[i];
			c = i;
			//temp = temp1;
		}
	}
	if (temp == nullptr) {
		int end = 0;
		return Iterator(end, hashArray, sizeOfArray);
	}
	while (temp != nullptr && temp->next != nullptr) {
		temp = temp->next;
		return Iterator(c, hashArray, sizeOfArray);
	}


}
//takes the string word and converts it into a key int
int HashMap::GenerateHash(string key) const {
	int newKey = 0;
	for(int i = 0; i < key.length(); i++){
		newKey += key[i];
	}
	newKey = newKey * 3; 
	while (newKey > 499) {
		newKey = (newKey % sizeOfArray);
	}
	return newKey;
}