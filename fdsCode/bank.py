def deposit(amount, transaction):
    return amount + transaction

def withdraw(amount, transaction):
    if transaction > amount:
        print("Withdrawal not allowed due to insufficient balance.")
        return amount
    return amount - transaction

def compute_net_amount(transaction_log):
    net_amount = 0
    transactions = transaction_log.split(", ")
    for transaction in transactions:
        trans_type, amount = transaction.split()
        amount = int(amount)
        if trans_type == 'D':
            net_amount = deposit(net_amount, amount)
        elif trans_type == 'W':
            net_amount = withdraw(net_amount, amount)
    return net_amount

log = input("Enter the transaction log (D/W amount, separated by commas): ")
result = compute_net_amount(log)
print(f"The net amount in the bank account is: {result}")
