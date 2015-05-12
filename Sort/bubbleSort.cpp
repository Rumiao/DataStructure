/* Bubble sort implementation */

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
void bubbleSort(T A[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = length - 1; j > i; --j) {
            if (prior(A[j], A[j - 1])) {
                Swap(A, j, j - 1);
            }
        }
    }
}
