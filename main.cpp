#include <bits/stdc++.h>
#include "mergeSort.h"
int s0[11] = {120, 10, 69, 420, 42, 143, 117, 823, 0, 1337, 11111};

int main()
{
    // make input and output more efficient
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    // testing inplce recursive merge
    int n = (int)(sizeof(s0) / sizeof(*s0));
    std::cout << "recursive Inplace array merge Sort\n";
    mergesort2(0, n-1,s0);
    int z = 0;
    while (z < n)
    {
        std::cout << s0[z] << '-';
        z++;
    }
    std::cout << "\n\nrecursive merge Sort\n";
   
    int s2[] = {777, 13, 69, 420, 42, 143, 117, 823, 911, 1337,411,880,21,-2,0};
    z = 0;
    n = (int)(sizeof(s2)/sizeof(*s2));
    mergesort(n, s2);
    while (z < n)
    {
        std::cout << s2[z] << ',';
        z++;
    }
    std::cout << "\n\nDynamic merge Sort\n";
    int s3[] = {777, 13, 69, 420, 42, 143, 117, 823, 911, 1337,411,880,21,-1,0,999,1234,59009};
    z = 0;
    n = (int)(sizeof(s3)/sizeof(*s3));
    mergeSort3(n, s3);
    while (z < n)
    {
        std::cout << s3[z] << ',';
        z++;
    }

    std::cout << "\n\n";
    
    return 0;
}