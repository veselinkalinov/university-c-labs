#include <stdio.h>

struct Vehicle {
  char brand[30];
  char model[30];
  int year;
  float maxSpeed;
  float price;
};

struct Car {
  struct Vehicle v1;
  int seats;
  int doors;
  float horsePower;
};

struct MotorBoat {
  struct Vehicle v1;
  int seats;
  float length;
  float enginePower;
};

struct Airplane {
  struct Vehicle v1;
  int passengers;
  float wingspan;
  float enginePower;
};

void printCar(struct Car car) {
  printf("Vid: Kola\n");
  printf("Marka: %s\n", car.v1.brand);
  printf("Model: %s\n", car.v1.model);
  printf("Godina: %d\n", car.v1.year);
  printf("Maksimalna skorost: %.2f km/h\n", car.v1.maxSpeed);
  printf("Cena: %.2f eur.\n", car.v1.price);
  printf("Mesta: %d\n", car.seats);
  printf("Vrati: %d\n", car.doors);
  printf("Moshtnost: %.2f h.p.\n\n", car.horsePower);
}

void printMotorBoat(struct MotorBoat boat) {
  printf("Vid: Motorna lodka\n");
  printf("Marka: %s\n", boat.v1.brand);
  printf("Model: %s\n", boat.v1.model);
  printf("Godina: %d\n", boat.v1.year);
  printf("Maksimalna skorost: %.2f km/h\n", boat.v1.maxSpeed);
  printf("Cena: %.2f eur.\n", boat.v1.price);
  printf("Mesta: %d\n", boat.seats);
  printf("Dalzhina: %.2f m\n", boat.length);
  printf("Moshtnost: %.2f k.s.\n\n", boat.enginePower);
}

void printAirplane(struct Airplane airplane) {
  printf("Vid: Samolet\n");
  printf("Marka: %s\n", airplane.v1.brand);
  printf("Model: %s\n", airplane.v1.model);
  printf("Godina: %d\n", airplane.v1.year);
  printf("Maksimalna skorost: %.2f km/h\n", airplane.v1.maxSpeed);
  printf("Cena: %.2f lv.\n", airplane.v1.price);
  printf("Mesta: %d\n", airplane.passengers);
  printf("Razmah na krilata: %.2f m\n", airplane.wingspan);
  printf("Moshtnost: %.2f h.p.\n\n", airplane.enginePower);
}

void compareVehiclesBySpeed(struct Vehicle first, struct Vehicle second) {
  printf("Sravnenie po maksimalna skorost:\n");
  printf("%s %s = %.2f km/h\n", first.brand, first.model, first.maxSpeed);
  printf("%s %s = %.2f km/h\n", second.brand, second.model, second.maxSpeed);

  if (first.maxSpeed > second.maxSpeed) {
    printf("Po-barzo e: %s %s\n\n", first.brand, first.model);
  } else if (second.maxSpeed > first.maxSpeed) {
    printf("Po-barzo e: %s %s\n\n", second.brand, second.model);
  } else {
    printf("Dvete prevozni sredstva sa s ednakva skorost.\n\n");
  }
}

int main(void) {
  struct Car car = {{"BMW", "M5", 2022, 250.0f, 145000.0f}, 5, 4, 625.0f};
  struct MotorBoat boat = {
      {"Yamaha", "242X", 2021, 85.0f, 98000.0f}, 8, 7.30f, 360.0f};
  struct Airplane airplane = {
      {"Cessna", "172", 2019, 302.0f, 820000.0f}, 4, 11.00f, 180.0f};

  printf("Danni za prevoznite sredstva:\n\n");
  printCar(car);
  printMotorBoat(boat);
  printAirplane(airplane);

  compareVehiclesBySpeed(car.v1, boat.v1);
  compareVehiclesBySpeed(car.v1, airplane.v1);
  compareVehiclesBySpeed(boat.v1, airplane.v1);

  return 0;
}
