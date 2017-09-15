#include <algorithm>

int solution(vector< vector<int> > &A) {

    int last_country = 0;
    vector< vector<int> > countries(A.size(),vector<int>(A[0].size()));
    countries[0][0] = last_country;
    
    for (unsigned int i=0; i<A.size(); i++) {
        for (unsigned int j=0; j<A[0].size(); j++) {
            int present_color = A[i][j];
            int possible_country = 0;
            // Quick cut'n'paste to compare in four directions
            // Up
            if (i>0) {
                if (present_color==A[i-1][j]) {
                    possible_country = countries[i-1][j];                    
                    // Special case of repainting left country because of discovered connection above
                    if ((j>0) && (A[i][j-1]==A[i-1][j])) {
                        A[i][j-1] = possible_country;
                        last_country--;
                    }
                }
            }

            // Left
            if ((j>0) && (!possible_country)) {
                if (present_color==A[i][j-1]) 
                    possible_country = countries[i][j-1];
            }
           
            // Right
            if ((j<(A[0].size()-1)) && (!possible_country)) {
                if (present_color==A[i][j+1])
                    possible_country = countries[i][j+1];  
            }

            // Down
            if ((i<(A.size()-1)) && (!possible_country)) {
                if (present_color==A[i+1][j]) 
                    possible_country = countries[i+1][j];
            }

            // Write down this country and indicate this country is taken
            if (possible_country>0)
                countries[i][j] = possible_country;
            else countries[i][j] = ++last_country;
        }
    }
    return last_country;
}
