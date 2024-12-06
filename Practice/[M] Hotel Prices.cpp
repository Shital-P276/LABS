#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
        : bedrooms_(bedrooms), bathrooms_(bathrooms) {}

    int get_price() const {
        return 50 * bedrooms_ + 100 * bathrooms_;
    }

private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
        : HotelRoom(bedrooms, bathrooms) {}

    int get_price() const {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cout << "Enter the number of rooms: ";
    cin >> n;

    vector<HotelRoom*> rooms;
    while (n--) {
        string room_type;
        int bedrooms, bathrooms;
        cout << "Enter room type (standard/apartment), bedrooms, and bathrooms: ";
        cin >> room_type >> bedrooms >> bathrooms;

        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else if (room_type == "apartment") {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        } else {
            cout << "Invalid room type. Try again." << endl;
            ++n; // Retry this iteration
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
        delete room; // Clean up while iterating
    }

    cout << "Total profit: " << total_profit << endl;

    return 0;
}
