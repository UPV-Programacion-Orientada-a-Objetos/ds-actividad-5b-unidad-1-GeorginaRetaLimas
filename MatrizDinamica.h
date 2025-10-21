#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include "MatrizBase.h"

template <typename T>
class MatrizDinamica : public MatrizBase<T> {
    private: 
        T **_datos;

        // Método auxiliar para asignar memoria
        void asignarMemoria() {
            // Creamos el array de punteros
            _datos = new T*[this->_filas];

            // Creamos array de columnas
            for(int i = 0; i < this->_filas; i++) {
                _datos[i] = new T[this->_columnas];

                // Inicializacion de ceros
                for(int j = 0; j < this->_columnas; j++) {
                    _datos[i][j] = T(0); // Inicialización
                }
            }
        }

        // Método auxiliar para liberar memoria
        void liberarMemoria() {
            if(_datos != nullptr) {
                // Liberamos cada fila
                for(int i = 0; i < this->_filas; i++) {
                    delete[] _datos[i];
                }

                // Liberamos el array de punteros
                delete[] _datos;
                _datos = nullptr;
            }
        }
    
    public:
        // Constructor
        MatrizDinamica(int filas, int columnas)
            : MatrizBase<T>(filas, columnas), _datos(nullptr){

            std::cout<<"Creando Matriz Dinamica ( "<<filas<<" x "<<columnas<<")"<<std::endl;
            asignarMemoria();
        }

        // Destructor
        ~MatrizDinamica(){
            std::cout<<"Destruyendo Matriz Dinámica ( "<<this->_filas<<" x "<<this->_columnas<<")"<<std::endl;
            liberarMemoria();
        }

        // Constructor de copia
        MatrizDinamica(const MatrizDinamica<T>& otra) 
            : MatrizBase<T>(otra._filas, otra._columnas), _datos(nullptr) {
            
            std::cout << "Constructor de copia llamado..."<<std::endl;
            asignarMemoria();
            
            // Copia profunda valor por valor
            for(int i = 0; i < this->_filas; i++) {
                for(int j = 0; j < this->_columnas; j++) {
                    _datos[i][j] = otra._datos[i][j];
                }
            }
        }

        // Operador de asignación
        MatrizDinamica<T>& operator=(const MatrizDinamica<T>& otra) {
            // Nos aseguramos que no se asigne a si mismo
            if(this == &otra) {  
                return *this;
            }
            
            std::cout<<"Operador de asignación llamado..."<<std::endl;
            
            liberarMemoria();
            
            // Actualizar dimensiones
            this->_filas = otra._filas;
            this->_columnas = otra._columnas;
            
            // Asignar nueva memoria
            asignarMemoria();
            
            // Copiar valores
            for(int i = 0; i < this->_filas; i++) {
                for(int j = 0; j < this->_columnas; j++) {
                    _datos[i][j] = otra._datos[i][j];
                }
            }
            
            return *this;
        }

        // Métodos virtuales

        // Cargar los valores
        void cargarValores() override {
            std::cout<<"Ingrese los valores de la matriz ( "<<this->_filas<<"x"<< this->_columnas<<" ):"<<std::endl;
            
            for(int i = 0; i < this->_filas; i++) {
                for(int j = 0; j < this->_columnas; j++) {
                    std::cout<<"Elemento ["<<i<<"]["<<j<<"]: ";
                    std::cin >> _datos[i][j];
                }
            }
        }

        // Sumar
        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
            // Verificar dimensiones
            if(this->_filas != otra.getFilas() || this->_columnas != otra.getColumnas()) {
                std::cout<<"Error: Dimensiones incompatibles para la suma"<<std::endl;
                return nullptr;
            }

            // Convertimos a MatrizBase a MatrizDinamica
            const MatrizDinamica<T>* otraDinamica = dynamic_cast<const MatrizDinamica<T>*>(&otra);

            if(otraDinamica == nullptr) {
                std::cout<<"Error: No se puede sumar con matriz de tipo diferente"<<std::endl;
                return nullptr;
            }

            // Crear una matriz de resultado
            MatrizDinamica<T>* resultado = new MatrizDinamica<T>(this->_filas, this->_columnas);

            // Realizar la suma de elemento por elemento
            for(int i = 0; i < this->_filas; i++) {
                for(int j = 0; j < this->_columnas; j++) {
                    resultado->_datos[i][j] = this->_datos[i][j] + otraDinamica->_datos[i][j];
                }
            }

            std::cout<<"Suma completada exitosamente"<<std::endl;
            return resultado;
        }

        // Imprimir
        void imprimir() const override {
            std::cout<<"\nMatriz ("<<this->_filas<<"x"<<this->_columnas<<"):"<<std::endl;
            
            for(int i = 0; i < this->_filas; i++) {
                std::cout<<"| ";
                for(int j = 0; j < this->_columnas; j++) {
                    std::cout<<_datos[i][j];
                    if(j < this->_columnas - 1) {
                        std::cout<<" | ";
                    }
                }
                std::cout<<" |"<<std::endl;
            }
            std::cout<<std::endl;
        }
};

#endif
