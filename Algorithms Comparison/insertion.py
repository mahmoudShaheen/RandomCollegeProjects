def insertion_sort(items):
	for j in range(1, len(items)):
		key=items[j]
		i=j-1
		while i>=0 and items[i]>key:
			items[i+1]=items[i]
			i-=1
		items[i+1]=key
