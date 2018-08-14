// Copyright 2018 <Author>

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"

#define MAX_NODE 100

class TypingMachine {
private:
	Node* homeNode;
	Node* endNode;
	Node* cursorNode;
	std::string line_buf;
	int maxChar = 0;


 public:
  TypingMachine();
  void HomeKey();
  void EndKey();
  void LeftKey();
  void RightKey();
  bool TypeKey(char key);
  bool EraseKey();
  std::string Print(char separator);
};

#endif  // TYPING_MACHINE_H_
