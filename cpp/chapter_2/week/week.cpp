/*
已知2006年12月1日为星期五。编写程序，接受用户输入的1—31之间的整数，按照下述格式将该日星期几信息打印在对应栏下。
例如，2006年12月1日打印在星期五'Fr'下面：
*/
#include <iostream>
#include <iomanip>

using namespace std;
typedef enum {SUN, MON, TUE, WED, THU, FRI, SAT} WEEKDAY;

int main(){
    int date;
    const WEEKDAY date_1 = FRI;
    WEEKDAY weekday;
    cout << "The program gets a date(1-31),\n";
    cout << "and prints a calendar of 2006-12(just the date).\n";
    cout << "The date:";
    cin >> date;

    if(date < 1 || date > 31){
        cout << "Date error!\n";
        return 1;
    }

    weekday = (WEEKDAY)((date + (int)date_1 -1) % 7);
    
    cout << "Calendar 2006-12\n";
    cout << "--------------------------\n";
    cout << "Su  Mo  Tu  We  Th  Fr  Sa\n";
    cout << "--------------------------\n";

    if (weekday == SUN)         cout << setw(2) << date;
    else if (weekday == MON)    cout << setw(6) << date;
    else if (weekday == TUE)    cout << setw(10) << date;
    else if (weekday == WED)    cout << setw(14) << date;
    else if (weekday == THU)    cout << setw(18) << date;
    else if (weekday == FRI)    cout << setw(22) << date;
    else                        cout << setw(26) << date;

    cout << endl << "--------------------------\n";
    return 0;
}
