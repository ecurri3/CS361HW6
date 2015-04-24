#include"barrier.h"
#include<stdlib.h>
#include<stdio.h>

void barrier_init(barrier* b, int s) {
	pthread_barrier_init(b, 0, s);
}

void barrier_wait(barrier* b) {
	pthread_barrier_wait(b);
}
