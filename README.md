# Relatório

## Comparação dos Métodos de Ordenação

### Bubble Sort
- É um algoritmo simples, mas ineficiente para grandes entradas.
- **Complexidade no pior caso**: \( O(n^2) \), onde \( n \) é o número de pratos.
- Para o limite máximo (\( n = 300,000 \)), o Bubble Sort seria extremamente lento e inviável.
- Implementação no código: percorre repetidamente a lista, trocando elementos adjacentes fora de ordem até que a lista esteja ordenada.

### QuickSort
- É muito mais eficiente e prático para entradas grandes.
- **Complexidade média**: \( O(n \log n) \).
- Divide a lista em subpartes menores usando um pivô, ordenando cada subparte recursivamente.
- Implementação no código: utiliza o último elemento como pivô, particiona os elementos menores para a esquerda e os maiores para a direita, e aplica a ordenação recursivamente.

---

## Escolha de Pivôs no Quicksort
No código, o pivô foi escolhido como o último elemento da sublista atual. Essa escolha é simples de implementar e funciona bem para listas de tamanhos moderados. 

Para melhorar o desempenho em casos piores (como listas quase ordenadas), outras estratégias, como o **mediano de três elementos**, poderiam ser usadas. Isso envolve escolher o pivô com base na mediana do primeiro, último e elemento central da lista atual.

---

## Ajustes Adicionais no Código

1. **Leitura de Arquivo CSV**
   - O código lê os dados do arquivo CSV no formato:
     ```csv
     prioridade,tempo,nome
     7,30,fish-and-chips
     1984,1,poitin
     1,20,bubble-and-squeak
     ```
   - Utiliza `std::getline` com delimitadores para extrair os campos corretamente.

2. **Exibição de Dados**
   - Após a ordenação, os nomes dos pratos são exibidos na ordem decrescente de prioridade e, em caso de empate, em ordem crescente de tempo de preparo.

3. **Método de Ordenação**
   - O usuário pode escolher entre Bubble Sort (1) e QuickSort (2) na execução do programa.

4. **Tratamento de Erros**
   - Verifica se o arquivo foi aberto corretamente antes de prosseguir com a leitura dos dados.
