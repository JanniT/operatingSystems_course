# https://www.geeksforgeeks.org/python-os-getenv-method/
import sys
import os

# function to calculate the result
def calculate(operator, values):
    # summing the operators together
    if operator == 'add':
        return sum(values)
    # multiplying all the operators together
    elif operator == 'multiply':
        result = 1
        for operand in values:
            result *= operand
        return result
    else:
        return "Unknown operator"

def main():
    # checking if the commandline arguments number is under 2
    if len(sys.argv) < 2:
        print("Usage of this program: {} <at least 2 values>".format(sys.argv[0]))
        sys.exit(1)
    # getting the operator
    operator = os.getenv('OPERATOR')
    if not operator:
        print("Error: OPERATOR environment variable is not set")
        sys.exit(1)

    # converting the commandline arguments to integers
    values = [int(x) for x in sys.argv[1:]] 
    result = calculate(operator, values)
    print(result)

if __name__ == "__main__":
    main()
