// Vergleich von Deklaration, Enumeration und Typumwandlung
// in C und C++

// Fehler                                           C
//enum enumeration { 1st, 2nd, 3rd, 4th };     // Z1  invalid suffix
//enum marks { '1', '2', '3', '4', '5', '6' }; // Z2  unexpected identifier
enum class1 { DIETER, HANS, PETER, KAI };    // Z3  OK
//enum class2 { ANDREA, KAI, SABINE, ZOE };    // Z4  OK
enum sports { FUSSBALL, BASKETBALL, HOCKEY };// Z5  OK

int main(void)                               // Z7  OK
{
    int i;                                   // Z8  OK
//  sports mysport;                          // Z9  unkown type (use enum)
    enum sports mysport;                     // Z10 OK
    mysport = FUSSBALL;                      // Z11 OK
    mysport = FUSSBALL + 1;                  // Z12 OK
    mysport = 1;                             // Z13 OK
    mysport = 10;                            // Z14 OK
    mysport = mysport + 1;                   // Z15 OK
    mysport = (enum sports)(mysport + 1);       // Z16 sport() undefined function (not a valid C-cast)
    float f;                                 // Z17 OK
    for (i = FUSSBALL; i <= HOCKEY; i++)     // Z18 OK
        mysport = (enum sports)i;                 // Z19 sport() undefined function (not a valid C-cast)
    for (int k = FUSSBALL; k <= HOCKEY; k++) // Z20 OK
        mysport = (enum sports)k;                 // Z21 sport() undefined function (not a valid C-cast)
    return 0;                                // Z22 OK
}
