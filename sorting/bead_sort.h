// C++ program to implement gravity/bead sort
#include <algorithm>

#define BEAD(i, j) beads[i * max + j]

// function to perform the above algorithm
void BeadSort(int *a, int len) {
    // Find the maximum element
    int max = *std::max_element(a, a + sizeof(a[0]) * len);

    // allocating memory
    bool* beads = new bool[max * len];
    std::fill(beads, beads + sizeof(bool) * max * len, 0);

    // mark the beads
    for (int i = 0; i < len; i++)
        for (int j = 0; j < a[i]; j++) BEAD(i, j) = 1;

    for (int j = 0; j < max; j++) {
        // count how many beads are on each post
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }

        // Move beads down
        for (int i = len - sum; i < len; i++) BEAD(i, j) = 1;
    }

    // Put sorted values in array using beads
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < max && BEAD(i, j); j++)
            a[i] = j;
    }
    delete[] beads;
}
