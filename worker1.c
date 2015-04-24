#include<stdlib.h>
#include<stdio.h>
#include<semaphore.h>

sem_t *service_sem, *request_sem;
int worker_count;
int browser_count;
void pair();

void init() {
	sem_init(&request_sem, 0, 0);
	sem_init(&service_sem, 0, 0);
}

void wait_for_service() {
	sem_wait(&service_sem);
	browser_count++;
	if(worker_count == 1 && browser_count == 1){
		pair();
		worker_count--;
		browser_count--;
		sem_post(&request_sem);
		sem_post(&service_sem);
	}

}

void wait_for_request() {
	sem_wait(&request_sem);
	worker_count++;
	if(worker_count == 1 && browser_count == 1){
		pair();
		worker_count--;
		browser_count--;
		sem_post(&request_sem);
		sem_post(&service_sem);
	}
}
