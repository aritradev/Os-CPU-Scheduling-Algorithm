# No1
a=int(input())
if a%2==0 and a>2: print("YES")
else: print("NO")

# No2

def solve():
    a = input()
    if(len(a)>10):
        print(a[0]+str(len(a)-2)+a[len(a)-1])
    else: print(a)

n=int(input())
for i in range(n):
    solve()

# NO3
n=int(input())
cnt=0
for i in range (n):
    a,b,c=map(int,input().split())
    if(a+b+c>1):cnt+=1
print(cnt)

# no4
n=int(input())
sum=0
for i in range (n):
    x=input()
    if "++" in x : sum+=1
    else: sum-=1
print(sum)

# no5
n,k=map(int,input().split())
arr=list(map(int,input().split()))
val=arr[k-1]
cur=0
for i in arr :
    if i>=val and i>0: 
        cur+=1

print(cur)


# no6
a,b=map(int,input().split())
print(int(a*b/2))

# no7
for i in range(5):
    row = list(map(int, input().split()))
    if 1 in row:
        col = row.index(1)
        print(abs(i - 2) + abs(col - 2))
        break

# no8
a = input().lower()
b = input().lower()

if a < b:
    print(-1)
elif a > b:
    print(1)
else:
    print(0)


# no9
s = input()

unique_chars = set(s)

if len(unique_chars) % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")

# no10

s = input()

nums = s.split("+")
nums.sort()

print("+".join(nums))
