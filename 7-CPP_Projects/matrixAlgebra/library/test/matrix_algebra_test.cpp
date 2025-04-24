#define CATCH_CONFIG_MAIN  
#include<catch.h>
#include"matrix_algebra.hpp"
#include<vector>
#include<array>
#include<cmath>
#include<iostream>



namespace cie1
{

	TEST_CASE(" Matrix operators test ")
	{
		Matrix matrixA({{	2.0,	3.0	},
						{	5.0,	4.0	}	});


		Matrix matrixB({ {	3.0,	2.0	},
						{	3.0,	2.0	}	});

		Matrix matrixC = matrixA + matrixB;

		double tolerance = 1e-14;

		CHECK(( matrixC(0, 0) == Approx(5.0).epsilon(tolerance) &&
			matrixC(0, 1) == Approx(5.0).epsilon(tolerance) &&
			matrixC(1, 0) == Approx(8.0).epsilon(tolerance) &&
			matrixC(1, 1) == Approx(6.0).epsilon(tolerance) ));


		Matrix matrixD = matrixA - matrixB;


		CHECK((matrixD(0, 0) == Approx(-1.0).epsilon(tolerance) &&
			matrixD(0, 1) == Approx(1.0).epsilon(tolerance) &&
			matrixD(1, 0) == Approx(2.0).epsilon(tolerance) &&
			matrixD(1, 1) == Approx(2.0).epsilon(tolerance)));

		
		matrixD = matrixA * matrixB;


		CHECK((matrixD(0, 0) == Approx(15.0).epsilon(tolerance) &&
			matrixD(0, 1) == Approx(10.0).epsilon(tolerance) &&
			matrixD(1, 0) == Approx(27.0).epsilon(tolerance) &&
			matrixD(1, 1) == Approx(18.0).epsilon(tolerance)));


		matrixD = matrixA * 2;

		CHECK((matrixD(0, 0) == Approx(4.0).epsilon(tolerance) &&
			matrixD(0, 1) == Approx(6.0).epsilon(tolerance) &&
			matrixD(1, 0) == Approx(10.0).epsilon(tolerance) &&
			matrixD(1, 1) == Approx(8.0).epsilon(tolerance)));


		matrixD = matrixA ^ -1;

		CHECK((matrixD(0, 0) == Approx(1.0/2).epsilon(tolerance) &&
			matrixD(0, 1) == Approx(1.0/3).epsilon(tolerance) &&
			matrixD(1, 0) == Approx(1.0/5).epsilon(tolerance) &&
			matrixD(1, 1) == Approx(1.0/4).epsilon(tolerance)));


	}

	TEST_CASE(" Norm test ")
	{
		Matrix matrix({ {	2.0,	3.0	},
						{	5.0,	4.0	} });

		double tolerance = 1e-14;
		double norm = matrix.norm();

		CHECK(norm == Approx(7.3484692283495345).epsilon(tolerance));

	}

	TEST_CASE(" Dot product test ")
	{
		Matrix matrix({ {	2.0,	3.0	},
						{	5.0,	4.0	} });

		std::vector<double> vector = { 2.0,3.0 };

		auto result = matrix.dot(vector);

		double tolerance = 1e-14;
		
		CHECK((	result[0] == Approx(13.0).epsilon(tolerance) &&
				result[1] == Approx(22.0).epsilon(tolerance)));

	}

	TEST_CASE(" Matrix matmul test ")
	{
		Matrix matrixA({ {	2.0,	3.0	},
						{	5.0,	4.0	} });


		Matrix matrixB({ {	3.0,	2.0,	4.0	},
						 {	3.0,	2.0,	5.0	} });

		Matrix matrixC = matrixA.matmul(matrixB);

		double tolerance = 1e-14;

		CHECK((	matrixC.size()[0]	==	matrixA.size()[0] && 
				matrixC.size()[1]	==	matrixB.size()[1] &&
				matrixC(0, 0) == Approx(15.0).epsilon(tolerance) &&
				matrixC(0, 1) == Approx(10.0).epsilon(tolerance) &&
				matrixC(0, 2) == Approx(23.0).epsilon(tolerance) &&
				matrixC(1, 0) == Approx(27.0).epsilon(tolerance) &&
				matrixC(1, 1) == Approx(18.0).epsilon(tolerance) &&
				matrixC(1, 2) == Approx(40.0).epsilon(tolerance) ));

	}

}