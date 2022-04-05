#include "Matrix.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace ziv;
using namespace std;
vector<vector<double>> Matrix::genMatrix(vector<double> vals, int r, int c){
    vector<vector<double>> mat;
    for(size_t i = 0; i < r; i++){
        vector<double> row;
        for(size_t j=0; j < c; j++){
            row.push_back(vals[i*size_t(c)+j]);
        }
        mat.push_back(row);
    }
    return mat;
}


Matrix::Matrix(std::vector<double> v, int r, int c): matrix(genMatrix(v,r,c)), rows(r), cols(c){}

ostream& ziv::operator<<(std::ostream& output, const Matrix& mat){
    for(size_t i = 0; i<mat.rows; i++){
        string row;
        for(size_t j = 0; j<mat.cols; j++){
            row = row + to_string(mat.get(i,j));
            if(j < mat.cols-1){
                row.push_back(' ');
            }
        }
        output << "[" << row << "]" << endl;
    }
    return output;
}

Matrix ziv::operator+(Matrix lMat, const Matrix& rMat){
    lMat += rMat;
    return lMat;
}


Matrix& Matrix::operator+=(const Matrix& rMat){
    ensureSameSize(rMat);
    auto MatCellAddition = [](const Matrix& mat1,const Matrix& mat2,size_t i, size_t j){
        return mat1.get(i,j)+mat2.get(i,j);
    };
    applyOnEach(rMat,MatCellAddition);
    return *this;
}


Matrix ziv::operator-(Matrix lMat, const Matrix& rMat){
    lMat -= rMat;
    return lMat;
}
Matrix& Matrix::operator-=(const Matrix& rMat){

    auto MatCellSubtraction = [](const Matrix& mat1,const Matrix& mat2,size_t i, size_t j){
        return mat1.get(i,j)-mat2.get(i,j);
    };
    ensureSameSize(rMat);
    applyOnEach(rMat,MatCellSubtraction);
    return *this;
}
Matrix ziv::operator-(Matrix mat){
    mat*=-1;
    return mat;
}


bool Matrix::operator<(const Matrix& rMat)const {
    return sum() < rMat.sum(); 
}
bool Matrix::operator>(const Matrix& rMat)const {
    return sum() > rMat.sum(); 
}
bool Matrix::operator==(const Matrix& rMat)const {
    if (rows != rMat.getRows() || cols != rMat.getCols()){
        return false;
    }
    for(size_t i = 0; i<rows; i++){
        for(size_t j = 0; j<cols; j++){
            if(matrix[i][j] != rMat.get(i,j)){
                return false;
            }
        }
    }
    return true;
}
bool Matrix::operator!=(const Matrix& rMat) const{
    return !operator==(rMat);
}
bool Matrix::operator<=(const Matrix& rMat) const{
    return this->operator==(rMat) || this->operator<(rMat);
}     
bool Matrix::operator>=(const Matrix& rMat) const{
    return this->operator==(rMat) || this->operator>(rMat);
}
          
Matrix& Matrix::operator++(){
    auto increment = [](const Matrix& mat1,double amount,size_t i, size_t j){
        return mat1.get(i,j)+amount;
    };
    
    applyOnEach(1,increment);
    return *this;
}

const Matrix Matrix::operator++(int){
    Matrix temp = *this;
    operator++();
    return temp;

}
Matrix& Matrix::operator--(){
    auto decrement = [](const Matrix& mat1,double amount,size_t i, size_t j){
        return mat1.get(i,j)-amount;
    };
    
    applyOnEach(1,decrement);
    return *this;
}

const Matrix Matrix::operator--(int){
    Matrix temp = *this;
    operator--();
    return temp;
}

Matrix ziv::operator*(Matrix lMat, double scalar){
    lMat*=scalar;
    return lMat;
}
Matrix ziv::operator*(double scalar,Matrix lMat){
    lMat*=scalar;
    return lMat;
}
Matrix& Matrix::operator*=(double scalar){
    auto mult = [](const Matrix& mat1,double s,size_t i, size_t j){
            return mat1.get(i,j)*s;
    };
    applyOnEach(scalar,mult);
    return *this;
}

Matrix ziv::operator*(Matrix lMat, const Matrix& rMat){
    lMat*=rMat;
    return lMat;
}


Matrix& Matrix::operator*=(const Matrix& rMat){
    
    
    return *this;
}

