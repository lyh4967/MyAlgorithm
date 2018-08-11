#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void merge(int arr[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int tmp_arr[1000000];
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			tmp_arr[k] = arr[i];
			i++;
		}
		else {
			tmp_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int m = j; m <= right; m++) {
			tmp_arr[k] = arr[m];
			k++;
		}
	}
	else {
		for (int m = i; m <= mid; m++) {
			tmp_arr[k] = arr[m];
			k++;
		}
	}
	for (int m = left; m <= right; m++)
		arr[m] = tmp_arr[m];
}
void mergeSort(int*arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}
void quickSort(int* arr,int left,int right) {
	int keyIndex = left;
	int endIndex = right;
	int key = arr[left];
	right = right + 1;
	if (left < right) {
		do {
			do {
				left++;
			} while (arr[left] < key);
			do {
				right--;
			} while (arr[right] > key);
			if (left < right) {
				swap(arr[left], arr[right]);
			} 
		} while (left < right);
		swap(arr[right], arr[keyIndex]);
		quickSort(arr, keyIndex,right - 1);
		quickSort(arr, right + 1, endIndex);
	}
}

int main() {

	int n; scanf("%d", &n);
	int arr[1000000];

	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	mergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++) {
		 printf("%d\n",arr[i]);
	}
	return 0;

}