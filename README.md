# Matrix Lib

The library implements several operations on matrices and also compares them. Matrices are implemented in dynamic memory of both the Vector class and pointers to double.

> Important!!!

1. Operator overloads are not implemented.
2. Use only for double data.
3. Some methods are not tested.

To get an element like in the two-dimensional array `A[i][j]` you need to call the method:

```c++
Matrix M;
M.GetValueByIndex(0, 3);
```

Similarly, if you want to assign:

```c++
M.SetValueByIndex(0, 3, 49.5);
```
