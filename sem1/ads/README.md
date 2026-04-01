# Advanced Data Structures (ADS) Lab

This directory contains the implementations of various advanced data structures and algorithms as part of the **CET MCA Semester 1** curriculum. Each implementation is designed for clarity, efficiency, and educational value.

## 📋 Table of Contents
| Experiment | File | Description |
| :--- | :--- | :--- |
| **1. Linked Lists** | [singly_linked_list.c](./singly_linked_list.c) | Basic insertion, deletion, and traversal. |
| | [doubly_linked_list.c](./doubly_linked_list.c) | Bidirectional navigation and manipulation. |
| | [double_ended_list.c](./double_ended_list.c) | Managing nodes from both ends. |
| **2. Stacks & Queues** | [stack.c](./stack.c) | Array-based stack (LIFO) implementation. |
| | [stack_using_list.c](./stack_using_list.c) | Dynamic stack using linked lists. |
| | [queue.c](./queue.c) | Standard FIFO queue implementation. |
| | [circular_queue.c](./circular_queue.c) | Efficient memory usage with circular buffers. |
| **3. Trees & Graphs** | [bst.c](./bst.c) | Binary Search Tree (Insertion, Search, Traversal). |
| | [bfs.c](./bfs.c) | Breadth-First Search graph traversal. |
| | [dfs.c](./dfs.c) | Depth-First Search graph traversal. |
| | [topological_sorting.c](./topological_sorting.c) | Ordering tasks with dependencies. |
| **4. Algorithms** | [kruskal_algorithm.c](./kruskal_algorithm.c) | Minimum Spanning Tree using Greedy approach. |
| | [prims_algorithm.c](./prims_algorithm.c) | Alternative MST implementation. |
| **5. Operations** | [array.c](./array.c) | Basic array manipulation and search. |
| | [bit_string.c](./bit_string.c) | Bitwise set representation and operations. |
| | [set_opration.c](./set_opration.c) | Union, Intersection, and Difference of sets. |

---


## 📝 Notes & Best Practices
- Always check the return value of malloc and free memory after use.
- Use descriptive variable and function names for clarity.
- Add comments for complex logic and edge cases.
- Test your code with different input cases, including edge cases.
- For large graphs or lists, check for stack/queue overflow.

## 📊 Sample Output (Example)
```
$ gcc stack.c -o stack
$ ./stack
--- Stack Operations ---
1. Push
2. Pop
3. Display
4. Exit
Choice: 1
Enter value: 10
Pushed 10 onto stack.
... (rest of output)
```

## 🛠 Compilation and Execution
To compile any experiment, use the `gcc` compiler:
```bash
gcc filename.c -o output
./output
```

## 📚 Syllabus Alignment
These programs are aligned with the **Lab-MCA105: Advanced Data Structures Lab** syllabus for students at the **College of Engineering Trivandrum**.

----
*Maintained by Ajmal UK.*
