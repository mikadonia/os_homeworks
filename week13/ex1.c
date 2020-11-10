#include <stdio.h>

int C[5][3];//current allocation matrix
int R[5][3];//request matrix
int proc_finished[5];
int E[3]; // existing resource vector
int A[3]; //available resource vector

int main () {
	FILE *input_dl = fopen("input_dl.txt", "r"); //open input.txt for reading

	for (int i = 0; i < 3; ++i){
		fscanf(input_dl, "%d", &E[i]); //read 7 2 6 to E
	}
	for (int i = 0; i < 3; ++i){
		fscanf(input_dl, "%d", &A[i]); //read 0 0 0 to A 
	}
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 3; ++j){
			fscanf(input_dl, "%d", &C[i][j]);//fill in C matrix
		}
	}
	for (int i = 0; i < 5; ++i){ //fill in R matrix
		for (int j = 0; j < 3; ++j){
			fscanf(input_dl, "%d", &R[i][j]);
		}
	}

	while (1) {
		int is_finished = 0; //process state. Firstly we suppose that process is not finished => 0
		for (int i = 0; i < 5; ++i){
			if (proc_finished[i] == 0) {//if process is not finished
				int flag = 1; //process state flag. Firstly we suppose that process can be finished => 0
				for (int j = 0; j < 3; ++j) {
					if (R[i][j] > A[j]) { //if can not be finished 
	 					flag = 0; //process is not finished
					    }
	 			}
				if (flag == 1) { //if process is finished
					proc_finished[i] = 1;
					is_finished = 1;
					for (int j = 0; j < 3; ++j){
						A[j] += C[i][j];	
					}
				}
						
			}
		}
        if (is_finished == 0) {
			break;
        }
	}	

	FILE *output_dl = fopen("output_dl.txt", "w"); //open the output.txt to write
	int deadlock = 0; //deadlock state. Suppose that no deadlock now
	for (int i = 0; i < 5; ++i){
		if (proc_finished[i] == 0) {//if proc can not finish => deadlock occured
			fprintf(output_dl, "%d ", i);
			deadlock = 1;		
		}
		else {
			fprintf(output_dl, "%s\n", "ok");
		}
    }
	if (deadlock == 0)
		fprintf(output_dl, "no deadlock is detected");

	fclose(input_dl);
	fclose(output_dl);

	return 0;
}
