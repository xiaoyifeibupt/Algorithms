/*
*分布式系统中的RPC请求经常出现乱序的情况。
*写一个算法来将一个乱序的序列保序输出。例如,假设起始序号是1，对于(1, 2, 5, 8, 10, 4, 3, 6, 9, 7)这个序列，输出是:
  1
  2
  3, 4, 5
  6
  7, 8, 9, 10
 
*上述例子中，3到来的时候会发现4,5已经在了。因此将已经满足顺序的整个序列（3, 4, 5）输出为一行。
 
*要求：
*1. 写一个高效的算法完成上述功能，实现要尽可能的健壮、易于维护
*2. 为该算法设计并实现单元测试
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printSeq(vector<int> aavec){
	if(aavec.size() == 0)
		return;
	set<int> bbset;
	bbset.insert(0);
	for(int i = 0; i < aavec.size(); ++i){
		bbset.insert(aavec[i]);
		vector<int> tem;
		while(bbset.size() >= 2 ){
			set<int>::iterator j = bbset.begin();
			set<int>::iterator x = j++;			
			if(*x == *j - 1){
				bbset.erase(x);
				tem.push_back(*j);
			}
			else
				break;				
		}
		for(int i = 0; i < tem.size(); i++){
			if(i == tem.size() - 1)
				cout<<tem[i]<<endl;
			else
				cout<<tem[i]<<",";
		}

	}
}

int main(){
	int na = 10;
	int aa[] = {1, 2, 5, 8, 10, 4, 3, 6, 9, 7};
	int nb = 10;
	int bb[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int nc = 10;
	int cc[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> aavec(aa, aa + na);
	vector<int> bbvec(bb, bb + nb);
	vector<int> ccvec(cc, cc + nc);
	vector<int> ddvec;
	cout<<"**********case 1***********"<<endl;
	printSeq(aavec);
	cout<<"**********case 2***********"<<endl;
	printSeq(bbvec);
	cout<<"**********case 3***********"<<endl;
	printSeq(ccvec);
	cout<<"**********case 4***********"<<endl;
	printSeq(ddvec);
	system("pause");
	return 0;
}
