#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct Prato {
    int prioridade;
    int tempo;
    std::string nome;
};


bool comparar(const Prato& a, const Prato& b) {
    if (a.prioridade != b.prioridade) {
        return a.prioridade > b.prioridade; 
    }
    return a.tempo < b.tempo; 
}

void bubbleSort(std::vector<Prato>& pratos) {
    bool trocou;
    do {
        trocou = false;
        for (size_t i = 0; i < pratos.size() - 1; ++i) {
            if (!comparar(pratos[i], pratos[i + 1])) {
                std::swap(pratos[i], pratos[i + 1]);
                trocou = true;
            }
        }
    } while (trocou);
}

int particionar(std::vector<Prato>& pratos, int inicio, int fim) {
    Prato pivo = pratos[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; ++j) {
        if (comparar(pratos[j], pivo)) {
            ++i;
            std::swap(pratos[i], pratos[j]);
        }
    }
    std::swap(pratos[i + 1], pratos[fim]);
    return i + 1;
}

void quickSort(std::vector<Prato>& pratos, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(pratos, inicio, fim);
        quickSort(pratos, inicio, pivo - 1);
        quickSort(pratos, pivo + 1, fim);
    }
}

int main() {
    std::string caminhoArquivo = "C:/Users/Felipe Moura/Desktop/lista_1/restaurante_pratos.csv";
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << std::endl;
        return 1;
    }

    std::vector<Prato> pratos;
    std::string linha;

    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        Prato prato;
        std::string prioridade, tempo;

        std::getline(ss, prioridade, ',');
        std::getline(ss, tempo, ',');
        std::getline(ss, prato.nome, ',');

        prato.prioridade = std::stoi(prioridade);
        prato.tempo = std::stoi(tempo);

        pratos.push_back(prato);
    }

    arquivo.close();

    std::cout << "Escolha o método de ordenação (1 = Bubble Sort, 2 = QuickSort): ";
    int escolha;
    std::cin >> escolha;

    if (escolha == 1) {
        bubbleSort(pratos);
    } else if (escolha == 2) {
        quickSort(pratos, 0, pratos.size() - 1);
    } else {
        std::cerr << "Método inválido escolhido!" << std::endl;
        return 1;
    }

    for (const auto& prato : pratos) {
        std::cout << prato.nome << std::endl;
    }

    return 0;
}
