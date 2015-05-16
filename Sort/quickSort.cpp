/* Quick sort implementation */

template <typename T>
void Swap(T A[], int i, int j) {
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <typename T>
bool prior(T arg1, T arg2) {
    if (arg1 < arg2) {
        return true;
    }
    return false;
}

template <typename T>
inline int findPivot(T A[], int first, int last) {
    return (first + last) / 2;
}

template <typename T>
inline int partition(T A[], int first, int last, T& pivot_value) {
    do {
        while (prior(A[++first], pivot_value));                     // Move first right and
        while ((last > first) && prior(pivot_value, A[--last]));    // last left
        Swap(A, first, last);                           // Swap out-of-place value
    } while (first < last);                             // Stop when they cross
    return first;
}

template <typename T>
void quickSort(T A[], int first, int last) {
    if (last <= first) {                                // Don't sort 0 or 1 element
        return;
    }
    int pivot_index = findPivot(A, first, last);        // Find the pivot'index, this pivot_value may work good
    Swap(A, pivot_index, last);                         // Put pivot at end
    int k = partition<T>(A, first - 1, last, A[last]);  //
    Swap(A, k, last);
    quickSort(A, first, k - 1);
    quickSort(A, k + 1, last);
}

