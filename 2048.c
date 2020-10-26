#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int table[4][4];
void newgame(int table[4][4]);
void printtable(int table[4][4],int score,int bestscore);
void add_random_num(int table[4][4]);
void up(int table[4][4],int score);
void down(int table[4][4],int score);
void right(int table[4][4],int score);
void left(int table[4][4],int score);
void newuser();
int score,bestscore,game=0;
void gameover(int table[4][4]);



struct user{
	char name[20];
	int kayit[4][4];
	int score;
	int kayit_sayisi;
	
	
	
}player;

int main(){
	char direction;
	int table[4][4];
	int random_num,random_row,random_column,i,j,k,x,oyun,oyunsayisi,sayac=0;
	char isim[20];
	
	srand(time(NULL));
	
	printf("---------Welcome the 2048 game---------\n\nFor New User please press 'N' or want play saved game please press 'Z'\n");
	scanf("%c",&direction);	
	
	if(direction=='n' || direction=='N'){
		newuser();		
		newgame(table);
	}
	
	else if(direction=='z' || direction=='Z'){
		printf("Please enter name");
		scanf("%s",player.name);	
		FILE *filep=fopen(player.name,"r");	
		if(!filep){
			printf("Kullanici bulunamadi\n");
			return 0;
		}
		fseek(filep,-1,SEEK_END);
		fscanf(filep,"%d",oyunsayisi);	
		fclose(filep);	
		
		
		printf("%d adet oyun bulundu kacinci oyunu oynamak istiyorsunuz",oyunsayisi);
		scanf("%d",oyun);
		filep=fopen(player.name,"r");
		if(oyun==1){
			fseek(filep,17,SEEK_SET);
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					fscanf(filep,"%d",&table[i][j]);
				}
			}
			fscanf(filep,"%d",player.score);	
		}
		else if(oyun==2){
			fseek(filep,34,SEEK_SET);
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					fscanf(filep,"%d",&table[i][j]);
				}
			}
			fscanf(filep,"%d",player.score);	
		}
		else if(oyun==3){
			fseek(filep,51,SEEK_SET);
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					fscanf(filep,"%d",&table[i][j]);
				}
			}
			fscanf(filep,"%d",player.score);	
		}
		else if(oyun==4){
			fseek(filep,68,SEEK_SET);
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					fscanf(filep,"%d",&table[i][j]);
				}
			}
			fscanf(filep,"%d",player.score);	
		}
		else if(oyun==5){
			fseek(filep,85,SEEK_SET);
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					fscanf(filep,"%d",&table[i][j]);
				}
			}
			fscanf(filep,"%d",player.score);	
		}
		fclose(filep);
		printtable(table,score,bestscore);
	}
	
	
	
	newgame(table);
	while(1){	
		printtable(table,score,bestscore);
		fflush(stdin);
		scanf("%c",&direction);	
	
		if(direction=='w' || direction=='W'){						
			up(table,score);
			gameover(table);
			if(game==0){
				printf("GAME OVER");
				return 0;
			}
			add_random_num(table);
		}
		else if(direction=='s' || direction=='S'){								
			down(table,score);
			gameover(table);
			if(game==0){
				printf("GAME OVER");
				return 0;
			}
			add_random_num(table);
		}		
		else if(direction=='d' || direction=='D'){						
			right(table,score);
			gameover(table);
			if(game==0){
				printf("GAME OVER");
				return 0;
			}
			add_random_num(table);
		}
		else if(direction=='a' || direction=='A'){			
			left(table,score);
			gameover(table);
			if(game==0){
				printf("GAME OVER");
				return 0;
			}
			add_random_num(table);
		}
		else if(direction=='c' || direction=='C'){			
			printf("You aren in command mode\n");	
				
		}
		else if(direction=='k' || direction=='K'){
			
			FILE *filep=fopen(player.name,"r");
				while(!feof(filep)){
				fscanf(filep,"%d",player.kayit_sayisi);	
				}
			fclose(filep);
			if(player.kayit_sayisi>5){
				printf("Kullanicinin 5 adet kaydi oldugu icin kayit yapilamadi");
				return 0;
			}
			filep=fopen(player.name,"a");			
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					fprintf(filep,"%d",table[i][j]);
				}
			}
			player.score=score;
			fprintf(filep, "%d", player.score);
			fprintf(filep,"%d",player.kayit_sayisi);
			fclose(filep);
			player.kayit_sayisi ++;
			printf("oyun kaydedildi\n");
			
		}
		else if(direction=='n' || direction=='N'){
			newgame(table);
		}
	}
	

	
	return 0;
}

void gameover(int table[4][4]){
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(table[i][j]==0){
				game+=1;
			}
		}
	}
	if(game==0){
		for(i=0;i<3;i++){
			for(j=0;j<4;j++){
				if(table[i][j]==table[i][j+1]){
					game+=1;
				}
			}
		}
	}
	if(game==0){
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(table[j][i]==table[j+1][i]){
					game+=1;
				}
			}
		}
	}
}
	
	

void newuser(){
	char name[20];
	printf("Please enter your name\n");			
	scanf("%s",player.name);
	player.kayit_sayisi=1;
	FILE *filep=fopen(player.name,"r");
	if(!filep){
		fclose(filep);
		FILE *filep=fopen(player.name,"w");
		player.score=0;
		fclose(filep);
	}
	else{
		printf("Ayni isimli kullanici zaten bulunuyor");
		
	}
}

void newgame(int table[4][4]){
	int i,j,x,random_num,random_row,random_column;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			table[i][j]=0;
		}
	}
	
	for(i=0 ; i<2 ; i++){
		do{
			x = rand()%100 ;
			if(x<70){
				random_num=2;
			}
			else{
				random_num=4;
			}
			random_row=rand()%4;
			random_column=rand()%4;
		}while (table[random_row][random_column] != 0);
		table[random_row][random_column]=random_num;
		
	}	
}

void printtable(int table[4][4],int score,int bestscore) {
	int i,j;
	if(score>bestscore){
		bestscore = score;
	}
	printf("Score=%d  Bestscore=%d\n",score,bestscore);
	for(i=0; i<4; i++){
		printf("-----------------\n");
		for(j=0; j<4; j++){
			
			if(table[i][j]==0){
				printf("|   ");
			}
			else{
				printf("| %d ",table[i][j]);
			}
			
		}
		printf("|\n");
	}	
	printf("-----------------\n");
	printf("\nw = up   a = left   s = down   d = right    c = command mode    k = save game  n = new game \n");
}

void add_random_num(int table[4][4]){
	int i,j,random_num,x,random_row,random_column;
	srand(time(NULL));
	do{
			x = rand()%100 ;
			if(x<70){
				random_num=2;
			}
			else{
				random_num=4;
			}
			random_row=rand()%4;
			random_column=rand()%4;
		}while (table[random_row][random_column] != 0);
	table[random_row][random_column]=random_num;
		
}

void up(int table[4][4],int score){
	int i,j,k,l;	
			
		for(k=0;k<4;k++){
			for(i=0;i<3;i++){
				for(j=0;j<4;j++){
					if(table[i+1][j]!=0&&table[i][j]==0){
						table[i][j]=table[i+1][j];
						table[i+1][j] = 0;
					}
				}
			}
		}
		
		for(i=0;i<3;i++){
			for(j=3;j>=0;j--){
				if(table[i+1][j]==table[i][j]){
					table[i][j]*=2;
					table[i+1][j] = 0;
					score += table[i][j];
				}
			}
		}
	
		for(k=0;k<4;k++){
			for(i=0;i<3;i++){
				for(j=0;j<4;j++){
					if(table[i+1][j]!=0&&table[i][j]==0){
						table[i][j]=table[i+1][j];
						table[i+1][j] = 0;
					}
				}
			}
		}
	
}

void down(int table[4][4],int score){
	int i,j,k,l;
	
	
		for(i=0;i<4;i++){
			for(k=0;k<4;k++){
				for(j=3;j>0;j--){
					if(!table[j][i]){					
						if(table[j-1][i]){
							table[j][i]=table[j-1][i];
							table[j-1][i]=0;
						}
					}
				}
			}
			
			for(l=3;l>0;l--){
				if(table[l][i]&&table[l][i]==table[l-1][i]){
					table[l][i]+=table[l-1][i];
					table[l-1][i]=0;
					score+=table[l][i];
				}
			}
			
			for(k=0;k<4;k++){
				for(j=3;j>0;j--){
					if(!table[j][i]){					
						if(table[j-1][i]){
							table[j][i]=table[j-1][i];
							table[j-1][i]=0;
						}
					}
				}
			}			
		}
	
}

void right(int table[4][4],int score){
	int i,j,k,l;
	
	
		for(i=0;i<4;i++){
			for(k=0;k<4;k++){
				for(j=3;j>0;j--){
					if(!table[i][j]){					
						if(table[i][j-1]){
							table[i][j]=table[i][j-1];
							table[i][j-1]=0;
						}
					}
				}
			}
		
			for(l=3;l>0;l--){
				if(table[i][l]&&table[i][l]==table[i][l-1]){
					table[i][l]+=table[i][l-1];
					table[i][l-1]=0;
					score+=table[i][l];
				}
			}
		
			for(k=0;k<4;k++){
				for(j=3;j>0;j--){
					if(!table[i][j]){						
						if(table[i][j-1]){
							table[i][j]=table[i][j-1];
							table[i][j-1]=0;
						}
					}
				}
			}		
  		}
	
}

void left(int table[4][4],int score){
	int i,j,k,l;

		for(i=0; i<4 ;i++) {  
			for(k=0;k<4;k++){    
				for(j=0; j<4 ;j++){
					if(!table[i][j]){    					  
						if(table[i][j+1]){
							table[i][j]=table[i][j+1]; 
							table[i][j+1]=0;          						
						}
					}
				}
			}
			
			for(l=0;l<4;l++){
				if(table[i][l]&&table[i][l]==table[i][l+1]){         
					table[i][l]+=table[i][l+1];            
					table[i][l+1]=0;        
					score+=table[i][l];               
				}
			}
			
			for(k=0;k<4;k++){
				for(j=0; j<4 ;j++){
					if(!table[i][j]){   					
						if(table[i][j+1]){
							table[i][j]=table[i][j+1]; 
							table[i][j+1]=0;          							
						}
					}
				}
			}						
		}			
	
}
	




