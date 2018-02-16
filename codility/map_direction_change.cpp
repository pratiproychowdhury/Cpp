int solution(int X, int Y) {
    // write your code in C++14 (g++ 6.2.0)
    int forwardDirection = (X+180) % 360;
    
    int change = Y - forwardDirection;
    
    if (change < -180)
        change += 360;
        
    if (change > 180)
        change -= 360;        
    
    if (abs(change) <= 15)
        return 0;
    else if ((-60 <= change) && (change < -15))
        return -30;
    else if ((15 < change) && (change <= 60))
        return 30;
    else if ((-112 <= change) && (change < -60))
        return -90;        
    else if ((60 < change) && (change <= 112))
        return 90;
    else if ((-157 <= change) && (change < -112))
        return -135;
    else if ((112 < change) && (change <= 157))
        return 135;
    else return 180;
}
