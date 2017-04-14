#归并排序的python实现
a = [49, 38, 65, 97, 26, 13, 37, 49, 55, 4]
gap = len(a)

#合并有序数列
def MemeryArray(a[], b[],  c[]):

	k = 0
	n = len(a)
	m = len(b)
	while (i <= n and j <= m):
		if a[i] < b[j]:
			c[k] = a[i]
			k++
			i++
		else:
			c[k] = b[j]
			k++
			i++
	while i <= n and j > m:
		c[k] = a[i]
		k++
		i++

	while i > n and j <= m:
		c[k] = b[j]
		k++
		i++

#归并排序
def merge_sort(a[], first, last, c[])：
	if first < last:
		mid = (first + last)/2
		merge_sort(a, first, mid, c)
		merge_sort(a, mid + 1, last, c)
		merge_sort(b, first, mid, c)
		merge_sort(b, mid + 1, last, c)
		MemeryArray(a, b, c)