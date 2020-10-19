#include<stdio.h>
#include <pthread.h> 
#define MAX 1000 
#define MAX_THREAD 10 

int a[MAX];


int sum_t[10] = { 0 }; 
int part = 0; 
  
void* sum_array(void* arg) 
{  
	int thread_part = part++; 
      for(int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++)
	{
		a[i]=1;
	}
    // Each thread computes sum of 1/10th of array 
   
  
    for (int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++) 
        sum_t[thread_part] += a[i]; 
        	

} 
  
// Driver Code 
int main() 
{ 

  
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 4 threads 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 
  
    // joining 4 threads i.e. waiting for all 4 threads to complete 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 
  
    // adding sum of all 4 parts 
    int total_sum = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
        total_sum += sum_t[i]; 
  
   printf("total:%d\n",total_sum);
  
    return 0; 
} 
