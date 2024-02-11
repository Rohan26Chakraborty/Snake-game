#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;
int height=20,width=20,x,y,fruitx,fruity,flag,gameEnd,ch;
int piece=0,score=0;
int tailx[100],taily[100];
void setup(){
	x=height/2;
	y=width/2;
	srand(time(0));
	label1:
		fruitx=(rand()%19);
		if(fruitx==0){
			fruitx=1;
		}
		if(fruitx=18){
			fruitx=17;
		}
		if(x==fruitx){
			goto label1;
		}
	label2:
		fruity=(rand()%19);
		if(fruity=18){
			fruity=17;
		}
		if(fruity==0){
			fruity=1;
		}
		if(y==fruity){
			goto label2;
		}
	score=0;
	gameEnd=0;
}
void draw(){
	system("cls");
	int i,j,k;
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			if(i==0||i==height-1||j==0||j==width-1){
				cout<<"*";
			}
			else{
				if(i==x && j==y){
					cout<<"0";
				}
				else if(i==fruitx && j==fruity){
					cout<<"@";
				}
				else{
					ch=0;
					for(k=0;k<piece;k++){
						if(i==tailx[k] && j==taily[k]){
							cout<<"0";
							ch=1;
						}
					}
					if(ch==0)
						cout<<" ";
				}
			}
		}
		cout<<'\n';
	}
	cout<<"Score is:"<<score<<'\n';
	
}
void input(){
	if(kbhit()){
		switch(getch()){
			case 'q':
				flag=1;
				break;
			case 'w':
				flag=2;
				break;
			case 'o':
				flag=3;
				break;
			case 'p':
				flag=4;
				break;
		}
	}
}
void makelogic(){
	int i;
	int prevx,prevy,prev2x,prev2y;
	prevx=tailx[0];
	prevy=taily[0];
	tailx[0]=x;
	taily[0]=y;
	for(i=1;i<=piece;i++){
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(flag){
		case 1:
			x--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y--;
			break;
		case 4:
			y++;
			break;
	}
	if(x==0||x==height-1||y==0||y==width-1){
		gameEnd=1;
		cout<<"Game over!"<<'\n';
	}
	if(x==fruitx && y==fruity){
		label3:
			fruitx=(rand()%19);
			if(fruitx==0){
				fruitx=1;
			}
			if(x==fruitx){
				goto label3;
			}
		label4:
			fruity=(rand()%19);
			if(fruity==0){
				fruity=1;
			}
			if(y==fruity){
				goto label4;
			}
		score++;
		piece++;
	}
}
int main(){
	setup();
	while(gameEnd!=1){
		input();
		draw();
		makelogic();
	}
	return 0; 
}
