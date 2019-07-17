#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double masaT = 5.972*pow(10,24);

double dxdt_x(double ti, double xi, double vx);
double dxdt_y(double ti, double yi, double vy);

double dvdt_x(double ti, double xi, double r12);
double dvdt_y(double ti, double yi, double r12);

double euler(double t0, double tf, double dxy, int puntos, string name);
double leapfrog(double t0, double tf, double dxy, int puntos, string name1);
double rungekutta(double t0, double tf, double dxy, int puntos, string name2);

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
    //double r = sqrt(pow(r12,2));
    return G*M*xi/(pow(r12,3));
}

//Derivada de la velocidad en la dimensión y

double dvdt_y(double ti, double yi, double r12)
{
    double G = -1.98256*pow(10,-29);
    double M = 1.989*pow(10,30);
    //double r = sqrt(pow(r12,2));
    return G*M*yi/(pow(r12,3));
}

//Método de euler para resolver la ecuación diferencial

double euler(double t0, double tf, double dxy, int puntos, string name)
{
    ofstream outfile;
    outfile.open(name);
    double dt = (tf-t0)/puntos;
    double t[puntos], x[puntos], y[puntos], vx[puntos], vy[puntos], r12[puntos], ma[puntos], energiaP[puntos], energiaK[puntos];
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
        ma[i] = (r12[i]*vx[i])-(r12[i]*vy[i]);
    }
    
    for (int i = 1; i<puntos; i++)
    {
        outfile << t[i-1] << "||" << x[i-1] << "||" << y[i-1] << "||" << vx[i-1] << "||" << vy[i-1] << "||" << ma[i] <<endl;
    }
    outfile.close();
}


//Método de LeapFrog para resolver la ecuación diferencial
double leapfrog(double t0, double tf, double dxy, int puntos, string name1)
{
    ofstream outfile1;
    outfile1.open(name1);
    double dt = (tf-t0)/puntos;
    double t[puntos], x[puntos], y[puntos], vx[puntos], vy[puntos], r12[puntos], ma[puntos], energiaP[puntos], energiaK[puntos];
    t[0] = 0;
    x[0] = 0.1163;
    y[0] = 0.9772;
    vx[0] = -6.35;
    vy[0] = 0.606;
    r12[0] = sqrt(pow(x[0],2)+pow(y[0],2));
    for(int i = 1; i<puntos; i++)
    {
        t[i] = t[i-1] + dt;
    }
    
    for(int i =1; i<puntos; i++)
    {
        x[i] = x[i-1] + (0.5*dxy*dxdt_x(t[i-1],x[i-1],vx[i-1]));
        y[i] = y[i-1] + (0.5*dxy*dxdt_y(t[i-1],y[i-1],vy[i-1]));
        r12[i] = sqrt(pow(x[i],2)+pow(y[i],2));
        vx[i] = vx[i-1] + (dxy*dvdt_x(t[i-1],x[i-1],r12[i-1]));
        vy[i] = vy[i-1] + (dxy*dvdt_y(t[i-1],y[i-1],r12[i-1]));   
        ma[i] = (r12[i]*vx[i])-(r12[i]*vy[i]);
    }    
    for (int i =1; i<puntos; i++)
    {
        outfile1 << t[i-1] << "||" << x[i-1] << "||" << y[i-1] << "||" << vx[i-1] << "||" << vy[i-1] << "||" << ma[i] <<endl;
        
    }
    outfile1.close();
    
}

//Método de Runge Kutta para resolver la ecuación

double rungekutta(double t0, double tf, double dxy, int puntos, string name2)
{
    ofstream outfile2;
    outfile2.open(name2);
    double t[puntos], x[puntos], y[puntos], vx[puntos], vy[puntos], r12[puntos], ma[puntos], energiaP[puntos], energiaK[puntos];
    //Condiciones iniciales
    t[0] = 0;
    x[0] = 0.1163;
    y[0] = 0.9772;
    vx[0] = -6.35;
    vy[0] = 0.606;
    r12[0] = sqrt(pow(x[0],2)+pow(y[0],2));
           
    double k1x,k2x,k3x,k4x;
    double k1y,k2y,k3y,k4y;
    double k1v_x, k2v_x, k3v_x, k4v_x;
    double k1v_y, k2v_y, k3v_y, k4v_y;
    double meanx, meany, meanv_x, meanv_y;
 
    double dt = (tf-t0)/puntos;
    for(int i = 1; i<puntos; i++)
    {
        t[i] = t[i-1] + dt;
    }
    
    for (int i =1; i<puntos; i++)
    {

        k1x = dxy*dxdt_x(t[i-1],x[i-1],vx[i-1]);
        k1y = dxy*dxdt_y(t[i-1],y[i-1],vy[i-1]);
        k1v_x = dxy*dvdt_x(t[i-1], x[i-1], r12[i-1]);
        k1v_y = dxy*dvdt_y(t[i-1], y[i-1], r12[i-1]);
        
        k2x = dxy*dxdt_x(t[i-1]+(dxy*0.5), x[i-1]+(k1x*0.5), vx[i-1]+(k1v_x*0.5));
        k2y = dxy*dxdt_y(t[i-1]+(dxy*0.5), y[i-1]+(k1y*0.5), vy[i-1]+(k1v_y*0.5));
        k2v_x = dxy*dvdt_x(t[i-1]+(dxy*0.5), x[i-1]+(k1x*0.5), r12[i-1]+(k1v_x*0.5));
        k2v_y = dxy*dvdt_y(t[i-1]+(dxy*0.5), y[i-1]+(k1y*0.5), r12[i-1]+(k1v_y*0.5));
        
        k3x = dxy*dxdt_x(t[i-1]+(dxy*0.5), x[i-1]+(k2x*0.5), vx[i-1]+(k2v_x*0.5));
        k3y = dxy*dxdt_y(t[i-1]+(dxy*0.5), y[i-1]+(k2y*0.5), vy[i-1]+(k2v_y*0.5));
        k3v_x = dxy*dvdt_x(t[i-1]+(dxy*0.5), x[i-1]+(k2x*0.5), r12[i-1]+(k2v_x*0.5));
        k3v_y = dxy*dvdt_y(t[i-1]+(dxy*0.5), y[i-1]+(k2y*0.5), r12[i-1]+(k2v_y*0.5));
        
        k4x = dxy*dxdt_x(t[i-1]+dxy, x[i-1]+k3x, vx[i-1]+k3v_x);
        k4y = dxy*dxdt_y(t[i-1]+dxy, y[i-1]+k3y, vy[i-1]+k3v_y);
        k4v_x = dxy*dvdt_x(t[i-1]+dxy, x[i-1]+k3x, r12[i-1]+k3v_x);
        k4v_y = dxy*dvdt_y(t[i-1]+dxy, y[i-1]+k3y, r12[i-1]+k3v_y);   
      
        meanx = (1.0/6.0)*(k1x+(2*k2x)+(2*k3x)+k4x);
        meany = (1.0/6.0)*(k1y+(2*k2y)+(2*k3y)+k4y);
        meanv_x = (1.0/6.0)*(k1v_x+(2*k2v_x)+(2*k3v_x)+k4v_x);
        meanv_y = (1.0/6.0)*(k1v_y+(2*k2v_y)+(2*k3v_y)+k4v_y);
        
        x[i] = x[i-1]+meanx;
        y[i] = y[i-1]+meany;
        r12[i] = sqrt(pow(x[i],2)+pow(y[i],2));
        vx[i] = vx[i-1]+meanv_x;
        vy[i] = vy[i-1]+meanv_y;
        ma[i] = (r12[i]*vx[i])-(r12[i]*vy[i]);
    }
    for(int i =1; i<puntos; i++)
    {
        outfile2 << t[i-1] << "||" << x[i-1] << "||" << y[i-1] << "||" << vx[i-1] << "||" << vy[i-1] << "||" << ma[i] <<endl;
    }
    
    outfile2.close();
}

int main()
{
    //Primer dt
    euler(0, 20, 0.001, 50000, "Euler1.dat");
    leapfrog(0, 20, 0.001, 20000, "LF1.dat");
    rungekutta(0, 20, 0.0001, 40000, "RK1.dat");
    
    //Segundo dt
    euler(0, 20, 0.0001, 50000, "Euler2.dat");
    leapfrog(0, 20, 0.0001, 20000, "LF2.dat");
    rungekutta(0, 20, 0.0001, 40000, "RK2.dat");
    
    //Tercer dt
    euler(0, 20, 0.0002, 52000, "Euler3.dat");
    leapfrog(0, 20, 0.0002, 22000, "LF3.dat");
    rungekutta(0, 20, 0.0002, 42000, "RK3.dat");
    return 0;
}

