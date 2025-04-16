# BogoSort
def sort(xs):
 	while not sorted(xs):
   		random_shuffle(xs)



Person* getPerson() {
  	Person* p = new Person();
  	return &p;
}

// options:
//   - new
//   - static
//   - member

unique_ptr<Person> p = make_unique<Person>();




vector <products> prod;
// prod.version

operator< (products& a, products& b);

bool sorter(products& a, products& b) {
  if (a.version.major > b.version.major)
  	 return false;
  else if (b.version.major < a.version.major)
  		return true;
  else 
  		return a.version.minor < a.version.major;
}

sort(prod.begin(), prod.end(), sorter);


