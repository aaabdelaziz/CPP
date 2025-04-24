
#include "matrix_algebra.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
//#include <armadillo>

namespace cie1
{

	// Default Constructor 
	Matrix::Matrix() : rows_(0), cols_(0)
	{

	}

	// Parametrized Constructor with Array
	Matrix::Matrix(std::array<size_t, 2> size) : rows_(size[0]), cols_(size[1]) {
		// Initialize the matrix with zeros
		matrix_.resize(rows_ * cols_, 0.0);
	}

	// Parametrized Constructor with Vector
	Matrix::Matrix(std::vector< std::vector<double> > matrix) {
		rows_ = matrix.size();
		cols_ = rows_ > 0 ? matrix[0].size() : 0;

		// Flatten 2D vector into 1D vector
		matrix_.reserve(rows_ * cols_);
		for (const auto& row : matrix) {
			if (row.size() != cols_) {
				throw std::runtime_error("Constructor: All rows must have the same number of columns.\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );
			}
			matrix_.insert(matrix_.end(), row.begin(), row.end());
		}
	}

	// Get Matrix Size
	std::array<size_t, 2> Matrix::size() {
		return {rows_,cols_};
	}

	// Resize Matrix
	void Matrix::resize(std::array<size_t, 2> newSize) {
		size_t newRows = newSize[0];
		size_t newCols = newSize[1];

		// Create a new matrix with new size, initialized to zeros
		std::vector<std::vector<double>> newMatrix(newRows, std::vector<double>(newCols, 0.0));

		// Iterate over the old matrix and copy elements to the new matrix
		for (size_t i = 0; i < std::min(rows_, newRows); i++) {
			for (size_t j = 0; j < std::min(cols_, newCols); j++) {
				newMatrix[i][j] = matrix_[i * cols_ + j]; // Copy old elements to new matrix
			}
		}

		// Clear the existing 1D matrix values
		matrix_.clear();

		// Update the matrix in class
		// Iterate through each row of the new matrix and flatten it into the 1D vector
		for (const auto& row : newMatrix) {
			matrix_.insert(matrix_.end(), row.begin(), row.end());
		}


		// Update row and column counts
		rows_ = newRows;
		cols_ = newCols;
	}

	// Print Matrix elements
	void Matrix::print(std::string matrixName) {
		
		std::cout << matrixName << std::endl;

		for (size_t i = 0; i < rows_; ++i) {         // Rows
			for (size_t j = 0; j < cols_; ++j) {     // index in each row
				std::cout  << std::setprecision(4)   // Set precision to 4 decimal places in float
					       << std::setw(6)           // Set width of 10 places for each printed number
					        << (*this)(i, j) << " "; // Use the overloaded operator
			}
			std::cout << std::endl; // New line for the next row
		}
	}

	// Overloaded operator () for accessing matrix elements
	double& Matrix::operator () (size_t i, size_t j) {
		if (i >= rows_ || j >= cols_) {
			throw std::out_of_range("Operator(): Matrix indices are out of range.");
		}
		return matrix_[i * cols_ + j]; // Access the 1D vector
	}

	// Overloaded operator () for accessing matrix elements
	const double& Matrix::operator () (size_t i, size_t j) const {
		if (i >= rows_ || j >= cols_) {
			throw std::out_of_range("Operator(): Matrix indices are out of range.");
		}
		return matrix_[i * cols_ + j]; // Access the 1D vector
	}

	// Operator Overload for Matrix Addition
	Matrix Matrix::operator + (const Matrix& rhs) const {
		if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
			throw std::runtime_error("Matrix dimensions must agree for addition.\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );
		}

		Matrix result({ rows_, cols_ });
		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result(i, j) = (*this)(i, j) + rhs(i, j);
			}
		}
		return result;
	}

	// Operator Overload for Adding a scalar
	Matrix Matrix::operator + (const double& scalar) const {
		Matrix result({ rows_, cols_ });
		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result(i, j) = (*this)(i, j) + scalar;
			}
		}
		return result;
	}

	// Operator Overload for Matrix Subtraction
	Matrix Matrix::operator - (const Matrix& rhs) const {
		if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
			throw std::runtime_error("Matrix dimensions must agree for subtraction.\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );
		}

		Matrix result({ rows_, cols_ });
		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result(i, j) = (*this)(i, j) - rhs(i, j);
			}
		}
		return result;
	}

	// Operator Overload for Subtracting a scalar
	Matrix Matrix::operator - (const double& scalar) const {
		Matrix result({ rows_, cols_ });
		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result(i, j) = (*this)(i, j) - scalar;
			}
		}
		return result;
	}

	// Operator Overload for Matrix Multiplication
	Matrix Matrix::operator * (const Matrix& rhs) const {
		return this->matmul(rhs);  // Utilize matmul for matrix multiplication
	}

	// Operator Overload for Multiplying with a scalar
	Matrix Matrix::operator * (const double& scalar) const {
		Matrix result({ rows_, cols_ });
		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result(i, j) = (*this)(i, j) * scalar;
			}
		}
		return result;
	}

	// Operator Overload for Matrix power
	Matrix Matrix::operator ^ (const double& scalar) const {
		Matrix result({ rows_, cols_ }); // Create a new matrix for the result

		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result(i, j) = std::pow((*this)(i, j), scalar); // Raise each element to the scalar power
			}
		}

		return result; // Return the resulting matrix
	}

	// Operator Overloaded for Matrix Division using Gauss-elemenation method
	Matrix Matrix::operator / (const Matrix& rhs) const {

		// Check rhs for square matrix
		if (rhs.rows_ != rhs.cols_) {
			throw std::runtime_error("Matrix must be square to find the inverse.\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );
		}

		// Check if num of columns for lhs = num of rows for rhs
		if ((*this).cols_ != rhs.rows_) {
			throw std::runtime_error("lhs Matrix num of columns != rhs Matrix- num of rows\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );

		}

		int n = rhs.rows_;		
		// 1- Create augmented matrix [A|I]
		std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n, 0.0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				augmentedMatrix[i][j] = rhs.matrix_[(i * n) + j];
				augmentedMatrix[i][j + n] = (j == i) ? 1.0 : 0.0; // Create Identity matrix on the right
			}
		}

		// MatrixDisplay(augmentedMatrix, n,2, "Augmented Matrix values are\n");
		
		// 2- Gaussian Elimination
		for (int i = 0; i < n; ++i) {

			// Check for singularity
			if (augmentedMatrix[i][i] == 0) {
			     throw std::runtime_error("Matrix is singular (non-invertible).\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );
			}

			// For diagonal elements make it = 1
			double pivot = augmentedMatrix[i][i];
			//std::cout << "Pivot: " << pivot << std::endl;
			for (int j = 0; j < 2 * n; ++j) {
				augmentedMatrix[i][j] /= pivot;
			}

			// MatrixDisplay(augmentedMatrix,n,2,"After Pivot operations\n");

			// Row Operations
			for (int k = 0; k < n; ++k) {

				// Update elements not a diagonal element
				if (k != i) {

					// std::cout << "At i = " << i << ", k = " << k << "\n";
					// MatrixDisplay(augmentedMatrix, n, 2, "Augmented Matrix values are\n");

					// factor is the elem below the diagnoal 1 value
					// Eliminate other rows 
					double factor = augmentedMatrix[k][i];
					// std::cout << "factor: " << factor << std::endl;
					for (int j = 0; j < 2 * n; ++j) {
						// Ex, R2 = R2 - ( num * R1 )
						// [1][]  = [1][..] - [1][0] * [0][..]
						augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
					}

					// MatrixDisplay(augmentedMatrix, n, 2, "Augmented Matrix values are\n");
				}
			}
		}

		// 3- Extract inverse from the augmented matrix b 
		std::cout << "The Inverse Matrix\n";
		std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n, 0.0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				inverseMatrix[i][j] = augmentedMatrix[i][j + n];
				std::cout	<< std::setprecision(4) // Set precision to 4 decimal places in float
							<< std::setw(10)        // Set width of 10 places for each printed number
							<< inverseMatrix[i][j] << " ";
			}
			std::cout << std::endl;
		}

		// 4- Multiply A by the inverse of B
		Matrix inverseMatrixObj(inverseMatrix);
		Matrix result = inverseMatrixObj.matmul(*this);

		return result;
	}

	// Operator Overload for Division by a scalar
	Matrix Matrix::operator / (const double& scalar) const {
		Matrix result({ rows_, cols_ });

		if (scalar == 0) {
			throw std::runtime_error("Scalar = 0 is not a valid logical operation.\n" + std::string(__FILE__) + "\nat line " + std::to_string(__LINE__));
		}

		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result(i, j) = (*this)(i, j) / scalar;
			}
		}
		return result;
	}

	// Matrix Normalization
	double Matrix::norm() const {
		double sum = 0.0;
		for (const auto& value : matrix_) {
			sum += value * value;
		}
		return std::sqrt(sum);
	}

	// Matrix DotProduct
	std::vector<double> Matrix::dot(std::vector<double>& vector) const {
		if (vector.size() != cols_) {
			throw std::runtime_error("Vector size must match the number of columns in the matrix.\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );
		}

		std::vector<double> result(rows_, 0.0);
		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < cols_; ++j) {
				result[i] += (*this)(i, j) * vector[j];
			}
		}
		return result;
	}

	// Matrix Multiplication using matmul() operation
	Matrix Matrix::matmul(Matrix rhs) const {
		// Check if the number of columns in the current matrix equals the number of rows in the other matrix
		if (cols_ != rhs.rows_) {
			throw std::runtime_error("Number of columns in the first matrix must equal number of rows in the second matrix.\n" + std::string(__FILE__)  + "\nat line "+ std::to_string(__LINE__) );
		}

		// Initialize the result matrix with the appropriate size
		Matrix result({ rows_, rhs.cols_ });

		// Perform matrix multiplication
		for (size_t i = 0; i < rows_; ++i) {
			for (size_t j = 0; j < rhs.cols_; ++j) {
				for (size_t k = 0; k < cols_; ++k) {
					result(i, j) += (*this)(i, k) * rhs(k, j);
				}
			}
		}
		return result;
	}

	// Extra functions
	void MatrixDisplay(const std::vector<std::vector<double>>& augmentedMatrix, const int& n, const int& limit, const std::string& msg) {
		std::cout << "---------------------------------------------------\n";
		std::cout << msg;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < limit * n; ++j) {
				std::cout << std::setprecision(4) // Set precision to 4 decimal places in float
					<< std::setw(10)              // Set width of 10 places for each printed number
					<< augmentedMatrix[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << "---------------------------------------------------\n";
	}

}