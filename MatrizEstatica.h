#ifndef MATRIZESTATICA_H
#define MATRIZESTATICA_H

#include "MatrizBase.h"

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {
    private:
        T _datos[M][N];
    
    public:
        // Constructor
        MatrizEstatica();

        // Métodos Virtuales
        void cargarValores() override;
        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override;
        void imprimir() const override;
};

#endif