#include "List.h"

List::List()
{
	Head = Tail = NULL;												//initialize the list
	Length = 0;
}

List::~List()
{
	destory();
}

void List::print() const
{
	Node *Temp = Head;
	if (!Temp)
		cout << "Empty List!" << endl;
	else
	{
		while (Temp)
		{
			Temp->print();											//call virtual function
			Temp = Temp->next();
		}
	}
}

Node * List::get_head()
{
	return Head;													//return Head
}

Node * List::get_tail()
{
	return Tail;													//return Tail
}

Node * List::operator[](int index)
{
	int count = 0;
	Node *Temp = Head;
	while(Temp)														//find the index poision's node
	{
		if (count == index)
			break;
		Temp = Temp->next();
		count++;
	}
	return Temp;													//return the node's pointer
}

const int List::length() const
{
	return Length;													//return the length
}

void List::insert_front(int a)										//insert Int node into front (function overload)
{
	Node *Temp = new IntNode(a);
	Temp->next() = Head;
	Head = Temp;
	if (!Tail)
		Tail = Temp;
	Length++;
}

void List::insert_front(double a)									//insert Double node into front (function overload)
{
	Node *Temp = new DoubleNode(a);
	Temp->next() = Head;
	Head = Temp;
	if (!Tail)
		Tail = Temp;
	Length++;
}

void List::insert_front(char * a)									//insert String node into front (function overload)
{
	Node *Temp = new StringNode(a);
	Temp->next() = Head;
	Head = Temp;
	if (!Tail)
		Tail = Temp;
	Length++;
}

void List::insert_back(int a)										//insert Int node into back(function overload)
{
	Node *Temp = new IntNode(a);
	Temp->next() = NULL;
	if(Tail)														//find the back node
		Tail->next() = Temp;
	Tail = Temp;
	if (!Head)
		Head = Temp;
	Length++;
}

void List::insert_back(double a)									//insert Double node into front (function overload)
{
	Node *Temp = new DoubleNode(a);
	Temp->next() = NULL;
	if (Tail)
		Tail->next() = Temp;
	Tail = Temp;
	if (!Head)
		Head = Temp;
	Length++;
}

void List::insert_back(char * a)									//insert String node into front (function overload)
{
	Node *Temp = new StringNode(a);
	Temp->next() = NULL;
	if (Tail)
		Tail->next() = Temp;
	Tail = Temp;
	if (!Head)
		Head = Temp;
	Length++;
}

void List::insert_p(int a, int index)								//insert Int node into the index poision (function overload)
{
	Length++;
	if(index>Length)
	{
		cout << "The index is out of current length!" << endl;
		return;
	}
	Node *Temp = new IntNode(a);
	if(1 == index)
	{
		Temp->next() = Head;
		Head = Temp;
		if (!Tail)
			Tail = Temp;
	}
	else
	{
		int count = 1;
		Node *T = Head;
		while (T)
		{
			count++;
			if (count == index)
				break;
			T = T->next();
		}
		if (index == Length)
			Temp->next() = NULL;
		else
			Temp->next() = T->next();
		T->next() = Temp;
	}
}

void List::insert_p(double a, int index)							//insert Double node into the index poision (function overload)
{
	Length++;
	if (index>Length)
	{
		cout << "The index is out of current length!" << endl;
		return;
	}
	Node *Temp = new DoubleNode(a);
	if (1 == index)
	{
		Temp->next() = Head;
		Head = Temp;
		if (!Tail)
			Tail = Temp;
	}
	else
	{
		int count = 1;
		Node *T = Head;
		while (T)
		{
			count++;
			if (count == index)
				break;
			T = T->next();
		}
		if (index == Length)
			Temp->next() = NULL;
		else
			Temp->next() = T->next();
		T->next() = Temp;
	}
}

void List::insert_p(char * a, int index)							//insert String node into the index poision (function overload)
{
	Length++;
	if (index>Length)
	{
		cout << "The index is out of current length!" << endl;
		return;
	}
	Node *Temp = new StringNode(a);
	if (1 == index)
	{
		Temp->next() = Head;
		Head = Temp;
		if (!Tail)
			Tail = Temp;
	}
	else
	{
		int count = 1;
		Node *T = Head;
		while (T)
		{
			count++;
			if (count == index)
				break;
			T = T->next();
		}
		if (index == Length)
			Temp->next() = NULL;
		else
			Temp->next() = T->next();
		T->next() = Temp;
	}
}

void List::delete_front()											//Delete the front node (function overload)
{
	if(!Head)
	{
		cout << "The list is empty!" << endl;
		return;
	}
	Node *Temp = Head;
	Head = Temp->next();
	delete Temp;
	Length--;
}

void List::delete_back()											//Delete the back node (function overload)
{
	if (!Tail)
	{
		cout << "The list is empty!" << endl;
		return;
	}
	Node *Temp = Head;
	if(1 == Length)
	{
		delete Tail;
		Head = Tail = NULL;
	}
	else
	{
		while (Temp->next()->next())
			Temp = Temp->next();
		delete Temp->next();
		Temp->next() = NULL;
		Tail = Temp;
	}
	Length--;
}

void List::delete_p(int index)										//Delete the index poision node (function overload)
{
	if(!Head)
	{
		cout << "The list is empty!" << endl;
		return;
	}
	if(index>Length)
	{
		cout << "The index is out of current length!" << endl;
		return;
	}
	Node *Temp = Head;
	if(1 == index)
	{
		Head = Temp->next();
		delete Temp;
		return;
	}
	else
	{
		int count = 1;
		while (Temp)
		{
			count++;
			if (count == index)
				break;
			Temp = Temp->next();
		}
		Node *T = Temp->next();
		if (index == Length)
			Temp->next() = NULL;
		else
			Temp->next() = Temp->next()->next();
		delete T;
	}
	Length--;
}

void List::reverse()												//Reverse the linked list
{
	if (1 >= Length)
		return;
	Node *FTemp = Head;
	Node *NTemp = Head->next();
	while(NTemp)
	{
		FTemp->next() = NTemp->next();
		NTemp->next() = Head;
		Head = NTemp;
		NTemp = FTemp->next();
	}
	Tail = FTemp;
}

void List::destory()												//Destory the linked list
{
	Node *Temp = Head;
	Node *T;
	while(Temp)
	{
		T = Temp;
		Temp = Temp->next();
		delete T;
	}
	Head = Tail = NULL;
	Length = 0;
}

void List::union_other(const List& a)									//Union two linked list
{
	Node *TTemp = Tail;
	Node *FTemp = a.Head;
	while(FTemp)
	{
		FTemp->union_other(TTemp);
		FTemp = FTemp->next();
		TTemp = TTemp->next();
	}
}

void List::operator=(const List & a)								//Overload the operator =
{
	destory();
	this->insert_front(1);
	Node *TTemp = Tail;
	Node *FTemp = a.Head;
	while (FTemp)
	{
		FTemp->union_other(TTemp);
		FTemp = FTemp->next();
		TTemp = TTemp->next();
	}
	this->delete_front();
}


IntNode::IntNode(int a)												//IntNode class
{
	Int_key = a;
}

void IntNode::union_other(Node *& a) const								//IntNode union
{
	a->next() = new IntNode(Int_key);
	a->next()->next() = NULL;
}

void IntNode::print() const											//IntNode print
{
	cout << Int_key << endl;
}



DoubleNode::DoubleNode(double a)									//DoubleNode class
{
	Double_key = a;
}

void DoubleNode::union_other(Node *& a) const							//DoubleNode union
{
	a->next() = new DoubleNode(Double_key);
	a->next()->next() = NULL;
}

void DoubleNode::print() const										//Double print
{
	printf("%lf\n", Double_key);
}

StringNode::StringNode(char * a)									//StringNode class
{
	Char_key = new char[strlen(a) + 1];
	strcpy(Char_key, a);
}

StringNode::~StringNode()											//virtual StringNode destructor function to release the space applicated in heap
{	
	delete Char_key;
}

void StringNode::union_other(Node *& a) const							//StringNode union
{
	a->next() = new StringNode(Char_key);
	a->next()->next() = NULL;
}

void StringNode::print() const										//StringNode print
{
	cout << Char_key << endl;
}
