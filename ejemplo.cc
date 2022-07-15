#include <global.hh>
#include <omp.h>
#include <cstdlib>
#include <random>

int pi_value(int num_trials)
{
	uint32_t trials_in_circ = 0; 
	double pi;
	double x, y;
	double r = 1.0; 

	for(uint32_t i=0; i<num_trials; i++){
		//rand()%(max-min + 1) + min
		//x = rand(-r,r); 
		std::mt19937 rng(1298321);
		std::uniform_int_distribution<double> gen(-r, r); // uniform, unbiased
		x = gen(rng);
		y = gen(rng);
		std::cout << "x: " << x << " y:" << y << std::endl;
		if ( (x*x + y*y) <= (r*r)) trials_in_circ++;
	}
	pi = 4.0 * ((double) trials_in_circ /(double)num_trials);
	std::cout << "TIC: " << trials_in_circ << " pi:" << pi << std::endl;
	return(pi); 
}


int main(int argc , char *argv []) {

	std::cout << "pi: " << pi_value(10) << std::endl;
	/*
	//Por omisión, se paraleliza con la capacidad del HW
	int32_t nt = omp_get_max_threads();
	
	///////////////////////////////////////
	//  Read command-line parameters
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-nt") {
			nt = atoi(argv[i+1]);
		}
	}
	
	uint32_t totalData = 20;
	
	#pragma omp parallel for  num_threads(nt)
	for(size_t i = 0; i < totalData; ++i){	
		int32_t thID = omp_get_thread_num();
		#pragma omp critical
		{
			std::cout << "thID:" << thID << ",i=" << i << std::endl;
		}
	}
	
	return(EXIT_SUCCESS);
	*/
}
