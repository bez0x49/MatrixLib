/**
 * @file Error.h
 * @author bez0x49 (bez0x49@github.com, nevedrb@gmail.com)
 * @brief Implementation error status
 * @version 0.1
 * @date 2020-11-01
 *
 * @copyright Copyright (c) 2020
 *
 */
#pragma once

/**
 * @brief Lists with possible error during programme execute
 *
 */
enum Error {
  // No error, everything is fine! Just enjoy!
  No,
  // Occurs when memory isn't allocated
  Memory,
  // Occurs when the index passed to the method extends beyond the arrays
  Range,
  // Occurs when the matrix is ​​divisible by zero
  Zero
};