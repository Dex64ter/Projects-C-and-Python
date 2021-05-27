#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <locale.h>
#include <pthread.h>

#define N 5
// #define LEFT (i+N-1)%N
// #define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond[N];

int state[N];

void printEstados();
void *philosopherFunction(void* i);
void take_forks(int i);
void put_forks(i);
void test(i);

int main(){
	setlocale(LC_ALL, "Portuguese");
	pthread_t philosopher1, philosopher2, philosopher3, philosopher4, philosopher5;
	int rp1, rp2, rp3, rp4, rp5;
	int p1=0, p2=1, p3=2, p4=3, p5=4; 
	
	rp1 = pthread_create( &philosopher1, NULL, philosopherFunction, &p1);
	rp2 = pthread_create( &philosopher2, NULL, philosopherFunction, &p2);
	rp3 = pthread_create( &philosopher3, NULL, philosopherFunction, &p3);
	rp4 = pthread_create( &philosopher4, NULL, philosopherFunction, &p4);
	rp5 = pthread_create( &philosopher5, NULL, philosopherFunction, &p5);
	
	pthread_join( philosopher1, NULL);
	pthread_join( philosopher2, NULL);
	pthread_join( philosopher3, NULL);
	pthread_join( philosopher4, NULL);
	pthread_join( philosopher5, NULL);
	   // pthread_t thread1, thread2;
	   // char *message1 = "Thread 1";
	   // char *message2 = "Thread 2";
	   // int iret1, iret2;
	   	
	exit(0);
}

void *philosopherFunction(void* i){ 	// i: o numero do filosofo, de 0 a N–1 
	int *in = (int*) i;
	while (1){   			// repete para sempre 
		//state[*in] = THINKING; 			// o filosofo esta pensando
		Sleep(5000);
		take_forks(*in); 		// pega dois garfos ou bloqueia 
		Sleep(5000);
		//state[*in] = EATING; 			// hummm, espaguete! 
		put_forks(*in); 		// devolve os dois garfos a mesa 
	}
}

void take_forks(int i){ 	// i: o numero do filosofo, de 0 a N–1 
	pthread_mutex_lock(&mutex1); 			// entra na regiao critica
	state[i] = HUNGRY; 		// registra que o filosofo esta faminto
	Sleep(5000);
	printEstados();
	printf("\n");
	test(i); 				// tenta pegar dois garfos
	pthread_cond_wait( &cond[i], &mutex1 );		// bloqueia se os garfos nao foram pegos 
	pthread_mutex_unlock(&mutex1); 			// sai da regiao critica
}

void put_forks(int i){ 			// i: o numero do filosofo, de 0 a N–1
	pthread_mutex_lock(&mutex1); 			// entra na regiao critica
	state[i] = THINKING; 	// o filosofo acabou de comer
	Sleep(5000);
	test((i+N-1)%N); 			// ve se o vizinho da esquerda pode comer agora
	Sleep(5000);
	test((i+1)%N); 			// ve se o vizinho da direita pode comer agora
	pthread_mutex_unlock(&mutex1); 			// sai da regiao critica
}

void test(int i){				// i: o numero do filosofo, de 0 a N–1 
	if (state[i] == HUNGRY && state[(i+N-1)%N] != EATING && state[(i+1)%N] != EATING){
		state[i] = EATING;
		Sleep(5000);
		printEstados();
		printf("\n");
		pthread_cond_signal( &cond[i] );
	}
	
}

void printEstados(){
	int aux;
	printf("Situação no momento: \n");
	for(aux=0; aux<N; aux++){
		switch(state[aux]){
			
		case 0:
			printf("Philosopher %d: Thinking\n", aux+1);
			break;
		case 1:
			printf("Philosopher %d: Hungry\n", aux+1);
			break;
		case 2:
			printf("Philosopher %d: Eating\n", aux+1);
			break;
		}
	}
}
