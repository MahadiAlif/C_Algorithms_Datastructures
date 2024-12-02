import random

def main():
    my_num = random.randint(1,100)
    print("I have chosen a secret number between 1 and 100\n")
    print()
    detect_guess(my_num)

def detect_guess(my_num):
    number = int(input())
    count = 1
    while number != my_num:
        print(f"Your guess: {number}")
        if number > my_num:
            print("Hint:  Too high!")
        elif number < my_num:
            print("Hint:  Too low!")
        else:
            print("Your number is not Valid")
        count = count + 1
        number = int(input())
    print("Hint:  Just right!")
    print(f"Congratulations! You guessed the number in {count} tries")
    



if __name__ == "__main__":
    main()