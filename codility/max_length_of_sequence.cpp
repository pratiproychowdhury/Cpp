int solution(vector<int> &A) {
    int maxseq = 0;
    sort(A.begin(), A.end());

    auto ptr = A.begin();
    while (ptr < A.end()) {
        int thisseq = count(ptr, A.end(), *ptr);
        maxseq = thisseq > maxseq ? thisseq : maxseq;
        ptr += thisseq;
    }

    int start = A.at(0);
    int end = A.back();
    for (int diff=1; diff<end-start; diff++) {
        auto ptr = A.begin();
        while (ptr < A.end()) {
            int next = *ptr;
            int thisseq = 1;
            next += diff;
            while (find(ptr, A.end(), next) != A.end()) {
                thisseq++;
                next += diff;
            }
            maxseq = thisseq > maxseq ? thisseq : maxseq;
            ptr++;
        }
    }
    return maxseq;
}
