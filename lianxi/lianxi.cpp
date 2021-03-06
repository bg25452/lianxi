// lianxi.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
class HotelRoom {
public:
	HotelRoom(int bedrooms, int bathrooms)
		: bedrooms_(bedrooms), bathrooms_(bathrooms) {}

	virtual int get_price() {
		return 50 * bedrooms_ + 100 * bathrooms_;
	}
	int get_price(int b) {
		return 50 * bedrooms_ + 100 * bathrooms_;
	}
private:
	int bedrooms_;
	int bathrooms_;
	int c;
};

class HotelApartment : public HotelRoom {
public:
	HotelApartment(int bedrooms, int bathrooms)
		: HotelRoom(bedrooms, bathrooms) {}

	int get_price() {
		return HotelRoom::get_price() + 100;
	}
};
int main() {
	int n;
	cin >> n;
	vector<HotelRoom*> rooms;
	for (int i = 0; i < n; ++i) {
		string room_type;
		int bedrooms;
		int bathrooms;
		cin >> room_type >> bedrooms >> bathrooms;
		if (room_type == "standard") {
			rooms.push_back(new HotelRoom(bedrooms, bathrooms));
		}
		else {
			rooms.push_back(new HotelApartment(bedrooms, bathrooms));
		}
	}

	int total_profit = 0;
	for (auto room : rooms) {
		total_profit += room->get_price();
	}
	cout << total_profit << endl;

	for (auto room : rooms) {
		delete room;
	}
	rooms.clear();
	system("pause");
	return 0;
}

