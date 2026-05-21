#include<stdio.h>
#include<string.h>
#define TF 200

main()
{
	int Vdia_vencimento[TF],op,pos,TL_inst=0,TL_alunos=0,TL_mod=0,TL_Aval=0,Data_hoje=0,i;
	float Vvalor[TF], Vvalor_aula[TF],receita_total;
	char Vinstrutor[TF][101], Vnome[TF][101], Vmodalidade[TF][101], Vcpf[TF][12],Vtelefone[TF][12],nome[201],continuar,cpf[12],Vcod_inst[TF][10],cod[10],Vcod_mod[TF][10], Vdia_avaliacao[TF][9], Vcpf_Aval[TF][12], Vcod_inst_Aval[TF][10];	
	
	do
	{
	
		printf("\n\n\tSeja Bem vindo ao sistema da Academia Hit-Boxe!!");
		printf("\n\t================================================");
		printf("\n\nPara iniciar selecione uma das opcoes a seguir:");
		printf("\n\n1 - Cadastro");
		printf("\n2 - Exclusao");
		printf("\n3 - Lancamento");
		printf("\n4 - Relatorio");
		printf("\n5 - Finalizar");
	
		printf("\n\nEntre com a opcao desejada: ");
		scanf("%d",&op);
	
		switch(op)
		{
			case 1: // Case de Cadastro 
				{
					do
					{
						printf("\n================================================");
						printf("\n\nQual opcao de cadastro voce deseja fazer?:");
					
						printf("\n1 - Instrutor");
						printf("\n2 - Aluno");
						printf("\n3 - Modalidade");
						printf("\n4 - Voltar");
				
						printf("\n\nQual a opcao desejada?: ");
						scanf("%d",&op);
						printf("\n================================================");
					
							switch(op)
							{
								case 1: //Cadastro de Instrutores
									{
										do
										{
											fflush(stdin);
											printf("\n\nEntre com o codigo do instrutor: ");
											gets(cod);
								
											//Checagem de cadastro
											pos=0;
								
											while(stricmp(cod,Vcod_inst[pos])!=0 && pos<TL_inst)
											pos++;
								 
											if(pos<TL_inst)
												printf("Instrutor ja cadastrado!!");
										
											else
											{
												strcpy(Vcod_inst[TL_inst],cod);
											
												fflush(stdin);
												printf("Entre com o nome e sobrenome do Instrutor: ");
												gets(Vinstrutor[TL_inst]);
												
												TL_inst++;
											}
									
											printf("\n\nDeseja cadastrar mais instrutores? | S - Sim | N- Nao |: ");
											scanf(" %c",&continuar);
											printf("\n================================================");
										}
										while(continuar=='S' || continuar=='s');
											
										break;
									}
						
								case 2: // Cadastro de Alunos
									{
										do
										{
											fflush(stdin);
											printf("\n\nEntre com o CPF do aluno: ");
											gets(cpf);
								
											//Checagem de cadastro
											pos=0;
								
											while(stricmp(cpf,Vcpf[pos])!=0 && pos<TL_alunos)
												pos++;
									
											if(pos<TL_alunos)
												printf("\nO aluno ja esta cadastrado!!");
									
											else
											{
												strcpy(Vcpf[TL_alunos],cpf);	
											
												printf("\nEntre com o nome e sobrenome do aluno: ");
												gets(Vnome[TL_alunos]);
												printf("Entre com o numero de telefone do aluno: ");
												gets(Vtelefone[TL_alunos]);
												printf("Entre com a data de vencimento  do pagamento: ");
												scanf("%d",&Vdia_vencimento[TL_alunos]);
												printf("Entre com o valor do plano escolhido pelo aluno: ");
												scanf("%f",&Vvalor[TL_alunos]);	
												printf("\n================================================");
											
												TL_alunos++;
											}	
									
											fflush(stdin);
											printf("\n\n Deseja cadastrar mais alunos? | S - Sim | N- Nao |: ");
											scanf(" %c",&continuar);
											printf("\n================================================");
								
										}
										while(continuar=='S' || continuar=='s');
										
										break;
									}
								
								case 3: // Cadastro de Modalidades
									{
										do
										{
											fflush(stdin);
											printf("\n\nEntre com o numero da nova modalidade: ");
											gets(cod);
									
											pos=0;
									
											while(stricmp(cod,Vcod_mod[pos])!=0 && pos<TL_mod)
											pos++;
									
											if(pos<TL_mod)
												printf("Modalidade ja cadastrada!!");
										
											else
											{
												strcpy(Vcod_mod[TL_mod],cod);
										
												fflush(stdin);
												printf("Entre com o nome da modalidade: ");
												gets(Vmodalidade[TL_mod]);
												fflush(stdin);
												printf("Entre com o valor da aula: ");
												scanf("%f",&Vvalor_aula[TL_mod]);
										
												TL_mod++;
											}
									
											fflush(stdin);
											printf("\n\nDeseja adicionar mais modalidades? | S - Sim | N- Nao |: ");
											scanf(" %c",&continuar);
											printf("\n================================================");
											
										}
										while(continuar=='S' || continuar=='s');
							
										break;
									}
									
							}
				
					} while(op>0 && op<4);
				
					break;
				}
		
		
			case 2: // Case de Exclusão
				{
					do
					{
						
						fflush(stdin);
						printf("\n================================================");
						printf("\n\nCom qual opcao de exclusao voce deseja prosseguir?:");
					
						printf("\n1 - Instrutor");
						printf("\n2 - Aluno");
						printf("\n3 - Modalidade");
						printf("\n4 - Voltar");
				
						printf("\n\nQual a opcao desejada?: ");
						scanf("%d",&op);
						printf("\n================================================");
						
						switch(op)
						{
							case 1:	//exclusão de intrutores
								{
									if(TL_inst==0)
										printf("\n\n---| !!Nao ha instrutores cadastrados no Sistema!! |---");
										
									else
									{
										do
										{
										
											fflush(stdin);
											printf("\n\nEntre com o codigo do instrutor a ser excluido: ");
											fflush(stdin);	
											gets(cod);
											
											pos=0;
													
											while(pos<TL_inst && stricmp(cod,Vcod_inst[pos])!=0)
											pos++;
											
											if(pos<TL_inst)
											{												
	
												for(i=pos;i<TL_inst-1;i++)
												{
													strcpy(Vcod_inst[i],Vcod_inst[i+1]);
													strcpy(Vinstrutor[i],Vinstrutor[i+1]);
												}
											
												TL_inst--;
													
												printf("\n\n---| !!Instrutor excluido do Sistema!! |---");
											}
													
											else
												printf("\n\n---| !!Instrutor nao encontrado no Sistema!! |---");
														
											printf("\n================================================");
											printf("\n\nDeseja excluir mais cadastros? | S - Sim | N- Nao |: ");
											scanf(" %c",&continuar);
											printf("\n================================================");
													
											if(TL_inst==0)
											{
												printf("\n\n---| !!Nao ha instrutores cadastrados no Sistema!! |---");
												break;
											}
											
										} while(continuar=='s' || continuar=='S');
									}
									
									break;
								}	
								
						
							case 2: //exclusão de alunos
								{
									if(TL_alunos==0)
										printf("\n\n---| !!Nao ha Alunos cadastrados no Sistema!! |---");
										
									else
									{
										do
										{

											fflush(stdin);
											printf("\n\nEntre com o CPF do aluno a ser excluido: ");
											gets(cpf);
											fflush(stdin);
											printf("\nEntre com o dia de hoje: ");
											scanf("%d",&Data_hoje);
											fflush(stdin);
									
											//Busca o CPF no vetor de CPF
											pos=0;
									
											while(pos<TL_alunos && stricmp(cpf,Vcpf[pos])!=0 )
											pos++;
									
									
											if(pos<TL_alunos && Data_hoje>Vdia_vencimento[pos])
											{
												for(i=pos;i<TL_alunos-1;i++)
												{
													strcpy(Vcpf[i],Vcpf[i+1]);
													strcpy(Vnome[i],Vnome[i+1]);
													strcpy(Vtelefone[i],Vtelefone[i+1]);
													strcpy(Vdia_vencimento[i],Vdia_vencimento[i+1]);
													Vvalor[i]=Vvalor[i+1];
												}
									
												TL_alunos--;
								
												printf("\n\n---| !!Aluno excluido do Sistema!! |---");
											}
									
											else
												printf("\n\n---| !!Aluno ainda esta no prazo, nao pode ser excluido!! |---");
										
											printf("\n================================================");
											printf("\n\nDeseja excluir mais cadastros? | S - Sim | N- Nao |: ");
											scanf(" %c",&continuar);
											printf("\n================================================");
			
											if(TL_alunos==0)
											{
												printf("\n\n---| !!Nao ha Alunos cadastrados no Sistema!! |---");
												break;
											}
											
											
										}while(continuar=='s' || continuar=='S');
									}
									
									break;
								}
								
					
							case 3: //exclusão de modalidades
								{
									if(TL_mod==0)
										printf("\n\n---| !!Nao ha Modalidades cadastradas no Sistema!! |---");
									
									else
									{
										do
										{

											fflush(stdin);
											printf("\n\nEntre com o codigo da modalidade que sera excluida: ");
											gets(cod);
												
											pos=0;
												
											fflush(stdin);
												
											while(pos<TL_mod && stricmp(cod,Vcod_mod[pos])!=0)
											{
												pos++;
											}
												
											if(pos<TL_mod)
											{
												for(i=pos;i<TL_mod-1;i++)
												{
													strcpy(Vcod_mod[i],Vcod_mod[i+1]);
													strcpy(Vmodalidade[i],Vmodalidade[i+1]);
													Vvalor_aula[i]=Vvalor_aula[i+1];
												}
												
												TL_mod--;
												
												printf("\n\n---| !!Modalidade excluida do Sistema!! |---");
											}
												
											else
												printf("\n\n---| !!Modalidade nao encontrada no Sistema!! |---");
										
											printf("\n================================================");
											printf("\n\nDeseja excluir mais cadastros? | S - Sim | N- Nao |: ");
											scanf(" %c",&continuar);
											printf("\n================================================");
												
											if(TL_mod==0)
											{
												printf("\n\n---| !!Nao ha Modalidades cadastradas no Sistema!! |---");
												break;
											}
											
											
										} while(continuar=='s' || continuar=='S');
									
									}
									
									break;	
								}
						}
						
							
					} while(op>0 && op<4);
					
					break;
				}
		
		
			case 3: // Case de Lançamento
				{
					do
					{
						printf("\n================================================");
						fflush(stdin);
						printf("\n\nEntre com seu codigo de instrutor: ");
						gets(cod);
						
						//consulta se o instrutor está cadastrado
						pos=0;
						
						while(pos<TL_inst && stricmp(cod,Vcod_inst[pos])!=0)
						pos++;
						
						if(pos>=TL_inst)
							printf("---| !!Instrutor não cadastrado no sistema!! |---");
							
						else
						{
							
								
							fflush(stdin);
							printf("Entre com o CPF do aluno que vai fazer a avaliacao: ");
							gets(cpf);
							
							//consulta se o aluno está mesmo cadastrado
							pos=0;
								
							while(stricmp(cpf,Vcpf[pos])!=0 && pos<TL_alunos)
							pos++;
								
							if(pos>=TL_alunos)
								printf("---| !!Aluno nao cadastrado no sistema!! |---");
								
							else
							{
								fflush(stdin);
								printf("Entre com a data que sera realizada a avaliacao (DD/MM/AA) : ");
								scanf("%s",&Vdia_avaliacao[pos]);
								
								strcpy(Vcpf_Aval[TL_Aval], cpf);
                				strcpy(Vcod_inst_Aval[TL_Aval], cod);
                				
                				TL_Aval++;
                				
                				printf("\n\n---| !!Avaliacao cadastrada no sistema!! |---");
							}
								
							printf("\n\n Deseja cadastrar mais avaliacoes? | S - Sim | N- Nao |: ");
							scanf(" %c",&continuar);
							printf("\n================================================");
								
						}
						
					}while(continuar=='S' || continuar =='s');

					break;
				}
		
		
			case 4: //Case de Relatório
				{
					do
				    {
				        printf("\n================================================");
				        printf("\n\n         MENU DE RELATORIOS                  ");
				        printf("\n================================================");
				        printf("\n1 - Relatorio Geral");
				        printf("\n2 - Relatorio de Alunos");
				        printf("\n3 - Relatorio de Instrutores");
				        printf("\n4 - Relatorio de Modalidades");
				        printf("\n5 - Relatorio de Avaliacoes Fisicas");
				        printf("\n6 - Voltar");
				        printf("\n\nQual a opcao desejada?: ");
				        scanf("%d", &op);
				        printf("\n================================================");
				
				        switch(op)
				        {
							
								case 1: //Case do relatorio Geral
									{
										printf("\n\n================================================");
					        			printf("\n\n    	Relatorio Geral do Sistema               ");
					        			printf("\n================================================");
					        			
					        			printf("\nTotal de instrutores cadastrados: %d", TL_inst);
					        			printf("\nTotal de alunos cadastrados: %d", TL_alunos);
					        			printf("\nTotal de modalidades cadastradas: %d", TL_mod);
					        			printf("\nTotal de avaliacoes cadastradas: %d", TL_Aval);
										break;
									}
									
																		
								case 2: //Case do relatorio dos Alunos
									{
										receita_total=0;
										
										printf("\n\n========================================");
	                					printf("\n          RELATORIO DE ALUNOS           ");
	                					printf("\n========================================\n");
	                					
	                					if(TL_alunos==0)
	                					{
	                						printf("\n---| !!Nenhum aluno cadastrado!! |---");
	                						printf("\n");
	                					}
	                					
	                					else
	                					{
	                						printf("\n\n%-5s| %-15s| %-25s| %-15s| %-12s| %-10s|\n","#", "CPF", "NOME", "TELEFONE", "VENCIMENTO", "VALOR");
	                    					printf("---------------------------------------------------------------------------------------------------------\n");
	                    					
	                    					for(i=0;i<TL_alunos;i++)
	                    					{
	                    						printf("%-5d| %-15s| %-25s| %-15s| %-12d| R$%-8.2f|\n",i+1,Vcpf[i],Vnome[i],Vtelefone[i],Vdia_vencimento[i],Vvalor[i]);
	                    						
	                    						receita_total=receita_total+Vvalor[i];
	                    					}
	                    					
	                    					printf("---------------------------------------------------------------------------------------------------------\n");	
	                    					printf("\nTotal de Alunos: %d",TL_alunos);
	                    					printf("\nReceita total esperada: R$ %.2f",receita_total);
	                					}
										break;
									}
										
										
								case 3: //Case do relatorio de instrutores
									{
										printf("\n\n========================================");
                						printf("\n       RELATORIO DE INSTRUTORES         ");
                						printf("\n========================================\n");
                						
                						if(TL_inst==0)
                						{
                							printf("---| !!Nenhum instrutor esta cadastrado!! |---");
                						}
										
										else
										{
											printf("%-10s| %-30s|\n", "CODIGO", "NOME");
                    						printf("-------------------------------------------\n");
                    						
                    						for(i=0;i<TL_inst;i++)
                    						{
                    							printf("%-10s| %-30s|\n", Vcod_inst[i], Vinstrutor[i]);
                    							printf("-------------------------------------------\n");
                    						}
                    						
                    						printf("\n\nO total de instrutores cadastrados e igual a: %d",TL_inst);
										}
										
										break;
									}
								
								
								case 4: //Case do relatorio de Modalidades
									{
										printf("\n\n========================================");
                						printf("\n       RELATORIO DE MODALIDADES         ");
                						printf("\n========================================\n");
                						
                						if(TL_mod==0)
                							printf("---| !! Nenhuma modalidade esta cadastrada!! |---");
                							
                						else
                						{
                							printf("%-10s| %-25s| %-10s|\n", "CODIGO", "MODALIDADE", "VALOR AULA");
                    						printf("-------------------------------------------\n");
                    						
                    						for(i=0;i<TL_mod;i++)
                    						{
                    							printf("%-10s| %-25s| R$%-8.2f|\n",Vcod_mod[i], Vmodalidade[i], Vvalor_aula[i]);
                    						}
                    						
                    						printf("-------------------------------------------\n");
                    						printf("Total de modalidades: %d\n", TL_mod);
                    						
                						}
                						
										break;
									}
									
										
								case 5: //Case do relatorio de Avaliações Físicas
									{
										printf("\n\n========================================");
               							printf("\n     RELATORIO DE AVALIACOES FISICAS    ");
                						printf("\n========================================\n");
                						
                						if(TL_Aval==0)
                							printf("---| !!Nenhuma avaliaçao está cadastrada!! |---");
                							
                						else
                						{
                							printf("%-15s| %-25s| %-15s| %-12s|\n","CPF ALUNO", "NOME ALUNO", "COD INSTRUTOR", "DATA AVAL.");
                    						printf("---------------------------------------------------------------\n");
                    						
                    						for(i=0;i<TL_Aval;i++)
                    						{
                    							 // Busca o nome do aluno pelo CPF
                        						pos = 0;
                        						
                        						while(pos < TL_alunos && stricmp(Vcpf_Aval[i], Vcpf[pos]) != 0)
                            					pos++;

                        						printf("%-15s| %-25s| %-15s| %-12s|\n",Vcpf_Aval[i],(pos < TL_alunos) ? Vnome[pos] : "Nao encontrado",Vcod_inst_Aval[i],Vdia_avaliacao[i]);
                    						}
                    						
                    						printf("---------------------------------------------------------------\n");
                    						printf("Total de avaliacoes marcadas: %d\n", TL_Aval);
                    						
                						}
										
										printf("========================================\n");
										break;
									} 
									
						}	

					}while(op>0 && op<6);
					
					break;
				}
				
		}
		
		
	}while(op!=5);	
}
