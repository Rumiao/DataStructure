/* selectSort implementation */

template <class T>
bool prior(T arg1, T arg2) {
    if (arg1 < arg2) {
        return true;
    }
    return false;
}

template <class T>
void Swap(T A[], int i, int j) {
    T temp = A[i];
    A[j] = A[i];
    A[i] = temp;
}

template <typename T>
void selectSort(T A[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        int lowIndex = i;
        for (int j = length - 1; j > i; --j) {
            if (prior(A[j], A[lowIndex])) {
                lowIndex = j;
            }
        }
        Swap(A, i, lowIndex);
    }
}
