// Push Zeros to end
// Send Feedback
// You have been given a random integer array/list(ARR) of size N. You have been required to
// push all the zeros that are present in the array/list to the end of it. Also, make sure to maintain the relative order of the non-zero elements.

// Note:
// Change in the input array/list itself. You don't need to return or print the elements.
// You need to do this in one scan of array only. Don't use extra space.

void pushZeroesEnd(int *input, int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] != 0)
        {
            input[j] = input[i];
            j++;
        }
    }
    for (int i = j; i < size; i++)
    {
        input[i] = 0;
    }
}
