#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cassert>
using namespace std;

template <typename T>                                //�N���X�e���v���[�g���쐬
size_t findOfall(T key, const vector<T>& v) {        //�������ꂽ�����ƃL�[�̐��̈�v�񐔂��J�E���g����֐�
	int n = v.size();
	int couOfran = 0;
	for (int i = 0; i <= n - 1; ++i) {
		if (v[i] == key) ++couOfran;
	}
	return couOfran;
}


int main() {

	random_device engine;

	cout << "�����𐶐�����͈͂̂����ŏ��̐�������͂��Ă��������B" << endl;
	int a;
	cin >> a;
	cout << "�����𐶐�����͈͂̂����ő�̐�������͂��Ă��������B" << endl;
	int b;
	cin >> b;

	assert(a <= b);                                         //�A�T�[�V�������g���� a<=b �Ƃ���B

	cout << "���������������̌�����͂��Ă��������B" << endl;
	int c;
	cin >> c;

	vector<int> v;
	size_t s = v.size();

	uniform_int_distribution<unsigned> dist1(a, b);        //��������������vector�Ɋi�[
	for (int i = 0; i < c; ++i) {
		v.push_back(dist1(engine));
	}

	sort(v.begin(), v.end());                              //���₷�����邽�߁A���בւ�
	auto begin = v.begin();
	auto end = v.end();

	ofstream outfile("kakuninn.txt", ios_base::out);       //�m�F�̂��߃t�@�C���o��
	for (int i = 0; i < c; ++i) {
		outfile << v[i] << " ,";
	}
	outfile.close();

	int d;
	cout << "�m�������؂�����������͂��Ă��������B" << endl;
	cin >> d;
	int target = d;

	assert(a <= d && d <= b);

	double couOfran = findOfall(target, v);
	double rate = (couOfran / c) * 100;
	if (rate == 0) cout << "���͂������͎w�肳�ꂽ���̗����̒��ɂ͊܂܂�܂���ł����B" << endl;
	else cout << "�w�肵�����́A" << rate << " ����������܂����B" << endl;

}