// Code Insertion Sort
// Send Feedback
// Provided with a random integer array/list(ARR) of size N, you have been required to sort this array using 'Insertion Sort'.

void insertionSort(int *input, int size)
{
    int i = 1;
    if (size <= 1)
        return;

    while (i < size)
    {
        int k = input[i];

        int j = i - 1;

        while (j >= 0)
        {

            if (input[j] <= k)
            {
                break;
            }

            if (input[j] > k)
            {
                input[j + 1] = input[j];
            }

            j--;
        }

        j++;

        input[j] = k;

        i++;
    }
}
