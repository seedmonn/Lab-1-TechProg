#pragma once

#include "queue_base.h"
class queue_protected : protected queue_base {
public:
	void calc();
	void print();
	void new_k(int num);
	void new_a(elem*value);
	void new_b(elem*value);
};
