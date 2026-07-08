#include <iostream>
#include "console.h"
#include <string>
#include <fstream>
#include "map.h"
#include "strlib.h"
#include "gwindow.h"
using namespace std;
void cantorSet(GWindow& window, int x, int y, int length, int levels);

int main()
{
    GWindow gw(800,600);
    gw.setColor("black");
    cantorSet(gw, 50,50,700, 5);
    return 0;
}

void cantorSet(GWindow& window, int x, int y, int length, int levels){
    window.drawLine(x,y,x+length,y);
    if(levels == 1){
    }
    else{
        cantorSet(window, x, y+20 , length/3, levels -1);
        cantorSet(window, x+length/3*2, y+20 , length/3, levels -1);
    }
}
