class BST {
 private:
  struct Node {
    int value;
    Node* left;
    Node* right;
  };

 public:
  void Insert(int key);
  void RemoveMin();
  int GetMin();
  void RemoveMax();
  int GetMax();
  int Size();
  bool Search(int key);
  void BFS();
  Node* GetRoot();
  Node* deleteNode(Node* root, int key);
  void InOrder(Node* node);
  void PreOrder(Node* node);
  void PostOrder(Node* node);

 private:
  Node* root_ = nullptr;
  int size_ = 0;
  Node* find(int key);
  int removeMin(Node* runner);
};
