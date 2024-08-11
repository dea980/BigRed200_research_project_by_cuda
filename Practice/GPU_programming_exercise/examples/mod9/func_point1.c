// demo of funtion pointers

extern unsigned int screenWidth;
extern void plotXY(double x, double y);


void graph(double minX, double minY,
           double maxX, double maxY,
           double (*fn)(double)) 
{ 
    double stepX = (maxX - minX) / screenWidth;
    for (double x=minX; x<maxX; x+=stepX) {
        double y = fn(x); // Get y for this x by calling passed-in fn()
        if (minY<=y && y<maxY) {
            plotXY(x, y); // Plot calculated point
        }
    }
}

