Grid<bool> floodedRegionsIn(const Grid<double>& terrain,
                            const Vector<GridLocation>& sources,
                            double height) {
    Grid<bool> res(terrain.numRows(),terrain.numCols(),false);
    Queue<GridLocation> q;
    for(GridLocation loc:sources){
        if(terrain[loc.row][loc.col]>= height){
            q.enqueue(loc);
            res[loc.row][loc.col]=true;
        }
    }
    while(!q.isEmpty()){
        GridLocation current = q.dequeue();
        double r = current.row;
        double c = current.col;
        if(height >= terrain[r][c]){
            q.enqueue(current);
            res[r][c]=true;
        }
        else{
        }
    }
    return res;
}
