#include <iostream>
//#include <stdlib.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	const int N = 5;
	int G[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			G[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			G[i][j] = rand() % 2;
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			G[i][j] = G[j][i];
		}
	}



	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			G[i][j] = 0;
		}
	}
	G[0][1] = 1;
	G[0][2] = 1;
	G[1][0] = 1;
	G[1][2] = 1;
	G[2][0] = 1;
	G[2][1] = 1;
	G[2][3] = 1;
	G[3][2] = 1;
	G[4][0] = 1;
	G[4][1] = 1;
	G[4][2] = 1;
	G[4][3] = 1;*/


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << G[i][j] << "\t";
		}
		cout << "\n";
	}

	int s = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (G[i][j] == 1) {
				s = s + 1;
			}
		}
	}
	cout << s << "\n";
	int schet = 0;
	for (int i = 0; i < N; i++) {
		s = 0;
		
		for (int j = 0; j < N; j++) {
			s = s + G[i][j];
		}
		if (s == 0) {
			cout << i + 1 << " -изолированная вершина " << "\n";
			schet = schet + 1;
		}
	}
	if (schet == 0) {
		cout << "Изолированных вершин нет" << "\n";
	}

	schet = 0;
	for (int i = 0; i < N; i++) {
		s = 0;

		for (int j = 0; j < N; j++) {
			s = s + G[i][j];
		}
		if (s == 1) {
			cout << i + 1 << " -концевая вершина " << "\n";
			schet = schet + 1;
		}
	}
	if (schet == 0) {
		cout << "Концевых вершин нет" << "\n";
	}


	schet = 0;
	for (int i = 0; i < N; i++) {
		s = 0;

		for (int j = 0; j < N; j++) {
			s = s + G[i][j];
		}
		if (s == N) {
			cout << i + 1 << " -доминирующая вершина " << "\n";
			schet = schet + 1;
		}
	}
	if (schet == 0) {
		cout << "Доминирующих вершин нет" << "\n";
	}
}