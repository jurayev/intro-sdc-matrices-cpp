//
// Created by Jurayev, Yuriy on 05/04/2020.
//
#include "matrix.hpp"
#include <vector>

#include "catch.hpp"

using namespace std;

TEST_CASE("When adding 2 matrices --> a product matrix is created") {
	
	// Arrange
	vector < vector<float> > grid_a = vector < vector <float> >(5, vector<float>(5, 0.5));
	Matrix matrix_a(grid_a);
	
	SECTION("When adding matrices matrix_a[5][5] = {{0.5}} and matrix_a[5][5] = {{0}} --> new matrix[5][5] = {{0.5}}",
			"[matrix_addition][reg]") {
		vector < vector<float> > grid_b = vector < vector <float> >(5, vector<float>(5, 0));
		Matrix matrix_b(grid_b);
		
		vector < vector<float> > expected_grid = vector < vector <float> >(5, vector<float>(5, 0.5));
		Matrix expected_matrix(expected_grid);
		// Act
		Matrix product_matrix = matrix_a.matrix_addition(matrix_b);
		// Assert
		REQUIRE((product_matrix == expected_matrix));
	}
	
	SECTION("When adding matrices matrix_a[5][5] = {{0.5}} and matrix_a[5][5] with pos and negative values --> new matrix[5][5] is correct",
			"[matrix_addition][smoke]") {
		vector < vector<float> > grid_b = {
				{-2, 8.5, -5, 12, -0.001},
				{-25, 8.5, 5, 44, -0.001},
				{-2, 8.43, -5, 12, -0.001},
				{-2, 0, -1, 12.1, -0.001},
				{-2, -0.5, 1, 12, -0.001}};
		Matrix matrix_b(grid_b);
		
		vector < vector<float> > expected_grid = {
				{-1.5f, 9.0f, -4.5f, 12.5f, 0.499f},
				{-24.5f, 9.0f, 5.5f, 44.5f, 0.499f},
				{-1.5f, 8.93f, -4.5f, 12.5f, 0.499f},
				{-1.5f, 0.5f, -0.5f, 12.6f, 0.499f},
				{-1.5f, 0.0f, 1.5f, 12.5f, 0.499f}};
		Matrix expected_matrix(expected_grid);
		// Act
		Matrix product_matrix = matrix_a.matrix_addition(matrix_b);
		// Assert
		REQUIRE((product_matrix == expected_matrix));
	}
	
}

TEST_CASE("When adding matrices the size is not the same --> throw invalid_argument error") {
	// Arrange
  	INFO("Create matrix a")
  	vector < vector<float> > grid_a = vector < vector <float> >(4, vector<float>(7, 1));
  	Matrix matrix_a(grid_a);

	SECTION("When adding matrices and rows number are not the same --> throw invalid_argument error",
			"[matrix_addition][errorrows][reg]") {
		// Test with some additional logging examples
		INFO("Create matrix b")
		vector < vector<float> > grid_b = vector < vector <float> >(3, vector<float>(7, 1));
		Matrix matrix_b(grid_b);

		// Act
		// Assert
		// Outputs info about matrices dimensions in case of a failure
		CAPTURE(matrix_a.getRows(), matrix_b.getRows());

	  	REQUIRE_THROWS_AS(matrix_a.matrix_addition(matrix_b), invalid_argument);
	}

  	SECTION("When adding matrices and columns number are not the same --> throw invalid_argument error",
  			"[matrix_addition][errorcols][reg]") {
		// Test with some additional logging examples
  	  	INFO("Create matrix b")
		vector < vector<float> > grid_b = vector < vector <float> >(4, vector<float>(5, 1));
		Matrix matrix_b(grid_b);

		// Act
		// Assert
		// Outputs info about matrices dimensions in case of a failure
		CAPTURE(matrix_a.getCols(), matrix_b.getCols());

		// Checks if error thrown has specific error message
		REQUIRE_THROWS_WITH(matrix_a.matrix_addition(matrix_b), "matrices are not the same size");
  	}
}

//TODO: matrix_transpose()
//TODO: matrix_print()
