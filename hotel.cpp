#include <iostream>
#include <vector>
#include <string>

class Room {
protected:
    int roomNumber;
    bool isOccupied;

public:
    Room(int number) : roomNumber(number), isOccupied(false) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool getIsOccupied() const {
        return isOccupied;
    }

    void occupy() {
        isOccupied = true;
    }

    void vacate() {
        isOccupied = false;
    }

    virtual void display() const {
        std::cout << "Room Number: " << roomNumber << ", Occupied: " << (isOccupied ? "Yes" : "No") << std::endl;
    }
};

class SingleRoom : public Room {
public:
    SingleRoom(int number) : Room(number) {}

    void display() const override {
        std::cout << "Single ";
        Room::display();
    }
};

class DoubleRoom : public Room {
public:
    DoubleRoom(int number) : Room(number) {}

    void display() const override {
        std::cout << "Double ";
        Room::display();
    }
};

class Hotel {
private:
    std::vector<Room*> rooms;

public:
    Hotel(int numSingleRooms, int numDoubleRooms) {
        for (int i = 1; i <= numSingleRooms; ++i) {
            rooms.push_back(new SingleRoom(i));
        }

        for (int i = 1; i <= numDoubleRooms; ++i) {
            rooms.push_back(new DoubleRoom(i + numSingleRooms));
        }
    }

    ~Hotel() {
        for (Room* room : rooms) {
            delete room;
        }
    }

    void displayRooms() const {
        for (const Room* room : rooms) {
            room->display();
        }
    }

    Room* findAvailableRoom() const {
        for (Room* room : rooms) {
            if (!room->getIsOccupied()) {
                return room;
            }
        }
        return nullptr; // No available room
    }
};

class Reservation {
private:
    std::string guestName;
    Room* room;

public:
    Reservation(const std::string& name, Room* assignedRoom) : guestName(name), room(assignedRoom) {
        room->occupy();
    }

    ~Reservation() {
        room->vacate();
    }

    void display() const {
        std::cout << "Guest: " << guestName << ", Room Number: " << room->getRoomNumber() << std::endl;
    }
};

int main() {
    Hotel hotel(3, 2);

    std::cout << "Initial Hotel State:" << std::endl;
    hotel.displayRooms();

    Room* availableRoom = hotel.findAvailableRoom();
    if (availableRoom) {
        Reservation reservation1("John Doe", availableRoom);
        std::cout << "\nReservation 1 Details:" << std::endl;
        reservation1.display();
    } else {
        std::cout << "\nNo available rooms for Reservation 1." << std::endl;
    }

    std::cout << "\nHotel State after Reservation 1:" << std::endl;
    hotel.displayRooms();

    availableRoom = hotel.findAvailableRoom();
    if (availableRoom) {
        Reservation reservation2("Jane Doe", availableRoom);
        std::cout << "\nReservation 2 Details:" << std::endl;
        reservation2.display();
    } else {
        std::cout << "\nNo available rooms for Reservation 2." << std::endl;
    }

    std::cout << "\nHotel State after Reservation 2:" << std::endl;
    hotel.displayRooms();

    return 0;
}
