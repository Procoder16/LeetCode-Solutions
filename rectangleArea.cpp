class Solution {
public:
    int area1 = 0;
    int area2 = 0;
    int commonArea = 0;
    int resArea = 0;
    
    int calArea(int ax1, int ay1, int ax2, int ay2)   {
        int l = ax2-ax1;
        int b = ay2-ay1;
        return l*b;
    }
    
    int intersectionX(int ax1, int ax2, int bx1, int bx2)  {
        int end = min(bx2,ax2);
        int start = max(bx1,ax1);
        return end-start;
    }
    int intersectionY(int ay1, int ay2, int by1, int by2)  {
        int end = min(by2,ay2);
        int start = max(by1,ay1);
        return end-start;
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        area1 = calArea(ax1,ay1,ax2,ay2);
        area2 = calArea(bx1,by1,bx2,by2);
        
        int interX = intersectionX(ax1,ax2,bx1,bx2);
        int interY = intersectionY(ay1,ay2,by1,by2);
        
        //Only consider common area if they overlap.
        if(interX>0&&interY>0)
            commonArea = interX*interY;
        
        //Subtracting common area from total area.
        resArea = area1 + area2 - commonArea;
        return resArea;
    }
};