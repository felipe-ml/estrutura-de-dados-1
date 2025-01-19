# Relatório

## Comparação dos Métodos de Ordenação

### Bubble Sort
- É um algoritmo simples, mas ineficiente para grandes entradas.
- **Complexidade no pior caso**: \( O(n^2) \), onde \( n \) é o número de pratos.
- Para o limite máximo (\( n = 300,000 \)), o Bubble Sort seria extremamente lento e inviável.

### QuickSort
- É muito mais eficiente e prático para entradas grandes.
- **Complexidade média**: \( O(n \log n) \).
- Pivôs são escolhidos estrategicamente, e o array é dividido em subpartes menores para facilitar a ordenação.

---

## Escolha de Pivôs no Quicksort
No código, o pivô foi escolhido como o último elemento da sublista atual. Essa escolha é simples de implementar e funciona bem para listas de tamanhos moderados. 

No entanto, em casos piores (como listas quase ordenadas), poderia ser melhor usar pivôs mais dinâmicos, como o **mediano de três elementos**.
