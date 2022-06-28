#include <iostream>
#include<vector>
#include <string>

using namespace std;
//
//1. An abstract Subject class

//2. A concrete Subject class which is ALSO a Singleton (based on assignment #1 or assignment #2)

//3. A Observer interface

//4. Add a few (at least 3) concrete Observer class, in the update method print each concrete observers name

//5. And finally, the code that shows how the concrete observer attaches to the Subject

//6. make a change in the Subject and make sure the Observers get the updates (and print the messages)


//Abstract class, base
class Observer
{
public:
	virtual void update(string& n) = 0;
};


class Subject 
{
private:
	string message_;
	vector<Observer*> observers;

public:

	void attach(Observer* o)
	{
		observers.push_back(o);
	}

	void detach(Observer* o)
	{
		int count;
		int c = observers.size();

		for (count = 0; count < observers.size(); count++)
		{
			if (observers[count] == o)
				break;
		}

		if (count < c)
		{
			observers.erase(observers.begin() + count);
		}
	}

	void notify()
	{
		for (size_t i = 0; i < observers.size(); i++)
		{
			observers[i]->update(message_);
		}
	}

	void CreateMessage(string message)
	{
		this->message_ = message;
	}
};




class University : public Subject
{
private:
	string message_;
	int number;
protected:
	University() {}
	static University* myInstance;

public:
	void setMessage(string mess);
	static University* GetInstance();

};

University* University::myInstance = nullptr;

University* University::GetInstance()
{

	if (myInstance == nullptr) {
		myInstance = new University();
	}
	return myInstance;
}

void University::setMessage(string mess)
{
	CreateMessage(mess);
	notify();
}


//Observer classes
class Department : public Observer
{
private:
	int num;
	static int num2;
	string m;
public:
	Department()
	{
		this->num = num2;
		cout << "Department # " << ++num2 << " created.\n";
		University::GetInstance()->attach(this);

	}

	void update(string& m); 
	void printInfo(string& m)
	{
		cout << "Department Message: " << m << endl;
	}

	void Remove()
	{
		University::GetInstance()->detach(this);
	}
};


void Department::update(string& m)
{
	cout << "Updated message for Department: " << endl;
	printInfo(m);
}

int Department::num2 = 0;



//Observer classes
class Building : public Observer
{
private:
	int num;
	static int num2;
	string m;
public:
	Building()
	{
		this->num = num2;
		cout << "Building # " << ++num2 << " created.\n";
		University::GetInstance()->attach(this);

	}

	void update(string& m);
	void printInfo(string& m)
	{
		cout << "Building Message: " << m << endl;
	}

	void Remove()
	{
		University::GetInstance()->detach(this);
	}
};


void Building::update(string& m)
{
	cout << "Updated message for Building: " << endl;
	printInfo(m);
}

int Building::num2 = 0;



//Observer classes
class Student : public Observer
{
private:
	int num;
	static int num2;
	string m;
public:
	Student()
	{
		this->num = num2;
		cout << "Student # " << ++num2 << " created.\n";
		University::GetInstance()->attach(this);

	}

	void update(string& m);
	void printInfo(string& m)
	{
		cout << "Student Message: " << m << endl;
	}

	void Remove()
	{
		University::GetInstance()->detach(this);
	}
};


void Student::update(string& m)
{
	cout << "Updated message for Student: " << endl;
	printInfo(m);
}

int Student::num2 = 0;


int main()
{
	string k = "CSUSM";
	University* subject = University::GetInstance(); //create an instance of university which is a subject/singleton
	Student* observer1 = new Student(); //create a student observer
	Building* observer2 = new Building(); //create a Building observer
	Department* observer3 = new Department(); //create a Department observer
	Department* observer4 = new Department(); //create a Department observer
	subject->setMessage("Hello All");
	subject->setMessage("Goodbye All");
	subject->detach(observer1);
	subject->setMessage("I removed student");

}