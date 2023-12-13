#   Author: Shubham Nikumbh 
from collections import Counter
def get_marks_from_user(num_students):
    marks = []
    absent_count = 0
    for i in range(num_students):
        while True:
            try:
                mark = int(input(f"Enter the marks for student {i + 1} (or -1 for absent): "))
                if mark == -1:
                    absent_count += 1
                else:
                    marks.append(mark)
                break
            except ValueError:
                print("Invalid input. Please enter a valid integer for marks.")
    return marks, absent_count

def compute_average(marks):
    if len(marks) == 0:
        return 0
    return sum(marks) / len(marks)

def find_highest_and_lowest(marks):
    if not marks:
        return None, None
    highest = max(marks)
    lowest = min(marks)
    return highest, lowest

def count_absent_students(absent_count):
    return absent_count

# def display_mark_with_highest_frequency(marks):
#     if not marks:
#         return None
#     mark_counts = {}
#     for mark in marks:
#         if mark in mark_counts:
#             mark_counts[mark] += 1
#         else:
#             mark_counts[mark] = 1
#     highest_frequency_mark = max(mark_counts, key=mark_counts.get)
#     return highest_frequency_mark

def mark_with_highest_frequency(marks):
    freq_counter = Counter(marks)
    if marks:
        highest_frequency = max(freq_counter.values())
        most_common_marks = [mark for mark, freq in freq_counter.items() if freq == highest_frequency]
        return most_common_marks
    return []
# Get the number of students
print(f"Author: Shubham Nikumbh")
num_students = int(input("Enter the number of students: "))

# Get marks and count of absent students from the user
marks, absent_count = get_marks_from_user(num_students)

# Compute and display the statistics

average = compute_average(marks)
highest, lowest = find_highest_and_lowest(marks)
absent_students_count = count_absent_students(absent_count)
highest_frequency_mark = mark_with_highest_frequency(marks)


print(f"a) The average score of the class: {average}")
print(f"b) Highest score of the class: {highest}, Lowest score of the class: {lowest}")
print(f"c) Count of students who were absent for the test: {absent_students_count}")
print(f"d) Mark with the highest frequency: {highest_frequency_mark}")
