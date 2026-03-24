typedef struct {
  char ownerName[31];
  char chip[8];
  int price;
} Patient;

Patient inputPatient(Patient p) { return p; }

int main() {
  Patient p;
  inputPatient(p);
  return 0;
}
