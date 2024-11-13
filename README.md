
# Push Swap

## Language
- [Français Version](./readme_fr.md)
- [한국어 Version](./readme_kr.md)

## Table of Contents

  - [Introduction](#introduction)
  - [Feature](#feature)
  - [Data Strucure](#data-structure)
  - [Algorithm](#algorithm)
  - [Functions List](#functions-list)
  - [Bonus](#bonus)
 

## Introduction

**Push Swap** is a C project that involves creating a program to sort a stack of integers using a minimal number of operations. The operations available are `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`. The goal of this project is to develop an efficient algorithm for sorting, understanding stack-based operations, and improving problem-solving skills. The sorting algorithm must be as optimized as possible, and no more than the required number of operations should be used.

By completing **Push Swap**, you'll learn about stack data structures, the importance of algorithm optimization, and gain experience in problem-solving and performance tuning.


## Feature

- Implements a sorting algorithm using stack-based operations.
- Provides an optimized solution for sorting integers.
- Includes a set of operations (`sa`, `sb`, `pa`, `pb`, etc.) to manipulate the stacks.

## Functions List

- `push_swap` - Main program that solves the sorting problem.
- `sa` - Swap the top two elements of stack A.
- `sb` - Swap the top two elements of stack B.
- `pa` - Push the top element from stack B to stack A.
- `pb` - Push the top element from stack A to stack B.
- `ra` - Rotate stack A (move the top element to the bottom).
- `rb` - Rotate stack B (move the top element to the bottom).
- `rr` - Rotate both stacks A and B.
- `rra` - Reverse rotate stack A (move the bottom element to the top).
- `rrb` - Reverse rotate stack B (move the bottom element to the top).
- `rrr` - Reverse rotate both stacks A and B.

## Data Structure
**Double Linked List**

In the **Push Swap** project, a **double linked list** is commonly used to represent the stack. A double linked list is a type of data structure where each element (node) contains a reference (or link) to both its next and previous elements, making it different from a regular singly linked list that only points to the next element.

### What is a Double Linked List?

A **double linked list** is a list of nodes, where each node contains three key components:
1. **Data**: The value stored in the node.
2. **Next**: A reference (or pointer) to the next node in the list.
3. **Prev**: A reference (or pointer) to the previous node in the list.

This structure allows for traversal in both directions: forward and backward.

### How Does a Double Linked List Work?

1. **Node Structure**:
   Each node of a double linked list consists of the following:
   - **Data**: The value of the element (e.g., the integer in the **Push Swap** stack).
   - **Next**: A pointer/reference to the next node in the list.
   - **Prev**: A pointer/reference to the previous node in the list.
   
   Here is a simple illustration of a node in a double linked list:

   ```
   [Prev | Data | Next]
   ```

2. **Advantages of a Double Linked List**:
   - **Bidirectional Traversal**: You can move both forward and backward through the list, which makes it easier to navigate in both directions when performing operations like push, swap, and rotate in the **Push Swap** project.
   - **Efficient Insertions/Deletions**: Insertion and deletion of nodes can be done efficiently in constant time, especially when the node is already known (using the `next` and `prev` references).
   - **Flexible Operations**: You can easily perform operations like swapping two elements by manipulating the `next` and `prev` pointers without needing to traverse the entire list.

3. **Operations on Double Linked List**:

   - **Push**:
     In the **Push Swap** project, a push operation means transferring an element from one stack (linked list) to another. When an element is pushed from Stack A to Stack B or vice versa, it’s done by adjusting the `next` and `prev` pointers of the nodes.
   
     - When pushing a node from Stack A to Stack B:
       1. The node's `next` pointer is set to the current top of Stack B.
       2. The current top of Stack B’s `prev` pointer is updated to the new node.
       3. The new node becomes the top of Stack B.

   - **Swap**:
     A swap operation involves swapping the top two elements of the stack. For a double linked list, this is done by adjusting the `next` and `prev` pointers of the two nodes.
     - Swap the first node with the second node by swapping their `next` and `prev` references.
   
   - **Rotate**:
     A rotate operation moves the top element of the stack to the bottom. It involves:
     - Updating the `next` pointer of the current top node to point to the `NULL` (the new tail).
     - Making the former top node the tail by adjusting the `prev` pointer of the new tail node to `NULL`.

     Similarly, the `prev` pointer of the new top node should be updated to `NULL`, and the `next` pointer of the new last node should be updated to point to the old top node.

   - **Reverse Rotate**:
     Reverse rotate is the opposite of rotate. It involves moving the last element of the stack to the top:
     - The tail node becomes the new top.
     - The `next` pointer of the new tail node points to the old top node.
     - The `prev` pointer of the old top node becomes the new tail.

4. **Memory Management**:
   - In a double linked list, proper memory management is crucial. When nodes are removed from the list, the memory should be freed to avoid memory leaks.
   - When adding a new node, dynamic memory allocation is used to ensure that the list can grow as needed.

### Example of Double Linked List in Push Swap

Here’s how a simple double linked list representing a stack in **Push Swap** might look:

```
[Prev | 10 | Next] ↔ [Prev | 20 | Next] ↔ [Prev | 30 | Next]
```

In this example:
- The first node has the value `10`, the second node has `20`, and the third node has `30`.
- The `prev` of the second node points to the first node, and the `next` of the first node points to the second node.
- The `prev` of the third node points to the second node, and the `next` of the second node points to the third node.
- The first node's `prev` is `NULL`, and the last node's `next` is `NULL`.

---

### Why Use a Double Linked List in **Push Swap**?

In **Push Swap**, the stack of numbers must be sorted using a variety of operations. The double linked list structure provides a flexible way to implement these operations efficiently. It allows for:
- Easy and quick traversal in both directions.
- Efficient pushing, swapping, rotating, and reverse rotating operations.
- Simplified manipulation of the stack when dealing with multiple operations simultaneously.

By utilizing a double linked list, the **Push Swap** project can be implemented with a more optimized and clean approach, allowing for fast and efficient sorting with fewer lines of code and reduced complexity.

---

This explanation covers how a double linked list is structured and used in the context of the **Push Swap** project, focusing on the main operations such as push, swap, rotate, and reverse rotate.

## Algorithm

1. **Push the First Two Numbers**:
   - Start by pushing two numbers from **STACK_A** to **STACK_B** without checking anything. This helps in setting up the initial configuration.

2. **Find the Cheapest Number**:
   - After the initial push, begin calculating the cost (number of operations) to move each number into its correct position in **STACK_B**. This includes checking rotations in both stacks (A and B).
   - Each number is analyzed one by one, and the "cheapest" (least number of operations) one is pushed to **STACK_B**.
  
3. **Push the Cheapest Number**:
   - Continue this process, always selecting the cheapest number (the one that requires the least number of operations to move into **STACK_B**).
   - Once you've pushed the number, start over and calculate the next cheapest number until all elements are sorted.

4. **Handle the Last Three Elements**:
   - Once you reach the last three elements, sorting becomes simpler. With a few rotations and swaps, these numbers can be sorted in no time.

5. **Push Back to **STACK_A**:
   - After sorting the numbers in **STACK_B**, start moving them back to **STACK_A**.
   - Before pushing a number back, check if it's in the correct position. If not, rotate **STACK_A** until the correct number is at the top, then push.

6. **Final Adjustment**:
   - Once all numbers are in **STACK_A**, ensure that the smallest number is at the top. If the smallest number isn't at the top, rotate **STACK_A** to place it there. 
   - Once the smallest number is on top, the stack is fully sorted.

## Bonus

- Optimized sorting algorithm using stack operations.
- Handles edge cases, such as sorting small or large input sizes.
- Provides additional operations for efficient stack manipulation.
