#include <iostream>
#include "Zoo.h"
#include "Animal.h"
#include "Habitat.h"

void enlistarAnimales(Zoo* pZoo){
    vector<Habitat>::iterator itVector;
    int num = 1;
    vector<Habitat> vectorHabitats = pZoo->getHabitats();
    for (itVector = vectorHabitats.begin(); itVector != vectorHabitats.end(); ++itVector, num++){
        Habitat habitatTemp = *itVector;
        cout << num << ") ";
        itVector->imprimirAnimales();
    }
}

void nuevoAnimal(Zoo* pZoo){
    string tipoHabitats[4] = {"Desertico", "Selvatico", "Polar", "Acuatico"};
    string tiposDietas[3]={"Carnivoro", "Herbivoro","Omnivoro"};
    string especie, nombre, tipoHabitat, tipoDieta;
    int edad, horasDormir, opcDieta = 0, opcTipo = 0, opcHabitat = 0;
    int id = pZoo->getId();
    cout<<"Cual es la especie del animal?: "<<endl;
    cin>>especie;
    getline(cin, especie);
    cout<<"Como se llama?: "<<endl;
    cin>>nombre;
    getline(cin, nombre);
    cout<<"Cual es su edad?: "<<endl;
    cin>>edad;
    cout<<"Cuantas horas necesita dormir?: "<<endl;
    cin>>horasDormir;
    do{
        cout << "Selecciona el tipo de habitat del animal:" << endl;
        for(int i = 0; i <= 3; i++){
            cout << i+1 << ") " << tipoHabitats[i] << endl;
        }
        cin >> opcTipo;
    }while(opcTipo < 1 || opcTipo > 4);
    do{
        cout << "Selecciona el tipo de dieta:" << endl;
        for(int i = 0; i <= 2; i++){
            cout << i+1 << ") " << tiposDietas[i] << endl;
        }
        cin >> opcDieta;
    }while(opcDieta < 1 || opcDieta > 3);
    cout<<"Seleccione el habitat para el nuevo animal: "<<endl;
    pZoo->imprimirHabitats();
    vector<Habitat>::iterator itVector;
    do{
        int i = 0;
        cin>>opcHabitat;
        itVector = pZoo->getHabitats().begin();
        while(i<opcHabitat-1 && itVector != pZoo->getHabitats().end()){
            ++itVector;
            i++;
        }
    }while(itVector->getTipo()!=tipoHabitats[opcTipo-1]);
    Animal* nuevoAnimal = new Animal(nombre, especie, tipoHabitats[opcTipo-1], tiposDietas[opcDieta-1], id, edad, horasDormir, 0);
    itVector->agregarAnimal(*nuevoAnimal);
    pZoo->setId(id + 1);
}

void anadirHabitat(Zoo* pZoo){

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

    Habitat habTemp(nombreHabitat, tipoHabitats[opcTipo-1], mapaAnimales);  //opcTipo-1 porque recibe el numeral de seleccion y se lo necesita como indice del arreglo tipoHabitats
    pZoo->agregarHabitat(habTemp);
}

int main(){
    Animal juan("juan", "Burro", "Selva", "Carne", 123, 18, 7, 0);

    Zoo* pZoo = new Zoo;
    anadirHabitat(pZoo);
    anadirHabitat(pZoo);
    pZoo->imprimirHabitats();
    return 0;
}

