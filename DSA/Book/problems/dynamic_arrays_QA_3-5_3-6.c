// Skiena 3.5

/*
3-5. [5] We have seen how dynamic arrays enable arrays to grow while still achiev-
ing constant-time amortized performance. This problem concerns extending
dynamic arrays to let them both grow and shrink on demand.
(a) Consider an underflow strategy that cuts the array size in half whenever
the array falls below half full. Give an example sequence of insertions and
deletions where this strategy gives a bad amortized cost.
(b) Then, give a better underflow strategy than that suggested above, one that
achieves constant amortized cost per deletion.
*/

// answer: 
/*A. Cutting the array in half every time if follows below half is not good because we would 
    be close near boundaries most of times and maybe causing repetivie push and pop
    ex:
    size = 4, capacity = 8
push → size = 5  (no resize)
pop  → size = 4  (resize down to 4)
push → size = 5  (resize up to 8)
pop  → size = 4  (resize down to 4)*/

/*B. For what I've seen some implementation don't shrink at all, but the ones that do
 require a size > capacity / 4 to do it because it leave room for the buffer to grow*/


 /*3-6. [3] Suppose you seek to maintain the contents of a refrigerator so as to minimize
food spoilage. What data structure should you use, and how should you use
it?*/

// answer:
 /* For each food I put in I need to map the food and the time to spolaigae as value,key
    and as a data structure I would use a priority queue by prioritizing the items close
    to get spoiled */