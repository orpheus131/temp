// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	Node* node = new Node(' ');
	homeNode = endNode = cursorNode = node;
  return;
}

void TypingMachine::HomeKey() {
	cursorNode = homeNode;
  return;
}

void TypingMachine::EndKey() {
	cursorNode = endNode;
  return;
}

void TypingMachine::LeftKey() {
	if (cursorNode != homeNode)	cursorNode = cursorNode->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
	if (cursorNode != endNode) cursorNode = cursorNode->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
	if (maxChar >= MAX_NODE) return false;

	if (32 <= key && key <= 126) {
		if (endNode == cursorNode->GetPreviousNode()) {
			cursorNode->InsertPreviousNode(key);
			endNode = cursorNode->GetPreviousNode();
		}
		else {		// Initial State
			cursorNode->InsertPreviousNode(key);
			if (cursorNode == endNode) {
				endNode = cursorNode;
			}
			if (cursorNode == homeNode) {
				homeNode = cursorNode->GetPreviousNode();
			}
		}

		maxChar++;
		return true;
	}

  return false;
}

bool TypingMachine::EraseKey() {
	if (maxChar <= 0) return false;

	if ((homeNode == endNode) && (endNode == cursorNode)) return false;
	if (cursorNode->GetPreviousNode() == homeNode) {
		homeNode = cursorNode;
		cursorNode->ErasePreviousNode();
		--maxChar;
		return true;
	}
	if (cursorNode != homeNode) {
		if (cursorNode->ErasePreviousNode()) {
			--maxChar;
			return true;
		}
	}
	return false;
}

std::string TypingMachine::Print(char separator) {
	line_buf = "";

	if ((homeNode == endNode) && (endNode == cursorNode) && (separator != 0)) {
		line_buf += separator;
		return (line_buf);
	}
	if ((cursorNode == homeNode) && (separator != 0)) line_buf += separator;

	for (Node* i = this->homeNode; i != endNode; i = i->GetNextNode()) {
			line_buf += i->GetData();
			if ((i == cursorNode->GetPreviousNode()) && (separator != 0)) line_buf += separator;

	}
	
  return (line_buf);
}
