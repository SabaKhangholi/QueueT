#include <iostream>
using namespace std;
#include "QueueT.h"

int main(){
	QueueT hi;
	QueueT qu(hi);
	QueueT q;
	
	hi.enqueue(5);

	hi.enqueue(4);
	//hi.empty();
	//hi.dequeue();
	//hi.print();
	//hi.enqueue(4);
	//hi.dequeue();
	//hi.dequeue();
	//hi.dequeue();

	//hi.dequeue();
	
	qu.enqueue(1);
	//qu.enqueue(2);
	qu.dequeue();
	hi.print();
	//cout<<"front"<<endl;
	//cout<<qu.getFront()<<endl;
	
	//hi.enqueue(6);
	
	QueueT Q(qu.merge(hi));
	//Q = qu.merge(hi);
	//Q.print();
	//Q(qu.merge(hi));
	/*
	qu.enqueue(5);
	qu.enqueue(6);
	qu.enqueue(7);
	qu.enqueue(8);
	*/
	//q.print();
	//Q.print();
	//Q(qu.merge(q));
	//mergeQ.print();
	//mergeQ.enqueue(3);

	q.concatenate(qu, 1);
//	q.print();
//	cout<<"qu"<<endl;
//	qu.print();
	
}
