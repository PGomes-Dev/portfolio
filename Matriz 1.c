#include<stdio.h>
#define TFL 5
#define TFC 2
main()
{
	int C,L,cont=0;
	float Mnotas[TFL][TFC],media,soma;
	
	//leitura da matriz
	for(C=0;C<TFC;C++)
	{
		printf("\n=== Notas ===");
	
		for(L=0;L<TFL;L++)
		{
				printf("\nEntre com a nota do aluno: ");
				scanf("%f",&Mnotas[L][C]);
		}
	}
	
	//Quantos alunos tiveram nota > 6 na 1ª prova
	for(L=0;L<TFL;L++)
		if(Mnotas[L][0]>6)
			cont++;
	
	//Calculando a média das notas em cada bimestre
	for(C=0;C<TFC;C++)
	{
		soma=0;
		for(L=0;L<TFL;L++)
			soma=soma+Mnotas[L][C];
			
		media=soma/TFL;
		printf("\nA media = %.2f",media);
	}
	
	printf("\n\n%d Alunos tiraram nota > 6 na 1 prova",cont);
	
	//exibir a matriz
	
	printf("\n\n======| Notas dos Alunos |======");
		
	for(L=0;L<TFL;L++)
	{
		printf("\n\n");
		printf("Aluno %d:",L+1);
			
		for(C=0;C<TFC;C++)
		{
			printf(" | %.2f | ",Mnotas[L][C]);				
		}
				
		printf("\n");
	}
			
}
