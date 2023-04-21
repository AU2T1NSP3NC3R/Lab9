#include "Object.h"

Object::Object(string inVal) {
	word = inVal;
	count = 1;
}

void Object::incr_count() {
	count++;
}
