#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct queueNode
{
	int data;
	queueNode* next;
};

class Queue
{
	public:
	queueNode* head;
	
	void enqueue(int d);
	int dequeue();
	void print();
	
	Queue();
};

//CONSTRUCTOR
Queue::Queue()
{
	head = nullptr;
}

//INSERTS A NODE INTO THE QUEUE
void Queue::enqueue(int d)
{
	queueNode* newNode = new queueNode;
	newNode->data = d;
	newNode->next = nullptr;
	
	if(head == nullptr) head = newNode;
	else {
		queueNode* step = head;
		while(step->next != nullptr) step = step->next;
		step->next = newNode;
	}
}

//REMOVES A NODE FROM THE QUEUE
int Queue::dequeue()
{
	if(head == nullptr) {
		cout << "ERROR: Queue is empty" << endl;
		return 0;
	}
	
	queueNode* temp = head;
	int d = head->data;
	head = head->next;
	delete temp;
	return d;
}

//PRINTS THE QUEUE
void Queue::print()
{
	queueNode* step = head;
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