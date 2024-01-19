#include <iostream>

class List {
  int size_ = 0;

  struct Node {
    int value;

    Node *next = nullptr;
  };

  Node *head = nullptr;

  Node *tail = nullptr;

 public:
  void PushBack(int key) {
    // TODO: Вставить элемент в конец списка

    size_ += 1;

    if (head == nullptr) {
      auto new_node = new Node{key};

      head = new_node;

      tail = new_node;

      return;
    }

    tail->next = new Node{key};

    tail = tail->next;
  };

  void PushFront(int key) {
    // TODO: Вставить элемент в начало списка

    size_ += 1;

    if (head == nullptr) {
      auto new_node = new Node;

      head = new_node;

      tail = new_node;

      new_node->value = key;

      return;
    }

    auto new_node = new Node{key};

    new_node->next = head;

    head = new_node;
  };

  void PopBack() {
    // TODO: Удалить элемент в конце списка

    if (size_ == 0) {
      return;
    }

    if (size_ == 1) {
      size_ -= 1;

      delete head;

      tail = nullptr;

      return;
    }

    Node *runner = head;

    while (runner->next != tail) {
      runner = runner->next;
    }

    runner->next = nullptr;

    delete tail;

    size_ -= 1;

    return;
  };

  void PopFront() {
    // TODO: Удалить элемент в начале списка

    if (size_ == 0) {
      return;
    }

    if (size_ == 1) {
      size_ = size_ - 1;

      delete head;

      tail = nullptr;

      return;
    }

    auto tmp = head->next;

    delete head;

    head = tmp;

    size_ -= 1;

    return;
  };

  int Size() { return size_; };

  ~List() {
    int size = size_;

    for (int i = 0; i < size; ++i) {
      PopFront();
    }

    size_ = 0;
  }

  void Print() {
    if (size_ == 0) {
      std::cout << "Empty list!\n";

      return;
    }

    auto runner = head;

    while (runner) {
      std::cout << runner->value << " ";

      if (runner->next) {
        runner = runner->next;

      }

      else {
        return;
      }
    }
  }

  void Add(int new_value, int idx) {
    --idx;

    if (size_ == 0) {
      return;
    }

    if (size_ < idx) {
      return;
    }

    if (size_ == 1) {
      PushBack(new_value);

      return;
    }

    if (size_ - 1 == idx) {
      PushBack(new_value);

      return;
    }

    auto runner = head;

    while (idx > 0) {
      --idx;

      runner = runner->next;
    }

    auto new_node = new Node{new_value};

    new_node->next = runner->next;

    runner->next = new_node;

    ++size_;
  }

  void Remove(int idx) {
    --idx;

    if (size_ == 0) {
      return;
    }

    if (size_ < idx) {
      return;
    }

    if (size_ == 1) {
      return;
    }

    if (size_ - 1 == idx) {
      PopBack();

      return;
    }

    auto runner = head;

    while (idx > 0) {
      --idx;

      runner = runner->next;
    }

    auto temp = runner->next->next;

    delete runner->next;

    runner->next = temp;

    --size_;
  }
};

int main() {
  std::cout << "Welcum to the user interface to test this shit\n";

  std::cout << "Enter the \"end\" if you want to end testing\n";

  List fll;

  while (true) {
    std::cout

        << "Choose command(addfr, addbk, popfr, popbk, size, find, print, "
           "get_max, get_min): ";

    std::string command;

    std::cin >> command;

    if (command == "addfr") {
      std::cout << "Enter the number: ";

      int value;

      std::cin >> value;

      fll.PushFront(value);

    }

    else if (command == "addbk") {
      std::cout << "Enter the number: ";

      int value;

      std::cin >> value;

      fll.PushBack(value);

    }

    else if (command == "popfr") {
      std::cout << "OK ";

      fll.PopFront();

    }

    else if (command == "popbk") {
      std::cout << "OK ";

      fll.PopBack();

    }

    else if (command == "ADD") {
      int value;

      int idx;

      std::cin >> value;

      std::cin >> idx;

      fll.Add(value, idx);

    }

    else if (command == "REMOVE") {
      int idx;

      std::cin >> idx;

      fll.Remove(idx);

    }

    else if (command == "size") {
      std::cout << fll.Size() << '\n';

    }

    else if (command == "print") {
      fll.Print();

      std::cout << '\n';

    }

    else if (command == "end") {
      std::cout << "It's your result:\n";

      fll.Print();

      break;
    }
  }
}