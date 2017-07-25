def merge_sort(items):
    if len(items)>1:
        mid = len(items)//2
        left = items[:mid]
        right = items[mid:]

        merge_sort(left)
        merge_sort(right)

        i=0
        j=0
        k=0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                items[k]=left[i]
                i=i+1
            else:
                items[k]=right[j]
                j=j+1
            k=k+1

        while i < len(left):
            items[k]=left[i]
            i=i+1
            k=k+1

        while j < len(right):
            items[k]=right[j]
            j=j+1
            k=k+1
