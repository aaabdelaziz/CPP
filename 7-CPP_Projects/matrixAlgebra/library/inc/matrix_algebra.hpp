
// matrix_algebra.hpp : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <array>

namespace cie1
{
   // Classes 
    class Matrix {

        std::vector<double> matrix_;
        double scalar_;
        int size_;
        size_t rows_;                     
        size_t cols_;

    public:
        Matrix();
        Matrix(std::array<size_t, 2> size);
        Matrix(std::vector< std::vector<double> > matrix);
        std::array<size_t, 2> size();
        void print(std::string matrixName);
        void resize(std::array<size_t,2> newSize);
        double& operator ( ) (size_t i, size_t j);
        const double& operator ( ) (size_t i, size_t j) const;
        Matrix operator + (const Matrix& rhs) const;
        Matrix operator + (const double& scalar) const;
        Matrix operator - (const Matrix& rhs) const;
        Matrix operator - (const double& scalar) const;
        Matrix operator * (const Matrix& rhs) const;
        Matrix operator * (const double& scalar) const;
        Matrix operator / (const Matrix& rhs) const;
        Matrix operator / (const double& scalar) const;
        Matrix operator ^(const double& scalar) const;
        double norm() const;
        double determinant(const Matrix& matrix);
        std::vector<double> dot(std::vector<double>& vector) const;
        Matrix matmul(Matrix rhs) const;
    };

    // Functions ProtoTypes
    void MatrixDisplay(const std::vector<std::vector<double>>& augmentedMatrix, const int& n, const int& limit, const std::string& msg);
    /*void MatrixLog(const std::vector<std::vector<double>>& augmentedMatrix,
                   const int& n, const int& limit, const std::string& msg);*/


} // namespace cie
