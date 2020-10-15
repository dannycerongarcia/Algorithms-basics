// ;==========================================
// ;Tittle: Merge sorts
// ;Author: Danny Ceron Garcia
// ;Date:   10-5-2020
// ;==========================================
// Most implementation of MergeSort have an average case complexity of T(n) = O(nlogn)
#include <bits/stdc++.h>
#include <math.h>
// ==========================================
// mergesort recursive basic
void merge(int h, int m, const int u[],
                         const int v[], 
                            int newS[])
{
    int i, j, k;
    i = 0;j = 0;k = 0;
    while (i < h && j < m)
    {
        if (u[i] < v[j])
        {
            newS[k] = u[i];
            i++;
        }
        else
        {
            newS[k] = v[j];
            j++;
        }
        k++;
    }
    if (i >= h) // copy v[j] through v[m] to s[k] through s[h+m]
    {
        while (j < m && k < (h + m))
        {
            newS[k] = v[j];
            j++;k++;
        }
    }
    else //copy v[i] through v[h] ti s[k] through s[h+m]
    {
        while (i < h && k < (h + m))
        {
            newS[k] = u[i];
            i++;k++;
        }
    }
}
void mergesort(int n, int newS[])
{
    if (n > 1)
    {
        const int h = (n / 2), m = n - h;
        int *u, *v;
        u = new int[h];
        v = new int[m];
        int i = 0;
        while (i <  h)
        {
            u[i] = newS[i];
            i++;
        }
        int j = 0;i = h ;
        while (j < m)
        {
            v[j] = newS[i];
            j++, i++; 
        }
        mergesort(h, u);
        mergesort(m, v);
        merge(h, m, u, v, newS);
        delete[] u; u = nullptr;
        delete[] v; v = nullptr;
    }
}

// ==========================================
// mergesort in place
void merge2(int low, int mid, int high,int s[])
{
    int i, j, k;
    int *u;
    u = new int[high];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (s[i] < s[j])
        {
            u[k] = s[i];
            i++;
        }
        else
        {
            u[k] = s[j];
            j++;
        }
        k++;
    }
    // Move s[j] through s[high] to u[k] through u[high]
    if (i > mid)
    {
        while (j <= high && k <= high)
        {
            u[k] = s[j];
            k++;j++;
        }
    }
    // Move s[i] tthrough s[mid]  to u[k] through u[high]
    else
    {
        while (i <= mid && k <= high)
        {
            u[k] = s[i];
            k++;i++;
        }
    }
    //move u[low] through u[high] to s[low] through s[high]
    while (low <= high)
    {
        s[low] = u[low];
        low++;
    }
    delete[] u;
    u =nullptr;
}
void mergesort2(int low, int high, int s[])
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort2(low, mid,s);
        mergesort2(mid + 1, high,s);
        merge2(low, mid, high,s);
    }
}

// ==========================================
// mersort Dynamic Programming Approach
void merge3(int low, int mid, int high, int s[])
{
    int i, j, k;
    int *u;
    u = new int[high];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (s[i] < s[j])
        {
            u[k] = s[i];
            i++;
        }
        else
        {
            u[k] = s[j];
            j++;
        }
        k++;
    }
    // Move s[j] through s[high] to u[k] through u[high]
    if (i > mid)
    {
        while (j <= high && k <= high)
        {
            u[k] = s[j];
            k++;j++;
        }
    }
    // Move s[i] tthrough s[mid]  to u[k] through u[high]
    else
    {
        while (i <= mid && k <= high)
        {
            u[k] = s[i];
            k++;i++;
        }
    }
    //move u[low] through u[high] to s[low] through s[high]
    while (low <= high)
    {
        s[low] = u[low];
        low++;
    }
    delete[] u;
    u =nullptr;
}
void mergeSort3(int n, int newS[])
{
    int m,low,mid,high,size;
    // m = 2^((int)log2(n));
    m = n;
    size = 1;
    for(int repeat = 0; repeat<=(int)log2(m); repeat++)
    {
        for(low =0; low<= m-2*size +1; low = low + 2*size)
        {
            mid = low+size-1;
            high = std::min(low+2*size-1,n);
            merge3(low,mid, high, newS);
        }
        size = 2*size;
    }
}

// ==========================================
// mersort LinkedList Approach
// code...