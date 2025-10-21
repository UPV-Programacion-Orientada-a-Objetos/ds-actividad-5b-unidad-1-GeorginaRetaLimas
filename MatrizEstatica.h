#ifndef MATRIZESTATICA_H
#define MATRIZESTATICA_H

#include "MatrizBase.h"
#include <iostream>

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {
    private:
        T _datos[M][N];
    
    public:
        // Constructor
        MatrizEstatica() : MatrizBase<T>(M, N) {
            std::cout<<"Creando Matriz Estatica ( "<<M<<"x"<<N<<" )..."<<std::endl;
            
            // Inicializar en cero
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    _datos[i][j] = T(0);
                }
            }
        }

        // Destructor
        ~MatrizEstatica() {
            std::cout<<"Destruyendo Matriz Estatica( "<<M<<"x"<<N<<" )..."<<std::endl;
        }

        // Métodos Virtuales

        // Cargar Valores
        void cargarValores() override {
            std::cout<<"Ingrese los valores de la matriz ( "<<M<<"x"<<N<<" ):"<<std::endl;
            
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    std::cout<<"Elemento ["<<i<<"]["<<j<< "]: ";
                    std::cin>>_datos[i][j];
                }
            }
        }

        // Sumar
        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
            // Checamos dimensiones
            if(this->_filas != otra.getFilas() || this->_columnas != otra.getColumnas()) {
                std::cout<<"Error: Dimensiones incompatibles para la suma"<<std::endl;
                return nullptr;
            }
            
            const MatrizEstatica<T, M, N>* otraEstatica = dynamic_cast<const MatrizEstatica<T, M, N>*>(&otra);
            
            if(otraEstatica == nullptr) {
                std::cout<<"Error: No se puede sumar con matriz de tipo diferente"<<std::endl;
                return nullptr;
            }
            
            // Crear nueva matriz resultado
            MatrizEstatica<T, M, N>* resultado = new MatrizEstatica<T, M, N>();
            
            // Realizar la suma
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    resultado->_datos[i][j] = this->_datos[i][j] + otraEstatica->_datos[i][j];
                }
            }
            
            std::cout<<"Suma completada exitosamente"<<std::endl;
            return resultado;
        }

        void imprimir() const override {
            std::cout<<"\nMatriz ( "<<M<<"x"<<N<<" ):"<<std::endl;
            
            for(int i = 0; i < M; i++) {
                std::cout<<"| ";
                for(int j = 0; j < N; j++) {
                    std::cout << _datos[i][j];
                    if(j < N - 1) {
                        std::cout<<" | ";
                    }
                }
                std::cout << " |"<<std::endl;
            }
            std::cout<<std::endl;
        }
};

#endif