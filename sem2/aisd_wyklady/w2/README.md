# Insertion sort

Problem: sorting an array using insertion sort

Algorithm: insertion sort

The array is virtually split into a sorted and an unsorted part.

Values from the unsorted part are picked and placed at the correct position in the sorted part.

Pseudocode/method:

```

Array = [9, 5, 1, 4, 3]

How it will look:

1. 5 9 | 1 4 3
2. 1 5 9 | 4 3
3. 1 4 5 9 | 3
4. 1 3 4 5 9 |

To reach (1), we compare 5 with 9, we swap them and move on since there are no more numbers to compare with.

On the next iteration, 1 becomes our key - first, we compare it with 9 - it's smaller, we swap them, and there are more numbers to compare with [1], so we move further. 1 (key) is smaller than 5 too, we swap them, and since there are no more numbers to compare with, we move on.

Outer loop: key, up to n - 1
Inner loop: one less than key, up to -1, break statement - [1]

After switching two array elements, we also need to change the key, because we have to move down the array with checking.

```

Output: sorted array
