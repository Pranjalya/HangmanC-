#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <limits> // for numeric_limits
#include <unistd.h> // for usleep (provides a delay similar to getch)

using namespace std;

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}

void clrscr() {
    system("clear"); // Use "clear" for Linux
}

void Title() {
    clrscr();
    int i, y;
    for (i = 0, y = 2; i < 5; ++i, ++y) {  // For H
        gotoxy(15, y);
        cout << "|";
        gotoxy(20, y);
        cout << "|";
    }
    for (y = 16; y < 20; ++y) {
        gotoxy(y, 4);
        cout << "*";
    }
    for (i = 21, y = 6; i < 26, y > 1; ++i, --y) {  // For A
        gotoxy(i, y);
        cout << "|";
    }
    for (i = 25, y = 2; i <= 29, y <= 6; ++i, ++y) {
        gotoxy(i, y);
        cout << "|";
    }
    gotoxy(23, 5);
    cout << "-----";
    for (i = 0, y = 2; i < 5; ++i, ++y) {  // For N
        gotoxy(30, y);
        cout << "|";
        gotoxy(35, y);
        cout << "|";
    }
    for (i = 31, y = 2; i <= 34, y <= 6; ++i, ++y) {
        gotoxy(i, y);
        cout << "+";
    }
    for (i = 0, y = 2; i < 5; ++i, ++y) {  // For G
        gotoxy(36, y);
        cout << "|";
    }
    gotoxy(37, 1);
    cout << "____";
    gotoxy(37, 6);
    cout << "____";
    gotoxy(39, 4);
    cout << "__";
    gotoxy(41, 2);
    cout << "|";
    gotoxy(41, 5);
    cout << "|";
    gotoxy(41, 6);
    cout << "|";
    for (i = 0, y = 2; i < 5; ++i, ++y) {  // For M
        gotoxy(42, y);
        cout << "|";
        gotoxy(47, y);
        cout << "|";
    }
    for (i = 43, y = 2; i < 45, y < 4; ++i, ++y) {
        gotoxy(i, y);
        cout << "|";
    }
    for (i = 45, y = 3; i < 47, y > 1; ++i, --y) {
        gotoxy(i, y);
        cout << "|";
    }
    for (i = 48, y = 6; i < 53, y > 1; ++i, --y) {  // For A
        gotoxy(i, y);
        cout << "|";
    }
    for (i = 52, y = 2; i <= 56, y <= 6; ++i, ++y) {
        gotoxy(i, y);
        cout << "|";
    }
    gotoxy(50, 5);
    cout << "-----";
    for (i = 0, y = 2; i < 5; ++i, ++y) {  // For N
        gotoxy(57, y);
        cout << "|";
        gotoxy(62, y);
        cout << "|";
    }
    for (i = 58, y = 2; i <= 61, y <= 6; ++i, ++y) {
        gotoxy(i, y);
        cout << "*";
    }
}

class Scor {
    char fname[80], lname[30];
    int age, id;

public:
    int sc;

    Scor() {
        strcpy(fname, "");
        strcpy(lname, "");
        id = 0;
        age = 0;
        sc = 0;
    }

    void getdet();

    void showdet() {
        strcat(fname, lname);
        cout << "\nName  : ";
        puts(fname);
        cout << "   ID    : " << id;
        cout << "\n   Age   : " << age;
        cout << "\n   Score : " << sc;
    }

    void modify();

    int ret() { return (id); }
};

void Scor::getdet() {
    while (true) { // Loop for ID input
        cout << "\nPlease enter a unique id, that has not been used already by you : ";
        cin >> id;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }
    cout << "\nPlease enter your first name : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(fname, 80);
    fname[0] = toupper(fname[0]);
    strcat(fname, " ");
    for (int j = 1; fname[j] != '\0'; ++j) {
        fname[j] = tolower(fname[j]);
    }

    cout << "\nPlease enter your last name : ";
    cin.getline(lname, 30);
    lname[0] = toupper(lname[0]);
    for (int j = 1; lname[j] != '\0'; ++j) {
        lname[j] = tolower(lname[j]);
    }

    while (true) { // Loop for age input
        cout << "\nPlease enter your age : ";
        cin >> age;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }
}

void Scor::modify() {
    int tid = 0, tempage = 0;
    char tempnm[80] = "";

    cout << "\nID   : " << id;
    cout << "\nName  : ";
    puts(fname);
    cout << "\nAge   : " << age;
    cout << "\nScore : " << sc;

    while (true) {
        cout << "\n\nEnter new id no or 0 to not alter : ";
        cin >> tid;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cout << "\n\nEnter new name or . to not alter : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(tempnm, 80);

    while (true) {
        cout << "\n\nEnter new age or 0 to not alter : ";
        cin >> tempage;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    if (tid != 0) {
        id = tid;
    }
    if (strcmp(tempnm, ".") != 0) {
        strcpy(fname, tempnm);
    }
    if (tempage != 0) {
        age = tempage;
    }
}

void Help() {
    clrscr();
    Title();
    gotoxy(23, 9);
    cout << "HOW  TO  PLAY  HANGMAN\n\n";
    cout << "\nIt is very easy. Main objective of the game is to guess the name of the movie. Just read these steps :- \n\n";
    cout << "1. In screen you will see certain number of dashes ( _ ). These dashes represent number of letters present in the name of the movie.";
    cout << "\n\n\n2. Each movie has only one letter in its name.";
    cout << "\n\n\n3. There are no extra characters or digits present in the name of the movie.";
    cout << "\n\n\n4. A hint is also given mandatorily. ";
    cout << "\n\n\n5. You will get 7 turns for guessing letters. Each wrong letter will lose you one turn.";
    cout << "\n\n\n6. There are three difficulty levels, EASY (10 points for correct movie), AVERAGE (20 points for correct movie) and HARD (30 points for correct movie), each where score is points times number of guesses left. You get 0 points for each wrong answer.";
    cout << "\n\n\n\n\tSo, it is simple, play and enjoy. Press any key to go back.";
    usleep(500000); // Pause for 0.5 seconds
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); // Wait for any key press
}

int letterfill(char, char[], char[]);
int letterfill(char guess, char secretword[], char guessword[]) {
    int i;
    int matches = 0, len;
    for (i = 0; secretword[i] != '\0'; ++i) {
        len = i + 1;
    }
    for (i = 0; i < len; ++i) {
        if (guess == guessword[i])
            return 0;
        if (guess == secretword[i]) {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

void Entry(int sco) {
    clrscr();
    fstream file;
    Scor s;
    Title();
    gotoxy(35, 9);
    cout << "ENTER YOUR SCORE";
    cout << "\n\n";
    file.open("Score.dat", ios::in | ios::app | ios::binary);
    s.getdet();
    s.sc = sco;
    file.write((char*)&s, sizeof(s));
    file.close();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
}

void Hangman() {
    clrscr();
    Title();
    Scor s1;
    char letter, hint[200];
    int wrong = 0, i, len, diff, sco;
    gotoxy(25, 12);
    cout << "Welcome to HANGMAN \n\n";
    char easy[3][40] = {"SHOLAY", "DHAMAAL", "SADAMA"};
    char avg[3][40] = {"INCEPTION", "PRESTIGE", "BIRDMAN"};
    char hard[3][40] = {"INTERSTELLAR", "KRANTIVEER", "KHALNAAYAK"};
    char word[80];
    srand(time(0)); // Initialize random seed
    int n = rand() % 3;
    do {
        while (true) { // Loop for difficulty input
            cout << "\n\nPlease enter difficulty mode : Easy(1),Average(2),Hard(3) :- ";
            cin >> diff;
            if (cin.fail() || cin.peek() != '\n') {
                cout << "\tERROR: Invalid input. Please enter 1, 2, or 3.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break;
            }
        }

        switch (diff) {
            case 1:
                strcpy(word, easy[n]);
                break;
            case 2:
                strcpy(word, avg[n]);
                break;
            case 3:
                strcpy(word, hard[n]);
                break;
            default:
                cout << "\tERROR: Invalid difficulty level.\n";
                break;
        };
    } while (diff != 1 && diff != 2 && diff != 3);

    if (strcmp(word, "SHOLAY") == 0)
        strcpy(hint, "One of the most epic bollywood films, it has bollywood's most famous villain.");
    else if (strcmp(word, "DHAMAAL") == 0)
        strcpy(hint, "A comedy film depicting money chase.");
    else if (strcmp(word, "SADAMA") == 0)
        strcpy(hint, "Finest acting skills were shown by Kamal Hasan and Sridevi in this movie.");
    else if (strcmp(word, "INCEPTION") == 0)
        strcpy(hint, "A brain-wrecking film directed by Christopher Nolan, and starring Leonardo diCaprio.");
    else if (strcmp(word, "PRESTIGE") == 0)
        strcpy(hint, "A Christopher Nolan film depicting conflicts of two magicians, starring Hugh Jackman and Christian Bale.");
    else if (strcmp(word, "BIRDMAN") == 0)
        strcpy(hint, "Best film Acadamy Award Winner. It's full name is '(TITLE) or the Unexpected Virtue of Ignorance'.");
    else if (strcmp(word, "INTERSTELLAR") == 0)
        strcpy(hint, "A Christopher Nolan masterpiece starring Matthew McConnaughy in space with a beautiful story.");
    else if (strcmp(word, "KRANTIVEER") == 0)
        strcpy(hint, "A patriotic film starring Nana Patekar, who shows his brilliant acting skills and one of finest dialogue deliveries.");
    else if (strcmp(word, "KHALNAAYAK") == 0)
        strcpy(hint, "A drama film starring Sanjay Datt, as one of the famous antihero.");

    for (i = 0; word[i] != '\0'; ++i) {
        len = i + 1;
    }
    char unknown[100] = "";

    for (i = 0; i < len; ++i) {
        unknown[i] = '_';
    }
    len = 0;
    cout << "\n\nHINT : ";
    puts(hint);

    while (wrong < 7) {
        cout << "\n\n\t\t\t";
        puts(unknown);
        cout << "\n\n\t\tGuess a letter : ";
        cin >> letter;
        letter = toupper(letter);
        if (letterfill(letter, word, unknown) == 0) {
            cout << "\n\n\tDamn! Letter isn't there.\n";
            wrong++;
        } else {
            cout << "\n\n\t\tFound a letter!\n";
        }
        cout << "\n\nYou have " << 7 - wrong << " guesses left.";
        sco = diff * (7 - wrong) * 10;
        if (strcmp(word, unknown) == 0) {
            cout << "\n\n\n\t\tYeah! You got it!";
            cout << "\n\n\n\n\t\tYour score is " << sco;
            break;
        }
    }
    if (wrong == 7)
        cout << "\n\n\t\t\tSorry\n";
    cout << "\n\n\n\t    The word was : ";
    puts(word);
    usleep(500000);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    Entry(sco);
    int x;
    for (x = 0; word[x] != '\0'; ++x)
        word[x] = '\0';
    for (x = 0; unknown[x] != '\0'; ++x)
        unknown[x] = '\0';
    clrscr();
}

void search() {
    clrscr();
    int d, f = 0;
    Title();
    Scor se;
    fstream file;
    gotoxy(40, 10);
    cout << "SEARCH";
    cout << "\n\nPlease enter ID : ";
    while (true) {
        cin >> d;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }
    file.open("Score.dat", ios::in | ios::binary);
    file.seekg(0, ios::beg);
    if (!file) {
        cout << "Error";
        exit(1);
    }
    while (file.read((char*)&se, sizeof(se))) {
        if (d == se.ret()) {
            se.showdet();
            f = 1;
        }
    }
    if (f == 0) {
        cout << "\nID not found";
    }
    file.close();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
}

void delet() {
    clrscr();
    Title();
    fstream fin, fout;
    int d;
    Scor t;
    char ch = 'y', found = 'f';
    gotoxy(40, 9);
    cout << "DELETE";
    cout << "\n\nEnter ID to be deleted : ";
    while (true) {
        cin >> d;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }

    fin.open("Score.dat", ios::in | ios::binary);
    fin.seekg(0);
    fout.open("temp.dat", ios::out | ios::binary);
    if (!fin) {
        cout << "ERROR";
        exit(1);
    }
    while (fin.read((char*)&t, sizeof(t))) {
        if (t.ret() == d) {
            t.showdet();
            found = 't';
            cout << "\nSurely want to delete it? (y/n): ";
            cin >> ch;
            if (ch != 'y') { // Write record to temp file if not deleting
                fout.write((char*)&t, sizeof(t));
            }
        } else {
            fout.write((char*)&t, sizeof(t));
        }
    }
    if (found == 'f')
        cout << "\nMatch Not Found";
    fin.close();
    fout.close();
    remove("Score.dat");
    rename("temp.dat", "Score.dat");
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
}

void modif() {
    clrscr();
    streampos loc;
    int d;
    fstream file;
    Scor t;
    Title();
    gotoxy(40, 9);
    cout << "MODIFY";
    cout << "\n\nEnter id to be modified: ";
    while (true) {
        cin >> d;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }

    file.open("Score.dat", ios::in | ios::out | ios::binary);
    file.seekg(0);
    if (!file) {
        cout << "ERROR";
        exit(1);
    }
    while (file) {
        loc = file.tellg();
        file.read((char*)&t, sizeof(t));
        if (t.ret() == d) {
            t.modify();
            file.seekg(loc);
            file.write((char*)&t, sizeof(t));
            break; // Stop after modifying the record
        }
    }
    file.close();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
}

void Score() {
    int op;
    Scor s;
    fstream f;
    clrscr();
    Title();
    gotoxy(40, 9);
    cout << "SCORES";
    cout << "\n\n\n\nYou have these options : \n";
    cout << "\n\n1. Search a score";
    cout << "\n\n2. Modify a score's details";
    cout << "\n\n3. Delete a score";
    cout << "\n\n4. Exit";
    cout << "\n\n5. See all Scores";
    cout << "\n\n6. Clear all Scores";
    cout << "\n\n   Any other key to go back.";
    cout << "\n\nPlease enter your choice : ";
    
    while (true) {
        cin >> op;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }
    
    switch (op) {
        case 1:
            search();
            break;
        case 2:
            modif();
            break;
        case 3:
            delet();
            break;
        case 4:
            exit(0);
            break;
        case 5:
            f.open("Score.dat", ios::in | ios::binary);
            f.seekg(0);
            clrscr();
            Title();
            gotoxy(1, 10);
            while (f.read((char*)&s, sizeof(s))) {
                cout << "\n\n";
                s.showdet();
            }
            f.close();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cin.get();
            break;
        case 6:
            f.open("Score.dat", ios::out | ios::binary);
            f.close();
            break;
        default:
            break;
    }
    getch();
}

int main() {
    int op, preview;
    fstream file;
    file.open("Score.dat", ios::app | ios::binary);
    file.close();
preview:
    clrscr();
    Title();
    gotoxy(15, 9);
    cout << "WELCOME!! WELCOME TO MY DOMAIN...... THE GAME OF HANGMAN";
    gotoxy(1, 11);
    cout << "Here are your options : \n";
    cout << "\n\n1. How to Play Hangman";
    cout << "\n\n2. Start Hangman";
    cout << "\n\n3. See Last Scores";
    cout << "\n\n4. Exit";
    cout << "\n\n\n\nPlease enter your choice : ";
    while (true) {
        cin >> op;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    }

    switch (op) {
        case 1:
            Help();
            goto preview;

        case 2:
            Hangman();
            goto preview;

        case 3:
            Score();
            goto preview;

        case 4:
            exit(0);
            break;
        default:
            cout << "\n\nWrong Choice. Let's start again. Press any key to do so.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cin.get();
            goto preview;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
    return 0;
}
