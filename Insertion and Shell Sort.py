
'''Write a Python program to store the second year percentage ofstudents in an array.
Write function for sorting array of floating point numbers in ascendingorder using
a) Insertion sort.
b) Shell Sort and display Top five scores.'''

#Code :-

def ins_sort(arr): 
    for i in range(1, len(arr)): 
        key = arr[i] 
        j = i - 1 
        while j >= 0 and key < arr[j]: 
            arr[j + 1] = arr[j] 
            j -= 1 
        arr[j + 1] = key 

def sh_sort(arr): 
    n = len(arr) 
    gap = n // 2 
    while gap > 0: 
        for i in range(gap, n): 
            temp = arr[i] 
            j = i 
            while j >= gap and arr[j - gap] > temp: 
                arr[j] = arr[j - gap] 
                j -= gap 
            arr[j] = temp 
        gap //= 2 

size = int(input("Enter the number of students: ")) 
percentages = [] 

for i in range(size): 
    percentage = float(input(f"Enter the percentage for student {i + 1}: ")) 
    percentages.append(percentage) 

# Insertion Sort
sorted_ins = percentages.copy()
ins_sort(sorted_ins) 
print("\nSorted array using Insertion Sort:", sorted_ins) 

# Shell Sort
sorted_shell = percentages.copy()
sh_sort(sorted_shell) 
print("\nSorted array using Shell Sort:", sorted_shell) 

# Top Five Scores
top_five = sorted_shell[-5:][::-1] 
print("\nTop five scores:", top_five)
