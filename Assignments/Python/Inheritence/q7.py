
class PaymentGateway:
    def process_payment(self, amount):
        print("Processing payment of Rs.", amount)


class CreditCardPayment(PaymentGateway):
    def process_payment(self, amount):
        print("Credit Card Payment")
        print("Payment of Rs.", amount, "processed using Credit Card.")


class UPIPayment(PaymentGateway):
    def process_payment(self, amount):
        print("UPI Payment")
        print("Payment of Rs.", amount, "processed using UPI.")


# Main program
amount = float(input("Enter payment amount: "))

print("\n1. Credit Card Payment")
print("2. UPI Payment")

choice = int(input("Enter your choice: "))

if choice == 1:
    p = CreditCardPayment()
    p.process_payment(amount)

elif choice == 2:
    p = UPIPayment()
    p.process_payment(amount)

else:
    print("Invalid choice!")
