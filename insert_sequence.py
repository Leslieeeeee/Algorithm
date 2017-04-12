#插入排序算法的python实现

a = [3, 4654 , 654, 76, 7, 733, 456, 656, 6555]

b = [45, 56, 58, 25, 4767, 2455768, 532, 56]

max = 0
n = 0
k = 0
j = 0
#快排
len = a.length()
while n < len:
for i in a:
	if a[n] < a[n+1]:
		continue
	else a[n] > a[n+1]:
		a[n] = max
		a[n] = a[n+1]
		a[n+1] = max
	i++
#插入
len = b.length()
while n < len:
	for i in b:
		for j in len:
			if b[i] <= a[j]:
				for k in len: 
					a[len+1] = a[len]
					k--
				a[j] = b[i]
			else:
				while k < len and k > j+1: 
					a[len+1] = a[len]
						k--
				a[j]+1 = b[i]
