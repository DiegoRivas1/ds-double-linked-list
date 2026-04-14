#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
#include "DoubleCircularList.h"
#include "DoubleCircularListComposition.h"

void saveDot(const std::string& content, const std::string& filename) {
    std::ofstream file("../outputs/" + filename);
    file << content;
    file.close();
    std::cout << "Generado: outputs/" << filename << "\n";
}

void generateImage(const std::string& name) {
    std::string cmd = "dot -Tpng ../outputs/" + name + ".dot -o ../outputs/" + name + ".png";
    int result = system(cmd.c_str());
    if (result == 0) {
        std::cout << "Imagen generada: outputs/" << name << ".png\n";
    } else {
        std::cout << "Error al generar: outputs/" << name << ".png\n";
    }
}

int main() {
    //const int cantidadNodos = 10; Se conoce en tiempo de ejecucion
    constexpr int cantidadNodos = 10; //constexpr (se conocie en tiempo de compilacion)
    constexpr int cantidadNames = 2;
    // Polimorfismo, listas que heredan de List<T>
    List<int>* lists[cantidadNames] = {
        new DoubleLinkedList<int>(),
        new DoubleCircularList<int>()
    };

    for (int i = 0; i < cantidadNames; i++) {
        std::string listNames[cantidadNames] = {"double_linked_list", "double_circular_list"};
        for (int j = 0; j < cantidadNodos; j++) {
            lists[i]->insert(j + 1, j);
        }
        std::cout << "=== " << listNames[i] << " ===\n";
        std::cout << *lists[i];
        saveDot(lists[i]->toDot(), listNames[i] + ".dot");
        generateImage(listNames[i]);
        delete lists[i];
    }

    // Composicion, DoubleCircularListComposition
    std::string compName = "double_circular_list_composition";
    DoubleCircularListComposition<int> comp;
    for (int i = 0; i < cantidadNodos; i++) {
        comp.insertBack(i + 1);
    }
    std::cout << "=== " << compName << " ===\n";
    std::cout << comp;
    saveDot(comp.toDot(), compName + ".dot");
    generateImage(compName);

    return 0;
}