#include"rwlock.h"
#include<stdlib.h>
#include<stdio.h>

int shared_count;

void rwlock_init(rwlock* m, int concurrent_readers){
	sem_init(&m->writers, 0, 1);
	sem_init(&m->readers, 0, concurrent_readers);

}

void rlock(rwlock * m){
	if(shared_count > 0){
		return;
	}
	sem_wait(&m->readers);
}

void runlock(rwlock * m){
	sem_post(&m->readers);
}

void wlock(rwlock * m){
	sem_wait(&m->writers);
	shared_count++;
}

void wunlock(rwlock * m){
	sem_post(&m->writers);
	shared_count--;
}

