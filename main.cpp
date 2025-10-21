#include <iostream>

#include "MatrizBase.h"
#include "MatrizDinamica.h"
#include "MatrizEstatica.h"

using namespace std;

int main() {
    std::cout<<"--- Sistema Genérico de Álgebra Lineal ---"<<std::endl<<std::endl;

    std::cout << ">> Demostración 1: Matrices Dinámicas (FLOAT) <<"<<std::endl<<std::endl;

    // Crear matriz dinamica A
    std::cout << "Creación de Matriz Dinámica (a través del puntero base)" << std::endl;
    MatrizBase<float>* matrizA = new MatrizDinamica<float>(3, 2);
    std::cout << std::endl;

    std::cout << "--- Cargando valores de Matriz A ---" << std::endl;
    matrizA->cargarValores();
    std::cout << std::endl;

    std::cout << "Matriz A:" << std::endl;
    matrizA->imprimir();
    std::cout << std::endl;

    // Crear matriz dinamica B
    std::cout << "Creación de Matriz Dinámica B (a través del puntero base)" << std::endl;
    MatrizBase<float>* matrizB = new MatrizDinamica<float>(3, 2);
    std::cout << std::endl;

    std::cout << "--- Cargando valores de Matriz B ---" << std::endl;
    matrizB->cargarValores();
    std::cout << std::endl;

    std::cout << "Matriz B:" << std::endl;
    matrizB->imprimir();
    std::cout << std::endl;

    // Crear la operacion suma
    std::cout << "Operación Polimórfica (Suma :D)" << std::endl;
    std::cout << "SUMANDO: Matriz C = A + B ..." << std::endl;

    // La suma es manejada por el método virtual de MatrizDinamica
    MatrizBase<float>* matrizC = matrizA->sumar(*matrizB);
    std::cout << std::endl;

    if(matrizC != nullptr) {
        std::cout << "Matriz Resultado C (3x2, Tipo FLOAT):" << std::endl;
        matrizC->imprimir();
    }
    std::cout << std::endl;

    // Demostracion
    std::cout << "========================================" << std::endl;
    std::cout << ">> Demostración usando operador + sobrecargado <<" << std::endl << std::endl;

    std::cout << "SUMANDO con operador +: D = A + B ..." << std::endl;
    MatrizBase<float>* matrizD = (*matrizA) + (*matrizB);
    std::cout << std::endl;

    if(matrizD != nullptr) {
        std::cout << "Matriz Resultado D:" << std::endl;
        matrizD->imprimir();
    }
    std::cout << std::endl;

    // Matrices estaticas
    std::cout << "========================================" << std::endl;
    std::cout << ">> Demostración con Matrices Estáticas (Tipo INT) <<" << std::endl << std::endl;

    MatrizBase<int>* matrizE = new MatrizEstatica<int, 2, 3>();
    std::cout << std::endl;

    std::cout << "--- Cargando valores de Matriz Estática E ---" << std::endl;
    matrizE->cargarValores();
    std::cout << std::endl;

    std::cout << "Matriz E:" << std::endl;
    matrizE->imprimir();
    std::cout << std::endl;

    MatrizBase<int>* matrizF = new MatrizEstatica<int, 2, 3>();
    std::cout << std::endl;

    std::cout << "--- Cargando valores de Matriz Estática F ---" << std::endl;
    matrizF->cargarValores();
    std::cout << std::endl;

    std::cout << "Matriz F:" << std::endl;
    matrizF->imprimir();
    std::cout << std::endl;

    std::cout << "SUMANDO: G = E + F ..." << std::endl;
    MatrizBase<int>* matrizG = (*matrizE) + (*matrizF);
    std::cout << std::endl;

    if(matrizG != nullptr) {
        std::cout << "Matriz Resultado G:" << std::endl;
        matrizG->imprimir();
    }
    std::cout << std::endl;

    // Limpieza de memoria
    std::cout << "========================================" << std::endl;
    std::cout << ">> Demostración de Limpieza de Memoria <<" << std::endl << std::endl;

    std::cout << "Llamando al destructor de G..." << std::endl;
    delete matrizG;
    std::cout << std::endl;

    std::cout << "Llamando al destructor de F..." << std::endl;
    delete matrizF;
    std::cout << std::endl;

    std::cout << "Llamando al destructor de E..." << std::endl;
    delete matrizE;
    std::cout << std::endl;

    std::cout << "Llamando al destructor de D..." << std::endl;
    delete matrizD;
    std::cout << std::endl;

    std::cout << "Llamando al destructor de C..." << std::endl;
    std::cout << "Liberando memoria de C (Matriz Dinámica)..." << std::endl;
    delete matrizC;
    std::cout << std::endl;

    std::cout << "Llamando al destructor de B..." << std::endl;
    std::cout << "Liberando memoria de B (Matriz Dinámica)..." << std::endl;
    delete matrizB;
    std::cout << std::endl;

    std::cout << "Llamando al destructor de A..." << std::endl;
    std::cout << "Liberando memoria de A (Matriz Dinámica)..." << std::endl;
    delete matrizA;
    std::cout << std::endl;

    

    return 0;
}