#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid) {
  printf("Hello, world! This is thread # %d\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t threads[NUMBER_OF_THREADS];
  int status;
  for (int i = 0; i < NUMBER_OF_THREADS; i++) {
    printf("This is main program. Create thread # %d\n", i);
    status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
    if (status != 0) {
      printf("Sorry pthread_create() return error code %d\n", status);
      exit(-1);
    }
  }
  sleep(1);
  exit(0);
} 
