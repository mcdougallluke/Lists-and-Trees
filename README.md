## CS 241 Data Organization using C

## Linked Lists and Binary Trees

## Brooke Chenoweth

## Fall 2021

```
This assignment is designed to let you work with linked lists and binary trees.
```
## Problem specification

I have provided header files defining some functions related to linked lists and binary trees.
I have also provided you with files to test these functions and a makefile to build it all.

## Linked Lists

In a file namedlinkedlist.c, implement all the functions declared inlinkedlist.hand
make sure they work withlisttest.c.

## Binary Trees

In a file namedbinarytree.c, implement all the functions declared inbinarytree.hand
make sure they work withtreetest.c.

## 1 Grading Rubric (total of 25 points + 3 bonus)

-2 point : The programs do not start with a comment stating the students first and last
name and/or the source files are not named correctly.

-5 points: Programs compile with warnings on moons.cs.unm.edu using /usr/bin/gcc
with the-Wall -ansi -pedanticoptions (using the makefile)

-5 points: Programs leak memory when tested with valgrind.

5 points : All code follows the CS-241 standards (including comments).

10 points : Output of runninglisttestmatcheslisttestout.txt.

### 1


+1 bonus point : Don’t create or destroy any nodes in thereverseListfunction. (This
would also include indirectly creating/destroying nodes via the stack manipulation
functions.) In other words, reverse the list in place by changing the pointers.

10 points : Output of runningtreetestmatchestreetestout.txt.

+1 bonus point : Only traverse the tree once in theisBalancedfunction. (The naive
implementation usingmaxDepthdoes not meet this requirement.)

+1 bonus point : Only traverse the tree once in theisBSTfunction.

### 2


