#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cctype>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib> 
#include <cctype> 
#include <map>
#include <list>
using namespace std;


class Node
{
public:
	int val;
	Node* next;
	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
	Node()
	{
		val = 0;
		next = NULL;
	}


	~Node()
	{

	}

};


class MyClass
{
public:
	
	MyClass() {

		head = NULL;
	}

	~MyClass()
	{
		Node* current = head;
		Node* next = NULL;
		while (current!=NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}

		head = nullptr;
	}

	void add(int value) {
		
		
		Node* Newnode = new Node(value);

		Node* temp = head;

		if (head == NULL) {
			head = Newnode;
			return;

		}

		while (temp->next!=NULL)
		{
			temp = temp->next;

		}
		temp->next = Newnode;
		 

	}


	void print() {
		Node* temp = head;
		cout << "THList is:" << endl;
		while (temp!=NULL)
		{
			cout << temp->val<<" ";
			temp = temp->next;
		}

		cout << endl;

	}


	void delete_at(int num) {
		
		Node* temp1 = head;
		Node* temp2 = NULL;

		while (num-->1)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;

	}
	/*delete temp1;*/
	MyClass& operator=(MyClass& rhs) {

		Node* current = head;
		Node* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}
		head = nullptr;

		Node* temp = rhs.head;
		
		
		/*head = temp;*/

		
		
		while (temp!=NULL)
		{
			
			add(temp->val);
			temp = temp->next;
			
			
		}
		
		return *this;
	}



private:
	Node* head;
};


int main()
{
	int x=0;

	MyClass list;

	list.add(2);
	list.add(6);
	list.add(3);
	list.add(223);
	list.add(2);
	list.add(2523);
	list.add(43);
	list.add(623);
	
	list.print();

	list.delete_at(4);
	
	list.print();

	cout << x<<endl;


	MyClass list2;

	list2 = list;

	list2.print();

	return 0;
}

