#include <iostream>  
#include <Eigen/Dense>  
using namespace std;
using namespace Eigen;
int main()
{
	Matrix2d mat;
	mat << 1, 2,
		3, 4;
	Vector2d u(-1, 1), v(2, 0);
	cout << "the mat is: \n" << mat << endl;
	cout << "the u is:\n" << u << endl;
	cout << "the v is:\n" << v << endl;
	cout << "Here is mat*mat:\n" << mat*mat << endl;
	cout << "Here is mat*u:\n" << mat*u << endl;
	cout << "here is u^T\n" << u.transpose() << endl;
	cout << "Here is u^T*v:\n" << u.transpose()*v << endl;
	cout << "Here is u*v^T:\n" << u*v.transpose() << endl;
}