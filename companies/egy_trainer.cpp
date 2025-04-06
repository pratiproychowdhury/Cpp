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
};
 
class Manager : public Person {
public:
	virtual void manageEmployees() {};
	vector<roles> role;
};
 
class Trainer : public Person {
public:
	virtual void coachMembers()= 0;
};
 
class Alex : public Manager, public Trainer {
public:
	void manageEmployees() {
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
	auto alex = new Person();
	alex.role.push_back(new Manager());
	alex.role.push_back(new Trainer());


    auto alex = Alex();
    alex.manageEmployees();
    alex.coachMembers();
        
    auto sam = Sam();
    sam.coachMembers();
}
