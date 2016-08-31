//#include "ListNode.h"
#include "CirList.h"
#include <iostream>

#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	CirList<int> poker;
	cout << "poker_CirList length : " << poker.GetCount() << endl;
	cout << "IsEmpty: " << poker.IsEmpty() << endl;

	for(int i=0; i<13; i++) {
		poker.AddTail(0);	//make a new circular list for 13 cards
	}
	cout << "poker_CirList length : " << poker.GetCount() << endl;
	cout << "IsEmpty: " << poker.IsEmpty() << endl;

	poker.SetBegin();
	cout << "@@Head node: " << endl;
	cout << "  ->link : " << poker.GetCur()->GetLink() << endl;
	cout << "  ->data : " << poker.GetCur()->GetData() << endl;

	ListNode<int>* head;
	head = poker.GetCur(); 
	cout << "@@Head node: " << endl;
	cout << "  ->link : " << head->GetLink() << endl;
	cout << "  ->data : " << head->GetData() << endl;

	poker.GetCur()->GetLink()->SetData(1);
	cout << "  =>Set 1 to the node pointed by the Head: " << endl;
	cout << "@@First node: " << endl;
	cout << "  ->link : " << poker.GetCur()->GetLink()->GetLink() << endl;
	cout << "  ->data: "  << poker.GetCur()->GetLink()->GetData() << endl;
	

	for(int i=2; i<14; i++) {
		cout << "i->" << i << endl;
		for (int j=0; j<i; j++) {
			poker.GetNext();	//find location of inserting a card
			cout << "     j->" << j << ": link->" << poker.GetCur()->GetLink() << "; data->" << poker.GetCur()->GetData() << endl;

			if(poker.GetCur()->GetData() !=0) {
				j--;	//if exist card, go to next 
			}
		}

		if(poker.GetCur() == head) { //Added by lch (50~62): I found '9' located 'head', which 'SetData()' not work
			cout << "     @@node: This is 'head', cannot assign a 'value', so just go on next." << endl;
			cout << "       ->link : " << poker.GetCur()->GetLink() << endl;
			cout << "       ->data : " << poker.GetCur()->GetData() << endl;
			for (int j=0; j<1; j++) {
				poker.GetNext();
				cout << "     j->" << j << ": link->" << poker.GetCur()->GetLink() << "; data->" << poker.GetCur()->GetData() << endl;
				
				if(poker.GetCur()->GetData() != 0) {
					j--;
				}
			}
		}
		poker.GetCur()->SetData(i);
		cout << "    ->setData: link->" << poker.GetCur()->GetLink() << "; data->" << poker.GetCur()->GetData() << endl;
	}
	
	poker.SetBegin();
	for(int i=0; i<13; i++) {
		cout << poker.GetNext() << "*";
	}
	cout << endl;
	
	system("PAUSE");
	return 0;
}
