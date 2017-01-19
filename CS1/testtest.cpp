// 1410
// Program 1
//Student: Muneer Khan
// TA:  Mr. Tzu-Hua Liu
// Date: 2/6/2015


#include <iostream>
#include <iomanip>
#include <ostream>

using namespace std;

int main()
{
    
    double electricity,gas;
    cout << "Electricity bill is?" <<endl;
    cin >> electricity;
    
    cout << "Gas bill is?" <<endl;
     cin >> gas;
    
    int rent,internet;
    rent=1200.00;
    internet=50.00;
    
    

    cout << " Bill Name:""      Amount""            Who Pays" <<endl;
    cout << "-------------------------------------------" <<endl;
    
    cout << " Rent " << setw(11) << "$"<< rent << setw(17);
    cout << "Moe" << endl;
    cout << " Internet " << setw(7)<< "$" << internet <<setw(21);
    cout << "Curly" <<endl;
    cout << " Electricity " <<setw(4) << "$"<< electricity <<setw(21);
    cout << "Larry" <<endl;
    cout << " Gas " << setw(12)<< "$" << gas<< setw(21);
    cout << "Larry" <<endl;
    
    cout<< endl;
    
    
    double total;
    total= rent+internet+electricity+gas;
    
    cout <<" Total Bills " <<setw(4) << "$" << total;
    cout << endl;
    
    double share;
    share=total/3;
    
    cout<<" Each Share " <<setw(5) << "$" << share;
    cout << endl;
    
    cout << endl;
    
    cout << " Who:""            Pays Moe" <<setw(18)<<endl;
    cout << "-------------------------------------------" <<endl;
    
    
    
    
    double larry,curly;
    larry=share-(electricity+gas);
    
    cout << setw(5)<< " Larry " <<setw(10)<<"$" << larry;
    cout <<endl;
    
    curly=share-internet;
    
    cout <<" Curly " <<setw(10) << "$" <<curly;
    cout << endl;
    
    
 
    return 0;
}
