// QueueT.cpp
#include "QueueT.h"
#include <iostream>
#include <stdexcept>
using namespace std;

QueueT::QueueT(){
	front = nullptr;	// initialize a front ptr
	back = nullptr;		// initialize a back ptr
}

QueueT::QueueT(const QueueT & qu){
	copyQueue(qu);
}

QueueT::~QueueT(){
	deleteQueue();
}

QueueT& QueueT::operator=(const QueueT & qu){
	if (this != &qu){
		deleteQueue();
		copyQueue(qu);	
	}
	return *this;
}

void QueueT::enqueue(int value){
	NodeT* newNode = new NodeT(value, NULL);
	if (front == nullptr){
		front = newNode;
		back = newNode;
	}
	else{
		back->next = newNode;
		back = newNode;
	}
}
int QueueT::dequeue(){
	if(empty())
		 throw std::out_of_range("queue empty");
	else{
		if (front == back){
			delete front;
			front = back = nullptr;
		}
		else{
			NodeT* nodePtr = front;
			front = front->next;
		}
	}
}
void QueueT::print(){
	NodeT* temp = front;
	while (temp != nullptr){
		cout << temp->data << endl;
		temp = temp->next;
	}
}
bool QueueT::empty(){
	if (front == nullptr && back == nullptr)
		return true;
	else
		return false;
}
int QueueT::size(){
	NodeT* temp = front;
	int n = 0;
	while (temp != nullptr){
		temp = temp->next;
		n++;
	}
	return n;
}
void QueueT::concatenate(QueueT & qu, int n){
	NodeT* nodePtr;
	nodePtr = qu.front;
	int i = 0;

	if (n>qu.size())
		throw std::out_of_range("number of elements to be concatenated is greater than the size of the qu parameter");

	while( i < n && nodePtr != nullptr){
		enqueue(nodePtr->data);
		nodePtr = nodePtr->next;
		qu.dequeue();
		i++;
	}
}
QueueT QueueT::merge(const QueueT& qu){
	NodeT* callObj = front;
	NodeT* param = qu.front;
	QueueT mergeQ;
	while(callObj != nullptr && param != nullptr){
		mergeQ.enqueue(callObj->data);
		mergeQ.enqueue(param->data);
		callObj = callObj->next;
		param=param->next;
	}
	if (callObj == nullptr){
		while(param != nullptr){
			mergeQ.enqueue(param->data);
			param = param->next;
		}
	}
	if (param == nullptr){
		while(callObj != nullptr){
			mergeQ.enqueue(callObj->data);
			callObj = callObj->next;
		}
	}	
	return mergeQ;
}
void QueueT::copyQueue(const QueueT & qu){
	front = nullptr;
	back = nullptr;
	NodeT* original = qu.front;
	if (original != nullptr){
		front = new NodeT(original->data);
		original = original->next;
		NodeT* copy = front;
		while (original != nullptr){
			NodeT* newNodeT = new NodeT(original->data);
			copy->next = newNodeT;
			copy = copy->next;
			original=original->next;
		}
		back = copy;
	}
}

void QueueT::deleteQueue(){
	NodeT* temp = front;
	while (front!=nullptr){
		front = front->next;
		delete front;
	}
	front = nullptr;
	back = nullptr;
}
