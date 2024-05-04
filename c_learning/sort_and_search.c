#include <stdio.h>

void print_arr(int arr[], int n) {
  printf("Array: [");

  for(int i = 0; i < n-1; i++) {
    printf("%d, ", arr[i]);
  }

  printf("%d]\n", arr[n-1]);
}


// Returns index of 'target' within 'arr' or -1
// if the target is not present
int binarySearch(int arr[], int l, int r, int target) {
  while (l < r) {
    int m = l + ((r - l) / 2);

    if (arr[m] == target) {
      return m;
    } else if (arr[m] > target) {
      r = m-1;
    } else {
      l = m+1;
    }
  }

  // target not found;
  return -1;
}

// merges two subarrays of arr[]
// first subarray is arr[l:m]
// second subarray is arr[m+1:r]
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m-l+1;
  int n2 = r-m;

  // temp arrs
  int L[n1], R[n2];

  // Copy data to temp arrays
  for (i = 0; i < n1; i++) {
    L[i] = arr[l+i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m+1+j];
  }

  // Reset indices
  i=0;
  j=0;
  k=l;

  // Merge elements of L and R back into arr
  while(i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      // Left candidate is smaller
      arr[k] = L[i];
      i++;
    } else {
      // Right candidate is strictly smaller
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining entries
  while(i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {

  if (l < r) {
    int m = l + ((r-l) / 2);

    printf("MS: %d, %d, %d\n", l, m, r);

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    
    merge(arr, l, m, r);
  }

}

int main() {
  printf("Hello %s.\n", "Alexander");

  int my_arr[10] = {1, 3, 3, 7, 9, 11, 11, 21, 43, 61};

  print_arr(my_arr, 10);

  int target = 21;
  int find = binarySearch(my_arr, 0, 9, target);

  printf("%d was found at index %d in my_arr\n", target, find);

  int unsorted_arr[10] = {5, 7, 2, 23, 91, 16, 37, 85, 22, 15};

  print_arr(unsorted_arr, 10);

  mergeSort(unsorted_arr, 0, 9);

  print_arr(unsorted_arr, 10);
  
  return 0;
}

