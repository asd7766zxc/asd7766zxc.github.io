#include <iostream>
using namespace std;
int main()
{
	
	cout << "二分搜尋法 帶原位置的那種 ㄟ嘿"<<endl;
	int n = 0 ; 
	cout <<"請輸入陣列個數:";
	cin >> n;
	int map[n][2]; // 儲存數對'0 -> 數值  1 -> 原位置 * 整理時附帶  
	cout << "請輸入各元素 >>" <<endl;
	for (int i =0 ; i < n ;i++)
	{
		cout<<"| map["<<i<<"][0]=";
		cin >> map[i][0] ;
		map[i][1] = i ;
		
	}
	cout << "原陣列     (數值,位置):";
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

	cout << "整理後陣列 (數值,位置):"; 
		for(int i = 0 ; i < n; i++)
	   cout << "("<<map[i][0]<<","<<map[i][1]<< ")";
	
	int key = 0; 
	cout <<endl<< "請輸入欲尋找ㄉ數字:";
	cin >> key;
	cout << endl;
	
	
	int left = 0;
	int right = n-1;
	int middle = (left + right ) / 2;
	
	while(true)
	{
		middle = (left + right ) / 2;
		if(key > map[middle][0])
		{
			left = middle;
		}
		else if ( key < map[middle][0])
		{
			right = middle;
		}
		if ( key == map[middle][0] )
		{
				
			int fpx = 0; //同時延伸數 
		//左右延伸數
			int lpx=1; 
			int rpx=1; 
			 	cout << "找到ㄌ (數值,整理後陣列位置,原陣列位置) >>"<<endl;
			 	
			for( ; rpx + middle < n &&   middle-lpx > -1 ; fpx++ ) // check if 那啥有重複 
			{
				if(key != map[middle+rpx ][0] && key!=map[ middle-lpx][0] )
				{
					rpx--;
					lpx--;
					break;
				}
				if(fpx != 0 )
				{
				
				
					if (key == map[middle +rpx][0] ) 
					{
						cout << "("<<map[middle+rpx][0]<<","<<middle+rpx<<","<<map[middle+rpx][1]<<")"<<endl;
						rpx++;
					}
					if (key == map[middle -lpx][0] )
					{
						cout << "("<<map[middle+lpx][0]<<","<<middle+lpx<<","<<map[middle+lpx][1]<<")"<<endl;
						 lpx++;
					}	
				}
				else 
				{
					cout << "("<<map[middle][0]<<","<<middle<<","<<map[middle][1]<<")"<<endl;
				}
			
		   }
		   //將判斷數分成左右的原因為 fpx = 左界|lpx  middle rpx    |右界 因此 在排列後的陣列中 可以輕易ㄉ找出連續的結果  
		  
	
		   
			middle = -1;
			break;
		}	 	
		else if(key == map[right][0])
		{
		
			cout << "找到ㄌ 在整理後陣列ㄉ " << right <<" 且在原陣列ㄉ "<< map[right][1];
			middle = -1;
			break;
		}	 
		else if( middle == (left + right ) / 2 )
		break;
	}
	cout <<endl;
	if( 	middle == (left + right ) / 2 )
	cout << "哭阿 找不到";

 } 

