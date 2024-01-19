#include "Heap.h"

void Heap::HeapSort() {
  int cur_size = size_;
  for (int i = 0; i < cur_size; ++i) {
    std::cout << extractMax() << " ";
  }
}

int Heap::extractMax() {
  int ans = arr_[0];
  swap(arr_[0], arr_[--size_]);
  arr_[size_] = 0;
  SiftDown(0);
  return ans;
}

void Heap::PopMax() {
  swap(arr_[0], arr_[--size_]);
  arr_[size_] = 0;
  SiftDown(0);
}

void Heap::Push(int value) {
  if (size_ + 1 > capacity_) {
    Resize();
  }
  arr_[size_] = value;
  SiftUp(size_++);
}

void Heap::Resize() {
  int* arr = new int[capacity_ * 2];
  for (int i = 0; i < size_; ++i) {
    arr[i] = arr_[i];
  }
  delete[] arr_;
  arr_ = arr;
}

void Heap::SiftUp(int index) {
  while (index > 0) {
    if (arr_[index] > arr_[Parent(index)]) {
      swap(arr_[index], arr_[Parent(index)]);
      index = Parent(index);
    } else {
      break;
    }
  }
}

void Heap::SiftDown(int index) {
  while (true) {
    int id_left = LeftChild(index);
    int id_right = RightChild(index);
    int id_max = index;  // Инициализируем id_max значением index

    if (id_left < size_ &&
        arr_[id_left] >
            arr_[id_max]) {  // Проверяем, что id_left в пределах размера кучи и
                             // его значение больше, чем у id_max
      id_max = id_left;  // Если условие выполняется, обновляем id_max
    }
    if (id_right < size_ &&
        arr_[id_right] >
            arr_[id_max]) {  // Проверяем, что id_right в пределах размера кучи
                             // и его значение больше, чем у id_max
      id_max = id_right;  // Если условие выполняется, обновляем id_max
    }

    if (id_max != index) {
      swap(arr_[index], arr_[id_max]);
      index = id_max;
    } else {
      break;
    }
  }
}

void Heap::Print() {
  for (int i = 0; i < size_; ++i) {
    std::cout << arr_[i] << " ";
  }
}

Heap::Heap(int* arr, int size) {
  arr_ = arr;
  size_ = size;
  for (int i = (size_ / 2) - 1; i >= 0; --i) {
    SiftDown(i);
  }
  for (int i = 0; i < size_; ++i) {
    SiftDown(i);
    if (i % 2 == 0) {
      capacity_ *= 2;
    }
  }
}

int Heap::Parent(int index) { return (index - 1) / 2; }
int Heap::LeftChild(int index) { return index * 2 + 1; }
int Heap::RightChild(int index) { return index * 2 + 2; }

void Heap::swap(int& a, int& b) {
  int temp = b;
  b = a;
  a = temp;
}