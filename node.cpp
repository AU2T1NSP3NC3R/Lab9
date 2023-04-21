#include "node.h"

template <class T>
node<T>::node(T* inVal) {
	data = inVal;
	left = nullptr;
	right = nullptr;
}