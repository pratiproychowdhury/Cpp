int binary_search_rotated(vector<int>& arr, int key) {
  int rotation = 0;
  while (arr[rotation] < arr[rotation+1])
    rotation++;
  rotation++;
  int start = 0;
  int end = arr.size();
  int mid = (start+end)/2;
  while (start != end) { 
    if (arr[(mid+rotation)%arr.size()] == key)
      return (mid+rotation)%arr.size();
    else if (arr[(mid+rotation)%arr.size()] > key) {
      end = mid+1;
      mid = (start+end)/2;
    }
    else {
      start = mid;
      mid = (start+end)/2;
    }

  }
  return -1;
}
