#include <cstdio>
char str[] = "No. 1\n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 2\n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 3\n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 4\n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 5\n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 6\n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 7\n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 8\n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 9\n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 10\n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 11\n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 12\n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
No. 13\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 14\n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 15\n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 16\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 17\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 18\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 19\n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 20\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 21\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 22\n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 23\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 24\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 25\n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 26\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 27\n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 28\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
No. 29\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 30\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 31\n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
No. 32\n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 33\n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 34\n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 35\n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 36\n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
No. 37\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
No. 38\n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 39\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 40\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 41\n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 42\n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
No. 43\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 44\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
No. 45\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
No. 46\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
No. 47\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 48\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 49\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 50\n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
No. 51\n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 52\n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 53\n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 54\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
No. 55\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 56\n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 57\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 58\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 59\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 60\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
No. 61\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 62\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 63\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
No. 64\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
No. 65\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 66\n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 67\n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 68\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 69\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 70\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
No. 71\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
No. 72\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
No. 73\n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 74\n\
0 0 0 0 0 0 1 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 75\n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 76\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 77\n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 78\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
No. 79\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 80\n\
0 0 0 0 1 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 1 0 0 0 0 0 0 \n\
No. 81\n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 82\n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 83\n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 1 0 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
No. 84\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 85\n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 1 0 0 0 0 0 \n\
No. 86\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
No. 87\n\
0 0 0 0 0 1 0 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
No. 88\n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
No. 89\n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
1 0 0 0 0 0 0 0 \n\
No. 90\n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
1 0 0 0 0 0 0 0 \n\
No. 91\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 1 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n\
No. 92\n\
0 0 1 0 0 0 0 0 \n\
0 0 0 0 0 1 0 0 \n\
0 0 0 1 0 0 0 0 \n\
0 1 0 0 0 0 0 0 \n\
0 0 0 0 0 0 0 1 \n\
0 0 0 0 1 0 0 0 \n\
0 0 0 0 0 0 1 0 \n\
1 0 0 0 0 0 0 0 \n";
int main(){
    printf("%s",str);
    return 0;
}
