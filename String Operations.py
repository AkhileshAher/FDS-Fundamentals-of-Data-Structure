/*
Write a python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in
the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
*/

#CODE :

  # Display Word With Longest Length
def longestWord():
    print("\tProgram to display word with longest length\n")
    str1 = input("Enter the String: ")
    slist = str1.split()
    large = ''
    for word in slist:
        if len(word) > len(large):
            large = word
    print("The word with the largest length is:", large, "\n")


# Frequency of occurrence of a particular character
def freqOfChar():
    print("\tProgram to find frequency of occurrence of a particular character\n")
    str1 = input("Enter the String: ")
    key = input("Enter the character: ")
    count = str1.count(key)  # Use built-in count method
    print(f"The occurrence of '{key}' in the given string is {count} times\n")


# Check whether the given string is a palindrome
def isPalindrome():
    print("\tProgram to check whether the given string is a palindrome or not\n")
    str1 = input("Enter the String: ")
    if str1 == str1[::-1]:
        print("String is a palindrome\n")
    else:
        print("String is not a palindrome\n")


# Display index of first appearance of substring
def findSubstr():
    print("\tProgram to display index of first appearance of substring\n")
    str1 = input("Enter the String: ")
    str2 = input("Enter the Substring: ")
    index = str1.find(str2)  # Use built-in find method
    if index != -1:
        print(f"The index of the first appearance of '{str2}' is {index}\n")
    else:
        print(f"The substring '{str2}' was not found in the given string\n")


# Count occurrences of each word in a given string
def countOfWords():
    print("\tProgram to count occurrences of each word in a given string\n")
    str1 = input("Enter the String: ")
    slist = str1.split()
    sdict = {}
    for word in slist:
        sdict[word] = sdict.get(word, 0) + 1  # Use dictionary's get method for cleaner logic
    print("Word count in the given string:")
    for word, count in sdict.items():
        print(f"{word}: {count}")
    print()


# Main Menu
while True:
    print("\n\n****************** M e n u ******************\n")
    print("1. Display the word with the longest length")
    print("2. Determine the frequency of occurrence of a particular character in a string")
    print("3. Check whether the given string is a palindrome")
    print("4. Display index of the first appearance of a substring")
    print("5. Count the occurrences of each word in a given string")
    print("0. Exit")
    try:
        choice = int(input("Enter Choice (Press 0 for Exit): "))
        print("\n******************************************************")
        if choice == 1:
            longestWord()
        elif choice == 2:
            freqOfChar()
        elif choice == 3:
            isPalindrome()
        elif choice == 4:
            findSubstr()
        elif choice == 5:
            countOfWords()
        elif choice == 0:
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Wrong choice. Please select a valid option.")
    except ValueError:
        print("Invalid input. Please enter a number between 0 and 5.")
