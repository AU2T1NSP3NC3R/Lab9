#include "node.h"
template <class T>
node<T>::node() {
	data = null;
	left = nullptr;
	right = nullptr;
}

template <class T>
node<T>::node(T* inVal) {
	data = inVal;
	left = nullptr;
	right = nullptr;
}