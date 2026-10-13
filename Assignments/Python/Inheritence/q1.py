
class Account:
    def __init__(self, name, balance):
        self.name = name
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount
        print("Amount deposited successfully.")

    def withdraw(self, amount):
        if amount <= self.balance:
            self.balance -= amount
            print("Amount withdrawn successfully.")
        else:
            print("Insufficient balance.")

    def check_balance(self):
        print("Account Holder:", self.name)
        print("Current Balance:", self.balance)


class Saving(Account):
    def calculate_interest(self):
        rate = 5
        interest = self.balance * rate / 100
        print("Interest at 5%:", interest)


# Main program
name = input("Enter account holder name: ")
balance = float(input("Enter initial balance: "))

s = Saving(name, balance)

while True:
    print("\n--- Bank Application ---")
    print("1. Deposit")
    print("2. Withdraw")
    print("3. Check Balance")
    print("4. Calculate Interest")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        amount = float(input("Enter amount to deposit: "))
        if amount > 0:
            s.deposit(amount)
        else:
            print("Enter a valid amount.")

    elif choice == 2:
        amount = float(input("Enter amount to withdraw: "))
        if amount > 0:
            s.withdraw(amount)
        else:
            print("Enter a valid amount.")

    elif choice == 3:
        s.check_balance()

    elif choice == 4:
        s.calculate_interest()

    elif choice == 5:
        print("Thank you for using the Bank Application.")
        break

    else:
        print("Invalid choice. Try again.")
