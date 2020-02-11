// QueueT.cpp
#include "QueueT.h"
#include <iostream>
#include <stdexcept>
using namespace std;

QueueT::QueueT(){
	front = nullptr;	
	back = nullptr;		
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
	NodeT* newNode = new NodeT(value, nullptr);
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
			delete back;
			front = back = nullptr;
		}
		else{
			NodeT* temp = front;
			front = front->next;
			delete temp;
			temp = front;
			/*NodeT* temp = front;
			int result = temp->data;
			front = front->next;
			return result;
			delete temp;*/
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
	delete temp;//****************************************
	return n;
}
void QueueT::concatenate(QueueT & qu, int n){
	NodeT* nodePtr;
	nodePtr = qu.front;
	int i = 0;

	if (n>qu.size())
		throw std::out_of_range("number of elements to be concatenated is greater than the size of the parameter");

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
	//delete front;
	//delete back;
	front = nullptr;
	//back = nullptr;
	NodeT* original = qu.front;
	if (original != nullptr){
		front = new NodeT(original->data); //**8**
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
		delete temp;
		temp = front;
	}
	front = nullptr;
	back = nullptr;
}

NodeT* QueueT::getFront(){
	return front;
}
