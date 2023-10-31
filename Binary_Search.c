#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n,target;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);

    int arr[n],x[n];
    for (int i = 0; i < n; i++) {
         printf("\nEnter sorted element %d:", i+1);
        scanf("%d", &x[i]);
        if(x[i]>x[i-1]){
            arr[i]=x[i];
        }else{
            printf("Not sorted");
            return 0;
        }
    }
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
