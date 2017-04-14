a = [3, 4654 , 654, 76, 7, 733, 456, 656, 6555]

b = [45, 56, 58, 25, 4767, 2455768, 532, 56，1]

c = a + b

#希尔排序
i = 0
m = 0
def shell_sort(a[], n, k):

	for i in n/2:
		while j > n/2 and j <=n:
			if j < i:
      			m = a[i]
      			a[i] = a[j]
      			a[j] = m
      		else:
    			continue
    		if a[i] < a[i+1]:
    			continue
    		else:
    			k = a[i]
      			a[i] = a[i+1]
      			a[i+1] = k
