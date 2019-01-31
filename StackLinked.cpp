#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
template<typename T>
struct Item{
	T val;
	Item<T>* next; 
};

template <class T2>
class Stack{
	private:
		Item<T2>* top;

	public:
		Stack(){top = NULL;}
		~Stack(){delete top;}
		void Push(const Item<T2> t)
		{
			if(!top)
			{
				top=new Item<T2>;
				memcpy(top, &t, sizeof(t));
				top->next=NULL;
			}
			else
			{
				Item<T2>* temp;
				temp= new Item<T2>;
				memcpy(temp, &t, sizeof(t));
				temp->next=top;
				top=temp;
			}
		}	

		Item<T2>* Pop()
		{
			if(!top)
				cout<<"Error";
			else
			{
				Item<T2>* temp1,*temp2;
				temp1 = new Item<T2>;
				memcpy(temp1, top, sizeof(*top));
				temp2=top;
				top=top->next;
				delete temp2;
				return temp1;
			}
		}

};

int main()
{
	Stack<char*> st;

	Item<char*> it, it1, *it2;
	it.val= new char[sizeof("Hello")];
	strcpy(it.val, "Hello");
	it1.val= new char[sizeof("Hello1")];
	strcpy(it1.val, "Hello1");
	st.Push(it);
	st.Push(it1);

	it2=st.Pop();
	cout<<it2->val;


}
