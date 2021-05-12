#include "mymatrix_library.h"

mymatrix::Matrix::Matrix() : size_(0), two_dem_array(0) {}

mymatrix::Matrix::Matrix(size_t rows) : size_(rows), two_dem_array(rows) {}

mymatrix::Matrix::Matrix(size_t coloms, size_t rows) : Matrix(rows)
{
    for (auto& element : two_dem_array)
    {
        element = std::vector<int>(coloms);
    }
}

mymatrix::Matrix::Matrix(const std::initializer_list<std::initializer_list<int>>& list) : Matrix(list.size())
{
    int cnt = 0;
   
    for (auto& element : list)
    {
        two_dem_array[cnt++] = element;
    }
}

size_t mymatrix::Matrix::length() const { return size_; }

std::vector<int>& mymatrix::Matrix::operator[](size_t i) { return two_dem_array[i]; }

mymatrix::Matrix& mymatrix::Matrix::operator=(const mymatrix::Matrix& other)
{
    if (&other != this)
    {
        size_ = other.size_;
        two_dem_array = other.two_dem_array;
    }

    return *this;
}

mymatrix::Matrix& mymatrix::Matrix::operator=(const std::initializer_list<std::initializer_list<int>>& list)
{
    if (list.size() != size_)
    {
        size_ = list.size();
        two_dem_array = my_matrix(size_);
    }

    int cnt = 0;

    for (auto& element : list)
    {
        two_dem_array[cnt++] = element;
    }

    return *this;
}

void mymatrix::Matrix::sort_diagonal()
{
    size_t coloms = two_dem_array[0].size();

    if (size_ != 0 && coloms != 0) {

        for (int k = 1; k <= size_; ++k)
            for (int i = 0; i != size_ - k; ++i)
                for (int j = 0; j != coloms - k; ++j)
                    if (two_dem_array[i][j] > two_dem_array[i + 1][j + 1])
                        std::swap(two_dem_array[i][j], two_dem_array[i + 1][j + 1]);
    }
}

