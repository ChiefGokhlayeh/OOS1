// Vergleich von Deklaration, Enumeration und Typumwandlung
// in C und C++

// Fehler                                               C    |  C++
enum enumeration { 1st, 2nd, 3rd, 4th };     // Z1           |
enum marks { '1', '2', '3', '4', '5', '6' }; // Z2           |
enum class1 { DIETER, HANS, PETER, KAI };    // Z3           |
enum class2 { ANDREA, KAI, SABINE, ZOE };    // Z4           |
enum sports { FUSSBALL, BASKETBALL, HOCKEY };// Z5           |

int main(void)                               // Z7           |
{
	int i;                                   // Z8           |
	sports mysport;                          // Z9           |
	enum sports mysport;                     // Z10          |
	mysport = FUSSBALL;                      // Z11          |
	mysport = FUSSBALL + 1;                  // Z12          |
	mysport = 1;                             // Z13          |
	mysport = 10;                            // Z14          |
	mysport = mysport + 1;                   // Z15          |
	mysport = sports(mysport + 1);           // Z16          |
	float f;                                 // Z17          |
	for (i = FUSSBALL; i <= HOCKEY; i++)     // Z18          |
		mysport = sports(i);                 // Z19          |
	for (int k = FUSSBALL; k <= HOCKEY; k++) // Z20          |
		mysport = sports(k);                 // Z21          |
	return 0;                                // Z22          |
}

