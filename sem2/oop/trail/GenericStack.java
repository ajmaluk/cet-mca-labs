/**
 * @file GenericStack.java
 * @brief Professional, type-safe generic stack implementation in Java.
 *
 * Features:
 * - Type safety using Java Generics
 * - Array-based stack with dynamic size
 * - Standard stack operations: push, pop, peek, isEmpty, isFull, size
 * - Clear error messages and robust edge case handling
 *
 * @author CET MCA
 * @date 2026
 */

public class GenericStack<T> {
    private final Object[] stack;
    private int top;
    private final int capacity;

    /**
     * Constructor to initialize stack with given size.
     * @param size Maximum number of elements stack can hold
     */
    public GenericStack(int size) {
        if (size <= 0) throw new IllegalArgumentException("Stack size must be positive.");
        capacity = size;
        stack = new Object[capacity];
        top = -1;
    }

    /**
     * Pushes an item onto the stack.
     * @param item Element to push
     */
    public void push(T item) {
        if (isFull()) {
            System.out.println("Stack Overflow: Cannot push " + item);
            return;
        }
        stack[++top] = item;
        System.out.println("Pushed: " + item);
    }

    /**
     * Pops the top item from the stack.
     * @return The popped element, or null if stack is empty
     */
    public T pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow: Nothing to pop.");
            return null;
        }
        T item = (T) stack[top--];
        System.out.println("Popped: " + item);
        return item;
    }

    /**
     * Returns the top item without removing it.
     * @return The top element, or null if stack is empty
     */
    public T peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty: Nothing to peek.");
            return null;
        }
        return (T) stack[top];
    }

    /**
     * Checks if the stack is empty.
     * @return true if empty, false otherwise
     */
    public boolean isEmpty() {
        return top == -1;
    }

    /**
     * Checks if the stack is full.
     * @return true if full, false otherwise
     */
    public boolean isFull() {
        return top == capacity - 1;
    }

    /**
     * Returns the current size of the stack.
     * @return Number of elements in stack
     */
    public int size() {
        return top + 1;
    }

    /**
     * Demonstrates usage of GenericStack with Integer and String types.
     */
    public static void main(String[] args) {
        System.out.println("--- Integer Stack Demo ---");
        GenericStack<Integer> intStack = new GenericStack<>(5);
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.pop();
        System.out.println("Top: " + intStack.peek());
        System.out.println("Stack size: " + intStack.size());

        System.out.println("\n--- String Stack Demo ---");
        GenericStack<String> stringStack = new GenericStack<>(3);
        stringStack.push("A");
        stringStack.push("B");
        stringStack.pop();
        System.out.println("Top: " + stringStack.peek());
        System.out.println("Stack size: " + stringStack.size());
    }
}

/*
 * Notes & Best Practices:
 * - Always check for stack overflow/underflow before push/pop.
 * - Use generics for type safety and code reuse.
 * - Prefer composition over inheritance for stack utilities.
 * - For production, consider using java.util.Stack or Deque.
 */
