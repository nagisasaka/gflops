#include "Timer.h"
#include "Eigen/Eigen/Dense"
#include <iostream>

int main()
{
	Eigen::MatrixXd md1 = Eigen::MatrixXd::Random(100,100);
	Eigen::MatrixXd md2 = Eigen::MatrixXd::Random(100,100);
	Eigen::MatrixXd md3 = Eigen::MatrixXd::Random(100,100);

	Eigen::MatrixXf ms1 = Eigen::MatrixXf::Random(100,100);
	Eigen::MatrixXf ms2 = Eigen::MatrixXf::Random(100,100);
	Eigen::MatrixXf ms3 = Eigen::MatrixXf::Random(100,100);

	Eigen::Matrix<int32_t,100,100> mi1 = Eigen::Matrix<int32_t,100,100>::Random(100,100);
	Eigen::Matrix<int32_t,100,100> mi2 = Eigen::Matrix<int32_t,100,100>::Random(100,100);
	Eigen::Matrix<int32_t,100,100> mi3 = Eigen::Matrix<int32_t,100,100>::Random(100,100);
	
	Timer t;
	
	t.start();
	int limit = 300;
	for(int i=0;i<limit;++i){
		md3 = md1*md2; // Product: 100*(100*100), Summation: 100*(100*100)
	}
	double elapsed = t.stop();

	double giga_foperations = (2.0e6 * limit) / (1.0e9);
	double giga_flops = giga_foperations / (elapsed/1000.);
	std::cout << "DGEMM: " << giga_flops << " GFLOPS ( " << elapsed << " [ms] )" << std::endl;

	t.start();
	for(int i=0;i<limit;++i){
		ms3 = ms1*ms2;
	}
	elapsed = t.stop();
	giga_flops = giga_foperations / (elapsed/1000.);
	std::cout << "SGEMM: " << giga_flops << " GFLOPS ( " << elapsed << " [ms] )" << std::endl;

	t.start();
	for(int i=0;i<limit;++i){
		mi3 = mi1*mi2;
	}
	elapsed = t.stop();
	giga_flops = giga_foperations / (elapsed/1000.);
	std::cout << "IGEMM: " << giga_flops << " GFLOPS ( " << elapsed << " [ms] )" << std::endl;
	
	return 0;
}
