#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
	double *Mat1 = new double[6];
	for (int i = 0; i < 6; i++)
	{
		Mat1[i] = i;
	}
	//静态矩阵，map使用
Eigen:Map<Matrix<double, 2, 3>>staMat(Mat1);
	cout << "显示静态矩阵：" << endl;
	for (int i = 0; i < staMat.size(); i++)
		cout << *(staMat.data() + i) << " ";
	cout << endl;
	//动态矩阵，map使用
	Map <MatrixXd> dyMat(Mat1, 2, 3);
	cout << "显示动态矩阵：" << endl;
	for (int i = 0; i < dyMat.size(); i++)
		cout << *(dyMat.data() + i) << " ";
	cout << endl;
}