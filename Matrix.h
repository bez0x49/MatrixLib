/**
 * @file Matrix.h
 * @author bez0x49 (bez0x49@github.com)
 * @brief Implementation class Matrix
 * @version 0.1
 * @date 2020-11-01
 *
 * @copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Error.h"
#include "Vector.h"

/**
 * @brief Implementation class Matrix,
 *        which is based on a pointer to a class Vector
 *
 */
class Matrix {
public:
  /**
   * @brief Constructor without parameters. Allocates memory for the vector
   * for 5 elements, for the matrix allocates memory for 5 vectors
   * and initializes elements to zero.
   *
   */
  Matrix();

  /**
   * @brief Construct with a parameter. Allocates memory for the vector
   *        for n elements, for the matrix allocates memory for n vectors
   *        and initializes elements to zero.
   *
   * @param n The size of the matrix
   */
  Matrix(size_t n);

  /**
   * @brief Construct with 2 parameters. Allocates memory for the vector
   *        for m elements, for the matrix allocates memory for n vectors
   *        and initializes elements to zero.
   *
   * @param n Number of columns
   * @param m Number of rows
   * @param value The value of initialization
   */
  Matrix(size_t n, size_t m, double value);

  /**
   * @brief Copy constructor
   *
   * @param other Initialized Matrix
   */
  Matrix(const Matrix &src);

  /**
   * @brief Destroy the Matrix object.
   *        Free allocated memory
   *
   */
  ~Matrix();

  /**
   * @brief Assignment operator
   *
   * @param src Initialized matrix
   * @return Matrix
   */
  Matrix &operator=(const Matrix &src);

  /**
   * @brief Prints elements of matrix to the console
   */
  void Print() const;

  /**
   * @brief Set the value by indexs
   *
   * @param i Index of row
   * @param j Index of column
   * @param value Value ​​for initialization
   */
  void SetValueByIndex(size_t i, size_t j, double value);

  /**
   * @brief Get the value by indexs
   *
   * @param i Index of row
   * @param j Index of column
   * @return Element
   */
  double GetValueByIndex(size_t i, size_t j) const;

  /**
   * @brief Add 2 matrices
   *
   * @param other Initialized matrix
   * @return Sum of 2 matrices
   */
  Matrix Add(const Matrix &other);

  /**
   * @brief Substract 2 matrices
   *
   * @param other Initialized matrix
   * @return Difference of 2 matrices
   */
  Matrix Substract(const Matrix &other);

  /**
   * @brief Divide marix by divisor
   *
   * @param divisor Value to divide
   * @return Matrix
   */
  Matrix DivideBy(const int divisor);

  /**
   * @brief Multiply 2 matrices
   *
   * @param other Initialized matrix
   * @return Product of 2 matrices
   */
  Matrix Multiply(const Matrix &other);

  /**
   * @brief Find the sum of matrix elements
   *
   * @return Sum of elements
   */
  double Sum() const;

  /**
   * @brief Checks if the matrix is ​​larger than the other.
   *        If the dimensions of the matrix are different, compare the sums of
   *        their elements
   * @param other Initialized matrix
   * @return The first matrix is ​​larger than the second
   */
  bool islarger(const Matrix &other) const;

  /**
   * @brief Checks if the matrix is ​​smaller than the other
   *        If the dimensions of the matrix are different, compare the sums of
   *        their elements
   * @param other Initalized matrix
   * @return The first matrix is ​​smaller than the second
   */
  bool issmaller(const Matrix &other) const;

  /**
   * @brief Checks whether matrices are not equal.
   *        If the sizes of matrices are not equal returns true,
   *        otherwise checks each element
   *
   * @param other Initialized matrix
   * @return Matrices are not equal
   */
  bool isnotequal(const Matrix &other) const;

private:
  /**
   * @brief Checks whether the index does not go beyond
   *
   * @exception If index goes outside, it causes an exception
   * @throw std::out_of_range
   *
   * @param i Index of row
   * @param j Index of column
   */
  void verifyIndex(size_t i, size_t j) const;

  // Number of vectors
  size_t size;
  // Vectors of Matrix
  Vector **ptr;
  // Error status
  mutable Error status{Error::No};
};