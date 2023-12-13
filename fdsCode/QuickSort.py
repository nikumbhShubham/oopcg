def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        lesser = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quick_sort(lesser) + [pivot] + quick_sort(greater)

# def display_top_scores(arr, top_count):
#     sorted_scores = quick_sort(arr)
#     top_scores = sorted_scores[-top_count:]
#     print(f"Top {top_count} scores:")
#     for score in reversed(top_scores):
#         print(score)

# Taking input of first-year percentages from the user
n = int(input("Enter the number of students: "))
first_year_percentages = []

for i in range(n):
    percentage = float(input(f"Enter percentage for student {i+1}: "))
    first_year_percentages.append(percentage)

# Sort the array using Quick Sort
sorted_percentages = quick_sort(first_year_percentages)

print(sorted_percentages)

# Display top five scores
top_count = 5
# display_top_scores(sorted_percentages, top_count)
print(f"Top {top_count} scores:")
for score in sorted_percentages[-top_count:][::-1]:
    print(score)
