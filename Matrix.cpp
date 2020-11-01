#include "stdafx.h"
#include "Matrix.h"

Matrix::Matrix(size_t n, size_t m, double value) : size(n) {
  ptr = new Vector *[size];
  if (ptr == nullptr) {
    status = Error::Memory;
    return;
  }

  for (size_t i = 0; i < size; i++) {
    ptr[i] = new Vector(m, value);
    if (ptr[i] == nullptr) {
      status = Error::Memory;
      return;
    }
  }
}

Matrix::Matrix(size_t n) : Matrix(n, n, 0) {}

Matrix::Matrix() : Matrix(5, 5, 0) {}

Matrix::~Matrix() {
  for (size_t i = 0; i < size; i++) {
    delete ptr[i];
  }
  delete[] ptr;
}

void Matrix::Print() const {
  status = Error::No;
  for (size_t i = 0; i < size; i++)
    ptr[i]->Print();
  std::cout << std::endl;
}

void Matrix::verifyIndex(size_t i, size_t j) const {
  if (i >= size && (*ptr)->len() <= j) {
    status = Error::Range;
    throw std::out_of_range("Out of range");
  }
}

void Matrix::SetValueByIndex(size_t i, size_t j, double value) {
  verifyIndex(i, j);
  ptr[i]->SetValueByIndex(j, value);
}

double Matrix::GetValueByIndex(size_t i, size_t j) const {
  verifyIndex(i, j);
  ptr[i]->GetValueByIndex(j);
}

Matrix Matrix::Add(const Matrix &other) {
  if (size != other.size && (*ptr)->len() != (*other.ptr)->len())
    return Matrix{};

  Matrix sum(size, (*ptr)->len(), 0);

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < (*ptr)->len(); j++) {
      sum.SetValueByIndex(i, j,
                          GetValueByIndex(i, j) + other.GetValueByIndex(i, j));
    }
  }
}

Matrix Matrix::Substract(const Matrix &other) {
  if (size != other.size && (*ptr)->len() != (*other.ptr)->len())
    return Matrix{};

  Matrix sum(size, (*ptr)->len(), 0);

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < (*ptr)->len(); j++) {
      sum.SetValueByIndex(i, j,
                          GetValueByIndex(i, j) - other.GetValueByIndex(i, j));
    }
  }

  return sum;
}

Matrix Matrix::DivideBy(const int divisor) {
  if (divisor == 0)
    return *this;

  Matrix div(size, (*ptr)->len(), 0);

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < (*ptr)->len(); j++) {
      div.SetValueByIndex(i, j, GetValueByIndex(i, j) / divisor);
    }
  }

  return div;
}

Matrix Matrix::Multiply(const Matrix &other) {
  if ((*ptr)->len() != other.size)
    return *this;

  Matrix product((*ptr)->len(), size, 0);

  for (size_t i = 0; i < (*ptr)->len(); i++) {
    for (size_t j = 0; j < size; j++) {
      double sum = 0;
      for (size_t k = 0; k < size; k++) {
        sum += GetValueByIndex(i, k) + other.GetValueByIndex(k, j);
      }
      product.SetValueByIndex(i, j, sum);
    }
  }

  return product;
}

double Matrix::Sum() const {
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += ptr[i]->Sum();
  }

  return sum;
}

bool Matrix::islarger(const Matrix &other) const { return Sum() > other.Sum(); }

bool Matrix::issmaller(const Matrix &other) const { return Sum() < Sum(); }

bool Matrix::isnotequal(const Matrix &other) const {
  if (size != other.size)
    return true;
  if ((*ptr)->len() != (*other.ptr)->len())
    return true;

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < (*ptr)->len(); j++) {
      if (GetValueByIndex(i, j) != other.GetValueByIndex(i, j))
        return true;
    }
  }

  return false;
}
