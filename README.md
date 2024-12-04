Identical Binary Trees


If two binary trees share the exact same structure and have the same node values, they are considered identical.

Given references to the root nodes of two binary trees, find out if the trees are identical or not.

Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 3 lines:

The first line contains two space-separated integers n and m denoting the number of nodes in the trees (including the NULL nodes).
The second line contains n space-separated integers that will form the first binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
The second line contains m space-separated integers that will form the first binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output contains a line with 1 or 0 based on whether the trees are identical or not respectively.

Sample Input
5
7 7
1 2 -1 4 -1 5 6
1 2 -1 4 -1 5 6
3 2
6 -1 4
6 1
7 7
8 -1 9 -1 10 11 12
8 -1 9 -1 10 11 12
5 5
28 14 11 -1 48
28 14 10 -1 48
1 1
6
6
Expected Output
1
0
1
0
1