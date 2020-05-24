#ifndef SORT_H
#define SORT_H

#include <algorithm>
#define BEAD(i, j) beads[i * max + j]

void BeadSort(int* arr, int n) {
    // Find the maximum element
    int max = *std::max_element(arr, arr + sizeof(arr[0]) * n);

    // allocating memory
    bool* beads = new bool[max * n];
    std::fill(beads, beads + sizeof(bool) * max * n, 0);

    // mark the beads
    for (int i = 0; i < n; i++)
        for (int j = 0; j < arr[i]; j++) BEAD(i, j) = 1;

    for (int j = 0; j < max; j++) {
        // count how many beads are on each post
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }

        // Move beads down
        for (int i = n - sum; i < n; i++) BEAD(i, j) = 1;
    }

    // Put sortednluesn arransing beads
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < max && BEAD(i, j); j++) arr[i] = j;
    }
    delete[] beads;
}

void InsertionSort(int* arr, int n) {
    int new_val, j;
    for (int i = 1; i < n; i++) {
        new_val = arr[i];
        for (j = i - 1; j >= 0 && new_val < arr[j];) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = new_val;
    }
}

void ShellSort(int* arr, int n) {
    for (int gap = n / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; j >= 0; j = j - gap) {
                if (arr[j] < arr[j + gap]) {
                    break;
                } else {
                    std::swap(arr[j], arr[j + gap]);
                }
            }
        }
    }
}

void BubbleSort(int* arr, int low, int high) {
    bool swap_check = true;
    for (int i = low; (i < high) && (swap_check); i++) {
        swap_check = false;
        for (int j = 0; j < high - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_check = true;
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SelectinSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int* min_loc = std::min_element(&arr[i], &arr[n]);
        std::swap(arr[i], *min_loc);
    }
}

// Quick Sort
int Partition(int* arr, int low, int high) {
    int pivot = arr[high];	// pivot
    int i = low - 1;		// Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void QuickSort(int* arr, int low, int high) {
    if (low < high) {
        int p = Partition(arr, low, high);

        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}

// Merge Sort
void Merge(int* arr, int l, int m, int r) {
    int len = r - l + 1;
    int* newloc = new int[len];

    // Copy data to newloc in order
    int i = l;
    int j = m + 1;
    int k = 0;
    for (; (i <= m) && (j <= r); ++k) {
        if (arr[i] <= arr[j]) {
            newloc[k] = arr[i];
            ++i;
        } else {
            newloc[k] = arr[j];
            ++j;
        }
    }

    std::copy(&arr[i], &arr[m + 1], &newloc[k]);
    std::copy(&arr[j], &arr[r + 1], &newloc[k]);

    // Copy back & clean up
    std::copy_n(newloc, len, &arr[l]);
    delete[] newloc;
}
void MergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}

// Heap Sort
void Heapify(int* arr, int n, int root) {
    int largest = root;	// Initialize largest as root
    int l = 2 * root + 1;	// left = 2*i + 1
    int r = 2 * root + 2;	// right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) largest = r;

    // If largest is not root
    if (largest != root) {
        std::swap(arr[root], arr[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(arr, n, largest);
    }
}
void HeapSort(int* arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) Heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}

#endif	// SORT_H
