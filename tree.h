#pragma once
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
#include "node.h"
#include "node.cpp"

template <class T>
class tree
{
public:
	tree();
	~tree();
	void clearTree(node<T>*);

	void publicInsert(T*);
	void publicRemove(T*);

	node<T>* insert(node<T>*, T*);
	int height(node<T>*);
	int difference(node<T>*);

	node<T>* rrRotate(node<T>*);
	node<T>* llRotate(node<T>*);
	node<T>* lrRotate(node<T>*);
	node<T>* rlRotate(node<T>*);

	node<T>* balance(node<T>*);
	node<T>* findMin(node<T>*);

	T* find(T*);

	int getSize();

	void getAllAscending(node<T>*);
	void getAllDescending(node<T>*);

	void printTree(node<T>*, int);
	void emptyTree();
	node<T>* remove(node<T>*, T*);
private:
	node<T>* root;
	int size;
};

