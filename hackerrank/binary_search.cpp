class object {
    public: 
        int value; 
        int index;

        IceCream(int y, int z) : value{y}, index{z} {
       }
};


int binarySearch(int first, int last, vector<object> arr, int search) {
   
    if (first > last)
        return -1;
    
    if (search == arr[first].value)
        return arr[first].index;
    
    if (search < arr[(first+last)/2].value)
        return binarySearch(first, ((first+last)/2)-1, arr, search);
    
    if (search > arr[(first+last)/2].value)
        return binarySearch(((first+last)/2)+1, last, arr, search);
    
    if (search == arr[(first+last)/2].value) {
        return arr[(first+last)/2].index; 
    }
    else return -1;
}
