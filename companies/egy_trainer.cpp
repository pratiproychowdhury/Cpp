/*
 *
 * The following snippets design the classes and interfaces for the following scenario:
 *
 *  Alex and Sam work for a gym.
 *  Alex works as manager and a trainer.
 *  Sam works as a trainer.
 *  A trainer's behavior is to coach gym members and
 *  a manager's behavior is to manage employees.
 *  
 */

class Person {
public:    
	string name;
	vector<Person *> role;
};
 
class Manager : public Person {
public:
	virtual void manageEmployees() {};
	vector<Person> subordinates;
};
 
class Trainer : public Person {
    string sport;
public:
	virtual void coachMembers() {};
};
 
class Alex : public Manager, public Trainer {
public:
	void manageEmployees() override {
    		//implementation goes here
	}
 
	void coachMembers() override {
    		//implementation goes here
	}
};
 
class Sam : public Trainer { 
public:
	void coachMembers() override {
	    	//implementation goes here
	}
};
	 
int main() {
	auto people = new Person();
	people->role.push_back(new Manager());
	people->role.push_back(new Trainer());

	auto alex = Alex();
	alex.manageEmployees();
	alex.coachMembers();
	
	auto sam = Sam();
	sam.coachMembers();
}
