#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cassert>
using namespace std;

template <typename T>                                //クラステンプレートを作成
size_t findOfall(T key, const vector<T>& v) {        //生成された乱数とキーの数の一致回数をカウントする関数
	int n = v.size();
	int couOfran = 0;
	for (int i = 0; i <= n - 1; ++i) {
		if (v[i] == key) ++couOfran;
	}
	return couOfran;
}


int main() {

	random_device engine;

	cout << "乱数を生成する範囲のうち最小の整数を入力してください。" << endl;
	int a;
	cin >> a;
	cout << "乱数を生成する範囲のうち最大の整数を入力してください。" << endl;
	int b;
	cin >> b;

	assert(a <= b);                                         //アサーションを使って a<=b とする。

	cout << "生成したい乱数の個数を入力してください。" << endl;
	int c;
	cin >> c;

	vector<int> v;
	size_t s = v.size();

	uniform_int_distribution<unsigned> dist1(a, b);        //生成した乱数をvectorに格納
	for (int i = 0; i < c; ++i) {
		v.push_back(dist1(engine));
	}

	sort(v.begin(), v.end());                              //見やすくするため、並べ替え
	auto begin = v.begin();
	auto end = v.end();

	ofstream outfile("kakuninn.txt", ios_base::out);       //確認のためファイル出力
	for (int i = 0; i < c; ++i) {
		outfile << v[i] << " ,";
	}
	outfile.close();

	int d;
	cout << "確率を検証したい数を入力してください。" << endl;
	cin >> d;
	int target = d;

	assert(a <= d && d <= b);

	double couOfran = findOfall(target, v);
	double rate = (couOfran / c) * 100;
	if (rate == 0) cout << "入力した数は指定された個数の乱数の中には含まれませんでした。" << endl;
	else cout << "指定した数は、" << rate << " ％生成されました。" << endl;

}