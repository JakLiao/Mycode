#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <winbase.h>
#include <windows.h>

#define pi 3.1415926
#define POPSIZE 50//初始
#define AVEGENS 4000 //循环迭代的次数，即循环完后，重新在新的取值范围初始化群体
#define SUMNUM 1//程序运行的次数，即运行完一遍后接着在运行
#define MAXGENS 2000
#define NVARS 3//3个变量
#define PXOVER 0.9
#define PMUTATION 0.02
#define TRUE 1
#define FALSE 0

int generation;
double avebest[SUMNUM];//用来保存每次运行后的最佳值
int cur_best;
double s;
FILE *galog;
struct genotype
{double gene[NVARS];
 double fitness;
 double upper[NVARS];
 double lower[NVARS];
 double rfitness;
 double cfitness;
};
struct genotype population[POPSIZE+1];
struct genotype newpopulation[POPSIZE+1];

void initialize(void);
double randval(double,double);
void evaluate(void);
void keep_the_best(void);
void elitist(void);
void select(void);
void crossover(void);
void Xover(int,int);
void swap(int *,int *);
void mutate(void);
void report(void);
void DBtransferdouble(double *,double *);

/********************************************************/
/*double re1_f(double m,double t,double c,double w)
{
    double MR,RI,w1,h1,h2,re;
     w1=w*t;
     h1=pow(w1,c);
     h2=pow(w1,2*c);
     MR=m+m*h1*cos(pi*c/2);
     RI=1+2*h1*cos(pi*c/2)+h2;
     re=MR/RI;
     return re;

}
double im1_f(double m,double t,double c,double w)
{
    double MI,RI,w1,h1,h2,im;
     w1=w*t;
     h1=pow(w1,c);
     h2=pow(w1,2*c);
     MI=(-m)*h1*sin(pi*c/2);
     RI=1+2*h1*cos(pi*c/2)+h2;
     im=MI/RI;
     return im;

}
double re(double m1,double t1,double c1,double m2,double t2,double c2,double w)
{
    double temp1,temp2,re;
    temp1=re1_f(m1,t1,c1,w);
    temp2=re1_f(m2,t2,c2,w);
    re=1-m1-m2+temp1+temp2;
    return re;
}
double im(double m1,double t1,double c1,double m2,double t2,double c2,double w)
{
    double temp1,temp2,im;
    temp1=im1_f(m1,t1,c1,w);
    temp2=im1_f(m2,t2,c2,w);
    im=temp1+temp2;
    return im;
}*/
/********************************************************/
double f1(double m,double t,double c,double w)
{
     double h1,h2,w1,a,b,F;
     w1=w*t;
     h1=pow(w1,c);
     h2=pow(w1,2*c);
     a=(-m)*h1*sin(pi*c/2);
     b=(1+(2-m)*h1*cos(pi*c/2)+(1-m)*h2);
     F=(-1000)*atan(a/b);
     return F;
}
/******************************************************/

void initialize(void)
{
    if(generation==0)
    {
        int i,j;
        double lbound[NVARS],ubound[NVARS];
        lbound[0]=0;
        ubound[0]=1;
        lbound[1]=0;
        ubound[1]=100;
        lbound[2]=0;
        ubound[2]=1;
        /*lbound[3]=0;
        ubound[3]=1;
        lbound[4]=0;
        ubound[4]=100;
        lbound[5]=0;
        ubound[5]=1;*/

        for(i=0;i<NVARS;i++)
        {

            for(j=0;j<POPSIZE;j++)
            {
                population[j].fitness=0;
                population[j].rfitness=0;
                population[j].cfitness=0;
                population[j].lower[i]=lbound[i];
                population[j].upper[i]=ubound[i];
                population[j].gene[i]=randval(population[j].lower[i],population[j].upper[i]);
            }
        }
    }
    else
    {
        int i,j;
        double down, up;
        for(i=0;i<NVARS;i++)
        {
            down=population[0].lower[i]+(population[POPSIZE].gene[i]-population[0].lower[i])/3;
            up=population[0].upper[i]-(population[0].upper[i]-population[POPSIZE].gene[i])/3;
            for(j=0;j<POPSIZE;j++)
            {
                population[j].fitness=0;
                population[j].rfitness=0;
                population[j].cfitness=0;
                population[j].lower[i]=down;
                population[j].upper[i]=up;
                population[j].gene[i]=randval(population[j].lower[i],population[j].upper[i]);
            }
        }

    }
}

double randval(double low,double high)
{double val;
 val=((double)(rand()%10000)/10000.0)*(high-low)+low;//;//RAND_MAX//);//
 return(val);
}



//重点
void evaluate(void)
{
 int men;
 int i;
 double x[NVARS],F[26],F1[26],f[26],temp,temp1,w;
 for(men=0;men<POPSIZE;men++)
 {
     for (i=0;i<NVARS;i++)
       x[i]=population[men].gene[i];
       for(i=0;i<26;i++)
       {
         temp=-7+0.5*i;
         f[i]=pow(2,temp);
         w=2*pi*f[i];
         F[i]=f1(0.5,10,0.4,w);
         F1[i]=f1(x[0],x[1],x[2],w);
         temp1=(F[i]-F1[i]);
         population[men].fitness+=pow(temp1,2);
       }
       population[men].fitness= sqrt(population[men].fitness/26);

 }
}
void keep_the_best()
{int mem;
 int i;
 cur_best=0;

 for(mem=0;mem<POPSIZE;mem++)
  {if(population[mem].fitness<population[POPSIZE].fitness)
   {cur_best=mem;
    population[POPSIZE].fitness=population[mem].fitness;
   }
  }
  for(i=0;i<NVARS;i++)
population[POPSIZE].gene[i]=population[cur_best].gene[i];
}

void elitist()
{int i;
 double best,worst;
 int best_mem,worst_mem;
 best=population[0].fitness;
 worst=population[0].fitness;
 for(i=0;i<POPSIZE;i++)
  {if(population[i].fitness<population[i+1].fitness)
     {if(population[i].fitness=best)
    {best=population[i].fitness;
         best_mem=i;
        }
      if(population[i+1].fitness>=worst)
    {worst=population[i+1].fitness;
         worst_mem=i+1;
    }
     }
  else
   {if(population[i].fitness>=worst)
    {worst=population[i].fitness;
         worst_mem=i;
    }
      if(population[i+1].fitness=best)
    {best=population[i+1].fitness;
         best_mem=i+1;
    }
     }
  }
 if(best=population[POPSIZE].fitness)
  {for(i=0;i<NVARS;i++)
    population[POPSIZE].gene[i]=population[best_mem].gene[i];
   population[POPSIZE].fitness=population[best_mem].fitness;
  }
 else
  {for(i=0;i<NVARS;i++)
    population[worst_mem].gene[i]=population[POPSIZE].gene[i];
population[worst_mem].fitness=population[POPSIZE].fitness;
  }
}


void select(void)
{int mem,i,j;
 double sum=0;
 double p;

 for(mem=0;mem<POPSIZE;mem++)
  {sum+=population[mem].fitness;
  }
 for(mem=0;mem<POPSIZE;mem++)
  {population[mem].rfitness=population[mem].fitness/sum;
 }
 population[0].cfitness=population[0].rfitness;
for(mem=1;mem<POPSIZE;mem++)
 {population[mem].cfitness=population[mem-1].cfitness+
population[mem-1].rfitness;
}
for(i=0;i<POPSIZE;i++)
 {p=rand()%10000/10000.0;
  if(p<population[0].cfitness)
  {
      newpopulation[i]=population[0];

  }
  else
   {for(j=0;j<POPSIZE;j++)
     if(p>=population[j].cfitness&&p<population[j+1].cfitness)
     {
         newpopulation[i]=population[j+1];

     }
 }
}
for(i=0;i<POPSIZE;i++)
{
    population[i]=newpopulation[i];

}
}
void crossover(void)
{int mem,one;
 int first=0;
 double x;

 for(mem=0;mem<POPSIZE;++mem)
  {x=rand()%1000/1000.0;
   if(x<PXOVER)
  {++first;
   if(first%2==0)
    Xover(one,mem);
  else
   one=mem;
}
}
}


void Xover(int one,int two)
{int i,j;
 int point;
 j=1;
 point=NVARS-1;
 for(i=0;i=point;i++)

     {
         DBtransferdouble(&population[one].gene[i],&population[two].gene[i]);


     }

}
void DBtransferdouble(double *x,double *y)
{
    //线性交叉的方法
    double a,temp1,temp2;
    a=randval(-0.5,1.5);//(double)((rand()%10000)/10000.0);
    while(a==0.5) a=(double)((rand()%10000)/10000.0);
    temp1=*x;
    temp2=*y;
    *x=a*temp1+(1-a)*temp2;
    *y=a*temp2+(1-a)*temp1;


}
void swap(int *x,int *y)
{int temp;

temp=*x;
*x=*y;
*y=temp;
}

void mutate(void)
{int i,j,ver=0;
 double lbound,hbound;
 double x,k=0.7;

for(i=0;i<POPSIZE;i++)
 for(j=0;j<NVARS;j++)
 {x=rand()%1000/1000.0;
  if(x<PMUTATION)
 {lbound=population[i].lower[j];
  hbound=population[i].upper[j];
  for(;ver==0;)
  {

      if((double)((rand()%1000)/1000.0)=0.5)
          population[i].gene[j]=population[i].gene[j]+k*(hbound-population[i].gene[j])*
              (double)((rand()%10000)/10000.0);
      else  population[i].gene[j]=population[i].gene[j]-k*(population[i].gene[j]-lbound)*
               (double)((rand()%10000)/10000.0);
      if(population[i].gene[j]>=lbound&&population[i].gene[j]=hbound)
          ver=1;
  }
}
}
}

void report(void)
{
 double best_val;

 best_val=population[POPSIZE].fitness;

 fprintf(galog,"\n%5d,%6.4f\n",generation,best_val);
}

void main(void)
{int i,j;
 if((galog=fopen("galog.txt","w"))==NULL)
   {
     exit(1);
   }

for(i=0;i<SUMNUM;i++)
{
  generation=0;
  population[POPSIZE].fitness=1000;
  initialize();


 evaluate();
 keep_the_best();
  report();
while(generation<MAXGENS)
{

  generation++;
  if(generation%100==0)
 printf("%d\n",generation);

  select();

 crossover();
 mutate();

evaluate();
elitist();

 report();
}

for(j=0;j<NVARS;j++)
{fprintf(galog,"\n var(%d)=%3.4f",j,population[POPSIZE].gene[j]);
}
fprintf(galog,"\n\n Best fitness=%3.4f",population[POPSIZE].fitness);

}

}
