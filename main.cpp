#include <iostream>
#include "Zoo.h"

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

int main() {
    Animal juan("juan", "Burro", "Selva", "Carne", 123, 18, 7, 0);
    juan.juego();
    juan.juego();
    juan.juego();

    anadirHabitat();
    return 0;
}
