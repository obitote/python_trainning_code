//优化：将打印的第二行空出第一个空
/*
打印日历
Calendar 2016-01
--------------------------
Su  Mo  Tu  We  Th  Fr  Sa
--------------------------
                     1   2
 3   4   5   6   7   8   9
10  11  12  13  14  15  16
17  18  19  20  21  22  23
24  25  26  27  28  29  30
31
--------------------------
*/
#include <iostream>
#include <iomanip>
using namespace std;
typedef enum {SUN=1,MON,TUE,WEN,THU,FRI,SAT} WEEK;
    
int main(){
    int i,day;
    const WEEK date_1=FRI;
    
    cout << "Calendar 2006-01" << endl;
    cout << "--------------------------" << endl;
    cout << "Su  Mo  Tu  We  Th  Fr  Sa" << endl;
    cout << "--------------------------" << endl;
    cout << setw(22);

    for(i=1;i<=31;i++){
        day=(i+int(date_1))%7;
        if(day==1){
            cout << i;
            cout << endl;
        }
        else
            cout << i << setw(4);
    }
    cout << endl;
    cout << "--------------------------" << endl;
}

