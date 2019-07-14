#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void dxdt_x(float t_i, float x_i, float v_x);
void dvdt_x(float t_i, float x_i, float v_x);

void dxdt_y(float t_i, float y_i, float v_y);
void dvdt_y(float t_i, float y_i, float v_y);

void euler(float t_i, float x_i, float y_i, float v_x, float v_y);
void leapfrog(float t_i, float x_i, float y_i, float v_x, float v_y);
void rungekutta(float t_i, float x_i, float y_i, float v_x, float v_y);

void dxdt(float t_i, float x_i, float v_x)
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
    return G*M/AU;
}

void dvdt_y(float t_i, float y_i, float v_y)
{
    float G = pow(-66.7, -11);
    float M = pow(19.89, 30);
    flaot AU = 1;
    return G*M/AU;
}

float años = pow(31.54,7);
