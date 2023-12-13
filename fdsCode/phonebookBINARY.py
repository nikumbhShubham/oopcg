def binary_search_recursive(arr, target, low, high):
    if high >= low:
        mid = low + (high - low) // 2

        if arr[mid][0] == target:
            return mid
        elif arr[mid][0] > target:
            return binary_search_recursive(arr, target, low, mid - 1)
        else:
            return binary_search_recursive(arr, target, mid + 1, high)
    else:
        return -1

def binary_search_iterative(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid][0] == target:
            return mid
        elif arr[mid][0] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1

def insert_friend(phonebook, name, number):
    index = binary_search_iterative(phonebook, name)
    if index == -1:
        phonebook.append((name, number))
        phonebook.sort(key=lambda x: x[0])  # Sort the phonebook by names
        print(f"{name} inserted into the phonebook.")
    else:
        print(f"{name} is already in the phonebook.")

phonebook = [("Alice", "1234567890"), ("Bob", "9876543210"), ("Charlie", "8765432109")]

while True:
    print("\nMenu:")
    print("1. Search friend (Recursive Binary Search)")
    print("2. Search friend (Iterative Binary Search)")
    print("3. Insert friend")
    print("4. Display phonebook")
    print("5. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter friend's name to search (Recursive): ")
        index = binary_search_recursive(phonebook, name, 0, len(phonebook) - 1)
        if index != -1:
            print(f"{name} found. Mobile number: {phonebook[index][1]}")
        else:
            print(f"{name} not found in the phonebook.")

    elif choice == "2":
        name = input("Enter friend's name to search (Iterative): ")
        index = binary_search_iterative(phonebook, name)
        if index != -1:
            print(f"{name} found. Mobile number: {phonebook[index][1]}")
        else:
            print(f"{name} not found in the phonebook.")
    
    elif choice == "3":
        name = input("Enter friend's name to insert: ")
        number = input("Enter friend's mobile number: ")
        insert_friend(phonebook, name, number)
    
    elif choice == "4":
        print("Phonebook:")
        for entry in phonebook:
            print(f"Name: {entry[0]}, Mobile: {entry[1]}")
    
    elif choice == "5":
        print("Exiting...")
        break
    
    else:
        print("Invalid choice. Please enter a valid option.")
