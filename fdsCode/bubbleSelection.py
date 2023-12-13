def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

def display_top_scores(arr, top_count):
    print(f"Top {top_count} scores:")
    for score in arr[-top_count:]:
        print(score)

n = int(input("Enter the number of students: "))
first_year_percentages = []

for i in range(n):
    percentage = float(input(f"Enter percentage for student {i+1}: "))
    first_year_percentages.append(percentage)

selection_sort_percentages = first_year_percentages.copy()
bubble_sort_percentages = first_year_percentages.copy()

selection_sort(selection_sort_percentages)
bubble_sort(bubble_sort_percentages)

print("\nSorted Selection Sort Percentages:")
print(selection_sort_percentages)

print("\nSorted Bubble Sort Percentages:")
print(bubble_sort_percentages)

print("\nUsing Selection Sort:")
display_top_scores(selection_sort_percentages, 5)

print("\nUsing Bubble Sort:")
display_top_scores(bubble_sort_percentages, 5)
