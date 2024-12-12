/*
Write a python program to store the first year percentage of students in an array.
Write function for sorting array of floating point numbers in ascending
order using
a) Selection Sort
b) Bubble sort and display top five scores.

*/

#CODE :

def selectionSort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(i + 1, n):
            if arr[i] > arr[j]:
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
    return arr

def bubbleSort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def inputMarks():
    arr = []
    num = int(input("Enter the number of students: "))
    for i in range(num):
        per = float(input("Enter the percentage of marks: "))
        arr.append(per)
    return arr

def displayTopFive(arr):
    top_five = arr[-5:] if len(arr) >= 5 else arr
    print("\nTop Five Scores:")
    for score in reversed(top_five):
        print(f"{score:.2f}")

while True:
    print("\n========== MENU ==========")
    print("1. Selection Sort")
    print("2. Bubble Sort and Display Top Five Scores")
    print("0. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        arr = inputMarks()
        sorted_arr = selectionSort(arr)
        print("AFTER SELECTION SORT, ARRAY IS:")
        for i in range(len(sorted_arr)):
            print(f"{sorted_arr[i]:.2f}")

    elif choice == 2:
        arr = inputMarks()
        sorted_arr = bubbleSort(arr)
        print("Sorted array is:")
        for i in range(len(sorted_arr)):
            print(f"{sorted_arr[i]:.2f}")
        displayTopFive(sorted_arr)

    elif choice == 0:
        print("Exiting the program. Goodbye!")
        break

    else:
        print("Invalid choice. Please try again.")
