def fibonacci_search(arr, target):
    # Initialize Fibonacci numbers
    fib_m_minus_2 = 0
    fib_m_minus_1 = 1
    fib_m = fib_m_minus_1 + fib_m_minus_2

    # Find the smallest Fibonacci number greater than or equal to len(arr)
    while fib_m < len(arr):
        fib_m_minus_2 = fib_m_minus_1
        fib_m_minus_1 = fib_m
        fib_m = fib_m_minus_1 + fib_m_minus_2

    offset = -1  # Index offset from where the array starts
    while fib_m > 1:
        # Check if fib_m_minus_2 is a valid index
        i = min(offset + fib_m_minus_2, len(arr) - 1)

        if arr[i] < target:
            # Move the indices to the right part of the array
            fib_m = fib_m_minus_1
            fib_m_minus_1 = fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
            offset = i
        elif arr[i] > target:
            # Move the indices to the left part of the array
            fib_m = fib_m_minus_2
            fib_m_minus_1 -= fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
        else:
            return i  # Target found at index i

    if fib_m_minus_1 and arr[offset + 1] == target:
        return offset + 1  # Target found at offset + 1

    return -1  # Target not found

# Example usage:
arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
target = 45
result = fibonacci_search(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}")
else:
    print(f"Element {target} not found in the array")
