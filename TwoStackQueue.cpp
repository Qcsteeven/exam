#include <iostream>
#include <string>

// TODO: Очередь на двух стеках.

class Stack {
  struct Node {
    int value;

    Node *next;
  };

  int size_ = 0;

  Node *head = nullptr;

 public:
  int Pop() {
    if (size_ == 0) {
      return -1;
    }

    if (size_ == 1) {
      int ans = head->value;

      delete head;

      head = nullptr;

      size_--;

      return ans;
    }

    int ans = head->value;

    Node *tmp = head;

    head = head->next;

    delete tmp;

    size_--;

    return ans;
  };

  void Push(int key) {
    if (size_ == 0) {
      auto new_node = new Node{key};

      head = new_node;

      size_++;

      return;
    }

    auto new_node = new Node{key};

    new_node->next = head;

    head = new_node;

    size_++;
  };

  int Size() { return size_; };

  ~Stack() {
    for (int i = 0; i < size_; ++i) {
      Pop();
    }
  }
};

class TwoStackQueue {
  Stack InOrder;

  Stack OutOrder;

 public:
  void Input(int key) { InOrder.Push(key); };

  int Output() {
    if (OutOrder.Size() == 0) {
      if (InOrder.Size() == 0) {
        return -1;  // Очередь пуста
      }

      while (InOrder.Size() > 0) {
        OutOrder.Push(InOrder.Pop());
      }
    }

    return OutOrder.Pop();
  };

  int Size() { return InOrder.Size() + OutOrder.Size(); };
};

int main() {
  TwoStackQueue bebra;

  while (true) {
    std::cout << "Welcum to the cum zone! Only cum inside TwoStackQueue. "
                 "Choose anal mod: add, erase, exit"
              << "\n";

    std::string input;

    std::cin >> input;

    if (input == "add") {
      std::cout << "Please enter the value you need to add"
                << "\n";

      int value;

      std::cin >> value;

      bebra.Input(value);
    }

    if (input == "erase") {
      std::cout << "This value going to naher: ";

      std::cout << bebra.Output() << "\n";
    }

    if (input == "size") {
      std::cout << bebra.Size() << "\n";
    }

    if (input == "exit") {
      std::cout << "Bye!";

      return 0;
    }
  }
}