

A = [0,3,4,2,4,6,7,11,8,1,9,31,0]

max = A[0]
second = None

for i in A:
    if i > max:
        max = i
    elif second is None:
        second = i
    elif i > second:
        second = i

print(second)