#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Prato {
    int prioridade;
    int tempo;
    string nome;

    bool operator<(const Prato& other) const {
        if (prioridade != other.prioridade)
            return prioridade > other.prioridade; 
        return tempo < other.tempo; 
    }
};


void bubbleSort(vector<Prato>& pratos) {
    size_t n = pratos.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (pratos[j] < pratos[j + 1]) {
                swap(pratos[j], pratos[j + 1]);
            }
        }
    }
}

int partition(vector<Prato>& pratos, int low, int high) {
    Prato pivot = pratos[high]; 
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (pratos[j] < pivot) { 
            ++i;
            swap(pratos[i], pratos[j]);
        }
    }
    swap(pratos[i + 1], pratos[high]);
    return i + 1;
}


void quickSort(vector<Prato>& pratos, int low, int high) {
    if (low < high) {
        int pi = partition(pratos, low, high); 
        quickSort(pratos, low, pi - 1);      
        quickSort(pratos, pi + 1, high);      
    }
}

int main() {
    int n;
    cin >> n;

    vector<Prato> pratos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pratos[i].prioridade >> pratos[i].tempo >> pratos[i].nome;
    }

    quickSort(pratos, 0, n - 1);

    for (const auto& prato : pratos) {
        cout << prato.nome << endl;
    }

    return 0;
}
