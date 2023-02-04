amt = int(input())
lst_nums = input().split()
map_nums = map(int, lst_nums)
nums = list(map_nums)

ans = 0
odd_amt = 0
even_amt = 0
for i in nums:
    if i%2 == 1:
        odd_amt+=1
    else:
        even_amt+=1

while True:
    
    if ans%2 == 0:
        if even_amt > 0:
            even_amt-=1
            ans+=1
        elif odd_amt > 1:
            ans+=1
            odd_amt-=2
        else:
            ans-=1
            break
    elif ans%2 == 1:
        if odd_amt > 0:
            ans+=1
            odd_amt-=1
        else:
            even_amt = 0
    
    if odd_amt == 0 and even_amt == 0:
        break
print(ans)
    