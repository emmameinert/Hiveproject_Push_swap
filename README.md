# Push_swap

Push_swap is an introduction to the world of numbers and algorithms.
Using a certain set of operations it aims to sort numbers with only two stacks.

## My approach

I divided my sorting in two parts: More numbers than 5 and less or equal to 5. 
With less or equal to 5 numbers I have combinations for three numbers sorting. For a greater amount of three I search for the smallest numbers and push them to b until I am down to a 3 number sorting again. Afterwards the numbers from stack b get pushed to a again.

For more than 5 numbers I used the radix sorting algorithm explained below.

## Operations

sa/sb - Swaps the first 2 elements at the top of stack a/stack b. 

pa/pb - Takes the first elemt of b and puts it on top of stack a/from a to b.

ra/rb Shift up all elements of stack a/b by 1.

rra/rrb: Shifts down all elements of stack a/b by 1.

rrr : rra and rrb at the same time.

ss : sa and sb at the same time.

rr : ra and rb at the same time.

## Algorithm - Radix sort 

Radix sort is a non comperative sorting algorithm with a perfomance of O(nw), with n as the amount of numbers and w the length of those numbers.

To use the radix sort algorithm I convert my integers to binary numbers. For not having negatives or missing numbers in my stack, I make a copy of my stack A and sort the copy recursively.

After that I compare the original stack A with my copy and give each value a new number form 1 to amount of numbers. This new stack A can now be converted easily to binary numbers. It is still unsorted but only contains numbers from 1 to the amount of numbers.

Starting on the most right of the number, it gets either pushed to stack B if its a 1 or Stack A gets rotated to look at the next number if its a 0. 
