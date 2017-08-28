#include <stdio.h>

int main(int argc,char *argv[])
{
   int i;
   printf("# de parametros:%d\n",(argc-1));
	
   for(i=0;i<argc;i++){
	   if(i==0){
		   printf("Nome do executavel:%s\n",argv[i]);
	   }
	   else{
		   printf("Parametro #%d: %s \n",i,argv[i]);
	   }
   }

	return 0;
}
