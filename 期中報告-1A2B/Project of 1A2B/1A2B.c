#include<stdio.h>
#include<stdlib.h>	//�ޤJrand�ܼƨ禡 
#include<time.h>	//�ޤJ�ɶ��ܼƺؤl
#include<windows.h>	//�ޤJSleep()����禡

int mods=0,hint=0,hint_times=1,re=0;

int clean()//�M���w�İϪ��r�� 
{
    while(getchar()!='\n');
}
int func(){
	int times=1; 
	srand((time(NULL)));//�ޤJ�ɶ��ܼƺؤl 
	int a=rand()%10,b=rand()%10,c=rand()%10,d=rand()%10;//���ܼ� 
	while(a==b){
		b=rand()%10;
	}
	while(a==c||b==c){
		c=rand()%10;	
	}
	while(a==d||b==d||c==d){
		d=rand()%10;	
	}
	//printf("���խ��ϥΡA���νе��ѱ� Ans:%d%d%d%d\n",a,b,c,d);
	a+=48,b+=48,c+=48,d+=48;
	int A=0,B=0,correct=0;
	char g1,g2,g3,g4;
	int reset=1;
	while(reset==1){
		clean(); 
		puts("Please your number of guess:");
		scanf("%c%c%c%c",&g1,&g2,&g3,&g4);
		if(g1<48||g1>57||g2<48||g2>57||g3<48||g3>57||g4<48||g4>57){//�L�o�Ʀr�H�~ 
			puts("Error<Please enter numbers.>\a\n");
			puts("----------------------------------------------------------------------------");
			reset=1;
		}
		else if(g1==g2||g1==g3||g1==g4||g2==g3||g2==g4||g3==g4){//���i�q���ƼƦr 
			puts("Error<Don't enter same number>\a\n");
			puts("----------------------------------------------------------------------------");
			reset=1;
		}
		else{
			reset=0;
		}
		while(correct==0&&reset==0){//�P�_���XA�XB 
			if(g1==a){
				A++;
			}
			else if(g1==b||g1==c||g1==d){
				B++;
			}
			if(g2==b){
				A++;
			}
			else if(g2==a||g2==c||g2==d){
				B++;
			}
			if(g3==c){
				A++;
			}
			else if(g3==a||g3==b||g3==d){
				B++;
			}
			if(g4==d){
				A++;
			}
			else if(g4==a||g4==b||g4==c){
				B++;
			}
			puts("");
			printf("%dA%dB\n",A,B);//�L�X�XA�XB 
			if(mods==2&&times==5){//�Y��Mode2�B�q�����ƶW�L�����Y�N��C������ 
				printf("Game Over!!!\a\n");
				printf("The answer is %d%d%d%d\n",a-48,b-48,c-48,d-48);
				puts("----------------------------------------------------------------------------");
				break;
			}
			else if(mods==2){//�Y��Mode2�ݧi�D���a�ѤU�X�����| 
					printf("You have %d chance.\n",5-times);
					puts("----------------------------------------------------------------------------");
			}
			else;
			if(A!=4){//�YA������4 =>�S�q�� 
				if(mods==1){//�Y��Mode1�h�������ܾ��| 
					puts("Enter 1:<Get hint>\nEnter 0:<Continue>");
					puts("****************************************************************************");
					scanf("%d",&hint);
					puts("----------------------------------------------------------------------------");
					if(hint==1&&hint_times==1){//�Ĥ@������ 
						printf("Frist number is %d\n",a-48);
						hint_times++;
					}
					else if(hint==1&&hint_times==2){//�ĤG������ 
						printf("Second number is %d\n",b-48);
						hint_times++;
					}
					else if(hint==1&&hint_times==3){//�ĤT������ 
						printf("Third number is %d\n",c-48);
						hint_times++;
					}
					else if(hint==1&&hint_times==4){//�ĥ|������ 
						printf("Fourth number is %d\n",d-48);
						hint_times++;
					}
					else;
					puts("----------------------------------------------------------------------------");
				}
					A=0;
					B=0;
					times++;//����+1
					reset=1;
			}
			else{
				correct=1;
				hint_times=0;
				printf("You WIN!!!!!!\n");
				printf("You use %d times\n",times);//����B�L�X�q�F�X�� 
				puts("----------------------------------------------------------------------------");
			}
				
		}
	
	}
}

int hard(void){
	int HA=0,HB=0;
	int end=0;
	int Htimes=1;
	int reset=1;
	srand((time(NULL)));//�ޤJ�ɶ��ܼƺؤl 
	int A=rand()%26+1,B=rand()%26+1,C=rand()%26+1,D=rand()%26+1;//���ܼ� 
	while(A==B) B=rand()%26+1;
	while(A==C||B==C) C=rand()%26+1;
	while(A==D||B==D||C==D) D=rand()%26+1; 
	A=A+64;//+64 EX ��1��A ��2��B 
	B=B+64;
	C=C+64;
	D=D+64;
	char G1,G2,G3,G4;
	//printf("���խ��ϥΡA���νе��ѱ� Ans:%c%c%c%c\n",A,B,C,D);
	while(reset==1){
		clean();
		puts("Please your alphabet of guess:");
		scanf("%c%c%c%c",&G1,&G2,&G3,&G4);//�ϥΪ̿�J
		if(G1<64||G1>90||G2<64||G2>90||G3<64||G3>90||G4<64||G4>90){//�L�oA~Z�H�~ 
			puts("Error<Please enter A~Z>\a\n");
			puts("----------------------------------------------------------------------------");
			reset=1;
		}
		else if(G1==G2||G1==G3||G1==G4||G2==G3||G2==G4||G3==G4){//���i��J���ƪ� 
			puts("Error<Don't enter same alphabet>\a\n");
			puts("----------------------------------------------------------------------------");
			reset=1;
		}
		else{
			reset=0;
		}
		while(end==0&&reset==0){//�P�_�XA�XB 
			if(G1==A){ 
				HA++;
			}
			else if(G1==B||G1==C||G1==D){
				HB++;
			}
			if(G2==B){
				HA++;
			}
			else if(G2==A||G2==C||G2==D){
				HB++;
			}
			if(G3==C){
				HA++;
			}
			else if(G3==A||G3==B||G3==D){
				HB++;
				}
			if(G4==D){
				HA++;
			}
			else if(G4==A||G4==B||G4==C){
				HB++;
			}
			puts("");
			printf("%dA%dB\n",HA,HB);
			puts("----------------------------------------------------------------------------");
			if(Htimes==15){//�p�G�W�L15�� �N��C������ 
			printf("Game Over\a\n");
			printf("The answer is %c%c%c%c\n",A,B,C,D);
			puts("----------------------------------------------------------------------------");
			end=1;
			}
			else if(HA!=4){
				G1=0,G2=0,G3=0,G4=0;
				HA=0;
				HB=0;
				printf("You have %d chance.\n",15-Htimes);
				
				Htimes++;
				puts("----------------------------------------------------------------------------");
				reset=1;
			}
			else{
				printf("You WIN!!!\n");
				printf("You use %d times\n",Htimes);
				puts("----------------------------------------------------------------------------");
				end=1;
			}
	
		}
	}
}




int main(){
	int r=0,final=0;
	while(mods==0){
		final=0;
		printf("%50s","<Weclome to My 1A2B World>\n");
		puts("============================================================================");
		printf("%52s","<Please Choose Mods You Want>\n");
		puts("|--------------------------------------------------------------------------|");
		puts("|                                                                          |");
		puts("|                 1:Easy(No restrict times to guess number)                |");
		puts("|                 2:Normal(Restrict 5 times to guess number)               |");
		puts("|                 3:Hard(Restrict 15 times to guess alphabet)              |");
		puts("|                                                                          |");
		puts("|--------------------------------------------------------------------------|");
		printf("%43s","<Your choice>\n");
		puts("============================================================================");
		scanf("%d",&mods);
		printf("%30s","Loding Game");
		printf("...."); 
		Sleep(1000);
		printf(".....");
		Sleep(1000);
		printf("........");
		Sleep(1000);
		printf("......\n");
		puts("");
		if(mods==1){
			//easy mods
			puts("                            <Esay Mode>                                  ");
			puts("============================================================================");
			puts("                            <Game Start>                                 ");
			puts("============================================================================");
			func();
		}
		else if(mods==2){
			puts("                            <Normal Mode>                                ");
			puts("============================================================================");
			puts("                            <Game Start>                                 ");
			puts("============================================================================");
			func();
			//normal mods
		}
		else if(mods==3){
			//hard mods
			puts("                            <Hard Mode>                                  ");
			puts("============================================================================");
			puts("                            <Game Start>                                 ");
			puts("============================================================================");
			hard();
		}
		else{
			clean();
			puts("�п�J���T�Ҧ�");
			puts("|--------------------------------------------------------------------------|");
			}
		if(mods==1||mods==2||mods==3){
			while(final==0){
				puts("If you want to try again:Enter 1");
				puts("If you don't:Enter 0");
				scanf("%d",&re);
				if(re==1){
					mods=0;
					mods=0,hint=0,hint_times=1,re=0;
					for(r=0;r<50;r++) printf("\n");
					puts("============================================================================");
					final=1;
				}
				else if(re==0){
					printf("%40s","From\n");
					printf("%50s","Student:B11107157�L����");
					Sleep(250);
					puts("");
					Sleep(250);
					puts("");
					Sleep(250);
					puts("");
					Sleep(250);
					puts("");
					printf("%50s","Student:B11107116�d�~�F");
					Sleep(250);
					puts("");
					Sleep(250);
					puts("");
					Sleep(250);
					puts("");
					Sleep(250);
					puts("");
					printf("%50s","Student:B11107152����}");
					final=1;
				}
				else{
					printf("�п�J���T���O\n");
				}
			}
		}	
	
	}
}

