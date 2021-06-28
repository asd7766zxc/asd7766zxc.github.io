#include<iostream>
#include <string>
#include <bits/stdc++.h>  //新增swap 函數 懶得寫了 
using namespace std;
void printslice(string text,int offset) //畫線很重要
{
	
	int length1 = 47+offset;
	int right = length1/4; 
	cout<< setfill('-')<<setw(length1/2)<<""; //(tab) (x7)
	cout <<text; //中文 (x2) 
	cout<< setfill('-')<<setw(length1/2)<<"";
}
int main()
{
	
	int subcount; 
	int pc;
	//輸入 
	cout <<"請輸入科目數:";
	cin >> subcount;
	cout <<endl<< "請輸入各個科目的名稱:";
	string subjects[subcount];
	for(int i =0; i < subcount ; i ++ )
	   cin>>subjects[i];
	int levelc;
	cout <<endl<<"請輸入等第切分數量:";
	cin >>levelc;
	cout << endl<<"請輸入等第和門檻分 格式為 [門檻(以上包含) 等第] > ";
	pair<int,string> levels[levelc];
	for(int i = 0 ;i < levelc; i++)
	{
		cin >> levels[i].first;
		cin >> levels[i].second; 
		
	}
	
	cout << endl<<"請輸入學生個數:";
	cin >> pc;
	float col[pc][subcount+4];
	for(int i = 0; i < pc ; i ++)
	{
		cout << "序列-"<<i<<" 座號:";
		cin >> col[i][0];
		for(int r = 0 ; r < subcount; r++ )
		{
			cout <<"座號 "<<col[i][0]<<"-"<< subjects[r]<<":";		
			cin >> col[i][r+1];
		}
		cout << endl;
	}
	//輸入
	 
	 //平均
	for(int i = 0 ; i < pc;i++)
	{
		float sum  = 0;
		for(int r = 1 ; r < subcount +1;r++)
		{
			if(col[i][r] >= 59 && col[i][r] < 60) col[i][r] ++; //加分 
		  sum+=col[i][r]; 
		  
		  
		}
		col[i][subcount+2] = sum;	
		col[i][subcount+1] = sum /subcount;
	}
	//平均
	
	//排序 主分數版
	if(pc!=1)
	for(int i = 0 ;i < pc;i++)
	{
		for(int r= 0 ; r < pc-i ;r++)
		{
			if(col[r][subcount+1] < col[r+1][subcount+1])
			{
			
				for(int j = 0; j < subcount +2;j++)
				 swap(col[r][j],col[r+1][j]);
		
			}
		}
	}
	//排序 等第
	if(levelc!=1)
	for(int i = 0 ;i < levelc;i++)
		for(int r= 0 ; r < levelc-i ;r++)
				if(levels[r].first < levels[r+1].first )
				  swap(levels[r],levels[r+1]);
				  
	cout<<endl<<endl << "--------------等第表------------"<<endl<<endl;				  
	for(int i = 0 ; i < levelc ; i ++)
	{
		cout << "\t"<<levels[i].first<<"\t"<<levels[i].second<<endl;
	}
	cout<<endl<<endl << "-------------******-------------"<<endl<<endl;
    string output;
	//排序
	output+= "序列\t座號\t"; 
	for(int i = 0; i < subcount ; i ++ ) 
	  output+= subjects[i]+"\t";
	output+= "平均\t總分\t不及格個數\t等第"; 
	printslice("主表單",subcount*8); //增加一科目約增加  8 
	cout <<endl << output<<endl;
    
	for(int i =0;i<pc;i++)
	{
	
		int failcount = 0;
			cout << i+1<<"\t ";
		for(int r= 0 ; r<subcount+1;r++)
		{
			if(col[i][r] < 60 && r!=0) //不及格標示 
			{
				failcount++;
				cout <<col[i][r]<<"*\t";
			}
			else 
			cout <<col[i][r]<<"\t";
		}
		string templevel;
		for(int c = levelc-1; c >= 0;c--)
		{
			
		   if(col[i][subcount+1] >= levels[c].first)
			templevel = levels[c].second;
		}
		
			if(col[i][subcount+1] < 60) //不及格標示  
			{
				cout <<setprecision(3)<<col[i][subcount+1]<<"*\t";
			}
			else 
			cout <<setprecision(3)<<col[i][subcount+1]<<"\t";
			
		cout <<" "<<col[i][subcount+2]<<"\t"<<failcount<<"\t\t"<<templevel<<"\t"<<endl;
	}
		cout <<endl;
	printslice("總  計",subcount*8);
	cout <<endl<< "平均"<<"\t\t"; 
	for(int h = 1 ; h < subcount+1 ; h++)
	{
		float sum = 0 ;
	 	for (int i = 0 ; i < pc ; i ++)
			sum += col[i][h];
		float avg = sum / pc ;
		if(avg< 60 )
		{
			cout<<setprecision(3) << avg<<"*\t";
		}
		else
		cout<<setprecision(3) << avg<<"\t";
	}
	cout <<endl << "不及格數"<<"\t"; 
	for(int h = 1 ; h < subcount+1 ; h++)
	{
		int failcount = 0 ;
	 	for (int i = 0 ; i < pc ; i ++)
			if(col[i][h]<60)
			{
				failcount++;
			}
			
		cout << failcount<<"\t";
	}
	cout << endl<<"最高分"<<"\t\t";
	for(int h = 1 ; h < subcount+1;h++)
	{
		float max = -1;
		for(int i = 0; i < pc ; i ++ )
		{
			if(col[i][h]>max)
			max = col[i][h];
		}
		if(max == -1)
		cout <<"\t";
		else
		cout << max<<"\t";
	}
}
