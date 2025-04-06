/*
 * Complete the 'getMinConnectionCost' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY warehouseCapacity
 *  2. 2D_INTEGER_ARRAY additionalHubs
 */

vector<long> getMinConnectionCost(vector<int> warehouseCapacity, vector<vector<int>> additionalHubs) {

    vector<long> answer(additionalHubs.size(), 0);
    
    vector<long> defaultcost(warehouseCapacity.size(), 0);
    for (size_t i=2; i<warehouseCapacity.size()-1; i++)
        defaultcost[i] = warehouseCapacity.back() - warehouseCapacity[i];
    
    for (size_t hub=0; hub<additionalHubs.size(); hub++) {
        
        for (size_t i=0; i<additionalHubs[hub][0]-1; i++) 
            answer[hub] += warehouseCapacity[additionalHubs[hub][0]-1] - warehouseCapacity[i];
        
        for (size_t i=additionalHubs[hub][0]; i<additionalHubs[hub][1]-1; i++) 
            answer[hub] += warehouseCapacity[additionalHubs[hub][1]-1] - warehouseCapacity[i];        

        for (size_t i=additionalHubs[hub][1]; i<warehouseCapacity.size()-1; i++) 
            answer[hub] += defaultcost[i];        
        
    }
    return answer;
}
