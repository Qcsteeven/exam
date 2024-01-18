#include <iostream>

#include "BinarySearchTree.cpp"

int main() {
  BST tree;
  while (true) {
    std::string str;
    std::cout
        << "Enter commmand(insert, get_min, remove_min, get_max,\n"
           "remove_max, size, erase, bfs, in-order, pre-order, post-order): ";
    std::cin >> str;
    if (str == "insert") {
      std::cout << "value: ";
      int value;
      std::cin >> value;
      tree.Insert(value);
    } else if (str == "get_min") {
      std::cout << (tree.GetMin()) << '\n';
    } else if (str == "remove_min") {
      tree.RemoveMin();
    } else if (str == "get_max") {
      std::cout << (tree.GetMax()) << '\n';
    } else if (str == "remove_max") {
      tree.RemoveMax();
    } else if (str == "size") {
      std::cout << tree.Size() << '\n';
    } else if (str == "search") {
      std::cout << "value: ";
      int value;
      std::cin >> value;
      if (tree.Search(value)) {
        std::cout << "Yes\n";
      } else {
        std::cout << "No\n";
      }
    } else if (str == "erase") {
      std::cout << "value: ";
      int value;
      std::cin >> value;
      tree.deleteNode(tree.GetRoot(), value);
    } else if (str == "bfs") {
      tree.BFS();
      std::cout << '\n';
    } else if (str == "in-order") {
      tree.InOrder(tree.GetRoot());
      std::cout << '\n';
    } else if (str == "pre-order") {
      tree.PreOrder(tree.GetRoot());
      std::cout << '\n';
    } else if (str == "post-order") {
      tree.PostOrder(tree.GetRoot());
      std::cout << '\n';
    } else if (str == "end") {
      return 0;
    }
  }
}