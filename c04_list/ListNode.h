// #ifndef _LISTNODE_H_
// #define _LISTNODE_H_

#include <cstddef> //if not, "NULL" cannot find

//using template: 
template <class T> class ListNode { //default construct function
          
	T data;
	ListNode<T>*  link;

public:

	ListNode() : link(NULL){}

	//construct function with parameter: initilize a node with value
	ListNode (T value) : link(NULL) , data(value) {}

	~ListNode(){};
	void SetLink(ListNode<T>* next);
	void SetData(T value);
	ListNode<T>*  GetLink ();
	T& GetData ();
};

//assign 'next' to the 'link' of the node
template <class T>
void ListNode<T>::SetLink(ListNode<T>* next){ 
	link = next;
}

//assign 'value' to the 'data' of the node
template <class T>
void ListNode<T>::SetData(T value){
	data = value;
}

//get 'link' of the node
template <class T>
ListNode<T>* ListNode<T>::GetLink(){
	return link;
}

//get 'data' of the value
template <class T>
T&  ListNode<T>::GetData(){
	return data;
}

//#endif
