#include "List.h"

int main()
{
	List A;
	A.insert_front(2017);
	cout << "Insert Int_2017 Node : " << endl;								//Insert Int_2017 Node
	A.print();
	cout << endl;

	cout << "Insert Double_6.15 into front : " << endl;						//Insert Double_6.15 into front
	A.insert_front(6.15);
	A.print();
	cout << endl;

	cout << "Insert String_OOP into back : " << endl;						//Insert String_OOP into back
	A.insert_back("OOP");
	A.print();
	cout << endl;

	cout << "Insert String_HeterogeneousList into 2 poisiton : " << endl;	//Insert String_HeterogeneousList into 2 poisiton
	A.insert_p("HeterogeneousList", 2);
	A.print();
	cout << endl;

	cout << "Insert other nodes(1,2,1,2) : " << endl;						//Insert other nodes(1,2,1,2)
	A.insert_front(2);
	A.insert_front(1);
	A.insert_back(1);
	A.insert_back(2);
	A.print();
	cout << endl;

	cout << "Delete front node(1) : " << endl;								//Delete front node(1)
	A.delete_front();
	A.print();
	cout << endl;

	cout << "Delete back node(2) : " << endl;								//Delete back node(2)
	A.delete_back();
	A.print();
	cout << endl;

	cout << "Delete 2 poision node(6.15) : " << endl;						//Delete 2 poision node(6.15)
	A.delete_p(2);
	A.print();
	cout << endl;

	cout << "Reverse the linked list and print : " << endl;					//Reverse the linked list and print
	A.reverse();
	A.print();
	cout << endl;

	cout << "Create other linked list and print : " << endl;				//Create other linked list and print
	List B;
	B.insert_front("OOP_List");
	B.insert_back("CLASSB");
	B.print();
	cout << endl;
	
	cout << "Union A and B into A : " << endl;								//Union A and B into A
	A.union_other(B);
	A.print();
	cout << endl;

	cout << "Assign B to A : " << endl;										//Assign B to A
	A = B;
	A.print();
	cout << endl;

	cout << "Print A's second Node use A[1] : " << endl;					//Print A's second Node use A[1]
	A[1]->print();
	cout << endl;

	cout << "Destroy the linked list and check whether it has been destoried by printing A and its length : " << endl;
	A.destory();															//Destroy the linked list and check whether it has been destoried by printing A and its length
	A.print();
	cout << A.length() << endl;
	return 0;
}