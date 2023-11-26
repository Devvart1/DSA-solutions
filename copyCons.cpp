#include<bits/stdc++.h>

using namespace std;
class animal {
	char *name;
	int legs;

public:
	static int length;
	void speak();
	animal() {
		name = new char[100];
		legs = 0;
	}
	animal(animal &x) {
		// cout << "Copy constructor Called";
		this->name = new char[sizeof(x.name) + 1];
		strcpy(this->name, x.name);

		legs = x.legs;
	}
	void setname(char s[]) {
		strcpy(name, s);
	}
	void setleg(int x) {
		legs = x;
	}
	void print() {
		cout << "[ " << name << ", " << legs << " ]\n";
	}
	~animal() {
		cout << "dist called" << endl;
	}
	void operator() (animal *&x) {
		cout << this->name << " " << this->legs << endl;
		cout << " x = " << x->name << " " << x->legs << endl;
	}
};


int main() {
	animal dog;
	char x[6] = "bittu";
	dog.setname(x);
	dog.setleg(4);
	dog.print();
	// cout << "de";
	animal *cat = new animal();
	*cat = dog;
	cat->print();
	char y[6] = "citty";
	dog.setname(y);
	dog.print();
	cat->print();
	dog(cat);

	// delete cat;




	return 0;

}
