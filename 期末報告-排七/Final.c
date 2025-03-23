//1-13<紅心[0]H1-H13> 14-26<方塊[1]D1-D13> 27-39<梅花C1-C13> 40-52<黑桃S1-S13> 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
int print_card(int a,int b);//Function:印出卡片 
int judge_flower(int c);//Function:判斷花色 
int change_player(int player);//Function:換下一個玩家 
int open(int player,int mod);//Function:遊戲開場 
int judge_put(int j_card[4][13],int j_player[4][13],int player,int c);//Function:判斷放置的是否正確
int clear_hand_card(int c_p[4][13],int c_player,int c_choose,int c_counter);//Function:刪除玩家手上的牌
int mode2_win(int c_p[4][13],int c_close_card[4]);//Function:用來判斷 mode2勝利 
int sort_array(int arr[4][13]);//Function:泡泡排序
int main(){
int re=1;	
while(re==1){
	int mode=0;
	int correct=0,counter=0,choose=0,flower=0,end=0,current_player=0,hand_card=0,choose_card=0,i,j,e=0,can_close=0,close,close_counter,can_pass;
	srand(time(NULL));//放入時間種子 
	int card[4][13]={};//紀錄場上的卡 
	int n[52]={};//洗牌用大卡池 
	int p[4][13]={};//紀錄每個玩家各自的卡
	int close_card[4]={};//紀錄蓋了幾張牌 
	for(i=0;i<52;i++){//洗牌
		n[i]=rand()%52+1;
		for(j=0;j<i;j++){
			while(n[i]==n[j]){
				n[i]=rand()%52+1;
				j=-1;
			}
		}
	}
	for(i=0;i<13;i++) p[0][i]=n[i];	//分配卡片到每個玩家 
	for(i=13;i<26;i++) p[1][i%13]=n[i];	//分配卡片到每個玩家 
	for(i=26;i<39;i++) p[2][i%13]=n[i];	//分配卡片到每個玩家 
	for(i=39;i<52;i++) p[3][i%13]=n[i];	//分配卡片到每個玩家 
	sort_array(p);//泡泡排序 
	for(i=0;i<4;i++){//找出黑桃7在哪裡 
		for(j=0;j<13;j++){
			if(p[i][j]==46){
				current_player=i;
				p[i][j]=-1;//刪除玩家手裡這張牌 
				for(int h=j+1;h<14;h++){
					p[i][h-1]=p[i][h];
				}
				p[i][12]=-1;
			} 
		}
	}
	card[3][6]=1;//把黑桃7丟入桌面 
	mode=open(current_player,mode);//開場選模式 
	current_player=change_player(current_player);//換下一個玩家 
	//-----------------------------------------------------------------------------
	while(end==0){
		pass://pass會goto回來 
		correct=0;
		close=0;
		puts("------------------------------------------------------------");
		printf("Hearts\t\tDiamonds\tClubs\t\tSpades\n");
		puts("------------------------------------------------------------");
		for(j=0;j<13;j++){ //印出桌上的牌:
			for(i=0;i<4;i++){
				if(card[i][j]==1) print_card(i,j+1);
				printf("\t\t");
			}
			puts("");
		}
		printf("Player %d :\n",current_player+1);//印出輪到第幾個玩家
		counter=0;//計算該玩家手上有多少牌 
		for(i=0;i<13;i++){
			if(p[current_player][i]!=-1) counter++;
		}
		if(mode==2) printf("目前共Close:%d張牌\n",close_card[current_player]);
		else;
		printf("目前共有%d張牌\n",counter);
		if(counter==0&&mode==2){
			current_player=change_player(current_player); //換下一位玩家
			goto pass;
		}
		for(i=0,j=0;i<13;i++){ //印出手上有甚麼牌  
			hand_card=p[current_player][i];
			if(hand_card>0&&hand_card<=13){
				printf("%d:",j+1);
				print_card(0,hand_card);
				if(judge_put(card,p,current_player,i+1)==1) printf(" 可出");
				puts("");
				j++;
			}
			if(hand_card>13&&hand_card<=26){
				printf("%d:",j+1);
				if(hand_card%13!=0) print_card(1,hand_card%13);
				else print_card(1,13);
				if(judge_put(card,p,current_player,i+1)==1) printf(" 可出");
				puts("");
				j++;
			}
			if(hand_card>26&&hand_card<=39){
				printf("%d:",j+1);
				if(hand_card%13!=0) print_card(2,hand_card%13);
				else print_card(2,13);
				if(judge_put(card,p,current_player,i+1)==1) printf(" 可出");
				puts("");
				j++;
			}
			if(hand_card>39&&hand_card<=52){
				printf("%d:",j+1);
				if(hand_card%13!=0) print_card(3,hand_card%13);
				else print_card(3,13);
				if(judge_put(card,p,current_player,i+1)==1) printf(" 可出");
				puts("");
				j++;
			}
		}	
			if(mode==1) printf("請輸入要選擇的卡牌:(Pass選擇-1)");//玩家開始選牌:
			else if(mode==2) printf("請輸入要選擇的卡牌:(Close選擇0):");
			else;
			scanf("%d",&choose);
			if(getchar()!='\n'){//判斷有沒有Wrong character 
				while(getchar()!='\n');//有的話就清除 
			}
			else if(choose==0&&mode==2){ //判斷有沒有要做要做蓋牌
				can_close=1;
				for(i=1;i<=counter;i++){	//先判斷是否可以蓋牌
					if(judge_put(card,p,current_player,i)==1){
						can_close=0;
					}
				}
				if(can_close==1){
					printf("請輸入要Close的卡牌:");
					scanf("%d",&choose);
					if((getchar()!='\n')){//清除所有字元重來 
						while(getchar()!='\n');
					}
					else if(choose>counter||choose<=-1||choose==0){
						printf("輸入錯誤\n");
					}
					else{
						close_card[current_player]++;
						close=1;
						close_counter++; 
						correct=1;
					}
				}
				else printf("目前還有可以出的卡片，因此無法Close\a\n");
			} 
			else if(choose>counter||(mode==1&&choose==0)||choose<-1)printf("請輸入正確的卡牌\a\n");//如果輸入的比手上的卡多 或是輸入0張 或是-1張以下 
			else if(choose==-1&&close==0&&mode==1){//如果選擇PASS 
				can_pass=1;
				for(i=1;i<=counter;i++){//先判斷是否可以蓋牌
					if(judge_put(card,p,current_player,i)==1){
						can_pass=0;
					}
				}
				if(can_pass==1){
					current_player=change_player(current_player); //換下一位玩家 
					goto pass; 
				}
				else printf("目前還有可以出的卡片，因此無法pass\a\n");
			}
			else if(close==0){//判斷是否輸入正確可以出的卡片 
				correct=judge_put(card,p,current_player,choose);
			}
			else printf("請輸入正確的卡牌\a\n");
			if(correct==1){
				if(close!=1) close_counter=0;
				choose_card=p[current_player][choose-1];//玩家選擇的 Card 
				flower=judge_flower(choose_card);//判斷花色
				if(close==0){
					if(choose_card%13!=0) card[flower][choose_card%13-1]=1; 
					else card[flower][12]=1; //如果%13==0 代表是13
				}
				else;
				clear_hand_card(p,current_player,choose,counter);//刪除玩家手裡這張牌 
				if(counter==1&&mode==1){//當剩下一張牌，且可以成功丟出，且模式為1時勝利 
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
				current_player=change_player(current_player); //換下一位玩家 
			}
			else if(choose!=0) printf("請輸入正確的卡牌\a\n");
			else if(choose==0&0&mode==1) printf("請輸入正確的卡牌\a\n");
			else printf("請輸入正確的卡牌\a\n");
	}
	if(end==1){
		puts("再玩一局<輸入1>");
		puts("退出<輸入0>");
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
		puts("|                      1、Normal Mode(can pass)                            |");
		puts("|                      2、Special Mode(can close card)                     |");
		puts("|                                                                          |");
		puts("|--------------------------------------------------------------------------|");
		printf("%43s","<Your choice>\n");
		puts("============================================================================");
	while(correct==0){
		printf("Choose:");
		scanf("%d",&mod);
		if(getchar()!='\n'){
				while(getchar()!='\n');
				puts("請輸入正確模式");
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
			puts("請輸入正確模式");
		}
	
	}
	puts("遊戲開始");
	Sleep(500);
	printf("洗牌中\n");
	for(int i=0;i<4;i++){
		printf("....");
		Sleep(500);
	}
	puts("");
	printf("黑桃7先手:\n");
	printf("Player %d 先手黑桃7\n",player+1);
	Sleep(500);
	return mod;//回傳遊玩模式
}
int print_card(int a,int b){//印出卡片
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


int judge_flower(int c){//判斷是什麼花色 
	if(c<=13) return 0;//紅心 
	if(c>13&&c<=26) return 1;//方塊 
	if(c>26&&c<=39) return 2;//梅花 
	if(c>39&&c<=52) return 3;//黑桃 
}


int change_player(int player){//換下一個玩家 
	if(player==3) player=0;
	else player++;
	return player;
} 


int judge_put(int j_card[4][13],int j_player[4][13],int player,int c){//判斷是否為可放置Card 
	int a[4]={0},b[4]={0},i,j=0,k=0,x,chan=0;
	for(i=0;i<4;i++){
		a[i]=0;
		b[i]=0;
	}
	for(x=0;x<4;x++){
		for(i=6;i<13;i++){ //數字7的位置在card[x][6]，把7以上遇到第一個沒放牌的(==0)放入a裡面
			if(j_card[x][i]==0){
				a[j]=i+chan+1;//a[k]為可放值，加chain是因為定義時是1到52分別為牌的1到52->一次加13 
				j++;
				i=13;
			}	
		}
		for(i=6;i>=0;i--){//把數字7以下第一個沒放牌的(==0)放入b裡面
			if(j_card[x][i]==0){
				b[k]=i+chan+1;//b[k]為可放值 
				k++;
				i=i*(-1);
				}
			}
			chan=chan+13;
		}
	for(i=0;i<4;i++){
		if(a[i]==j_player[player][c-1]||b[i]==j_player[player][c-1]){
			return 1;//正確:可以開始放牌 
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
	for(min=100,i=0;i<4;i++){//去找誰蓋最少牌 
		if(min>=c_close_card[i]){
			min=c_close_card[i];
		}
	}
	for(i=0;i<4;i++){//印出該最少牌的那個人獲勝 
		if(c_close_card[i]==min) printf("Player %d WIN THIS GAME!!!!\n",i+1);
	}
	return 1;
}


int sort_array(int arr[4][13]){
	int temp,i,j,k;
	for(i=0;i<4;i++){ //玩家 
		for(j=0;j<13;j++){ //Card 
			for(k=0;k<12;k++){ //每一張Card做12次泡泡 
				if(arr[i][k]>arr[i][k+1]){ //如果前面比後面大 
					temp=arr[i][k];	//用一個暫存把前一個記住 
					arr[i][k]=arr[i][k+1]; //把小數往前丟 
					arr[i][k+1]=temp;	//把大數往後丟
				}
			}
		}
	}
}
