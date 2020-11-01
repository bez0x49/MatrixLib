#include "stdafx.h"
#include "Vector.h"

Vector::Vector(size_t n, double value) : size(n) {
  ptr = new double[size];
  if (ptr == nullptr)
    return;

  for (size_t i = 0; i < size; i++)
    ptr[i] = value;
}

Vector::~Vector() { delete[] ptr; }

void Vector::Print() const {
  for (size_t i = 0; i < size; i++)
    std::cout << ptr[i] << ' ';
  std::cout << std::endl;
}

void Vector::SetValueByIndex(size_t i, double value) {
  verifyIndex(i);
  ptr[i] = value;
}

double Vector::GetValueByIndex(size_t i) {
  verifyIndex(i);
  return ptr[i];
}

double Vector::Sum() const {
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += ptr[i];
  }

  return sum;
}

void Vector::verifyIndex(size_t i) const {
  if (i >= size)
    throw std::out_of_range("Out of range");
}