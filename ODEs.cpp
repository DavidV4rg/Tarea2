#include <iostream>
#include <fstream>

using namespace std;

void dxdt(float t, float x, float y, float v);
void dvdt(float t, float x, float y,  float v);

void euler(float t, float x, float y, float v);
void leapfrog(float t, float x, float y, float v);
void rungekutta(float t, float x, float y, float v);
