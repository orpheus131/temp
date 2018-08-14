// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	this->next = nullptr;
	this->prev = nullptr;
	this->value = data;

  return;
}

char Node::GetData() {
		return value;
}

Node* Node::GetPreviousNode() {
	if (this->prev != nullptr) {
		return prev;
	}
	else return nullptr;
}

Node* Node::GetNextNode() {
	if (this->next != nullptr) {
		return next;
	}
	else return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node* temp_node = new Node(data);

	if (this->prev != nullptr) {
		temp_node->next = this;
		temp_node->prev = this->prev;
		this->prev->next = temp_node;
	}
	else {
		temp_node->next = this;
		temp_node->prev = nullptr;

	}
	this->prev = temp_node;
	return temp_node;
}

Node* Node::InsertNextNode(char data) {
	Node* temp_node = new Node(data);
	if (this->next != nullptr) {
		temp_node->prev = this;
		temp_node->next = this->next;
		this->next->prev = temp_node;
	}
	else {
		temp_node->next = nullptr;
		temp_node->prev = this;
	}
	this->next = temp_node;
	return temp_node;

}

bool Node::ErasePreviousNode() {
	if (this->prev != nullptr) {
		Node* temp_node = this->prev;
		//this->prev = temp_node->prev;
		if (temp_node->prev != nullptr) {
			this->prev = temp_node->prev;
			temp_node->prev->next = this;
		}
		else { this->prev = nullptr; }
		delete temp_node;
		return true;
	}
  return false;
}

bool Node::EraseNextNode() {
	if (this->next != nullptr) {
		Node* temp_node = this->next;
		//this->next = temp_node->next;
		if (temp_node->next != nullptr) {
			this->next = temp_node->next;
			temp_node->next->prev = this;
		}
		else { this->next = nullptr; }
		delete temp_node;
		return true;
	}

  return false;
}
