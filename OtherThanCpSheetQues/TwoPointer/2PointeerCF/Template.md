Suppose you received a problem at the contest in which you need to do something similar: find the longest (shortest) good segment or count the number of good segments.
How do you know if you can apply the two-pointer method to it?

First, one of the following two properties must be met:

if the segment [L,R] is good, then any segment nested in it is also good (in this case, you can apply the code from the first problem);
if the segment [L,R] is good, then any segment that contains it is also good (in this case, you can apply the code from the second problem).
Secondly, you should be able to recalculate your function (check if current segment is good or bad), while moving the left or right border by one to the right.

In such tasks, the code almost always looks like this:

//My code start here

L = 0
for R = 0..n-1
    add(a[R])
    while not good():
        remove(a[L])
        L++


To solve such problems, you need to implement three functions: add, remove, and good.