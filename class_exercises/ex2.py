def main():
    number = input("please enter numbers to check\n")
    numbers = list(number)
    numbers = [int(x) for x in numbers]
    check_armstrong(numbers, int(number))


def check_armstrong(numbers, number):
    sum = 0
    for i in range(len(numbers)):
        sum = sum + numbers[i]**len(numbers)
    if sum == number:
        print("The number is an armstrong number")
    else:
        print("The number is not armstrong")
    



if __name__ == "__main__":
    main()