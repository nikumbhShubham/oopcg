# Function to handle deposit
def deposit(amount, balance):
    return balance + amount

# Function to handle withdrawal
def withdraw(amount, balance):
    if balance >= amount:
        return balance - amount
    else:
        return balance  # Withdrawal not allowed if balance is insufficient

# Process transaction log and compute net amount
def compute_net_amount(log):
    transactions = log.split(', ')
    balance = 0

    for transaction in transactions:
        transaction_type, amount = transaction.split()
        amount = int(amount)

        if transaction_type == 'D':
            balance = deposit(amount, balance)
        elif transaction_type == 'W':
            balance = withdraw(amount, balance)

    return balance

# Loop for completing transactions until the user chooses to exit
while True:
    transaction_log = input("Enter transaction log (Format - D amount, W amount, ...), or 'exit' to quit: ")
 
    if transaction_log.lower() == 'exit':
        break

    net_amount = compute_net_amount(transaction_log)
    print("Net amount in the bank account:", net_amount)
