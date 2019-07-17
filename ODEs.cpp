#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//float años = pow(31.54,7);

double dxdt_x(double ti, double xi, double vx);
double dxdt_y(double ti, double yi, double vy);

double dvdt_x(double ti, double xi, double r12);
double dvdt_y(double ti, double yi, double r12);

double euler(double t0, double tf, double dxy, int puntos, string name);
double leapfrog(double t0, double tf, double dxy, int puntos, string name);
double rungekutta(double t0, double tf, double dxy, int puntos, string name);

//Derivada de la posición en la dimensión x

double dxdt_x(double ti, double xi, double vx)
{
    return vx;
}

//Derivada de la posición en la dimensión y

double dxdt_y(double ti, double yi, double vy)
{
    return vy;
}


//Derivada de la velocidad en la dimensión x

double dvdt_x(double ti, double xi, double r12)
{
    double G = -1.98256*pow(10,-29);
    double M = 1.989*pow(10,30);
    double r = sqrt(pow(r12,2));
    return G*M*xi/(pow(r,3));
}

//Derivada de la velocidad en la dimensión y

double dvdt_y(double ti, double yi, double r12)
{
    double G = -1.98256*pow(10,-29);
    double M = 1.989*pow(10,30);
    double r = sqrt(pow(r12,2));
    return G*M*yi/(pow(r,3));
}

//Método de euler para resolver la ecuación diferencial

double euler(double t0, double tf, double dxy, int puntos, string name)
{
    ofstream outfile;
    outfile.open(name);
    double dt = (tf-t0)/puntos;
    double t[puntos], x[puntos], y[puntos], vx[puntos], vy[puntos], r12[puntos];
    t[0] = 0;
    x[0] = 0.1163;
    y[0] = 0.9772;
    vx[0] = -6.35;
    vy[0] = 0.606;
    r12[0] = sqrt(pow(x[0],2)+pow(y[0],2));
    
    for (int i = 1; i < puntos; i++)
    {
        t[i] = t[i-1] + dt;
    }
    for (int i = 1; i < puntos; i++)
    {
        x[i] = x[i-1] + (dxy*dxdt_x(t[i-1], x[i-1], vx[i-1]));
        y[i] = y[i-1] + (dxy*dxdt_y(t[i-1], y[i-1], vy[i-1]));
        r12[i] = sqrt(pow(x[i],2)+pow(y[i],2));
        vx[i] = vx[i-1] + (dxy*dvdt_x(t[i-1], x[i-1], r12[i-1]));
        vy[i] = vy[i-1] + (dxy*dvdt_y(t[i-1], y[i-1], r12[i-1]));
    }
    
    for (int i = 1; i<puntos; i++)
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
    
    euler(0, 20, 0.001, 1050, "Euler1.dat");
    euler(0, 20, 0.001, 1000, "Euler2.dat");
    euler(0, 20, 0.001, 2000, "Euler3.dat");

    return 0;
}

