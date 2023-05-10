#!/usr/bin/python3

def print_last_digit(number):
    last_digit = number % 10
    print(last_digit, end="")
    return last_digit
if __name__ == "__main__":
    number = int(input("Enter a number: "))
    print_last_digit(number)
