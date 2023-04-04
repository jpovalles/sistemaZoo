#include <iostream>
#include "Zoo.h"
#include "Animal.h"
#include "Habitat.h"

void listarAnimales(Zoo* pZoo) {
    Habitat *pHabitatTemp;
    Animal *pAnimalTemp;
    vector<Habitat> vectorHabitats = pZoo->getHabitats();
    vector<Habitat>::iterator iVectorH;

    for (iVectorH = vectorHabitats.begin(); iVectorH != vectorHabitats.end(); ++iVectorH) {
        unordered_map<int, Animal> *mapaAnimales = iVectorH->getMapa();
        unordered_map<int, Animal>::iterator iMapa;
        cout << "En " << iVectorH->getNombre() << " de tipo " << iVectorH->getTipo() << " se encuentran: \n" << endl;
        for (iMapa = mapaAnimales->begin(); iMapa != mapaAnimales->end(); ++iMapa) {
            cout << "\tID: " << iMapa->second.getId() << " Nombre: " << iMapa->second.getNombre() << " Especie: "
                 << iMapa->second.getEspecie() << " Edad: " << iMapa->second.getEdad();
            cout << " Dieta: " << iMapa->second.getDieta() << " Tipo de habitat: " << iMapa->second.getTipoHabitat()
                 << "\n" << endl;
        }
    }
}
void anadirHabitat(){
    string tipoHabitats[4] = {"Desertico", "Selvatico", "Polar", "Acuatico"};
    int opcTipo = 0;
    string nombreHabitat;

    cout << "Ingrese el nombre del nuevo habitat:" << endl;
    cin >> nombreHabitat;

    do{
        cout << "Selecciona el tipo de habitat:" << endl;
        for(int i = 0; i <= 3; i++){
            cout << i+1 << ") " << tipoHabitats[i] << endl;
        }
        cin >> opcTipo;
    }while(opcTipo < 1 || opcTipo > 4);

    unordered_map<int, Animal>* mapaAnimales;

    Habitat habTemp(nombreHabitat, tipoHabitats[opcTipo], mapaAnimales);
}

int main(){
    Animal juan("juan", "Burro", "Selva", "Carne", 123, 18, 7, 0);
    juan.juego();
    juan.juego();
    juan.juego();

    anadirHabitat();
    return 0;
}

