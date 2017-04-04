#=======================================================================
#  Author: Isai Damier
#  Title: QuickSort
#  Project: geekviewpoint
#  Package: algorithm.sorting
#
#  Statement: Given a disordered list of integers (or any other items),
#  rearrange the integers in natural order.
#
#  Sample Input: [8,5,3,1,9,6,0,7,4,2]
#
#  Sample Output: [0,1,2,3,4,5,6,7,8,9]
#
#  Time Complexity of Solution:
#  Best = Average = O(nlog(n)); Worst = O(n^2).
#
#  Approach:
#  Quicksort is admirably known as the algorithm that sorts an array
#  while preparing to sort it. For contrast, recall that merge sort
#  first partitions an array into smaller pieces, then sorts each piece,
#  then merge the pieces back. Quicksort actually sorts the array
#  during the partition phase.
#
#  Quicksort works by selecting an element called a pivot and splitting
#  the array around that pivot such that all the elements in, say, the
#  left sub-array are less than pivot and all the elements in the right
#  sub-array are greater than pivot. The splitting continues until the
#  array can no longer be broken into pieces. That's it. Quicksort is
#    done.
#
#  All this fussing about quicksort sorting while preparing to sort
#  may give the impression that it is better than mergesort, but its
#  not. In practice their time complexity is about the same -- with
#  one funny exception. Because quicksort picks its pivot randomly,
#  there is a practically impossible possibility that the algorithm
#    may take O(n^2) to compute.
#
#  The aforementioned notwithstanding, quicksort is better than
#    mergesort if you consider memory usage. Quicksort is an in-place
#    algorithm, requiring no additional storage to work.
#======================================================================= 
import random
 
def quicksort( aList ):
    _quicksort( aList, 0, len( aList ) - 1 )
 
def _quicksort( aList, first, last ):
    if first < last:
      pivot = partition( aList, first, last )
      _quicksort( aList, first, pivot - 1 )
      _quicksort( aList, pivot + 1, last )
 
 
def partition( aList, first, last ) :
    pivot = first + random.randrange( last - first + 1 )
    swap( aList, pivot, last )
    for i in range( first, last ):
      if aList[i] <= aList[last]:
        swap( aList, i, first )
        first += 1
 
    swap( aList, first, last )
    return first
 
 
def swap( A, x, y ):
  A[x],A[y]=A[y],A[x]
