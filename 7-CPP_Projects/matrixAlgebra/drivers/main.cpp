// Matrix_solution.cpp : Defines the entry point for the application.
//

#include "matrix_algebra.hpp"
#include <iostream>

using namespace std;


int main()
{
   
    std::cout << "*************************************************************" << std::endl;
    std::cout << "............. (Task 1.1)   General Matrix Operations ............." << std::endl;
    std::cout << "*************************************************************" << std::endl;

    //----------------------- Create & Intialize for two matrices ------------------//
    // Matrix A initilization dimensions as (3 x 2 Matrix)
    // Initialize a 3x2 matrix filled with zerose
    // Using the size constructor

    std::cout << "*************************************************************" << std::endl;

    //cie1::Matrix matrixA({ 3, 2 }); 
    //// Setting some values
    //matrixA(0, 0) = 1;      
    //matrixA(0, 1) = 2;
    //matrixA(1, 0) = 3;
    //matrixA(1, 1) = 4;
    //matrixA(2, 0) = 5;
    //matrixA(2, 1) = 6;

    try {

        // Create 3 x 4 Matrix
        cie1::Matrix matrixA({ {1,2,2,1},
                               {1,1,2,2},
                               {0,0,0,0} });

        matrixA.print("Matrix A"); // Print matrix A
        //std::array<size_t,2> matrix_size = matrixA.size();  // matrix_size = {rows_,cols_};
        //size_t rows = matrix_size[0];
        //size_t cols = matrix_size[1];
        //cout << "Size: " << rows << " x " << cols;
        cout << "Size: " << matrixA.size()[0] << " x " << matrixA.size()[1];
        std::cout << "------------------------------------" << std::endl;

        // Create a 3x4 matrixB filled with 2.0
        int rowsB = 4;
        int colsB = 3;
        std::vector<std::vector<double>> initMatrixB(rowsB, std::vector<double>(colsB, 2.0)); //  vector(4,2.0)
        cie1::Matrix matrixB = (initMatrixB);
        matrixB.print("Matrix B");
        cout << "Size: " << matrixB.size()[0] << " x " << matrixB.size()[1];
        std::cout << "------------------------------------" << std::endl;

        // Create a 4x3 matrixC filled with 2.0
        int rowsC = 3;
        int colsC = 4;
        std::vector<std::vector<double>> initMatrixC(rowsC, std::vector<double>(colsC, 2.0));

        cie1::Matrix matrixC ({ {1,2,2,1},
                                {1,1,2,2},
                                {0,0,0,0} });
        matrixC.print("Matrix C");
        matrixC.size();
        std::cout << "*************************************************************" << std::endl;
        
        //------------------------------------------ Matrix Addition ---------------------------------//
        std::cout << "Matrix,Scalar Addition:   Matrix_A + 3" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matrixAdditionScalar = matrixA + 3.0;
        matrixA.print("Matrix_A");
        matrixAdditionScalar.print("Result Matrix");
        matrixAdditionScalar.size();
        std::cout << "*************************************************************" << std::endl;


        std::cout << "Matrix,Matrix Addition:   ( Matrix_A + Matrix_C )" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matrixAddition = matrixA + matrixC;
        matrixA.print("Matrix_A");
        matrixC.print("Matrix_C");
        matrixAddition.print("Result Matrix ");
        matrixAddition.size();
        std::cout << "*************************************************************" << std::endl;

        //------------------------------------------ Matrix Subtraction ------------------------------//
        std::cout << "Matrix,Scalar Subtraction: ( Matrix_A - 3 )" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matrixSubtractionScalar = matrixA - 3;
        matrixA.print("Matrix_A");
        matrixSubtractionScalar.print("Result Matrix");
        matrixSubtractionScalar.size();
        std::cout << "*************************************************************" << std::endl;

        std::cout << "Matrix,Matrix Subtraction: ( Matrix_A - Matrix C )" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matrixSubtraction = matrixA - matrixC;
        matrixA.print("Matrix_A");
        matrixC.print("Matrix_C");
        matrixSubtraction.print("Result Matrix");
        matrixSubtraction.size();
        std::cout << "*************************************************************" << std::endl;

        //------------------------------------------ Matrix Multiplication --------------------------//
        std::cout << "Matrix,Scalar Multiplication: ( Matrix_A * 3 )" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matrixMultiplicationScalar = matrixA * 3;
        matrixA.print("Matrix_A");
        matrixMultiplicationScalar.print("Result Matrix:");
        matrixMultiplicationScalar.size();
        std::cout << "*************************************************************" << std::endl;

        std::cout << "Matrix,Matrix Multiplication: ( Matrix_A * Matrix_B )" << std::endl;
        std::cout << "*************************************************************" << std::endl;

        cie1::Matrix matrixK({ {	2.0,	3.0	},
                               {	5.0,	4.0	} });


        cie1::Matrix matrixL({ {	3.0,	2.0	},
                               {	3.0,	2.0	} });

        cie1::Matrix matrixMultiplication = matrixK * matrixL;

        matrixA.print("Matrix_A");
        matrixB.print("Matrix_B");
        matrixMultiplication.print("Result Matrix:");
        matrixMultiplication.size();
        std::cout << "*************************************************************" << std::endl;

        std::cout << "Matrix,Matrix Multiplication using matmul: ( Matrix_A * Matrix_B )" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matmulResult = matrixA.matmul(matrixB);
        matmulResult.print("matmulResult:");
        matmulResult.print("Result Matrix:");
        matmulResult.size();
        std::cout << "*************************************************************" << std::endl;


        //------------------------------------------ Matrix Power -------------------------------//
        std::cout << "Matrix Cubic Power: ( Matrix_A^3 )" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matrixPower = matrixA ^ 3;
        matrixA.print("Matrix_A");
        matrixPower.print("Result Matrix:");
        matrixPower.size();
        std::cout << "*************************************************************" << std::endl;


        //------------------------------------------ Matrix division -----------------------------//
        // Create square Matrix 3 x 3 Matrix
        //cie1::Matrix matrixF({ {-3,2,-1},
        //                       {6,-6,7},
        //                       {3,-4,4} });

        cie1::Matrix matrixE({ {4,2,1},
                                {0,1,3},
                                {2,3,5} });


        cie1::Matrix matrixF({ {6,-4,3},
                               {15,-11,-6},
                               {-2,1,0} });


        std::cout << "Matrix,Scalar Division: ( Matrix_E / 3 )" << std::endl;
        std::cout << "*************************************************************" << std::endl;
        cie1::Matrix matrixDivisionScalar = matrixE / 3;
        matrixE.print("Matrix_E");
        matrixE.size();
        matrixDivisionScalar.print("Result Matrix:");
        matrixDivisionScalar.size();
        std::cout << "*************************************************************" << std::endl;

        std::cout << "Matrix,Matrix Division: ( Matrix_E / Matrix_F )" << std::endl;
        std::cout << "*************************************************************" << std::endl;

        matrixE.print("Matrix_E");
        matrixE.size();
        matrixF.print("Matrix_F");
        matrixF.size();

        cie1::Matrix matrixDivision = matrixE / matrixF;
        matrixDivision.print("Result Matrix:");
        matrixDivision.size();
        std::cout << "*************************************************************" << std::endl;


        //------------------------------------------ Matrix Normalization --------------------------//
        double norm = matrixA.norm();
        std::cout << "Matrix_A Normalization: " << norm << std::endl;
        std::cout << "*************************************************************" << std::endl;

        //------------------------------------------ Matrix Dot Product ----------------------------//
        std::cout << "Matrix_A Dot Product with { 1.0, 2.0, 3.0 }" << std::endl;
        std::cout << "*************************************************************" << std::endl;

        std::vector<double> vectD = { 1.0, 2.0, 3.0, 4.0 };
        std::vector<double> matrixResult = matrixA.dot(vectD);

        std::cout << "[ ";
        for(const auto& elem : matrixResult) {
            std::cout << elem << " ";
        }
        std::cout << "] " << std::endl;

        //------------------------------------------ Matrix Resize --------------------------//
        std::cout << "*************************************************************" << std::endl;
        matrixC.print("MatrixC Before Resiz:");
        matrixC.resize({ 4, 6 });
        matrixC.print("Resized MatrixC:");

        //------------------------------------------ Matrix rotation -------------------------------//
        // R . (M.s + T)
        // R .  ( vertices . s + num)
        std::cout << "*************************************************************" << std::endl;
        std::cout << "........... (Task 1.2)  Retangle transormation(A - F) .........." << std::endl;
        std::cout << "*************************************************************" << std::endl;
    
        cie1::Matrix rotMatrix = cie1::Matrix({
                                            { std::sqrt(2.0) / 2.0, -std::sqrt(2.0) / 2.0, 0.0},
                                            { std::sqrt(2.0) / 2.0,  std::sqrt(2.0) / 2.0, 1.0},
                                            { 0, 0, 1}  });
        rotMatrix.print("rotMatrix Matrix");

        cie1::Matrix vertices = cie1::Matrix({ { 1, 2, 2, 1 },
                                               { 1, 1, 2, 2 },
                                               { 0, 0, 0, 0 } });
        vertices.print("Vertices Matrix");

        std::cout << "*************************************************************" << std::endl;
        std::cout << "For Rotation * ( (Vertices * scale) + Tranisiton)" << std::endl;
        std::cout << "*************************************************************" << std::endl;

        // Scaled Matrix
        cie1::Matrix verticesScaled = vertices * 3;
        verticesScaled.print("Vertix Matrix Scale by 3");

        // Transition Matrix
        cie1::Matrix verticesTransition = verticesScaled + 3;
        verticesTransition.print("Transition Matrix by 3");

        // Rotated Matrix
        cie1::Matrix newRotatedVertices = rotMatrix.matmul(verticesTransition);    // Keep the console window open
        newRotatedVertices.print("Rotated Matrix");

        system("pause");

    }
    catch (const std::runtime_error& error) {
        std::cerr << "Runtime error: " << error.what() << std::endl;
    }
    
    return 0;
}
