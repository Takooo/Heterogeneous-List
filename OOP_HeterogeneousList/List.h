#pragma once
#include<string>  
#include<iostream>
#include<cstdio>
using namespace std;

class Node													//Base class
{
public:
	Node() {}
	virtual ~Node(){}										//virtual destructor
	Node *&next() { return Next; }							//get the Next pointer
	virtual void print() const = 0;							//pure virtual function to print key
	virtual void union_other(Node *&a) const = 0;				//pure virtual function to do union
private:
	Node *Next;												//the pointer point the next node
};

class IntNode :public Node									//Int Node class
{
private:
	int Int_key;											//Int Key
public:
	IntNode(int a);											//Constructor function
	~IntNode(){}											//because it doesn't have the application of space of heap, so there is no need to achieve destructor function
	virtual void union_other(Node *&a) const;					//vitural function to do union
	virtual void print() const;								//virtual function to print
};

class StringNode :public Node								//String Node class
{
private:
	char *Char_key;											//String Key
public:
	StringNode(char *a);									//Constructor function
	~StringNode();											//because it has the application of space of heap, so it must achieve destructor function
	virtual void union_other(Node *&a) const;					//vitural function to do union
	virtual void print() const;								//virtual function to print
};

class DoubleNode :public Node								//Double Node class
{
private:
	double Double_key;										//Double Key
public:	
	DoubleNode(double a);									//Constructor function
	~DoubleNode() {}										//because it doesn't have the application of space of heap, so there is no need to achieve destructor function
	virtual void union_other(Node *&a) const;					//vitural function to do union
	virtual void print() const;								//virtual function to print
};

class List
{
private:
	Node *Head;												//the head of the linked list
	Node *Tail;												//the tail of the linked list
	int Length;												//the length of the linked list
public:
	List();													//constructor function
	~List();												//destructor function
	void print() const;										//print all the key contained
	Node * get_head();										//return the head pointer of the linked list
	Node * get_tail();										//return the tail pointer of the linked list
	Node * operator[](int index);							//use [] to control the linked list							//index is the node's poision that you want to operate 
	const int length() const;								//return the length of the linked list
	void insert_front(int a);								//insert the IntNode into the front of the linked list		//a is what you want to insert
	void insert_front(double a);							//insert the DoubleNode into the front of the linked list	//a is what you want to insert
	void insert_front(char *a);								//insert the StringNode into the front of the linked list	//a is what you want to insert
	void insert_back(int a);								//insert the IntNode into the back of the linked list		//a is what you want to insert
	void insert_back(double a);								//insert the Double into the back of the linked list		//a is what you want to insert
	void insert_back(char *a);								//insert the StringNode into the back of the linked list	//a is what you want to insert
	void insert_p(int a, int index);						//insert the IntNode into the index poistion of the linked list			//a is what you want to insert, index is where you want to insert
	void insert_p(double a, int index);						//insert the DoubleNode into the index poistion of the linked list		//a is what you want to insert, index is where you want to insert
	void insert_p(char *a, int index);						//insert the StringNode into the index poistion of the linked list		//a is what you want to insert, index is where you want to insert
	void delete_front();									//delete the front node of the linked list
	void delete_back();										//delete the back node of the linked list
	void delete_p(int index);								//delete the index poistion node of the linked list
	void reverse();											//reverse the linked list
	void destory();											//destroy the linked list
	void union_other(const List& a);							//union the linked list with other linked list				//a is the linked list that you want to union to original linked list
	void operator = (const List& a);						//assign other linked list to this linked list				//a is the linked list that you want to assign to original linked list
};
