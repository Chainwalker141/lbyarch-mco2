#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000000
#define PRINT 10


extern float asmMP2(float x1, float x2, float y1, float y2);

// test function to determine timer works
void function(){
	int i;
	for (i = 0; i < 1000000000; i++){
		int result = i+1;
	}
}

int main(){
	
	clock_t start, end;
	double time;
	
	
	// float x1[]={1.5f,4.0f,3.5f,2.0f};
	// float x2[]={3.0f,2.5f,2.5f,1.0f};
	// float y1[]={4.0f,3.0f,3.5f,3.0f};
	// float y2[]={2.0f,2.5f,1.0f,1.5f};
	// float z[4];
	
	float *x1 = (float*)malloc(SIZE * sizeof(float));
	float *x2 = (float*)malloc(SIZE * sizeof(float));
	float *y1 = (float*)malloc(SIZE * sizeof(float));
	float *y2 = (float*)malloc(SIZE * sizeof(float));
	float *z = (float*)malloc(SIZE * sizeof(float));
	
	if (!x1 || !x2 || !y1 || !y2 || !z) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

	printf("Z ->");
	int i;
	
	// initialize all arrays to i
	// 1 indexed to prevent 0 value
	printf("VALUES OF ARRAYS [i] UNTIL [%d]\n", PRINT);
	printf("ARRRAY SIZE: %d\n", SIZE);
	printf("=========================\n");
	for (i = 1; i <= SIZE; i++){
		x1[i] = i * 1.0f;  // Explicitly cast to float 
		x2[i] = i * 2.0f;
		y1[i] = i * 3.0f;
		y2[i] = i * 4.0f;
		if(i <= PRINT){
			printf("[%d] x1=%f, x2=%f, y1=%f, y2=%f, \n", i, x1[i], x2[i], y1[i], y2[i]);
		}
	}
	printf("=========================\n\n");
	
	
	printf("VALUES OF Z AT [i] UNTIL [%d]\n", PRINT);
	printf("=========================\n");
	// to get the time of the start of the function
	start = clock();
	// 1 indexed to prevent 0 value
	for (i = 1; i <= SIZE; i++){
		z[i] = asmMP2(x1[i], x2[i], y1[i], y2[i]);
		
		if(i <= PRINT){
			printf("[%d] %f\n", i,z[i]);
		}
		
		
	}
	printf("=========================\n\n");
	// to get the time of the end of the function
	end = clock();
	
	time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("Execution time of kernel: %fs", time);
	
	// Free allocated memory
    free(x1);
    free(x2);
    free(y1);
    free(y2);
    free(z);
	
	printf("\n");
	return 0;
}
