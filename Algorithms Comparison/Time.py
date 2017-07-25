from insertion import insertion_sort
from merge import merge_sort
import random
import time


if __name__ == '__main__':
    items=[random.randint(-50,100) for c in range (1000)]
    items2 = items
    start = time.time()
    insertion_sort(items)
    insertiontime = time.time()-start
    print "Insertion Sort Time = " , insertiontime

    merge_sort(items2)
    mergetime = time.time()-insertiontime
    print "Merge Sort Time = " , mergetime
