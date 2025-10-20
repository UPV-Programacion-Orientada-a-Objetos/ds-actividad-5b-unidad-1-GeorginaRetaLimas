#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include "MatrizBase.h"

template <typename T>
class MatrizDinamica : public MatrizBase<T> {
    private: 
        T **_datos;

        // Método auxiliar para asignar memoria
        void asignarMemoria() {
            _datos = new T*[this->_filas];
            for(int i = 0; i < this->_filas; i++) {
                _datos[i] = new T[this->_columnas];
            }
        }

        // Método auxiliar para liberar memoria
        void liberarMemoria() {
            if(_datos != nullptr) {
                for(int i = 0; i < this->_filas; i++) {
                    delete[] _datos[i];
                }

                delete[] _datos;
                _datos = nullptr;
            }
        }
    
    public:
        // Constructor
        MatrizDinamica(int filas, int columnas);

        // Destructor
        ~MatrizDinamica();

        // Constructor de colonia
        MatrizDinamica(const MatrizDinamica<T>& otra);

        // Métodos virtuales
        void cargarValores() override;
        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override;
        void imprimir() const override;
};

#endif
