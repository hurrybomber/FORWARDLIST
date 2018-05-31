#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
};

class ForwardList {
	Node* first;
public:
	ForwardList() : first{ nullptr } {}

	ForwardList(Node* node_) : first{ node_ } {}

	auto insert(int) -> void;

	auto printlist() const -> void;
	
	auto removefirst(int) -> bool;

	auto search(int) const -> bool;

	auto empty_list() const -> bool;

	auto replacement(int, int) const -> bool;

	auto sort() -> void;
	
	~ForwardList() {
		while (first != nullptr) {
			Node* p = first;
			first = first->next;
			delete p;
		}
	}
};

void print_menu();