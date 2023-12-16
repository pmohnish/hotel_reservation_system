This project represents a simplified Hotel Reservation System implemented using Object-Oriented Programming (OOP) principles in C++.

Room Class: The Room class is an abstract base class representing a generic hotel room.It has properties like roomNumber and isOccupied.It has methods like occupy and vacate to mark the room as occupied or vacated.The display method is a virtual function, allowing derived classes to override and customize the display behavior.

SingleRoom and DoubleRoom Classes: These classes inherit from the Room class, demonstrating inheritance. They specialize by adding information about the room type (single or double). They override the display method to include the room type in the output.

Hotel Class: The Hotel class contains a vector of Room pointers, representing the rooms in the hotel. The constructor initializes the rooms, creating instances of SingleRoom and DoubleRoom. The displayRooms method prints the details of all rooms in the hotel. The findAvailableRoom method finds the first available room in the hotel.

Reservation Class: The Reservation class represents a guest reservation. It stores the guest name and a pointer to the reserved room. The constructor marks the room as occupied during the reservation. The destructor marks the room as vacated when the reservation is over.

Main Function: An instance of the Hotel class is created with a specified number of single and double rooms. The initial state of the hotel is displayed. A reservation is made for a guest named "John Doe," and the details are displayed.The hotel state is displayed again, showing the occupied room. A second reservation is attempted for a guest named "Jane Doe," and the details are displayed.The final hotel state is displayed, reflecting both reservations.

In summary, this program models a simple hotel reservation system using OOP principles, such as abstraction (via abstract base class), encapsulation (by hiding implementation details within classes), inheritance (with derived room types), and polymorphism (through virtual functions). It provides a basic structure for managing rooms, reservations, and the overall state of a hotel.
