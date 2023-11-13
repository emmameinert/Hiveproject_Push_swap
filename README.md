# Push_swap

Push_swap is an introduction to the world of numbers and algorithms.
Using a certain set of operations it aims to sort numbers with only two stacks.
The programm displays the operations, which were used to sort the numbers.
It was created during my journey at Hive Helsinki.

## My approach

I divided my sorting in two parts: More numbers than 5 and less or equal to 5. 
With less or equal to 5 numbers I have combinations for three numbers sorting. For a greater amount of three I search for the smallest numbers and push them to b until I am down to a 3 number sorting again. Afterwards the numbers from stack b get pushed to a again.

For more than 5 numbers I used the [radix sorting algorithm](https://www.geeksforgeeks.org/radix-sort/) explained below. 

To use the algorithm I convert my integers to binary numbers. For not having negatives in my stack, I make a copy of my stack A and sort the copy recursively.

After that I compare the original stack A with my copy and give each value a new number form 1 to amount of numbers. This new stack A can now be converted easily to binary numbers. It is still unsorted but only contains numbers from 1 to the amount of numbers.

## Operations

sa/sb - Swaps the first 2 elements at the top of stack a/stack b. 

pa/pb - Takes the first elemt of b and puts it on top of stack a/from a to b.

ra/rb Shift up all elements of stack a/b by 1.

rra/rrb: Shifts down all elements of stack a/b by 1.

rrr : rra and rrb at the same time.

ss : sa and sb at the same time.

rr : ra and rb at the same time.

## Algorithm - Radix sort 

Radix sort is a non comperative sorting algorithm with a perfomance of O(nw), with n as the amount of numbers and w the length of those numbers. It goes through the order of numbers digit by digit starting with the last and sorting them into buckets. The more and higher numbers there are, the longer the algorithm takes. In the case of push swap this is illustrated by the operations that are printed out.

## Using radix sort with binary numbers

In Push_swap are only two "buckets" with stack A and B. 
Starting with the first bit of the numbers (the last digit of the number), the number gets either pushed to stack B if its bit is a 1 or Stack A gets rotated to look at the next number if its a 0. 
After going through the whole stack, numbers from B are pushed to A and it all starts again but with the second to last digit. 
