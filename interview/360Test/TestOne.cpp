#include<iostream>
#include<vector>
using namespace std;


class student {
public:
	student(){}
	student(int a, int b, int c, int d){
		politic = a;
		English = b;
		math = c;
		profess = d;
		sum = a + b + c +d;
	}
	int judgeStu() {
		if (politic < 60 || English < 60 || math < 90 || profess < 90 || sum < 310)
			return 0;
		if (sum < 350)
			return 1;
		else
			return 2;
	}
private:
	int politic;
	int English;
	int math;
	int profess;
	int sum;
};

int main() {

	int N;
	cin>>N;
	vector<int> result;
	for (int i = 0; i < N; ++i) {
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		student stu(a,b,c,d);
		result.push_back(stu.judgeStu());
	}
	for (int i = 0; i < N; ++i) {
		if (result[i] == 0)
			cout<<"Fail";
		else if (result[i] == 1)
			cout<<"Zifei";
		else
			cout<<"Gongfei";
		if (i != N - 1)
			cout<<endl;
	}
	return 0;
}