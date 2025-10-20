#ifndef MATRIZBASE_H
#define MATRIZBASE_H

#include <iostream>

template <typename T>
class MatrizBase {
    protected:
        int _filas;
        int _columnas;
    
    public:
        // Constructor
        MatrizBase(int filas, int columnas) : 
            _filas(filas), _columnas(columnas) {}

        // Destructor
        virtual ~MatrizBase() {}

        // Métodos virtuales abstractos
        virtual void cargarValores() = 0;
        virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;
        virtual void imprimir() const = 0;

        // Sobrecarga
        MatrizBase<T>* operator+(const MatrizBase<T>& otra) const{
            return this->sumar(otra);
        }

        // Getters
        int getFilas() const{ return _filas}
        int getColumnas() const{ return _columnas}
};

#endif