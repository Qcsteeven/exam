class Heap {
 public:
  Heap(int* arr, int size);
  void SiftUp(int index);
  void SiftDown(int index);
  void Push(int value);
  void PopMax();
  void Print();
  void HeapSort();

  int Parent(int index);
  int LeftChild(int index);
  int RightChild(int index);
  void Resize();

 private:
  int* arr_;
  int size_ = 0;
  int capacity_ = 1;
  void swap(int& a, int& b);
  int extractMax();
};