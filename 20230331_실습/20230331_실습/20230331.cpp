#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;


class Shape {

	int side_num;
	int side_bottom_length;

public:
	Shape(int side_num, int side_bottom_length){
		this->side_num = side_num;
		this->side_bottom_length = side_bottom_length;
	}
	int get_side_bottom_length() {
		return side_bottom_length;
	}
	int printInfo() {
		return side_num, side_bottom_length;
	}
};


class Rectangle : public Shape {
	int height;
public:
	Rectangle(int side_num, int side_bottom_length, int height) : Shape(side_num, side_bottom_length){
		this->height = height;
	}
	int area() {

		return height * get_side_bottom_length();
	}
};
class Triangle : public Shape {
	int height;
public:
	Triangle(int side_num, int side_bottom_length, int height) : Shape(side_num, side_bottom_length) {
		this->height = height;
	}

	double area() {
		return (double) height * get_side_bottom_length() /2;
	}
};
int main() {
	Rectangle R(4,3,5);
	Triangle T(3, 3, 5);

	std::cout << R.printInfo() << std::endl;
	std::cout << R.area() << " " << T.area();
}