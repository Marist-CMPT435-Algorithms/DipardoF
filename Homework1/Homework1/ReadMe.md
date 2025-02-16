
# Chapter 1:
### 1. Describe a real-world problem in which only the best solution will do. Then describe one in which a solution that is “approximately” the best is good enough.
**Answer:** A real-world problem where the best solution will be is to take into account an airline's schedule. We have to account for where the airline is going and how many passengers are on board. Understanding when each flight has to leave is very important for airports to keep in mind. If not then scheduling would be a mess and many planes would have difficulty taking off if there are other planes coming in at the same time as they leave   
A scenario for "good enough" would involve someone's GPSs rerouting them to find the next best route to their destination if there is traffic or other delays, or even avoiding tolls.


### 2. Suppose we are comparing implementations of insertion sort and merge sort on the same machine. For inputs of size n, insertion sort runs in 8n2 steps, while merge sort runs in 64n lg n steps. For which values of n does insertion sort beat merge sort?

**Answer:**  
**Insertion sort:** T(n) = 8n^2   
**Merge sort:** T(n) = 64n logn   
**Solving for:** 8n^2 < 64n logn  
**Simplified:** 2^n/8 < n  
**Values:**   
when n = 1, Insertion: 2^1/8 ≈ 1.09 , Merge: 1 , 1.09 > 1  
when n = 2, Insertion: 2^2/8 ≈ 1.19, Merge: 2 , 1.19 < 2  
when n = 10, Insertion: 2^10/8 ≈ 2.38, Merge: 10 , 2.38 < 10   
when n = 40, Insertion: 2^40/8 = 32, Merge: 40, 32 < 40  
when n = 44, Insertion 2^44/8 ≈ 45.25, Merge: 44, 45.25 > 44  
So Insertion sort beats merge sort when values of n are less than 2 and greater than 44.   

### 3. What is the smallest value of n such that an algorithm whose running time is 100n2 runs faster than an algorithm whose running time is 2n on the same machine?

**Answer:**  
**Simplify:**  
100n^2 = 2^n  
sqrt(100n^2) = sqrt(2^n)  
10n = (2n)^1/2  
10n = (2^n/2)  
**Values:**   
when n = 1, 10(1) = (2^1/2), 10 = 1.41  
when n = 10 10(10) = (2^10/2), 100 = 32  
when n = 15, 10(15) = (2^15/2) 150 = 181.02  
when n = 14, 10(14) = (2^14/2) 140 = 128  
The samllest value of n = 14.  


# Chapter 2
### 1. The searching problem may be specified as Input: A sequence of n numbers A = ⟨a1, a2, …, an⟩ and a value v. Output: An integer i such that v = ai or the special value NIL if v does not appear in A. Write pseudo-code, in the style of our textbook, for a linear search that scans through the input sequence, looking for v. Also, describe the loop invariant for this algorithm. Annotate your pseudo-code with costs and times for each statement/instruction, as demonstrated in class and our textbook for INSERTION-SORT.
**Answer:**  
Linear search:  

~~~
 for i = 1 to a.length{  //Cost: c1, Runs n times, minimum of 1 (worst case)
	if a[i] == v{	    //Cost: c2, Runs n times, minimum of 1 (worst case)
		return i;	    //Cost: c3, Runs once or 0 times (best case)
		
	}
}
return NIL;		           //Cost: c4, Runs once or 0 times (if v not found)

//Best case is when the target value v is the first element of array
//   T(n) = c1*1 + c2*1 + c3 + c4 = c1 + c2 + c3 + c4 = c = O(1)
//Average case is when the target value v is in the middle
//   T(n) = c1 * (n/2) + c2 * (n/2) + c3 = ((c1n/2 + c2n/2) + c3 + c4) = c(n/2) = O(n)
//Worst case is when the target value v is not in array
//   T(n) = c1 * (n) + c2 * (n) + c3 + c4 =  ((c1n + c2n) + c3 + c4) = c(n) = O(n)
~~~  
*Loop Invariant:*   
Initialization: Before the loop starts, no elements have been searched, so the invariant holds.   
Maintenance: As iterations continue, it will check one more element and keep going until it reaches the value v and returns it.    
Termination: There are two results, One where the v value is found the loop terminates, or one where the value v is not found in the array and returns NIL.    


### 2. Next, consider the minimum element problem in which we want to find the least number within a sequence. Specify this problem in the style demonstrated in the textbook and use it again in the previous exercise about the searching problem. Write pseudo-code, in the style of our textbook, for a linear search that scans through the input sequence, looking for v. Also, describe the loop invariant for this algorithm. Annotate your pseudo-code with costs and times for each statement/instruction, as demonstrated in class and our textbook for INSERTION-SORT.   

**Answer:**  

Linear Search (minimum element): The problem being solved here is finding the smallest value within an index in the array and returning the smallest value.

~~~
min_value = a[1]{			//cost: c1, Runs once  
for i = 1 to a.length{	    //Cost: c2, Runs n-1 times  
    if a[i] < min_value     //Cost: c3, Runs n-1 times (worst case)  
        min_value = a[i]    //Cost: c4, runs n-1 times  
    }  
}  

return min_value		    //Cost: c5, Runs once  
//Best case is when the target value v is the first element of array
//   T(n) = c1*1 + c2*(n-1) + c3*(n-1) + c4*1 + c5*1 = ((c2 + c3)*n-1) +c1 + c4 + c5 = cn-1 = O(n)
//Average case is when the target value v is in the middle
//   T(n) = c1 + c2 * (n-2) + c3 * (n-2) + c4 * (n-1/2) + c5 = ((c2 + c3 + )*n-1) + (c4n-1/2) + c1 + c5) = c(n-1) = O(n)
//Worst case is when the target value v is not in array
//   T(n) = c1 * 1 + c2 * (n-1) + c3 * (n-1) + c4 * (n-1) + c5 = ((c2 + c3 + c4) * n - 1) + c1 + c5 = c(n-1) = O(n)
~~~    
*Loop Invariant:*   
Initialization: Before the loop starts, we initialize the first index   
Maintenance: As we iterate through the loop, it will check one more element and continue checking all elements until it finds the smallest value within the array.    
Termination: After iterating through all elements in the array and checking each one, min_value holds the smallest value among them. The algorithm then returns min_value as the final output.   


### Consider a method of sorting n numbers stored in array A by first finding the smallest element of A and exchanging it with the element in A[1]. Then find the second smallest element of A, and exchange it with A[2].  
 Continue in this manner for the first n − 1 elements of A. Here is pseudocode for this procedure:  
NEW-SORT(A)  
for i = 1 to A.length − 1  
    k = i  
    for j = i to A.length  
        if A[j] < A[k]  
            k = j  
    key = A[k]  
    A[k] = A[i]  
    A[i] = key  

~~~  
NEW-SORT(A)  
for i = 1 to A.length − 1        // Cost: c1, Runs n-1 times  
    k = i                         // Cost: c2, Runs n-1 times  
    for j = i to A.length         // Cost: c3, Runs n-i+1 times per iteration of i  
        if A[j] < A[k]            // Cost: c4, Runs n-i times in worst case  
            k = j                 // Cost: c5, Runs at most n-i times  
    key = A[k]                    // Cost: c6, Runs n-1 times  
    A[k] = A[i]                   // Cost: c7, Runs n-1 times  
    A[i] = key                    // Cost: c8, Runs n-1 times  

//Best Case: T(n) = c1(n-1) + c2(n-1) + c3 (n-i+1) + c4(n-1)/2 + c5 (n-1)/2 + c6(n-1) + c7(n-1) + c8(n-1) =
(c3 + c4/2 + c5/2 ) ((n-1)n/2) + (c1 + c2 + c6 + c7 + c8)(n-1) = O(n^2)

//Average Case: T(n) = c1(n-1) + c2(n-1) + c3 (n-i+1) + c4(n-1) + c5 (n-1) + c6(n-1) + c7(n-1) + c8(n-1) =
(c3 + c4 + c5) ((n-1)n/2) + (c1 + c2 + c6 + c7 + c8)(n-1) = O(n^2)

//Worst Case: T(n) = c1(n-1) + c2(n-1) + c3 (n-i+1) + c4(n-1) + c5 (n-1) + c6(n-1) + c7(n-1) + c8(n-1) =
(c3 + c4 + c5) ((n-1)n/2) + (c1 + c2 + c6 + c7 + c8)(n-1) = O(n^2)

~~~


