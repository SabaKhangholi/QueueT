#include <iostream>
using namespace std;
#include "QueueT.h"

int main(){
	QueueT q;
	QueueT copy;
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	copy = q;
	//q.print();
	copy.print();
}
