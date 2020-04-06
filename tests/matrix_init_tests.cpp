//
// Created by Jurayev, Yuriy on 05/04/2020.
//
#include "matrix.hpp"
#include <vector>

#include "catch.hpp"

using namespace std;

TEST_CASE("When default matrix is created --> 'matrix[10][5] = {{0.5}}'", "[matrix_init][default][reg]") {{
	//Arrange
	Matrix matrix;
  	vector < vector<float> >  expected_grid = vector < vector<float> >(10, vector<float>(5, 0.5));
	//Act
    vector < vector<float> >  matrix_grid = matrix.getGrid();
	//Assert
    REQUIRE(matrix_grid == expected_grid);
}}

TEST_CASE("When matrix is created with matrix[5][3] = {{0}} --> matrix[5][3] = {{0}}", "[matrix_init][custom][smoke]") {{
	//Arrange
	vector < vector<float> >  expected_grid = vector < vector<float> >(5, vector<float>(3, 0));
	Matrix matrix(expected_grid);

	//Act
	vector < vector<float> >  matrix_grid = matrix.getGrid();
	//Assert
	REQUIRE(matrix_grid == expected_grid);
}}

TEST_CASE("When matrix is created with empty grid --> matrix[0][0] = {{0}}", "[matrix_init][empty][reg]") {{
	//Arrange
	vector < vector<float> >  empty_grid = vector < vector<float> >(0, vector<float>(0, 0));

	Matrix matrix(empty_grid);

  	vector < vector<float> >  expected_grid = vector < vector<float> >(1, vector<float>(1, 0));
	//Act
	vector < vector<float> >  matrix_grid = matrix.getGrid();
	//Assert // CHECK example
  	CHECK(matrix.getRows() == 1);
  	CHECK(matrix.getCols() == 1);
	CHECK(matrix_grid == expected_grid);
}}

TEST_CASE("When matrix is created matrix[1][2] = {{-1.5}} --> matrix rows and columns are correct") {{
	//Arrange
	vector < vector<float> >  initial_grid = vector < vector<float> >(1, vector<float>(2, -1.5));

	Matrix matrix(initial_grid);

	SECTION("When matrix is created with grid matrix[1][2] = {{-1.5}} --> matrix.rows = 1", "[matrix_init][rows][smoke]") {{
		//Act
		int matrix_rows = matrix.getRows();
		//Assert
		REQUIRE(matrix_rows == 1);
	}}


	SECTION("When matrix is created with grid matrix[1][2] = {{-1.5}} --> matrix.cols = 2", "[matrix_init][cols][smoke]") {{
		//Act
		int matrix_cols = matrix.getCols();
		//Assert
		REQUIRE(matrix_cols == 2);
	}}
}}

TEST_CASE("When matrix is updated with matrix[15][15] = {{80}} --> a new matrix[15][15] = {{80}}", "[matrix_init][update][reg]") {{
  	// Arrange
  	vector < vector<float> >  initial_grid = vector < vector<float> >(1, vector<float>(1, -0));
  	vector < vector<float> >  new_grid = vector < vector<float> >(15, vector<float>(15, 80));

	Matrix matrix(initial_grid);
	
	// Act
	matrix.setGrid(new_grid);
	auto matrix_grid = matrix.getGrid();

	// Assert
	REQUIRE(matrix_grid == new_grid);
}}
