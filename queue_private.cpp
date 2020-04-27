#include "queue_private.h"
#include <iostream>
using namespace std;

void queue_private::calc() {
	float sum = 0;
	float sum_A = 0;
	elem* temp = get_b();

	while (temp != NULL) {
		sum_A = sum_A + temp->Val;
		temp = temp->Prev;
	}
	sum = sum_A / get_k();
	cout << "\nСреднее арифметическое = [" << sum << "]\n";
	temp = get_b();
	while (temp != NULL) {
		if (temp->Val < sum) {
			float flag = temp->Val;
			cout << "Последний элемент, меньшего среднего арифметического [" << flag; cout << "]" << endl; break;
		}
		temp = temp->Prev;
	}
}

void queue_private::print() {
	if (!get_k()) {
		cout << "Очередь пуста!" << endl;
		return;
	}
	elem *temp = get_b();
	int *och = new int[get_k()];
	int l = get_k() - 1;
	for (int i = 0; i < get_k(); ++i) {
		och[l--] = temp->Val;
		temp = temp->Prev;
	}
	cout << "Текущая очередь:" << endl;
	for (int i = 0; i < get_k(); ++i) {
		cout << "[" << och[i] << "] ";
	}
	delete[] och;
}

void queue_private::new_k(int num) {
	set_k(num);
}

void queue_private::new_a(elem*value) {
	set_a(value);
}

void queue_private::new_b(elem*value) {
	set_b(value);
}
