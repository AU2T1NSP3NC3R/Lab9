#include "tree.h"
template <class T>
tree<T>::tree() {
	root = nullptr;
	size = 0;
}

template <class T>
int tree<T>::height(node<T>* parent) {
	int h = 0;
	if (parent != nullptr) {
		int lHeight = height(parent->left);
		int rheight = height(parent->right);
		int maxHeight = max(lHeight, rHeight);
		h = maxHeight + 1;
	}
	return h;
}

template <class T>
int tree<T>::difference(node<T>* parent) {
	int lHeight = height(parent->left);
	int rHeight = height(parent->right);
	int dif = lHeight - rHeight;
	return dif;
}

template <class T>
node<T>* tree<T>::rrRotate(node<T>* parent) {
	node<T>* temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

template <class T>
node<T>* tree<T>::llRotate(node<T>* parent) {
	node<T>* temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

template <class T>
node<T>* tree<T>::rlRotate(node<T>* parent) {
	node* temp = parent->right;
	parent->right = llRotate(temp);
	return rrRotate(parent);
}

template <class T>
node<T>* tree<T>::lrRotate(node<T>* parent) {
	node* temp = parent->left;
	parent->left = rrRotate(temp);
	return llRotate(parent);
}

template <class T>
node<T>* tree<T>::balance(node<T>* temp) {
	int diff = difference(temp);
	if (diff > 1) {
		if (difference(temp->left) > 0) {
			temp = llRotate(temp);
		}
		else {
			t = lrRotate(temp);
		}
	}
	else if (diff < -1) {
		if (difference(temp->right) > 0) {
			temp = rlRotate(temp);
		}
		else {
			temp = rrRotate(temp);
		}
	}
	return temp;
}

template <class T>
node<T>* tree<T>::insert(node<T>* rt, T* inVal) {
	if (rt == nullptr) {
		node<T>* newNode = new node(inVal);
		rt = newNode;
		size++;
		return rt;
	}
	else if (*inVal < *rt->data) {
		rt->left = insert(rt->left, inVal);
		rt = balance(rt);
	}
	else if (*inVal > *rt->data) {
		rt->right = insert(rt->right, inVal);
		rt = balance(rt);
	}
	else if (*inVal == *rt->data) {
		//throw duplicate item error
	}
	return rt;
}

template <class T>
int tree<T>::getSize() {
	return size;
}

template <class T>
void tree<T>::printTree(node<T>* parent, int l) {
	int i;
	if (parent != nullptr) {
		show(parent->right, l + 1);
		cout << " ";
		if (parent == root) {
			cout << "Root -> ";
		}
		for (i = 0; i < l && p != root; i++) {
			cout << " " << *parent->data;
			show(parent->left, l + 1);
		}
	}
}

template <class T>
node<T>* tree<T>::remove(node<T>* rt, T* inVal) {
	node* temp;

	if (rt == nullptr) {
		return nullptr;
	}
	else if (*inVal < *rt->data) {
		rt->left = remove(rt->left, inVal);
	}
	else if (*inVal > *rt->data) {
		rt->right = remove(rt->right, inVal);
	}

	else if (rt->left && rt->right) {
		temp = findMin(rt->right);
		rt->data = temp->data;
		rt->right = remove(rt->right, rt->data);
	}
	else {
		temp = rt;
		if (rt->left == nullptr) {
			rt = rt->right
		}
		else if (rt->right == nullptr) {
			rt = rt->left;
		}
		size--;
		delete temp;
	}
	if (rt == nullptr) {
		return rt;
	}

	if (height(rt->left) - height(rt->right) == 2) {
		if (height(rt->left->left) - height(rt->left->right) == 1) {
			return lrRotate(rt);
		}
		else {
			return llRotate(rt);
		}
	}
	else if (height(rt->right) - height(rt->left) == 2) {
		if (height(rt->right->right) - height(rt->right->left) == 1)
			return rlRotate(rt);
		else
			return rrRotate(rt);
	}
	return rt;
}

template <class T>
node<T>* tree<T>::findMin(node<T>* temp) {
	if (temp == nullptr) {
		return nullptr;
	}
	else if (temp->left == nullptr) {
		return temp;
	}
	else {
		return findMin(temp->left);
	}
}

template <class T>
void tree<T>::publicInsert(T* inVal) {
	root = insert(root, inVal);
}

template <class T>
void tree<T>::publicRemove(T* inVal) {
	root = remove(root, inVal);
}

template <class T>
tree<T>::~tree() {
	clearTree(root);
}

template <class T>
void tree<T>::clearTree(node<T>* temp) {
	if (temp != nullptr) {
		clearTree(temp->left);
		clearTree(temp->right);
		delete temp;
	}
}

template <class T>
void tree<T>::emptyTree() {
	clearTree(root);
}

template <class T>
T* tree<T>::find(T* inVal) {
	if (root == nullptr) {
		return nullptr;
	}
	node* temp = root;
	while (temp->data != inVal) {
		if (temp == nullptr) {
			return nullptr;
		}
		else if (*inVal < *temp->data) {
			temp = temp->left;
		}
		else if (*inVal > *temp->data) {
			temp = temp->right;
		}
		else if(*inVal == *temp->data){
			return temp->data;
		}
	}
}

template <class T>
void tree<T>::getAllAscending(node<T>* temp) {
	if (temp == nullptr) {
		return;
	}
	getAllAscending(temp->left);
	cout << *temp->data << endl;
	getAllAscending(temp->right);
}

template <class T>
void tree<T>::getAllDescending(node<T>* temp) {
	if (temp == nullptr) {
		return;
	}
	getAllDescending(temp->right);
	cout << *temp->data << endl;
	getAllDescending(temp->left);
}