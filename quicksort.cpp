#include <stdio.h>

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      // salva valor do pivot
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      // enquanto os índices não se encontrarem/cruzarem
      while (i <= j) {
      	    // aumenta índice da esquerda até encontrar um valor igual ou maior que o pivot
            while (arr[i] < pivot)
                  i++;
      	    // diminui índice da direita até encontrar um valor igual ou menor que o pivot
            while (arr[j] > pivot)
                  j--;
            // se os índices não se cruzaram
            if (i <= j) {
            	// troca valores dos índices encontrados
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                // aumenta índice da esquerda e diminui da direita
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      // se sub-vetor da esquerda tem mais que uma posição
      if (left < j)
            quickSort(arr, left, j);
      // se sub-vetor da direita tem mais que uma posição
      if (i < right)
            quickSort(arr, i, right);
}

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void imprime(int vetor[]) {
	for(int i=0; i<8; i++) {
		printf("%d, ", vetor[i]);
	} 
	printf("\n");
}

int partition(int arr[], int left, int right) {
	int m = (left + right) / 2;
	swap(arr, left, m);
	int pivot = arr[left];
	int lo = left + 1;
	int hi = right;

	// enquanto os indices não se cruzam...
	while (lo<=hi) {
		while(arr[hi] > pivot)
			hi--;
		while(lo<=hi && arr[lo]<= pivot)
			lo++;
		if(lo<=hi) {
			printf("pre-swap lo:%d hi: %d\n", lo, hi);
			imprime(arr);
			swap(arr, lo, hi);
			printf("post-swap lo:%d hi: %d\n", lo, hi);
			imprime(arr);
			printf("---------------------------------\n");
			lo++;
			hi--;
		}
	}
	printf("pre-final swap lo:%d hi: %d\n", lo, hi);
	imprime(arr);
	swap(arr, left, hi);
	printf("post-final swap lo:%d hi: %d\n", lo, hi);
	imprime(arr);
	printf("=========================================\n");
	return hi;
}

void quicksort(int arr[], int left, int right) {

	if(left < right) {
		int q = partition(arr, left, right);
		quicksort(arr, left, q-1);
		quicksort(arr, q+1, right);
	} 
}

int main () {
	/*int vetor[8];
	for(int i=0; i<8; i++) {
		scanf("%d", &vetor[i]);
	} */
	int vetor[9] = {25,57,48,37,12,92,86,33,12};
	
	quicksort(vetor, 0, 8);
	
	imprime(vetor);
}
