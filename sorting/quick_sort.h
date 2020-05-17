#include <algorithm>

int Partition(int* arr, int low, int high) {
	int pivot = arr[high];	// pivot
	int i = (low - 1);		// Index of smaller element

	for (int j = low; j < high; j++) {
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot) {
			i++;  // increment index of smaller element
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i+1], arr[high]);
	return (i + 1);
}

void QuickSort(int* arr, int low, int high) {
	if (low < high) {
		int p = Partition(arr, low, high);

		QuickSort(arr, low, p - 1);
		QuickSort(arr, p + 1, high);
	}
}
