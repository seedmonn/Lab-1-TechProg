#pragma once

#include "Element.h"
class queue_base {
	elem *a;
	elem *b;
	int k;
public:
	queue_base();
	~queue_base();
	void del();
	void add(int user_value);
	void print_queue();
	void calc();
	void copy_queue(queue_base &op1);
	queue_base *merge(queue_base *op1);
	elem *get_a();
	elem *get_b();
	int get_k();
	void set_k(int num);
	void set_a(elem *value);
	void set_b(elem *value);
};
