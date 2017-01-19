//Deandre Hall - 1241692

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

struct dijk{
	string origin = "@";
	int distFromOrigin = 0;
	bool finished = false;
};

struct student{
	string name;
	int score;
};

struct city{
	string cityName;
	vector<student> students;
};

struct info{
	bool edge = false;
	int dist=0;
};

bool inArray(vector<string> temp, string dummy);
int vecPosition(vector<string> temp, string dummy);
void print(vector<vector<info>> adjList);
void setConnections(vector<vector<info>> &adjList, vector<string> temp, string filesnames[3]);
void setCities(vector<city> &cityVec, vector<string> cities, string filenames[3]);
void shortPath(vector<city> cityVec, vector<vector<info>> adjList, vector<string> uniqueCities, string filenames[3]);

int main(int argc, char* argv[]){
	fstream citiesFile;
	string filename;
	string cities;
	string dest;
	string people;
	string tempstring;
	
	//"city=cities_input.txt;people=student_input.txt;visit=destinations_input.txt"
	
	tempstring = argv[1];
	
	size_t pos1 = tempstring.find("city=");
	size_t pos2 = tempstring.find(";");
	cities = tempstring.substr(pos1 + 5, (pos2 - pos1 - 5));
	cout<<"cities="<<cities<<endl;
	citiesFile.open(cities);
	tempstring = tempstring.substr(pos2 + 1);
	
	pos1 = tempstring.find("people=");
	pos2 = tempstring.find(";");
	people = tempstring.substr(pos1 + 7, (pos2 - pos1 - 7));
	cout<<"people="<<people<<endl;
	tempstring = tempstring.substr(pos2 + 1);
	
	pos1 = tempstring.find("visit=");
	pos2 = tempstring.find(";");
	dest = tempstring.substr(pos1 + 6, (pos2 - pos1 - 6));
	cout<<"dest="<<dest<<endl;
	tempstring = tempstring.substr(pos2 + 1);
	
	string filenames[3];
	filenames[0] = cities;
	filenames[1] = people;
	filenames[2] = dest;
	
	string city1, city2, dummy;
	string lastCity1 = "";
	string lastCity2 = "";
	int distance=0;
	int numCity1=0;
	int numCity2=0;
	
	vector<string> uniqueCities;
	int numUnique = 0;
	
	while(getline(citiesFile, dummy)){
		istringstream input(dummy);
		
		if(dummy[0]!='#'){
			input>>city1>>city2>>distance;
			
			if( !inArray(uniqueCities, city1) ){
				uniqueCities.push_back(city1);
				numUnique++;
			}
			if( !inArray(uniqueCities, city2) ){
				uniqueCities.push_back(city2);
				numUnique++;
			}
			
		}
	}
	
	citiesFile.close();
	
	cout<<"num unique cities: "<<numUnique<<endl<<endl;
	
	for(int i = 0; i<numUnique; i++){
		cout<<uniqueCities[i]<<endl;
	}
	
	vector< vector<info> > cons;
	vector<city> cityVec;
	
	cons.resize(numUnique, vector<info>(numUnique));
	setConnections(cons, uniqueCities, filenames);
	setCities(cityVec, uniqueCities, filenames);
	shortPath(cityVec, cons, uniqueCities, filenames);
	print(cons);
	
	return 0;
}

bool inArray(vector<string> temp, string dummy){
	
	for(int i = 0; i<temp.size(); i++){
		if(dummy == temp[i]) return true;
	}
	return false;
}

bool inArray(vector<city> temp, string dummy){
	
	for(int i = 0; i<temp.size(); i++){
		if(dummy == temp[i].cityName) return true;
	}
	return false;
}

int vecPosition(vector<string> temp, string dummy){
	
	for(int i = 0; i<temp.size(); i++){
		if(dummy == temp[i]) return i;
	}
	
	return -1;
}

int vecPosition(vector<city> temp, string dummy){
	
	for(int i = 0; i<temp.size(); i++){
		if(dummy == temp[i].cityName) return i;
	}
	
	return -1;
}

string retCity(vector<string> temp, int city){
	
	for(int i = 0; i<temp.size(); i++){
		if(i == city) return temp[i];
	}
	
	return "@";
}

void print(vector<vector<info>> adjList){
	
	for(int y = 0; y<adjList.size(); y++){
		
		for(int x = 0; x<adjList.size(); x++){
			if(adjList[y][x].edge == false) cout<<"x";
			else if(adjList[y][x].edge == true) cout<<"o";
		}
		cout<<endl;
	}
	
}

void setConnections(vector<vector<info>> &adjList, vector<string> temp, string filenames[3]){
	
	fstream file;
	file.open(filenames[0]);
	string dummy = "";
	string city1 = "";
	string city2 = "";
	int distance = 0;
	int city1pos = 0;
	int city2pos = 0;
	
	while(getline(file, dummy)){
		istringstream input(dummy);
		if(dummy[0]!='#'){
			input>>city1>>city2>>distance;
			city1pos = vecPosition(temp, city1);
			city2pos = vecPosition(temp, city2);
			adjList[city1pos][city2pos].edge = true;
			adjList[city1pos][city2pos].dist = distance;
		}
	}
	file.close();
}

void setCities(vector<city> &cityVec, vector<string> cities, string filenames[3]){
	fstream file;
	file.open(filenames[1]);
	string dummy = "";
	string cityname = "";
	string name = "";
	int score = 0;
	int cityPos = 0;
	int size = 0;
	
	student tempStu;
	city test;
	
	while(getline(file, dummy)){
		istringstream input(dummy);
		if(dummy[0]!='#'){
			input>>score>>name>>cityname;
			//cout<<score<<'\t'<<name<<'\t'<<cityname<<endl;
			if(inArray(cityVec,cityname)){
				cityPos = vecPosition(cityVec, cityname);
				tempStu.name = name;
				tempStu.score = score;
				cityVec[cityPos].students.push_back(tempStu);
			}
			else if(!inArray(cityVec, cityname)){
				tempStu.name = name;
				tempStu.score = score;
				cityVec.resize(cityVec.size()+1);
				int size = cityVec.size()-1;
				cityVec[size].students.push_back(tempStu);
				cityVec[size].cityName = cityname;
			}
		}
	}
	
	file.close();
	
}

void retStudent(vector<city> &cityVec, string city){
	int maxScore = -1;
	int pos1;
	int pos2;
	for(int i = 0; i<cityVec.size(); i++){
		if(cityVec[i].cityName == city){
			pos1 = i;
			for(int k = 0; k<cityVec.size(); k++){
				if(cityVec[pos1].students[k].score > maxScore){
					pos2 = k;
					maxScore = cityVec[pos1].students[k].score;
				}
			}
		}
	}
	
	//cityVec[pos1].students[pos2].score = -1;
	cout<<cityVec[pos1].students[pos2].name<<endl;
	
}

bool dijkstras(vector<vector<info>> adjList, vector<string> cityNames, vector<vector<dijk>> &temp, int city,int &last){ //set city to 0???
	static int n = adjList.size();
	static vector<bool>visited(n, false);
	static int min = 1<<30;
	bool flag = false;
	int minPos = 0;
	
	visited[city] = true;
	
	for(int i = 0; i<n; i++){
		if(adjList[city][i].edge == true){
			if(adjList[city][i].dist<temp[city][i].distFromOrigin){
				temp[city][i].distFromOrigin = adjList[city][i].dist;
				temp[city][i].origin = retCity(cityNames,i);
				if(temp[city][i].distFromOrigin < min){
					min = temp[city][i].distFromOrigin;
					minPos = i;
				}
				
			}
			
		}
		
	}
	
	if(adjList[city][minPos].edge == true && !visited[minPos]){
		flag = dijkstras(adjList, cityNames, temp, minPos, last);
		if(flag) return true;
	}
	
	last = city;
	return false;
	
}

bool dfs(vector<vector<info>> adjList, int city1, int city2, vector<bool> &visited){
	//bool flag = false;
	int n = adjList.size();
	int cur;
	bool flag = false;
	
	if(city1 == city2) return true;
	
	//deque <bool> queue;
	visited[city1] = true;

	
	for(int i = 0; i<n; i++){
		if(adjList[city1][i].edge==true){
			cur = i;
		}
		
		if(cur == city2) return true;
		if(adjList[city1][i].edge && !visited[i]){
			//visited[i]=true;
			
		flag = dfs(adjList, cur, city2, visited);
		}
		if(flag) return true;
	}
	
	return false;
}

void printStudents(vector<dijk> table, vector<city> cityVec, vector<string> cityNames, int source, int target){
	
	string z = cityNames[source];
	int newTarget = target;
	deque<string> queue;
	string dummy = "";
	queue.push_back(cityNames[target]);
	cout<<"city target:"<<cityNames[target]<<endl;
	cout<<"city source:"<<cityNames[source]<<endl;
	
	while(z!=cityNames[source]){
		z = table[newTarget].origin;
		queue.push_back(z);
		newTarget = vecPosition(cityNames,z);
	}
	
	while(!queue.empty()){
		dummy = queue.back();
		cout<<"student:"<<dummy<<endl;
		//retStudent(cityVec,dummy);
		queue.pop_back();
	}
	
}


void validPath(vector<vector<info>> temp, int a, int b, vector<string> cityNames, vector<dijk> &table, vector<city>cityVec){
	int n = temp.size();
	bool valid = false;
	vector<bool> visited(n, false);
	int dist = 0;
	int last = 0;
	
	vector<vector<dijk>> ok;
	ok.resize(n,vector<dijk>(n));
	
	for(int i = 0; i<n; i++){
		for(int k = 0; k<n; k++){
			ok[i][k].distFromOrigin = 1<<30;
			ok[i][k].finished = false;
		}
	}
	
	dijkstras(temp, cityNames, ok, a, last);
	
	for(int i = 0; i<n; i++){
		table[i] = ok[last][i];
	}
	
	printStudents(table, cityVec, cityNames, a, b);
	
	//valid = dfs(temp, a, b, visited);
	//if(valid) return true;
	//else return false;
	
}


void shortPath(vector<city> cityVec, vector<vector<info>> adjList, vector<string> uniqueCities, string filenames[3]){
	int big = 1 << 30;
	string dummy = "";
	string city1 = "";
	string city2 = "";
	int a = 0;
	int b = 0;
	int n = adjList.size();
//	vector<bool>visited(n, false);
	deque <int> queue;
	vector<string>xo;
	vector<dijk>table(n);
	fstream file;
	file.open(filenames[2]);
	while(getline(file, dummy)){
		istringstream input(dummy);
		if(dummy[0]!='#'){
			
			input>>city1>>city2;
			a = vecPosition(uniqueCities, city1);
			b = vecPosition(uniqueCities, city2);

			int path = 0;
			int cur = 0;
			int vfound = 0;
			bool found = false;
			int dist = 0;
			vector<bool>visited(n, false);
			vector<int>distance(n);
			
			cout<<city1<<":"<<a<<'\t'<<city2<<":"<<b<<endl;
			//dfs(adjList, a, b, visited, queue);
			validPath(adjList,a,b,uniqueCities,table,cityVec);
			//deque <int> queue;
			
			queue.push_back(a);
			visited[a] = true;
			//dist+=adjList[a][b].dist;
		
		//	cout<<"visited "<<uniqueCities[a]<<endl;
			
			while(!queue.empty()){
				a = queue.front();
				//if(validPath(adjList,a,b,uniqueCities,table)){
				//	xo.push_back(retCity(uniqueCities, a));
				//}
				//dist+=adjList[a][b].dist;	
				queue.pop_front();
				
				for(int i = 0; i<n; i++){
					
						if(adjList[a][i].edge == true){
							if(visited[i] == false){
								
								if(uniqueCities[i] == city2){
									xo.push_back(retCity(uniqueCities, i));
									dist+=adjList[a][i].dist;
									visited[i] = true;
									//cout<<"visited "<<retCity(uniqueCities,a)<<endl;
									//cout<<"test"<<endl;
									for(int q = 0; q<xo.size(); q++){
										//cout<<xo[q]<<endl;
									}
									//cout<<"end test"<<endl;
									vfound = i;
									found = true;
									//cout<<"found "<<retCity(uniqueCities, i)<<" distance= "<<dist<<" from "<<retCity(uniqueCities,a)<<endl;
									//break;
									
								}
								//dist+=adjList[a][i].dist;
								visited[i] = true;
								//cout<<"visited "<<uniqueCities[i]<<endl;
								queue.push_back(i);
							}
						}
					
				}
				
			}
			
			
			
			
			
			/*
			for(int i = 0; i < n; i++){
				distance[i] = big;
			}
			distance[a] = 0;
			//visited[a] = true;
			
			for(int i = 0; i < n; i++){
				int cur = -1;
				for(int k = 0; k < n; k++){
					if(visited[k]) continue;
					if( cur == -1 || distance[k] < distance[cur]){
						cur = k;	
					}
				}
				
				visited[cur] = true;
				//cout<<"current city = "<<uniqueCities[cur]<<endl;
				for(int k = 0; k < n; k++){
					if(adjList[cur][k].edge == true) path = distance[cur] + adjList[cur][k].dist;
					if(adjList[cur][k].dist != 0) cout<<adjList[cur][k].dist<<endl;
					if ( path < distance[k]){
						distance[k] = path;
					}
				}
			
			}
			
			cout<<uniqueCities[a]<<" distance from "<<uniqueCities[b]<<": "<<distance[b]<<endl;
			
			for(int i = 0; i<n; i++){
				cout<<distance[i]<<endl;
			}
			
			for(int i = 0; i<n; i++){
				if(visited[i] == true){
					cout<<uniqueCities[i]<<endl;
				}
			}
			*/
		}
	}
	

}
