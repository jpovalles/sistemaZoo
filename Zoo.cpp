//
// Created by LENOVO on 03/04/2023.
//

#include "Zoo.h"

void Zoo::agregarHabitat(Habitat habitatTemp){
    this->listaHabitats.push_back(habitatTemp);
    cout << "El habitat " << habitatTemp.getNombre() << " fue anadido correctamente!" << endl;
}

vector<Habitat> Zoo::getHabitats(){
    return listaHabitats;
}

unordered_map<string, vector<string>> Zoo::getComida(){
    return comida;
}

bool Zoo::buscarComida(string tipoDieta, string alimento){
    vector<string> vectorDieta = this->comida[tipoDieta];
    vector<string>::iterator itVector;

    for (itVector = vectorDieta.begin(); itVector != vectorDieta.end(); ++itVector){
        //string comida = *itVector;
        if(*itVector == alimento){
            return true;
        }
    }
    return false;
}

void Zoo::agregarAlimento(string tipoDieta, string alimento){
    this->comida[tipoDieta].push_back(alimento);
    cout << alimento << " fue añadido correctamente a la dieta " << tipoDieta << endl;
}

bool Zoo::eliminarAlimento(string tipoDieta, string alimento){
    vector<string> vectorDieta = this->comida[tipoDieta];
    vector<string>::iterator itVector;

    for (itVector = vectorDieta.begin(); itVector != vectorDieta.end(); ++itVector){
        //string comida = *itVector;
        if(*itVector == alimento){
            vectorDieta.erase(itVector);
            cout << alimento << " fue eliminado de la dieta " << tipoDieta << endl;
            return true;
        }
    }
    cout << alimento << " no se encuentra en la dieta " << tipoDieta << endl;
    return false;
}

void Zoo::imprimirHabitats(){
    vector<Habitat>::iterator itVector;
    int num = 1;

    for (itVector = this->listaHabitats.begin(); itVector != this->listaHabitats.end(); ++itVector, num++){
        Habitat habitatTemp = *itVector;
        cout << num << ")" << endl;
        cout << "Nombre: " << habitatTemp.getNombre() << endl;
        cout << "Tipo de habitat: " << habitatTemp.getTipo() << endl;
        cout << "-------------------------------" << endl;
    }
}