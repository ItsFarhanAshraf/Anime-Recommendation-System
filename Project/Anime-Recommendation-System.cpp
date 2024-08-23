#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<sstream>
using namespace std;

void suggest_mix_anime();
void rate_program();
void display_average_rating();
void add_user();
void view_suggestions();
void give_suggestion();
void search_anime();
void menu();

class anime {
protected:
    string name;
    int no_of_seasons;
    int no_of_episodes;
    string genre;

public:
    anime()
    {
        name = "Null";
        genre = "Null";
        no_of_episodes = 0;
        no_of_seasons = 0;
    }
    anime(string n1, int e1, int s1, string g1) :name(n1), no_of_episodes(e1), no_of_seasons(s1), genre(g1) {}


};//End of Anime class

class long_anime :public anime {
public:
    bool search_long_anime(string anime_name) {
        ifstream file("longAnime.txt");
        string line, _name, _episodes, _seasons, _genre;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, _name, ',');
            getline(ss, _episodes, ',');
            getline(ss, _seasons, ',');
            getline(ss, _genre, ',');

            if (_name == anime_name) {
                return true;
            }
        }

        file.close();
        return false;
    }

    void add_long_anime()
    {
        cout << "Enter Name of Anime: " << endl;
        cin >> name;
        if (search_long_anime(name))
        {
            cout << name << " already exists in the database.\n";
        }
        else
        {
            cout << "Enter No of episodes: " << endl;
            cin >> no_of_episodes;
            cout << "Enter No of seasons: " << endl;
            cin >> no_of_seasons;
            cout << "Enter Genre of Anime: " << endl;
            cin >> genre;
            ofstream outfile("longAnime.txt", ios::app);
            if (outfile.is_open())
            {
                outfile << name << "," << no_of_episodes << "," << no_of_seasons << "," << genre << endl;
                cout << name << " added successfully to the file." << endl;
            }
            else
                cout << "Unable to open or create file." << endl;
        }

    }//End of add_long_anime function 

    void view_long_anime() {
        ifstream file("longAnime.txt");
        string line, name, episodes, seasons, genre;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, episodes, ',');
            getline(ss, seasons, ',');
            getline(ss, genre, ',');

            cout << "Name: " << name << endl;
            cout << "Episodes: " << episodes << endl;
            cout << "Seasons: " << seasons << endl;
            cout << "Genre: " << genre << endl;
            cout << "------------------------" << endl;
        }

        file.close();
    }//End of view_long_anime() function

    void suggest_long_anime() {
        ifstream file("longAnime.txt");
        string line, name, episodes, seasons, genre;
        int count = 0;

        while (getline(file, line)) {
            count++;
        }

        file.clear();
        file.seekg(0);

        srand(time(0));
        int random_line = rand() % count;

        for (int i = 0; i <= random_line; i++) {
            getline(file, line);
        }

        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, episodes, ',');
        getline(ss, seasons, ',');
        getline(ss, genre, ',');

        cout << "Suggested Long Anime: " << name << endl << endl;
        cout << "Name: " << name << endl;
        cout << "Episodes: " << episodes << endl;
        cout << "Seasons: " << seasons << endl;
        cout << "Genre: " << genre << endl;

        file.close();
    }

    void delete_long_anime() {
        system("cls");
        string anime_name;
        cout << "Enter Name of Anime to delete: " << endl;
        cin >> anime_name;
        if (search_long_anime(anime_name)) {

            ifstream infile("longAnime.txt");
            ofstream temp_file("temp.txt");
            string line, _name, _episodes, _seasons, _genre;

            while (getline(infile, line)) {
                stringstream ss(line);
                getline(ss, _name, ',');
                getline(ss, _episodes, ',');
                getline(ss, _seasons, ',');
                getline(ss, _genre, ',');

                if (_name != anime_name) {
                    temp_file << line << endl;
                }
            }

            infile.close();
            temp_file.close();

            remove("longAnime.txt");
            rename("temp.txt", "shortAnime.txt");
            cout << anime_name << " Deleted Successfully from the file\n";
        }
        else
            cout << "No Anime of name ' " << anime_name << " ' exists in the databse.\n";
    }//End of delete_short_anime() function

    void update_long_anime(string anime_name) {
        ifstream file("longAnime.txt");
        ofstream temp_file("temp.txt");
        string line, name, episodes, seasons, genre;

        bool found = false;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, episodes, ',');
            getline(ss, seasons, ',');
            getline(ss, genre, ',');

            if (name == anime_name) {
                cout << "Enter new episodes: ";
                cin >> episodes;
                cout << "Enter new seasons: ";
                cin >> seasons;
                cout << "Enter new genre: ";
                cin >> genre;
                found = true;
            }

            temp_file << name << "," << episodes << "," << seasons << "," << genre << endl;
        }

        file.close();
        temp_file.close();

        if (found) {
            remove("longAnime.txt");
            rename("temp.txt", "longAnime.txt");
            cout << "Anime updated successfully!" << endl;
        }
        else {
            remove("temp.txt");
            cout << "Anime not found!" << endl;
        }
    }


};

class short_anime :public anime {
public:
    bool search_short_anime(string anime_name) {
        ifstream file("shortAnime.txt");
        string line, _name, _episodes, _seasons, _genre;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, _name, ',');
            getline(ss, _episodes, ',');
            getline(ss, _seasons, ',');
            getline(ss, _genre, ',');

            if (_name == anime_name) {
                return true;
            }
        }

        file.close();
        return false;
    }

    void add_short_anime()
    {
        cout << "Enter Name of Anime: " << endl;
        cin >> name;
        if (search_short_anime(name)) {
            cout << "Anime already exists!" << endl;
        }
        else {
            cout << "Enter No of episodes: " << endl;
            cin >> no_of_episodes;
            cout << "Enter No of seasons: " << endl;
            cin >> no_of_seasons;
            cout << "Enter Genre of Anime: " << endl;
            cin >> genre;
            ofstream outfile("shortAnime.txt", ios::app);
            if (outfile.is_open())
            {
                outfile << name << "," << no_of_episodes << "," << no_of_seasons << "," << genre << endl;
                cout << name << " added successfully to the file." << endl;
            }
            else
                cout << "Unable to open or create file." << endl;
        }

    }//End of add_short_anime function 

    void view_short_anime() {
        ifstream file("shortAnime.txt");
        string line, name, episodes, seasons, genre;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, episodes, ',');
            getline(ss, seasons, ',');
            getline(ss, genre, ',');

            cout << "Name: " << name << endl;
            cout << "Episodes: " << episodes << endl;
            cout << "Seasons: " << seasons << endl;
            cout << "Genre: " << genre << endl;
            cout << "------------------------" << endl;
        }

        file.close();
    }

    void suggest_short_anime() {
        ifstream file("shortAnime.txt");
        string line, name, episodes, seasons, genre;
        int count = 0;

        while (getline(file, line)) {
            count++;
        }

        file.clear();
        file.seekg(0);

        srand(time(0));
        int random_line = rand() % count;

        for (int i = 0; i <= random_line; i++) {
            getline(file, line);
        }

        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, episodes, ',');
        getline(ss, seasons, ',');
        getline(ss, genre, ',');

        cout << "Suggested Short Anime: " << name << endl << endl;
        cout << "Name: " << name << endl;
        cout << "Episodes: " << episodes << endl;
        cout << "Seasons: " << seasons << endl;
        cout << "Genre: " << genre << endl;

        file.close();
    }

    void delete_short_anime() {
        string anime_name;
        cout << "Enter Name of Anime: " << endl;
        cin >> anime_name;
        if (search_short_anime(anime_name)) {

            ifstream infile("shortAnime.txt");
            ofstream temp_file("temp.txt");
            string line, _name, _episodes, _seasons, _genre;

            while (getline(infile, line)) {
                stringstream ss(line);
                getline(ss, _name, ',');
                getline(ss, _episodes, ',');
                getline(ss, _seasons, ',');
                getline(ss, _genre, ',');

                if (_name != anime_name) {
                    temp_file << line << endl;
                }
            }

            infile.close();
            temp_file.close();

            remove("shortAnime.txt");
            rename("temp.txt", "shortAnime.txt");
            cout << anime_name << " Deleted Successfully from the file\n";
        }
        else
            cout << "No Anime of name ' " << anime_name << " ' exists in the databse.\n";
    }//End of delete_short_anime() function

    void update_short_anime(string anime_name) {
        ifstream file("shortAnime.txt");
        ofstream temp_file("temp.txt");
        string line, name, episodes, seasons, genre;

        bool found = false;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, episodes, ',');
            getline(ss, seasons, ',');
            getline(ss, genre, ',');

            if (name == anime_name) {
                cout << "Enter new episodes: ";
                cin >> episodes;
                cout << "Enter new seasons: ";
                cin >> seasons;
                cout << "Enter new genre: ";
                cin >> genre;
                found = true;
            }

            temp_file << name << "," << episodes << "," << seasons << "," << genre << endl;
        }

        file.close();
        temp_file.close();

        if (found) {
            remove("shortAnime.txt");
            rename("temp.txt", "shortAnime.txt");
            cout << "Anime updated successfully!" << endl;
        }
        else {
            remove("temp.txt");
            cout << "Anime not found!" << endl;
        }
    }


};





void add_new_anime()
{
    long_anime lobj;
    short_anime sobj;
    int choice;
start:
    cout << "What Type of Anime You Want to Add?" << endl;
    cout << "1.Long Anime\n2.Short Anime" << endl;
    cout << "Enter Your Choice: " << endl;
    cin >> choice;
    if (choice == 1)
    {
        cout << "Long Anime List" << endl;
        lobj.add_long_anime();
    }
    else if (choice == 2)
    {
        sobj.add_short_anime();
        cout << "Short Anime List" << endl;
    }
    else
    {
        system("cls");
        cout << "Invalid choice, Please Enter valid number(1-2)\n";
        cout << "--------------------------------------------------\n";
        goto start;
    }
}//End of add_new_anime() function

void delete_an_anime() {
    long_anime lobj;
    short_anime sobj;
    int choice;
    string _name;
start:
    cout << "What Type of Anime You Want to delete?" << endl;
    cout << "1.Long Anime\n2.Short Anime" << endl;
    cout << "Enter Your Choice: " << endl;
    cin >> choice;
    if (choice == 1)
    {
        lobj.delete_long_anime();
    }
    else if (choice == 2)
    {
        sobj.delete_short_anime();
    }
    else
    {
        system("cls");
        cout << "Invalid choice, Please Enter valid number(1-2)\n";
        cout << "--------------------------------------------------\n";
        goto start;
    }
}

void view_anime_list() {

    long_anime lobj;
    short_anime sobj;
    int choice;
start:
    cout << "What Type of Anime You Want to See?" << endl;
    cout << "1.All Anime\n2.Short Anime\n3.Long Anime" << endl;
    cout << "Enter Your Choice: " << endl;
    cin >> choice;
    if (choice == 1)
    {
        system("cls");
        lobj.view_long_anime();
        sobj.view_short_anime();

    }
    else if (choice == 2)
    {
        system("cls");
        sobj.view_short_anime();
    }
    else if (choice == 3)
    {
        system("cls");
        lobj.view_long_anime();
    }
    else
    {
        system("cls");
        cout << "Invalid choice, Please Enter valid number(1-3)\n";
        cout << "--------------------------------------------------\n";
        goto start;
    }
}

void get_random_anime() {
    long_anime lobj;
    short_anime sobj;
    int choice;
start:
    cout << "What type of anime would you like to watch?" << endl;
    cout << "1. Long Anime" << endl;
    cout << "2. Short Anime" << endl;
    cout << "3. Mix (Both Long and Short)" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        lobj.suggest_long_anime();
        break;
    case 2:
        sobj.suggest_short_anime();
        break;
    case 3:
        suggest_mix_anime();
        break;
    default:
        system("cls");
        cout << "Invalid choice, Please Enter valid number(1-3)\n";
        cout << "--------------------------------------------------\n";
        goto start;

    }


}

void update_anime() {
    system("cls");
    string anime_name;
    long_anime lobj;
    short_anime sobj;
    cout << "Enter the name of the anime to update: ";
    cin >> anime_name;
start:
    int choice;
    cout << "What type of anime is this?" << endl;
    cout << "1. Long Anime" << endl;
    cout << "2. Short Anime" << endl;
    cin >> choice;

    if (choice == 1) {
        system("cls");
        lobj.update_long_anime(anime_name);
    }
    else if (choice == 2) {
        system("cls");
        sobj.update_short_anime(anime_name);
    }
    else {
        cout << "Invalid choice!,Please Enter a Valid Number (1-2)" << endl;
        goto start;
    }
}

void admin_menu() {
    int choice;
    while (true) {
        system("cls");
        cout << "\tWelcome Admin\n" << endl;
        cout << "1.Add new Anime\n";
        cout << "2.Delete an Anime\n";
        cout << "3.View All Anime\n";
        cout << "4.Search an Anime\n";
        cout << "5.Get Random Anime\n";
        cout << "6.Update Anime Details\n";
        cout << "7.Add User\n";
        cout << "8.View Suggestions\n";
        cout << "9.Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            add_new_anime();
            system("pause");
            break;
        case 2:
            delete_an_anime();
            system("pause");
            break;
        case 3:
            view_anime_list();
            system("pause");
            break;
        case 4:
            search_anime();
            //system("pause");
            break;
        case 5:
            get_random_anime();
            system("pause");
            break;
        case 6:
            update_anime();
            system("pause");
            break;
        case 7:
            add_user();
            system("pause");
            break;
        case 8:
            view_suggestions();
            system("pause");
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid Choice, Please enter valid number(1-8)\n";
            system("pause");
        }
    }
}

void user_menu() {
    string userid, password;
    cout << "Enter your user ID: ";
    cin >> userid;
    cout << "Enter your password: ";
    cin >> password;
    ifstream file("users.txt");
    string line, stored_userid, stored_password;
    bool authenticated = false;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, stored_userid, ',');
        getline(ss, stored_password, ',');
        if (userid == stored_userid && password == stored_password) {
            authenticated = true;
            break;
        }
    }
    file.close();
    if (authenticated) {
        int choice;
        while (true) {
            system("cls");
            cout << "\tWelcome User\n" << endl;
            cout << "1.View Anime List\n";
            cout << "2.Get Random Anime Suggestion\n";
            cout << "3. Rate the Program\n";
            cout << "4.Suggest to improve experience\n";
            cout << "5.Quit\n";
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                view_anime_list();
                system("pause");
                break;
            case 2:
                get_random_anime();
                system("pause");
                break;
            case 3:
                search_anime();
            case 4:
                rate_program();
                system("pause");
                break;
            case 5:
                give_suggestion();
                system("pause");
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid Choice, Please enter valid number(1-6)\n";
                system("pause");
            }
        }
    }
    else {
        cout << "Invalid user ID or password!,Please Enter Correct ID or password" << endl;
        user_menu();
    }
}


void menu() {
    int choice;
    while (true) {
        system("cls");
        cout << "\t\t\t\x1B[36mAnimeSuggest\x1B[0m\n"; // Colored title
        cout << "\t\t================================\n";
        cout << "\t\t\x1B[32mWelcome to AnimeSuggest!\x1B[0m\n"; // Colored welcome message
        cout << "\t\tThe ultimate anime recommendation system\n\n";
        cout << "\t\tPlease select an option:\n";
        cout << "\t\t1. \x1B[34mAdmin Login\x1B[0m\n";
        cout << "\t\t2. \x1B[34mUser Login\x1B[0m\n";
        cout << "\t\t3. \x1B[34mQuit\x1B[0m\n\n";
        cout << "\t\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            admin_menu();
            break;
        case 2:
            user_menu();
            break;
        case 3:
            cout << "\t\t\x1B[32mThanks for using AnimeSuggest!\x1B[0m\n";
            exit(0);
        default:
            cout << "\t\t\x1B[31mInvalid choice. Please try again.\x1B[0m\n";
            system("pause");
        }
    }
}



int main()
{
    menu();
}

void suggest_mix_anime() {
    ifstream file1("longAnime.txt");
    ifstream file2("shortAnime.txt");
    string line, name, episodes, genre, seasons;
    int count1 = 0, count2 = 0;

    while (getline(file1, line)) {
        count1++;
    }

    while (getline(file2, line)) {
        count2++;
    }

    int total_count = count1 + count2;
    srand(time(0));
    int random_line = rand() % total_count;

    if (random_line < count1) {
        file1.clear();
        file1.seekg(0);

        for (int i = 0; i <= random_line; i++) {
            getline(file1, line);
        }

        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, episodes, ',');
        getline(ss, seasons, ',');
        getline(ss, genre, ',');

        cout << "Suggested Anime: " << name << endl << endl;
        cout << "Name: " << name << endl;
        cout << "Episodes: " << episodes << endl;
        cout << "Seasons: " << seasons << endl;
        cout << "Genre: " << genre << endl;
    }
    else {
        file2.clear();
        file2.seekg(0);

        for (int i = 0; i <= (random_line - count1); i++) {
            getline(file2, line);
        }

        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, episodes, ',');
        getline(ss, seasons, ',');
        getline(ss, genre, ',');

        cout << "Suggested Anime: " << name << endl << endl;
        cout << "Name: " << name << endl;
        cout << "Episodes: " << episodes << endl;
        cout << "Seasons: " << seasons << endl;
        cout << "Genre: " << genre << endl;
    }

    file1.close();
    file2.close();
}
void rate_program() {
    int rating;
    cout << "Please rate our program (1-5): ";
    cin >> rating;

    if (rating < 1 || rating > 5) {
        cout << "Invalid rating! Please enter a number between 1 and 5." << endl;
        rate_program();
    }
    else {
        ofstream file("program_rating.txt", ios_base::app);
        file << rating << endl;
        file.close();

        cout << "Thank you for your feedback!" << endl;
    }
    display_average_rating();
}
void display_average_rating() {
    ifstream file("program_rating.txt");
    int sum = 0, count = 0, rating;
    while (file >> rating) {
        sum += rating;
        count++;
    }
    file.close();
    if (count == 0) {
        cout << "No ratings yet!" << endl;
    }
    else {
        double average = static_cast<double>(sum) / count;
        cout << "Average rating: " << average << endl;
    }
}
void add_user() {
    string userid, password;
    cout << "Enter new user's ID: ";
    cin >> userid;
    cout << "Enter new user's password: ";
    cin >> password;

    ofstream file("users.txt", ios_base::app);
    file << userid << "," << password << endl;
    file.close();

    cout << "User added successfully!" << endl;
}
void give_suggestion() {
    string suggestion;
    cout << "Enter your suggestion to improve the program: ";
    cin.ignore();
    getline(cin, suggestion);

    ofstream file("suggestions.txt", ios_base::app);
    file << suggestion << endl;
    file.close();

    cout << "Thank you for your suggestion!" << endl;
    cout << "We will do our best to make the user experience better and best\n";
}
void view_suggestions() {
    ifstream file("suggestions.txt");
    if (file.is_open()) {
        string suggestion;
        int count = 1;
        while (getline(file, suggestion)) {
            cout << "Suggestion " << count << ": " << suggestion << endl;
            count++;
        }
        file.close();
    }
    else {
        cout << "No suggestions available." << endl;
    }
}
void search_anime() {
    string search_term;
    cout << "Enter Anime name: ";
    cin >> search_term;
    bool found = false;
    // Search in shortAnime.txt
    ifstream short_file("shortAnime.txt");
    string line, name, seasons, episodes, genre;
    while (getline(short_file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, episodes, ',');
        getline(ss, seasons, ',');
        getline(ss, genre, ',');
        if (name.find(search_term) != string::npos) {
            cout << "Short Anime: " << name << ", Episodes: " << episodes << ", Seasons: " << seasons << ", Genre: " << genre << endl;
            found = true;
        }
    }
    short_file.close();
    // Search in longAnime.txt
    ifstream long_file("longAnime.txt");
    while (getline(long_file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, episodes, ',');
        getline(ss, seasons, ',');
        getline(ss, genre, ',');
        if (name.find(search_term) != string::npos) {
            cout << "Long Anime: " << name << ", Episodes: " << episodes << ", Seasons: " << seasons << ", Genre: " << genre << endl;
            found = true;
        }
    }
    long_file.close();
    if (!found) {
        cout << "No matching anime found." << endl;
    }
    system("pause");
}


