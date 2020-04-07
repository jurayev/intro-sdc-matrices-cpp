//
// Created by Jurayev, Yuriy on 05/04/2020.
//
#include "matrix.hpp"
#include <vector>

#include "catch.hpp"

using namespace std;

TEST_CASE("When transpose a non-square matrix[3][5] --> a product is matrix[5][3]", "[matrix_transpose][smoke]") {
	
	// Arrange
	vector < vector<float> > initial_grid, expected_grid;

	initial_grid = {
			{1, 8.5, -5, 12, 0.001},
			{-25, 1, 5, 44, 0.002},
			{-2, 8.43, -5, 1, -0.023}};
	Matrix matrix(initial_grid);

	expected_grid = {
			{1, -25, -2},
			{8.5, 1, 8.43},
			{-5, 5, -5},
			{12, 44, 1},
			{0.001, 0.002, -0.023}};
	Matrix matrix_expected(expected_grid);

	//Act
	Matrix matrix_product = matrix.matrix_transpose();

	//Assert
	CAPTURE(matrix_product.getGrid());
	CAPTURE(matrix_expected.getGrid());

	REQUIRE((matrix_product == matrix_expected));
}

TEST_CASE("When transpose a square matrix[2][2] --> a product is matrix[2][2]", "[matrix_transpose][reg]") {

	// Arrange
	vector < vector<float> > initial_grid, expected_grid;

	initial_grid = {
			{1, 8.5},
			{-25, 3}};
	Matrix matrix(initial_grid);

	expected_grid = {
			{1, -25},
			{8.5, 3}};
	Matrix matrix_expected(expected_grid);
	//Act
	Matrix matrix_product = matrix.matrix_transpose();

	//Assert
	CAPTURE(matrix_product.getGrid());
	CAPTURE(matrix_expected.getGrid());

	REQUIRE((matrix_product == matrix_expected));
}

TEST_CASE("When transpose a mirror matrix[1][1] --> a product is matrix[1][1]", "[matrix_transpose][reg]") {

	// Arrange
	vector < vector<float> > initial_grid, expected_grid;
	initial_grid = { {1} };
	Matrix matrix(initial_grid);

	expected_grid = { {1} };
	Matrix matrix_expected(expected_grid);
	//Act
	Matrix matrix_product = matrix.matrix_transpose();

	//Assert
	CAPTURE(matrix_product.getGrid());
	CAPTURE(matrix_expected.getGrid());

	REQUIRE((matrix_product == matrix_expected));
}
