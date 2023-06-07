# CardBST
"Game" simulation. Program reads 2 .txt files, takes data, inserts data into Binary Searh Tree, and compares data. The end of program shows the time program took to run using my implementation of the BST class, compared to a basic linear search comparison which I implemented in linearSearchCompare.cpp. Python file creates random test values, and can be run independent of main.cpp.

# What I learned
* Solidified my understanding of BSTs, and when their usage is most efficient.
* Improved my skills with pointers, and memory allocation/deallocation on the heap.
* Gained experience of writing to .txt files using python, and solidified general numpy skills.
* Wrote my own Makefile to create/delete executable files, object files, and run tests

# How to use
To generate tests using my python program and run game simulation, write:<br />
```make randomTests``` and follow prompt.<br />
To run program multiple times with sample .txt files write:<br />
```make tests```<br />
into your command line.<br />
Feel free to change/add/delete card values in those .txt files to test different values.<br />
c=club, s=spade, h=heart, d=diamond<br />
a=ace, j=jack, q=queen, k=king, 2-10=card number<br />

To delete executable and object files, write:
```make clean```
