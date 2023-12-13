def remove_duplicates(lst):
    new_list = []
    for item in lst:
        if item not in new_list:
            new_list.append(item)
    return new_list

def both_cricket_badminton(list_cricket, list_badminton):
    common_students = [student for student in list_cricket if student in list_badminton]
    return remove_duplicates(common_students)

def either_cricket_or_badminton(list_cricket, list_badminton):
    exclusive_students = [student for student in list_cricket + list_badminton if student not in both_cricket_badminton(list_cricket, list_badminton)]
    return remove_duplicates(exclusive_students)

def neither_cricket_nor_badminton(total_students, list_cricket, list_badminton):
    neither_students = [student for student in total_students if student not in list_cricket + list_badminton]
    return len(remove_duplicates(neither_students))

def cricket_football_not_badminton(list_cricket, list_football, list_badminton):
    special_students = [student for student in list_cricket + list_football if student not in list_badminton]
    return len(remove_duplicates(special_students))

# Taking user input for group A (Cricket), B (Badminton), and C (Football) students
num_students = int(input("Enter the total number of students: "))

group_A = []
group_B = []
group_C = []

for i in range(num_students):
    name = input(f"Enter student {i + 1} name: ")
    sport = input(f"Enter the sport (Cricket/C, Badminton/B, Football/F) for {name}: ").upper()

    if sport == 'C':
        group_A.append(name)
    elif sport == 'B':
        group_B.append(name)
    elif sport == 'F':
        group_C.append(name)

# Displaying the results
print("\na) List of students who play both cricket and badminton:")
print(both_cricket_badminton(group_A, group_B))

print("\nb) List of students who play either cricket or badminton but not both:")
print(either_cricket_or_badminton(group_A, group_B))

print("\nc) Number of students who play neither cricket nor badminton:")
print(neither_cricket_nor_badminton(list(set(group_A + group_B + group_C)), group_A, group_B))

print("\nd) Number of students who play cricket and football but not badminton:")
print(cricket_football_not_badminton(group_A, group_C, group_B))
