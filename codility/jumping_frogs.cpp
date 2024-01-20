int solution(vector<int> &blocks) {
    int toleft  = 0;
    int maxdist = 1;
    int N = blocks.size();
    for (int initial=0; initial<N; initial++) {
        if ( (initial>0)  && (blocks.at(initial) <= blocks.at(initial-1)) )
            toleft++;
        else
            toleft = 0;
        int thisdist = toleft+1;
        int nextblk = initial;
        while ( (nextblk<N-1) && (blocks.at(nextblk) <=  blocks.at(nextblk+1)) ) {
            thisdist++;
            nextblk++;
        }
        maxdist = maxdist > thisdist ? maxdist : thisdist; 
    }
    return maxdist;
}
