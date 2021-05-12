#include <gtest/gtest.h>
#include "mymatrix_library.h"


TEST(mymatrix_test, test_for_right_write)
{
    mymatrix::Matrix a{ {1,2,3,4},{5,6,7,8},{8,7,6,5},{4,3,2,1} };

    std::vector<std::vector<int>> av = { {1,2,3,4},{5,6,7,8},{8,7,6,5},{4,3,2,1} };

    for (size_t i = 0; i != a.length(); i++)
    {
        for (size_t j = 0; j != a[0].size(); j++)
        {
            ASSERT_EQ(a[i][j], av[i][j]);
        }
    }
}

TEST(mymatrix_test, test_for_right_assign) 
{
    mymatrix::Matrix a{ {1,2,3,4},{5,6,7,8},{8,7,6,5},{4,3,2,1} };
    a = { {3,3,1,1}, {2, 2, 1, 2}, {1, 1, 1, 2} };

    std::vector<std::vector<int>> av = { {3,3,1,1}, {2, 2, 1, 2}, {1, 1, 1, 2} };

    for (size_t i = 0; i != a.length(); i++)
    {
        for (size_t j = 0; j != a[0].size(); j++)
        {
            ASSERT_EQ(a[i][j], av[i][j]);
        }
    }
}

TEST(mymatrix_test, test_for_right_sort_expample_in_task)
{
    mymatrix::Matrix a{ {3,3,1,1}, {2, 2, 1, 2}, {1, 1, 1, 2} };
    
    a.sort_diagonal();

    std::vector<std::vector<int>> av = { {1,1,1,1}, {1, 2, 2, 2}, {1, 2, 3, 3} };

    for (size_t i = 0; i != a.length(); i++)
    {
        for (size_t j = 0; j != a[0].size(); j++)
        {
            ASSERT_EQ(a[i][j], av[i][j]); 
        }
    }
}

TEST(mymatrix_test, test_one_to_one_matrix)
{
    mymatrix::Matrix a = { {1} };

    std::vector<std::vector<int>> av{ {1} };
    
    ASSERT_EQ(a[0][0], av[0][0]);
}

TEST(mymatrix_test, test_for_some_matrix) 
{
    mymatrix::Matrix a{ {4,2,1,4,5,6,4}, {2, 2, 1, 2, 0, 8, 5}, {5, 3, 1, 6, 8, 1, 10}, {23, 2, 41, 4, 7, 11, 21}, {0, 1, 2, 1, 3, 6, 1},
    {7, 15, 12, 13, 4, 5, 6, 7} };

    a.sort_diagonal();

    std::vector<std::vector<int>> av = { {1, 1, 1, 0, 5, 5, 4}, {1, 2, 2, 1, 1, 8, 6}, {2, 2, 3, 6, 2, 4, 10}, {1, 2, 3, 4, 6, 8, 21 },
    {0, 12, 5, 4, 4, 6, 11}, {7, 15, 23, 13, 41, 5, 7} };

    for (size_t i = 0; i != a.length(); i++)
    {
        for (size_t j = 0; j != a[0].size(); j++)
        {
            ASSERT_EQ(a[i][j], av[i][j]);
        }
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}