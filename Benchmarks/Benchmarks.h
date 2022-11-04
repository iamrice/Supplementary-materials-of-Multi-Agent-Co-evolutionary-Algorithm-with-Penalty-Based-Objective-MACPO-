#ifndef BENCHMARKS_H
#define BENCHMARKS_H

#include <string>
#include <vector>
#include "../util/json.hpp"
using json = nlohmann::json;
using std::string;
using std::vector;

class Benchmarks {
private:
	int group_num;
    json func_config;
	string funcID;
	template<typename T>T** read_data(string);
	
	// 第一类函数的变量
	int **group;
	double ***R, **xopt;
	double local_eva_for_global_solution(double*, int);
	bool overlap_grouping;
	double local_eva_type1(double* x, int groupIndex);
	// 第二类函数的变量
	double **R_global, **A, **W=nullptr;
	bool if_rotate;
	bool if_shift;
	double local_eva_type2(double* x, int groupIndex);
	double global_eva_type2(double* x);
	int funcClass;
	// string funcType;
	double weight;
	bool if_heterogeneous;
public:
	int max_eva_times;
	int eva_count;
	bool reach_max_eva_times;
	Benchmarks(string ID,int max_eva_times = 3000000, bool = true);
	~Benchmarks();
	double global_eva(double* x);
	double local_eva(double* x, int groupIndex);
	double getMinX();
	double getMaxX();
	int getGroupNum();
	int getDimension();
    vector<int> getOverlapDim(int g1,int g2);
    vector<int> getOverlapDimIndex(int g1,int g2);
    vector<int> getGroupDim(int g);
	vector<int> getGroupExcluDim(int groupIndex);
	vector<int> getOverlapGroup(int g);
	double getBestFitness();
	bool reachMaxEva();
	double getLocalOpt(int groupIndex);
	double** getNetworkGraph();
};

#endif