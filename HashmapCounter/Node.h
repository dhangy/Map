#ifndef __NODE__
#define __NODE__

#include <string>

class Node
{
public:
	Node()
	{
		value = 0;
	}
	Node(std::string input)
	{
		key = input;
		value = 1;
		next = nullptr;
	}
	Node(std::string input, int count)
	{
		key = input;
		this->value = count;
		next = nullptr;
	}
	Node(std::string input, int count, Node *next)
	{
		key = input;
		this->value = count;
		this->next = next;
	}
	~Node() = default; // really nothing to destruct

	Node *next;
	std::string key;	// this is the "word"
	unsigned int value;	// this is the "count"
};

#endif // !__NODE__
