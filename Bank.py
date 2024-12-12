/*
Write a python program that computes the net amount of a bank account based a transaction log from console input.

The transaction log format is shown as following:
  D 100 W 200 (Withdrawal is not allowed if balance is going negative.
Write functions for withdraw and deposit) D means deposit while W means
withdrawal.
Suppose the following input is supplied to the program:
D 300
D 300
W 200
D 100
Then, the output should be: 500
*/

#CODE :

def deposit(num):
    global balance
    balance += num  # Add amount to the balance
    
def withdrawal(num):
    global balance
    if balance >= num:  # Check if balance is sufficient
        balance -= num  # Deduct the amount
    else:
        print("Insufficient funds")

# Initialize balance and transaction list
list1 = []
balance = 0

# Input transactions
while True:
    data = input("Please enter the transaction details (D/W <amount>) or 'Exit' to stop:\n")
    if data.lower() == 'exit':  # Check for exit condition
        break
    list1.append(data.split())  # Split input into operation and amount

# Process transactions
for var in list1:
    if var[0] == 'D':  # Deposit
        deposit(int(var[1]))
    elif var[0] == 'W':  # Withdrawal
        withdrawal(int(var[1]))
    else:
        print(f"Invalid transaction type: {var[0]}")

# Display final balance
print("Final Balance is:", balance)
