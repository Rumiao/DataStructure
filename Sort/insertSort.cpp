/* Insert sort implementation */

template <typename T>
bool prior(T arg1, T arg2) {
    if (arg1 < arg2) {
        return true;
    }
    return false;
}

template <typename T>
inline void Swap(T A[], int i, int j) {
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <typename T>
void insertSort(T A[], int length) {
    for (int i = 1; i < length; ++i) {
        for (int j = i; (j > 0) && (prior(A[j], A[j - 1])); --j) {
            Swap(A, j, j - 1);
        }
    }
}

