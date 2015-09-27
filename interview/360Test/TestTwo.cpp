#include<iostream>
#include<vector>
using namespace std;
const char zero[5][3] = {{' ','-',' '},{'|', ' ', '|'},{' ', ' ', ' '},{'|', ' ', '|'},{' ','-',' '}};
const char one[5][3] = {{' ',' ',' '},{' ', '|', ' '},{' ', ' ', ' '},{' ', '|', ' '},{' ',' ',' '}};
const char two[5][3] = {{' ','-',' '},{' ', ' ', '|'},{' ', '-', ' '},{'|', ' ', ' '},{' ','-',' '}};
const char three[5][3] = {{' ','-',' '},{' ', ' ', '|'},{' ', '-', ' '},{' ', ' ', '|'},{' ','-',' '}};
const char four[5][3] = {{' ',' ',' '},{'|', ' ', '|'},{' ', '-', ' '},{' ', ' ', '|'},{' ',' ',' '}};
const char five[5][3] = {{' ','-',' '},{'|', ' ', ' '},{' ', '-', ' '},{' ', ' ', '|'},{' ','-',' '}};
const char six[5][3] = {{' ','-',' '},{'|', ' ', ' '},{' ', '-', ' '},{'|', ' ', '|'},{' ','-',' '}};
const char seven[5][3] = {{' ','-',' '},{' ', ' ', '|'},{' ', ' ', ' '},{' ', ' ', '|'},{' ',' ',' '}};
const char eight[5][3] = {{' ','-',' '},{'|', ' ', '|'},{' ', '-', ' '},{'|', ' ', '|'},{' ','-',' '}};
const char ning[5][3] = {{' ','-',' '},{'|', ' ', '|'},{' ', '-', ' '},{' ', ' ', '|'},{' ','-',' '}};
vector<vector<char> > ONE(one,one + 15);
vector<vector<char> > TWO(two,two + 15);
const char squ[5][3] = {{' ',' ',' '},{' ', ' ', ' '},{' ', '*', ' '},{' ', ' ', ' '},{' ',' ',' '}};

/*
vector<char> Num2Image(int num) {
	vector<vector<vector<char> > >result;
	vector<int> digit;
	while (num) {
		digit.push_back(num % 10);
		num /= 10;
	}
//	reverse(digit.begin(), digit.end());
	for (int i = digit.size() - 1; i >= 0; --i) {
		switch (digit[i]) {
		case 1:
			
			result.push_back(ONE);
			break;
		default:
				break;
		}
	}
}

*/
vector<int> dividePrime(int num) {
	vector<int> result;
	for(int i = 2; i <= num; i++)
		while(num != i) {
			if(num % i == 0) {
				result.push_back(i);
				num = num / i;
			} else
				break;
		}
		result.push_back(num);
		return result;
}

int main() {
	vector<int> result = dividePrime(2012);

	return 0;
}