//Deandre Hall - 1241692
//1410 COSC [T/Th 11:30-1] lab TA: Chris Devito

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

struct product{
	double price;
	int weight;
};

double totalPrice(product& pr){
	double total = 0.0;
	total=pr.price*pr.weight;
	return total;
}

int main(){

product celery;

celery.price=2.99;
celery.weight = 2;
cout<<"total = "<<totalPrice(celery);
cout<<endl<<endl;



system("pause");
return 0;
}

