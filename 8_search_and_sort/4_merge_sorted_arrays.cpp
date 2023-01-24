// Code Merge Two Sorted Arrays
// Send Feedback
// You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively,
// merge them into a third array/list such that the third array is also sorted.

void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            ans[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            ans[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < size1)
    {
        ans[k] = arr1[i];
        k++;
        i++;
    }

    while (j < size2)
    {
        ans[k] = arr2[j];
        k++;
        j++;
    }
}
