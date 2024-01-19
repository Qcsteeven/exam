#include "BinarySearchTree.h"
#include <iostream>
#include <queue>
int BST::Size() { return size_; }

void BST::Insert(int key) {
  if (root_ == nullptr) {
    auto new_node = new Node{key};
    new_node->right = nullptr;
    new_node->left = nullptr;
    root_ = new_node;
    size_++;
    return;
  }
  Node* runner = root_;
  while (true) {
    if (key > runner->value) {
      if (runner->right) {
        runner = runner->right;
      } else {
        auto new_node = new Node{key};
        new_node->left = nullptr;
        new_node->right = nullptr;
        runner->right = new_node;
        size_++;
        return;
      }
    }
    if (key < runner->value) {
      if (runner->left) {
        runner = runner->left;
      } else {
        auto new_node = new Node{key};
        new_node->left = nullptr;
        new_node->right = nullptr;
        runner->left = new_node;
        size_++;
        return;
      }
    }
    if (key == runner->value) {
      return;
    }
  }
}

void BST::RemoveMin() {
  if (!root_) {
    return;
  }
  if (size_ == 1) {
    delete root_;
    root_ = nullptr;
    --size_;
    return;
  }
  Node* runner = root_;
  Node* parent = root_;
  if (runner->left) {
    runner = runner->left;
  } else {
    root_ = runner->right;
    delete runner;
    --size_;
    return;
  }
  while (true) {
    if (runner->left) {
      runner = runner->left;
      parent = runner->left;
      continue;
    }
    delete runner;
    parent->left = nullptr;
    --size_;
    return;
  }
}

int BST::GetMin() {
  if (!root_) {
    return -1;
  }
  if (!root_->left) {
    return root_->value;
  }
  Node* runner = root_;
  while (true) {
    if (runner->left) {
      runner = runner->left;
    } else {
      return runner->value;
    }
  }
}

void BST::RemoveMax() {
  if (!root_) {
    return;
  }
  if (size_ == 1) {
    delete root_;
    root_ = nullptr;
    --size_;
    return;
  }
  Node* runner = root_;
  Node* parent = root_;
  if (runner->right) {
    runner = runner->right;
  } else {
    root_ = runner->left;
    delete runner;
    --size_;
    return;
  }
  while (true) {
    if (runner->right) {
      runner = runner->right;
      parent = runner->right;
      continue;
    }
    delete runner;
    parent->right = nullptr;
    --size_;
    return;
  }
}

int BST::GetMax() {
  if (!root_) {
    return -1;
  }
  if (!root_->right) {
    return root_->value;
  }
  Node* runner = root_;
  while (true) {
    if (runner->right) {
      runner = runner->right;
    } else {
      return runner->value;
    }
  }
}

bool BST::Search(int key) {
  if (!root_) {
    return false;
  }
  Node* runner = root_;
  while (true) {
    if (key > runner->value) {
      if (runner->right) {
        runner = runner->right;
      } else {
        return false;
      }
    } else if (key < runner->value) {
      if (runner->left) {
        runner = runner->left;
      } else {
        return false;
      }
    } else if (key == runner->value) {
      return true;
    }
  }
}

BST::Node* BST::GetRoot() { return root_; }

BST::Node* BST::deleteNode(BST::Node* root, int key) {
  if (root == nullptr) {
    return root;
  };

  if (root->value > key) {
    root->left = deleteNode(root->left, key);
    return root;
  } else if (root->value < key) {
    root->right = deleteNode(root->right, key);
    return root;
  }

  if (root->left == nullptr) {
    Node* temp = root->right;
    --size_;
    delete root;
    return temp;
  } else if (root->right == nullptr) {
    Node* temp = root->left;
    --size_;
    delete root;
    return temp;
  }

  else {
    Node* succParent = root;
    Node* succ = root->right;
    while (succ->left != nullptr) {
      succParent = succ;
      succ = succ->left;
    }
    if (succParent != root) {
      succParent->left = succ->right;
    } else {
      succParent->right = succ->right;
    }
    root->value = succ->value;
    --size_;
    delete succ;
    return root;
  }
}

BST::Node* BST::find(int key) {
  if (!root_) {
    return nullptr;
  }
  Node* runner = root_;
  while (true) {
    if (key > runner->value) {
      if (runner->right) {
        runner = runner->right;
      } else {
        return nullptr;
      }
    } else if (key < runner->value) {
      if (runner->left) {
        runner = runner->left;
      } else {
        return nullptr;
      }
    } else if (key == runner->value) {
      return runner;
    }
  }
}

void BST::BFS() {
  if (!root_ ) {
    return;
  }

  std::queue<Node*> q;
  q.push(root_);

  while (!q.empty()) {
    Node* current = q.front();
    q.pop();
    std::cout << current->value << " ";

    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }
  }
}

void BST::InOrder(Node* node) {
  if (!node) {
    return;
  }
  InOrder(node->left);
  std::cout << node->value << ' ';
  InOrder(node->right);
} 

void BST::PreOrder(Node* node) {
  if (!node) {
    return;
  }
  std::cout << node->value << ' ';
  PreOrder(node->left);
  PreOrder(node->right);
}

void BST::PostOrder(Node* node) {
  if (!node) {
    return;
  }
  PreOrder(node->left);
  PreOrder(node->right);
  std::cout << node->value << ' ';
}