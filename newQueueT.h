#pragma once
#include <iostream>
using namespace std;

class NodeT{
public:
	// Constructors and destructor
	NodeT(): data(0), next(nullptr) {};
	NodeT(int value): data(value), next(nullptr){};
	NodeT(int value, NodeT* nd): data(value), next(nd) {};
	~NodeT(){}; 
	// Attributes
	int data;
	NodeT* next;
};

class QueueT{
public:
	// PRE: 
	// PARAM: 
	// POST: creates empty stack
	QueueT();
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	QueueT(QueueT const & qu);
	~QueueT();
	QueueT& operator=(QueueT const & qu);
	void enqueue(int value);
	int dequeue();
	void print();
	bool empty();
	int size();
	void concatenate(QueueT & qu, int n);
	QueueT merge(const QueueT& qu);
	//add getFront
private:
	NodeT* front;
	NodeT* back;
	int numValues;
	void copyQueue(QueueT const & qu);
	void deleteQueue();
};
