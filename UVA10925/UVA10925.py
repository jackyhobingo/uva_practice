
bill = 1
while True:
    N_str, F_str = input().split(" ")
    N = int(N_str)
    F = int(F_str)
    if N == F and N == 0:
        break

    sum_ = 0
    for _ in range(N):
        sum_ += int(input())
    
    print("Bill #{} costs {}: each friend should pay {}".format(bill, sum_, sum_ //F))
    print()
    bill += 1
