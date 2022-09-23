#include <iostream>
#include <string>
class Human;
class Apple;

class String {
private:
	char* str;
	void copyValues(const String& other) {

		size_t length = strlen(other.str);
		this->str = new char[length + 1];
		for (size_t i = 0; i < length; i++) {
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}
public:
	//Constructors
	String() { this->str = nullptr; }
	String(const char* str) {
		size_t length = strlen(str);
		this->str = new char[length + 1];
		for (size_t i = 0; i < length; i++) this->str[i] = str[i];
		this->str[length] = '\0';
	}
	// Copy constructor
	String(const String& other) { copyValues(other); }

	// Move constructor
	String(String&& other) {
		this->str = other.str;
		other.str = nullptr;
	}
	// Operators
	String& operator = (const String& other) {
		if (this->str != nullptr) delete[] this->str;
		this->copyValues(other);
		return *this;
	}

	bool operator == (const String& other) {
		size_t length = strlen(this->str);
		if (length != strlen(other.str)) return false;
		for (size_t i = 0; i < length; i++) if (this->str[i] != other.str[i]) return false;
		return true;
	}

	bool operator != (const String& other) { return !this->operator==(other); }

	String operator +(const String& other) {
		String tmp;
		size_t thisLength = strlen(this->str);
		size_t otherLength = strlen(other.str);
		tmp = new char[thisLength + otherLength + 1];
		int i = 0;
		for (; i < thisLength; i++) tmp.str[i] = this->str[i];
		for (int j = 0; j < otherLength; j++, i++) tmp.str[i] = other.str[j];
		tmp.str[thisLength + otherLength] = '\0';
		return tmp;
	}

	char& operator[](int idx) {return this->str[idx];}

	// API
	void print() { for (size_t i = 0; i < strlen(this->str) + 1; i++)  std::cout << str[i]; std::cout << '\n'; }

	size_t length() { return strlen(this->str); }
	//Destructor
	~String() { delete[] this->str; }
};

class Point {
private:
	int x;
	int y;
public:
	// Constructors
	Point() {
		this->x = 0;
		this->y = 0;
	};
	Point(int x, int y) {
#ifdef DEBUG
		std::cout << this << " Constructor" << '\n';
#endif
		this->x = x;
		this->y = y;
	}
	// Copy constructor
	Point(const Point& other) {
#ifdef DEBUG
		std::cout << this << " Copy!" << '\n';
#endif 
		this->x = other.x;
		this->y = other.y;
	}

	// Operators

	Point& operator = (const Point& other) {
#ifdef DEBUG
		std::cout << this << " =!" << '\n';
#endif 
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	bool operator == (const Point& other) { return (this->x == other.x && this->y == other.y); }
	bool operator != (const Point& other) { return !this->operator==(other); }


	Point operator + (const Point& other) {

		Point tmp;
#ifdef DEBUG
		std::cout << &tmp << " Plus!" << '\n';
#endif 

		tmp.x = this->x + other.x;
		tmp.y = this->y + other.y;
		return tmp;
	}

	Point& operator ++ () {
		this->x++;
		this->y++;
		return *this;
	}

	Point& operator ++ (int value) {
		Point temp(*this);
		this->x++;
		this->y++;
		return temp;
	}

	Point& operator -- () {
		this->x--;
		this->y--;
		return *this;
	}

	Point& operator -- (int value) {
		Point tmp(*this);
		this->x--;
		this->y--;
		return tmp;
	}
	// Getter and setters

	int getX() { return this->x; }
	int getY() { return this->y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	//API
	void print() { std::cout << '[' << this->getX() << ':' << this->getY() << ']'; }


	// Destructor
	~Point() {
#ifdef DEBUG
		std::cout << this << " Destroyed!" << '\n';
#endif 
	}
};

class Human {
public:
	void takeApple(Apple& apple);
};

class Apple {
private:
	int weight;
	std::string color;

	friend void Human::takeApple(Apple& apple);
public:
	Apple(int weight, std::string color) {
		this->weight = weight;
		this->color = color;
	}
};

void Human::takeApple(Apple& apple) {
	std::cout << apple.color << '\t' << apple.weight << '\n';
}



int main() {
	String txt("Hello world!");
	String txt2("And biba boba!");

	String txt3 = txt + txt2;

	return 0;
}