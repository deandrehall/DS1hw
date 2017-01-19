#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    char name[25], address[25];
	int item, quantity, i;
	double price;
	const int SIZE = 6;
	int VALID_ITEM [SIZE] =          {106, 108, 307, 405, 457, 688};
	double VALID_ITEM_PRICE [SIZE] = {0.59, 0.99, 4.50, 15.99, 17.50, 39.00};
	bool foundIt = false;
	string MSG_YES = "\n\nItem available\n\n", MSG_NO = "\n\nItem not found\n";

    cout<<"Enter name: ";
	cin.get( name, 24);
	cin.ignore();
	cout<<endl;
	
	cout<<"Enter address: ";
	cin.get(address, 24);
	cin.ignore(1);
	cout<<endl;
	
	cout <<"Enter item to buy {106, 108, 307, 405, 457, 688}: ";
	cin>>item;
	cout<<"Enter quantity to buy: ";
	cin>>quantity;

	i = 0;
	while (i < SIZE)
	{
		if (item == *(VALID_ITEM+i))
		{
			foundIt = true;
			price = *(VALID_ITEM_PRICE+i);
		}

		i = i + 1;
	}

	if (foundIt == true)
	{
		cout<< MSG_YES;
		cout<<quantity<<" at "<< price <<" each"<<endl;
		double cost = quantity * price;
		cout<< "Total Cost $"<< cost<<endl;
	}
	else
		cout<< MSG_NO;

    system("pause");
    return 0;
}
