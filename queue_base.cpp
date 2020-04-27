#include "queue_base.h"
#include <iostream>
using namespace std;

queue_base::queue_base() {
	a = nullptr; //  обнуляем указатель
	b = nullptr; //  обнуляем указатель 
	k = 0; // k = кол-во объектов в очереди
}

queue_base::~queue_base() {
	elem *temp = b;
	while (temp) {
		temp = b->Prev;
		delete b; // вызывает краш программы, при выполении 4 пункта меню
		b = temp;
	}
}

void queue_base::del() {
	if (!k) {
		cout << "Очередь пуста!" << endl; // защита, если элементов в очереди нет
		return;
	}
	if (k == 1) {
		delete a;
		a = nullptr; // если элемент в очереди всего один, нет смысла идти с конца до первого, удаляем сразу, и обнуляем указатели
		b = nullptr;
	}
	else {
		elem *temp = b; // "временному" объекту структуры присваиваются значения последнего элемента в очереди (т.е. значения полей val и *prev )
		while (temp->Prev != a) { // справа налево продвигаемся по элементам очереди, пока не дойдем до второго элемента (слева) очереди
			temp = temp->Prev;
		}
		delete a; // когда дошли, удаляем первый элемент, очищаем память
		a = temp; // теперь a - это ранее второй элемент очереди становится первым, и т.д.
		a->Prev = nullptr; // указатель бывшего второго элемента очищаем(удаляем), т.к. элемент на которой он указывал, был удален
	}
	k--; // уменьшаем счетчик элементов на 1
}

void queue_base::add(int user_value) {
	elem *temp = new elem; // Выделяем память для объекта структуры elem.
	if (k == 0) { // если в очереди 0 элементов 
		temp->Val = user_value; // то присваиваем в поле Val переменной temp значение, введенное с клавиатуры
		temp->Prev = nullptr; // в указатель на предыдущий присваиваем значение нулевого указателя, т.к. элемент всего 1
		a = temp; // переменные а и б отвечают за первый и последний элемент в очереди, т.к. в очереди 1 элемент, то он является одновременно первым и последним
		b = temp; // temp - "временный" объект структуры присваюващий значения полям базового класса
	}
	else {
		temp->Val = user_value; // т.к. это не первый элемент в очереди, в поле val присваиваем значение введенное с клавиатуры
		temp->Prev = b; // в поле prev присваиваем значение указателя на предыдущий элемент
		b = temp; // значение и адрес "временной" переменной присваим объекту б, т.е. указатель объекта б теперь имеет указатель на передстоящий элемент в очереди
	}
	k++; // увеличиваем счетчик элементов очереди
}

void queue_base::print_queue() {
	if (!k) { // защиита, если элементов в очереди нет
		cout << "Очередь пуста!" << endl; 
		return;
	}
	elem *temp = get_b(); //присваиваем значения последнего элемента (т.е. val и *prev) временному объекту структуры
	int *och = new int[get_k()]; // динамически выделяем память под количество элементов в очереди
	int l = get_k() - 1; // l - это индекс элементов в очереди
	for (int i = 0; i < get_k(); ++i) { // цикл выполняется пока не дойдет до первого элемента в очереди
		och[l--] = temp->Val;// 
							// с конца заполняем массив значениями очереди
		temp = temp->Prev; //
	}
	cout << "Текущая очередь:" << endl;
	for (int i = 0; i < get_k(); ++i) {
		cout << "[" << och[i] << "] ";
	}
	delete[] och; // очищаем память
}

void queue_base::calc() {
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

void queue_base::copy_queue(queue_base &op1) {
	elem *temp = b; //присваиваем значения последнего элемента (т.е. val и *prev) временному объекту структуры
	int *och = new int[k];// выделяем память под количество элементов в очереди
	int l = k - 1; // l - это индекс элементов в очереди
	for (int i = 0; i < k; ++i) {
		och[l--] = temp->Val; //
		temp = temp->Prev;   // с конца заполняем массив значениями очереди
	}						//
	for (l = 0; l < k; l++)
		op1.add(och[l]); // с помощью метода add(och[l]) (в качестве аргумента - это массив со значениями нашей текущей очереди (поле Val)) отправляем в объект на который ссылаемся
	delete[] och;
}

queue_base* queue_base::merge(queue_base *op1) {
	elem *temp = b;
	queue_base *j = new queue_base;
	int *och_i = new int[k];
	int *och_j = new int[k];
	int l = k - 1;
	for (int i = 0; i < k; ++i) {
		och_i[l--] = temp->Val;
		temp = temp->Prev;
	}
	temp = op1->b;
	l = k - 1;
	for (int i = 0; i < k; ++i) {
		och_j[l--] = temp->Val;
		temp = temp->Prev;
	}
	for (int i = 0; i < k; ++i)
		j->add(och_i[i]);
	for (int i = 0; i < k; ++i)
		j->add(och_j[i]);
	delete[] och_i;
	delete[] och_j;
	och_i = nullptr;
	och_j = nullptr;
	return j;
}

elem *queue_base::get_a() {
	return a;
}

elem *queue_base::get_b() {
	return b;
}

int queue_base::get_k() {
	return k;
}

void queue_base::set_k(int num) {
	k = num;
}

void queue_base::set_a(elem *Val) {
	a = Val;
}

void queue_base::set_b(elem *Val) {
	b = Val;
}
