#include <stdio.h>
#include <stdlib.h>

void print_arr(int arr[], int n, const char *end) {
    putchar('[');
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i < (n - 1)) printf(", ");
    }
    printf("]%s", end);
}

int bin_search(int x, int v[], int n) {
    int low, high, mid;
    int it = 0;
    low = 0;
    high = n - 1;
    while (low < high) {
        ++it;
        printf("it: %d\n", it);
        mid = (low + high) / 2;
        if (x <= v[mid]) high = mid;
        else low = mid + 1;
    }
    if (v[high] == x) return high;
    return -1;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    int it = 0;
    low = 0;
    high = n - 1;
    while (low <= high) {
        ++it;
        printf("it: %d\n", it);
        mid = (low + high) / 2;
        if (x < v[mid]) high = mid - 1;
        else if (x > v[mid]) low = mid + 1;
        else return mid;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_size = 10;
    int key = 0;

    printf("# binsearch 1 #\n");
    print_arr(arr, arr_size, "\n");
    int index = binsearch(key, arr, arr_size);
    printf("index: %d\n", index);
    printf("# binsearch 2 #\n");
    print_arr(arr, arr_size, "\n");
    index = bin_search(key, arr, arr_size);
    printf("index: %d\n", index);

    return EXIT_SUCCESS;
}
