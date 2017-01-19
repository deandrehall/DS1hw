#include <iostream>

using namespace std;

int main()
{
    //enum direction {N=1, S, E, W, Q,R};
    bool quit= false;
    int travelDirection=0, x=0,y=0;
    
    cout<<"Which direction do you want to travel? \n"
            <<"(North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;
        
        while (!quit) {
              if( travelDirection==1){
                  cout<<"North"<<endl<<endl;y++;
                  cout<<"You are at: ("<<x<<","<<y<<")"<<endl<<endl;
                  cout<<"Which direction do you want to travel? "<<endl;
                  cout<<" (North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;}
                  else if (travelDirection==2){
                  cout<<"South"<<endl<<endl;y--;
                  cout<<"You are at: ("<<x<<","<<y<<")"<<endl<<endl;
                  cout<<"Which direction do you want to travel? "<<endl;
                  cout<<" (North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;}
                  else if (travelDirection==3){
                  cout<<"East"<<endl<<endl;x++;
                  cout<<"You are at: ("<<x<<","<<y<<")"<<endl<<endl;
                  cout<<"Which direction do you want to travel? "<<endl;
                  cout<<" (North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;}
                  else if (travelDirection==4){
                  cout<<"West"<<endl<<endl;x--;
                  cout<<"You are at: ("<<x<<","<<y<<")"<<endl<<endl;
                  cout<<"Which direction do you want to travel? "<<endl;
                  cout<<" (North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;}
                  else if (travelDirection==5){
                  cout<<"Quit"<<endl<<endl;}
                  else if (travelDirection==6){
                  cout<<"Reset"<<endl<<endl;x=y=0;
                  cout<<"You are at: ("<<x<<","<<y<<")"<<endl<<endl;
                  cout<<"Which direction do you want to travel? "<<endl;
                  cout<<" (North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;}
                  else {
                  cout<<"Not a valid option. Try again."<<endl<<endl;
                  cout<<"Which direction do you want to travel? "<<endl;
                  cout<<" (North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;}
                  
                  if(travelDirection==5) quit=true;
                  
                  
    
	//Initialize an enum with the values NORTH, SOUTH, EAST, WEST, QUIT.
	//Initialize variables

   /* do
    {
        cout<<"Which direction do you want to travel? \n"
            <<" (North=1, South=2, East=3, West=4, Quit=5, Reset=6) "<<endl<<endl;
        cin>>travelDirection;
        
        //instead of switch case
        
        switch(travelDirection)
        {
              case N: case 'n': cout<<"North"<<endl<<endl;y++;break;
              case S: case 's': cout<<"South"<<endl<<endl; y--; break;
              case E: case 'e': cout<<"East"<<endl<<endl; x++; break;
              case W: case 'w': cout<<"West"<<endl<<endl; x--; break; 
              case Q: case 'q': cout<<"Quit"<<endl<<endl; break;
              case R: case 'r': cout<<"Reset"<<endl<<endl; x=y=0; break;         
             //Write code to increment or decrement x and y based on the direction
             default: cout<<"Not a valid option. Try again."<<endl;                 
        }
        cout<<"You are at: ("<<x<<","<<y<<")"<<endl<<endl;
        
    } while (travelDirection != Q);
    */
}
    cout<<"Your final destination is: ("<<x<<","<<y<<")"<<endl;
    
    cin.get();
    return 0;   
}
