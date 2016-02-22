def solve(number, ink_letter_list):
    
    ink_used_list = []
    for i in range(2, 37):
        ink = 0
        r = 0
        q = number
        while(q >= i):
            r = q % i
            q = q // i
            ink += ink_letter_list[r]
        r = q % i
        q // i
        ink += ink_letter_list[r]
        ink_used_list.append(ink)
    
    ans = [""]
    for i, ink_used in zip(range(2, 37), ink_used_list):
        if ink_used == min(ink_used_list):
            ans.append(i)

    print("Cheapest base(s) for number ", number, sep="", end=":")
    print(*ans)


case_amount = int(input())

for case in range(1, case_amount + 1):
    if(case > 1):
        print()
    print("Case ", case, ":", sep="")

    ink_letter_list = []

    for _ in range(4):
        ink_letter_list.extend(map(int, input().split(" ")))

    numbers = int(input())

    for num in range(numbers):
        solve(int(input()), ink_letter_list)