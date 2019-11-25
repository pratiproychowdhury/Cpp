struct purchase {
    purchaseId,
    custId,
    vector<int> itemId,
    timestamp
}


struct product {
    int itemId;
    int numPurchases;
}

ordered_map <int, int> numpurchases;

priority_queue<struct product> shop;

m purchases, n products

m*log(n)

n



vector<int> calculate(vector<purchase> sales, int topn) {
    
    for (vector<purchase>::iterator z=sales.begin(); z!=sales.end(); z++) {
        for
            ordered_map <int, int>::iterator thisproduct = numpurchases.find(z->itemId);
            if (thisproduct != numpurchases.end()) // is already in the hash
                thisproduct.emplace(thisproduct<1>, thisproduct<2>+1);
            else
                numpurchases.emplace(z->purchaseId, 1);
    }
    
    for (ordered_map <int, int>::iterator purchases = numpurchases.begin(); purchases!=numpurchases.end(); purchases++)
        shop.push(new product(purchases->first, purchases->second));
    
    vector<int> rank(topn);
    for (int i=0; i<topn; i++) {
        rank.push_back(shop.top()->first);
        shop.pop();
    }
     
    return rank;   
}



for each purchase
    increment the number purchases of this product in the inordered_map
    
after all purchases are processes
    insert all the info in this unordered_map into the heap
    
return the n top selling product getting the top of the heap

    
