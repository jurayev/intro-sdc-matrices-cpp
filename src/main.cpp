//
//  main.cpp
//  intro_sdc_matrices_cpp
//
//  Created by Jurayev, Yuriy on 24/11/2019.
//  Copyright © 2019 Jurayev, Yuriy. All rights reserved.
//
#include <iostream>
#include <vector>
#include "matrix.hpp"

int main () {
    
    std::vector <std:: vector <float> >
        initial_grid (7, std::vector <float>(5, 0.4));
    Matrix matrixa(initial_grid);
    matrixa.matrix_print();
    
    std::cout << "matrixa rows: " << matrixa.getRows() << std::endl;
    std::cout << "matrixa columns: " << matrixa.getCols() << std::endl;
    
    Matrix transposea = matrixa.matrix_transpose();
    transposea.matrix_print();

    std::vector <std:: vector <float> >
        second_grid (7, std::vector <float>(5, 0.2));
    
    Matrix matrixb(second_grid);
    Matrix matrixsum = matrixa.matrix_addition(matrixb);
    matrixsum.matrix_print();

    return 0;
}
