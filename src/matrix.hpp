//
//  matrix.hpp
//  intro_sdc_matrices_cpp
//
//  Created by Jurayev, Yuriy on 24/11/2019.
//  Copyright © 2019 Jurayev, Yuriy. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <vector>
#include <iostream>
#include <stdexcept>

#include <vector>

class Matrix {
    private:

        std::vector< std::vector<float> > grid;
        std::vector<float>::size_type rows;
        std::vector<float>::size_type cols;

    public:

        // constructor functions
        Matrix ();
        Matrix (std::vector< std::vector<float> >);

		// operator functions
		bool operator==(Matrix&);

		// set functions
        void setGrid(std::vector< std::vector<float> >);

        // get functions
        std::vector< std::vector<float> > getGrid();
        std::vector<float>::size_type getRows();
        std::vector<float>::size_type getCols();

        // matrix functions
        Matrix matrix_transpose();
        Matrix matrix_addition(Matrix);

        // matrix printing
        void matrix_print();

};

#endif /* matrix_hpp */
