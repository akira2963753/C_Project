//Final version 12/12
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double basic(double ans);//基本模式
double exp_ln_log(double ans);//指對數運算 
double tri(double ans);//三角函數運算 
double absolute(double ans);//絕對值運算 
int Differential_Integral(int mod);//方程式微積分 
void array_calculate(void);//矩陣計算 
void enter_element(int *ptr,int row,int column);//輸入矩陣 
void product_array(int *array1,int *array2,int row1,int column1,int row2,int column2);//計算矩陣相乘 
void function(void); 
void find_coefficient(int x_coe,int y_coe,int c); 
void coordinate_system(int x_coe,int y_coe,int c);//座標系統 
int factorial(int number);//階乘計算 
int reduction(int v,int sv,int f);//約分 

int main(void){
	char s[100]={};
	int k=0,p=0;//用k記小數點位置,p記輸出精度 
	int end=0;//是否停止計算機 
	int mode; //計算機模式 
	double m; //記憶 
	int n=0,out=0;
	while(end==0){ //當end==0 代表要繼續執行計算機
		out=0,k=0,p=6; 
		puts("Calculator Modes");
		puts("------------------------------------------");
		puts("|Mode1:Basic                             |");
		puts("|Mode2:Absolute                          |");
		puts("|Mode3:Exponentail-Logarithmic Function  |");
		puts("|Mode4:Trigonometric Functions           |");
		puts("|Mode5:Differential                      |");
		puts("|Mode6:Array Calculate                   |");
		puts("|Mode7:Equation and Coordinate_system    |");
		puts("|Mode8:Factorial Calculate               |");
		puts("|Mode9:Integral                          |");
		puts("|----------------------------------------|");
		again:
		puts("Choose mode:");
		scanf("%d",&mode); //選擇模式 
		if(getchar()!='\n'){
			while(getchar()!='\n');
			printf("Please Enter Correct Mode\a\n");
			mode=0;
			goto again;
		}
		switch(mode){ //switch語法判斷模式 
			case 1:
				m=basic(m); //把m等於basic()出來的答案 
				break;
			case 2:
				m=absolute(m);
				break;
			case 3:
				m=exp_ln_log(m);
				break;
			case 4:
				m=tri(m);
				break;
			case 5:
				Differential_Integral(mode);
				puts("");
				break;
			case 6:
				array_calculate();
				puts("");
				break;
			case 7:
				function();
				puts("");
				break;
			case 8:
				printf("Enter Factorial Number:");
				scanf("%d",&n);
				if(n<13&&n>=0){
					printf("%d!",n);
					m=(double)factorial(n);
				}
				else{
					printf("Out of Calculate Range\n");
					out=1;
				}
				break;
			case 9:
				Differential_Integral(mode);
				puts("");
				break;
			default:
				printf("Please Enter Correct Mode\a\n");
				mode=0;
				goto again;
		}
		if(mode!=5&&mode!=6&&mode!=7&&mode!=9&&out==0){
			sprintf(s,"%lf",m);//將答案變成字串
			for(int i=0;s[i]!='.';i++,k++);//Double精度為6 先找出小數點在哪裡
			for(int i=6;s[k+i]=='0';i--) p--;//搜索最後是不是為0，是的話就往前搜索 然後精度-1  
			printf("=%.*lf\n",p,m);		
		}
		puts("--------------------------");
		printf("Continue:(Enter 0):");
		scanf("%d",&end);
	}
}

double number(char a[],int x,int* k,int need_memory,double ans)
{
	int z=0,neg=1;//z 判斷是否有小數點，neg 判斷負數 
	double num=0;//number 
	if(a[x+*k]=='-')//讓num可以是負數 
	{
		neg=-1;
		*k=*k+1;
	}
	if(need_memory==1&&a[x+*k]=='A'&&a[x+*k+1]=='n'&&a[x+*k+2]=='s')//Ans另Ans=Ans 
	{
		*k=*k+3;
		ans=ans*neg;
		return ans;
	}
	while(1)//取數字 
	{
		if((int)a[x+*k]<=57&&(int)a[x+*k]>=48) 
		{
			
			if(z>0)//小數 
			{
				num=num+(pow(0.1,z))*((int) a[x+*k]-'0');
				z++;
			}
			else//整數 
			{
				num = 10*num + (int)a[x+*k]-'0';
			}		
		}
		else if(a[x+*k]=='.')//開始為小數 
		{
			z=1;
		}
		else//取完了 
		{
			break;
		}
		*k=*k+1;
	}
	num=num*neg; //讓number可以是負數 
	return (num);//回傳num 
}

double basic(double ans)
{
	
	char a [100]={'\0'};//紀錄算式 
	char a1 [100]={'\0'};//準備要取代算式的數值 
	int b[100],c[100];//紀錄括弧的位置 
	int s=0,m=0,k2;	//m 先乘除後加減，k2 當括弧只有瓜住一個數字時，所使用的變數 
	int *k=&s;//*k為括弧後現在的讀取位置 
	int i=0,j1=0,x,y,z,op,neg,need_memory,error=0;//i,z for迴圈 ，j1判斷有無括弧，x "("位置 +1=="數字"位置 ，y 第一個")"的位置 
	double n1=0,n2=0;//number1,number2
	input_again://輸入錯誤時使用 
	printf("Use Ans(Enter 1)(使用時請自行輸入Ans):");
	scanf("%d",&need_memory); 
	if(getchar()!='\n'){//抵掉使用者亂輸入 
		while(getchar()!='\n');
		printf("Please Enter Correct Mode\a\n");
		need_memory=0;
		goto input_again;
	}
	printf("請輸入運算式:\n");
	scanf("%s",a);
	error=0;
	while(a[i]!='\0')//抵掉使用者亂輸入 
	{
		if(((int) a[i]>(int) '9' || (int) a[i]<(int) '0') && a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/' && a[i]!='^' && a[i]!='A' &&a[i]!='.'&& a[i]!='n' && a[i]!='s' && a[i]!='(' && a[i]!=')')
		{
			error=1;
			break;
		}
		if(a[i]=='A'&&(a[i+1]!='n'||a[i+2]!='s'))
		{
			error=1;
			break;
		}
		if((a[i]=='+'||a[i]=='-')&&(a[i+1]=='*'||a[i+1]=='/'||a[i+1]=='^'))
		{
			error=1;
			break;
		}
		if((a[i]=='*'||a[i]=='/'||a[i]=='^')&&(a[i+1]=='-'||a[i+1]=='*'||a[i+1]=='/'||a[i+1]=='^'))
		{
			error=1;
			break;
		}
		i++;
	}
	if(error==1)
	{
		printf("error\n");
		goto input_again;
	}
	all://運算時使用 
	i=0,j1=0,n1=0,n2=0,y=0;
	while(1)
	{
		if(a[i]=='(')
		{
			b[j1]=i;//紀錄'('位置 
			j1++;
		}
		if(a[i]=='\0')
		{
			if(j1==0)//沒有'('，"數字"位置等於0 
			{
				x=0;
			}
			else
			{
				x=b[j1-1]+1;//"("位置 +1=="數字"位置 
			}
			break;
		}
		i++;
	}
	i=x;
	while(1)
	{
		if(a[i]==')')
		{
			y=i;//第一個")"的位置 
			break;
		}
		if(a[i]=='\0')
		{
			break;
		}
		i++;
	}
	if((y==0&&j1!=0)||(y!=0&&j1==0))//抵掉括弧沒有成對 
	{
		printf("error\n");
		goto input_again;
	}
	
	i=0;
	*k=0;
	m=0;
	while(1)//先乘除後加減 ， 在括弧內尋找在'+-'後的 ' * / ^' 
	{

		if(a[i+x]=='+'||a[i+x]=='-')
		{
			m=i+1;
		}
		if((a[i+x]=='*'||a[i+x]=='/'||a[i+x]=='^')&&m!=0)
		{
			*k=m;
			break;
		}
		if(a[i+x]=='\0'||a[i+x]==')')
		{
			m=0;
			*k=0;
			break;
		}	
		i++;
	}
	n1=number(a,x,k,need_memory,ans);//取number1 
	op=(int)a[x+*k];//取運算符號 
	if(op==')')//括弧只有括一個時，運算符號取下一個 ，並使用k2紀錄 
	{
		*k=*k+1;
		op=(int)a[x+*k];
		k2=1;
	}
	*k=*k+1;
	n2=number(a,x,k,need_memory,ans);//取number2 
	if(op==(int)'+')//運算 
		n1=n1+n2;
	else if(op==(int)'-')
		n1=n1-n2;
	else if(op==(int)'*')
		n1=n1*n2;
	else if(op==(int)'/')
		n1=n1/n2;
	else if(op==(int)'^')
		n1=pow(n1,n2);
	else
		return n1;//沒有運算即回傳答案 
	sprintf(a1, "%f" , n1);//將結果變為字串 
	if(a[x+m-1]=='('&&a[x+*k]==')')//x+m-1為'('位置 ，x+*k為')'位置 
	{
		for(z=0;z<y-x+2;z++)//從 x-1開始取代 ，取代 y-x+2個 
		{
			if(a1[z]!='\0')//如果數字不夠長，取代成0 
				a[x+z-1]=a1[z];
			else
				a[x+z-1]=0;	
		}
	}
	else if(k2==1)//括弧只有括一個數字時，從 x-1開始取代，取代 (x+*k)-m-x+1個 
	{
		k2=0;
		for(z=0;z<=(x+*k)-m-x;z++)
		{
			if(a1[x]!='\0')//如果數字不夠長，取代成0 
				a[x+z-1]=a1[z];
			else
				a[x+z-1]='0';	
		}
	}
	else
	{
		for(z=0;z<(x+*k)-m-x;z++)//沒有括弧時，從 x+m開始取代，取代 (x+*k)-m-x個 
		{
			if(a1[z]!='\0')//如果數字不夠長，取代成0 
				a[x+m+z]=a1[z];
			else
				a[x+m+z]='0';
		}
	}
	for(z=0;z<99;z++)//--得+ 
	{
		if(a[z]=='-'&&a[z+1]=='-')
		{
			a[z]='+';
			a[z+1]='+';
		}
	}
	goto all;//回去 
}


double absolute(double ans){
	double number;
	int need_memory=0;
	again:
	printf("Use Ans(Enter 1):");
	scanf("%d",&need_memory);
	if(need_memory==1){
		ans=fabs(ans);
		puts("|Ans|");
	}
	else{
		printf("Enter number:");
		scanf("%lf",&number);
		if(getchar()!='\n'){
			while(getchar()!='\n');
			printf("Please Enter Correct Number\a\n");
			number=0;
			goto again;
		}
		else ans=fabs(number);
	}
	return ans;
	
	
}

double exp_ln_log(double ans)//^:exp、]:ln、~:log
{
	double number;
	int need_memory=0,correct=0,i;
	int exp_mode=0;
	double base;
	printf("Use Ans(Enter 1):");
	scanf("%d",&need_memory);
	while(correct==0)
	{
		again:
		exp_mode=0;
		puts("---------------------------------");
		puts("Exponentail-Logarithmic Function:");
		printf("1:exp[]\t2:ln[]\t3:log[]\t4:log<>[]\n");
		scanf("%d",&exp_mode);
		if(getchar()!='\n'){
			while(getchar()!='\n');
			printf("Please Enter Correct Function\a\n");
			goto again;
		}
		else if(exp_mode==1) printf("e");
		else if(exp_mode==2) printf("ln");
		else if(exp_mode==3) printf("log");
		else if(exp_mode==4){
			printf("請輸入底數:");
			scanf("%lf",&base);
			if(base<=0||getchar()!='\n'){//輸入錯誤底數 
				while(getchar()!='\n');
				printf("Please Enter Correct Base Number\a\n");
				base=0;
				goto again;
			}
			else printf("log<%.10lg>",base);
		}
		else{
			printf("Please Enter Correct Function\a\n");
			goto again;			
		}
		if(need_memory==1)
		{
			number=ans;
			puts("(Ans)");
		}
		else scanf("%lf",&number);
		if(need_memory!=1&&getchar()!='\n'){
			while(getchar()!='\n');
			printf("Please Enter Correct Number\a\n");
			goto again;
		}
		else;
		switch(exp_mode)
		{
			case 1:
				ans=exp(number);
				correct=1;
				break;
			case 2:
				if(number<0) printf("Out of Range\a\n");
				else{
					ans=log(number);
					correct=1;	
				}
				break;
			case 3:
				if(number<0) printf("Out of Range\a\n");
				else{
					ans=log10(number);
					correct=1;	
				}
				break;
			case 4:
				if(number<0) printf("Out of Range\a\n");
				else{
					ans=log10(number)/log10(base);
					correct=1;	
				}
				break;
		}
	}
	return ans;	
}



double tri(double ans) 
{
	double number;
	int need_memory=0,correct=0,i;
	char o='0';
	int tri_mode=0;
	printf("Using Ans(Enter 1):");
	scanf("%d",&need_memory);
	if(getchar()!='\n'){
		while(getchar()!='\n');
	}
	while(correct==0)
	{	
		again:
		tri_mode=0;
		puts("------------------------");
		puts("Trigonometric Functions:");
		printf("1:sin[]\t\t2:cos[]\t\t3:tan[]\n4:cot[]\t\t5:sec[]\t\t6:csc[]\t\n");
		printf("7:arcsin[]\t8:arccos[]\t9:arctan[]\t\n10:arccot[]\t11:arcsec[]\t12:arccsc[]\t\n");
		scanf("%d",&tri_mode);
		if(getchar()!='\n'){
			while(getchar()!='\n');
			printf("Please Enter Correct Function\a\n");
			goto again;
		}
		else if(tri_mode==1) printf("sin");
		else if(tri_mode==2) printf("cos");
		else if(tri_mode==3) printf("tan");
		else if(tri_mode==4) printf("cot");
		else if(tri_mode==5) printf("sec");
		else if(tri_mode==6) printf("csc");
		else if(tri_mode==7) printf("arcsin");
		else if(tri_mode==8) printf("arccos");
		else if(tri_mode==9) printf("arctan");
		else if(tri_mode==10) printf("arccot");
		else if(tri_mode==11) printf("arcsec");
		else if(tri_mode==12) printf("arccsc");
		else{
			printf("Please Enter Correct Function\a\n");
			goto again;
		}
		if(need_memory==1){
			number=ans;
			puts("[Ans]");
		}
		else scanf("%lf",&number);
		if(need_memory!=1&&getchar()!='\n'){
			while(getchar()!='\n');
			printf("Please Enter Correct Number\a\n");
			goto again;
		}
		else if(tri_mode==1||tri_mode==6){
				number=number*M_PI/180;
				ans=sin(number);
				if(tri_mode==6){
					if(ans==0) printf("Out of Range\n");
					else{
						ans=1/ans;
						correct=1; 
					}
				}
				else correct=1;
		}
		else if(tri_mode==2||tri_mode==5){
				number=number*M_PI/180;
				ans=cos(number);
				if(tri_mode==5){
					if(ans==0) printf("Out of Range\n");
					else{
						ans=1/ans;
						correct=1; 
					}
				}
				else correct=1;			
		}
		else if(tri_mode==3||tri_mode==4){
				number=number*M_PI/180;
				ans=tan(number);
				if(tri_mode==4){
					if(ans==0) printf("Out of Range\n");
					else{
						ans=1/ans;
						correct=1; 
					}
				}
				else if(ans>1000) printf("Out of Range\n");
				else correct=1;		
		}
		else if(tri_mode==7||tri_mode==12){
				if(tri_mode==12){
					number=1/number;	
				}
				if(number>1||number<-1) printf("Out of Range\n");
				else{
					ans=asin(number);
					ans=ans*180/M_PI;
					correct=1;
				}
		}
		else if(tri_mode==8||tri_mode==11){
				if(tri_mode==11){
					number=1/number;	
				}
				if(number>1||number<-1) printf("Out of Range\n");
				else{
					ans=acos(number);
					ans=ans*180/M_PI;
					correct=1;
				}
		}
		else if(tri_mode==9||tri_mode==10){
				if(tri_mode==10){
					number=1/number;	
				}
				ans=atan(number);
				ans=ans*180/M_PI;
				correct=1;	
		}
		else;
	}
	return ans;	
}

int Differential_Integral(int mod){
	int i=0,j=0,n=0,t=0;
	int len=0;//字串長度為何
	int hold=0;//目前處理的位置 
	char eq[100]={};//存方程式的地方 
	int value=0;//係數 
	int svalue=0;//次方 
	printf("Note:\n");
	puts("1、必須輸入次方");
	if(mod==5){ //微分模式的輸出 
		puts("2、常數項不用輸入");
		printf("Enter Equation F(x)=");
		scanf("%s",eq);
		printf("F'(x)=");
	}
	else{ //積分模式的輸出 
		printf("Enter Equation f(x)=");
		scanf("%s",eq);
		printf("F(x)=");
	} 

	for(i=0;eq[i]!='\0';i++,len++);////要先知道輸入多少個數字 
	hold=len;
	while(hold>0){
		i=0,j=0,n=0,t=0,value=0,svalue=0;
		for(i=len-hold;eq[i]!='^';i++,n++); //讀到^停下來
		n=n+len-hold;
		for(i=len-hold;i<n;i++){
			if((eq[i]=='x')&&n-i==1&&(eq[i-1]!='0'&&eq[i-1]!='1'&&eq[i-1]!='2'&&eq[i-1]!='3'&&eq[i-1]!='4'&&eq[i-1]!='5'&&eq[i-1]!='6'&&eq[i-1]!='7'&&eq[i-1]!='8'&&eq[i-1]!='9')){
				value=1;
			}
			else;
			if(eq[i]=='0'||eq[i]=='1'||eq[i]=='2'||eq[i]=='3'||eq[i]=='4'||eq[i]=='5'||eq[i]=='6'||eq[i]=='7'||eq[i]=='8'||eq[i]=='9'){
				value=10*value+(eq[i]-'0'); //把字串轉成整數 
			}
			else;
		}
		if(eq[len-hold]=='-') value=-value; //如果為-係數的情況 係數要帶負號出來
		//printf("%d\n",value); 
		for(i=n,t=n;(eq[i]!='+')&&((i==n+1)||(eq[i]!='-'))&&(eq[i]!='\0');i++,t++){
			if(eq[i]=='0'||eq[i]=='1'||eq[i]=='2'||eq[i]=='3'||eq[i]=='4'||eq[i]=='5'||eq[i]=='6'||eq[i]=='7'||eq[i]=='8'||eq[i]=='9'){
				svalue=10*svalue+(eq[i]-'0'); //把字串轉成整數 
			}
			else;
		} 
		if(eq[n+1]=='-') svalue=-svalue;//如果^-的情況 次方要帶負號
		//printf("%d\n",svalue);
		if(mod==5){//微分模式  
			if(len-hold==0){ //第一個不用印出正
				if(svalue-1==0) printf("%d",value); //當次方-1等於0時 代表變為常數項 
				else if(svalue*value==1) printf("x^%d",svalue-1);//當次方跟係數相乘等於1時 不會印出1 只印x
				else if(svalue*value==-1) printf("-x^%d",svalue-1);//當次方跟係數相乘等於-1時 不會印出-1 只印-x
				else printf("%dx^%d",svalue*value,svalue-1); //其他的正常印出 
			} 
			else{//不為第一個項要開始印出正負
				if(svalue-1==0) printf("%+d",value);//當次方-1等於0時 代表變為常數項
				else if(svalue*value==1) printf("+x^%d",svalue-1); //當次方跟係數相乘等於1時 不會印出1 只印x
				else if(svalue*value==-1) printf("-x^%d",svalue-1);//當次方跟係數相乘等於-1時 不會印出-1 只印-x
				else printf("%+dx^%d",svalue*value,svalue-1);					 
			 
			} 
		} 
		else if(mod==9){ //積分模式  
			if(svalue==-1){ //當次方為-1且value>0時 要印出lnx 
				if(len-hold!=0){ //當不為第一項時要印出正 
					if(value==1) printf("+lnx"); //係數為1時 
					else printf("+ln%dx",value); //係數不為1時 
				}
				else{ //第一項時不用印出正負 
					if(value==1) printf("lnx"); //係數為1時  
					else printf("ln%dx",value); //係數不為1時 
				}
			} 
			else if(len-hold==0){//如果是第一項不用印出正 
				if(value%(svalue+1)==0){ //如果整除時 
					if(value/(svalue+1)==1) printf("x^%d",svalue+1); //如果value/svalue+1==1時 就只印出x 
					else if(value/(svalue+1)==-1) printf("-x^%d",svalue+1); //如果value/svalue+1==-1時 就只印出-x 
					else printf("%dx^%d",value/(svalue+1),svalue+1);
				}
				else reduction(value,svalue+1,len-hold);//如果不整除就約分後印出 
			}
			else{//其他情況要印正負 
				if(value%(svalue+1)==0){
					if(value/(svalue+1)==1) printf("+x^%d",svalue+1); //如果value/svalue+1==1時 就不印係數了
					else if(value/(svalue+1)==-1) printf("-x^%d",svalue+1); //如果value/svalue+1==-1時 就只印出-x 
					else printf("%+dx^%d",value/(svalue+1),svalue+1);
				}
				else reduction(value,svalue+1,len-hold);//如果不整除就約分後印出			
			}
		}
		hold=len-t; //處理下一個運算式 
	}
}

void array_calculate(void)
{
	int i,j;
	int correct=0;
	char o='0';
	while(correct==0)
	{
		int row1,column1;
		printf("Please enter first array's row and column : ");
		scanf("%d %d",&row1,&column1);
		int array1[row1][column1];
		
		int row2,column2;
		printf("Please enter second array's row and column : ");
		scanf("%d %d",&row2,&column2);
		int array2[row2][column2];
		
		printf("Please enter array1's elements : \n");
		enter_element(array1[0],row1,column1);
		printf("Please enter array2's elements : \n");
		enter_element(array2[0],row2,column2);
		
		printf("Please enter + or - or * : ");
		getchar();
		scanf("%c",&o);
		
		switch(o)
		{
			case '+':
				if(row1!=row2||column1!=column2)
				{
					printf("Error\n");
					break;
				}
				for(i=0;i<row1;i++)
				{
					for(j=0;j<column1;j++)
					{
						printf("%4d",array1[i][j]+array2[i][j]);
					}
					puts("");
				}	
				correct=1;
				break;
			case '-':
				if(row1!=row2||column1!=column2)
				{
					printf("Error\n");
					break;
				}
				for(i=0;i<row1;i++)
				{
					for(j=0;j<column1;j++)
					{
						printf("%4d",array1[i][j]-array2[i][j]);
					}
					puts("");
				} 
				correct=1;
				break;
			case '*':
				if(column1!=row2)
				{
					printf("Error\n");
					break;
				} 	
				product_array(array1[0],array2[0],row1,column1,row2,column2);
				correct=1;
				break;
			default :
				printf("Error\n");
				break;
		}	
	}
}

void enter_element(int *ptr,int row,int column)
{
	int times=row*column;
	for(int i=0;i<times;i++)
	{
		scanf("%d",(ptr+i));
	}
} 

void product_array(int *array1,int *array2,int row1,int column1,int row2,int column2)
{
	int judge=0;//判斷array1換行 
	int ans;
	for(int l=0;l<row1;l++)
	{
		for(int i=0;i<column2;i++)
		{
			int a=0;//判斷array2換行 
			ans=0;
			for(int j=0;j<row2;j++)
			{
				ans+=*(array1+j+judge)**(array2+i+a);
				a+=column2;
			}
			
			printf("%4d",ans);
			if(i==column2-1)
			{
				puts("");
			}
		}
		judge+=column1;
	}
}



void function(void)
{	
	int s=0;
	int correct=0;
	int x_coe,y_coe,c;
	printf("Format : Ax + By = C\n");
	while(correct==0)
	{
		printf("Please enter x's coefficient A : ");
		scanf("%d",&x_coe);
		printf("Please enter y's coefficient B : ");
		scanf("%d",&y_coe);
		printf("Please enter constant C : ");
		scanf("%d",&c);
		printf("%dx + %dy = %d\n",x_coe,y_coe,c);
		find_coefficient(x_coe,y_coe,c);
		correct=1;
	}
	printf("\nCoordinate_system<Integer>(Enter 1):");
	scanf("%d",&s);
	if(s==1) coordinate_system(x_coe,y_coe,c); 
}

void find_coefficient(int x_coe,int y_coe,int c)
{	
	int n=0;
	int tmp;
	int x_up;
	int x_low;
	if(y_coe!=0 && x_coe!=0)
	{
		x_up=(c-y_coe*10)/x_coe;
		x_low=(c-y_coe*(-10))/x_coe;
		if(x_low>x_up)
		{
			tmp=x_up;
			x_up=x_low;
			x_low=tmp;
		}
		for(int i=-10;i<=10;i++)
		{
			for(int j=x_low;j<=x_up;j++)
			{
				if(x_coe*j+y_coe*i==c)
				{
					printf("(%3d,%3d)\n",j,i);
				}
			}
		}	
	}
	if(y_coe==0 && x_coe!=0)
	{
		for(int i=-10;i<=10;i++)
		{
			if(x_coe*i==c)
			{
				printf("X = %d\n",i);
			}
		}
	}
	if(x_coe==0 && y_coe!=0)
	{
		double ans=(double)c/y_coe;

		printf("Y = %lg\n",ans);
	}
}

void coordinate_system(int x_coe,int y_coe,int c){
	int n=0;
	int tmp;
	int x_up;
	int x_low;
	int p=0;
	again:
	printf("Choose precision:(建議<20)");
	scanf("%d",&p);
	if(p<=0){
		printf("請輸入正確精度\n");
		while(getchar()!='\n');
		goto again;
	}
	if(y_coe!=0&&x_coe!=0)//斜直線 
	{
		x_up=(c-y_coe*p)/x_coe;
		x_low=(c-y_coe*(-p))/x_coe;
		if(x_low>x_up)
		{
			tmp=x_up;
			x_up=x_low;
			x_low=tmp;
		}
		for(int i=p;i>=-p;i--){
			printf("%3d|",i);
			for(int j=-p;j<=p;j++){
				if(x_coe*j+y_coe*i==c){
					printf("*");//在這一格 
				}
				else printf("    ");
			}
			puts("");
		}
	}
	else if(y_coe!=0&&x_coe==0){//水平線
		for(int i=p;i>=-p;i--){
			printf("%3d|",i);
			if(y_coe*i==c){
				for(int k=p;k>=-p;k--) printf("  * ");
				puts("");
			}
			else puts("");
		}
	}
	else if(y_coe==0&&x_coe!=0){//垂直線
		for(int i=p;i>=-p;i--){
			printf("%3d|",i);
			for(int k=-p;k<=p;k++){
				if(x_coe*k==c) printf("*");
				else printf("    "); 
			}
			puts("");
		}
	}
	else;
	printf("   |");
	for(int i=-p;i<=p;i++) printf("%-3d|",i);//x軸基準線 
}

int factorial(int number){
	if(number<=1) return 1;//當 0!和 1!時為1 
	else return number*factorial(number-1);//其他狀況 n!=n-(n-1)! 
}

int reduction(int v,int sv,int f){
	int n=1,r=1;
	while(n<=fabs(v)){
		if((v%n==0)&&(sv%n==0)) r=n;
		n++;
	}
	if(f==0){//不用印正出來，注意絕對值要用浮點數出 
		if(sv*v>0) printf("%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv跟v係數和為正 不用印出+
		else printf("-%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv跟v係數和為負 印出- 
	}
	else{ //印出正負，注意絕對值要用浮點輸出 
		if(sv*v>0) printf("+%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv跟v係數和為正 印出+
		else printf("-%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv跟v係數和為負 印出- 	
	} 
}




