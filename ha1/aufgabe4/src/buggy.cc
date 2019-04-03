// Vergleich von Deklaration, Enumeration und Typumwandlung 
// in C und C++

// Fehler                                           C++
//enum enumeration { 1st, 2nd, 3rd, 4th };     // Z1  expected identifier before numeric constant
//enum marks { '1', '2', '3', '4', '5', '6' }; // Z2  expected identifier before '1', '2', ...
enum class1 { DIETER, HANS, PETER, KAI };    // Z3  OK
//enum class2 { ANDREA, KAI, SABINE, ZOE };    // Z4  redeclaration of 'KAI'
enum sports { FUSSBALL, BASKETBALL, HOCKEY };// Z5  OK

int main(void)                               // Z7  OK
{
    int i;                                   // Z8  OK
    sports mysport;                          // Z9  OK
//    enum sports mysport;                     // Z10 redeclaration of 'sports mysport'
    mysport = FUSSBALL;                      // Z11 OK
    mysport = FUSSBALL + 1;                  // Z12 invalid conversion from 'int' to 'sports' (gcc -fpermissive)
    mysport = 1;                             // Z13 invalid conversion from 'int' to 'sports' (gcc -fpermissive)
    mysport = 10;                            // Z14 invalid conversion from 'int' to 'sports' (gcc -fpermissive)
    mysport = mysport + 1;                   // Z15 invalid conversion from 'int' to 'sports' (gcc -fpermissive)
    mysport = sports(mysport + 1);           // Z16 OK
    float f;                                 // Z17 OK
    for (i = FUSSBALL; i <= HOCKEY; i++)     // Z18 OK
        mysport = sports(i);                 // Z19 OK
    for (int k = FUSSBALL; k <= HOCKEY; k++) // Z20 OK
        mysport = sports(k);                 // Z21 OK
    return 0;                                // Z22 OK
}
