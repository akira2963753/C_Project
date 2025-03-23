//Final version 12/12
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double basic(double ans);//�򥻼Ҧ�
double exp_ln_log(double ans);//����ƹB�� 
double tri(double ans);//�T����ƹB�� 
double absolute(double ans);//����ȹB�� 
int Differential_Integral(int mod);//��{���L�n�� 
void array_calculate(void);//�x�}�p�� 
void enter_element(int *ptr,int row,int column);//��J�x�} 
void product_array(int *array1,int *array2,int row1,int column1,int row2,int column2);//�p��x�}�ۭ� 
void function(void); 
void find_coefficient(int x_coe,int y_coe,int c); 
void coordinate_system(int x_coe,int y_coe,int c);//�y�Шt�� 
int factorial(int number);//�����p�� 
int reduction(int v,int sv,int f);//���� 

int main(void){
	char s[100]={};
	int k=0,p=0;//��k�O�p���I��m,p�O��X��� 
	int end=0;//�O�_����p��� 
	int mode; //�p����Ҧ� 
	double m; //�O�� 
	int n=0,out=0;
	while(end==0){ //��end==0 �N��n�~�����p���
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
		scanf("%d",&mode); //��ܼҦ� 
		if(getchar()!='\n'){
			while(getchar()!='\n');
			printf("Please Enter Correct Mode\a\n");
			mode=0;
			goto again;
		}
		switch(mode){ //switch�y�k�P�_�Ҧ� 
			case 1:
				m=basic(m); //��m����basic()�X�Ӫ����� 
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
			sprintf(s,"%lf",m);//�N�����ܦ��r��
			for(int i=0;s[i]!='.';i++,k++);//Double��׬�6 ����X�p���I�b����
			for(int i=6;s[k+i]=='0';i--) p--;//�j���̫�O���O��0�A�O���ܴN���e�j�� �M����-1  
			printf("=%.*lf\n",p,m);		
		}
		puts("--------------------------");
		printf("Continue:(Enter 0):");
		scanf("%d",&end);
	}
}

double number(char a[],int x,int* k,int need_memory,double ans)
{
	int z=0,neg=1;//z �P�_�O�_���p���I�Aneg �P�_�t�� 
	double num=0;//number 
	if(a[x+*k]=='-')//��num�i�H�O�t�� 
	{
		neg=-1;
		*k=*k+1;
	}
	if(need_memory==1&&a[x+*k]=='A'&&a[x+*k+1]=='n'&&a[x+*k+2]=='s')//Ans�tAns=Ans 
	{
		*k=*k+3;
		ans=ans*neg;
		return ans;
	}
	while(1)//���Ʀr 
	{
		if((int)a[x+*k]<=57&&(int)a[x+*k]>=48) 
		{
			
			if(z>0)//�p�� 
			{
				num=num+(pow(0.1,z))*((int) a[x+*k]-'0');
				z++;
			}
			else//��� 
			{
				num = 10*num + (int)a[x+*k]-'0';
			}		
		}
		else if(a[x+*k]=='.')//�}�l���p�� 
		{
			z=1;
		}
		else//�����F 
		{
			break;
		}
		*k=*k+1;
	}
	num=num*neg; //��number�i�H�O�t�� 
	return (num);//�^��num 
}

double basic(double ans)
{
	
	char a [100]={'\0'};//�����⦡ 
	char a1 [100]={'\0'};//�ǳƭn���N�⦡���ƭ� 
	int b[100],c[100];//�����A������m 
	int s=0,m=0,k2;	//m ��������[��Ak2 ��A���u���ʦ�@�ӼƦr�ɡA�ҨϥΪ��ܼ� 
	int *k=&s;//*k���A����{�b��Ū����m 
	int i=0,j1=0,x,y,z,op,neg,need_memory,error=0;//i,z for�j�� �Aj1�P�_���L�A���Ax "("��m +1=="�Ʀr"��m �Ay �Ĥ@��")"����m 
	double n1=0,n2=0;//number1,number2
	input_again://��J���~�ɨϥ� 
	printf("Use Ans(Enter 1)(�ϥήɽЦۦ��JAns):");
	scanf("%d",&need_memory); 
	if(getchar()!='\n'){//�豼�ϥΪ̶ÿ�J 
		while(getchar()!='\n');
		printf("Please Enter Correct Mode\a\n");
		need_memory=0;
		goto input_again;
	}
	printf("�п�J�B�⦡:\n");
	scanf("%s",a);
	error=0;
	while(a[i]!='\0')//�豼�ϥΪ̶ÿ�J 
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
	all://�B��ɨϥ� 
	i=0,j1=0,n1=0,n2=0,y=0;
	while(1)
	{
		if(a[i]=='(')
		{
			b[j1]=i;//����'('��m 
			j1++;
		}
		if(a[i]=='\0')
		{
			if(j1==0)//�S��'('�A"�Ʀr"��m����0 
			{
				x=0;
			}
			else
			{
				x=b[j1-1]+1;//"("��m +1=="�Ʀr"��m 
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
			y=i;//�Ĥ@��")"����m 
			break;
		}
		if(a[i]=='\0')
		{
			break;
		}
		i++;
	}
	if((y==0&&j1!=0)||(y!=0&&j1==0))//�豼�A���S������ 
	{
		printf("error\n");
		goto input_again;
	}
	
	i=0;
	*k=0;
	m=0;
	while(1)//��������[�� �A �b�A�����M��b'+-'�᪺ ' * / ^' 
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
	n1=number(a,x,k,need_memory,ans);//��number1 
	op=(int)a[x+*k];//���B��Ÿ� 
	if(op==')')//�A���u���A�@�ӮɡA�B��Ÿ����U�@�� �A�èϥ�k2���� 
	{
		*k=*k+1;
		op=(int)a[x+*k];
		k2=1;
	}
	*k=*k+1;
	n2=number(a,x,k,need_memory,ans);//��number2 
	if(op==(int)'+')//�B�� 
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
		return n1;//�S���B��Y�^�ǵ��� 
	sprintf(a1, "%f" , n1);//�N���G�ܬ��r�� 
	if(a[x+m-1]=='('&&a[x+*k]==')')//x+m-1��'('��m �Ax+*k��')'��m 
	{
		for(z=0;z<y-x+2;z++)//�q x-1�}�l���N �A���N y-x+2�� 
		{
			if(a1[z]!='\0')//�p�G�Ʀr�������A���N��0 
				a[x+z-1]=a1[z];
			else
				a[x+z-1]=0;	
		}
	}
	else if(k2==1)//�A���u���A�@�ӼƦr�ɡA�q x-1�}�l���N�A���N (x+*k)-m-x+1�� 
	{
		k2=0;
		for(z=0;z<=(x+*k)-m-x;z++)
		{
			if(a1[x]!='\0')//�p�G�Ʀr�������A���N��0 
				a[x+z-1]=a1[z];
			else
				a[x+z-1]='0';	
		}
	}
	else
	{
		for(z=0;z<(x+*k)-m-x;z++)//�S���A���ɡA�q x+m�}�l���N�A���N (x+*k)-m-x�� 
		{
			if(a1[z]!='\0')//�p�G�Ʀr�������A���N��0 
				a[x+m+z]=a1[z];
			else
				a[x+m+z]='0';
		}
	}
	for(z=0;z<99;z++)//--�o+ 
	{
		if(a[z]=='-'&&a[z+1]=='-')
		{
			a[z]='+';
			a[z+1]='+';
		}
	}
	goto all;//�^�h 
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

double exp_ln_log(double ans)//^:exp�B]:ln�B~:log
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
			printf("�п�J����:");
			scanf("%lf",&base);
			if(base<=0||getchar()!='\n'){//��J���~���� 
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
	int len=0;//�r����׬���
	int hold=0;//�ثe�B�z����m 
	char eq[100]={};//�s��{�����a�� 
	int value=0;//�Y�� 
	int svalue=0;//���� 
	printf("Note:\n");
	puts("1�B������J����");
	if(mod==5){ //�L���Ҧ�����X 
		puts("2�B�`�ƶ����ο�J");
		printf("Enter Equation F(x)=");
		scanf("%s",eq);
		printf("F'(x)=");
	}
	else{ //�n���Ҧ�����X 
		printf("Enter Equation f(x)=");
		scanf("%s",eq);
		printf("F(x)=");
	} 

	for(i=0;eq[i]!='\0';i++,len++);////�n�����D��J�h�֭ӼƦr 
	hold=len;
	while(hold>0){
		i=0,j=0,n=0,t=0,value=0,svalue=0;
		for(i=len-hold;eq[i]!='^';i++,n++); //Ū��^���U��
		n=n+len-hold;
		for(i=len-hold;i<n;i++){
			if((eq[i]=='x')&&n-i==1&&(eq[i-1]!='0'&&eq[i-1]!='1'&&eq[i-1]!='2'&&eq[i-1]!='3'&&eq[i-1]!='4'&&eq[i-1]!='5'&&eq[i-1]!='6'&&eq[i-1]!='7'&&eq[i-1]!='8'&&eq[i-1]!='9')){
				value=1;
			}
			else;
			if(eq[i]=='0'||eq[i]=='1'||eq[i]=='2'||eq[i]=='3'||eq[i]=='4'||eq[i]=='5'||eq[i]=='6'||eq[i]=='7'||eq[i]=='8'||eq[i]=='9'){
				value=10*value+(eq[i]-'0'); //��r���ন��� 
			}
			else;
		}
		if(eq[len-hold]=='-') value=-value; //�p�G��-�Y�ƪ����p �Y�ƭn�a�t���X��
		//printf("%d\n",value); 
		for(i=n,t=n;(eq[i]!='+')&&((i==n+1)||(eq[i]!='-'))&&(eq[i]!='\0');i++,t++){
			if(eq[i]=='0'||eq[i]=='1'||eq[i]=='2'||eq[i]=='3'||eq[i]=='4'||eq[i]=='5'||eq[i]=='6'||eq[i]=='7'||eq[i]=='8'||eq[i]=='9'){
				svalue=10*svalue+(eq[i]-'0'); //��r���ন��� 
			}
			else;
		} 
		if(eq[n+1]=='-') svalue=-svalue;//�p�G^-�����p ����n�a�t��
		//printf("%d\n",svalue);
		if(mod==5){//�L���Ҧ�  
			if(len-hold==0){ //�Ĥ@�Ӥ��ΦL�X��
				if(svalue-1==0) printf("%d",value); //����-1����0�� �N���ܬ��`�ƶ� 
				else if(svalue*value==1) printf("x^%d",svalue-1);//�����Y�Ƭۭ�����1�� ���|�L�X1 �u�Lx
				else if(svalue*value==-1) printf("-x^%d",svalue-1);//�����Y�Ƭۭ�����-1�� ���|�L�X-1 �u�L-x
				else printf("%dx^%d",svalue*value,svalue-1); //��L�����`�L�X 
			} 
			else{//�����Ĥ@�Ӷ��n�}�l�L�X���t
				if(svalue-1==0) printf("%+d",value);//����-1����0�� �N���ܬ��`�ƶ�
				else if(svalue*value==1) printf("+x^%d",svalue-1); //�����Y�Ƭۭ�����1�� ���|�L�X1 �u�Lx
				else if(svalue*value==-1) printf("-x^%d",svalue-1);//�����Y�Ƭۭ�����-1�� ���|�L�X-1 �u�L-x
				else printf("%+dx^%d",svalue*value,svalue-1);					 
			 
			} 
		} 
		else if(mod==9){ //�n���Ҧ�  
			if(svalue==-1){ //���謰-1�Bvalue>0�� �n�L�Xlnx 
				if(len-hold!=0){ //�����Ĥ@���ɭn�L�X�� 
					if(value==1) printf("+lnx"); //�Y�Ƭ�1�� 
					else printf("+ln%dx",value); //�Y�Ƥ���1�� 
				}
				else{ //�Ĥ@���ɤ��ΦL�X���t 
					if(value==1) printf("lnx"); //�Y�Ƭ�1��  
					else printf("ln%dx",value); //�Y�Ƥ���1�� 
				}
			} 
			else if(len-hold==0){//�p�G�O�Ĥ@�����ΦL�X�� 
				if(value%(svalue+1)==0){ //�p�G�㰣�� 
					if(value/(svalue+1)==1) printf("x^%d",svalue+1); //�p�Gvalue/svalue+1==1�� �N�u�L�Xx 
					else if(value/(svalue+1)==-1) printf("-x^%d",svalue+1); //�p�Gvalue/svalue+1==-1�� �N�u�L�X-x 
					else printf("%dx^%d",value/(svalue+1),svalue+1);
				}
				else reduction(value,svalue+1,len-hold);//�p�G���㰣�N������L�X 
			}
			else{//��L���p�n�L���t 
				if(value%(svalue+1)==0){
					if(value/(svalue+1)==1) printf("+x^%d",svalue+1); //�p�Gvalue/svalue+1==1�� �N���L�Y�ƤF
					else if(value/(svalue+1)==-1) printf("-x^%d",svalue+1); //�p�Gvalue/svalue+1==-1�� �N�u�L�X-x 
					else printf("%+dx^%d",value/(svalue+1),svalue+1);
				}
				else reduction(value,svalue+1,len-hold);//�p�G���㰣�N������L�X			
			}
		}
		hold=len-t; //�B�z�U�@�ӹB�⦡ 
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
	int judge=0;//�P�_array1���� 
	int ans;
	for(int l=0;l<row1;l++)
	{
		for(int i=0;i<column2;i++)
		{
			int a=0;//�P�_array2���� 
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
	printf("Choose precision:(��ĳ<20)");
	scanf("%d",&p);
	if(p<=0){
		printf("�п�J���T���\n");
		while(getchar()!='\n');
		goto again;
	}
	if(y_coe!=0&&x_coe!=0)//�ת��u 
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
					printf("*");//�b�o�@�� 
				}
				else printf("    ");
			}
			puts("");
		}
	}
	else if(y_coe!=0&&x_coe==0){//�����u
		for(int i=p;i>=-p;i--){
			printf("%3d|",i);
			if(y_coe*i==c){
				for(int k=p;k>=-p;k--) printf("  * ");
				puts("");
			}
			else puts("");
		}
	}
	else if(y_coe==0&&x_coe!=0){//�����u
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
	for(int i=-p;i<=p;i++) printf("%-3d|",i);//x�b��ǽu 
}

int factorial(int number){
	if(number<=1) return 1;//�� 0!�M 1!�ɬ�1 
	else return number*factorial(number-1);//��L���p n!=n-(n-1)! 
}

int reduction(int v,int sv,int f){
	int n=1,r=1;
	while(n<=fabs(v)){
		if((v%n==0)&&(sv%n==0)) r=n;
		n++;
	}
	if(f==0){//���ΦL���X�ӡA�`�N����ȭn�ίB�I�ƥX 
		if(sv*v>0) printf("%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv��v�Y�ƩM���� ���ΦL�X+
		else printf("-%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv��v�Y�ƩM���t �L�X- 
	}
	else{ //�L�X���t�A�`�N����ȭn�ίB�I��X 
		if(sv*v>0) printf("+%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv��v�Y�ƩM���� �L�X+
		else printf("-%lg/%lgx^%d",fabs(v/r),fabs(sv/r),sv);//sv��v�Y�ƩM���t �L�X- 	
	} 
}




