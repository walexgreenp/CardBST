# CardBST
"Game" simulation. Program reads 2 .txt files, takes data, inserts data into Binary Searh Tree, and compares data. 

# What I learned
* Solidified my understanding of BSTs, and when their usage is most efficient.
* Improved my skills with pointers, and memory allocation/deallocation on the heap.
* Gained experience with using .txt files, as well as translating data into easier to use values.
* Wrote my own Makefile to create/delete executable files, object files, and run tests

# How to use
To run program multiple times with all sample .txt files write:<br />
```make tests```<br />
into your command line.<br />
Feel free to change/add/delete card values in those .txt files to test different values.<br />
c=club, s=spade, h=heart, d=diamond<br />
a=ace, j=jack, q=queen, k=king, 2-10=card number<br />

To delete executable and object files, write:
```make clean```
