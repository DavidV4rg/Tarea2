#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//float años = pow(31.54,7);

void dxdt_x(float t_i, float x_i, float v_x);
void dvdt_x(float t_i, float x_i, float v_x);

void dxdt_y(float t_i, float y_i, float v_y);
void dvdt_y(float t_i, float y_i, float v_y);

void euler(double a, double b, , int puntos, float t_i, float x_i, float y_i, float v_x, float v_y);
void leapfrog(double a, double b, , int puntos, float t_i, float x_i, float y_i, float v_x, float v_y);
void rungekutta(double a, double b, , int puntos, float t_i, float x_i, float y_i, float v_x, float v_y);

void dxdt_x(float t_i, float x_i, float v_x)
{
    return v_x;
}

void dxdt_y(float t_i, float y_i, float v_y);
{
    return v_y;
}

void dvdt_x(float t_i, float x_i, float v_x)
{
    float G = pow(-66.7, -11);
    float M = pow(19.89, 30);
    float AU = 1;    
    return G*M*x_i/AU;
}

void dvdt_y(float t_i, float y_i, float v_y)
{
    float G = pow(-66.7, -11);
    float M = pow(19.89, 30);
    flaot AU = 1;
    return G*M*y_i/AU;
}

void euler(double a, double b, double dxy , int puntos, float xi, float yi, float vxi, float vyi)
{
    float t[puntos];
    float x[puntos];
    float y[puntos];
    float vx[puntos];
    float vy[puntos];
    
    //Condiciones iniciales
    t[0]=0.0;
    x[0]= xi;
    y[0]= yi;
    vx[0]=vxi;
    vy[0]=vyi;
    
    double dt = b-a/puntos;
    
    //Arreglo del tiempo
    
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

    
}
int main()
{
    return 0;
}

