#include <stdio.h>
#include <malloc.h>


void* my_malloc(size_t a, const void * ptr){

	void *p;
	p=sbrk(0);
	printf("\n%p\n\n", sbrk(0));
	sbrk(a);
	return p;

}

void my_free(void *ptr, const void *p){
/*	int a;
	void *buf;
	a=sizeof(ptr);
	printf("\n\n%d\n\n", a);
	buf=sbrk(ptr);*/
	brk(ptr);
}


void init(void){
	__malloc_hook=my_malloc;
	__free_hook=my_free;
}

void (* __malloc_initialize_hook)(void)=init;

int main(){

	int *a, *b, *c;
	struct mallinfo mi;
	a=malloc(4);
	b=malloc(4);
	c=malloc(4);
	*a=11111;
	*b=22222;
	*c=33333;
	printf("%d - %d - %d\n", *a, *b,*c);
	printf("%p - %p - %p\n", a, b,c);
	free(b);
	printf("\nTra-ta-ta - %d  %p  %p\n", *c, c, sbrk(0));
	*c=4444;
	printf("\n%d\n",*c);
}
