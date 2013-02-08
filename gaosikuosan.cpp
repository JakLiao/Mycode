#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define e 2.718281828459
#define PI 3.1415926
void qiuxy(char wending ,double x,double &dy,double &dz)
{
    switch(wending)
	{
	   case 'A': dy=0.22*x/(sqrt(1+0.0001*x)), dz=0.2*x; break;
	   case 'B': dy=0.16*x/(sqrt(1+0.0001*x)), dz=0.12*x; break;
	   case 'C': dy=0.11*x/(sqrt(1+0.0001*x)), dz=0.08*x/(sqrt(1+0.0002*x)); break;
	   case 'D': dy=0.08*x/(sqrt(1+0.0001*x)), dz=0.06*x/(sqrt(1+0.0015*x)); break;
	   case 'E': dy=0.06*x/(sqrt(1+0.0001*x)), dz=0.03*x/(1+0.0003*x); break;

	   case 'F': dy=0.04*x/(sqrt(1+0.0001*x)), dz=0.016*x/(1+0.0003*x); break;
	}
}

main()
{
    double c1,c2,x,z,t,p0,H,dx,dy,dz,a,s,k,I,Ts;
	char daqi;
	cout<<"请按以下格式输入："<<endl;
	cout<<"下风口L处坐标（米）："<<endl;
	cin>>x;
	cout<<"地点的纵坐标（米）："<<endl;
    cout<<"0 "<<endl;
    cout<<"地点的铅直坐标（米）："<<endl;
	cin>>z;
	cout<<"扩散时间（秒）："<<endl;
	cin>>t;
	cout<<"地面反射系数："<<endl;
	cin>>a;
    cout<<"放射性气体扩散速度（m/s）："<<endl;
	cin>>s;
	cin>>s;
	cin>>s;
	cin>>s;
	cin>>s;
	cout<<"风速（m/s）："<<endl;
	cin>>k;
    cout<<"雨水强度（毫米/小时）："<<endl;
	cin>>I;
	cout<<"核物质衰变周期（天）："<<endl;
    cin>>Ts;
    cout<<"初始浓度（千克/立方米）："<<endl;
	cin>>p0;
	cout<<"有效高度（米）："<<endl;
	cin>>H;
	cout<<"大气稳定度等级："<<endl;
	cin>>daqi;
	qiuxy(daqi,x,dy,dz);
	dx=dz;
    c1=p0/(2*PI*(s-k)*dy*dz)*pow(e,-(0.693*x)/(3600*(Ts*24)*(k+s))-(8*e-5*pow(I,0.6)*x)/(k+s))*(pow(e,-((z-H)+(0.01*x/(s-k)))*((z-H)+(0.01*x/(s-k)))/2*dz*dz)+a*pow(e,-(z+H+(0.01*x/(s-k)))*(z+H+(0.01*x/(s-k)))/(2*dz*dz)));
    cout<<"下风口L处放射性物质浓度= "<<c1<<endl;
	c2=p0/(2*PI*(s-k)*dy*dz)*pow(e,-(0.693*(-x))/(3600*(Ts*24)*(k+s))-(8*e-5*pow(I,0.6)*(-x))/(k+s))*(pow(e,-((z-H)+(0.01*(-x)/(s-k)))*((z-H)+(0.01*(-x)/(s-k)))/2*dz*dz)+a*pow(e,-(z+H+(0.01*(-x)/(s-k)))*(z+H+(0.01*(-x)/(s-k)))/(2*dz*dz)));
    cout<<"上风口-L处放射性物质浓度= "<<c2<<endl;
}

//-x*x/(4*dx*t)-y*y/(4*dy*t)
//-(z-H)*(z-H)/(4*dz*t)-a*(z+H)*(z+H)/(4*dz*t)
