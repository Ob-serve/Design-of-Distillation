#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define g 9.81
#define RR 8.314

void PRINT(float x,char name[],char unit[])       /*输出数据格式*/
{
    printf((fabs(x)>=0.01&&fabs(x)<1000)?("%s=%10.5f %s"):("%s=%10.3e %s"),name,x,unit);
}

float density_LA(float t)   /*丙烯液相密度-温度表*/
{
    float a[6]={285,300,315,330,345,365};
    float b[6]={535,509,481,443,390,233};
    int i;
    t+=273.15;
    for(i=0;i<5;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("密度不在已知范围内！\n");
    exit(0);
}

float density_LB(float t)   /*丙烷液相密度-温度表*/
{
    float a[5]={291.83,317.42,330.70,351.23,359.61};
    float b[5]={504,460,434,381,347};
    int i;
    t+=273.15;
    for(i=0;i<4;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("密度不在已知范围内！\n");
    exit(0);
}

float density_water(float t)   /*液态水密度-温度表*/
{
    float a[4]={50,60,70,80};
    float b[4]={988.1,983.2,977.8,971.8};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("密度不在已知范围内！\n");
    exit(0);
}

float surface_tension_LB(float t)   /*丙烷液相表面张力-温度表*/
{
    float a[3]={40,50,60};
    float b[3]={5.268,4.173,3.124};
    int i;
    for(i=0;i<2;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("表面张力不在已知范围内！\n");
    exit(0);
}

float vaporization_heat_LA(float t)   /*丙烯液相摩尔汽化热(kJ/mol)-温度表*/
{
    float a[4]={20,40,60,80};
    float b[4]={14.356,12.698,10.567,7.264};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("汽化热不在已知范围内！\n");
    exit(0);
}

float vaporization_heat_LB(float t)   /*丙烷液相摩尔汽化热(kJ/mol)-温度表*/
{
    float a[4]={30,40,50,60};
    float b[4]={14.49,13.61,12.60,11.39};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("汽化热不在已知范围内！\n");
    exit(0);
}

float vaporization_heat_water(float t)   /*水质量汽化热(kJ/kg)-温度表*/
{
    float a[7]={55,60,65,70,75,80,85};
    float b[7]={2366.4,2355.1,2343.4,2331.2,2319.5,2307.8,2295.2};
    int i;
    for(i=0;i<6;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("汽化热不在已知范围内！\n");
    exit(0);
}

float heat_capacity_LA(float t)   /*丙烯液相比热容(kJ/(kg*K))-温度表*/
{
    float a[5]={285,300,315,330,345};
    float b[5]={2.72,2.85,3.10,3.40,3.77};
    int i;
    t+=273.15;
    for(i=0;i<4;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("比热容不在已知范围内！\n");
    exit(0);
}

float heat_capacity_LB(float t)   /*丙烷液相比热容(kJ/(kg*K))-温度表*/
{
    float a[5]={291.83,317.42,330.70,351.23,359.61};
    float b[5]={2.58,2.78,3.27,4.27,6.62};
    int i;
    t+=273.15;
    for(i=0;i<4;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("比热容不在已知范围内！\n");
    exit(0);
}

//float heat_capacity_water(float t)   /*液态水比热容(kJ/(kg*K))-温度表*/
/*{
    float a[5]={50,60,70,80,90};
    float b[5]={4.174,4.178,4.187,4.195,4.208};
    int i;
    for(i=0;i<4;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("比热容不在已知范围内！\n");
    exit(0);
}*/

float viscosity_LA(float t)   /*丙烯液相黏度(mPa*s)-温度表*/
{
    float a[5]={30,40,50,60,80};
    float b[5]={0.076,0.066,0.055,0.046,0.031};
    int i;
    for(i=0;i<4;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("黏度不在已知范围内！\n");
    exit(0);
}

float viscosity_LB(float t)   /*丙烷液相黏度(mPa*s)-温度表*/
{
    float a[4]={20,40,60,80};
    float b[4]={0.102,0.082,0.065,0.050};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("黏度不在已知范围内！\n");
    exit(0);
}

float viscosity_VB(float t)   /*丙烷气相黏度(mPa*s)-温度表*/
{
    float a[3]={25,50,75};
    float b[3]={0.00811,0.00878,0.00942};
    int i;
    for(i=0;i<2;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("黏度不在已知范围内！\n");
    exit(0);
}

float viscosity_water(float t)   /*液态水黏度(mPa*s)-温度表*/
{
    float a[7]={55,60,65,70,75,80,85};
    float b[7]={0.5064,0.4688,0.4355,0.4061,0.3799,0.3565,0.3355};
    int i;
    for(i=0;i<6;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("黏度不在已知范围内！\n");
    exit(0);
}

float heat_conductivity_LA(float t)   /*丙烯液相热导率(W/(m*K))-温度表*/
{
    float a[4]={20,40,60,80};
    float b[4]={0.09163,0.08577,0.07991,0.07071};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("热导率不在已知范围内！\n");
    exit(0);
}

float heat_conductivity_LB(float t)   /*丙烷液相热导率(W/(m*K))-温度表*/
{
    float a[4]={20,40,60,80};
    float b[4]={0.09121,0.08535,0.07950,0.07196};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("热导率不在已知范围内！\n");
    exit(0);
}

float heat_conductivity_water(float t)   /*液态水热导率(W/(m*K))-温度表*/
{
    float a[4]={50,60,70,80};
    float b[4]={0.648,0.659,0.668,0.675};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("热导率不在已知范围内！\n");
    exit(0);
}

float boiling_point_A(float p)   /*丙烯沸点-压强表*/
{
    float a[4]={1.210,1.710,2.410,3.190};
    float b[4]={300,315,330,345};
    int i;
    for(i=0;i<3;i++)
    {
        if(p>=a[i]&&p<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(p-a[i])-273.15;
    }
    printf("沸点不在已知范围内！\n");
    exit(0);
}

float boiling_point_B(float p)   /*丙烷沸点-压强表*/
{
    float a[3]={1.520,2.026,3.039};
    float b[3]={317.42,330.70,351.23};
    int i;
    for(i=0;i<2;i++)
    {
        if(p>=a[i]&&p<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(p-a[i])-273.15;
    }
    printf("沸点不在已知范围内！\n");
    exit(0);
}

float vapour_pressure_water(float t)   /*水饱和蒸气压-温度表*/
{
    float a[7]={55,60,65,70,75,80,85};
    float b[7]={0.015743,0.019923,0.025014,0.031164,0.038551,0.047379,0.057875};
    int i;
    for(i=0;i<6;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("饱和蒸气压不在已知范围内！\n");
    exit(0);
}

float constant_KAD(float t)   /*丙烯相平衡常数-温度表(p=pD约为17.0atm时)*/
{
    float a[3]={35.9,41.0,46.1};
    float b[3]={0.9,1.0,1.1};
    int i;
    for(i=0;i<2;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("平衡常数不在已知范围内！\n");
    exit(0);
}

float constant_KBD(float t)   /*丙烷相平衡常数-温度表(p=pD约为17.0atm时)*/
{
    float a[3]={36.3,42.5,47.0};
    float b[3]={0.8,0.9,1.0};
    int i;
    for(i=0;i<2;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("平衡常数不在已知范围内！\n");
    exit(0);
}

float constant_KAW(float t)   /*丙烯相平衡常数-温度表(p=pW约为17.5atm时)*/
{
    float a[6]={36.9,42.1,46.9,50.2,55.8,59.1};
    float b[6]={0.9,1.0,1.1,1.2,1.3,1.4};
    int i;
    for(i=0;i<5;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("平衡常数不在已知范围内！\n");
    exit(0);
}


float constant_KBW(float t)   /*丙烷相平衡常数-温度表(p=pW约为17.5atm时)*/
{
    float a[6]={37.6,43.4,48.0,52.0,56.9,61.9};
    float b[6]={0.8,0.9,1.0,1.1,1.2,1.3};
    int i;
    for(i=0;i<5;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(t-a[i]);
    }
    printf("平衡常数不在已知范围内！\n");
    exit(0);
}

float Smith_fit_C20(float h)   /*Smith关联图(C20-(HT-hL))列表(FLV=0.304时)*/
{
    float a[11]={0.05,0.10,0.15,0.20,0.25,0.30,0.35,0.40,0.45,0.50,0.55};
    float b[11]={0.0175,0.0213,0.0242,0.0280,0.0330,0.0405,0.0465,0.0557,0.0670,0.0740,0.0790};
    int i;
    for(i=0;i<10;i++)
    {
        if(h>=a[i]&&h<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(h-a[i]);
    }
    printf("C20因子不在已知范围内！\n");
    exit(0);
}

float flooding_load_CF(float HT)   /*泛点负荷因数关联图(CF-HT)列表(rhoV=39.4kg/m^3时)*/
{
    float a[4]={0.3,0.45,0.6,0.9};
    float b[4]={0.094,0.119,0.132,0.143};
    int i;
    for(i=0;i<3;i++)
    {
        if(HT>=a[i]&&HT<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(HT-a[i]);
    }
    printf("泛点负荷因数CF不在已知范围内！\n");
    exit(0);
}

int D_HT_Correcting(float D,float HT)   /*塔径D与塔板间距HT经验关系表*/
{
    float a[5]={0.3,0.5,0.8,1.6,2.0};
    float b[5]={0.2,0.3,0.35,0.45,0.6};
    int i,tag=-1;
    for(i=0;i<4;i++)
    {
        if(D>=a[i]&&D<a[i+1]&&HT>=b[i]&&HT<b[i+1])
            {
                if(fabs((D-a[i])/(a[i+1]-a[i])-(HT-b[i])/(b[i+1]-b[i]))<0.7)
                    {
                        tag=1;
                        printf("塔径D与塔板间距HT符合经验关系\n");
                        PRINT(D,"塔径 D","m,  ");
                        PRINT(HT,"塔板间距 HT","m. \n");
                        return 1;
                    }
                tag=0;
                break;
            }
    }
    if(tag==-1)
    {
        PRINT(D,"塔径 D","m,  ");
        PRINT(HT,"塔板间距 HT","m. \n");
        printf("塔径D与塔板间距HT不符合经验关系！需重新假设HT\n");
        return 0;
    }
    if(tag==0)
    {
        PRINT(D,"塔径 D","m,  ");
        PRINT(HT,"塔板间距 HT","m. \n");
        printf("塔径D与塔板间距HT符合经验关系，但在经验关系的边缘区！需重新假设HT\n");
        return 0;
    }
}


float diameter_fit_T(float D)    /*塔径圆整*/
{
    switch((int)(10*D))
    {
        case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 12:case 14:case 16:case 18:case 20:
        return (int)(10*D)/10.0;
        case 11:case 13:case 15:case 17:case 19:
        return ((int)(10*D)+1)/10.0;
        default:printf("塔径不在已知范围内！\n");
        exit(0);
    }
}

float dew_point(float y,float t0,float *KAD,float *KBD)         /*塔顶计算露点*/
{
    float t,x1,x2,eps=-1;int i=0;
    printf("【计算露点开始】\n");
    t=t0-2;                    /*选取初值*/
    while(fabs(eps)>1e-3)
    {
        i++;
        t+=0.01;
        *KAD=constant_KAD(t);
        x1=y/(*KAD);
        *KBD=constant_KBD(t);
        x2=(1-y)/(*KBD);
        eps=x1+x2-1;
        printf("<第%d次结果>\n",i);    /*可不输出*/
        PRINT(t,"t","; ");    /*可不输出*/
        PRINT(*KAD,"KAD","; ");    /*可不输出*/
        PRINT(x1,"x1","; ");    /*可不输出*/
        PRINT(*KBD,"KBD","; ");    /*可不输出*/
        PRINT(x2,"x2",". \n");    /*可不输出*/
    }
    printf("【计算露点结束】(共计算%d次)\n",i);
    return t;
}

float bubbling_point(float x,float t0,float *KAW,float *KBW)         /*塔底、进料计算泡点*/
{
    float t,y1,y2,eps=-1;int i=0;
    printf("【计算泡点开始】\n");
    t=t0+2;                    /*选取初值*/
    while(fabs(eps)>1e-3)
    {
        i++;
        t-=0.01;
        *KAW=constant_KAW(t);
        y1=*KAW*x;
        *KBW=constant_KBW(t);
        y2=*KBW*(1-x);
        eps=y1+y2-1;
        printf("<第%d次结果>\n",i);    /*可不输出*/
        PRINT(t,"t","; ");    /*可不输出*/
        PRINT(*KAW,"KAW","; ");    /*可不输出*/
        PRINT(y1,"y1","; ");    /*可不输出*/
        PRINT(*KBW,"KBW","; ");    /*可不输出*/
        PRINT(y2,"y2",". \n");    /*可不输出*/
    }
    printf("【计算泡点结束】(共计算%d次)\n",i);
    return t;
}

float plate_number(float xD,float xW,float xF,float pD,float *pW,float *tW,float ET,int *NTF,float rhoL_D,float *alpha,float alphaD,float R_Rmin,float *R,float *Rmin,float qnD,float qnF,float q,float *qnL_D,float *qnV_D,float *qnL,float *qnV)      /*计算理论塔板数*/
{
    float alphaW,KAW,KBW,tb_B,x,y;
    int NT1,NT2=109,i=0;
    printf("【计算理论塔板数开始】\n");
    do
    {
        i++;
        printf("<第%d次计算>\n",i);
        NT1=NT2;
        printf("【计算塔底参数】\n");
        *pW=pD+rhoL_D*g*0.1*NT1/ET*1e-6;
        PRINT(*pW,"塔底压力 pW","MPa \n");
        tb_B=boiling_point_B(*pW);      /*丙烷沸点，用于计算泡点的初值*/
        *tW=bubbling_point(xW,tb_B,&KAW,&KBW);
        PRINT(*tW,"塔底温度 tW","°C \n");
        alphaW=KAW/KBW;
        PRINT(alphaW,"塔底相对挥发度 alphaW","\n");
        *alpha=(alphaD+alphaW)/2;
        PRINT(*alpha,"全塔平均相对挥发度 alpha","\n");
        *Rmin=1/(*alpha-1)*(xD/xF-*alpha*(1-xD)/(1-xF));
        *R=*Rmin*R_Rmin;
        *qnL_D=*R*qnD;
        *qnV_D=(*R+1)*qnD;    /*或qnV_D=qnL_D+qnD*/
        *qnL=*qnL_D+q*qnF;
        *qnV=*qnV_D+(q-1)*qnF;    /*或qnV=qnL-qnW*/
        PRINT(*Rmin,"最小回流比 Rmin","\n");
        PRINT(*R,"回流比 R","\n");
        PRINT(*qnL_D,"塔顶液相摩尔流量 qnL","kmol/h \n");
        PRINT(*qnV_D,"塔顶气相摩尔流量 qnV","kmol/h \n");
        PRINT(*qnL,"塔底液相摩尔流量 qnL\'","kmol/h \n");
        PRINT(*qnV,"塔底气相摩尔流量 qnV\'","kmol/h \n");
        printf("<第%d次逐板计算结果>\n",i);
        NT2=1;
        y=xD;
        x=y/(*alpha-(*alpha-1)*y);
        PRINT(y,"y001",",  ");PRINT(x,"x001",";  ");
        while(x>xF)
        {
            NT2++;
            y=*R/(*R+1)*x+xD/(*R+1);
            x=y/(*alpha-(*alpha-1)*y);
            printf("y%03d",NT2);PRINT(y,"",",  ");printf("x%03d",NT2);PRINT(x,"",";  ");    /*可不输出*/
            if(NT2%5==0) printf("\n");    /*可不输出*/
        }
        *NTF=NT2;
        while(x>xW)
        {
            NT2++;
            y=*qnL/(*qnV)*x-(qnF-qnD)/(*qnV)*xW;
            x=y/(*alpha-(*alpha-1)*y);
            printf("y%03d",NT2);PRINT(y,"",",  ");printf("x%03d",NT2);PRINT(x,"",";  ");    /*可不输出*/
            if(NT2%5==0) printf("\n");    /*可不输出*/
        }
        if(NT2%5!=0) printf("\n");
        NT2--;
        printf("NT1=%d, NT2=%d, NTF=%d. \n",NT1,NT2,*NTF);
    }while(NT2!=NT1);
    printf("【计算理论塔板数结束】(共计算%d次)\n",i);
    return NT2;
}

void tray_spacing(float *HT,float FLV,float u_uf,float *u,float *uf,float Ad_AT,float *D,float *AT,float*A,float hL,float sigmaL,float qVVs,float rhoL,float rhoV)     /*确定塔板间距*/
{
    int i=0,tag=0;
    float C20,C,D0;
    printf("【确定塔板间距开始】\n");
    do
    {
        i++;
        printf("<第%d次计算>\n",i);
        printf("选取HT(m)=[input]");
        scanf("%f",HT);
        C20=Smith_fit_C20(*HT-hL);
        C=C20*pow(sigmaL/20,0.2);
        *uf=C*sqrt((rhoL-rhoV)/rhoV);
        *u=*uf*u_uf;
        *A=qVVs/(*u);
        *AT=*A/(1-Ad_AT);
        D0=sqrt(4*(*AT)/PI);
        *D=diameter_fit_T(D0);
        printf("<第%d次计算结果>\n",i);
        PRINT(*HT,"HT","m, ");
        PRINT(C20,"C20",", ");
        PRINT(C,"C",", ");
        PRINT(*uf,"uf","m/s, ");
        PRINT(*u,"u","m/s, ");
        PRINT(*A,"A","m^2, ");
        PRINT(*AT,"AT","m^2, ");
        PRINT(D0,"D0","m, ");
        PRINT(*D,"D","m. \n");
        tag=D_HT_Correcting(*D,*HT);
        if(tag==1)
        {
            printf("是[0]否[1]要重新计算：[input]");
            scanf("%d",&tag);
        }
    }while(tag==0);
    printf("【确定塔板间距结束】(共计算%d次)\n",i);
}

float hole_distant(float t)    /*确定浮阀孔中心距*/
{
    float a[4]={0.075,0.100,0.125,0.150};
    int i;
    for(i=0;i<3;i++)
    {
        if(t>=a[i]&&t<a[i+1])
            if((t-a[i])<(a[i+1]-t))
                return a[i];
            else return a[i+1];
    }
    printf("浮阀孔中心距不在已知范围内！\n");
    exit(0);
}

float Fair_fit(float G,float Xtt)    /*Fair垂直管内流型图在给定的lg(Gh)下,对a-lg(1/Xtt)列表*/
{
    float y=log10(G*3600),x=log10(1/Xtt);
    float xA[6]={0.48,0.65,0.76,0.89,1.06,1.20};
    float xB[6]={-0.70,-0.60,-0.50,-0.38,-0.27,-0.13};
    float yA=4.8,yB=6.2;
    float a[6];
    float b[6]={1.0,0.8,0.6,0.4,0.2,0.1};
    int i;
    PRINT(y,"lg(Gh)","\n");
    PRINT(x,"lg(1/Xtt)","\n");
    for(i=0;i<5;i++)
        a[i]=xA[i]+(xB[i]-xA[i])/(yB-yA)*(y-yA);
    for(i=0;i<5;i++)
    {
        if(x>=a[i]&&x<a[i+1])
            return b[i]+(b[i+1]-b[i])/(a[i+1]-a[i])*(x-a[i]);
    }
    if(x<a[0]) return 1.0;
    if(x>=a[5]) return 0;
    printf("数据出错！\n");
    exit(0);
}

int diameter_fit_R(float Ds)    /*圆整再沸器壳体内径*/
{
    int i;
    for(i=400;i<2000;i+=100)
    {
        if(Ds>i&&Ds<=i+100)
            return i+100;
    }
    printf("再沸器壳体内径不在已知范围内！\n");
    exit(0);
}

int pipe_diameter_max_out(float Ds)    /*确定壳程最大接管直径*/
{
    int a[8]={400,600,800,1000,1200,1400,1600,1800};
    int b[8]={100,100,125,150,200,250,300,300};
    int i;
    for(i=0;i<7;i++)
    {
        if(Ds>=a[i]&&Ds<a[i+1])
            if((Ds-a[i])<(a[i+1]-Ds))
                return b[i];
            else return b[i+1];
    }
    printf("最大接管直径不在已知范围内！\n");
    exit(0);
}

int pipe_diameter_max_in(float Ds)    /*确定管程最大接管直径*/
{
    int a[8]={400,600,800,1000,1200,1400,1600,1800};
    int b[8]={200,250,350,400,450,450,500,500};
    int i;
    for(i=0;i<7;i++)
    {
        if(Ds>=a[i]&&Ds<a[i+1])
            if((Ds-a[i])<(a[i+1]-Ds))
                return b[i];
            else return b[i+1];
    }
    printf("最大接管直径不在已知范围内！\n");
    exit(0);
}

float xe_Correcting(float qmV,float di,float do_,float N,float rL,float cpL,float etaL,float lambdaL,float qmo,float rhoo,float etao,float lambdao,float etaV,float rhoV,float rhoL,float pW,float sigmaL,float deltat_deltap,float deltatm,float Di1,float Di5,float Ap,float PHIR,float L)      /*试差确定循环流量xe,并计算传热系数、循环推动力和循环阻力*/
{
    float xe=0.255,qmt,G,Rei,Pri,hi,Mo,Reo,ho_,Ri=0.176*1e-3,Ro=0.09*1e-3,RW=0.002/45,dm=(0.025+0.021)/2,KL;   /*xe为初值*/
    float hiE,htp,a,hnb,Ftp,hi_,Xtt_xe,Xtt_0_4xe,Xtt_0_33xe,x,aE,a_,KE,KC,LBC_L,LBC,LCD,AC,H;
    float deltapD,rhotp_,rhotp,RL_0_33xe,RL_xe,l;
    float deltapf,deltap1,deltap2,deltap3,deltap4,deltap5,deltapV3,deltapL3,deltapV5,deltapL5;
    float lambda1,L1,G1,Re1,lambda2,lambdaV3,GV3,ReV3,lambdaL3,GL3,ReL3,xi,G5,L5,lambdaV5,GV5,ReV5,lambdaL5,GL5,ReL5;
    int i=0;
    printf("【确定出口气含率开始】\n");
    do
    {
        i++;xe-=0.005;                /*可改*/
        printf("<第%d次计算>\n",i);
        PRINT(xe,"出口气含率 xe"," \n");
        
        printf("【传热能力核算】\n");
		qmt=qmV/xe;
		PRINT(qmt,"釜液循环质量流量 qmt","kg/s \n");
        printf("【计算显热段管内表面传热系数】\n");
        G=qmt/(PI/4*di*di*N);
        Rei=di*G/(etaL*1e-3);
        Pri=(cpL*1e3)*(etaL*1e-3)/lambdaL;
        hi=0.023*lambdaL/di*pow(Rei,0.8)*pow(Pri,0.4);
        PRINT(G,"釜液质量流速 G","kg/(m^2*s) \n");
        PRINT(Rei,"雷诺数 Rei"," \n");
        PRINT(Pri,"普朗特数 Pri"," \n");
        PRINT(hi,"显热段管内表面传热系数 hi","W/(m^2*K) \n");
        
        printf("【计算显热段壳程蒸汽冷凝表面传热系数】\n");
        Mo=qmo/(PI*do_*N);
        Reo=4*Mo/(etao*1e-3);
        ho_=1.88*pow(Reo,-1/3.0)*pow(pow(rhoo,2)*g*pow(lambdao,3)/pow(etao*1e-3,2),1/3.0);
        PRINT(Mo,"Mo","kg/(m*s) \n");
        PRINT(Reo,"雷诺数 Reo"," \n");
        PRINT(ho_,"显热段壳程蒸汽冷凝表面传热系数 ho","W/(m^2*K) \n");
        
        printf("【计算显热段总传热系数】\n");
        KL=1/((Ri+1/hi)*do_/di+RW*do_/dm+Ro+1/ho_);
        PRINT(KL,"显热段总传热系数 KL","W/(m^2*K) \n");
        
        printf("【计算蒸发段管内两相对流表面传热系数】\n");
        x=0.4*xe;
        Xtt_0_4xe=pow((1-x)/x,0.9)*pow(rhoV/rhoL,0.5)*pow(etaL/etaV,0.1);
        Ftp=3.5*pow(1/Xtt_0_4xe,0.5);
        hi_=0.023*lambdaL/di*pow(Rei*(1-x),0.8)*pow(Pri,0.4);
        htp=Ftp*hi_;
        PRINT(x,"0.4xe"," \n");
        PRINT(Xtt_0_4xe,"Xtt_0.4xe"," \n");
        PRINT(Ftp,"Ftp"," \n");
        PRINT(hi_,"以液体单独存在为基础求得的管内表面传热系数 hi\'","W/(m^2*K) \n");
        PRINT(htp,"蒸发段管内两相对流表面传热系数 htp","W/(m^2*K) \n");
        
        printf("【计算蒸发段管内泡核沸腾表面传热系数】\n");
        hnb=0.225*lambdaL/di*pow(Pri,0.69)*pow(PHIR*di/(Ap*rL*(etaL*1e-3)),0.69)*pow(rhoL/rhoV-1,0.33)*pow(pW*1e6*di/(sigmaL*1e-3),0.31);
        PRINT(hnb,"蒸发段管内泡核沸腾表面传热系数 hnb","W/(m^2*K) \n");
        
        printf("【计算蒸发段管内泡核沸腾修正因数】\n");
        x=xe;
        Xtt_xe=pow((1-x)/x,0.9)*pow(rhoV/rhoL,0.5)*pow(etaL/etaV,0.1);
        aE=Fair_fit(G,Xtt_xe);
        a_=Fair_fit(G,Xtt_0_4xe);
        a=(aE+a_)/2;
        PRINT(Xtt_xe,"Xtt_xe"," \n");
        PRINT(aE,"aE"," \n");
        PRINT(a_,"a\'"," \n");
        PRINT(a,"蒸发段管内泡核沸腾修正因数 a"," \n");
        
        printf("【计算蒸发段管内沸腾表面传热系数】\n");
        hiE=htp+a*hnb;
        PRINT(hiE,"蒸发段管内沸腾表面传热系数 hiE","W/(m^2*K) \n");
        
        printf("【计算蒸发段总传热系数】\n");
        KE=1/((Ri+1/hiE)*do_/di+RW*do_/dm+Ro+1/ho_);
        PRINT(KE,"蒸发段总传热系数 KE","W/(m^2*K) \n");
        
        printf("【计算显热段和蒸发段长度】\n");
        LBC_L=deltat_deltap/(deltat_deltap+PI*di*N*KL*deltatm/(cpL*1e3*rhoL*qmt));
        LBC=LBC_L*L;
        LCD=L-LBC;
        PRINT(LBC_L,"LBC/L"," \n");
        PRINT(LBC,"显热段长度 LBC","m \n");
        PRINT(LCD,"蒸发段长度 LCD","m \n");
        
        printf("【计算平均传热系数】\n");
        KC=(KL*LBC+KE*LCD)/L;
        PRINT(KC,"平均传热系数 KC","W/(m^2*K) \n");
        
        printf("【计算面积裕度】\n");
        AC=PHIR*1e3/(KC*deltatm);
        H=(Ap-AC)/AC;
        PRINT(AC,"计算传热面积 AC","m^2 \n");
        PRINT(H,"面积裕度 H"," \n");
        
        printf("【循环流量校核】\n");
        printf("【计算循环推动力】\n");
        x=xe/3;
        Xtt_0_33xe=pow((1-x)/x,0.9)*pow(rhoV/rhoL,0.5)*pow(etaL/etaV,0.1);
        l=1.02;
        RL_xe=Xtt_xe/pow(Xtt_xe*Xtt_xe+21*Xtt_xe+1,0.5);
        RL_0_33xe=Xtt_0_33xe/pow(Xtt_0_33xe*Xtt_0_33xe+21*Xtt_0_33xe+1,0.5);
		rhotp_=rhoV*(1-RL_xe)+rhoL*RL_xe;
		rhotp=rhoV*(1-RL_0_33xe)+rhoL*RL_0_33xe;
        deltapD=(LCD*(rhoL-rhotp_)-l*rhotp)*g;
        PRINT(x,"xe/3"," \n");
        PRINT(Xtt_0_33xe,"Xtt_xe/3"," \n");
        PRINT(RL_xe,"RL_xe"," \n");
        PRINT(RL_0_33xe,"RL_xe/3"," \n");
        PRINT(rhotp_,"rhotp_","kg/m^3 \n");
        PRINT(rhotp,"rhotp","kg/m^3 \n");
        PRINT(deltapD,"deltapD","Pa \n");
        
        printf("【计算循环总阻力】\n");
        printf("【1.管程进口管阻力】\n");
        G1=qmt/(PI/4*Di1*Di1);
        Re1=Di1*G1/(etaL*1e-3);
        lambda1=0.01277+0.7543/pow(Re1,0.38);
        L1=pow(Di1/0.0254,2)/0.3426/(Di1/0.0254-0.1914);
        deltap1=lambda1*L1/Di1*G1*G1/2/rhoL;
        PRINT(G1,"质量流速 G1","kg/(m^2*s) \n");
        PRINT(Re1,"雷诺数 Re1"," \n");
        PRINT(lambda1,"摩擦系数 lambda1"," \n");
        PRINT(L1,"当量长度 L1","m \n");
        PRINT(deltap1,"阻力 deltap1","Pa \n");
        
        printf("【2.传热管显热段阻力】\n");
        lambda2=0.01277+0.7543/pow(Rei,0.38);
        deltap2=lambda2*LBC/di*G*G/2/rhoL;
        PRINT(lambda2,"摩擦系数 lambda2"," \n");
        PRINT(deltap2,"阻力 deltap2","Pa \n");
        
        printf("【3.传热管蒸发段阻力】\n");
        GV3=2/3.0*xe*G;
        ReV3=di*GV3/(etaV*1e-3);
        lambdaV3=0.01277+0.7543/pow(ReV3,0.38);
        deltapV3=lambdaV3*LCD/di*GV3*GV3/2/rhoV;
        GL3=G-GV3;
        ReL3=di*GL3/(etaL*1e-3);
        lambdaL3=0.01277+0.7543/pow(ReL3,0.38);
        deltapL3=lambdaL3*LCD/di*GL3*GL3/2/rhoL;
        deltap3=pow(pow(deltapV3,1/4.0)+pow(deltapL3,1/4.0),4);
        PRINT(GV3,"质量流速 GV3"," \n");
        PRINT(ReV3,"雷诺数 ReV3"," \n");
        PRINT(lambdaV3,"摩擦系数 lambdaV3"," \n");
        PRINT(deltapV3,"气相阻力 deltapV3"," \n");
        PRINT(GL3,"质量流速 GL3"," \n");
        PRINT(ReL3,"雷诺数 ReL3"," \n");
		PRINT(lambdaL3,"摩擦系数 lambdaL3"," \n");
        PRINT(deltapL3,"液相阻力 deltapL3"," \n");
        PRINT(deltap3,"阻力 deltap3"," \n");
        
        printf("【4.管程内因动量变化引起的阻力】\n");
        xi=pow((1-xe),2)/RL_xe+rhoL/rhoV*xe*xe/(1-RL_xe)-1;
        deltap4=G*G*xi/rhoL;
        PRINT(xi,"动量变化引起的阻力系数 xi"," \n");
        PRINT(deltap4,"deltap4","Pa \n");
        
        printf("【5.管程出口管阻力】\n");
        G5=qmt/(PI/4*Di5*Di5);
        GV5=xe*G5;
        L5=pow(Di5/0.0254,2)/0.3426/(Di5/0.0254-0.1914);
        ReV5=Di5*GV5/(etaV*1e-3);
        lambdaV5=0.01277+0.7543/pow(ReV5,0.38);
        deltapV5=lambdaV5*L5/Di5*GV5*GV5/2/rhoV;
        GL5=G5-GV5;
        ReL5=Di5*GL5/(etaL*1e-3);
        lambdaL5=0.01277+0.7543/pow(ReL5,0.38);
        deltapL5=lambdaL5*L5/Di5*GL5*GL5/2/rhoL;
        deltap5=pow(pow(deltapV5,1/4.0)+pow(deltapL5,1/4.0),4);
        PRINT(G5,"质量流速 G5","kg/(m^2*s) \n");
        PRINT(GV5,"质量流速 GV5","kg/(m^2*s) \n");
        PRINT(L5,"当量长度 L5","m \n");
        PRINT(ReV5,"雷诺数 ReV5"," \n");
        PRINT(lambdaV5,"摩擦系数 lambdaV5"," \n");
        PRINT(deltapV5,"气相阻力 deltapV5","Pa \n");
        PRINT(GL5,"质量流速 GL5","kg/(m^2*s) \n");
        PRINT(ReL5,"雷诺数 ReL5"," \n");
        PRINT(lambdaL5,"摩擦系数 lambdaL5"," \n");
        PRINT(deltapL5,"液相阻力 deltapL5","Pa \n");
        PRINT(deltap5,"阻力 deltap5","Pa \n");
    
    	printf("【总阻力】\n");
    	deltapf=deltap1+deltap2+deltap3+deltap4+deltap5;
    	PRINT(deltapf,"总阻力 deltapf","Pa \n");
    	PRINT((deltapD-deltapf)/deltapD,"(deltapD-deltapf)/deltapD","\n");
    }while((deltapD-deltapf)/deltapD>0.05||(deltapD-deltapf)/deltapD<0.01);
    printf("【确定出口气含率结束】(共计算%d次)\n",i);
    if(H<0.3)
    {
    	printf("面积裕度过小！\n");
    	exit(0);
	}
	return xe;
}

main()
{
    float q=1,xD=0.98,xW=0.02,xF=0.65,pD=1.72,pW,tD,tW,qnF=70,ET=0.6,R_Rmin=1.6,R,Rmin,tb_A;
    float MA=42.081,MB=44.096,MD,MW;
    float rhoLA,rhoLB,rhoL,rhoVA,rhoVB,rhoV,rhoLA_D,rhoLB_D,rhoL_D,sigmaL;
    float qmL_D,qmV_D,rhoVA_D,rhoVB_D,rhoV_D,ZA_D,ZB_D;
    float alphaD,alpha,KAD,KBD;
    float qnD,qmD,qVD,qnW,qmW,qVW,qnL_D,qnV_D,qnL,qmL,qVLs,qnV,qmV,qVVs;
    int NT,NTF,NP,NPF;
    float PHIR,pF,tF,KAF,KBF,MF,qmF,qVF,rhoLA_F,rhoLB_F,rhoL_F;
    float pcA=4.610,pcB=4.250,TcA=364.8,TcB=369.8,ZA,ZB;            /*T的单位为K*/
    float HT,FLV,u_uf=0.69,u,uf,Ad_AT,bd_D,lW_D=0.74,lW,D,Ad,AT,A,Aa,Ao,Ab;      /*u_uf，lW_D为预先设定值，需调整*/ 
    float bd,bs=0.075,bc=0.050,hb=0.045,hW,hOW,hL=0.08,eps0=0.5;               /*bs，bc，hb，hL为预先设定值*/ 
    float d_o=0.039,n,t,phi;
    float uo,ub,Fo=11,F11,F12,ZL,CF,hf,ho,hl,hsigma,uoc,Hd,hd,Hd_,phi_=0.5,tau,k,uo_,Fo_=5;    /*Fo为预先设定值*/
    
    float rLA,rLB,rL,cpLA,cpLB,cpL,etaLA,etaLB,etaL,etaV,lambdaLA,lambdaLB,lambdaL,deltat_deltap;
    float ro,rhoo,etao,lambdao;
    float deltatm=20,T,qmo,K=800,Ap,L=4.500,di=0.021,do_=0.025,b,Ds,Di1,Di5,xe;    /*do_为外径*/ /*deltatm，K，L，di，do_为预先设定值*/
    int N;     /*N即NT*/
    
    printf("***化工过程与设备课程设计——丙烯-丙烷精馏装置设计***\n");
    printf("【1 精馏塔塔底浮阀塔板设计】\n");
    PRINT(q,"进料热状态参数 q","\n");
    PRINT(xF,"进料组成 xF","\n");
    PRINT(xD,"塔顶组成 xD","\n");
    PRINT(xW,"釜液组成 xW","\n");
    PRINT(pD,"塔顶操作压力 pD(绝压，下同)","MPa \n");
    PRINT(qnF,"处理量 qnF","kmol/h \n");
    PRINT(ET,"总板效率 ET","\n");
    PRINT(R_Rmin,"回流比系数 R/Rmin","\n");
    
    printf("【物料衡算】\n");
    MD=xD*MA+(1-xD)*MB;
    MW=xW*MA+(1-xW)*MB;   /*气相、液相组成近似相等*/
    PRINT(MD,"塔顶平均摩尔质量 MD","kg/kmol \n");
    PRINT(MW,"塔底平均摩尔质量 MW","kg/kmol \n");
    qnD=qnF*((xF-xW)/(xD-xW));
    qmD=qnD*MD/3600;
    qnW=qnF*((xD-xF)/(xD-xW));
    qmW=qnW*MW/3600;
    PRINT(qnD,"塔顶采出摩尔流量 qnD","kmol/h \n");
    PRINT(qmD,"塔顶采出质量流量 qmD","kg/s \n");
    PRINT(qnW,"塔底采出摩尔流量 qnW","kmol/h \n");
    PRINT(qmW,"塔底采出质量流量 qmW","kg/s \n");
    
    printf("【计算塔顶参数】\n");
    tb_A=boiling_point_A(pD);      /*丙烯沸点，用于计算露点的初值*/
    tD=dew_point(xD,tb_A,&KAD,&KBD);
    PRINT(tD,"塔顶温度 tD","°C \n");
    alphaD=KAD/KBD;
    PRINT(alphaD,"塔顶相对挥发度 alphaD","\n");
    rhoLA_D=density_LA(tD);
    rhoLB_D=density_LB(tD);
    PRINT(rhoLA_D,"塔顶丙烯液相密度 rhoLA_D","kg/m^3 \n");
    PRINT(rhoLB_D,"塔顶丙烷液相密度 rhoLB_D","kg/m^3 \n");
    rhoL_D=1/((MA*xD/(MA*xD+MB*(1-xD)))*(1/rhoLA_D)+(MB*(1-xD)/(MA*xD+MB*(1-xD)))*(1/rhoLB_D));
    PRINT(rhoL_D,"塔顶液相密度 rhoL_D","kg/m^3 \n");
    qVD=qmD/rhoL_D;
    PRINT(qVD,"塔顶采出体积流量 qVD","m^3/s \n");
    
    printf("【计算塔底参数及理论塔板数】\n");
    NT=plate_number(xD,xW,xF,pD,&pW,&tW,ET,&NTF,rhoL_D,&alpha,alphaD,R_Rmin,&R,&Rmin,qnD,qnF,q,&qnL_D,&qnV_D,&qnL,&qnV);
    printf("理论塔板数 NT=%d\n",NT);
    NP=(int)(NT/ET);
    printf("实际塔板数 NP=%d\n",NP);
    NPF=(int)(NTF/ET+1);
    printf("实际进料位置 NPF=%d\n",NPF);
    
    printf("【热量衡算】\n");
    rLA=vaporization_heat_LA(tW);
    rLB=vaporization_heat_LB(tW);
    rL=(xW*rLA+(1-xW)*rLB)/MW*1e3;
    PRINT(rLA,"塔底丙烯液相摩尔汽化热 rLA","kJ/mol \n");
    PRINT(rLB,"塔底丙烷液相摩尔汽化热 rLB","kJ/mol \n");
    PRINT((xW*rLA+(1-xW)*rLB),"塔底液相摩尔汽化热 rLn","kJ/mol \n");
    PRINT(rL,"塔底液相汽化热 rL","kJ/kg \n");
    PHIR=qnV*(xW*rLA+(1-xW)*rLB)*1e3/3600;
    PRINT(PHIR,"再沸器热流量 PHIR","kW \n");
    
    printf("【计算进料参数】\n");
    pF=pD+NPF*rhoL_D*g*0.1*1e-6;
    tF=bubbling_point(xF,boiling_point_A(pF),&KAF,&KBF);    /*进料压力按塔底压力算*/
    PRINT(pF,"进料压力 pF","Mpa \n");
    PRINT(tF,"进料温度 tF","°C \n");
    MF=xF*MA+(1-xF)*MB;
    PRINT(MF,"进料平均摩尔质量 MF","kg/kmol \n");
    qmF=qnF*MF/3600;       /*或qmF=qmW+qmD*/
    PRINT(qmF,"进料质量流量 qmF","kg/s \n");
    rhoLA_F=density_LA(tF);
    rhoLB_F=density_LB(tF);
    PRINT(rhoLA_F,"进料丙烯液相密度 rhoLA_F","kg/m^3 \n");
    PRINT(rhoLB_F,"进料丙烷液相密度 rhoLB_F","kg/m^3 \n");
    rhoL_F=1/((MA*xF/(MA*xF+MB*(1-xF)))*(1/rhoLA_F)+(MB*(1-xF)/(MA*xF+MB*(1-xF)))*(1/rhoLB_F));
    PRINT(rhoL_F,"进料液相密度 rhoL_F","kg/m^3 \n");
    qVF=qmF/rhoL_F;
    PRINT(qVF,"进料体积流量 qVF","m^3/s \n");
    
    printf("【计算塔底其他参数】\n");
    rhoLA=density_LA(tW);
    rhoLB=density_LB(tW);
    PRINT(rhoLA,"塔底丙烯液相密度 rhoLA","kg/m^3 \n");
    PRINT(rhoLB,"塔底丙烷液相密度 rhoLB","kg/m^3 \n");
    rhoL=1/((MA*xW/(MA*xW+MB*(1-xW)))*(1/rhoLA)+(MB*(1-xW)/(MA*xW+MB*(1-xW)))*(1/rhoLB));
    PRINT(rhoL,"塔底液相密度 rhoL","kg/m^3 \n");
    qVW=qmW/rhoL;
    PRINT(qVW,"塔底采出体积流量 qVW","m^3/s \n");
    qmL=qnL*MW/3600;
    qVLs=qmL/rhoL;
    qmV=qnV*MW/3600;    /*或qmV=qmL-qmW*/
    PRINT(qmL,"塔底液相质量流量 qmL\'","kg/s \n");
    PRINT(qVLs,"塔底液相体积流量 qVLs\'","m^3/s \n");
    PRINT(qmV,"塔底气相质量流量 qmV\'","kg/s \n");
    PRINT(pW/pcA,"查Z-pr-Tr图得：prA",", ");PRINT((tW+273.15)/TcA,"TrA","时，压缩因子 ZA=0.78\n");     /*查表*/
    PRINT(pW/pcB,"查Z-pr-Tr图得：prB",", ");PRINT((tW+273.15)/TcB,"TrB","时，压缩因子 ZB=0.75\n");     /*查表*/
    ZA=0.78;ZB=0.75;
    rhoVA=pW*1e3*MA/(ZA*RR*(tW+273.15));
    rhoVB=pW*1e3*MB/(ZB*RR*(tW+273.15));
    PRINT(rhoVA,"塔底丙烯气相密度 rhoVA","kg/m^3 \n");
    PRINT(rhoVB,"塔底丙烷气相密度 rhoVB","kg/m^3 \n");
    rhoV=1/((MA*xW/(MA*xW+MB*(1-xW)))*(1/rhoVA)+(MB*(1-xW)/(MA*xW+MB*(1-xW)))*(1/rhoVB));
    PRINT(rhoV,"塔底气相密度 rhoV","kg/m^3 \n");
    qVVs=qmV/rhoV;
    PRINT(qVVs,"塔底气相体积流量 qVVs\'","m^3/s \n");
    PRINT(qnL*MW/rhoL,"塔底液相小时体积流量 qVLh\'","m^3/h \n");
    PRINT(qnV*MW/rhoV,"塔底气相小时体积流量 qVVh\'","m^3/h \n");
    sigmaL=surface_tension_LB(tW);                /*近似为纯丙烷液相表面张力*/
    PRINT(sigmaL,"塔底液相表面张力 sigmaL","mN/m \n");
    
    printf("【计算塔顶其他参数】\n");
    qmL_D=qnL_D*MD/3600;
    qmV_D=qnV_D*MD/3600;    /*或qmV_D=qmL_D+qmD*/
    PRINT(qmL_D,"塔顶液相质量流量 qmL_D","kg/s \n");
    PRINT(qmV_D,"塔顶气相质量流量 qmV_D","kg/s \n");
    PRINT(pD/pcA,"查Z-pr-Tr图得：prA_D",", ");PRINT((tD+273.15)/TcA,"TrA_D","时，压缩因子 ZA_D=0.77\n");     /*查表*/
    PRINT(pD/pcB,"查Z-pr-Tr图得：prB_D",", ");PRINT((tD+273.15)/TcB,"TrB_D","时，压缩因子 ZB_D=0.73\n");     /*查表*/
    ZA_D=0.77;ZB_D=0.73;
    rhoVA_D=pD*1e3*MA/(ZA_D*RR*(tD+273.15));
    rhoVB_D=pD*1e3*MB/(ZB_D*RR*(tD+273.15));
    PRINT(rhoVA_D,"塔顶丙烯气相密度 rhoVA_D","kg/m^3 \n");
    PRINT(rhoVB_D,"塔顶丙烷气相密度 rhoVB_D","kg/m^3 \n");
    rhoV_D=1/((MA*xD/(MA*xD+MB*(1-xD)))*(1/rhoVA_D)+(MB*(1-xD)/(MA*xD+MB*(1-xD)))*(1/rhoVB_D));
    PRINT(rhoV_D,"塔顶气相密度 rhoV_D","kg/m^3 \n");
    
    printf("【确定塔板间距】\n");
    FLV=qmL/qmV*sqrt(rhoV/rhoL);
    PRINT(FLV,"两相流动参数 FLV"," \n");
    Ad_AT=(asin(lW_D)-lW_D*sqrt(1-pow(lW_D,2)))/PI;
    bd_D=(1-sqrt(1-pow(lW_D,2)))/2;
    PRINT(Ad_AT,"Ad/AT"," \n");
    PRINT(bd_D,"bd/D"," \n");
    tray_spacing(&HT,FLV,u_uf,&u,&uf,Ad_AT,&D,&AT,&A,hL,sigmaL,qVVs,rhoL,rhoV);
    
    printf("【计算圆整后塔径对应的参数】\n");
    AT=PI/4*D*D;
    A=AT*(1-Ad_AT);
    u=qVVs/A;
    u_uf=u/uf;
    PRINT(AT,"实际塔截面积 AT","m^2 \n");
    PRINT(A,"实际气体流通截面积 A","m^2 \n");
    PRINT(u,"实际塔底气相流速 u","m/s \n");
    PRINT(u_uf,"实际塔底泛点率 u/uf"," \n");
    
    printf("【计算降液管及溢流堰尺寸】\n");
    lW=lW_D*D;
    PRINT(lW,"堰长 lW","m \n");
    PRINT(qVLs*3600/lW,"溢流强度 qVLh/lW","m^3/(m*h) \n");
    if(qVLs*3600/lW>100)
    {
        printf("溢流强度不符合要求！\n");
        exit(0);
    }
    ub=qVLs/(lW*hb);
    PRINT(ub,"底隙液体流速 ub","m/s \n");
    if(ub>0.5)
    {
        printf("底隙液体流速不符合要求！\n");
        exit(0);
    }
    Ad=Ad_AT*AT;
    bd=bd_D*D;
    Aa=2*((D/2-bd-bs)*sqrt(pow(D/2-bc,2)-pow(D/2-bd-bs,2))+pow(D/2-bc,2)*asin((D/2-bd-bs)/(D/2-bc)));
    PRINT(Ad,"降液管截面积 Ad","m^2 \n");
    PRINT(bd,"堰宽 bd","m \n");
    PRINT(Aa,"有效传质区面积 Aa","m^2 \n");
    hOW=2.84*1e-3*1*pow(qVLs*3600/lW,2/3.0);
    PRINT(hOW,"堰上方液头高度 hOW","m \n");
    if(hOW<0.006)
    {
        printf("堰上方液头高度不符合要求！\n");
        exit(0);
    }
    hW=hL-hOW;
    PRINT(hW,"堰高 hW","m \n");
    
    printf("【浮阀数的确定】\n");
    uo=Fo/sqrt(rhoV);
    n=qVVs/(PI/4*d_o*d_o*uo);
    Ao=n*PI/4*d_o*d_o;
    t=d_o*sqrt(0.907*Aa/Ao);
    PRINT(uo,"初估阀孔气速 uo","m/s \n");
    PRINT(n,"初估浮阀数 n"," \n");
    PRINT(Ao,"初估开孔面积 Ao","m^2 \n");
    PRINT(t,"初估孔心距 t","m \n");
    PRINT(hole_distant(t)*1e3,"按孔心距 t","mm 进行布孔,得到实排浮阀数 n=[input]");
    scanf("%f",&n);
    Ao=n*PI/4*d_o*d_o;
    uo=qVVs/Ao;
    Fo=uo*sqrt(rhoV);
    phi=Ao/AT;
    PRINT(Ao,"开孔面积 Ao","m^2 \n");
    PRINT(uo,"阀孔气速 uo","m/s \n");
    PRINT(Fo,"阀孔动能因子 Fo"," \n");
    PRINT(phi,"开孔率 phi"," \n");
    
    printf("【液沫夹带量校核】\n");
    ZL=D-2*bd;
    Ab=AT-2*Ad;
    CF=flooding_load_CF(HT);
    F11=(qVVs*sqrt(rhoV/(rhoL-rhoV))+1.36*qVLs*ZL)/(Ab*CF);
    F12=qVVs*sqrt(rhoV/(rhoL-rhoV))/(0.78*AT*CF);
    PRINT(ZL,"液体横过塔板流动的行程 ZL","m \n");
    PRINT(Ab,"塔板上液流面积 Ab","m^2 \n");
    PRINT(CF,"泛点负荷因数 CF"," \n");
    PRINT(F11,"泛点率 F11"," \n");
    PRINT(F12,"泛点率 F12"," \n");
    if(F11>0.8||F12>0.8)
    {
        printf("泛点率不符合要求！\n");
        exit(0);
    }
    
    printf("【塔板阻力计算】\n");
    uoc=pow(73.12/rhoV,1/1.825);
    if(uo<uoc)
    {
        printf("uo<uoc，阀未全开\n");
        ho=19.9*pow(uo,0.175)/rhoL;
    }
    else
    {
        printf("uo>uoc，阀全开\n");
        ho=5.34*rhoV/rhoL*uo*uo/(2*g);
    }
    hl=eps0*hL;
    hsigma=4*1e-3*sigmaL/(rhoL*g*d_o);
    hf=ho+hl+hsigma;
    PRINT(uoc,"临界孔速 uoc","m/s \n");
    PRINT(ho,"干板阻力 ho","m \n");
    PRINT(hl,"塔板充气液层阻力 hl","m \n");
    PRINT(hsigma,"克服表面张力所造成的阻力 hsigma","m \n");
    PRINT(hf,"塔板阻力（相当的清液柱高度） hf","m \n");
    
    printf("【降液管液泛校核】\n");
    hd=1.18*1e-8*pow(qVLs*3600/(lW*hb),2);
    Hd=hW+hOW+hf+hd;
    Hd_=Hd/phi_;
    PRINT(hd,"液体通过降液管的流动阻力 hd","m \n");
    PRINT(Hd,"降液管中清液层高度 Hd","m \n");
    PRINT(Hd_,"降液管中泡沫层高度 Hd\'","m \n");
    if(Hd_>HT+hW)
    {
        printf("发生降液管液泛！\n");
        exit(0);
    }
    
    printf("【液体在降液管中停留时间校核】\n");
    tau=Ad*HT/qVLs;
    PRINT(tau,"液体在降液管中停留时间 tau","s \n");
    if(tau<5)
    {
        printf("液体在降液管中停留时间过短！\n");
        exit(0);
    }
    
    printf("【严重漏液校核】\n");
    uo_=Fo_/sqrt(rhoV);
    k=uo/uo_;
    PRINT(uo_,"漏液点气速 uo\'","m/s \n");
    PRINT(k,"稳定系数 k"," \n");
    if(k<2)
    {
        printf("发生严重漏液！\n");
        exit(0);
    }
    
    printf("【塔板负荷性能图】\n");
    printf("【1.过量液沫夹带线参数：(1)F11>F12时为 qVVh=a*qVLh+b ; (2)F12>F11时为 qVVh=c 】\n");
    if(F11>F12) 
    {
        PRINT(-1.36*ZL/sqrt(rhoV/(rhoL-rhoV)),"a"," \n");
        PRINT(0.8*3600/(sqrt(rhoV/(rhoL-rhoV))/(Ab*CF)),"b"," \n");
    }
    else PRINT(0.8*3600/(sqrt(rhoV/(rhoL-rhoV))/(0.78*AT*CF)),"c"," \n");
    printf("【2.液相下限线参数：qVLh=d 】\n");
    PRINT(3.07*lW,"d"," \n");
    printf("【3.严重漏夜线参数：qVVh=e 】\n");
    PRINT(3600*Ao*uo_,"e"," \n");
    printf("【4.液相上限线参数：qVLh=f 】\n");
    PRINT(720*Ad*HT,"f"," \n");
    printf("【5.降液管液泛线参数：qVVh=sqrt( g + h*qVLh^(2/3.0) + i*qVLh^2 ) 】\n");
    //a=3.40*1e-8*rhoV/rhoL/pow(n*d_o*d_o,2)
    //b=4.26*1e-3/pow(lW,2/3.0)
    //c=1.18*1e-8/pow(lW*hb,2)
    //d=phi_*HT+(phi_-1.5)*hW
    //g=d/a    h=-b/a    i=-c/a
    PRINT((phi_*HT+(phi_-1.5)*hW)/(3.40*1e-8*rhoV/rhoL/pow(n*d_o*d_o,2)),"g"," \n");
    PRINT(-(4.26*1e-3/pow(lW,2/3.0))/(3.40*1e-8*rhoV/rhoL/pow(n*d_o*d_o,2)),"h"," \n");
    PRINT(-(1.18*1e-8/pow(lW*hb,2))/(3.40*1e-8*rhoV/rhoL/pow(n*d_o*d_o,2)),"i"," \n");
    
    printf("【塔高计算】\n");
    PRINT(NP*HT+qVW*20*60/(PI/4*D*D)+(0.7-HT)+(0.8-HT)*(NP/15)+1.5*2+5,"塔高 Z","m \n");
    
    
    printf("【塔底再沸器设计】\n");
    printf("【计算再沸器管程流体物性】\n");
    cpLA=heat_capacity_LA(tW);
    cpLB=heat_capacity_LB(tW);
    cpL=(MA*xW/(MA*xW+MB*(1-xW)))*cpLA+(MB*(1-xW)/(MA*xW+MB*(1-xW)))*cpLB;
    PRINT(cpLA,"塔底丙烯液相比热容 cpLA","kJ/(kg*K) \n");
    PRINT(cpLB,"塔底丙烷液相比热容 cpLB","kJ/(kg*K) \n");
    PRINT(cpL,"塔底液相比热容 cpL","kJ/(kg*K) \n");
    etaLA=viscosity_LA(tW);
    etaLB=viscosity_LB(tW);
    etaL=pow(10,xW*log10(etaLA)+(1-xW)*log10(etaLB));
    etaV=viscosity_VB(tW);
    PRINT(etaLA,"塔底丙烯液相黏度 etaLA","mPa*s \n");
    PRINT(etaLB,"塔底丙烷液相黏度 etaLB","mPa*s \n");
    PRINT(etaL,"塔底液相黏度 etaL","mPa*s \n");
    PRINT(etaV,"塔底气相黏度 etaV","mPa*s \n");
    lambdaLA=heat_conductivity_LA(tW);
    lambdaLB=heat_conductivity_LB(tW);
    lambdaL=(MA*xW/(MA*xW+MB*(1-xW)))*lambdaLA+(MB*(1-xW)/(MA*xW+MB*(1-xW)))*lambdaLB;
    PRINT(lambdaLA,"塔底丙烯液相热导率 lambdaLA","W/(m*K) \n");
    PRINT(lambdaLB,"塔底丙烷液相热导率 lambdaLB","W/(m*K) \n");
    PRINT(lambdaL,"塔底液相热导率 lambdaL","W/(m*K) \n");
    deltat_deltap=g*tW*(MW*1e-3)/((xW*rLA+(1-xW)*rLB)*1e3*rhoV);
    PRINT(deltat_deltap,"塔底液相蒸汽压曲线斜率 deltat_deltap","K*m^2/kg \n");
    
    printf("【计算再沸器壳程流体物性】\n");
    T=tW+deltatm;
    PRINT(T,"壳程蒸汽温度 T","°C \n");
    PRINT(vapour_pressure_water(T)*1e3,"壳程蒸汽压力 P","kPa \n");
    ro=vaporization_heat_water(T);
    rhoo=density_water(T);
    etao=viscosity_water(T);
    lambdao=heat_conductivity_water(T);
    PRINT(ro,"蒸汽冷凝液汽化热 ro","kJ/kg \n");
    PRINT(rhoo,"蒸汽冷凝液密度 rhoo","kg/m^3 \n");
    PRINT(etao,"蒸汽冷凝液黏度 etao","mPa*s \n");
    PRINT(lambdao,"蒸汽冷凝液热导率 lambdao","W/(m*K) \n");
    
    printf("【估算再沸器尺寸】\n");
    qmo=PHIR/ro;
    PRINT(PHIR,"再沸器热流量 PHIR","kW \n");
    PRINT(qmo,"蒸汽质量流量 qmo","kg/s \n");
    PRINT(K,"设定传热系数 K","W/(m^2*K) \n");
    Ap=PHIR*1e3/(K*deltatm);
    PRINT(Ap,"估算再沸器传热面积 Ap","m^2 \n");
    PRINT(L,"设定管长 L","m \n");
    PRINT(di*1e3,"设定管内径 di","mm \n");
    PRINT(25,"设定管外径 do","mm \n");
    PRINT(32,"设定管心距 t","mm \n");
    N=(int)(Ap/(PI*do_*L));
    b=1.1*sqrt((float)N);
    Ds=32*(b-1)+2.5*do_*1e3;               /*Ds单位为mm*/
    printf("再沸器传热管根数 NT=%d \n",N);
    PRINT(b,"参数 b"," \n");
    PRINT(Ds,"圆整前壳体内径 Ds0","mm \n");
    Ds=(float)(diameter_fit_R(Ds));
    PRINT(Ds,"圆整后的壳体内径 Ds","mm \n");
    PRINT(L*1e3/Ds,"再沸器长径比 L/Ds"," \n");
    if(L*1e3/Ds>6||L*1e3/Ds<4)
    {
        printf("再沸器长径比不符合要求！\n");
        exit(0);
    }
    printf("壳程最大接管直径为 %d mm\n",pipe_diameter_max_out(Ds));
    printf("管程最大接管直径为 %d mm\n",pipe_diameter_max_in(Ds));
    printf("选取管程进口管直径 Di1(m)=[input]");
    scanf("%f",&Di1);
    printf("选取管程出口管直径 Di5(m)=[input]");
    scanf("%f",&Di5);
    
    printf("【试差确定出口气含率】\n");
    xe=xe_Correcting(qmV,di,do_,N,rL,cpL,etaL,lambdaL,qmo,rhoo,etao,lambdao,etaV,rhoV,rhoL,pW,sigmaL,deltat_deltap,deltatm,Di1,Di5,Ap,PHIR,L);
    PRINT(xe,"出口气含率 xe"," \n");
    
    
    
    
}


  












  
