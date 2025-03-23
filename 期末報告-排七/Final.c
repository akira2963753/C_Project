//1-13<����[0]H1-H13> 14-26<���[1]D1-D13> 27-39<����C1-C13> 40-52<�®�S1-S13> 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
int print_card(int a,int b);//Function:�L�X�d�� 
int judge_flower(int c);//Function:�P�_��� 
int change_player(int player);//Function:���U�@�Ӫ��a 
int open(int player,int mod);//Function:�C���}�� 
int judge_put(int j_card[4][13],int j_player[4][13],int player,int c);//Function:�P�_��m���O�_���T
int clear_hand_card(int c_p[4][13],int c_player,int c_choose,int c_counter);//Function:�R�����a��W���P
int mode2_win(int c_p[4][13],int c_close_card[4]);//Function:�ΨӧP�_ mode2�ӧQ 
int sort_array(int arr[4][13]);//Function:�w�w�Ƨ�
int main(){
int re=1;	
while(re==1){
	int mode=0;
	int correct=0,counter=0,choose=0,flower=0,end=0,current_player=0,hand_card=0,choose_card=0,i,j,e=0,can_close=0,close,close_counter,can_pass;
	srand(time(NULL));//��J�ɶ��ؤl 
	int card[4][13]={};//�������W���d 
	int n[52]={};//�~�P�Τj�d�� 
	int p[4][13]={};//�����C�Ӫ��a�U�۪��d
	int close_card[4]={};//�����\�F�X�i�P 
	for(i=0;i<52;i++){//�~�P
		n[i]=rand()%52+1;
		for(j=0;j<i;j++){
			while(n[i]==n[j]){
				n[i]=rand()%52+1;
				j=-1;
			}
		}
	}
	for(i=0;i<13;i++) p[0][i]=n[i];	//���t�d����C�Ӫ��a 
	for(i=13;i<26;i++) p[1][i%13]=n[i];	//���t�d����C�Ӫ��a 
	for(i=26;i<39;i++) p[2][i%13]=n[i];	//���t�d����C�Ӫ��a 
	for(i=39;i<52;i++) p[3][i%13]=n[i];	//���t�d����C�Ӫ��a 
	sort_array(p);//�w�w�Ƨ� 
	for(i=0;i<4;i++){//��X�®�7�b���� 
		for(j=0;j<13;j++){
			if(p[i][j]==46){
				current_player=i;
				p[i][j]=-1;//�R�����a��̳o�i�P 
				for(int h=j+1;h<14;h++){
					p[i][h-1]=p[i][h];
				}
				p[i][12]=-1;
			} 
		}
	}
	card[3][6]=1;//��®�7��J�ୱ 
	mode=open(current_player,mode);//�}����Ҧ� 
	current_player=change_player(current_player);//���U�@�Ӫ��a 
	//-----------------------------------------------------------------------------
	while(end==0){
		pass://pass�|goto�^�� 
		correct=0;
		close=0;
		puts("------------------------------------------------------------");
		printf("Hearts\t\tDiamonds\tClubs\t\tSpades\n");
		puts("------------------------------------------------------------");
		for(j=0;j<13;j++){ //�L�X��W���P:
			for(i=0;i<4;i++){
				if(card[i][j]==1) print_card(i,j+1);
				printf("\t\t");
			}
			puts("");
		}
		printf("Player %d :\n",current_player+1);//�L�X����ĴX�Ӫ��a
		counter=0;//�p��Ӫ��a��W���h�ֵP 
		for(i=0;i<13;i++){
			if(p[current_player][i]!=-1) counter++;
		}
		if(mode==2) printf("�ثe�@Close:%d�i�P\n",close_card[current_player]);
		else;
		printf("�ثe�@��%d�i�P\n",counter);
		if(counter==0&&mode==2){
			current_player=change_player(current_player); //���U�@�쪱�a
			goto pass;
		}
		for(i=0,j=0;i<13;i++){ //�L�X��W���ƻ�P  
			hand_card=p[current_player][i];
			if(hand_card>0&&hand_card<=13){
				printf("%d:",j+1);
				print_card(0,hand_card);
				if(judge_put(card,p,current_player,i+1)==1) printf(" �i�X");
				puts("");
				j++;
			}
			if(hand_card>13&&hand_card<=26){
				printf("%d:",j+1);
				if(hand_card%13!=0) print_card(1,hand_card%13);
				else print_card(1,13);
				if(judge_put(card,p,current_player,i+1)==1) printf(" �i�X");
				puts("");
				j++;
			}
			if(hand_card>26&&hand_card<=39){
				printf("%d:",j+1);
				if(hand_card%13!=0) print_card(2,hand_card%13);
				else print_card(2,13);
				if(judge_put(card,p,current_player,i+1)==1) printf(" �i�X");
				puts("");
				j++;
			}
			if(hand_card>39&&hand_card<=52){
				printf("%d:",j+1);
				if(hand_card%13!=0) print_card(3,hand_card%13);
				else print_card(3,13);
				if(judge_put(card,p,current_player,i+1)==1) printf(" �i�X");
				puts("");
				j++;
			}
		}	
			if(mode==1) printf("�п�J�n��ܪ��d�P:(Pass���-1)");//���a�}�l��P:
			else if(mode==2) printf("�п�J�n��ܪ��d�P:(Close���0):");
			else;
			scanf("%d",&choose);
			if(getchar()!='\n'){//�P�_���S��Wrong character 
				while(getchar()!='\n');//�����ܴN�M�� 
			}
			else if(choose==0&&mode==2){ //�P�_���S���n���n���\�P
				can_close=1;
				for(i=1;i<=counter;i++){	//���P�_�O�_�i�H�\�P
					if(judge_put(card,p,current_player,i)==1){
						can_close=0;
					}
				}
				if(can_close==1){
					printf("�п�J�nClose���d�P:");
					scanf("%d",&choose);
					if((getchar()!='\n')){//�M���Ҧ��r������ 
						while(getchar()!='\n');
					}
					else if(choose>counter||choose<=-1||choose==0){
						printf("��J���~\n");
					}
					else{
						close_card[current_player]++;
						close=1;
						close_counter++; 
						correct=1;
					}
				}
				else printf("�ثe�٦��i�H�X���d���A�]���L�kClose\a\n");
			} 
			else if(choose>counter||(mode==1&&choose==0)||choose<-1)printf("�п�J���T���d�P\a\n");//�p�G��J�����W���d�h �άO��J0�i �άO-1�i�H�U 
			else if(choose==-1&&close==0&&mode==1){//�p�G���PASS 
				can_pass=1;
				for(i=1;i<=counter;i++){//���P�_�O�_�i�H�\�P
					if(judge_put(card,p,current_player,i)==1){
						can_pass=0;
					}
				}
				if(can_pass==1){
					current_player=change_player(current_player); //���U�@�쪱�a 
					goto pass; 
				}
				else printf("�ثe�٦��i�H�X���d���A�]���L�kpass\a\n");
			}
			else if(close==0){//�P�_�O�_��J���T�i�H�X���d�� 
				correct=judge_put(card,p,current_player,choose);
			}
			else printf("�п�J���T���d�P\a\n");
			if(correct==1){
				if(close!=1) close_counter=0;
				choose_card=p[current_player][choose-1];//���a��ܪ� Card 
				flower=judge_flower(choose_card);//�P�_���
				if(close==0){
					if(choose_card%13!=0) card[flower][choose_card%13-1]=1; 
					else card[flower][12]=1; //�p�G%13==0 �N��O13
				}
				else;
				clear_hand_card(p,current_player,choose,counter);//�R�����a��̳o�i�P 
				if(counter==1&&mode==1){//��ѤU�@�i�P�A�B�i�H���\��X�A�B�Ҧ���1�ɳӧQ 
					printf("Player %d WIN THIS GAME!!!!\n",current_player+1);
					end=1;
				}
				else if(mode==2){
					e=0;
					
					for(i=0;i<4;i++){
						if(p[i][0]==-1) e++;
					}
					if(e==4) end=mode2_win(p,close_card);
					}
				else if(close_counter==4){
					end=mode2_win(p,close_card);
				}
				else;
				current_player=change_player(current_player); //���U�@�쪱�a 
			}
			else if(choose!=0) printf("�п�J���T���d�P\a\n");
			else if(choose==0&0&mode==1) printf("�п�J���T���d�P\a\n");
			else printf("�п�J���T���d�P\a\n");
	}
	if(end==1){
		puts("�A���@��<��J1>");
		puts("�h�X<��J0>");
		scanf("%d",&re);
	}
	else;
}

}
int open(int player,int mod){
	int correct=0;
	printf("%51s","<Weclome to My sevens World>\n");
		puts("============================================================================");
		printf("%52s","<Please Choose Mods You Want>\n");
		puts("|--------------------------------------------------------------------------|");
		puts("|                                                                          |");
		puts("|                      1�BNormal Mode(can pass)                            |");
		puts("|                      2�BSpecial Mode(can close card)                     |");
		puts("|                                                                          |");
		puts("|--------------------------------------------------------------------------|");
		printf("%43s","<Your choice>\n");
		puts("============================================================================");
	while(correct==0){
		printf("Choose:");
		scanf("%d",&mod);
		if(getchar()!='\n'){
				while(getchar()!='\n');
				puts("�п�J���T�Ҧ�");
			}
		else if(mod==1){
			puts("<Normal Mode>");
			correct=1;
		}
		else if(mod==2){
			puts("<Special Mode>");
			correct=1;
		}
		else{
			puts("�п�J���T�Ҧ�");
		}
	
	}
	puts("�C���}�l");
	Sleep(500);
	printf("�~�P��\n");
	for(int i=0;i<4;i++){
		printf("....");
		Sleep(500);
	}
	puts("");
	printf("�®�7����:\n");
	printf("Player %d ����®�7\n",player+1);
	Sleep(500);
	return mod;//�^�ǹC���Ҧ�
}
int print_card(int a,int b){//�L�X�d��
	switch(a){
		case 0:
			if(b==1)printf("H %s","A");
			else if(b==11)printf("H %s","J");
			else if(b==12)printf("H %s","Q");
			else if(b==13)printf("H %s","K");
			else printf("H %d",b);
			break;
		case 1:
			if(b==1)printf("D %s","A");
			else if(b==11)printf("D %s","J");
			else if(b==12)printf("D %s","Q");
			else if(b==13)printf("D %s","K");
			else printf("D %d",b);
			break;
		case 2:
			if(b==1)printf("C %s","A");
			else if(b==11)printf("C %s","J");
			else if(b==12)printf("C %s","Q");
			else if(b==13)printf("C %s","K");
			else printf("C %d",b);
			break;
		case 3:
			if(b==1)printf("S %s","A");
			else if(b==11)printf("S %s","J");
			else if(b==12)printf("S %s","Q");
			else if(b==13)printf("S %s","K");
			else printf("S %d",b);
			break;
		default:
			break;
			
	}
}


int judge_flower(int c){//�P�_�O������ 
	if(c<=13) return 0;//���� 
	if(c>13&&c<=26) return 1;//��� 
	if(c>26&&c<=39) return 2;//���� 
	if(c>39&&c<=52) return 3;//�®� 
}


int change_player(int player){//���U�@�Ӫ��a 
	if(player==3) player=0;
	else player++;
	return player;
} 


int judge_put(int j_card[4][13],int j_player[4][13],int player,int c){//�P�_�O�_���i��mCard 
	int a[4]={0},b[4]={0},i,j=0,k=0,x,chan=0;
	for(i=0;i<4;i++){
		a[i]=0;
		b[i]=0;
	}
	for(x=0;x<4;x++){
		for(i=6;i<13;i++){ //�Ʀr7����m�bcard[x][6]�A��7�H�W�J��Ĥ@�ӨS��P��(==0)��Ja�̭�
			if(j_card[x][i]==0){
				a[j]=i+chan+1;//a[k]���i��ȡA�[chain�O�]���w�q�ɬO1��52���O���P��1��52->�@���[13 
				j++;
				i=13;
			}	
		}
		for(i=6;i>=0;i--){//��Ʀr7�H�U�Ĥ@�ӨS��P��(==0)��Jb�̭�
			if(j_card[x][i]==0){
				b[k]=i+chan+1;//b[k]���i��� 
				k++;
				i=i*(-1);
				}
			}
			chan=chan+13;
		}
	for(i=0;i<4;i++){
		if(a[i]==j_player[player][c-1]||b[i]==j_player[player][c-1]){
			return 1;//���T:�i�H�}�l��P 
		}
	}
	return 0;
}	


int clear_hand_card(int c_p[4][13],int c_player,int c_choose,int c_counter){
	int i;
	for(i=c_choose;i<c_counter+1;i++){
		c_p[c_player][i-1]=c_p[c_player][i];
		}
	c_p[c_player][c_counter-1]=-1;
}


int mode2_win(int c_p[4][13],int c_close_card[4]){
	int i,min=0;				
	for(min=100,i=0;i<4;i++){//�h��ֻ\�ֵ̤P 
		if(min>=c_close_card[i]){
			min=c_close_card[i];
		}
	}
	for(i=0;i<4;i++){//�L�X�ӳֵ̤P�����ӤH��� 
		if(c_close_card[i]==min) printf("Player %d WIN THIS GAME!!!!\n",i+1);
	}
	return 1;
}


int sort_array(int arr[4][13]){
	int temp,i,j,k;
	for(i=0;i<4;i++){ //���a 
		for(j=0;j<13;j++){ //Card 
			for(k=0;k<12;k++){ //�C�@�iCard��12���w�w 
				if(arr[i][k]>arr[i][k+1]){ //�p�G�e����᭱�j 
					temp=arr[i][k];	//�Τ@�ӼȦs��e�@�ӰO�� 
					arr[i][k]=arr[i][k+1]; //��p�Ʃ��e�� 
					arr[i][k+1]=temp;	//��j�Ʃ����
				}
			}
		}
	}
}
