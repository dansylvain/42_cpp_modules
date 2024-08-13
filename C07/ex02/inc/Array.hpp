#pragma once

template <typename T>
class Array {
public:
    Array(size_t size);     // Constructeur avec taille
    Array(const Array& other); // Constructeur de copie
    Array& operator=(const Array& other); // Opérateur d'assignation
    ~Array();               // Destructeur

    T& operator[](size_t index); // Accesseur d'élément
    const T& operator[](size_t index) const; // Accesseur d'élément (const)

    size_t getSize() const; // Retourne la taille du tableau

private:
    T* data;         // Tableau dynamique pour stocker les éléments
    size_t size;     // Taille du tableau

    void copyFrom(const Array& other); // Méthode pour copier les données
    void free();    // Méthode pour libérer la mémoire
};

#include "Array.tpp" // Inclure les définitions des templates
