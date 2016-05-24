Assume everytime we switch one button from the four button,
we made a transition from a node to another.

So each node, we have four out line, pointing to other nodes.

if we mark button 1 as A, button 2 as B, button 3 as C, button 4 as D.

we mark eight nodes as 1, 2, 3, 4, 5, 6, 7, 8.

we suggest initial all lamps on as node 1.

Then we have another 4 nodes from node 1 if we switch A, B, C and D.

node 1 -> node 2 (A)
node 1 -> node 3 (B)
node 1 -> node 4 (C)
node 1 -> node 5 (D)

from node 2:

node 2 -> node 1 (A)
node 2 -> node 3 (C)
node 2 -> node 4 (B)
node 2 -> node 6 (D)

3: 1, 2, 4, 7

4: 1, 2, 3, 8

5: 1, 7, 8, 6

6: 2, 5, 7, 8

7: 3, 5, 8, 6

8: 4, 5, 7, 6

After we draw this graph, if we start from node 1.

Step 0: 1

Step 1: 2, 3, 4, 5

Step 2: 1, 2, 3, 4, 6, 7, 8

Step 3: 1, 2, 3, 4, 5, 6, 7, 8

More steps will reached at any node in the eight nodes.


