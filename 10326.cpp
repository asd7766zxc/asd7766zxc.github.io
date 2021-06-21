#include <iostream>
using namespace std;
int main()
{
	cout << "Binary Search"<<endl;
	int n = 0 ; 
	cout <<"plz input elements count:";
	cin >> n;
	int map[n][2]; 
	cout << "plz input element >>" <<endl;
	for (int i =0 ; i < n ;i++)
	{
		cout<<"| map["<<i<<"][0]=";
		cin >> map[i][0] ;
		map[i][1] = i ;
		
	}
	cout << "Original Array    (value,index):";
	for(int i = 0 ; i < n; i++)
	   cout << "("<<map[i][0]<<","<<map[i][1]<< ")";
	cout << endl;
	
	int value = 0; 
	int pos = 0 ; 
	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 0 ; j < n-1;j++)
		{
			if(map[j][0] > map[j+1][0])
			{
				value = map[j][0];
				pos = map[j][1];
				
				map[j][0] = map[j+1][0];
				map[j][1] = map[j+1][1];
				
				map[j+1][0] = value;
				map[j+1][1] = pos; 
				
			}
		}
	}

	cout << "Array After Short (Value,Index):"; 
		for(int i = 0 ; i < n; i++)
	   cout << "("<<map[i][0]<<","<<map[i][1]<< ")";
	
	int key = 0; 
	cout <<endl<< "input value to search:";
	cin >> key;
	cout << endl;
	
	
	int left = 0;
	int right = n-1;
	int middle = (left + right ) / 2;
	
	while(left <= right)
	{
		middle = (left + right ) / 2;
		
		if ( key == map[middle][0] )
		{
			int fpx = 0; 
		
			int lpx=1; 
			int rpx=1; 
			 	cout << "Found (Value,Short Index,Original Index) >>"<<endl;
			 	cout << "("<<map[middle][0]<<","<<middle<<","<<map[middle][1]<<")"<<endl;
			   while(lpx !=-2 ||rpx!=-2)
			   {
			   	if(middle-lpx >=0)
			   	  if(map[middle-lpx][0] == key) 
			   	  {
					 	cout << "("<<map[middle-lpx][0]<<","<<middle-lpx<<","<<map[middle-lpx][1]<<")"<<endl;
			   	  	lpx++;
			   	  }
				  else
				     lpx = -2;
				     
				if(middle+rpx >=0)
			   	  if(map[middle+rpx][0] == key) 
			   	  {
						cout << "("<<map[middle+rpx][0]<<","<<middle+rpx<<","<<map[middle+rpx][1]<<")"<<endl;	 
			   	  	rpx++;
			   	  }
				  else
				     rpx = -2;
			       
			   }
			middle = -1;
			break;
		}	 
		else if(key > map[middle][0])
		{
			left = middle+1;
		}
		else if ( key < map[middle][0])
		{
			right = middle-1;
		}	
	
	}
	cout <<endl;
	if( middle == (left + right ) / 2 )
	cout << "Cannot Found";
 } 

