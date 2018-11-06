/* 
使用循环结构打印下述图形，打印行数n由用户输入。图中每行事实上包括两部分，
中间间隔空格字符数m也由用户输入。
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i,j,n,m;
    cout << "请输入打印的行数：";
    cin >> n;
    cout << "请输入中间间隔空格字符数：";
    cin >> m;

    for(i=1;i<=n;++i)
    {   
        for(j=0;j<=n-i;j++){
            cout << " ";
        }
        for(j=0;j<(2*i-1);j++){
            cout << "*";
        }
        for(j=0;j<m;j++){
            cout << " ";
        }
        for(j=0;j<(2*n-2*i+1);j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}



/*不能得到理想的效果
#include <iostream>
using namespace std;
int main()
{
    int i=1,j=0;
    for(i;i<=5;i++)
    {
        for(j;j<2*i;++j)
        {
            cout << "*";
        }
        cout << endl;
    }    
    return 0;
}
*/