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
	copyQueue(qu);		// helper method
}

QueueT::~QueueT(){

}

QueueT& QueueT::operator=(const QueueT & qu){
	copyQueue(qu);		// helper method
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
	while (front != nullptr){
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

}
void QueueT::concatenate(QueueT & qu, int n){

}
QueueT QueueT::merge(const QueueT& qu){

}
//add getFront
void QueueT::copyQueue(const QueueT & qu){
	front = nullptr;
	back = nullptr;
	NodeT* original = qu.front;
	// copy front of queue
	if (original != nullptr){
		// copy front of queue
		front = new NodeT(original->data);
		original = original->next;
		NodeT* copy = front;
		// copy remaining nodes
		while (original != nullptr){
			NodeT* newNodeT = new NodeT(original->data);
			copy->next = newNodeT;
			copy = copy->next;
			original=original->next;
		}
	}
}
