#include<stdio.h>
#include<stdlib.h>
struct stack
{
   int top;
   int heights[18000];
};

void push(struct stack *s, int x)
{
   if(s->top==18000-1)
 {
   printf("\n stack overflow");
 }
 else
 {
   s->top=s->top+1;
   int top=s->top;
   s->heights[top]=x;
 }
}

int st_empty(struct stack *s)
{
    if  (s->top==-1)
    {
      return  1;
    }
   else
   {
     return 0;
   }
}

int pop(struct stack *s)
{
  int temp;
  if(s->top==-1)
 {
   printf("\n stack underflown");
 }
 else
 {
  int top=s->top;
  temp= s->heights[top];
  s->top=s->top-1;
  return temp;
 }
}

void print_sum(int a[], int n)
{
 int i=0,sum=0;
 struct stack s;
 s.top=-1;
 int element,next;
 push(&s,a[0]);
 for(i=1;i<n;i++)
 {
  next=a[i];
  if(st_empty(&s)==0)
  {
   element = pop(&s);
   while(element<next)
   {
    sum=(sum+next)%1000000001;
    if(st_empty(&s)==1)
    break;
    element=pop(&s);
   }
   if(element>next)
   push(&s,element);
  }
  push(&s,next);
 }
 while(st_empty(&s)==0)
  {
   element=pop(&s);
   next = 0;
   sum=(sum+next)%1000000001;
  }
  printf("\nsum= %d", sum);
}

int  main()
{
   int *a, n,next,i,t;
   printf("Enter the number of test cases : ");
   scanf("%d",&t);
   if(t<1||t>100)
   {
   	printf("Invalid input");
   	exit(0);
   }
 while(t!=0)
 
 {
    printf("\n Enter the number of towers : ");
    scanf("%d",&n);
    if(n<1||n>18000)
    {
    	printf("Invaid input");
    	exit(0);
	}
    a = (int *)malloc(n *sizeof(int));
    printf("Enter the heights of %d towers:",n);
    for(i=0;i<n;i++)
    
   {
   
      scanf("%d",&a[i]);
      if(a[i]<0||a[i]>100000)
    {
    	printf("Invalid input");
    	exit(0);
	}
    }
    
    printf("\n");
   	print_sum(a,n);
   	t--;                        
	
}
    return 0;
}
