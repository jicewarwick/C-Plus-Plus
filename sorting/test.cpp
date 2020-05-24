#include <gtest/gtest.h>

#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "sort.h"

using std::vector;

class SortingTest : public ::testing::Test {
public:
    static vector<int> GenerateRandomInt(int n, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, max);

        vector<int> output;
        for (int i = 0; i < n; ++i) output.push_back(dis(gen));
        return output;
    }

    static bool isSorted(const vector<int> input_vec) {
        for (size_t i = 1; i < input_vec.size(); ++i) {
            if (input_vec[i - 1] > input_vec[i]) {
                return false;
            }
        }
        return true;
    }
};

TEST(SortingTest, BeadSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        BeadSort(random_number.data(), n);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}
TEST(SortingTest, QuickSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        QuickSort(random_number.data(), 0, n);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}
TEST(SortingTest, BubbleSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        BubbleSort(random_number.data(), 0, n);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}
TEST(SortingTest, MergeSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        MergeSort(random_number.data(), 0, n - 1);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}
TEST(SortingTest, ShellSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        ShellSort(random_number.data(), n);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}
TEST(SortingTest, InsertionSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        InsertionSort(random_number.data(), n);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}
TEST(SortingTest, SelectionSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        SelectinSort(random_number.data(), n);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}
TEST(SortingTest, HeapSortTest) {
    int num_test = 10;
    int n = 20;
    int max = 50;
    for (int i = 0; i < num_test; ++i) {
        vector<int> random_number = SortingTest::GenerateRandomInt(n, max);
        HeapSort(random_number.data(), n);
        ASSERT_TRUE(SortingTest::isSorted(random_number));
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
