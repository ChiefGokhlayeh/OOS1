/*

Spiel Tsching, Tschang, Tschong

Regeln:
Es gibt zwei Spieler: der Programmierer und der Computer.
Beide Spieler waehlen gleichzeitig eines der drei Objekte
Stein, Schere und Papier. Beide können das gleiche Objekt w�hlen.
Der Spieler, der das mächtigere Objekt gewählt hat gewinnt.
SCHERE kann einen STEIN nicht zerschneiden, d.h. STEIN ist
mächtiger als SCHERE. PAPIER wickelt STEIN ein, d.h. PAPIER ist
mächtiger als STEIN. SCHERE zerschneidet PAPIER, d. h. SCHERE
ist maechtiger als PAPIER

*/

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <limits>
using namespace std;

// Aufzählungstyp für Stein etc.
enum objectType
{
    SCHERE,
    STEIN,
    PAPIER,

    INVALID_CHOICE
};

// Struktur für einen Spieler bestehend aus Name und Wahl
// des Spielers
struct player
{
    const char *name;
    objectType choice;
};

// Variable für den Namen des Spielers
char name[15];

// Name des Spielers eingeben
char *enterName(char str[], int len)
{
    do
    {
        cout << "Name des Spielers: ";
        if (fgets(str, len, stdin) == nullptr)
        {
            cerr << "Fehler im Eingabestream!" << endl;
            exit(1);
            return nullptr;
        }
    } while (strlen(str) <= 1);

    int new_line = strlen(str) - 1;
    if (str[new_line] == '\n')
        str[new_line] = '\0';
    return str;
}

// Den Computer zufällig wählen lassen.
// Nutzen Sie srand(...) und rand().
objectType randomChoice()
{
    srand(time(nullptr));
    return static_cast<objectType>(rand() % INVALID_CHOICE);
}

// Die Wahl von STEIN etc. als String zurückgeben lassen
const char *object2str(objectType o)
{
    switch (o)
    {
    case SCHERE:
        return "Schere";
    case STEIN:
        return "Stein";
    case PAPIER:
        return "Papier";
    case INVALID_CHOICE:
    default:
        return "<UNGÜLTIG>";
    }
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(player p)
{
    cout << "Spieler: " << p.name << endl
         << "\tAuswahl: " << object2str(p.choice) << endl;
}

// Die Wahl des Spielers abfragen
objectType enterChoice()
{
    int choice = INVALID_CHOICE;
    do
    {
        cout << "Triff deine Wahl (Schere=" << SCHERE << " Stein=" << STEIN << " Papier=" << PAPIER << "): ";
        cin >> choice;
        if (cin.bad())
        {
            cerr << "Fehler im Eingabestream!" << endl;
            exit(1);
        }
        else if (cin.fail() || choice >= INVALID_CHOICE)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = INVALID_CHOICE;
            cerr << "Ungültige Auswahl!" << endl;
        }
        else
        {
            cout << "Deine Auswahl: " << choice << endl;
        }
    } while (choice >= INVALID_CHOICE);
}

// Die Wahl bestimmen, die gewonnen hat
objectType winningObject(objectType obj1, objectType obj2)
{
    switch (obj1)
    {
    case SCHERE:
        if (obj2 == PAPIER)
        {
            return obj1;
        }
        else
        {
            return obj2;
        }
    case STEIN:
        if (obj2 == SCHERE)
        {
            return obj1;
        }
        else
        {
            return obj2;
        }
    case PAPIER:
        if (obj2 == STEIN)
        {
            return obj1;
        }
        else
        {
            return obj2;
        }
    case INVALID_CHOICE:
    default:
        return INVALID_CHOICE;
    }
}

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{
    if (p1.choice == p2.choice)
    {
        cout << "UNENTSCHIEDEN!" << endl;
    }
    else
    {
        objectType win = winningObject(p1.choice, p2.choice);
        player &winner = p1;
        if (win == p2.choice)
        {
            winner = p2;
        }
        cout << winner.name << " hat gewonnen!" << endl;
    }
}

int main()
{
    player player1, player2;
    player1.name = "Computer";
    player1.choice = randomChoice();
    cout << "Der Computer hat sein Wahl getroffen." << endl;
    player2.name = enterName(name, sizeof(name));
    player2.choice = enterChoice();
    showPlayer(player1);
    showPlayer(player2);
    showWinner(player1, player2);
}
