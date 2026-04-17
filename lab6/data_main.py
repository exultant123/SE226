from data_package.cleaner import strip_whitespaces
from data_package.cleaner import remove_duplicates
from data_package.analyzer import find_maximum
from data_package.analyzer import calculate_mean

try:
    s = input("Enter a comma-separated list of numbers (e.g., 12, 5, 12, 8 , 21): ")

    l = s.split(",")
    1
    l = strip_whitespaces(l)

    l = remove_duplicates(l)


    print("Cleaned and unique data: ")
    print(l)

    print("--------------------")

    print("Mean:")
    print(calculate_mean(l))
    print("Maximum:")
    print(find_maximum(l))
except ValueError:
    # This catches non-integer strings like 'otuz'
    print("Data Error: Please make sure you only enter numbers separated by commas.")
