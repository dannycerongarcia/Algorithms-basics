// ;==========================================
// ;Tittle: Merge sorts
// ;Author: Danny Ceron Garcia
// ;Date: 10-5-2020
// ;==========================================
int s[] = {120, 10, 69, 420, 42, 143, 117, 823, 0, 1337,11111};
#include <iostream>
#include <vector>
// ==========================================
// mergesort in place

void merge2(int low, int mid, int high)
{
    int i, j, k;
    int *u;
    u = new int[high];
    i = low; j = mid + 1; k = low;
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
            k++; j++;
        }
    }
    // Move s[i] tthrough s[mid]  to u[k] through u[high]
    else
    {
        while (i <= mid && k <= high)
        {
            u[k] = s[i];
            k++; i++;
        }
    }
    //move u[low] through u[high] to s[low] through s[high]
    while(low<=high)
    {
        s[low] = u[low];
        low++;
    }
    delete[] u;
}
void mergesort2(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort2(low, mid);
        mergesort2(mid + 1, high);
        merge2(low, mid, high);
    }
}
// ==========================================



// testing main
int main()
{
    // testing inplce recursive merge
    int n = (int)(sizeof(s)/sizeof(*s));
    std::cout<<"n =" <<n<<std::endl;
    mergesort2(0, n-1);
    int z = 0;
    while(z<n){
        std::cout << s[z] <<'-';
        z++;
    }
    std::cout << std::endl;
    return 0;
}
