#include<bits/stdc++.h>

using namespace std;
class animal {
	string name;
	int legs;

public:
	static int length;
	void speak();
	animal() {
		name = "x";
		legs = 0;
	}
	animal(animal &x) {
		name = x.name;
		legs = x.legs;
	}
	void setname(string s) {
		name = s;

	}
	void setleg(int x) {
		legs = x;
	}
	string getname() {
		return name;
	}

	int getleg() {
		return legs;
	}
};

int animal :: length = 100;
class dog : public animal {
public:
	void speak() {
		cout << "\n woof";
	}

};

class cat : public animal {
public:
	void speak() {
		cout << "\n meoww";
	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	// dog d;
	// cat c;
	// d.speak();
	// c.speak();

	animal dog;
	dog.setleg(4);
	string name = "siitu";
	dog.setname(name);

	cout << dog.getname() << " " << dog.getleg() << "\n";
	name = "bittu";
	animal dog2(dog);
	dog.setname(name);
	cout << dog.getname() << " " << dog.getleg() << "\n";
	cout << dog2.getname() << " " << dog2.getleg() << "\n";
	cout << animal::length;
	return 0;
}