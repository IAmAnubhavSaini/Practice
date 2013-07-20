#include <time.h>
#include <stdlib.h>

void initiate_randomness(void){
  srand(time(NULL));
#ifndef INITIATED_RANDOMNESS
#define INITIATED_RANDOMNESS
#endif
}
int generate_random_number(void){
#ifndef INITIATED_RANDOMNESS
  initiate_randomness();
#endif
  int r = rand();
}

