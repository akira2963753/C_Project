#include <stdio.h>
#include <windows.h>
char a[3][3];//OOXX�ѽL�G���}�C 
char b[]={'O','X'};//�P�_��Ĺ�ɨϥ� 
char b2[]={'o','x'};
int mode,k=0,O=0,X=0,X_quantity,x_quantity,O_quantity,o_quantity;//O X�Ҧ�1�p�� k���� 
int x_memory[4][2]={{-1,-1},{-1,-1},{-1,-1},{-1,-1}};//�S��Ҧ��ɥΨӰO�Х��ᶶ�ǡA�]-1���ŭ� 
int o_memory[4][2]={{-1,-1},{-1,-1},{-1,-1},{-1,-1}};//�S��Ҧ��ɥΨӰO�Х��ᶶ�ǡA�]-1���ŭ�
void show()//��ܴѽL 
{
	printf("%c|%c|%c\n",a[0][0],a[0][1],a[0][2]);
	printf("-----\n");
	printf("%c|%c|%c\n",a[1][0],a[1][1],a[1][2]);
	printf("-----\n");
	printf("%c|%c|%c\n\n",a[2][0],a[2][1],a[2][2]);
}
void push_x(void)//�N�᭱��m���e���� 
{
	int i,j;
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
			if(x_memory[i][0]==-1&&x_memory[i+1][0]!=-1)//�p�G�e�@��O�ŭȡA���� 
			{
				x_memory[i][0]=x_memory[i+1][0]; 
				x_memory[i][1]=x_memory[i+1][1];
				x_memory[i+1][0]=-1;
				x_memory[i+1][1]=-1;
			}	
		}	
	}
}
void push_o(void)//�N�᭱��m���e���� 
{
	int i,j;
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
			if(o_memory[i][0]==-1&&o_memory[i+1][0]!=-1)//�p�G�e�@��O�ŭȡA���� 
			{
				o_memory[i][0]=o_memory[i+1][0];
				o_memory[i][1]=o_memory[i+1][1];
				o_memory[i+1][0]=-1;
				o_memory[i+1][1]=-1;
			}	
		}	
	}
} 
void stepx(void)//��JX 
{
	int x,y,i,j;//�]XY���y���ܼ� 
	while(1)//���쥿�T�e���_���� 
	{
		printf("Enter the row and column for X:");
		getchar();
		scanf("%c%c",&x,&y);
		if (a[x-48][y-48]!='\0')//�P�_�O�_�U�b�Ů�W 
		{
			printf("error\n");
		}
		else if(x>50||x<48||y>50||y<48)//�P�_�O�_�W�X�d�� 
		{
			printf("error\n");
		}
		else//�N�y�г]��X�A�ø��X 
		{
			x=x-48;
			y=y-48;
			a[x][y]='X';
			j=0;
			while(1)//�S��Ҧ��ϥ� 
			{
				if(x_memory[j][0]==-1&&x_memory[j][1]==-1)//�p�G��j�欰�ŭȡA��J��j��ø��X�A�_�hj++�~����� 
				{
					x_memory[j][0]=x;
					x_memory[j][1]=y;
					break;
				}
				j++;
			}
			break;
		}
	}
}
void stepO(void)//��JO
{
	int x,y,i,j;
	while(1)//���쥿�T�e���_���� 
	{
		printf("Enter the row and column for O:");
		getchar();
		scanf("%c%c",&x,&y);
		if (a[x-48][y-48]!='\0')//�P�_�O�_�U�b�Ů�W 
		{
			printf("error\n");
		}
		else if(x>50||x<48||y>50||y<48)//�P�_�O�_�W�X�d�� 
		{
			printf("error\n");
		}
		else//�N�y�г]��O�A�ø��X 
		{
			x=x-48;
			y=y-48;
			a[x][y]='O';
			j=0;
			while(1)//�S��Ҧ��ϥ� 
			{
				if(o_memory[j][0]==-1&&o_memory[j][1]==-1)//�p�G��j�欰�ŭȡA��J��j��ø��X�A�_�hj++�~����� 
				{
					o_memory[j][0]=x;
					o_memory[j][1]=y;
					break;
				}
				j++;
			}
			break;
		}
	}
}

int win(void)//�P�_�s�u 
{
	int i,OX=0,re,j;//i����p�Ʀ@�T��//OX�P�_OX�@�⦸//�^�ǭ� 
	for(OX=0;OX<2;OX++)
	{
		for(i=0;i<3;i++)
		{
			if(a[i][0]==a[i][1]&&a[i][0]==a[i][2]&&a[i][0]==b[OX])//�P�_��u 
			{
				printf("%c win\n\n",b[OX]);
				re=1;
				a[i][0]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
				a[i][1]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
				a[i][2]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
				if(b[OX]=='O')//�S��Ҧ��ɡA�N�s�u��O�вM�� 
				{
					for(j=0;j<4;j++)
					{
						if(o_memory[j][0]==i)//�p�G�O�лP�s�u�b�P�@��u�W�A�R������O�� 
						{
							o_memory[j][0]=-1;
							o_memory[j][1]=-1;
						}
					}
					O++;
				}
				else if(b[OX]=='X')//�S��Ҧ��ɡA�N�s�u��O�вM�� 
				{
					for(j=0;j<4;j++)
					{
						if(x_memory[j][0]==i)//�p�G�O�лP�s�u�b�P�@��u�W�A�R������O�� 
						{
							x_memory[j][0]=-1;
							x_memory[j][1]=-1;
						}
					}
					X++;
				}
			}
		}
		for(i=0;i<3;i++)
		{
			if(a[0][i]==a[1][i]&&a[0][i]==a[2][i]&&a[0][i]==b[OX])//�P�_���u 
			{
				printf("%c win\n\n",b[OX]);
				re=1;
				a[0][i]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
				a[1][i]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
				a[2][i]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
				if(b[OX]=='O')//�S��Ҧ��ɡA�N�s�u��O�вM�� 
				{
					for(j=0;j<4;j++)
					{
						if(o_memory[j][1]==i)//�p�G�O�лP�s�u�b�P�@���u�W�A�R������O��
						{
							o_memory[j][0]=-1;
							o_memory[j][1]=-1;
						}
					}
					O++;
				}
				else if(b[OX]=='X')//�S��Ҧ��ɡA�N�s�u��O�вM��
				{
					for(j=0;j<4;j++)
					{
						if(x_memory[j][1]==i)//�p�G�O�лP�s�u�b�P�@���u�W�A�R������O��
						{
							x_memory[j][0]=-1;
							x_memory[j][1]=-1;
						}
					}
					X++;
				}
			}
		}
		if(a[0][0]==a[1][1]&&a[0][0]==a[2][2]&&a[1][1]==b[OX] )//�P�_�׽u 
		{
			printf("%c win\n\n",b[OX]);
			re=1;
			a[0][0]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
			a[1][1]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
			a[2][2]='\0';//�S��Ҧ��ɡA�N�s�u��M�� 
			if(b[OX]=='O')//�S��Ҧ��ɡA�N�s�u��O�вM��
			{
				for(j=0;j<4;j++)
				{
					if(o_memory[j][0]==o_memory[j][1])//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						o_memory[j][0]=-1;
						o_memory[j][1]=-1;
					}
				}
				O++;
			}
			else if(b[OX]=='X')//�S��Ҧ��ɡA�N�s�u��O�вM��
			{
				for(j=0;j<4;j++)
				{
					if(x_memory[j][0]==x_memory[j][1])//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						x_memory[j][0]=-1;
						x_memory[j][1]=-1;
					}
				}
				X++;
			}
		}
		if(a[0][2]==a[1][1]&&a[0][2]==a[2][0]&&a[1][1]==b[OX])
		{
			printf("%c win\n\n",b[OX]);
			re=1;
			a[0][2]='\0';//�S��Ҧ��ɡA�N�s�u��M��
			a[1][1]='\0';//�S��Ҧ��ɡA�N�s�u��M��
			a[2][0]='\0';//�S��Ҧ��ɡA�N�s�u��M��
			if(b[OX]=='O')//�S��Ҧ��ɡA�N�s�u��O�вM��
			{
				for(j=0;j<4;j++)
				{
					if(o_memory[j][0]==0&&o_memory[j][1]==2)//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						o_memory[j][0]=-1;
						o_memory[j][1]=-1;
					}
					if(o_memory[j][0]==1&&o_memory[j][1]==1)//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						o_memory[j][0]=-1;
						o_memory[j][1]=-1;
					}
					if(o_memory[j][0]==2&&o_memory[j][1]==0)//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						o_memory[j][0]=-1;
						o_memory[j][1]=-1;
					}
				}
				O++;
			}
			else if(b[OX]=='X')//�S��Ҧ��ɡA�N�s�u��O�вM��
			{
				for(j=0;j<4;j++)
				{
					if(x_memory[j][0]==0&&x_memory[j][1]==2)//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						x_memory[j][0]=-1;
						x_memory[j][1]=-1;
					}
					if(x_memory[j][0]==1&&x_memory[j][1]==1)//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						x_memory[j][0]=-1;
						x_memory[j][1]=-1;
					}
					if(x_memory[j][0]==2&&x_memory[j][1]==0)//�p�G�O�лP�s�u�b�P�@�׽u�W�A�R������O��
					{
						x_memory[j][0]=-1;
						x_memory[j][1]=-1;
					}
				}
				X++;
			}
		}
	}
	if(re==1)//���s�u�� 
	{
		if(mode==1)//�S��Ҧ��� 
		{
			show();//��ܳs�u���᪺���G 
			push_x();//�No���e�� 
			push_o();//�Nx���e��
			printf("O:X\n%d:%d\n\n",O,X);//��ܥثe��� 
		}
		return(1);
	}
	else//��S���s�u�� 
	{
		if(mode==1)//�S��Ҧ��� 
		{
			if(x_memory[3][0]!=-1&&x_memory[3][1]!=-1)//��x�U���4�B 
			{
				a[x_memory[0][0]][x_memory[0][1]]='\0';//��1�B��m�M�� 
				x_memory[0][0]=-1;//��1�B��m�O�вM�� 
				x_memory[0][1]=-1;//��1�B��m�O�вM�� 
				show();//��ܧR�����᪺���G 
				push_x();//�Nx���e��
			}
			if(o_memory[3][0]!=-1&&o_memory[3][1]!=-1)//��Uo���4�B
			{
				a[o_memory[0][0]][o_memory[0][1]]='\0';//��1�B��m�M�� 
				o_memory[0][0]=-1;//��1�B��m�O�вM��
				o_memory[0][1]=-1;//��1�B��m�O�вM��
				show();//��ܧR�����᪺���G
				push_o();//�Nx���e��
			}
		}
		return(0);
	}
}






void stepx2(void)//��JX 
{
	int i,j;//�]XY���y���ܼ�
	char x,y;
	char Xx;
	while(1)
	{
		printf("Chose X or x(X:%d x:%d):",X_quantity,x_quantity);
		getchar();
		scanf("%c",&Xx);
		if(Xx=='X')
		{
			if(X_quantity==0)
			{
				printf("X is not enough\n");
			}
			else
			{
				X_quantity--;
				break;
			}
		}
		else if(Xx=='x')
		{
			if(x_quantity==0)
			{
				printf("x is not enough\n");
			}
			else
			{
				x_quantity--;
				break;
			}
		}
		else if(Xx!=88||Xx!=120){
			printf("error\n");
		}
		else
		{
			printf("error\n");
		}
	}
	while(1)//���쥿�T�e���_���� 
	{
		printf("Enter the row and column for X:");
		getchar();
		scanf("%c%c",&x,&y);
		if (a[x-48][y]!='\0'&&Xx=='x')//�P�_�O�_�U�b�Ů�W 
		{
			printf("error\n");
		}
		else if(a[x-48][y-48]=='O'&&Xx=='X')
		{
			printf("error\n");
		}
		else if(a[x-48][y-48]=='x'&&Xx=='X')
		{
			printf("error\n");
		}
		else if(x>50||x<48||y>50||y<48)//�P�_�O�_�W�X�d�� 
		{
			printf("error\n");
		}
		else//�N�y�г]��X�A�ø��X 
		{
			x=x-48;
			y=y-48;
			if(Xx=='x')
			{
				a[x][y]='x';
			}
			else if(Xx=='X')
			{
				if(a[x][y]=='o')
				{
					k--;
				}
				a[x][y]='X';
			}
			break;
		}
	}
}
void stepO2(void)//��J
{
	int i,j;//�]XY���y���ܼ�
	char x,y; 
	char Oo;
	while(1)
	{ 
		printf("Chose O or o(O:%d o%d):",O_quantity,o_quantity);
		getchar();
		scanf("%c",&Oo);
		if(Oo=='O')
		{
			if(O_quantity==0)
			{
				printf("O is not enough\n");
			}
			else
			{
				O_quantity--;
				break;
			}
		}
		else if(Oo=='o')
		{
			if(o_quantity==0)
			{
				printf("o is not enough\n");
			}
			else
			{
				o_quantity--;
				break;
			}
		}
		else if(Oo!=79||Oo!=111){
			printf("error\n");
		}
		else
		{
			printf("error\n");
		}
	}
	while(1)//���쥿�T�e���_���� 
	{
		printf("Enter the row and column for O:");
		getchar();
		scanf("%c%c",&x,&y);
		if (a[x-48][y-48]!='\0'&&Oo=='o')//�P�_�O�_�U�b�Ů�W 
		{
			printf("error\n");
		}
		else if(x>50||x<48||y>50||y<48)//�P�_�O�_�W�X�d�� 
		{
			printf("error\n");
		}
		else if(a[x-48][y-48]=='X'&&Oo=='O')
		{
			printf("error\n");
		}
		else if(a[x-48][y-48]=='o'&&Oo=='O')
		{
			printf("error\n");
		}
		else//�N�y�г]��O�A�ø��X 
		{
			x=x-48;
			y=y-48;
			if(Oo=='o')
			{
				a[x][y]='o';
			}
			else if(Oo=='O')
			{
				if(a[x][y]=='x')
				{
					k--;
				}
				a[x][y]='O';
			}
			break;
		}
	}
}





int win2(void)//�P�_�s�u 
{
	int i,OX=0,re,j;//i����p�Ʀ@�T��//OX�P�_OX�@�⦸//�^�ǭ� 
	for(OX=0;OX<2;OX++)
	{
		for(i=0;i<3;i++)
		{
			if((a[i][0]==b[OX]||a[i][0]==b2[OX]) && (a[i][1]==b[OX]||a[i][1]==b2[OX]) && (a[i][2]==b[OX]||a[i][2]==b2[OX]))//�P�_��u 
			{
				printf("%c win\n\n",b[OX]);
				re=1;
			}
		}
		for(i=0;i<3;i++)
		{
			if((a[0][i]==b[OX]||a[0][i]==b2[OX]) && (a[1][i]==b[OX]||a[1][i]==b2[OX]) && (a[2][i]==b[OX]||a[2][i]==b2[OX]))//�P�_���u 
			{
				printf("%c win\n\n",b[OX]);
				re=1;
			}
		}
		if((a[0][0]==b[OX]||a[0][0]==b2[OX]) && (a[1][1]==b[OX]||a[1][1]==b2[OX]) && (a[2][2]==b[OX]||a[2][2]==b2[OX]) )//�P�_�׽u 
		{
			printf("%c win\n\n",b[OX]);
			re=1;
		}
		if((a[0][2]==b[OX]||a[0][2]==b2[OX]) && (a[2][0]==b[OX]||a[2][0]==b2[OX]) && (a[1][1]==b[OX]||a[1][1]==b2[OX]))
		{
			printf("%c win\n\n",b[OX]);
			re=1;
		}
	}
	if(re==1)//���s�u�� 
	{
		return(1);
	}
	else//��S���s�u�� 
	{
		return(0);
	}
}

void clean(void)
{
	int i,j;
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]='\0';
		}
	}
	for (i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			x_memory[i][j]=-1;
			o_memory[i][j]=-1;
		}
	}
	k=0;
	O=0,X=0;//�o���k0
}





int main(void)
{
	while(1)
	{
		clean();
		printf("%45s","<Weclome to OOXX>\n");
		puts("==========================================================================");
		printf("%52s","<Please Choose Mods You Want>\n");
		puts("|------------------------------------------------------------------------|");
		puts("|                                                                        |");
		puts("|                            0:Normal                                    |");
		puts("|                            1:Special-1                                 |");
		puts("|                            2:Special-2                                 |");
		puts("|                           -1:Exit                                      |");
		puts("|                                                                        |");
		puts("|------------------------------------------------------------------------|");
		scanf("%d",&mode);
		if(mode<3&&mode>-1){
			printf("Loding Game");
			printf("...."); 
			Sleep(1000);
			printf(".....");
			Sleep(1000);
			printf("........");
			Sleep(1000);
			printf("......\n\n");
			printf("�ѽL�t��\n\n");
			printf("00|01|02\n");
			printf("--------\n");
			printf("10|11|12\n");
			printf("--------\n");
			printf("20|21|22\n\n");
			puts("==========================================================================\n");				
		}
		if (mode==-1)
		{
			break;
		}
		if(mode==0)
		{
			show();
			while(1)
			{
				int end=0;//�]end�Ѽ� 
				stepx();//��JX
				k++; 
				show();//��ܴѽL 
				end=win();//�P�_�s�u�ñ���end�� 
				if (end==1)//��end=1���� 
				{
					break;
				}
				else if(k==9)
				{
					printf("This game ended in a tie.\n");
					break;
				}
				stepO();//��JO 
				k++;
				show();//��ܴѽL 
				end=win();//�P�_�s�u�ñ���end�� 
				if (end==1)//��end=1���� 
				{
					break;
				}
				else if(k==9)
				{
					printf("This game ended in a tie.\n");
					break;
				}
			}
		}
		else if(mode==1)
		{
			show(); 
			while(1)
			{
				int end=0;//�]end�Ѽ� 
				stepx();//��JX
				show();//��ܴѽL 
				end=win();//�P�_�s�u�ñ���end��(end�ȯS��Ҧ����|�Ψ�) 
				if (O==3)//��o�o3�� 
				{
					printf("o win the special mode\n");//oĹ�o�S��Ҧ��ø��X 
					break;
				}
				if (X==3)//��x�o3�� 
				{
					printf("x win the special mode\n");//xĹ�o�S��Ҧ��ø��X 
					break;
				}
				stepO();//��JO 
				show();//��ܴѽL 
				end=win();//�P�_�s�u�ñ���end��(end�ȯS��Ҧ����|�Ψ�)
				if (O==3)//��o�o3�� 
				{
					printf("o win the special mode\n");//oĹ�o�S��Ҧ��ø��X 
					break;
				}
				if (X==3)//��x�o3�� 
				{
					printf("x win the special mode\n");//xĹ�o�S��Ҧ��ø��X 
					break;
				}
			}
		}
		else if(mode==2)
		{
			O_quantity=2;
			X_quantity=2;
			o_quantity=4;
			x_quantity=4;
			show();
			int end=0;
			k=0;
			while(1)
			{
				stepx2();//��JX
				k++;
				show();//��ܴѽL 
				end=win2();
				if (end==1)//��end=1���� 
				{
					break;
				}
				else if(k==9&&X_quantity==0)
				{
					printf("This game ended in a tie.\n");
					break;
				}
				stepO2();//��JO
				k++;
				show();//��ܴѽL 
				end=win2();
				if (end==1)//��end=1���� 
				{
					break;
				}
				else if(k==9&&O_quantity==0)
				{
					printf("This game ended in a tie.\n");
					break;
				}
			}
		}
	}
	return 0;
}
	



