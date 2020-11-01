def prime_set():
    span_p = int(input("Enter the range upto which the set of prime numbers is to be generated: "))
    prime_list = []
    for num in range(2, span_p+1):
        if prime_numbers(num):
            prime_list.append(num)
        else:
            pass
    return set(prime_list)


def prime_numbers(num):
    count = 0
    for i in range(1, num+1):
        if num % i == 0:
            count = count + 1
    if count == 2:
        return num


def odd_numbers(num):
    for i in range(1, num+1):
        if num % 2 == 1:
            return num


def odd_set():
    span_o = int(input("Enter the range upto which the set of odd numbers is to be generated: "))
    odd_list = []
    for num in range(1, span_o+1):
        if odd_numbers(num):
            odd_list.append(num)
        else:
            pass
    return set(odd_list)


set_prime = prime_set()
print(set_prime)
set_odd = odd_set()
print(set_odd)

print("\nUnion = ", end='')
print(set_odd.union(set_prime))
print("Intersection = ", end='')
print(set_odd.intersection(set_prime))
print("Difference of Odd numbers from Prime numbers = ", end='')
print(set_odd.difference(set_prime))
print("Difference of Prime numbers from Odd numbers = ", end='')
print(set_prime.difference(set_odd))
print("Symmetric Difference = ", end='')
print(set_odd.symmetric_difference(set_prime))
