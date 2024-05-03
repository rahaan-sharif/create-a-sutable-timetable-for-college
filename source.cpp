//library
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

class time_section {
public:
    string day[7] = { "saturday ", " sunday  ", " monday  ", " tuesday ", "wednesday", "thursday "," friday  " };
    string clock[8] = { "(8)", "(9)", "(10)", "(11)", "(14)", "(15)", "(16)","(17)" };
    int tcheck[16][7][8];
    int pcheck[7][8];
    int day_time[7][8];
    int week[16][7][8];
    time_section() {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                day_time[i][j] = 0;
                pcheck[i][j] = 0;
            }

        }

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    week[i][j][k] = 0;
                    tcheck[i][j][k] = 0;
                }
            }
        }
    }
    void time_sections(int a = -1, int b = -1, int c = -1, int aa = -1, int bb = -1, int cc = -1)
    {
        for (int i = 0; i < c; i++)
        {
            day_time[a][b + i] = 1;
        }
        for (int i = 0; i < cc; i++)
        {
            day_time[aa][bb + i] = 1;
        }
        cout << "********\n";
        cout << "                              -** schedule **-" << endl;
        cout << "                ";
        for (int i = 0; i < 8; i++)
            cout << clock[i] << "\t";
        cout << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << day[i] << "\t";
            for (int j = 0; j < 8; j++)
            {
                cout << day_time[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "*********\n";
    }
    void showtime() {
        cout << "\nshowtime:" << endl;
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (day_time[i][j] == 1)
                {
                    cout << "day: " << i << endl;
                    cout << "time: " << j << endl;
                    cout << endl;
                }
            }
        }


    }

    void week_time(int a = -1, int b = -1, int c = -1, int d = -1, int e = -1)
    {
        if ((a > -1) && (b > -1) && (c > -1) && (d > -1))
        {
            for (int i = a; i < a + b; i++)
                for (int j = d; j < d + e; j++)
                {
                    {
                        week[i][c][j] = 1;
                    }
                }
        }
    }
    void week_show()
    {
        for (int i = 0; i < 16; i++)
        {
            cout << "week: " << i << endl;
            for (int j = 0; j < 7; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    cout << week[i][j][k] << "  ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    void reset_day()
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
                day_time[i][j] = 0;
        }
    }

    void reset_week()
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    week[i][j][k] = 0;
                }
            }
        }
    }
};

//class permanent titles:
class C :public time_section
{
public:
    int check_room;//checks if it has classroom or not.
    static int id_count;//counts number of entered classes.
    char name[20], teacher[20];
    int location_id;//gets the class id entered by education.
    int hour[4], tool[4]/*duration of classes.*/, count/*counter of students*/, studentnumber, x = 0, k;
    bool abc = false;
    int student[40];
    int idd/*id of this class*/, idd2, teacher_id/*gets the professor id.*/;
    bool per;  int sessions;
public:

    C() {
        idd2 = id_count;
        id_count++;
    };
    void store() {
        for (int i = 0; i < 2; i++) {
            hour[i] = 0; tool[i] = 0;
        }
        cout << "**-**" << endl;
        cout << "ID: ";
        cin >> idd;
        cout << "title: ";
        cin >> name;



        cout << "*** sections ***\n";
        cout << "(if there is just one section, enter -1 for second one.\n";
        int a = 0;
        cout << "section 1:" << endl;
        cout << "day: 0-saturday  1-sunday  2-monday  3-tuesday  4-wednesday  5-thursday  6-friday\n";
        cin >> a;
        cout << "starts:\n";
        cout << "(0)eight  (1)nine  (2)ten  (3)eleven\n";
        cout << "(4)fourteen  (5)fifteen  (6)sixteen  (7)seventeen\n";
        cin >> hour[0];
        cout << "duration:";
        cin >> hour[1];
        int c = hour[1];

        int aa = 0;
        cout << "section 2:" << endl;
        cout << "day: 0-saturday  1-sunday  2-monday  ";
        cout << "3-tuesday  4-wednesday  5-thursday  6-friday\n\n";
        cin >> aa;
        cout << "starts:\n";
        cout << "(0)eight  (1)nine  (2)ten  (3)eleven\n";
        cout << "(4)fourteen  (5)fifteen  (6)sixteen  (7)seventeen\n";
        cin >> hour[2];
        cout << "duration:";
        cin >> hour[3];
        int cc = hour[3];

        time_sections(a, hour[0], c, aa, hour[2], cc);

        count = 50;
        while (count > 40)
        {
            cout << "insert number of student: ";
            cin >> count;
            if (count > 40)
                cout << "----out of range!" << endl;
        }

        for (int i = 0; i < count; i++) {
            cout << "enter student ID of student: " << i + 1 << " : ";
            cin >> student[i];
        }

        cout << "teacher: ";
        cin >> teacher;
        cout << "enter teacher id: ";
        cin >> teacher_id;
        cout << "location:(\nif you dont want choose any classrom, enter 0; else, enter class id: ";
        cin >> location_id;
    }
    void print() {
        cout << "------------\n";
        cout << "\nID: " << idd << endl;;
        cout << "name: " << name << endl;
        showtime();

        cout << "student list: ";
        int i = 0;
        for (int i = 0; i < count; i++)
        {
            cout << "student ID of student: " << i + 1 << " : " << student[i] << endl;
        }

        cout << "teacher: ";
        cout << teacher << endl;
        cout << "location: ";
        cout << location_id << endl;
    }

    //compare class time for logic presence of student, professor, physical classroom and also id of classess:
    int c_s(C ob, int voroodi) {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (ob.day_time[i][j] == day_time[i][j])
                {
                    for (int ii = 0; ii < count; ii++)
                    {
                        for (int jj = 0; jj < ob.count; jj++)
                        {
                            if (location_id == ob.location_id)
                            {
                                if (idd == ob.idd) {
                                    cout << "***\n***\n";
                                    cout << "error!\none two classes have the same ID.\n";
                                    cout << "please pay attention to the last class.\n";
                                    cout << "***\n***\n";
                                    reset_day();
                                    voroodi--;
                                    return voroodi;
                                }
                                if (location_id != 0)
                                {
                                    cout << "***\n***\n";
                                    cout << "error!\ntwo classes are in one location in the same time.\n";
                                    cout << "please pay attention to the last class.\n";
                                    cout << "***\n***\n";
                                    reset_day();
                                    voroodi--;
                                    return voroodi;
                                }
                            }
                            if (teacher_id == ob.teacher_id) {
                                cout << "***\n***\n";
                                cout << "error!\none teacher is detected in two classes in the same time.\n";
                                cout << "please pay attention to the last class.\n";
                                cout << "***\n***\n";
                                reset_day();
                                voroodi--;
                                return voroodi;
                            }
                            if (student[ii] == ob.student[jj])
                            {
                                cout << "***\n***\n";
                                cout << "error!\none student is detected in two classes in the same time.\n";
                                cout << "please pay attention to the last class.\n";
                                cout << "***\n***\n";
                                reset_day();
                                voroodi--;
                                return voroodi;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

};
int C::id_count = 0;

//class temporary titles:
class T :public time_section
{
public:
    int check_room;//checks if it has classroom or not.
    static int id_count;//counts number of entered classes.
    char name[20], teacher[20];
    int location_id;//gets the class id entered by education.
    int hour[4], tool[4]/*duration of classes.*/, count, studentnumber, x = 0, k;
    bool abc = false;
    int student[40];
    int idd/*id of this class*/, idd2, teacher_id/*gets the professor id.*/;
    bool per;  int sessions;
public:

    T() {
        idd2 = id_count;
        id_count++;
    };
    void store() {
        for (int i = 0; i < 2; i++) {
            hour[i] = 0; tool[i] = 0;
        }
        cout << "**-**" << endl;
        cout << "ID: ";
        cin >> idd;
        cout << "title: ";
        cin >> name;
        cout << "\n**weeks: " << endl;
        int wd = 0, ws = 0;
        int week_duration = 0, week_start = 0;
        cout << "enter start time(week)(begin from zero): ";
        cin >> ws;
        week_start = ws;
        cout << "enter duration time(week)(begin from one):";
        cin >> wd;
        week_duration = wd;
        cout << "duration is: " << wd << endl;

        cout << "\n\n                       *** sections ***\n";
        cout << "    (if there is just one section, enter -1 for second one.)\n\n";
        int a = 0;
        int day = 0;
        int hour_start = 0, hour_duration = 0;
        cout << "section 1:" << endl;
        cout << "day: 0-saturday  1-sunday  2-monday  3-tuesday  4-wednesday  5-thursday  6-friday\n";
        cin >> a;
        day = a;
        cout << "starts:\n";
        cout << "(0)eight  (1)nine  (2)ten  (3)eleven\n";
        cout << "(4)fourteen  (5)fifteen  (6)sixteen  (7)seventeen\n";
        cin >> hour[0];
        hour_start = hour[0];
        cout << "duration: (1)one hour   (2)two hour: ";
        cin >> hour[1];
        hour_duration = hour[1];
        week_time(week_start, week_duration, day, hour_start, hour_duration);

        int aa = 0;
        cout << "section 2:" << endl;
        cout << "day: 0-saturday  1-sunday  2-monday  ";
        cout << "3-tuesday  4-wednesday  5-thursday  6-friday\n";
        cin >> aa;
        day = aa;
        cout << "starts:\n";
        cout << "(0)eight  (1)nine  (2)ten  (3)eleven\n";
        cout << "(4)fourteen  (5)fifteen  (6)sixteen  (7)seventeen\n";
        cin >> hour[2];
        hour_start = hour[2];
        cout << "duration: (1)one hour  (2)two hour";
        cin >> hour[3];
        hour_duration = hour[3];
        week_time(week_start, week_duration, day, hour_start, hour_duration);
        cout << "**********" << endl;
        week_show();
        cout << "**********" << endl;


        do {
            cout << "enter the number of student: ";
            cin >> count;
            if (count < 40 && count >= 0) {
                x = 1;
                for (int i = 0; i < count; i++) {
                    cout << "enter student ID of student: " << i + 1 << " : ";
                    cin >> student[i];
                }
            }
            else { cout << "out of the range" << endl; }
        } while (x == 0);

        cout << "teacher: ";
        cin >> teacher;
        cout << "enter teacher id: ";
        cin >> teacher_id;
        cout << "location:(\nif you dont want choose any classrom, enter 0; else, enter class id: ";
        cin >> location_id;
    }
    void print() {
        cout << "------------\n";
        cout << "\nID: " << idd << endl;;
        cout << "name: " << name << endl;
        week_show();

        cout << "student list: ";
        int i = 0;
        for (int i = 0; i < count; i++)
        {
            cout << "student ID of student: " << i + 1 << " : " << student[i] << endl;
        }

        cout << "teacher: ";
        cout << teacher << endl;
        cout << "location: ";
        cout << location_id << endl;
    }

    //compare class time for logic presence of student, professor, physical classroom and also id of classess:
    int c_s(T ob, int voroodi) {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (ob.week[i][j][k] == week[i][j][k])
                    {
                        for (int ii = 0; ii < count; ii++)
                        {
                            for (int jj = 0; jj < ob.count; jj++)
                            {
                                if (location_id == ob.location_id)
                                {
                                    if (idd == ob.idd) {
                                        cout << "***\n***\n";
                                        cout << "error!\ntwo classes have the same ID.\n";
                                        cout << "please pay attention to the last class.\n";
                                        cout << "***\n***\n";
                                        reset_week();
                                        voroodi--;
                                        return voroodi;
                                    }
                                    if (location_id != 0)
                                    {
                                        cout << "***\n***\n";
                                        cout << "error!\ntwo classes are in one location in the same time.\n";
                                        cout << "please pay attention to the last class.\n";
                                        cout << "***\n***\n";
                                        reset_week();
                                        voroodi--;
                                        return voroodi;
                                    }
                                }
                                if (teacher_id == ob.teacher_id) {
                                    cout << "***\n***\n";
                                    cout << "error!\none teacher is detected in two classes in the same time.\n";
                                    cout << "please pay attention to the last class.\n";
                                    cout << "***\n***\n";
                                    reset_week();
                                    voroodi--;
                                    return voroodi;
                                }
                                if (student[ii] == ob.student[jj])
                                {
                                    cout << "***\n***\n";
                                    cout << "error!\none student is detected in two classes in the same time.\n";
                                    cout << "please pay attention to the last class.\n";
                                    cout << "***\n***\n";
                                    reset_week();
                                    voroodi--;
                                    return voroodi;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

};
int T::id_count = 0;

//*************************************************************


//pemanent classrooms:
class pclassroom : public time_section
{
public:
    int id;
    int capacity;
    static int counter;
    void store() {
        cout << "please enter class_id: ";
        cin >> id;
        cout << "please insert the capacity of this class:\n";
        cin >> capacity;
        counter++;
    }
    void showclassroom() {
        cout << "ID: " << id << "  capacity: " << capacity << endl;

    }
};
int pclassroom::counter = 0;

//temporary classrooms:
class tclassroom :public time_section
{
public:
    int id;
    int capacity;
    static int counter;
    void store() {
        cout << "please enter class_id: ";
        cin >> id;
        cout << "please insert the capacity of this class:\n";
        cin >> capacity;
        counter++;
    }
    void showclassroom() {
        cout << "ID: " << id << "  capacity: " << capacity << endl;

    }
};
int tclassroom::counter = 0;

//######################################################################################

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(void) {



    //permanent titles:
    int counter = 0;
    cout << "please enter number of permanent classes: ";
    cin >> counter;
    vector<C> myVector(counter);
    for (int i = 0; i < counter; i++)
    {
        myVector[i].store();
        for (int j = 0; j < i; j++)
        {
            int b = 0;
            b = myVector[i].c_s(myVector[j], i);
            if (b != -1)
            {
                i = b;
                break;
            }
        }
    }
    cout << "**********\n";

    //temporary titles:
    int number = 0;
    cout << "please enter number of temporary classes: ";
    cin >> number;
    vector<T> myvector(number);
    for (int i = 0; i < number; i++) {
        myvector[i].store();
        for (int j = 0; j < i; j++) {
            int b = myvector[i].c_s(myvector[j], i);
            if (b != -1) {
                i = b;
                break;
            }
        }
    }
    cout << "**********\n";

    //prmanent classrooms:
    int pcounter_classroom = 0;
    cout << "please enter number of phisical parmenent classes: ";
    cin >> pcounter_classroom;
    vector <pclassroom> proom(pcounter_classroom);
    for (int i = 0; i < pcounter_classroom; i++)
    {
        cout << "...\n";
        cout << "classroom number " << i + 1 << ": " << endl;
        proom[i].store();
    }
    cout << "**********\n";

    //temporary classrooms:
    int tcounter_classroom = 0;
    cout << "please enter number of phisical temporary classes: ";
    cin >> tcounter_classroom;
    vector <tclassroom> troom(tcounter_classroom);
    for (int i = 0; i < tcounter_classroom; i++)
    {
        cout << "...\n";
        cout << "classroom number " << i + 1 << ": " << endl;
        troom[i].store();
    }
    cout << "**********\n";



    //function for permanent classrooms:
    for (int i = 0; i < pcounter_classroom; i++)
    {
        for (int j = 0; j < counter; j++)
            if (proom[i].id == myVector[j].location_id)
            {
                for (int ii = 0; ii < 7; ii++)
                {
                    for (int jj = 0; jj < 8; jj++)
                    {
                        if (myVector[j].day_time[ii][jj] == 1)
                        {
                            proom[i].day_time[ii][jj] = myVector[j].idd;
                            myVector[j].check_room = 1;
                        }
                    }
                }
            }
    }

    //function for temporary function:
    for (int i = 0; i < tcounter_classroom; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (troom[i].id == myvector[j].location_id)
            {
                for (int a = 0; a < 16; a++)
                {
                    for (int ii = 0; ii < 7; ii++)
                    {
                        for (int jj = 0; jj < 8; jj++)
                        {
                            if (myvector[j].week[a][ii][jj] == 1)
                            {
                                troom[i].week[a][ii][jj] = myvector[j].idd;
                                myvector[j].check_room = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++
    //automatic function for permanent classroooms:
    for (int i = 0; i < pcounter_classroom; i++)
    {
        for (int ii = 0; ii < 7; ii++)
        {
            for (int jj = 0; jj < 8; jj++)
            {
                if (proom[i].day_time[ii][jj] == 0)
                {
                    for (int a = 0; a < counter; a++)
                    {
                        if (myVector[a].count <= proom[i].capacity)
                        {
                            if ((myVector[a].day_time[ii][jj] != 0) && (myVector[a].pcheck[ii][jj] == 0))
                            {
                                proom[i].day_time[ii][jj] = myVector[a].idd;
                                myVector[a].pcheck[ii][jj] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    //automatin function for temporary classroom:
    for (int i = 0; i < tcounter_classroom; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                for (int t = 0; t < 8; t++)
                {
                    if (troom[i].week[j][k][t] == 0)
                    {
                        for (int a = 0; a < number; a++)
                        {
                            if ((myvector[a].week[j][k][t] == 1) && (myvector[a].tcheck[j][k][t] == 0))
                            {
                                troom[i].week[j][k][t] = myvector[a].idd;
                                myvector[a].tcheck[j][k][t] = 1;
                            }
                        }
                    }
                }
            }
        }
    }





    //show time_tables of each classroom:
    //parmenent classrooms:

    string day[7] = { "saturday ", " sunday  ", " monday  ", " tuesday ", "wednesday", "thursday "," friday  " };
    string clock[8] = { "(8)", "(9)", "(10)", "(11)", "(14)", "(15)", "(16)","(17)" };

    cout << "schedule of permanent classrooms:" << endl;
    for (int i = 0; i < pcounter_classroom; i++) {
        cout << "ID: " << proom[i].id << endl;

        cout << "                ";
        for (int ip = 0; ip < 8; ip++)
            cout << clock[ip] << "\t";
        cout << endl;
        for (int ii = 0; ii < 7; ii++)
        {
            cout << day[ii] << "\t";
            for (int jj = 0; jj < 8; jj++)
            {
                cout << proom[i].day_time[ii][jj] << "\t";
            }
            cout << endl;
        }
        cout << "###" << endl;
    }

    //temporary classrooms:

    cout << "***\nschedule of temporary classrooms:\n\n" << endl;
    for (int a = 0; a < tcounter_classroom; a++)
    {
        cout << " ->classroom with ID: " << troom[a].id << endl;
        for (int i = 0; i < 16; i++)
        {
            cout << "\n                                         <<week: " << i << ">>" << endl;
            //
            cout << "                ";
            for (int ip = 0; ip < 8; ip++)
                cout << clock[ip] << "\t";
            cout << endl;
            //
            for (int j = 0; j < 7; j++)
            {
                cout << day[j] << "\t";
                for (int k = 0; k < 8; k++)
                {
                    cout << troom[a].week[i][j][k] << "\t";
                }
                cout << endl;
            }
        }
    }



    //save doc file:
    string a, b;
    //parmenent classroom:
    a += "schedule of permanent classrooms:\n";
    for (int i = 0; i < pcounter_classroom; i++) {
        a += "ID: ";
        a += to_string(proom[i].id);
        a += "\n";

        a += "                ";
        for (int ip = 0; ip < 8; ip++)
        {
            a += clock[ip];
            a += "\t";

        }

        a += "\n";
        for (int ii = 0; ii < 7; ii++)
        {
            a += day[ii];
            a += "\t";
            for (int jj = 0; jj < 8; jj++)
            {
                a += to_string(proom[i].day_time[ii][jj]);
                a += "\t";
            }
            a += "\n";
        }
        a += "###\n";
    }

    //temporary classrooms:

    a += "***\nschedule of temporary classrooms:\n\n\n";
    for (int a = 0; a < tcounter_classroom; a++)
    {
        cout << " ->classroom with ID: " << troom[a].id << endl;
        b += " ->classroom with ID: ";
        b += to_string(troom[a].id);
        b += "\n";

        for (int i = 0; i < 16; i++)
        {
            b += "\n                                         <<week: ";
            b += to_string(i);
            b += ">>\n";
            //
            b += "                ";
            for (int ip = 0; ip < 8; ip++)
            {
                b += clock[ip];
                b += "\t";
            }
            b += "\n";
            //
            for (int j = 0; j < 7; j++)
            {
                b += day[j];
                b += "\t";
                for (int k = 0; k < 8; k++)
                {
                    b += to_string(troom[a].week[i][j][k]);
                    b += "\t";
                }
                b += "\n";
            }
        }
    }

    ofstream file_open("schedule.txt");
    if (!file_open)
    {
        cout << "can not open the file;";
        return 0;
    }
    file_open << a;
    file_open << b;
    file_open.close();



    return 0;
}
