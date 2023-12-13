def fibonacci_search(arr, target):
    fib_m_minus_2 = 0
    fib_m_minus_1 = 1
    fib_m = fib_m_minus_1 + fib_m_minus_2

    while fib_m < len(arr):
        fib_m_minus_2 = fib_m_minus_1
        fib_m_minus_1 = fib_m
        fib_m = fib_m_minus_1 + fib_m_minus_2

    offset = -1
    while fib_m > 1:
        i = min(offset + fib_m_minus_2, len(arr) - 1)

        if arr[i][0] < target:
            fib_m = fib_m_minus_1
            fib_m_minus_1 = fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
            offset = i
        elif arr[i][0] > target:
            fib_m = fib_m_minus_2
            fib_m_minus_1 -= fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
        else:
            return i

    if fib_m_minus_1 and arr[offset + 1][0] == target:
        return offset + 1

    return -1

def insert_friend(phonebook, name, number):
    index = fibonacci_search(phonebook, name)
    if index == -1:
        phonebook.append((name, number))
        phonebook.sort(key=lambda x: x[0])  # Sort the phonebook by names
        print(f"{name} inserted into the phonebook.")
    else:
        print(f"{name} is already in the phonebook.")

# Initial phonebook data
phonebook = [("Alice", "1234567890"), ("Bob", "9876543210"), ("Charlie", "8765432109")]

while True:
    print("\nMenu:")
    print("1. Search friend")
    print("2. Insert friend")
    print("3. Display phonebook")
    print("4. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter friend's name to search: ")
        index = fibonacci_search(phonebook, name)
        if index != -1:
            print(f"{name} found. Mobile number: {phonebook[index][1]}")
        else:
            print(f"{name} not found in the phonebook.")
    
    elif choice == "2":
        name = input("Enter friend's name to insert: ")
        number = input("Enter friend's mobile number: ")
        insert_friend(phonebook, name, number)
    
    elif choice == "3":
        print("Phonebook:")
        for entry in phonebook:
            print(f"Name: {entry[0]}, Mobile: {entry[1]}")
    
    elif choice == "4":
        print("Exiting...")
        break
    
    else:
        print("Invalid choice. Please enter a valid option.")
