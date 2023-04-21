#pragma once
template <class T>
class node
{
public:
	T* data;
	node* left;
	node* right;

	node(T*);
};

