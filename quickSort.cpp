// ;==========================================
// ;Tittle: Quick sorts 🐊
// ;Author: Danny Ceron Garcia
// ;Date:   10-13-2020
// ;==========================================
// ;Worst case: 𝙣(𝙣-1)/2 ∈ Θ(𝙣²)
// ;Avg   case: 1.38(𝙣+1)𝙣log𝙣 ∈ Θ(𝙣log𝙣) 
#include <bits/stdc++.h>
#include <math.h>
// glabal test array
// int s[]={0,1,120, 10, 69, 420, 42, 143, 117, 823, 0, 1337, 11111};
// ========================================== Quick Sort ==========================================
void partition(int low,int high, int& pivotpoint,int s[])
{
    int i,j;
    j = low;
    int pivotItem = s[low];
    for(i = low+1; i<high; i++)
    {
        if(s[i] < pivotItem)
        {
            j++;
            int temp = s[j];
            s[j] = s[i];
            s[i] = temp;
        }
    }
    pivotpoint = j;
    int temp = s[pivotpoint];
    s[pivotpoint] = s[low];
    s[low] = temp;
}
void quickSort(int low, int high, int s[])
{
    int pivotpoint;
    if(high>low)
    {
        partition(low,high, pivotpoint,s);
        quickSort(low,pivotpoint-1,s);
        quickSort(pivotpoint+1,high,s);
    }
}
// ================================================================================================
