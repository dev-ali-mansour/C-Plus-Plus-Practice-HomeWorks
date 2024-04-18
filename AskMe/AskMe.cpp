#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

////////////Helper Methods/////////////////
vector<string> ReadFileLines(string path) {
    vector<string> lines;
    fstream file_handler(path.c_str());
    if (file_handler.fail()) {
        cout << "\n\nError: Can't open the file!\n\n";
        return lines;
    }
    string line;

    while (getline(file_handler, line)) {
        if (line.size() == 0)
            continue;
        lines.push_back(line);
    }
    return lines;
}

void WriteFileLines(string path, vector<string> lines, bool append = true) {
    auto status = ios::in | ios::out | ios::app;

    if (!append)
        status = ios::in | ios::out | ios::trunc; // Overwrite

    fstream file_handler(path.c_str(), status);

    if (file_handler.fail()) {
        cout << "\n\nError: Can't open the file!\n\n";
        return;
    }

    for (auto line: lines)
        file_handler << line << "\n";

    file_handler.close();
}

vector<string> SplitString(string s, string delimiter = ",") {
    vector<string> strs;

    int pos = 0;
    string substr;
    while ((pos = (int) s.find(delimiter)) != -1) {
        substr = s.substr(0, pos);
        strs.push_back(substr);
        s.erase(0, pos + delimiter.length());
    }
    strs.push_back(s);
    return strs;
}

int ToInt(string str) {
    istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

int ReadInt(int low, int high) {
    cout << "Enter a number in range " << low << " - " << high << ": ";
    int value;
    cin >> value;
    if (low <= value && value <= high)
        return value;

    cout << "Error: Invalid number...Try again\n";
    return ReadInt(low, high);
}

int ShowReadMenu(vector<string> choices) {
    cout << "\nMenu:\n";
    for (int ch = 0; ch < (int) choices.size(); ++ch) {
        cout << "\t" << ch + 1 << ": " << choices[ch] << endl;
    }
    return ReadInt(1, (int) choices.size());
}

////////////////////////////////////////////////

struct Question {
    int question_id;
    // To support thread. Each question look to a parent question
    // -1 No parent (first question in the thread)
    int parent_question_id;
    int from_user_id;
    int to_user_id;
    bool is_anonymous_question;
    string question_text;
    string answer_text; // empty = not answered

    Question() {
        question_id = parent_question_id = from_user_id = to_user_id = -1;
        is_anonymous_question = true;
    }

    Question(string line) {
        vector<string> substrs = SplitString(line);
        assert(substrs.size() == 7);

        question_id = ToInt(substrs[0]);
        parent_question_id = ToInt(substrs[1]);
        from_user_id = ToInt(substrs[2]);
        to_user_id = ToInt(substrs[3]);
        is_anonymous_question = ToInt(substrs[4]);
        question_text = substrs[5];
        answer_text = substrs[6];
    }

    string ToString() {
        ostringstream oss;
        oss << question_id << "," << parent_question_id << "," << from_user_id << "," << to_user_id << ","
            << is_anonymous_question << "," << question_text << "," << answer_text;
        return oss.str();
    }

    void PrintToQuestion() {
        string prefix = "";
        if (parent_question_id != -1)
            prefix = "\t Thread: ";
        cout << prefix << "Question Id (" << question_id << ")";
        if (!is_anonymous_question)
            cout << " from user id (" << from_user_id << ")";
        cout << "\t Question: " << question_text << endl;
        if (!answer_text.empty())
            cout << prefix << "\tAnswer: " << answer_text << endl;
        cout << endl;
    }

    void PrintFromQuestion() {
        cout << "Question Id (" << question_id << ")";
        if (!is_anonymous_question)
            cout << " !AQ";

        cout << " to user id(" << to_user_id << ")";
        cout << "\t Question: " << question_text << endl;

        if (!answer_text.empty())
            cout << "\t Answer: " << answer_text << endl;
        else cout << "\t NOT ANSWERED YET\n";
    }

    void PrintFeedQuestion() {
        if (parent_question_id != -1)
            cout << "Thread Parent Question ID (" << question_id << ") ";

        cout << "Question Id (" << question_id << ")";
        if (!is_anonymous_question)
            cout << " from user id(" << from_user_id << ")";

        cout << " to user id(" << to_user_id << ")";
        cout << "\t Question: " << question_text << endl;

        if (!answer_text.empty())
            cout << "\t Answer: " << answer_text << endl;
        else cout << "\t NOT ANSWERED YET\n";
    }
};

struct User {
    int user_id;    // internal system ID
    string username;
    string password;
    string name;
    string email;
    bool allow_anonymous_questions;
    vector<int> questions_id_from_me;
    // From question id to list of questions IDS on this question (thread questions) - For this user
    map<int, vector<int>> questionId_questionIdsThead_to_map;

    User() {
        user_id = -1;
        allow_anonymous_questions = false;
    }

    User(string line) {
        vector<string> substrs = SplitString(line);
        assert(substrs.size() == 6);
        user_id = ToInt(substrs[0]);
        username = substrs[1];
        password = substrs[2];
        name = substrs[3];
        email = substrs[4];
        allow_anonymous_questions = ToInt(substrs[5]);
    }

    string ToString() {
        ostringstream oss;
        oss << user_id << "," << username << "," << password << "," << name << "," << email << ","
            << allow_anonymous_questions;
        return oss.str();
    }

    void Print() {
        cout << "User " << user_id << ", " << username << " " << password << ", " << name << ", " << email << endl;
    }
};

struct QuestionsManager {
    // From question id to list of questions IDS on this question (thread questions) - All users
    map<int, vector<int>> questionId_questionIdsThead_to_map;

    // Map the question id to question object. Let's keep one place ONLY with the object
    // When you study pointers, easier handling
    map<int, Question> questionId_questionObject_map;

    int last_id;

    QuestionsManager() {
        last_id = 0;
    }

    void LoadDatabase() {
        last_id = 0;
        questionId_questionIdsThead_to_map.clear();
        questionId_questionObject_map.clear();

        vector<string> lines =
                ReadFileLines(R"(D:\Developing\Projects\C++\HomeWorks\AskMe\questions.txt)");
        for (auto &line: lines) {
            Question question(line);
            questionId_questionObject_map[question.question_id] = question;
            last_id = max(last_id, question.question_id);

            questionId_questionObject_map[question.question_id] = question;

            if (question.parent_question_id != -1)
                questionId_questionIdsThead_to_map[question.question_id].push_back(question.question_id);
            else questionId_questionIdsThead_to_map[question.parent_question_id].push_back(question.question_id);
        }
    }

    void FillUserQuestions(User &user) {
        user.questions_id_from_me.clear();
        user.questionId_questionIdsThead_to_map.clear();

        for (auto &pair: questionId_questionIdsThead_to_map) {
            for (auto &question_id: pair.second) {
                // Get the question from the map. & means same in memory, DON'T COPY
                Question &question = questionId_questionObject_map[question_id];

                if (question.from_user_id == user.user_id)
                    user.questions_id_from_me.push_back(question_id);

                if (question.to_user_id == user.user_id) {
                    if (question.parent_question_id == -1)
                        user.questionId_questionIdsThead_to_map[question.question_id].push_back(question.question_id);
                    else user.questionId_questionIdsThead_to_map[question.parent_question_id].push_back(question_id);
                }
            }
        }
    }

    void PrintUserToQuestions(User &user) {
        cout << "\n";

        if (user.questionId_questionIdsThead_to_map.size() == 0)
            cout << "No Questions";

        for (auto &pair: user.questionId_questionIdsThead_to_map) {        // pair<int, vector<Question>>
            for (auto &question_id: pair.second) {        //  vector<Question>

                // Get the question from the map. & means same in memory, DON'T COPY
                Question &question = questionId_questionObject_map[question_id];
                question.PrintToQuestion();
            }
        }
        cout << "\n";
    }

    void PrintUserFromQuestions(User &user) {
        cout << "\n";
        if (user.questions_id_from_me.size() == 0)
            cout << "No Questions";

        for (auto &question_id: user.questions_id_from_me) {        //  vector<Question>

            // Get the question from the map. & means same in memory, DON'T COPY
            Question &question = questionId_questionObject_map[question_id];
            question.PrintFromQuestion();
        }
        cout << "\n";
    }

    // Used in Answering a question for YOU.
    // It can be any of your questions (thread or not)
    int ReadQuestionIdAny(User &user) {
        int question_id;
        cout << "Enter Question id or -1 to cancel: ";
        cin >> question_id;

        if (question_id == -1)
            return -1;

        if (!questionId_questionObject_map.count(question_id)) {
            cout << "\nERROR: No question with such ID. Try again\n\n";
            return ReadQuestionIdAny(user);
        }
        Question &question = questionId_questionObject_map[question_id];

        if (question.to_user_id != user.user_id) {
            cout << "\nERROR: Invalid question ID. Try again\n\n";
            return ReadQuestionIdAny(user);
        }
        return question_id;
    }

    // Used to ask a question on a specific thread for whatever user
    int ReadQuestionIdThread(User &user) {
        int question_id;
        cout << "For thread question: Enter Question id or -1 for new question: ";
        cin >> question_id;

        if (question_id == -1)
            return -1;

        if (!questionId_questionIdsThead_to_map.count(question_id)) {
            cout << "No thread question with such ID. Try again\n";
            return ReadQuestionIdThread(user);
        }
        return question_id;
    }

    void AnswerQuestion(User &user) {
        int question_id = ReadQuestionIdAny(user);

        if (question_id == -1)
            return;

        Question &question = questionId_questionObject_map[question_id];

        question.PrintToQuestion();

        if (question.answer_text != "")
            cout << "\nWarning: Already answered. Answer will be updated\n";

        cout << "Enter answer: ";    // if user entered comma, system fails :)
        getline(cin, question.answer_text);    // read last enter
        getline(cin, question.answer_text);
    }

    void DeleteQuestion(User &user) {
        int question_id = ReadQuestionIdAny(user);

        if (question_id == -1)
            return;

        vector<int> ids_to_remove;    // to remove from questionid_questionobject_map

        // Let's see if thread or not. If thread, remove all of it
        if (questionId_questionIdsThead_to_map.count(question_id)) { // thread
            ids_to_remove = questionId_questionIdsThead_to_map[question_id];
            questionId_questionIdsThead_to_map.erase(question_id);
        } else {
            ids_to_remove.push_back(question_id);

            // let's find in which thread to remove. Consistency is important when have multi-view
            for (auto &pair: questionId_questionIdsThead_to_map) {
                vector<int> &vec = pair.second;
                for (int pos = 0; pos < (int) vec.size(); ++pos) {
                    if (question_id == vec[pos]) {
                        vec.erase(vec.begin() + pos);
                        break;
                    }
                }
            }

        }

        for (auto id: ids_to_remove) {
            questionId_questionObject_map.erase(id);
        }
    }

    void AskQuestion(User &user, pair<int, int> to_user_pair) {
        Question question;

        if (!to_user_pair.second) {
            cout << "Note: Anonymous questions are not allowed for this user\n";
            question.is_anonymous_question = false;
        } else {
            cout << "Is anonymous questions?: (0 or 1): ";
            cin >> question.is_anonymous_question;
        }

        question.parent_question_id = ReadQuestionIdThread(user);

        cout << "Enter question text: ";    // if user entered comma, system fails :)
        getline(cin, question.question_text);
        getline(cin, question.question_text);

        question.from_user_id = user.user_id;
        question.to_user_id = to_user_pair.first;

        // What happens in 2 parallel sessions who asked question?
        // They are given same id. This is wrong handling :)
        question.question_id = ++last_id;

        questionId_questionObject_map[question.question_id] = question;

        if (question.parent_question_id == -1)
            questionId_questionIdsThead_to_map[question.question_id].push_back(question.question_id);
        else
            questionId_questionIdsThead_to_map[question.parent_question_id].push_back(question.question_id);
    }

    void ListFeed() {
        for (auto &pair: questionId_questionObject_map) {
            Question &question = pair.second;

            if (question.answer_text == "")
                continue;

            question.PrintFeedQuestion();
        }
    }

    void UpdateDatabase() {
        vector<string> lines;

        for (auto &pair: questionId_questionObject_map)
            lines.push_back(pair.second.ToString());

        WriteFileLines(R"(D:\Developing\Projects\C++\HomeWorks\AskMe\questions.txt)", lines, false);
    }

};

struct UsersManager {
    map<string, User> userame_userobject_map;
    User current_user;
    int last_id;

    UsersManager() {
        last_id = 0;
    }

    void LoadDatabase() {
        last_id = 0;
        userame_userobject_map.clear();

        vector<string> lines = ReadFileLines(R"(D:\Developing\Projects\C++\HomeWorks\AskMe\users.txt)");
        for (auto &line: lines) {
            User user(line);
            userame_userobject_map[user.username] = user;
            last_id = max(last_id, user.user_id);
        }
    }

    void AccessSystem() {
        int choice = ShowReadMenu({"Login", "Sign Up"});
        if (choice == 1)
            DoLogin();
        else
            DoSignUp();
    }

    void DoLogin() {
        LoadDatabase();    // in case user added from other parallel run

        while (true) {
            cout << "Enter username & password: ";
            cin >> current_user.username >> current_user.password;

            if (!userame_userobject_map.count(current_user.username)) {
                cout << "\nInvalid username or password. Try again\n\n";
                continue;
            }
            User user_exist = userame_userobject_map[current_user.username];

            if (current_user.password != user_exist.password) {
                cout << "\nInvalid username or password. Try again\n\n";
                continue;
            }
            current_user = user_exist;
            break;
        }
    }

    void DoSignUp() {
        while (true) {
            cout << "Enter username. (No spaces): ";
            cin >> current_user.username;

            if (userame_userobject_map.count(current_user.username))
                cout << "Already used. Try again\n";
            else
                break;
        }
        cout << "Enter password: ";
        cin >> current_user.password;

        cout << "Enter name: ";
        cin >> current_user.name;

        cout << "Enter email: ";
        cin >> current_user.email;

        cout << "Allow anonymous questions? (0 or 1): ";
        cin >> current_user.allow_anonymous_questions;

        // What happens in 2 parallel sessions if they signed up?
        // They are given same id. This is wrong handling :)
        current_user.user_id = ++last_id;
        userame_userobject_map[current_user.username] = current_user;

        UpdateDatabase(current_user);
    }

    void ListUsersNamesIds() {
        for (auto &pair: userame_userobject_map)
            cout << "ID: " << pair.second.user_id << "\t\tName: " << pair.second.name << "\n";
    }

    pair<int, int> ReadUserId() {
        int user_id;
        cout << "Enter User id or -1 to cancel: ";
        cin >> user_id;

        if (user_id == -1)
            return make_pair(-1, -1);

        for (auto &pair: userame_userobject_map) {
            if (pair.second.user_id == user_id)
                return make_pair(user_id, pair.second.allow_anonymous_questions);
        }

        cout << "Invalid User ID. Try again\n";
        return ReadUserId();
    }

    void UpdateDatabase(User &user) {
        string line = user.ToString();
        vector<string> lines(1, line);
        WriteFileLines(R"(D:\Developing\Projects\C++\HomeWorks\AskMe\users.txt)", lines);
    }
};

struct AskMeSystem {
    UsersManager users_manager;
    QuestionsManager questions_manager;

    void LoadDatabase(bool fill_user_questions = false) {
        users_manager.LoadDatabase();
        questions_manager.LoadDatabase();

        if (fill_user_questions)    // first time, waiting for login
            questions_manager.FillUserQuestions(users_manager.current_user);
    }

    void run() {
        LoadDatabase();
        users_manager.AccessSystem();
        questions_manager.FillUserQuestions(users_manager.current_user);

        vector<string> menu;
        menu.push_back("Print Questions To Me");
        menu.push_back("Print Questions From Me");
        menu.push_back("Answer Question");
        menu.push_back("Delete Question");
        menu.push_back("Ask Question");
        menu.push_back("List System Users");
        menu.push_back("Feed");
        menu.push_back("Logout");

        while (true) {
            int choice = ShowReadMenu(menu);
            LoadDatabase(true);

            if (choice == 1)
                questions_manager.PrintUserToQuestions(users_manager.current_user);
            else if (choice == 2)
                questions_manager.PrintUserFromQuestions(users_manager.current_user);
            else if (choice == 3) {
                questions_manager.AnswerQuestion(users_manager.current_user);
                questions_manager.UpdateDatabase();
            } else if (choice == 4) {
                questions_manager.DeleteQuestion(users_manager.current_user);
                // Let's build again (just easier, but slow)
                questions_manager.FillUserQuestions(users_manager.current_user);
                questions_manager.UpdateDatabase();
            } else if (choice == 5) {
                pair<int, int> to_user_pair = users_manager.ReadUserId();
                if (to_user_pair.first != -1) {
                    questions_manager.AskQuestion(users_manager.current_user, to_user_pair);
                    questions_manager.UpdateDatabase();
                }
            } else if (choice == 6)
                users_manager.ListUsersNamesIds();
            else if (choice == 7)
                questions_manager.ListFeed();
            else
                break;
        }
        run();    // Restart again
    }
};


int main() {
    AskMeSystem service;
    service.run();

    return 0;
}