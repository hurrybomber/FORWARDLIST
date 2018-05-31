#include <iostream>
#include "ForwardList.hpp"
using namespace std;

auto ForwardList::printlist() const -> void 
{
	Node* p = first;
	while (p->next != nullptr) {
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << p->data << endl;
}
auto ForwardList::insert(int n) -> void {
	Node* p = first;
	if (p == nullptr) {
		this->first = new Node{ n, nullptr };
	}
	else {
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new Node{ n,nullptr };
	}
}

auto ForwardList::removefirst(int n) -> bool {
	bool indicator = false;
	Node* p = first;
	if (p == nullptr) cout << "Список пуст" << endl;
	else {
		if (first->data == n) {
			first = first->next;
			indicator = true;
			delete p;
			p = first;
		}
		if (p != nullptr)
			while ((p->next != nullptr) && (!indicator)) {
				if (p->next->data == n) {
					if (p->next->next == nullptr) {
						delete p->next;
						p->next = nullptr;
					}
					else {
						Node* q = p->next;
						p->next = p->next->next;
						delete q;
					}
					indicator = true;
				}
				if (p->next != nullptr) p = p->next;
			}
	}
	return indicator;
}

auto ForwardList::empty_list() const -> bool {
	if (this->first == nullptr) return true;
	else return false;
}

auto ForwardList::search(int value) const -> bool {
	bool indicator = false;
	int number = 0;
	Node* p = first;
	while (p != nullptr) {
		if (p->data == value) {
			indicator = true;
			cout << number << " ";
		}
		p = p->next;
		number++;
	}
	return indicator;
}

auto ForwardList::replacement(int position, int value) const -> bool {
	int i = 0;
	Node* p = first;
	while ((i != position) && (p != nullptr)) {
		p = p->next;
		i++;
	}
	if (p == nullptr)
		return false;
	else {
		p->data = value;
		return true;
	}
}

auto ForwardList::sort() -> void {
	Node* p = first;
	int number = 0;
	while (p != nullptr) {
		number++;
		p = p->next;
	}
	p = first;
	int* array = new int[number];
	for(unsigned int i = 0; i < number; i++) {
		array[i] = p->data;
		p = p->next;
	}
	for (unsigned int i = 0; i < number - 1; i++) {
		for (unsigned int j = 0; j < number - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
	p = first;
	for (unsigned int i = 0; i < number; i++) {
		p->data = array[i];
		p = p->next;
	}
	delete[] array;
}

void print_menu() {
	cout << "1.Распечатать список" << endl
		 << "2.Добавить элементы в список" << endl
		 << "3.Удалить элемент" << endl
		 << "4.Найти позиции элементов" << endl
		 << "5.Заменить элемент на другой" << endl
		 << "6.Отсортировать элементы списка" << endl
		 << "7.Завершить работу программы" << endl;
}