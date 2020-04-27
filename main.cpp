#include <iostream>
#include <conio.h>
#include <windows.h>
#include "queue_base.h"
#include "queue_protected.h"
#include "queue_public.h"
#include "queue_private.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	queue_base base; // объект базового класса queue_base 
	queue_base base_copy; // копия-объект базового класса queue_base 
	queue_base base_merge; // объект-слияние базового класса queue_base
	queue_private priv; // объект класса наследника с модификатором доступа private
	queue_public publ; // объект класса наследника с модификатором доступа public
	queue_protected prot; // объект класса наследника с модификатором доступа protected
	int user_value = 0; // переменная-число, отвечающая за добавление в очередь
	char menu_choice; // переменная-символ отвечающая за выбор в меню
	char submenu_choice; // переменная-символ отвечающая за выбор в подменю
	do
	{
		system("cls");
		cout <<" Выберете функцию:"<< endl;
		cout << "[1] Добавление в очередь" << endl;
		cout << "[2] Исключение элемента из очереди" << endl;
		cout << "[3] Вывод на экран текщей очереди" << endl;
		cout << "[4] Нахождение последнего элемента, меньшего среднего арифметического" << endl;
		cout << "[5] Создание копии очереди" << endl;
		cout << "[6] Слияние очередей (при наличии копии)" << endl;
		cout << "[7] Выход из программы\nВаш выбор: ";
		cin >> menu_choice;
		switch (menu_choice) {
		case '1':
			system("cls");
			base.set_a(base.get_a()); // вызоваем сеттер объекта базового класса и инициализируем значением, полученым с помощью геттера
			base.set_b(base.get_b()); // вызоваем сеттер объекта базового класса и инициализируем значением, полученым с помощью геттера
			cout << "Введите элемент:\n=>";
			cin >> user_value;
			base.add(user_value); // добавляем в очередь значение введенное с клавиатуры, с помощью метода add(user_value)
			break;
		case '2':
			system("cls");
			base.set_a(base.get_a()); 
			base.set_b(base.get_b()); 
			base.del(); // с помощью метода базового класса del() удаляем первый элемент очереди
			cout << "Исключение успешно!" << endl;
			system("Pause");
			break;
		case '3':
			system("cls");
			base.set_a(base.get_a()); 
			base.set_b(base.get_b()); 
			base.print_queue(); // с помощью метода базового класса print_queue() выводим на экран текущую очередь
			cout << "\n";
			system("Pause");
			break;
		case '4':
			base.set_a(base.get_a());
			base.set_b(base.get_b());
			if (!base.get_k())
			{
				cout << "Очередь пуста!\n"; system("Pause");
				break;
			}
			system("cls");
			cout << "Выберите модификатор доступа:" << endl;
			cout << "[1] Private." << endl;
			cout << "[2] Protected." << endl;
			cout << "[3] Public." << endl;
			cout << "[4] Выход." << endl;
			cout << "=> ";
			cin >> submenu_choice;
			cout << "\n";
			switch (submenu_choice) {
			case '1':
				priv.new_a(base.get_a());
				priv.new_b(base.get_b());
				priv.new_k(base.get_k());
				priv.print();
				priv.calc();
				break;
			case '2':
				prot.new_a(base.get_a());
				prot.new_b(base.get_b());
				prot.new_k(base.get_k());
				prot.print();
				prot.calc();
				break;
			case '3':
				publ.set_a(base.get_a());
				publ.set_b(base.get_b());
				publ.new_k(base.get_k());
				publ.print();
				publ.calc();
				break;
			case '4':
				break;
			}
			system("Pause");
			break;
		case '5':
			system("cls");
			base.set_a(base.get_a());
			base.set_b(base.get_b());
			base.copy_queue(base_copy); // с помощью метода copy_queue(base_copy) (в качестве параметра указан объект базового типа) создаем копию текущей очереди
			cout << "Копия создана: ";
			base_copy.print_queue();
			system("Pause");
			break;
		case '6':
			system("cls");
			base.set_a(base.get_a());
			base.set_b(base.get_b());
			base_merge = *base.merge(&base_copy);
			base_merge.print_queue();
			system("Pause");
			break;
		case '7':
			menu_choice = 7;
			break;
		default:
			break;
		}
	} while (menu_choice != 7);
	return 0;
}