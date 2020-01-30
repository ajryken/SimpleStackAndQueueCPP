#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct stackNode
{
	int data;
	stackNode* next;
};

class Stack
{
	public:
	stackNode* head;
	
	void push(int d);
	int pop();
	void print();
	
	Stack();
};

//CONSTRUCTOR
Stack::Stack()
{
	head = nullptr;
}

//PUSHES A NODE ONTO THE STACK
void Stack::push(int d)
{
	stackNode* newNode = new stackNode;
	newNode->data = d;
	newNode->next = nullptr;
	
	if(head == nullptr) head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
}

//POPS A NODE OFF THE STACK
int Stack::pop()
{
	if(head == nullptr) {
		cout << "ERROR: Stack is empty" << endl;
		return 0;
	}
	else {
		stackNode* temp = head;
		int d = head->data;
		head = head->next;
		delete temp;
		return d;
	}
}

//PRINTS OUT THE CONTENTS OF THE STACK
void Stack::print()
{
	stackNode* step = head;
	if(head == nullptr)
	{
		cout << "(Empty)" << endl;
		return;
	}
	while(step != nullptr)
	{
		cout << step->data << '\t';
		step = step->next;
	}
	cout << endl;
}

#endif