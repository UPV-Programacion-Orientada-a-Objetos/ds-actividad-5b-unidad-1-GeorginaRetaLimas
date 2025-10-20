#ifndef MATRIZBASE_H
#define MATRIZBASE_H

#include <iostream>

template <typename T>
class MatrizBase {
    protected:
        int _filas;
        int _columnas;
    
    public:
    virtual void cargarValores() = 0;
    virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;
    virtual void imprimir() const = 0;
};