#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

class DoubleLinked
{
private:

	struct node
	{
		long long digits;
		char digit;
		string number;
		node *next;
		node *prev;
	};

	node *head;
	node *tail;
	int count;


public:




	DoubleLinked()
	{ head = NULL; tail = NULL; count = 0;  }

	~DoubleLinked();

	void appendR(string);
	void display() const;
	void displayString() const;
	void destroyList();
	void reverseDisplay() const;
	int getDigit(int) const;
	int getCount() const;
	void append(long long);
	void appendS(char);
	char getStr(int);
	void appendString(string);
	string getString(int);
	
};



int main()
{
	ifstream count;
	char word[10];
	string wordC[10];
	int wordCounter = 0;
	int counter = 0;
	int counts = 0;
	int count1;
	int count2;
	long long total = 0;
	int carry = 0;
	int zeros = 0;
	int strSize1 = 0;
	int strSize2 = 0;
	int strSize3 = 0;
	char ch = ' ';
	int index = 0;
	int nums1, nums2;
	string fileName;
	string str2;
	int digits;
	bool flag = false;
	bool flagC = false;
	bool Zflag1 = false;
	bool Zflag2= false;
	bool skip = true;
	DoubleLinked num1, num2, result, numM;
	string operation;
	string opSymbol;
	string whole1;
	string whole2;
	string whole3;
	string input;
	string line;
	string totalS;
	string total1;
	/*
	fileName = argv[1];	// sending filename to string
	str2 = fileName.substr(9); // getting rid of filename=
	str2.c_str()
	*/
	
	//string filename;
	//string tok1,tok2,str2;

	//fileName = argv[1];	// sending filename to string
	//str2 = fileName.substr(6); // getting rid of input=
	//cout<<str2<<endl;
	//cout<<fileName<<endl;

	//size_t pos1 = fileName.find("input=");
	//size_t pos2 = fileName.find(";");
	//tok1=fileName.substr(pos1+6,pos2-6);
	//pos1=fileName.find("digitsPerNode=");
	//tok2=fileName.substr(pos1+14);



	//cin >> fileName;
	//cin >> digits;
	
	fileName="input1";

	count.open(fileName + ".txt");


	while(getline(count, line))	// while loop in order to read everything in the file
	{
		line = line + "\n";
		counts = 0;

		while(line[counts] != '\n')
		{
			ch = line[counts];


			if (ch == ' ') // Breaks the for loop in order to start over once it finds a space
			{
				counts++;
				ch = line[counts];
			}

			else if ((ch == '\n') || (ch == '\r')) //Breaks the for loop once the end of the string is reached
			{
				break;
			}



			if((isspace(ch)) || (ch == '+') || (ch == '*'))
			{
				if(ch == '+')
				{
					opSymbol = "+";
						flag = true;
					counts++;
					ch = line[counts];

					if (ch == ' ')
					{
						counts++;
						ch = line[counts];
					} 

					if((ch == '\n')  || (ch == '\r'))
					{
						break;
					}

				}

				if(ch == '*')
				{
					opSymbol = "*";
					flag = true;
					counts++;
					ch = line[counts];

					if (ch == ' ')
					{
						counts++;
						ch = line[counts];
					} 

					if((ch == '\n')  || (ch == '\r'))
					{
						break;
					}
				}
			}


			if((ch != ' ') || (ch != '+') || (ch != '*') || (ch != '\r'))
			{
				if(flag == false)
				{
					num1.appendS(ch);
				}

				else
					num2.appendS(ch);

			}
			counts++;
		}

		//================================================================== end of reading from line
		//================================================================== start of 
		counter = 0;
		count1 = num1.getCount(); 
		count2 = num2.getCount();
		whole1 = "";
		whole2 = "";

		if(opSymbol == "+")
		{
			if(count1 > count2)		
			{
				if((count1 == 3 && count2 == 2) && digits ==2 )
				{
					whole1 += '0';

					int ay = 0;
					ay = count2;

					for(ay; ay < 4; ay++)
					{
						whole2 += '0';
					}
				}

				else
				{
					zeros = count1 - count2;
					for(int ay = 0; ay < zeros; ay++)
					{
						whole2 += '0';
					}
				}
			}

			if( count2 > count1)	// Adds zeros in order to align the list if the second list is larger than the 1st.
			{

				if((count1 == 2 && count2 == 3) && digits == 2)
				{

					whole2 += '0';

					int ay = 0;
					ay = count2;

					for(ay; ay < 4; ay++)
					{
						whole1 += '0';
					}
				}

				else
				{
					zeros = count2 - count1;
					for(int ay = 0; ay < zeros; ay++)
					{
						whole1 += '0';
					}
				}
			}
		}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			while(count1 > counter)
			{
				whole1 += num1.getStr(counter);
				counter++;
			}

			counter = 0;
			while(count2 > counter)
			{
				whole2 += num2.getStr(counter);
				counter++;
			}
			counter = 0;

			num1.display();
			cout << opSymbol;
			num2.display();

			num1.destroyList();
			num2.destroyList();
			index = 0;
			whole1 += '\n';
			whole2 += '\n';
			if(opSymbol == "*")
			{
				digits = 1;
			}

			for(int c = 0; c < 10; c++)
			{
				word[c] = ' ';
			}

			while( whole1[index] != '\n')
			{

				for(int ay = 0; ay < digits; ay++)
				{
					word[ay] = whole1[index];
					if(whole1[index] == '\n')
					{
						break;
					}
					index++;

				}

				for(int b = 0; b < digits; b++)
				{
					whole3 += word[b];

				}

				for(int b = 0; b < 10; b++)
				{
					word[b] = ' ';
				}


				num1.appendString(whole3);
				whole3 = "";
			}

			index = 0;

			while( whole2[index] != '\n')
			{

				for(int ay = 0; ay < digits; ay++)
				{
					word[ay] = whole2[index];
					if(whole2[index] == '\n')
					{
						break;
					}
					index++;

				}

				for(int b = 0; b < digits; b++)
				{
					whole3 += word[b];

				}

				for(int b = 0; b < 10; b++)
				{
					word[b] = ' ';
				}

				num2.appendString(whole3);
				whole3 = "";
			}
		

		if(opSymbol == "+") //=================================================================================////////   addition   ++++++
		{
			counter = 0;
			count1 = num1.getCount(); 
			count2 = num2.getCount(); 

			while(count1 > counter && count2 > counter)
			{

				whole1 = num1.getString(counter);
				whole2 = num2.getString(counter);

				nums1 = stoi(whole1);
				nums2 = stoi(whole2);

				strSize1 = whole1.size();
				strSize2 = whole2.size();


				if(strSize1 == strSize2 && nums1 == 0 && nums2 == 0)
				{
					result.appendR(whole1);
				}

				else if(digits == 1 || (nums1 <= 9 && nums2 <= 9))	///////////////////////// for one digit
				{

					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}

					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}

					if( total > 9)
					{
						carry = 1;
						total -= 10;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
						skip = false;
					}

					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;

				}

				else if(digits == 2  || (nums1 <= 99 && nums2 <= 99) ) ////////////////////////////////// for 2 digits 
				{

					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}
					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}

					if( total > 99)
					{
						carry = 1;
						total -= 100;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
					}

					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;

				}




				else if(digits == 3 || (nums1 <= 999 && nums2 <= 999) ) ///////////////////////////////////////////////////// for 3 digits
				{
					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}
					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}


					if(total > 999 )
					{
						carry = 1;
						total -= 1000;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
					}

					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;
				}

				else if(digits == 4  || (nums1 <= 9999 && nums2 <= 9999)) ////////////////////////////////////////////// for 4 digits
				{

					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}
					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}


					if(total > 99999)
					{
						carry = 1;
						total -= 1000;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
					}
					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;

				}



				else if(digits == 5  || (nums1 <= 99999 && nums2 <= 99999)) /////////////////////////////////////////// for 5 digits
				{
					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}
					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}


					if(total > 999999)
					{
						carry = 1;
						total -= 10000;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
					}

					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;
				}


				else if(digits == 6  || (nums1 <= 999999 && nums2 <= 999999)) ///////////////////////////////////////////////////////// for 6 digits
				{
					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}
					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}


					if(total > 9999999)
					{
						carry = 1;
						total -= 100000;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
					}

					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;


				}
				else if(digits == 7  || (nums1 <= 9999999 && nums2 <= 9999999)) ///////////////////////////////////////////////////////////////////////////////////////////for 6 digits
				{
					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}
					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}


					if(total > 99999999)
					{
						carry = 1;
						total -= 1000000;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
					}

					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;

				}

				else if(digits == 8  || (nums1 <= 99999999 && nums2 <= 99999999)) ////////////////////////////////////////////////////////////////////////// for 6 digits
				{
					if(flagC == true)
					{
						total = nums1 + nums2 + carry;
						flagC = false;
					}
					else
					{
						total = nums1 + nums2;
						totalS = to_string(static_cast<long long>(total));
					}


					if(total > 999999999)
					{
						carry = 1;
						total -= 10000000;
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
						flagC = true;
					}
					if(count1 - 1 != counter && strSize1 != strSize2)
					{
						strSize3 = totalS.size();

						if(digits != strSize3)
						{

							for(strSize3; strSize3 < digits; strSize3++)
							{
								whole3 += "0";
							}

							totalS = whole3 + totalS;
							result.appendR(totalS);
							skip = false;
						}
					}

					if(skip == true)
					{
						totalS = to_string(static_cast<long long>(total));
						result.appendR(totalS);
					}

					skip = true;

				}

				counter++;
			}




			if(flagC == true)															// Adds carry if any if left
			{
				totalS = to_string(static_cast<long long>(carry));;
				result.appendR(totalS);
				flagC = false;
			}



		}


		if (opSymbol == "*")//////////////////////////////////////////////////////////////////////////// Multiplication ******************************
		{
			counter = 0;
			count1 = num1.getCount(); 
			count2 = num2.getCount(); 

			if(count1 >= count2)
			{
				for(int a = 0; a < count2; a++)
				{
					double counterss = a;
					double shift2 = pow(10.0,a);
					whole2 = num2.getString(a);
					nums2 = stoi(whole2);
					for(int b = 0; b < count1; b++)
					{
						double counterss = b;
						double shift1 = pow(10.0,b);
						whole1 = num1.getString(b);
						nums1 = stoi(whole1);
						total += ((nums1 * shift1) * (nums2 * shift2));
						flagC = false;

					}
					
					//numM.appendString(totalS);
					//total = 0;
				}
totalS = to_string(static_cast<long long>(total));
total = 0;
			}


			if(count2 > count1)
			{
				for(int a = 0; a < count1; a++)
				{
					double counterss = a;
					double shift2 = pow(10.0,a);
					whole1 = num1.getString(a);
					nums1 = stoi(whole1);
					for(int b = 0; b < count2; b++)
					{
						double counterss = b;
						double shift1 = pow(10.0,b);
						whole2 = num2.getString(b);
						nums2 = stoi(whole2);
						total += ((nums1 * shift1) * (nums2 * shift2));
						flagC = false;

					}
					
					//numM.appendString(totalS);
					//total = 0;
				}
			}
totalS = to_string(static_cast<long long>(total));
total = 0;
		}






		cout << "=";
		if(opSymbol == "+")
		{
			//result.displayString();
		}
		else
		{
			cout << totalS;
			cout << endl;
		}
		cout << endl;
		num1.destroyList();
		num2.destroyList();
		numM.destroyList();
		result.destroyList();
		flag = false;




	}
	
	
	system("pause");
	return 0;
	}


void DoubleLinked::append(long long number)
{

	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->digits = number;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(!head)
	{
		head = newNode;
		tail = newNode;
		count++;
	}

	else 
	{
		nodePtr = head;

		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
		newNode->prev = nodePtr;
		tail = newNode;
		count++;
	}
}

void DoubleLinked::appendS(char number)
{

	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->digit = number;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(!head)
	{
		head = newNode;
		tail = newNode;
		count++;
	}

	else 
	{
		nodePtr = head;

		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
		newNode->prev = nodePtr;
		tail = newNode;
		count++;
	}
}

void DoubleLinked::appendR(string num)
{
	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->number = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(!head)
	{
		head = newNode;
		tail = newNode;
		count++;
	}

	else 
	{
		nodePtr = tail;

		while(nodePtr->prev)
		{
			nodePtr = nodePtr->prev;
		}

		nodePtr->prev = newNode;
		newNode->next = nodePtr;
		head = newNode;
		count++;
	}
}

DoubleLinked::~DoubleLinked()
{
	node *nodePtr;
	node *nextNode;

	nodePtr = head;

	while(nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void DoubleLinked::display() const
{
	node *nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		cout << nodePtr->digit;

		nodePtr = nodePtr->next;
	}
}

void DoubleLinked::destroyList()
{
	node *ptr;
	count = 0;
	while(head != NULL)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}

	tail = NULL;
}

void DoubleLinked::reverseDisplay() const
{
	node *nodePtr;

	nodePtr = tail;

	while(nodePtr != NULL)
	{
		cout << nodePtr->digits << endl;
		nodePtr = nodePtr->prev;
	}
}

int DoubleLinked::getDigit(int position) const
{
	node *nodePtr;

	nodePtr = tail;

	if(position == 0)
	{
		return nodePtr->digits;
	}

	if(position >= count)
	{
		return 0;
	}

	else
	{
		for(int a = 0; a < position; a++)
		{
			nodePtr = nodePtr->prev;
		}

		return nodePtr->digits;
	}
}

int DoubleLinked::getCount() const
{
	return count;
}

char DoubleLinked::getStr(int position)
{
	node *nodePtr;

	nodePtr = head;

	if(position == 0)
	{
		return nodePtr->digit;
	}

	if(position >= count)
	{
		return 0;
	}

	else
	{
		for(int a = 0; a < position; a++)
		{
			nodePtr = nodePtr->next;
		}

		return nodePtr->digit;
	}
}

void DoubleLinked::appendString(string num)
{

	node *newNode;
	node *nodePtr;

	newNode = new node;
	newNode->number = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(!head)
	{
		head = newNode;
		tail = newNode;
		count++;
	}

	else 
	{
		nodePtr = head;

		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
		newNode->prev = nodePtr;
		tail = newNode;
		count++;
	}
}

string DoubleLinked::getString(int position)
{
	node *nodePtr;

	nodePtr = tail;

	if(position == 0)
	{
		return nodePtr->number;
	}

	if(position >= count)
	{
		return 0;
	}

	else
	{
		for(int a = 0; a < position; a++)
		{
			nodePtr = nodePtr->prev;
		}

		return nodePtr->number;
	}
}

void DoubleLinked::displayString() const
{
	node *nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		cout << nodePtr->number << endl;

		nodePtr = nodePtr->next;
	}
}
