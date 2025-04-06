/*
 * Complete the 'calculateReviewAdjustments' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY reviews
 *  2. INTEGER_ARRAY counts
 */

vector<long> calculateReviewAdjustments(vector<int> reviews, vector<int> counts) {

    vector<long> answer(counts.size(), 0);
    unordered_map<int, long> aux;
    
    for(size_t i=0; i<counts.size(); i++) {
        
        auto temp = aux.find(counts[i]);
        if (temp == aux.end()) {
            int x = counts[i];
            long total=0;
            for_each(reviews.begin(), reviews.end(), [&total, &x, i](int j) { total  += abs(j-x); });
            answer[i] = total;
            aux.emplace(x, total);
        }
        else {
            answer[i] = temp->second;
        }
    }

    return answer;
}
