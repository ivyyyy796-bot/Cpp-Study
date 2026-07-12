#include "Plotter.h"
#include "strlib.h"
#include "graph.h"
using namespace std;
void runPlotterScript(istream& input) {
    double x=0;
    double y=0;
    double newX=x;
    double newY=y;
    int op=0;        //default case: PenUp
    PenStyle style ={1.0,"black"};
    for (string line; getline(input, line); ) {
        line=toLowerCase(line);
        Vector<string> d = stringSplit(line, " ");
        if(startsWith(line,"pendown")) {
            op=1;
        }
        else if(startsWith(line,"penup")){
            op=0;
        }
        else if(startsWith(line,"pencolor")){
            style.color=d[1];
        }
        else if(startsWith(line,"penwidth")){
            style.width=stringToReal(d[1]);
        }
        else if (startsWith(line,"moveabs")){      
            newX=stringToReal(d[1]);
            newY=stringToReal(d[2]);
            if(op==1){
                drawLine(x,y,newX,newY,style);
            }
            x=newX;
            y=newY;
        }
        else if(startsWith(line,"moverel")){
            newX=x+stringToReal(d[1]);
            newY=y+stringToReal(d[2]);
            if(op==1){
                drawLine(x,y,newX,newY,style);
            }
            x=newX;
            y=newY;
        }
    }
}
