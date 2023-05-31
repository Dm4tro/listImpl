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
#include <stdarg.h>
#include <list>
#include <cstdarg>
using namespace std;


template<typename T>

class Node
{
public:
	T val;
	Node<T>* next;
	Node<T>* previosus;
	Node(const T& val) {
		this->val = val;
		this->next = this;
		this->previosus = this;
	}
	Node()
	{
		val = 0;
		next = this;
		previosus = this;
	}


	~Node()
	{

	}

};

template<typename T>
class List
{
public:

	List() {

		head = NULL;
	}
	List(const T values[]) {
		head = NULL;
		const auto array_length = sizeof(values)==0 ? 0: sizeof(values) / sizeof(values[0]);
		for (size_t i = 0; i < array_length; i++)
		{
			add_before_head(values[i], head);
		}
		
	}

	~List()
	{
		Node<T>* current = head;
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}

		head = nullptr;
		
	}

	List(const List<T>& rhs) {
		copyClass( rhs);

	}

	/*void add(T value) {

		Node* add(current)
		Node<T>* Newnode = new Node<T>(value);

		Node<T>* temp = head;

		if (head == NULL) {
			head = Newnode;
			return;

		}

		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = Newnode;
		


	}*/

	void add_front(T value) {
		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;
		if (head == NULL) {
			head = Newnode;
			Newnode->next = Newnode;
			Newnode->previosus = Newnode;
			return;

		}
		Newnode->previosus = current->previosus;
		Newnode->next = current;
		current->previosus = Newnode;
		do
		{
			current = current->next;
		} while (current->next != head);
		current->next = Newnode;
		head = Newnode;

	}
	void add_back(T value) {
		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;

		if (head == NULL) {
			head = Newnode;
			Newnode->next = Newnode;
			Newnode->previosus = Newnode;
			return;

		}

		/*while (current->next != head);
		{
			current = current->next;
		} */

		do
		{
			current = current->next;
		} while (current->next != head);

		current->next = Newnode;

		Newnode->next = head;
		Newnode->previosus = current;

		
	}

	//template<class T>
    static Node<T>* add_before_head(const T& value, Node<T>*& head ) {

		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;
		if (head == NULL) {
			head = Newnode;
			Newnode->next = Newnode;
			Newnode->previosus = Newnode;
			return head;

		}
		Newnode->previosus = current->previosus;
		Newnode->next = current;
		current->previosus = Newnode;
		do
		{
			current = current->next;
		} while (current->next != head);
		current->next = Newnode;
		head = Newnode;

		return head;
	}




	void print()const {
		Node<T>* temp = head;
		cout << "THList is:" << endl;
		while (temp != NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}

		cout << endl;

	}


	void delete_at(int num) {

		Node<T>* temp1 = head;
		Node<T>* temp2 = NULL;

		while (num-- > 1)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;

	}
	/*delete temp1;*/
	List<T>& operator=(List<T>& rhs) {

		Node<T>* current = head;
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			delete current;
			current = next;

		}
		head = nullptr;

		Node<T>* temp = rhs.head;


		/*head = temp;*/



		while (temp != NULL)
		{

			add(temp->val);
			temp = temp->next;


		}

		return *this;
	}


	friend ostream& operator<<(ostream& os, const List<T>& rhs)
	{
		Node<T>* temp = head;
		os << "THList is:" << endl;
		while (temp != NULL)
		{
			os << temp->val << " ";
			temp = temp->next;
		}
		os << endl;
		return os;
	}

	private:
	Node<T>* head;
	
	protected:
		void copyClass(List rs) {
			Node<T>* current = head;
			Node<T>* next = NULL;
			while (current != NULL)
			{
				next = current->next;
				delete current;
				current = next;

			}
			head = nullptr;

			Node<T>* temp = rs.head;


			/*head = temp;*/



			while (temp != NULL)
			{

				add(temp->val);
				temp = temp->next;


			}

			/*return *this;*/

		}
};


int main()
{
	int x = 0;

	string myNum[3] = { "fsd","sadasd","dsad" };
	List<string> list3(myNum);
	list3.print();
	

	return 0;
}
