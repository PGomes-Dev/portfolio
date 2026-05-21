#include<stdio.h>
#include<string.h>
#define TF 10
main()
{
	char vnomes[TF][26],nome[25];		
	float vsaldop[TF];
	int pos,TL=0,i,op;
	
	printf("1. inserir\n");
	printf("2. excluir\n");
	printf("3. consultar\n");
	printf("4. sair\n");
	printf("Opcao desejada: ");
	scanf("%d",&op);
	
	while(op>=1 && op<=3)
	{
		switch(op)
		{
			case 1: printf("\nEntre com o nome do jogador:");
				    fflush(stdin);
			        gets(nome);
			        //busca no vetor uma informação
			        pos=0;
			        
			        while(stricmp(nome,vnomes[pos])!=0 && pos<TL)
			          pos++;
			          
			        if(pos<TL)
					  printf("\nJogador ja cadastrado!!");
					else
					{
						strcpy(vnomes[TL],nome);
						printf("\nEntre com o saldo de pontos:");
						scanf("%f",&vsaldop[TL]);
						TL++;
					}  
			        
			        break;
			        
			case 2:	printf("\nEntre com o nome do jogador a ser excluido:");
					gets(nome);
					//buscar o nome no Vetor
					pos=0;
					while(pos<TL && stricmp(nome,vnomes[pos])!=0)
						pos++;
					//Sera que achou?
					
					if(pos<TL)
					{
						for(i=pos;i<TL-1;i++)	//exlusão - remanejar os jogadores
						{
							strcpy(vnomes[i], vnomes[i+1]);
							vsaldop[i]=vsaldop[i+1];
						}
						
						//atualizar o valor do TL
						TL--;
					}
					
					else
						printf("\nJogador nao encontrado...");
					
					break;
			    
			case 3: printf("\nNome procurado: ");
			        fflush(stdin);
			        gets(nome);
			        
			        pos=0;
			        while(stricmp(nome,vnomes[pos])!=0 && pos<TL)
			         pos++;
			        if(pos<TL)
			         printf("Jogador = %s com %.2f pontos.\n",nome,vsaldop[pos]);
			        else
			         printf("\nUsuario nao encontrado!!");
			
			          //for(i=0;i<TL;i++)
			          //printf("Jogador = %s com %.2f pontos.\n",vnomes[i],vsaldop[i]);
			          
			        break;
			
		}
		
		
		
		printf("1. inserir\n");
	    printf("2. excluir\n");
	    printf("3. consultar\n");
	    printf("4. sair\n");
	    printf("Opcao desejada: ");
	    scanf("%d",&op);
	}
	
	
	
}
