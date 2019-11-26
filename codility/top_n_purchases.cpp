/*
for each purchase
    increment the number purchases of this product in the inordered_map
    
after all purchases are processes
    insert all the info in this unordered_map into the heap
    
return the n top selling product getting the top of the heap
*/

struct purchase {
    purchaseId;
    custId;
    int itemId;
    timestamp;
};

struct product {
    int itemId;
    int numPurchases;
};

boolean compare(product a, product b) {
  return a.numPurchases > b.numPurchases;
}

vector<int> calculate(vector<purchase> sales, int topn) {

  unordered_map<int, int> numpurchases;
  priority_queue<struct product, vector<struct product>, compare> shop;
    
  for (vector<purchase>::iterator z=sales.begin(); z!=sales.end(); z++)
    numpurchases[z->itemId]++;
    
  for (unordered_map<int, int>::iterator purchases=numpurchases.begin(); purchases!=numpurchases.end(); purchases++)
    shop.push(new product(purchases->first, purchases->second));
    
  vector<int> rank(topn);
  for (int i=0; i<topn; i++) {
    if (shop.empty())
      return rank;
    rank.push_back(shop.top()->itemId);
    shop.pop();
  }

  return rank;   
}
