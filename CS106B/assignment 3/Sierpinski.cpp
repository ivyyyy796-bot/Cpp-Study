void drawTriangle(GWindow& window,
                  double x0, double y0,
                  double x1, double y1,
                  double x2, double y2) {
    window.setColor("black");
    window.fillPolygon({ x0, y0, x1, y1, x2, y2 });
}

void drawSierpinskiTriangle(GWindow& window,
                            double x0, double y0,
                            double x1, double y1,
                            double x2, double y2,
                            int order) {
    //if the order parameter is less than zero, use the error()
    if(order < 0){
        error("ERROR: order should be no less than 0.");
    }
    if(order == 0){
        drawTriangle(window,x0,y0,x1,y1,x2,y2);
    }
    else{
        drawSierpinskiTriangle(window,x0,y0,(x1+x0)/2,(y1+y0)/2,(x2+x0)/2,(y2+y0)/2,order-1);
        drawSierpinskiTriangle(window,(x0+x1)/2,(y0+y1)/2,x1,y1,(x1+x2)/2,(y1+y2)/2,order-1);
        drawSierpinskiTriangle(window,(x0+x2)/2,(y0+y2)/2,(x1+x2)/2,(y1+y2)/2,x2,y2,order-1);
    }
}
