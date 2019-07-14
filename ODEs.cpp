#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//float años = pow(31.54,7);

float dxdt_x(float t_i, float x_i, float v_x);
float dvdt_x(float t_i, float x_i, float v_x);

float dxdt_y(float t_i, float y_i, float v_y);
float dvdt_y(float t_i, float y_i, float v_y);

float euler(double a, double b, double dxy , int puntos, float xi, float yi, float vxi, float vyi);
float leapfrog(double a, double b, double dxy , int puntos, float xi, float yi, float vxi, float vyi);
float rungekutta(double a, double b, double dxy , int puntos, float xi, float yi, float vxi, float vyi);

float dxdt_x(float t_i, float x_i, float v_x)
{
    return v_x;
}

float dxdt_y(float t_i, float y_i, float v_y)
{
    return v_y;
}

float dvdt_x(float t_i, float x_i, float v_x)
{
    float G = pow(-66.7, -11);
    float M = pow(19.89, 30);
    float AU = 1;    
    return G*M*x_i/AU;
}

float dvdt_y(float t_i, float y_i, float v_y)
{
    float G = pow(-66.7, -11);
    float M = pow(19.89, 30);
    float AU = 1;
    return G*M*y_i/AU;
}

float euler(double a, double b, double dxy , int puntos, float xi, float yi, float vxi, float vyi)
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
float leapfrog(double a, double b, double dxy , int puntos, float xi, float yi, float vxi, float vyi)
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
    
    for(int i =1; i<puntos; i++)
    {
        x[i] = x[i-1] + (0.5*dxy*dxdt_x(t[i-1],x[i-1],vx[i-1]));
        y[i] = y[i-1] + (0.5*dxy*dxdt_y(t[i-1],y[i-1],vy[i-1]));
        vx[i] = vx[i-1] + (dxy*dvdt_x(t[i-1],x[i-1],vx[i-1]));
        vy[i] = vy[i-1] + (dxy*dvdt_y(t[i-1],y[i-1],vy[i-1]));        
    }    
}

float rungekutta(double a, double b, double dxy , int puntos, float xi, float yi, float vxi, float vyi)
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
    float k1x,k2x,k3x,k4x;
    float k1y,k2y,k3y,k4y;
    float k1v_x, k2v_x, k3v_x, k4v_x;
    float k1v_y, k2v_y, k3v_y, k4v_y;
    float meanx, meany, meanv_x, meanv_y;
    
    //Arreglo del tiempo
    
    for(int i = 1; i<puntos; i++)
    {
        t[i] = t[i-1] + dt;
    }
    
    for (int i =1; i<puntos; i++)
    {
        k1x = dxy*dxdt_x(t[i-1],x[i-1],vx[i-1]);
        k1v_x = dxy*dvdt_x(t[i-1], x[i-1], vx[i-1]);
        
        k2x = dxy*dxdt_x(t[i-1]+dxy/2, x[i-1]+k1x/2, vx[i-1]+k1v_x/2);
        k2v_x = dxy*dvdt_x(t[i-1]+dxy/2, x[i-1]+k1x/2, vx[i-1]+k1v_x/2);
        
        k3x = dxy*dxdt_x(t[i-1]+dxy/2, x[i-1]+k2x/2, vx[i-1]+k2v_x/2);
        k3v_x = dxy*dvdt_x(t[i-1]+dxy/2, x[i-1]+k2x/2, vx[i-1]+k2v_x/2);
        
        k4x = dxy*dxdt_x(t[i-1]+dxy, x[i-1]+k3x, vx[i-1]+k3v_x);
        k4v_x = dxy*dvdt_x(t[i-1]+dxy, x[i-1]+k3x, vx[i-1]+k3v_x);
        
        
        k1y = dxy*dxdt_y(t[i-1],x[i-1],vx[i-1]);
        k1v_y = dxy*dvdt_y(t[i-1], x[i-1], vx[i-1]);
        
        k2y = dxy*dxdt_y(t[i-1]+dxy/2, y[i-1]+k1y/2, vy[i-1]+k1v_y/2);
        k2v_y = dxy*dvdt_y(t[i-1]+dxy/2, y[i-1]+k1y/2, vy[i-1]+k1v_y/2);
        
        k3y = dxy*dxdt_y(t[i-1]+dxy/2, y[i-1]+k2y/2, vy[i-1]+k2v_y/2);
        k3v_y = dxy*dvdt_y(t[i-1]+dxy/2, y[i-1]+k2y/2, vy[i-1]+k2v_y/2);
        
        k4y = dxy*dxdt_y(t[i-1]+dxy, y[i-1]+k3y, vy[i-1]+k3v_y);
        k4v_y = dxy*dvdt_y(t[i-1]+dxy, y[i-1]+k3y, vy[i-1]+k3v_y);   
    }
    
    
}

int main()
{
    float x_in = 0.1163;
    float y_in = 0.9772;
    float vx_i = -6.35;
    float vy_i = 0.606;
    double d_xy = 0.01;
    double a1 = 0;
    double b1 = 200;
    
    euler(a1, b1, d_xy, 300, x_in, y_in, vx_i, vy_i);
    leapfrog(a1, b1, d_xy, 300, x_in, y_in, vx_i, vy_i);
    rungekutta(a1, b1, d_xy, 300, x_in, y_in, vx_i, vy_i);
    
    return 0;
}

