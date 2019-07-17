#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//float años = pow(31.54,7);

double dxdt_x(double t_i, double x_i, double v_x);
double dvdt_x(double t_i, double x_i, double v_x);

double dxdt_y(double t_i, double y_i, double v_y);
double dvdt_y(double t_i, double y_i, double v_y);

double euler(double a, double b, double dxy , int puntos, double xi, double yi, double vxi, double vyi, string name);
double leapfrog(double a, double b, double dxy , int puntos, double xi, double yi, double vxi, double vyi, string name1);
double rungekutta(double a, double b, double dxy , int puntos, double xi, double yi, double vxi, double vyi, string name2);

//Derivada de la posición en la dimensión x

double dxdt_x(double t_i, double x_i, double v_x)
{
    return v_x;
}

//Derivada de la posición en la dimensión y

double dxdt_y(double t_i, double y_i, double v_y)
{
    return v_y;
}

//Derivada de la velocidad en la dimensión x

double dvdt_x(double t_i, double x_i, double v_x)
{
    double G = 1.98256*pow(10,-29); //constante gravitacional
    double M = 1.989*pow(10,30); //masa solar 
    double r = pow(pow(x_i,2),0.5);
    return -G*M*x_i/pow(r,3);
}

//Derivada de la velocidad en la dimensión y

double dvdt_y(double t_i, double y_i, double v_y)
{
    double G = 1.98256*pow(10,-29); //constante gravitacional
    double M = 1.989*pow(10,30); //Masa solar
    double r = pow(pow(y_i,2),0.5);
    return -G*M*y_i/pow(r,3);
}

//Método de euler para resolver la ecuación diferencial

double euler(double a, double b, double dxy , int puntos, double xi, double yi, double vxi, double vyi, string name)
{
    ofstream outfile;
    outfile.open(name);
    double t[puntos];
    double x[puntos];
    double y[puntos];
    double vx[puntos];
    double vy[puntos];
    
    //Condiciones iniciales
    t[0]=0.0;
    x[0]= xi;
    y[0]= yi;
    vx[0]=vxi;
    vy[0]=vyi;
       
    //Arreglo del tiempo 
    double dt = (b-a)/puntos;
    for(int i = 1; i<puntos; i++)
    {
        t[i] = t[i-1] + dt;
    }
    
    for(int i = 1; i<puntos; i++)
    {
        x[i] = x[i-1] + (dxy*dxdt_x(t[i-1],x[i-1],vx[i-1]));
        y[i] = y[i-1] + (dxy*dxdt_y(t[i-1],y[i-1],vy[i-1]));
        vx[i] = vx[i-1] + (dxy*dvdt_x(t[i-1],x[i-1],vx[i-1]));
        vy[i] = vy[i-1] + (dxy*dvdt_y(t[i-1],y[i-1],vy[i-1]));  
    } 
    for(int i=1; i<puntos; i++)
    {
        outfile << t[i-1] << "||" << x[i-1] << "||" << y[i-1] << "||" << vx[i-1] << "||" << vy[i-1] << endl;
        
    }
    outfile.close();
}
/*
//Método de LeapFrog para resolver la ecuación diferencial
double leapfrog(double a, double b, double dxy , int puntos, double xi, double yi, double vxi, double vyi, string name1)
{
    ofstream outfile1;
    outfile1.open(name1);
    double t[puntos];
    double x[puntos];
    double y[puntos];
    double vx[puntos];
    double vy[puntos];
    
    //Condiciones iniciales
    t[0]=0.0;
    x[0]= xi;
    y[0]= yi;
    vx[0]=vxi;
    vy[0]=vyi;
        
    //Arreglo del tiempo
    double dt = (b-a)/puntos;
    for(int i = 1; i<puntos; i++)
    {
        t[i] = t[i-1] + dt;
    }
    
    for(int i =1; i<puntos; i++)
    {
        x[i] = x[i-1] + (0.5*dxy*dxdt_x(t[i-1],x[i-1],vx[i-1]));
        y[i] = y[i-1] + (0.5*dxy*dxdt_y(t[i-1],y[i-1],vy[i-1]));
        vx[i] = vx[i-1] + (dxy*dvdt_x(t[i-1],x[i-1],vx[i-1]));
        vy[i] = vy[i-1] + (dxy*dvdt_y(t[i-1],y[i-1],vy[i-1]));        
    }    
    for (int i =1; i<puntos; i++)
    {
        //outfile1 << t[i-1] << "||" << x[i-1] << "||" << y[i-1] << "||" << vx[i-1] << "||" << vy[i-1] << endl;
        
    }
    outfile1.close();
    
}

//Método de Runge Kutta para resolver la ecuación
double rungekutta(double a, double b, double dxy , int puntos, double xi, double yi, double vxi, double vyi, string name2)
{
    ofstream outfile2;
    outfile2.open(name2);
    double t[puntos];
    double x[puntos];
    double y[puntos];
    double vx[puntos];
    double vy[puntos];
    
    //Condiciones iniciales
    t[0]=0.0;
    x[0]= xi;
    y[0]= yi;
    vx[0]=vxi;
    vy[0]=vyi;
        
    double k1x,k2x,k3x,k4x;
    double k1y,k2y,k3y,k4y;
    double k1v_x, k2v_x, k3v_x, k4v_x;
    double k1v_y, k2v_y, k3v_y, k4v_y;
    double meanx, meany, meanv_x, meanv_y;
    
    //Arreglo del tiempo  
    double dt = (b-a)/puntos;
    for(int i = 1; i<puntos; i++)
    {
        t[i] = t[i-1] + dt;
    }
    
    for (int i =1; i<puntos; i++)
    {
        //Calculo en x
        k1x = dxy*dxdt_x(t[i-1],x[i-1],vx[i-1]);
        k1v_x = dxy*dvdt_x(t[i-1], x[i-1], vx[i-1]);
        
        k2x = dxy*dxdt_x(t[i-1]+dxy/2, x[i-1]+k1x/2, vx[i-1]+k1v_x/2);
        k2v_x = dxy*dvdt_x(t[i-1]+dxy/2, x[i-1]+k1x/2, vx[i-1]+k1v_x/2);
        
        k3x = dxy*dxdt_x(t[i-1]+dxy/2, x[i-1]+k2x/2, vx[i-1]+k2v_x/2);
        k3v_x = dxy*dvdt_x(t[i-1]+dxy/2, x[i-1]+k2x/2, vx[i-1]+k2v_x/2);
        
        k4x = dxy*dxdt_x(t[i-1]+dxy, x[i-1]+k3x, vx[i-1]+k3v_x);
        k4v_x = dxy*dvdt_x(t[i-1]+dxy, x[i-1]+k3x, vx[i-1]+k3v_x);
        
        //calculo en y
        k1y = dxy*dxdt_y(t[i-1],y[i-1],vy[i-1]);
        k1v_y = dxy*dvdt_y(t[i-1], y[i-1], vy[i-1]);
        
        k2y = dxy*dxdt_y(t[i-1]+dxy/2, y[i-1]+k1y/2, vy[i-1]+k1v_y/2);
        k2v_y = dxy*dvdt_y(t[i-1]+dxy/2, y[i-1]+k1y/2, vy[i-1]+k1v_y/2);
        
        k3y = dxy*dxdt_y(t[i-1]+dxy/2, y[i-1]+k2y/2, vy[i-1]+k2v_y/2);
        k3v_y = dxy*dvdt_y(t[i-1]+dxy/2, y[i-1]+k2y/2, vy[i-1]+k2v_y/2);
        
        k4y = dxy*dxdt_y(t[i-1]+dxy, y[i-1]+k3y, vy[i-1]+k3v_y);
        k4v_y = dxy*dvdt_y(t[i-1]+dxy, y[i-1]+k3y, vy[i-1]+k3v_y);   
        
        meanx = (1/6)*(k1x+2*k2x+2*k3x+k4x);
        meany = (1/6)*(k1y+2*k2y+2*k3y+k4y);
        meanv_x = (1/6)*(k1v_x+2*k2v_x+2*k3v_x+k4v_x);
        meanv_y = (1/6)*(k1v_y+2*k2v_y+2*k3v_y+k4v_y);
        
        x[i] = x[i-1]+meanx;
        y[i] = y[i-1]+meany;
        vx[i] = vx[i-1]+meanv_x;
        vy[i] = vy[i-1]+meanv_y;
    }
    for(int i =1; i<puntos; i++)
    {
        //outfile2 << t[i-1] << "||" << x[i-1] << "||" << y[i-1] << "||" << vx[i-1] << "||" << vy[i-1] << endl;
        
    }
    
    outfile2.close();
}
*/
int main()
{
    double x_in = 0.1163;
    double y_in = 0.9772;
    double vx_i = -6.35;
    double vy_i = 0.606;
    double d_xy = 0.01;
    double a = 0;
    double b = 20;
    
    euler(a, b, d_xy, 1000, x_in, y_in, vx_i, vy_i, "euler1.dat");
   // leapfrog(a, b, d_xy, 2001, x_in, y_in, vx_i, vy_i, "LF1.dat");
    //rungekutta(a, b, d_xy, 2001, x_in, y_in, vx_i, vy_i, "RK1.dat");
    
   // euler(a, b, d_xy, 3001, x_in, y_in, vx_i, vy_i, "euler2.dat");
  //  leapfrog(a, b, d_xy, 3001, x_in, y_in, vx_i, vy_i, "LF2.dat");
   // rungekutta(a, b, d_xy, 3001, x_in, y_in, vx_i, vy_i, "RK2.dat");
    
   // euler(a, b, d_xy, 1001, x_in, y_in, vx_i, vy_i, "euler3.dat");
    //leapfrog(a, b, d_xy, 1001, x_in, y_in, vx_i, vy_i, "LF3.dat");
    //rungekutta(a, b, d_xy, 1001, x_in, y_in, vx_i, vy_i, "RK3.dat");
   
    return 0;
}

