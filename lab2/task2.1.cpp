//
// Created by reenie on 26.09.2021.
//
#include <iostream>

bool task1 (uint32_t year) {
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	} else if (year % 400 == 0) {
		return true;
	} else {
		return false;
	}
}

bool task2 (int32_t tower_x, int32_t tower_y, int32_t target_x, int32_t target_y) {
	if ((tower_x == target_x) xor (tower_y == target_y)) {
		return true;
	} else {
		return false;
	}
} // или просто return (tower_x == target_x) xor (tower_y == target_y)

bool task3 (int32_t bishop_x, int32_t bishop_y, int32_t target_x, int32_t target_y) {
	if (abs(bishop_x - target_x) == abs(bishop_y - target_y)) {
		return true;
	} else {
		return false;
	}
} // или просто return abs(bishop_x - target_x) == abs(bishop_y - target_y)

bool task4 (int32_t queen_x, int32_t queen_y, int32_t target_x, int32_t target_y) {
	if (task2(queen_x, queen_y, target_x, target_y) || task3(queen_x, queen_y, target_x, target_y)) {
		return true;
	} else {
		return false;
	}
} // как return task2(queen_x, queen_y, target_x, target_y) || task3(queen_x, queen_y, target_x, target_y)

bool task5 (int32_t horse_x, int32_t horse_y, int32_t target_x, int32_t target_y) {
	if (abs(horse_x - target_x) == 1 && abs(horse_y) == 2) {
		return true;
	} else if (abs(horse_x - target_x) == 2 && abs(horse_y - target_y) == 1) {
		return true;
	} else {
		return false;
	}
}

int main() {
	//std::cout << task2(1,1,2,1);
	return 1;
}