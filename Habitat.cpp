//
// Created by LENOVO on 03/04/2023.
//

#include "Habitat.h"

Habitat::Habitat(string nombre, string tipo, unordered_map<int, Animal*> mapaAnimales): nombre(nombre), tipo(tipo), mapaAnimales(mapaAnimales){}

string Habitat::getNombre(){
    return this->nombre;
}

string Habitat::getTipo(){
    return this->tipo;
}

unordered_map<int, Animal*> Habitat::getMapa(){
    return mapaAnimales;
}

void Habitat::agregarAnimal(Animal tempAnimal){
    this->mapaAnimales.insert(make_pair(tempAnimal.getId(), &tempAnimal));

    cout<<tempAnimal.getNombre()<<" fue agregado al habitat"<<endl;
}

void Habitat::imprimirAnimales(){
    unordered_map<int, Animal*> mapaAnimales = this->mapaAnimales;
    unordered_map<int, Animal*>::iterator iMapa;
    cout << "En " << this->nombre << " de tipo " << this->tipo << " se encuentran: \n" << endl;
    int num = 1;
    for (iMapa = mapaAnimales.begin(); iMapa != mapaAnimales.end(); ++iMapa, num++) {
        cout << "\t"<<num<< ") ID: " << iMapa->second->getId() << " Nombre: " << iMapa->second->getNombre() << " Especie: "
             << iMapa->second->getEspecie() << " Edad: " << iMapa->second->getEdad();
        cout << " Dieta: " << iMapa->second->getDieta() << " Tipo de habitat: " << iMapa->second->getTipoHabitat()
             << "\n" << endl;
    }
}