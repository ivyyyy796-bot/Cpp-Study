void dropSandOn(Grid<int>& world, int row, int col) {
    if(!world.inBounds(row,col)){
        return;
    }
    else{
        world[row][col]+=1;
        if(world[row][col]>=4){
            world[row][col]-=4;
            dropSandOn(world,row+1,col);
            dropSandOn(world,row-1,col);
            dropSandOn(world,row,col+1);
            dropSandOn(world,row,col-1);
        }
    }
}
