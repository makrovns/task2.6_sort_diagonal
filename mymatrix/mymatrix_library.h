#pragma once
#include <initializer_list>
#include <utility>
#include <vector>

namespace mymatrix
{
    class Matrix
    {
    public:

        Matrix();
        Matrix(size_t rows);
        Matrix(size_t coloms, size_t rows);
        Matrix(const std::initializer_list<std::initializer_list<int>>& list);

        size_t length() const;
        std::vector<int>& operator[](size_t i);

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(const std::initializer_list<std::initializer_list<int>>& list);
    
        void sort_diagonal();

    private:
        using my_matrix = std::vector<std::vector<int>>;

        size_t size_;
        my_matrix two_dem_array;
    };
}
