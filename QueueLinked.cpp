#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
template<typename T1>
struct item{
	T1 st;
	item<T1>* next;
};
template<class T>
class Queue{
	public:
	Queue(){ top=NULL; bottom=NULL;};
	~Queue(){ delete top; delete bottom;}


	void Enqueue(const item<T> To)
	{
		if(top == NULL )
		{
			top= new item<T>;
			memcpy(top, &To, sizeof(To));
			top->next=NULL;
			bottom=top;
		}
		else
		{
			item<T>* temp= new item<T>;
			memcpy(temp,&To, sizeof(To));
			bottom->next=temp;
			bottom=temp;
		}
	}

	item<T>* Dequeue()
	{
		if(!top)
		{
			cout<<"Error: No items in Queue";
		}
		else
		{
			item<T>* res = top;
			top=top->next;
			if(!top)
				bottom=top;
			return res;
		}
	}

	private:
	item<T>* top;
	item<T>* bottom;


};

int main()
{
	Queue<char*> q;

	item<char*> t, t1, *t2, t3, *t4;
	t.st = new char[sizeof("hello")];
	t1.st = new char[sizeof("hello1")];
	t3.st = new char[sizeof("hello1")];
	strcpy(t.st, "hello");
	q.Enqueue(t);
	strcpy(t1.st, "hello1");
	q.Enqueue(t1);
	strcpy(t3.st, "hello1");
	q.Enqueue(t3);
	t2=q.Dequeue();
	t4=q.Dequeue();
	cout<<t2->st<<t4->st;


}
