/**
 * @file Vector.h
 * @author bez0x49 (bez0x49@github.com, nevedrb@gmail.com)
 * @brief Implementation class Matrix
 * @version 0.1
 * @date 2020-11-01
 *
 * @copyright Copyright (c) 2020
 *
 */
#pragma once

/**
 * @brief Implementation class Vector,
 *        which is based on a pointer to double
 *
 */
class Vector {
public:
  /**
   * @brief Construct with 2 parameters. Allocates memory for n elements
   *        and initializes elements to initializedValue.
   * @param n Vector length
   * @param value The value of initialization
   */
  Vector(size_t n, double value);

  /**
   * @brief Destroy the Vector object.
   *        Free allocated memory
   *
   */
  ~Vector();

  /**
   * @brief Prints elements of vector to the console
   *
   */
  void Print() const;

  /**
   * @brief Set the value to the element by index
   *
   * @param i Index of element
   * @param value Value ​​for initialization
   */
  void SetValueByIndex(size_t i, double value);

  /**
   * @brief Get the value of element by index
   *
   * @param i Index of element
   * @return Element
   */
  double GetValueByIndex(size_t i);

  /**
   * @brief Returns the number of elements in the vector
   *
   * @return Vector length
   */
  constexpr size_t len() const { return size; }

  /**
   * @brief Find the sum of vector elements
   *
   * @return Sum of elements
   */
  double Sum() const;

private:
  /**
   * @brief Checks whether the index does not go beyond
   *
   * @exception If index goes outside, it causes an exception
   * @throw std::out_of_range
   *
   * @param i Index
   */
  void verifyIndex(size_t i) const;

  // Elements of Vector
  double *ptr;
  // Vector length
  size_t size;
};