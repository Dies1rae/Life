#include "Structures.h"
#include "Evolution.h"

#include <iostream>
#include <iomanip>

#ifdef _WIN32
	#include <Windows.h>
#endif

using namespace std;

void makeplayground(std::vector<std::vector<char>>& field) {
	for (size_t y = 0; y < field.size(); y++) {
		for (size_t x = 0; x < field[y].size(); x++) {
			if (x == 0 || y == 0 || y == field.size() - 1 || x == field[y].size() - 1) {
				field[y][x] = '@';
			} else {
				field[y][x] = '.';
			}
		}
	}
}

void displayplayground(std::vector<std::vector<char>>& field, std::ostream& out) {
	std::string buff;

	for (size_t y = 0; y < field.size(); y++) {
		for (size_t x = 0; x < field[y].size(); x++) {
			buff += field[y][x];
		}
		buff += '\n';
	}
	#ifdef __linux__ 
		system("clear");
	#elif _WIN32
		COORD coord;
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	#endif
	out << buff;
}

void markcolony(std::vector<std::vector<char>>& field, const vector<Colony>& colonys) {
	for (const auto& colony : colonys) {
		for (const Cell& cell : colony.GetColony()) {
			field[cell.Coords_.x_][cell.Coords_.y_] = '*';
		}
	}
}

int main() {
	system("MODE CON COLS=150 LINES=190");

	Coordinates max_filed_coords{ 51,101 };
	vector<vector<char>> field(max_filed_coords.x_);
	for (auto& vec : field) {
		vec.resize(max_filed_coords.y_);
	}

	Toad toa_u({ 45,4 }, Direction::UP, max_filed_coords);
	Toad toa_d({ 4,90 }, Direction::DOWN, max_filed_coords);

	Glider gli_ul({ 4,4 }, Direction::DOWN, max_filed_coords);
	Glider gli_ur({ 45,4 }, Direction::UP, max_filed_coords);
	Glider gli_dl({ 4,90 }, Direction::DOWN, max_filed_coords);
	Glider gli_dr({ 45,90 }, Direction::UP, max_filed_coords);

	RPentomino pent_u({ 25,50 }, Direction::RIGHT, max_filed_coords);

	vector<Colony> test_gli{ gli_ul.colony_, gli_ur.colony_, gli_dl.colony_, gli_dr.colony_ };
	vector<Colony> test_penta{ pent_u.colony_ };
	vector<Colony> test_toad{ toa_u.colony_, toa_d.colony_ };

	Evolution Earth(std::move(test_gli));
	Evolution Earth_1(std::move(test_penta));
	Evolution Earth_2(std::move(test_toad));

	while(!Earth.Static()){
		makeplayground(field);
		markcolony(field, Earth.GetColonys());
		displayplayground(field, cout);
		Earth.LifeCircle(max_filed_coords);
		cout << "Glider test\n";
		cout << "Evolution lifetime: " << std::fixed << std::setprecision(2) << Earth.GetLifeTime() << " seconds\n";
		for (const auto& [type, gen] : Earth.GetColonyData()) {
			cout << "Colony type: " << type << '\n';
			cout << "Colony gen: " << gen << '\n';
		}
	}
	cout << "\nGLIDER TEST'S END OK\n";
	system("PAUSE");
	system("cls");

	while (!Earth_2.Static()) {
		makeplayground(field);
		markcolony(field, Earth_2.GetColonys());
		displayplayground(field, cout);
		Earth_2.LifeCircle(max_filed_coords);
		cout << "Toad test\n";
		cout << "Evolution lifetime: " << std::fixed << std::setprecision(2) << Earth_2.GetLifeTime() << " seconds\n";
		for (const auto& [type, gen] : Earth_2.GetColonyData()) {
			cout << "Colony type: " << type << '\n';
			cout << "Colony gen: " << gen << '\n';
		}
		if (Earth_2.GetLifeTime() > 10.0) {
			break;
		}
	}
	cout << "\nTOADS TEST'S END OK\n";
	system("PAUSE");
	system("cls");

	while (!Earth_1.Static()) {
		makeplayground(field);
		markcolony(field, Earth_1.GetColonys());
		displayplayground(field, cout);
		Earth_1.LifeCircle(max_filed_coords);
		cout << "RPentomino test\n";
		cout << "Evolution lifetime: " << std::fixed << std::setprecision(2) << Earth_1.GetLifeTime() << " seconds\n";
		for (const auto& [type, gen] : Earth_1.GetColonyData()) {
			cout << "Colony type: " << type << '\n';
			cout << "Colony gen: " << gen << '\n';
		}
		if (Earth_2.GetLifeTime() > 30.0) {
			break;
		}
	}
	cout << "\RPentomino TEST'S END OK\n";
	system("PAUSE");
	system("cls");
	cout << "\nALL TEST'S END OK\n";

	return 0;
}
