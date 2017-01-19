
#include <iostream>

using namespace std;

int main()
{
	//Initialize an enum with the values NORTH, SOUTH, EAST, WEST, QUIT.
	enum Direction {N=1,S=2,E=3,W=4,Quit=5,Reset=6};
	//Initialize variables
	int travelDirection;
	int x=0,y=0;
 

    do
    {
        reset:
        cout<<"Which direction do you want to travel? \n"
            <<"(N=1, S=2, E=3, W=4, Quit=5, Reset=6) "<<endl;
        cin>>travelDirection;
        cout<<endl;
        
        /*
        switch(travelDirection)
        {
             case N: cout<<"You move north one unit.";y++;break;
             case S: cout<<"You move south one unit.";y--;break;
             case E: cout<<"You move east one unit.";x++;break;
             case W: cout<<"You move west one unit.";x--;break;
             case Quit: break;
             case Reset: x=y=0; break;          
             default: cout<<"That is not a valid choice."<<endl;                 
        }
        */
        
        if (travelDirection==N) {cout<<"You move north one unit."<<endl;y++;}
        else if (travelDirection==S) {cout<<"You move south one unit."<<endl;y--;}
        else if (travelDirection==E) {cout<<"You move east one unit."<<endl;x++;}
        else if (travelDirection==W) {cout<<"You move west one unit."<<endl;x--;}
        else if (travelDirection==Quit) {break;}
        else if (travelDirection==Reset) {x=y=0;}
        else cout<<"That is not a valid choice."<<endl;   
        
        cout<<"You are at: ("<<x<<","<<y<<")"<<endl<<endl;
        
    } while (travelDirection != Quit);
    
    cout<<"Your final destination is: "<<x<<","<<y<<endl;
    
    cin.get();
    return 0;   
}
