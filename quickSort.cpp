// ;==========================================
// ;Tittle: Merge sorts
// ;Author: Danny Ceron Garcia
// ;Date:   10-13-2020
// ;==========================================
#include <bits/stdc++.h>
#include <math.h>
// glabal test array
// int s[]={0,1,120, 10, 69, 420, 42, 143, 117, 823, 0, 1337, 11111};

void partition(int low,int high, int& pivotpoint,int s[])
{
    int i,j;
    int pivotItem = s[low];
    j = low;
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