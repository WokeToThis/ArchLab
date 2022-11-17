#include <stdio.h>

int main(void){

int a=0;

for(int i=0;i<10000;i++){
	if(a%2==0){
		a++;
		
	}
	a = a + i*3;
}

return 0;
}
