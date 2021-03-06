


#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>
using namespace std;
void my_set_color(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}
enum COLORS {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	AQUA = 3,
	RED = 4,
	PURPLE = 5,
	YELLOW = 6,
	WHITE = 7,
	GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_AQUA = 11,
	LIGHT_RED = 12,
	LIGHT_PURPLE = 13,
	LIGHT_YELLOW = 14,
	BRIGHT_WHITE = 15
};
void main() {
	srand(time(0));
	const int row = 21;
	const int col = 21;
	char mas[row][col] = {};//birinci və ikinci cədvəlləri qurmaq və həmçinin birinci cədvəlin gəmilərini göstərmək üçün massiv
	const int row1 = 10;
	const int col1 = 10;
	char mas1[row1][col1] = {};//Ikinci cədvəlin xanalarında gəmiləri göstərmək üçün
	const int num_row = 10;
	const int num_col = 10;
	short arr[num_row][num_col]{}; //massiv birinci cədvəlin xanalarının içində olan elementlər
	const int num_row1 = 15;
	const int num_col1 = 15;
	short arr1[num_row1][num_col1] = {}; //ikinci cədvəlin xanalarının içində olan elementlər üçün
	short count_row = 0;
	short count_col = 0;
	short x = 0;
	short c = 0; // Xananin içində əks olunan dəyərləri dəyişmək üçün. 1-ci cədvəldə
	short c1 = 1; // Xananin içində əks olunan dəyərləri dəyişmək üçün. 2-ci cədvəldə
	short a; //Xananın içində olan. dəyər alan indekslərin koordinatları üçün ki onları yazıb dəyəri dəyişmək olsun.
	short b; //Xananın içində olan. dəyər alan indekslərin koordinatları üçün ki onları yazıb dəyəri dəyişmək olsun.
	short s = 0; //ikinci cədvəlin üst hissəsini qurmaq üçün lazımdır ki, kod bir dəfə müraciət eləsin ikinci cədvəlin üst hissəsini qurmaga
	short k = 0; //Dəyər alan massivin növbəti sətrə keçməsini bir vahid ləngitmək üçün
	short user_or_komp = 0; //komp və user arasında ardıcıllığı təyin edir döyüş zamanı
	short m; //Gəmilərin sayını təyin etmək üçün 1-dən 4-ə kimi
	short one = 0, two = 0, three = 0, four = 0;
	short horizontal = 0; //gemilerin horizontal duzulushu uchun. eger sifir olmasa vertikal duzsun--------
	char ABC[] = { 'A','B','C','D','E','F','G','H','I','J' }; //massiv
	short v1, l1, v2, l2;
	short v3, v4, l3, l4;
	short compartment = 0; //Gəminin vurulmamış xanalarını saymaq üçün. Əgər heç olmasa bir vurulmamış xana varsa gəminin ətrafına uldular düzməsin deyə
	short horizontal_ship_lenght = -1; //horizontal gəminin uzunlugunu bilmek uchun
	short vertikal_ship_lenght = -1; //horizontal gəminin uzunlugunu bilmek uchun
	short user_win = 0, komp_win = 0;
	short star_definition_row, star_definition_col, slip_for_star_row, slip_for_star_col; //Gəminin uzunluğuna görə ulduzları düzməsi üçün
	system("color 06");
	while (one != 4 || two != 3 || three != 2 || four != 1) { // 1-ci cədvəlin içinə gəmilərin qoyulması üçün
		one = 0; two = 0; three = 0; four = 0;
		for (int i = 0; i < num_row; i++) { //birinci cədvəl arr massivi üçün random elementlərə dəyər vermə
			while (count_col < num_col) {
				m = rand() % 5;//0-dən 4-də ədədlər alır. Hansı ədədi alsa o qədər saylı gəmi qoyur sətir üzrə
				horizontal = rand() % 2;
				if (m == 4 && four == 0) {// 4 dama gəmi start****-----
					if (horizontal == 1 && num_col - count_col - 1 >= 4) { // Horizontal start
						if (i > 0 && count_col > 0) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0 &&
								arr[i - 1][count_col + 2] == 0 && arr[i - 1][count_col + 3] == 0 && arr[i - 1][count_col + 4] == 0) {
								four++;
								for (int j = 0; j < m; j++) {
									arr[i][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else if (i > 0) {
							if (arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0 &&
								arr[i - 1][count_col + 2] == 0 && arr[i - 1][count_col + 3] == 0 && arr[i - 1][count_col + 4] == 0) {
								four++;
								for (int j = 0; j < m; j++) {
									arr[i][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else {
							four++;
							for (int j = 0; j < m; j++) {
								arr[i][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					} //horizontal finish
					else if (horizontal == 0 && i <= 5) { //vertikal start------------
						if (i > 0 && count_col > 0 && count_col < 9) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0 &&
								arr[i - 1][count_col + 1] == 0) { //Vertikal
								four++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 0) {
							if (arr[i - 1][count_col] == 0 &&
								arr[i - 1][count_col + 1] == 0) { //Vertikal
								four++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 9) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0) { //Vertikal
								four++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else {
							four++;
							for (int j = i; j < m + i; j++) {
								arr[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
							}
							count_col++; //növbəti elementə keçid
						}
					} //vertikal finish---------
				}// 4 dama gəmi finish****-----
				else if (m == 3 && three <= 1) {// 3 dama gəmi start****----
					if (horizontal == 1 && num_col - count_col - 1 >= 3) { // Horizontal start
						if (i > 0 && count_col > 0) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0 &&
								arr[i - 1][count_col + 2] == 0 && arr[i - 1][count_col + 3] == 0) {
								three++;
								for (int j = 0; j < m; j++) {
									arr[i][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else if (i > 0) {
							if (arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0 &&
								arr[i - 1][count_col + 2] == 0 && arr[i - 1][count_col + 3] == 0) {
								three++;
								for (int j = 0; j < m; j++) {
									arr[i][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else {
							three++;
							for (int j = 0; j < m; j++) {
								arr[i][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					} //horizontal finish
					else if (horizontal == 0 && i <= 6) { //vertikal start------------
						if (i > 0 && count_col > 0 && count_col < 9) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0 &&
								arr[i - 1][count_col + 1] == 0) { //Vertikal
								three++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 0) {
							if (arr[i - 1][count_col] == 0 &&
								arr[i - 1][count_col + 1] == 0) { //Vertikal
								three++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}

						}
						else if (i > 0 && count_col == 9) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0) { //Vertikal
								three++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else {
							three++;
							for (int j = i; j < m + i; j++) {
								arr[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
							}
							count_col++; //növbəti elementə keçid
						}
					} //vertikal finish---------
				}// 3 dama gəmi finish****-----
				else if (m == 2 && two <= 2) {// 2 dama gəmi start****-----
					if (horizontal == 1 && num_col - count_col - 1 >= 2) { // Horizontal start
						if (i > 0 && count_col > 0) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0 &&
								arr[i - 1][count_col + 2] == 0) {
								two++;
								for (int j = 0; j < m; j++) {
									arr[i][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else if (i > 0) {
							if (arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0 &&
								arr[i - 1][count_col + 2] == 0) {
								two++;
								for (int j = 0; j < m; j++) {
									arr[i][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else {
							two++;
							for (int j = 0; j < m; j++) {
								arr[i][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}

					} //horizontal finish
					else if (horizontal == 0 && i <= 7) { //vertikal start------------
						if (i > 0 && count_col > 0 && count_col < 9) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0 &&
								arr[i - 1][count_col + 1] == 0) { //Vertikal
								two++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 0) {
							if (arr[i - 1][count_col] == 0 &&
								arr[i - 1][count_col + 1] == 0) { //Vertikal
								two++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 9) {
							if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0) { //Vertikal
								two++;
								for (int j = i; j < m + i; j++) {
									arr[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else {
							two++;
							for (int j = i; j < m + i; j++) {
								arr[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
							}
							count_col++; //növbəti elementə keçid
						}
					} //vertikal finish---------
				}// 2 dama gəmi finish****-----
				else if (m == 1 && one <= 3 && num_col - count_col - 1 >= 1) {// 1 dama gəmi start****----
					if (i > 0 && count_col > 0) {
						if (arr[i - 1][count_col - 1] == 0 && arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0) {
							one++;
							for (int j = 0; j < m; j++) {
								arr[i][count_col] = 1; // 1 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					}
					else if (i > 0) {
						if (arr[i - 1][count_col] == 0 && arr[i - 1][count_col + 1] == 0) {
							one++;
							for (int j = 0; j < m; j++) {
								arr[i][count_col] = 1; // 1 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					}
					else {
						one++;
						for (int j = 0; j < m; j++) {
							arr[i][count_col] = 1; // 1 damalı gəmi qoymaq üçün Horizontal
							count_col++; //növbəti elementə keçid
						}
					}
				} // 1 damali gemilerin qoyulmasi finish
				if (count_col < num_col) { //---------
					count_col++;
				}
			}
			count_col = 0;
		}
	} //1-ci cədvəlin içinə gəmilərin qoyulması üçün(Finish)
	one = 0; two = 0; three = 0; four = 0; // 2-ci cədvəl üçün

	while (one != 4 || two != 3 || three != 2 || four != 1) {// 2-ci cədvəl elementlər başlanğıc. Əgər 1 dörd damalı, 2 üç damalı, 3 iki damalı, 4 bir damalı gəmi alınmadısa bu halda yenidən gəmiləri təyin etsin deyə.
		one = 0; two = 0; three = 0; four = 0;
		for (int i = 0; i < num_row; i++) { //birinci cədvəl arr massivi üçün random elementlərə dəyər vermə
			while (count_col < num_col) {
				m = rand() % 5;//0-dən 4-də ədədlər alır. Hansı ədədi alsa o qədər saylı gəmi qoyur sətir üzrə
				horizontal = rand() % 2;
				if (m == 4 && four == 0) {// 4 dama gəmi start****---
					if (horizontal == 1 && num_col - count_col - 1 >= 4) { // Horizontal start
						if (i > 0 && count_col > 0) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0 &&
								arr1[i - 1][count_col + 2] == 0 && arr1[i - 1][count_col + 3] == 0 && arr1[i - 1][count_col + 4] == 0) {
								four++;
								for (int j = 0; j < m; j++) {
									arr1[i][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else if (i > 0) {
							if (arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0 &&
								arr1[i - 1][count_col + 2] == 0 && arr1[i - 1][count_col + 3] == 0 && arr1[i - 1][count_col + 4] == 0) {
								four++;
								for (int j = 0; j < m; j++) {
									arr1[i][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else {
							four++;
							for (int j = 0; j < m; j++) {
								arr1[i][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					} //horizontal finish
					else if (horizontal == 0 && i <= 5) { //vertikal start------------
						if (i > 0 && count_col > 0 && count_col < 9) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0 &&
								arr1[i - 1][count_col + 1] == 0) { //Vertikal
								four++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 0) {
							if (arr1[i - 1][count_col] == 0 &&
								arr1[i - 1][count_col + 1] == 0) { //Vertikal
								four++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 9) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0) { //Vertikal
								four++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün vertikal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else {
							four++;
							for (int j = i; j < m + i; j++) {
								arr1[j][count_col] = 1; // 4 damalı gəmi qoymaq üçün vertikal
							}
							count_col++; //növbəti elementə keçid
						}
					} //vertikal finish---------
				}// 4 dama gəmi finish****-----
				else if (m == 3 && three <= 1) {// 3 dama gəmi start****-----
					if (horizontal == 1 && num_col - count_col - 1 >= 3) { // Horizontal start
						if (i > 0 && count_col > 0) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0 &&
								arr1[i - 1][count_col + 2] == 0 && arr1[i - 1][count_col + 3] == 0) {
								three++;
								for (int j = 0; j < m; j++) {
									arr1[i][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else if (i > 0) {
							if (arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0 &&
								arr1[i - 1][count_col + 2] == 0 && arr1[i - 1][count_col + 3] == 0) {
								three++;
								for (int j = 0; j < m; j++) {
									arr1[i][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else {
							three++;
							for (int j = 0; j < m; j++) {
								arr1[i][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					} //horizontal finish
					else if (horizontal == 0 && i <= 6) { //vertikal start------------
						if (i > 0 && count_col > 0 && count_col < 9) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0 &&
								arr1[i - 1][count_col + 1] == 0) { //Vertikal
								three++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 0) {
							if (arr1[i - 1][count_col] == 0 &&
								arr1[i - 1][count_col + 1] == 0) { //Vertikal
								three++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 9) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0) { //Vertikal
								three++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else {
							three++;
							for (int j = i; j < m + i; j++) {
								arr1[j][count_col] = 1; // 3 damalı gəmi qoymaq üçün Horizontal
							}
							count_col++; //növbəti elementə keçid
						}
					} //vertikal finish---------
				}// 3 dama gəmi finish****-----
				else if (m == 2 && two <= 2) {// 2 dama gəmi start****-----
					if (horizontal == 1 && num_col - count_col - 1 >= 2) { // Horizontal start
						if (i > 0 && count_col > 0) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0 &&
								arr1[i - 1][count_col + 2] == 0) {
								two++;
								for (int j = 0; j < m; j++) {
									arr1[i][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else if (i > 0) {
							if (arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0 &&
								arr1[i - 1][count_col + 2] == 0) {
								two++;
								for (int j = 0; j < m; j++) {
									arr1[i][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
									count_col++; //növbəti elementə keçid
								}
							}
						}
						else {
							two++;
							for (int j = 0; j < m; j++) {
								arr1[i][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					} //horizontal finish
					else if (horizontal == 0 && i <= 7) { //vertikal start------------
						if (i > 0 && count_col > 0 && count_col < 9) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0 &&
								arr1[i - 1][count_col + 1] == 0) { //Vertikal
								two++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 0) {
							if (arr1[i - 1][count_col] == 0 &&
								arr1[i - 1][count_col + 1] == 0) { //Vertikal
								two++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else if (i > 0 && count_col == 9) {
							if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0) { //Vertikal
								two++;
								for (int j = i; j < m + i; j++) {
									arr1[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
								}
								count_col++; //növbəti elementə keçid
							}
						}
						else {
							two++;
							for (int j = i; j < m + i; j++) {
								arr1[j][count_col] = 1; // 2 damalı gəmi qoymaq üçün Horizontal
							}
							count_col++; //növbəti elementə keçid
						}
					} //vertikal finish---------
				}// 2 dama gəmi finish****-----
				else if (m == 1 && one <= 3 && num_col - count_col - 1 >= 1) {// 1 dama gəmi start****----
					if (i > 0 && count_col > 0) {
						if (arr1[i - 1][count_col - 1] == 0 && arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0) {
							one++;
							for (int j = 0; j < m; j++) {
								arr1[i][count_col] = 1; // 1 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					}
					else if (i > 0) {
						if (arr1[i - 1][count_col] == 0 && arr1[i - 1][count_col + 1] == 0) {
							one++;
							for (int j = 0; j < m; j++) {
								arr1[i][count_col] = 1; // 1 damalı gəmi qoymaq üçün Horizontal
								count_col++; //növbəti elementə keçid
							}
						}
					}
					else {
						one++;
						for (int j = 0; j < m; j++) {
							arr1[i][count_col] = 1; // 1 damalı gəmi qoymaq üçün Horizontal
							count_col++; //növbəti elementə keçid
						}
					}
				} // 1 damali gemilerin qoyulmasi finish
				if (count_col < num_col) { //------------------------------------
					count_col++;
				}
			}
			count_col = 0;
		}
	}//******************************2-ci cədvəl gəmilər son
	while (user_win <= 21 && komp_win <= 21) {
		if (user_win == 21) {
			cout << " ";
			break;
		}
		if (komp_win == 21) {
			cout << " ";
			break;
		}
		int d = 0;
		for (int i = 0; i < 10; i++) { // Hərflərin üstdə çap edilməsi üçün.(Başlanğıc)
			if (i == 0)
				cout << " ";
			else
				cout << " ";
			cout << ABC[i];
			if (i == 9 && d == 0) {
				cout << "\t\t\t";
				i = -1;
				d++;
			}
		}
		d = 0;
		cout << endl; // Hərflərin üstdə çap edilməsi üçün.(Son)
		for (int i = 0; i < row; i++) { //Dama cədvəl başlanğıc
			s = 0;
			k = 0;
			for (int j = 0; j < col; j++) {
				if (i == 0) { //bir damanın üst hissəsinin yığılması üçün
					if (j == 0) {
						mas[i][j] = 218;
						cout << " " << mas[i][j];
					}
					else if (j % 2 != 0) {
						mas[i][j] = 196;
						cout << mas[i][j];
					}
					else if (j > 0 && j % 2 == 0) {
						if (j == col - 1)
							mas[i][j] = 191;
						else
							mas[i][j] = 194;
						cout << mas[i][j];
					}

					if (j == 20 && s == 0) { // bir damanın üst hissəsinin TƏKRAR yığılması üçün lazımdır.
						j = -1;
						s++;
						if (user_or_komp % 2 == 0) {
							cout << "\t" << " >>>>>>>>\t";
						}
						else {
							cout << "\t" << " <<<<<<<<\t";
						}
					}
				}
				else if (i % 2 != 0) { //bir damanın yan hissələrinin qoyulması

					if (j % 2 == 0) {
						if (j == 0) {
							cout << x; // sətirləri nömrələmək üçün
							x++;
						}
						mas[i][j] = 179;
						cout << mas[i][j];
					}
					else if (j % 2 != 0) {//---------------------xananın içinə elementin təyin edilməsi
						if (s == 0) { //s=0 olanda birinci cədvəlin içindəki elementlər yazılır
							if (arr[count_row][count_col] == 1) {//----------// 1-ci cədvəlin içinə yazılan elementlər start

								mas[i][j] = 219; //Hər xananın içinə elementin təyin edilməsi
							}
							else if (arr[count_row][count_col] != 1) {
								mas[i][j] = arr[count_row][count_col]; //Hər xananın içinə elementin təyin edilməsi
							}
							else if (c != 0 && user_or_komp % 2 == 0) {//Əgər c sıfırdan fərqli dəyər alıbsa və komp userin xanasına top atırsa kompun xanasının dəyəri dəyişməlidir
																	   //arr[]-ın əvvəlki dəyərinini mən dəyişənə mənimsətməliyəm ki, yoxlayım. Əgər həmin dəyər bir idisə onda kənarlarını da yoxlayım. əgər bitişik kənarları da birdisə onlar da
																	   //X-ə bərabər edim ki komp düşmən gəmisinin bir damasını vurarsa bütün gəmi vurulmuş hesab edilsin.
								mas[i][j] = arr[a][b];
							}//----------//1-ci cədvəlin içinə yazılan elementlər finish
							if (mas[i][j] == 'X') {
								my_set_color(RED, BLACK);
							}
							cout << mas[i][j];//----------//---ekrana chixan yekun netice budur xananin ichindeki deyer olaraq
							my_set_color(YELLOW, BLACK);
						}
						else {//----------//2-ci cədvəlin içinə yazılan elementlər start
							if (arr1[count_row][count_col] == 1) {
								mas1[i][j] = 219; //Hər xananın içinə elementin təyin edilməsi
							}
							else if (arr1[count_row][count_col] != 1) {
								mas1[i][j] = arr1[count_row][count_col]; //Hər xananın içinə elementin təyin edilməsi
							}
							else if (c1 != 0 && user_or_komp % 2 != 0) {
								mas1[i][j] = arr1[a][b];
							}
							if (arr1[count_row][count_col] == 1) {// Kompyuterin gəmilərini gizlətmək üçün. Gəminin vurulmuş hissəsinin üstü açılır
								cout << ' ';
							}
							else {
								if (mas1[i][j] == 'X') {
									my_set_color(RED, BLACK);
								}
								cout << mas1[i][j];
								my_set_color(YELLOW, BLACK);
							}
						}//----------//2-ci cədvəlin içinə yazılan elementlər finish
						count_col++;
						if (s == 1 && count_col == num_col && k == 0) { //Tam bir sətri və ikinci cədvəlin birinci sətrini doldurandan sonra növbəti sətrə keçmək üçün
							count_row++;/////-----------/////
							k++;
						}
						if (count_col == num_col) {
							count_col = 0;
						}
					}//-----------------------xananın içinə elementin təyin edilməsi
					if (j == 20 && s == 0) { //---- bir damanın YAN hissəsinin TƏKRAR yığılması üçün lazımdır.
						j = -1;
						s++;
						x = d; //ikinci cədvəl üçün təkrar nömrləmə üçün nömrəsi sıfırlayırıq. Bunun üçün d=0;
						d++; //daha sonra d-ni hər dəfə 1 vahid artırırıq ki, növbəti x-in d-ə mənimsədilməsində d növbəti nömrəni alsın
						cout << "\t\t\t"; //cədvəllər arasında məsafənin qoyulması üçün.
					}//---------TƏKRARLANMA ÜÇÜN
				}
				else if (i % 2 == 0 && i < row - 1) { //Bir damanın alt hissəsini yığılması(axırıncı damalardan başqa)
					if (j == 0) {
						mas[i][j] = 195;
						cout << " " << mas[i][j];
					}
					else if (j % 2 != 0) {
						mas[i][j] = 196;
						cout << mas[i][j];
					}
					else if (j > 0 && j % 2 == 0) {
						if (j == col - 1)
							mas[i][j] = 180;
						else
							mas[i][j] = 197;
						cout << mas[i][j];
					}
					if (j == 20 && s == 0) { // bir damanın ALT hissəsinin TƏKRAR yığılması üçün lazımdır.(axırıncı damalardan başqa)ikinci cədvəl
						j = -1;
						s++;
						cout << "\t\t\t";
					}
				}
				else if (i == row - 1) { //Bir damanın alt hissəsini yığılması. Sonuncu damalar üçün.
					if (j == 0) {
						mas[i][j] = 192;
						cout << " " << mas[i][j];
					}
					else if (j % 2 != 0) {
						mas[i][j] = 196;
						cout << mas[i][j];
					}
					else if (j > 0 && j % 2 == 0) {
						if (j == col - 1)
							mas[i][j] = 217;
						else
							mas[i][j] = 193;
						cout << mas[i][j];
					}
					if (j == 20 && s == 0) { // bir damanın alt hissəsinin TƏKRAR yığılması.sonuncu damalar. ikinci cədvəl üçün
						j = -1;
						s++;
						cout << "\t\t\t";
					}
				}
			}
			cout << endl;
		} // Dama son
		x = 0; //setirleri yeniden 0-dan 9-a kimi saymaq uchun
		count_row = 0;
		count_col = 0;
		if (user_or_komp % 2 == 0) {
			cout << "User hucum edir:\n";
		}
		else {
			cout << "Komp hucum edir:\n";
		}
		cout << "Geminin koordinatlarini daxil edin.(Setir ve sutun):\n ";
		if (user_win == 20) {
			Sleep(2000);
			user_win = 21;
		}
		if (komp_win == 20) {
			Sleep(2000);
			komp_win = 21;
		}
		if (user_win < 20) {
			user_win = 0;
		}
		if (komp_win < 20) {
			komp_win = 0;
		}
		if (user_or_komp % 2 == 0) { //bu halda user vurur
			char str[1000]{};
			if (user_win <= 20 && komp_win != 21) {
				do {
					cin.getline(str, 1000);
					switch (str[0])
					{
					case '0': a = 0; break;
					case '1': a = 1; break;
					case '2': a = 2; break;
					case '3': a = 3; break;
					case '4': a = 4; break;
					case '5': a = 5; break;
					case '6': a = 6; break;
					case '7': a = 7; break;
					case '8': a = 8; break;
					case '9': a = 9; break;
					}
					switch (str[1])
					{
					case 'A': b = 0; break;
					case 'a': b = 0; break;
					case 'B': b = 1; break;
					case 'b': b = 1; break;
					case 'C': b = 2; break;
					case 'c': b = 2; break;
					case 'D': b = 3; break;
					case 'd': b = 3; break;
					case 'E': b = 4; break;
					case 'e': b = 4; break;
					case 'F': b = 5; break;
					case 'f': b = 5; break;
					case 'G': b = 6; break;
					case 'g': b = 6; break;
					case 'H': b = 7; break;
					case 'h': b = 7; break;
					case 'I': b = 8; break;
					case 'i': b = 8; break;
					case 'J': b = 9; break;
					case 'j': b = 9; break;
					}
					v1 = a; //Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					v2 = a;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					l1 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					l2 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					v3 = a;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					v4 = a;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					l3 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					l4 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
					if (!(str[0] >= '0' && str[0] <= '9') || !(str[1] >= 'A' && str[1] <= 'J') && !(str[1] >= 'a' && str[1] <= 'j') || str[2] != '\0') {
						cout << "Wrong coordinates!.. Try again!\n";
					}
				} while (!(str[0] >= '0' && str[0] <= '9') || !(str[1] >= 'A' && str[1] <= 'J') && !(str[1] >= 'a' && str[1] <= 'j') || str[2] != '\0');
			}
			if (arr1[a][b] == 1 || arr1[a][b] == 88) {
				c1 = 88;
			}
			else {
				c1 = 33;
			}
			arr1[a][b] = c1;

			while (arr1[v4][l4] == 88 || arr1[v4][l4] == 1) { // 1 sola
				horizontal_ship_lenght++;
				if (l4 > -1) {
					l4--;
				}
				if (arr1[v4][l4] == 1) {
					compartment++;
					//break;
				}
				if (l4 == -1) {
					break;
				}
			}
			while (arr1[v3][l3] == 88 || arr1[v3][l3] == 1) { //2 saga //kompun gemilerini saymaq uchun(2-ci cədvəl)
				horizontal_ship_lenght++;
				if (l3 < 10) {
					l3++;
				}
				if (arr1[v3][l3] == 1) {
					compartment++; //bu sıfırdan böyük o deməkdir ki, gəminin heç olmasa bir dənə salamat yeri var yəni tam vurulmayıb
				}
				if (l3 == 10) {
					break;
				}
			}
			while (arr1[v2][l2] == 88 || arr1[v2][l2] == 1) { //3 yuxari
				vertikal_ship_lenght++;
				if (v2 > -1) {
					v2--;
				}
				if (arr1[v2][l2] == 1) {
					compartment++;
					//break;
				}
				if (v2 == -1) {
					break;
				}
			}
			while (arr1[a][b] == 88 || arr1[a][b] == 1) { //4 ashagi
				vertikal_ship_lenght++;
				if (a < 10) {
					a++;
				}
				if (arr1[a][b] == 1) {
					compartment++;
					//break;
				}
				if (a == 10) {
					break;
				}
			}//kompun gemilerini saymaq uchun
			if (compartment == 0) {//-------------------------------------
				if (horizontal_ship_lenght == 4) {
					star_definition_row = a - 2;
					star_definition_col = l3 - 1 - 4;
					slip_for_star_row = 3;
					slip_for_star_col = 6;
				}
				else if (horizontal_ship_lenght == 3) {
					star_definition_row = a - 2;
					star_definition_col = l3 - 1 - 3;
					slip_for_star_row = 3;
					slip_for_star_col = 5;
				}
				else if (horizontal_ship_lenght == 2) {
					star_definition_row = a - 2;
					star_definition_col = l3 - 1 - 2;
					slip_for_star_row = 3;
					slip_for_star_col = 4;
				}
				else if (vertikal_ship_lenght == 4) {
					star_definition_row = a - 5;
					star_definition_col = b - 1;
					slip_for_star_row = 6;
					slip_for_star_col = 3;
				}
				else if (vertikal_ship_lenght == 3) {
					star_definition_row = a - 4;
					star_definition_col = b - 1;
					slip_for_star_row = 5;
					slip_for_star_col = 3;
				}
				else if (vertikal_ship_lenght == 2) {
					star_definition_row = a - 3;
					star_definition_col = b - 1;
					slip_for_star_row = 4;
					slip_for_star_col = 3;
				}
				else if (horizontal_ship_lenght == 1) {
					star_definition_row = a - 2;
					star_definition_col = b - 1;
					slip_for_star_row = 3;
					slip_for_star_col = 3;
				}
				for (int i = star_definition_row; i < star_definition_row + slip_for_star_row; i++) { // Ulduzlarin qoyulmasi -- vurulmush geminin etrafina start(2-ci cədvəl)
					for (int j = star_definition_col; j <star_definition_col + slip_for_star_col; j++) {
						if (i == 0 && j == 0) {
							if (arr1[i + 1][j] == 88 || arr1[i][j + 1] == 88 || arr1[i + 1][j + 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i == 0 && j > 0 && j < 9) {
							if (arr1[i + 1][j] == 88 || arr1[i][j + 1] == 88 || arr1[i][j - 1] == 88 || arr1[i + 1][j - 1] == 88
								|| arr1[i + 1][j + 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i == 0 && j == 9) {
							if (arr1[i + 1][j] == 88 || arr1[i][j - 1] == 88 || arr1[i][j - 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i > 0 && i < 9 && j == 0) {
							if (arr1[i - 1][j] == 88 || arr1[i][j + 1] == 88 || arr1[i + 1][j] == 88 || arr1[i + 1][j + 1] == 88
								|| arr1[i - 1][j + 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i > 0 && i < 9 && j>0 && j < 9) {
							if (arr1[i - 1][j] == 88 || arr1[i][j + 1] == 88 || arr1[i + 1][j] == 88 || arr1[i][j - 1] == 88
								|| arr1[i - 1][j - 1] == 88 || arr1[i - 1][j + 1] == 88 || arr1[i + 1][j - 1] == 88
								|| arr1[i + 1][j + 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i > 0 && i < 9 && j == 9) {
							if (arr1[i - 1][j] == 88 || arr1[i + 1][j] == 88 || arr1[i][j - 1] == 88
								|| arr1[i - 1][j - 1] == 88 || arr1[i + 1][j - 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i == 9 && j == 0) {
							if (arr1[i - 1][j] == 88 || arr1[i][j + 1] == 88 || arr1[i - 1][j + 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i == 9 && j > 0 && j < 9) {
							if (arr1[i - 1][j] == 88 || arr1[i][j + 1] == 88 || arr1[i][j - 1] == 88 || arr1[i - 1][j - 1] == 88
								|| arr1[i - 1][j + 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
						else if (i == 9 && j == 9) {
							if (arr1[i - 1][j] == 88 || arr1[i][j - 1] == 88 || arr1[i - 1][j - 1] == 88) {
								if (arr1[i][j] != 'X')
									arr1[i][j] = '*';
							}
						}
					}
				}// Ulduzlarin qoyulmasi -- vurulmush geminin etrafina finish(2-ci cədvəl)
			}
			compartment = 0; //Növbəti vuruşda gəminin salamat hissələrini yenidən saymaq üçün
		}
		else { // bu halda komp vurur(Yəni 1-ci cədvəli)
			Sleep(1500);
			do {
				a = rand() % 10;
				b = rand() % 10;
			} while (arr[a][b] == 33 || arr[a][b] == 88 || arr[a][b] == '*'); //Bu lazımdır ki, bir dəfə top düşən xanaya komp təkrar top atmasın.
			v1 = a; //Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			v2 = a;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			l1 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			l2 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			v3 = a;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			v4 = a;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			l3 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			l4 = b;//Gəmilərin sətir və sütunlar üzrə bir udara tam vurulması üçün
			if (arr[a][b] == 1) {
				arr[a][b] = 88;
			}
			else {
				arr[a][b] = 33;
			}
			//bu halda komp vurur
			while (arr[v3][l3] == 88) { //1 saga
				if (l3 < 9) {
					l3++;
				}
				if (arr[v3][l3] == 1) {
					arr[v3][l3] = 88;
				}
				else {
					break;
				}
			}
			while (arr[v4][l4] == 88) { // 2 sola
				if (l4 > 0) {
					l4--;
				}

				if (arr[v4][l4] == 1) {
					arr[v4][l4] = 88;
				}
				else {
					break;
				}
			}
			while (arr[v2][l2] == 88) { //3 yuxari
				if (v2 > 0) {
					v2--;
				}
				if (arr[v2][l2] == 1) {
					arr[v2][l2] = 88;
				}
				else {
					break;
				}
			}
			while (arr[a][b] == 88) { //4 ashagi
				if (a < 9) {
					a++;
				}
				if (arr[a][b] == 1) {
					arr[a][b] = 88;
				}
				else {
					break;
				}
			}
			for (int i = 0; i < num_row; i++) { // Ulduzlarin qoyulmasi -- vurulmush geminin etrafina start(1-ci cədvəl)

				for (int j = 0; j < num_col; j++) {
					if (i == 0 && j == 0) {
						if (arr[i + 1][j] == 88 || arr[i][j + 1] == 88 || arr[i + 1][j + 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
					else if (i == 0 && j > 0 && j < 9) {
						if (arr[i + 1][j] == 88 || arr[i][j + 1] == 88 || arr[i][j - 1] == 88 || arr[i + 1][j - 1] == 88
							|| arr[i + 1][j + 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
					else if (i == 0 && j == 9) {
						if (arr[i + 1][j] == 88 || arr[i][j - 1] == 88 || arr[i][j - 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
					else if (i > 0 && i < 9 && j == 0) {
						if (arr[i - 1][j] == 88 || arr[i][j + 1] == 88 || arr[i + 1][j] == 88 || arr[i + 1][j + 1] == 88
							|| arr[i - 1][j + 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
					else if (i > 0 && i < 9 && j>0 && j < 9) {
						if (arr[i - 1][j] == 88 || arr[i][j + 1] == 88 || arr[i + 1][j] == 88 || arr[i][j - 1] == 88
							|| arr[i - 1][j - 1] == 88 || arr[i - 1][j + 1] == 88 || arr[i + 1][j - 1] == 88
							|| arr[i + 1][j + 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
					else if (i > 0 && i < 9 && j == 9) {
						if (arr[i - 1][j] == 88 || arr[i + 1][j] == 88 || arr[i][j - 1] == 88
							|| arr[i - 1][j - 1] == 88 || arr[i + 1][j - 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
					else if (i == 9 && j == 0) {
						if (arr[i - 1][j] == 88 || arr[i][j + 1] == 88 || arr[i - 1][j + 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}

					}
					else if (i == 9 && j > 0 && j < 9) {
						if (arr[i - 1][j] == 88 || arr[i][j + 1] == 88 || arr[i][j - 1] == 88 || arr[i - 1][j - 1] == 88
							|| arr[i - 1][j + 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
					else if (i == 9 && j == 9) {
						if (arr[i - 1][j] == 88 || arr[i][j - 1] == 88 || arr[i - 1][j - 1] == 88) {
							if (arr[i][j] != 'X')
								arr[i][j] = '*';
						}
					}
				}

			}// Ulduzlarin qoyulmasi -- vurulmush geminin etrafina finish(1-ci cədvəl)
		}
		for (short i = 0; i < num_row; i++) {
			for (short j = 0; j < num_col; j++) {
				if (arr1[i][j] == 'X')
					user_win++;
			}
		}
		for (short i = 0; i < num_row; i++) {
			for (short j = 0; j < num_col; j++) {
				if (arr[i][j] == 'X')
					komp_win++;
			}
		}
		user_or_komp++;
		horizontal_ship_lenght = -1;
		vertikal_ship_lenght = -1;
		system("cls");
	}
	if (user_win == 41) {
		cout << "USER WIN!!!" << endl;
	}
	if (komp_win == 41) {
		cout << "KOMP WIN!!!" << endl;
	}
	system("pause");
}

