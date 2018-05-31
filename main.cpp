#include <iostream>
#include <algorithm>
#include <string>
#include "ForwardList.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	string sym_menu;
	char end, resume;
	setlocale(LC_ALL, "RUS");
	ForwardList list;
	int nom_argv = 2, value = 0, position = 0;
	bool indicator = false, indicator_input = false;
	if (argc == 1) {
		cout << "список пуст" << endl;
	}
	else 

		if (argc == 2) {
			char* argument = argv[1];
			while (1) {
				list.insert(atoi(argument));
				argument = strchr(argument, ',') + 1;
				if (!strchr(argument, ','))
					break;
			}
			list.insert(atoi(argument));

		}
	else
		for ( unsigned int i = 1; i < argc; i++) {
			list.insert(atoi(argv[i]));		
		}
	int ex = 0;
	while (ex != 1) {
		print_menu();
		int num_menu = 0;
		string menu, count;
		while (num_menu == 0)
		{
			getline(cin, menu);
			if (atoi(menu.c_str())) num_menu = atoi(menu.c_str());
			if(!(atoi(menu.c_str())) && (menu != "")) print_menu();
		}
		switch (num_menu) {
		case 1:
			if (list.empty_list()) cout << "список пуст" << endl;
			else list.printlist();
			break;
		case 2:
			cout << "Введите элементы:";
			for (;;) {
				indicator = 0;
				end = '1';
				resume = '1';
				while (cin) {
					cin >> value;
					if (!cin) {
						indicator = true;
						cin.clear();
					}
					if (!indicator) {
						list.insert(value);
					}
					cin.get(end);
					if (end == '\n') break;
				}
				if (indicator) {
					cout << "Ввод прерван: аргумент не число. Продолжить ввод?(type y/n):";
					cin >> resume;
					if (resume == 'n') break;
				}
				else break;
			}
			break;
		case 3:
			if (list.empty_list()) cout << "список уже пуст" << endl;
			else {
				cout << "Введите число для удаления" << endl;
				cin >> value;
				if (cin) 
					if (!list.removefirst(value)) 
						cout << "Элемент " << value << " отсутствует" << endl;
					else;
				else {
					cout << "Введено не число" << endl;
					cin.clear();
					cin.get();
				}
			}
			break;
		case 4:
			if (list.empty_list()) cout << "список пуст" << endl;
			else {
				cout << "Введите число для поиска:";
				cin >> value;
				if (!cin) {
					cout << "Введено не число";
					cin.clear();
					cout << endl;
					cin.get();
				}
				else
					if (!list.search(value))
						cout << "Элемент отсутствует" << endl;
					else
						cout << endl;
			}
			break;
		case 5:
			indicator_input = false;
			if (list.empty_list()) cout << "список пуст" << endl;
			else {
				cout << "Введите позицию и новое значение:";
				cin >> position;
				if (!cin) {
					cin.clear();
					cin.get();
					indicator_input = true;
				}
				cin >> value;
				if ((!cin) || (indicator_input)) {
					cout << "Введено не число для позиции или значения";
					cin.clear();
					cout << endl;
					cin.get();
				}
				else
					if (!list.replacement(position, value)) 
						cout << "Элемент с позицией " << position << " не существует" << endl;
			}
			break;
		case 6:
			if (list.empty_list()) cout << "список пуст" << endl;
			else {
				list.sort();
			}
			break;
		case 7:
			cout << "Вы точно хотите выйти? (y/n): ";
			cin >> sym_menu;
			if ((sym_menu == "y") || (sym_menu == "y") || (sym_menu == "yes") ||
				(sym_menu == "yes") || (sym_menu == "yes")) {
				ex = 1;
				cout << "До свидания!" << endl;
			}
			break;
		}
	}
	cin.get();
	cin.get();
}