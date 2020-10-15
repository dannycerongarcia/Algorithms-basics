// ;==========================================
// ;Tittle: Main(testing)
// ;Author: Danny Ceron Garcia
// ;Date:   10-14-2020
// ;==========================================
#include <bits/stdc++.h>
#include "mergeSort.h"
#include "quickSort.h"
#ifdef __unix__
    #include <stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif
int s0[11] = {120, 10, 69, 420, 42, 143, 117, 823, 0, 1337, 11111};

// testing in main
int main()
{
    //========================================== Merge Sort ==========================================
    // make input and output more efficient
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    // testing inplce recursive merge
    int n = (int)(sizeof(s0) / sizeof(*s0));
    // system("Color B5"); 
    std::cout << "🔄 Recursive Inplace array merge Sort 🐊\n";
    mergesort2(0, n-1,s0);
    int z = 0;
    // system("Color 04");
    while (z < n)
    {
        std::cout << s0[z] << '-';
        z++;
    }
    // system("Color 06");
    std::cout << "\n\n🔄 Recursive merge Sort 🐊\n";
    int s2[] = {777, 13, 69, 420, 42, 143, 117, 823, 911, 1337,411,880,21,-2,0};
    z = 0;
    n = (int)(sizeof(s2)/sizeof(*s2));
    mergesort(n, s2);
    // system("Color 04");
    while (z < n)
    {
        std::cout << s2[z] << ',';
        z++;
    }
    // system("Color 06");
    std::cout << "\n\n⏩ Dynamic merge Sort 🐊\n";
    int s3[] = {777, 13, 69, 420, 42, 143, 117, 823, 911, 1337,411,880,21,-1,0,999,1234,59009};
    z = 0;
    n = (int)(sizeof(s3)/sizeof(*s3));
    mergeSort3(n, s3);
    // system("Color 04");
    while (z < n)
    {
        std::cout << s3[z] << ',';
        z++;
    }

    std::cout << "\n\n";
    //======================================== End Merge Sort ========================================
    //========================================== Quick Sort ==========================================
    int s4[]={0,1,120, 10, 69, 420, 42, 143, 117, 823, -69, 1337, 11111};
    quickSort(0,(int)(sizeof(s4)/sizeof(*s4)),s4);
    // system("Color 06");
    std::cout<<"🔄 Quick Sort 🐊\n";
    // system("Color 04");
    for(int number:s4)
    {
        std::cout<<number<<",";
    }
    std::cout<<"\n";
    //======================================== End Quick Sort ========================================
    return 0;
}