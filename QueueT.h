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
	QueueT(QueueT const &);
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	~QueueT();
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	QueueT& operator=(QueueT const & qu);
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	void enqueue(int value);
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	int dequeue();
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	void print();
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	bool empty();
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	int size();	
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	void concatenate(QueueT & qu, int n);
	// PRE: call copyQueue() helper method
	// PARAM: qu = parameter QueueT object deep copy
	// POST: creates deep copy of QueueT parameter
	QueueT merge(const QueueT& qu);
	//add getFront
private:
	NodeT* front;
	NodeT* back;
	int numValues;
	void copyQueue(QueueT const & qu);
	void deleteQueue();
};
