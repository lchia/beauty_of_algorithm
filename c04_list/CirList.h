//#ifndef _CIRLIST_H_
//#define _CIRLIST_H_

#include "ListNode.h"

template <class T > class CirList{

	ListNode<T>* head;
	ListNode<T>* tail;
	ListNode<T>* cur;

public :
	CirList();
	~CirList();

	bool AddTail(T value);
	void RemoveThis();
	void RemoveAll();
	void SetBegin();
	int GetCount();
	ListNode<T>* GetCur();

	bool IsEmpty();
	T GetNext();
};

template <class T >  
CirList<T>::CirList(){
	head = tail = new ListNode<T>;
	cur = head;
	head->SetLink(head);
}

template <class T>  
CirList<T>::~CirList(){
	RemoveAll();
	delete head;
}

template <class T> 
bool CirList< T >::AddTail(T value){
	ListNode<T>* add = new ListNode<T>(value);

	tail->SetLink(add);		//
	tail = tail->GetLink();		//
	tail->SetLink(head);		//

	if(tail != NULL)
		return true;
	else
		return false;
}

template <class T> 
void CirList<T>::RemoveThis(){
	if(cur == head){
	    cur = cur->GetLink();
	}
 
	ListNode<T>* node_del = cur;
	ListNode<T>* preCur = cur;
	for(int i=0;i<this->GetCount();i++){
	    preCur = preCur->GetLink();
	}

	preCur->SetLink(cur->GetLink());
	delete node_del;
	cur = preCur->GetLink();
	preCur = NULL;
}

template <class T> 
void CirList< T >::RemoveAll(){
    SetBegin();
	int length = GetCount();
	for(int i=0;i<length;i++){ 
		RemoveThis();
	}
	cur = head;
}

template <class T> 
void CirList< T >::SetBegin(){
	cur = head;
}

template <class T> 
int CirList<T>::GetCount(){
	int num = 0;
	if (cur==NULL)
		this->SetBegin();
	ListNode<T>* here = cur;
	while(cur->GetLink() != here){
		cur = cur->GetLink();
		++num;
	}
	//cur = cur->GetLink();
	cur = here;
	return 
		num;
}

template <class T> 
ListNode<T>* CirList< T >::GetCur(){
	return cur;
}

template <class T > 
bool CirList< T >::IsEmpty(){
	return 
		head->GetLink() == head;
}


template <class T> 
T CirList< T >::GetNext(){
	if(cur == head){
		cur = cur->GetLink();
	}
	T num = cur->GetData();	//
	cur = cur->GetLink();	//
	return 	
	num; 
}

//#endif
