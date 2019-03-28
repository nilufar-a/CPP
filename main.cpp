#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include <Task.h>
#include <Date.h>
#include <University.h>
#include <Work.h>
#include <Shopping.h>

using namespace std;

ofstream myfile;

void addTask();
void saveTask(Task task);
void saveUniversity(University university);
void saveWork(Work work);
void saveShopping(Shopping shopping);
vector<Task> getAllTasks();
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
string mapCategory(int value);

int main()
{
    int decision;
    while(true)
    {
      cout << endl << endl;
      cout<<"Press 0 to exit, 1 to Add Task, 2 to see All Task, 3 to see Unfinished Tasks, 4 to search by Category: ";
      cin >> decision;
      cout << endl << endl;

      if(decision == 1) {
            addTask();
      }
      else if(decision == 2) {
            vector<Task> tasks = getAllTasks();
            for(vector<int>::size_type i = 0; i != tasks.size(); i++ )
            {
                cout << "Name : " << tasks[i].getName() << ", Description: " << tasks[i].getDescription()
                     << ", Category: " << mapCategory(tasks[i].getCategory());
                cout << endl;
            }
      }
      else if(decision == 3) {
          int day, month,  year;
          cout << "Enter todays day: ";
          cin >> day ;
          cout << "Enter todays month: ";
          cin >> month ;
          cout << "Enter todays year ";
          cin >> year ;

          vector<Task> tasks = getAllTasks();
          for(vector<int>::size_type i = 0; i != tasks.size(); i++ )
          {
                Date date = tasks[i].getEndDate();
                if(date.getYear() > year || (date.getYear() >= year && month > month) || (date.getYear() >= year && date.getMonth() >= month && date.getDay() > day))
                {
                    cout << "Name : " << tasks[i].getName() << ", Description: " << tasks[i].getDescription()
                     << ", Category: " << mapCategory(tasks[i].getCategory());
                    cout << endl;
                }
           }
      }
      else if(decision == 4) {
          vector<Task> tasks = getAllTasks();
          int d;
          cout << "Press 9 for default Tasks, 1 to search for University, 2 for work and 3 for shopping: ";
          cin >> d;
          cout << endl;

          for(vector<int>::size_type i = 0; i != tasks.size(); i++ )
          {
              if(d == tasks[i].getCategory() && d == 1)
              {
                  cout << "Name : " << tasks[i].getName() << ", Description: " << tasks[i].getDescription() << ", Category: "
                     << mapCategory(tasks[i].getCategory()) << ", Number of Homeworks: " << tasks[i].getData1()
                     << ", Number of Midterm: " << tasks[i].getData2();
                  cout << endl;
              }
              else if(d == tasks[i].getCategory() && d == 2)
              {
                   cout << "Name : " << tasks[i].getName() << ", Description: " << tasks[i].getDescription() << ", Category: "
                        << mapCategory(tasks[i].getCategory()) << ", Number of working hours: " << tasks[i].getData1();
              }
              else if(d == tasks[i].getCategory() && d == 3)
              {
                   cout << "Name : " << tasks[i].getName() << ", Description: " << tasks[i].getDescription() << ", Category: "
                        << mapCategory(tasks[i].getCategory()) << ", Price for shopping: " << tasks[i].getData1();
              }
              else if(d == 9) {
                cout << "Name : " << tasks[i].getName() << ", Description: " << tasks[i].getDescription()
                     << ", Category: " << mapCategory(tasks[i].getCategory());
                cout << endl;
              }
          }
      }

      if(decision == 0)
            break;
    }

    cout << endl << endl << endl;
    return 0;
}


vector<Task> getAllTasks() { //function to return all tasks read from file, tasks.txt, return value will be a vector of Task
    vector<Task> tasks;

    try{
    string line;
    ifstream file ("tasks.txt");

    string name, description;
    int priority, category;
    int sday, smonth, syear, eday, emonth, eyear;
    int data1,  data2;

    cout << endl;
    if (file.is_open())
    {
        while (getline(file, line))
        {
           vector<string> v;
           split(line, v, ' ');
           name = v[0];
           description  = v[1];
           priority =  atoi(v[2].c_str());
           category =  atoi(v[3].c_str());
           sday =   atoi(v[4].c_str());
           smonth =   atoi(v[5].c_str());
           syear =  atoi(v[6].c_str());
           eday =   atoi(v[7].c_str());
           emonth =  atoi(v[8].c_str());
           eyear =   atoi(v[9].c_str());
           data1 =  atoi(v[10].c_str());
           data2 = atoi(v[11].c_str());

           Date startDate(sday, smonth, syear);
           Date endDate(eday, emonth, eyear);

           Task t(name, description, startDate, endDate, priority, category);
           t.setData1(data1);
           t.setData2(data2);
           tasks.push_back(t);
        }
    }
    file.close();
    }
    catch(exception &ex) {
     cout << "Error occured";
    }
    return tasks;
}


void saveTask(Task task, bool finish) { //function to save task to file, task is passed as parameter to the function
    myfile.open ("tasks.txt", ios_base::app);
    myfile << task.getName();
    myfile << " ";
    myfile << task.getDescription();
    myfile << " ";
    myfile << task.getPriority();
    myfile << " ";
    myfile << task.getCategory();
    myfile << " ";
    myfile << task.getStartDate().getDay();
    myfile << " ";
    myfile << task.getStartDate().getMonth();
    myfile << " ";
    myfile << task.getStartDate().getYear();
    myfile << " ";
    myfile << task.getEndDate().getDay();
    myfile << " ";
    myfile << task.getEndDate().getMonth();
    myfile << " ";
    myfile << task.getEndDate().getYear();

    if(finish == true) {
    myfile << " ";
    myfile << 0;
    myfile << " ";
    myfile << 0;
    myfile << "\n";
   }
}


void saveUniversity(University university) { //function to save university task, we need to call saveTask function, then save other university properties
    saveTask(university, false); //save university, this is possible because of polymorphism(subtyping) achieved through inheritance
    myfile << " ";
    myfile << university.getNumHw();
    myfile << " ";
    myfile << university.getNumMid();
    myfile << "\n";
}

void saveShopping(Shopping shopping) { //same as for university, but in this case shopping
    saveTask(shopping, false);
    myfile << " ";
    myfile << shopping.getPrice();
    myfile << " ";
    myfile << shopping.getQuant();
    myfile << "\n";
}

void saveWork(Work work) { //same as for university, but in this case work
    saveTask(work, false);
    myfile << " ";
    myfile << work.getHours();
    myfile << "\n";
}




void addTask() //function to add tasks, getinput from user first, then save to file
{
    string name, description;
    int sday, smonth, syear, eday, emonth, eyear;
    int priority, category;

    cout << "Enter the name of the task: ";
    cin >> name;


    cout << "Enter the description of the task: ";
    cin >> description;

    cout << "Enter the starting day: ";
    cin >> sday;

    cout << "Enter the starting month: ";
    cin >> smonth;

    cout << "Enter the starting year: ";
    cin >> syear;

    cout << "Enter the ending day: ";
    cin >> eday;

    cout << "Enter the ending month: ";
    cin >> emonth;

    cout << "Enter the ending year: ";
    cin >> eyear;

    cout << "Enter the priority of the task: ";
    cin >> priority;

    cout << "Enter the category of the task, 0 for default, 1 for University, 2 for Work, 3 For Shopping: ";
    cin >> category;

    Date startDate(sday, smonth, syear);
    Date endDate(eday, emonth, eyear);

    if(category == 0) {
        Task task(name, description, startDate, endDate, priority, category);
        saveTask(task, true);
    }
    else if(category == 1) {
        int md, hw;
        cout << "Enter the number of homeworks: ";
        cin >> hw;
        cout << "Enter the number of midterms: ";
        cin >> md;
        University university(name, description, startDate, endDate, priority, category, hw, md);
        saveUniversity(university);
    }
    else if(category == 2){
        int hours;
        cout << "Enter the number of hours: ";
        cin >> hours;
        Work work(name, description, startDate, endDate, priority, category, hours);
        saveWork(work);
    }
    else if(category == 3) {
        int price,quant;
        cout << "Enter the price: ";
        cin >> price;
        cout << "Enter the quantity: ";
        cin >> quant;

        Shopping shopping(name, description, startDate, endDate, priority, category, price,quant);
        saveShopping(shopping);
    }
}

string mapCategory(int value) //function that maps category int value to string, returns a string value for the category
{
    if(value == 0) return "Default";
    if(value == 1) return "University";
    if(value == 2) return "Work";
    if(value == 3) return "Shopping";
}

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)//function to split string based on delimeter,
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}
