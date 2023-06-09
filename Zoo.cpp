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

void Zoo::setVector(vector<Habitat> vectorTemp){
    this->listaHabitats = vectorTemp;
}

unordered_map<string, vector<string>> Zoo::getComida(){
    return comida;
}

//verifica en el mapa que el alimento que se quiere dar exista y pertenezca a la dieta del animal
bool Zoo::buscarComida(string tipoDieta, string alimento){
    vector<string> vectorDieta = this->comida[tipoDieta];
    vector<string>::iterator itVector;
    for (itVector = vectorDieta.begin(); itVector != vectorDieta.end(); ++itVector){
        if(*itVector == alimento){
            return true;
        }
    }
    cout << "\n# " << alimento << " no se encuentra en la dieta " << tipoDieta << endl;
    return false;
}

void Zoo::agregarAlimento(string tipoDieta, string alimento){
    this->comida[tipoDieta].push_back(alimento);
    cout << alimento << " fue anadido correctamente a la dieta " << tipoDieta << endl;
}

bool Zoo::eliminarAlimento(string tipoDieta, string alimento){
    vector<string>::iterator itVector;

    for (itVector = this->comida[tipoDieta].begin(); itVector != this->comida[tipoDieta].end(); ++itVector){
        if(*itVector == alimento){
            this->comida[tipoDieta].erase(itVector);
            cout << alimento << " fue eliminado de la dieta " << tipoDieta << endl;
            return true;
        }
    }
    cout << "\n# " << alimento << " no se encuentra en la dieta " << tipoDieta << endl;
    return false;
}

int Zoo::getId(){
    return this->currentId;
}

void Zoo::setId(int id){
    this->currentId = id;
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

void Zoo::imprimirDieta(string tipo){
    vector<string> vectorComidas = this->comida[tipo];
    vector<string>::iterator itVector;

    cout << "Dieta " << tipo << ":" << endl;

    for (itVector = vectorComidas.begin(); itVector != vectorComidas.end(); ++itVector){
        string alimentoTemp = *itVector;
        cout << "\t" << alimentoTemp << endl;
    }
    cout << "-------------------------------" << endl;
}