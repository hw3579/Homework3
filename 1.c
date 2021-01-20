#include<stdio.h>
#include<stdlib.h>


typedef int ELEMENT;

typedef struct Stack{
	int * List;  // 用来存储元素的顺序表
	int curNumber;   // 用来存储当前元素的总个数
}Stack;

void iniStack(Stack * A);   // 初始化堆栈
int is_empty(Stack * A);      //判断当前堆栈是否为空，空返回1，非空返回0
void clearStack(Stack * A);  //清空堆栈
void push(Stack * A, ELEMENT obj);	//将元素obj压入堆栈的栈顶
void pop(Stack * A);	//将当前栈顶的元素弹出栈。要求：栈不为空
ELEMENT get_top(Stack * A);     //返回当前栈顶的元素值。要求：栈不为空
void display(Stack * A);     //自顶向下显示堆栈中的元素

int main(){
	Stack * A = (Stack*)malloc(10*sizeof(Stack));
	iniStack(A);
	int i,temp,n;

	printf("———————元素进栈———————\n"); 
	printf("输入要进栈的元素数量(栈空间为10)：");
	scanf("%d", &n);
	while(n>10){
		printf("已经超出栈空间容量，请重新输入：");
		scanf("%d", &n);
	} 
	printf("开始进栈："); 
	for(i=0; i<n; i++){
		scanf("%d", &temp);
		push(A, temp);
	}
	printf("进栈结束");
	printf("\n—————当前栈内元素———————\n");
	display(A);//自顶向下显示堆栈中的元素
	printf("\n——————————————————\n"); 
	
	printf("输出当前栈顶的元素值并将其弹出栈\n");
	while(!is_empty(A)){
		if(A->curNumber < 0)break;
		printf("%d ", get_top(A));
		pop(A);
	}
	
	
	clearStack(A);
	free(A);
	return 0;
}

void iniStack(Stack *A){// 初始化堆栈
	A->curNumber = -1;
	A->List = (int*)malloc(10*sizeof(int));
}

void clearStack(Stack *A){//清空堆栈
	free(A->List);
}

void push(Stack * A, ELEMENT obj){//将元素obj压入堆栈的栈顶
	A->curNumber++;
	*((A->List)+A->curNumber)=obj;	
}

void pop(Stack * A){//将当前栈顶的元素弹出栈。要求：栈不为空
	if(!is_empty(A)) A->curNumber--;
}

ELEMENT get_top(Stack * A){//返回当前栈顶的元素值。要求：栈不为空
	if(!is_empty(A)) return *(A->List+A->curNumber);
}

int is_empty(Stack * A){//判断当前堆栈是否为空，空返回1，非空返回0
	if(A->curNumber>-1) return 0;
	else return 1;
}

void display(Stack * A){//自顶向下显示堆栈中的元素
	int i;
	if(A->curNumber>-1){
		for(i=A->curNumber;i>=0;i--){
			printf("%d ",*(A->List+i));
		}		
	}
}
//网上找的，改了一些，依然还是有些不会，还要理解下
