#include "HumanPyramids.h"
#include <error.h>
#include "grid.h"
using namespace std;

double wHelper(int row, int col, int pyramidHeight,Grid<double>& mem){
    if(row < 0 || col < 0 || row >= pyramidHeight || col > row){
        error("ERROR: out of bounds.0");
    }
    double res;
    if(mem[row][col] >= 0){
        return mem[row][col];
    }
    else if(row==0 && col ==0){
        res=0;
    }
    else{
        if(col==0){
            res=80+wHelper(row-1,col,pyramidHeight,mem)/2;
        }
        else if(col == row){
            res=80+wHelper(row-1,col-1,pyramidHeight,mem)/2;
        }
        else{
            res = 160+wHelper(row-1,col-1,pyramidHeight,mem)/2
                            +wHelper(row-1,col,pyramidHeight,mem)/2;
        }
    }
    mem[row][col] = res;
    return res;
}


double weightOnBackOf(int row, int col, int pyramidHeight) {
    Grid<double> mem(pyramidHeight,pyramidHeight,-1);
    return wHelper(row,col,pyramidHeight,mem);
}

