# include <stdio.h>
# include <stdlib.h>

void Procedimento1 () { 
	int i = 0, a = 0, n; 
	printf("digite n");
	scanf("%d",&n);
	while (i < n) { 
		a += i;  
		i += 2;
		printf("procedimento 1 a=%d\n",a);
	} 
} 

void Procedimento2 () { 
	int i, j,n, a = 0;
	printf("digite n");
	scanf("%d",&n);
	for (i = 0; i < n; i ++) 
		for (j = 0; j < i; j ++) 
			a += i + j;
	printf("procedimento 2 a=%d\n",a);
} 

int main (){
	
	Procedimento1();
	Procedimento2();
	
	return 0;
}

