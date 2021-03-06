#ifndef DS_MATRIX_H
#define DS_MATRIX_H

#include "Ratio.h"
#include <iostream>
#include <string>

namespace ds_course
{
    template <class T>
    class Matrix
    {
    private:
        int rows; // row count
        int cols; // column count
    public:
        T **a;
        Matrix(int rr, int cc);
        int getRows();
        int getCols();

        bool operator==(const ds_course::Matrix<T> &rhs);
        Matrix operator+(const ds_course::Matrix<T> &rhs);
        Matrix operator-(const ds_course::Matrix<T> &rhs);
        Matrix operator*(const ds_course::Matrix<T> &rhs);

        friend std::istream &operator>>(std::istream &input, ds_course::Matrix<T> &m)
        {
            for (int i = 0; i < m.getRows(); i++)
                for (int j = 0; j < m.getCols(); j++)
                    input >> m.a[i][j];
            return input;
        }

        friend std::ostream &operator<<(std::ostream &oStream, ds_course::Matrix<T> &m){
            for (int i = 0; i < m.getRows(); i++){
                for (int j = 0; j < m.getCols(); j++){
                    oStream << m.a[i][j];
                    if(j != m.getCols() - 1){
                        oStream << " ";
                    }
                }
                oStream << std::endl; 
            }  
            return oStream;
        }

    };
} // namespace ds_course


template <class T>
ds_course::Matrix<T>::Matrix(int rr, int cc) : rows(rr), cols(cc)
{
    a = new T *[rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
}

template <class T>
int ds_course::Matrix<T>::getRows() { return rows; }

template <class T>
int ds_course::Matrix<T>::getCols() { return cols; }


template <class T>
bool ds_course::Matrix<T>::operator==(const ds_course::Matrix<T> &rhs)
{
    if (rows != rhs.rows)
    {
        throw std::out_of_range("row counts differ");
    }
    if (cols != rhs.cols)
    {
        throw std::out_of_range("col counts differ");
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (! (a[i][j] == rhs.a[i][j]))
                return false;
    return true;
}

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator+(const ds_course::Matrix<T> &rhs){
    if (rows != rhs.rows)
    {
        throw std::out_of_range("row counts differ");
    }
    if (cols != rhs.cols)
    {
        throw std::out_of_range("col counts differ");

    }

    int rowss = getRows();
    int colss = getCols();


    ds_course::Matrix<T> retmat(rowss, colss);

    for( int i = 0; i < rowss; i++){
        for (int j = 0; j < colss; j++){
            retmat.a[i][j] = a[i][j] + rhs.a[i][j];
        }
    }

    return retmat;
}

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator-(const ds_course::Matrix<T> &rhs){
    if (rows != rhs.rows)
    {
        throw std::out_of_range("row counts differ");
    }
    if (cols != rhs.cols)
    {
        throw std::out_of_range("col counts differ");

    }

    int rowss = getRows();
    int colss = getCols();

    ds_course::Matrix<T> retmat(rowss, colss);

    for( int i = 0; i < rowss; i++){
        for (int j = 0; j < colss; j++){
            retmat.a[i][j] = a[i][j] - rhs.a[i][j];
        }
    }

    return retmat;
}

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator*(const ds_course::Matrix<T> &rhs){
    if (cols != rhs.rows)
    {
        throw std::out_of_range("the column and row counts differ");

    }

    int rowss = getRows();
    int colss = rhs.cols;



    ds_course::Matrix<T> retmat(rowss, colss);

    for( int i = 0; i < rowss; i++){
        for (int j = 0; j < colss; j++){
            retmat.a[i][j] = 0;
            for(int k = 0; k < getCols(); k++){

                retmat.a[i][j] = retmat.a[i][j] + (a[i][k] * rhs.a[k][j]);
            }

        }
    }

    return retmat;
}

#endif /* DS_MATRIX_H */