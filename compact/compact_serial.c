#include <stdio.h>
#include <stdlib.h> 
// #include <omp.h> 

int *generateIndex(int size){
	int *tmp_ind = (int*)malloc(size*sizeof(int));
	int i; 
	for(i = 0; i < size; i++)
		tmp_ind[i] = rand()%2; 
	return tmp_ind;
}

char *generateData(int size){
	char *tmp_data = (char *) malloc(size * sizeof(char)); 
	int i; 
	for(i = 0; i<size; i++)
		tmp_data[i] = rand()%26 + 65; 
	tmp_data[i+1] = '\0'; 
	return tmp_data; 
}

int main(int argc, char *argv[]){
	if(argc != 3) {
		printf("Usage:\nbash$:./compact_serial <sizeOfData> <debugFlag>\n\n");
		printf("Example: \n"); 
		printf("$bash: ./compact_serial 10 1\n"); 
		printf("That generates 10 random character and Turns on Debug\n"); 
		printf("$bash: ./compact_serial 10 0\n"); 
		printf("That generates 10 random character and Turns off Debug\n"); 
		exit(EXIT_FAILURE); 
	}
	int n = atoi(argv[1]); 
	int debug = atoi(argv[2]); 
	int i;
	int *index = generateIndex(n);
	char *data = generateData(n); 
	if(debug == 1){
		printf("DATA:\t\t");
		for(i = 0; i < n; i++) printf("%c%c", data[i], (i == n-1)?'\n':' '); 
		printf("INDEXES\t\t");
		for(i = 0; i < n; i++) printf("%d%c", index[i], (i == n-1)?'\n':' '); 
	}
	char *comp = (char*)calloc(n,sizeof(char));
	int tmp_ind = 0; 
	int new_index[n]; 
	for(i = 0; i < n; i++){
		if(index[i] == 1) {
			new_index[i] = tmp_ind; 
			tmp_ind++; 
		}
		else {
			new_index[i] = tmp_ind; 
		}
	}
	
	for(i = 0; i < n; i++){
		if(index[i] == 1){
			comp[new_index[i]] = data[i];
		}
	}
	if(debug == 1){
		printf("NEW INDEXES\t");
		for(i = 0; i < n; i++) printf("%d%c",new_index[i], (i==n-1)?'\n':' ');
		printf("COMPACTED\t");
		for(i = 0; i < n; i++) printf("%c ", comp[i]);
		printf("\n");
	}
	return 0; 
}
