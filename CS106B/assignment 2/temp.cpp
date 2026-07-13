#include "RisingTides.h"
#include "GUI/SimpleTest.h"
#include "queue.h"
using namespace std;

Grid<bool> floodedRegionsIn(const Grid<double>& terrain,
                            const Vector<GridLocation>& sources,
                            double height) {
    Grid<bool> res(terrain.numRows(),terrain.numCols(),false);
    Queue<GridLocation> q;
    for(GridLocation loc:sources){
        if(terrain[loc.row][loc.col] <= height){
            q.enqueue(loc);
            res[loc.row][loc.col]=true;
        }
    }
    while(!q.isEmpty()){
        GridLocation current = q.dequeue();
        int r = current.row;
        int c = current.col;
        if(terrain.inBounds(r+1,c) &&
            !res[r+1][c] &&
            height >= terrain[r+1][c]){
            q.enqueue({r+1,c});
            res[r+1][c]=true;
        }
        if(terrain.inBounds(r-1,c) &&
            !res[r-1][c] &&
            height >= terrain[r-1][c]){
            q.enqueue({r-1,c});
            res[r-1][c]=true;
        }
        if(terrain.inBounds(r,c+1) &&
            !res[r][c+1] &&
            height >= terrain[r][c+1]){
            q.enqueue({r,c+1});
            res[r][c+1]=true;
        }
        if(terrain.inBounds(r,c-1) &&
            !res[r][c-1] &&
            height >= terrain[r][c-1]){
            q.enqueue({r,c-1});
            res[r][c-1]=true;
        }

    }
    return res;
}
