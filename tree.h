#pragma once
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
#include "node.h"
#include "node.cpp"
template <class T>
class tree
{
public:
	tree();
	~tree();
	void clearTree(node*);

	void publicInsert(T*);
	void publicRemove(T*);

	node* insert(node*, T*);
	int height(node*);
	int difference(node*);

	node* rrRotate(node*);
	node* llRotate(node*);
	node* lrRotate(node*);
	node* rlRotate(node*);

	node* balance(node*);
	node* findMin(node*);

	T* find(T*);

	int getSize();

	void getAllAscending(node<T>*);
	void getAllDescending(node<T>*);

	void printTree(node*, int);
	void emptyTree();
	node* remove(node*, T*);
private:
	node<T>* root;
	int size;
};

