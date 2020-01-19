#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
#define START 1
#define FINISH 2


void upper(char s[]) {//buyuk harfe cevirme fonksiyonu
   int k = 0;
   
   while (s[k] != '\0') {
      if (s[k] >= 'a' && s[k] <= 'z') {
         s[k] = s[k] - 32;
        }
      k++;
      }
    }

int find_length(char word[]){//girilen stringin uzunlugunu bulma

	int length = 0;
    while(word[length]!='\0')  //  remove ;
    {
        length++;
    }
	return length;
	}
	
void searching_in_puzzle_south(int row,int column,char *dict[],char word[],int coord[][4]){//south  kontrol
	int i,j,length;
	//printingmap(puzzlemap,dict,coord);
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
		
		if(coord[i][0]==row&&coord[i][1]==column){//girilen degerler bir baslangýc degeri ise
			for(j=1;j<length;j++){
				row=row+1;
					}
			if(coord[i][2]==row&&coord[i][3]==column){
				printf("your word:%s is same with %s (in puzzle) and they southward range from your entered coordinates:\n\n ",word,dict[i]);	
				upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
				return;
				}
			}
	}
	printf("your word:%s is NOT in SOUTHWARD range from your entered coordinates:\n\n ",word);	
}

void searching_in_puzzle_north(int row,int column,char *dict[],char word[],int coord[][4]){//north kontrol
	int i,j,length;
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
		if(coord[i][2]==row&&coord[i][3]==column)//girilen degerler bitis kordinatýysa
		{
			for(j=1;j<length;j++){
				row=row-1;
				}
			if(coord[i][0]==row&&coord[i][1]==column){
				printf("your word:%s is same with %s (in puzzle) and they northward range from your entered coordinates:\n\n ",word,dict[i]);	
			upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
			return;
			}
		}
	}
	printf("your word:%s NOT in NORTHWARD range from your entered coordinates:\n\n ",word);	
}

void searching_in_puzzle_west(int row,int column,char *dict[],char word[],int coord[][4]){//west kontrol
	int i,j,length;
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
			if(coord[i][2]==row&&coord[i][3]==column)
			{
				
				for(j=1;j<length;j++){
					column=column-1;//batiya dogru kontrol 
					
				}
				if(coord[i][0]==row&&coord[i][1]==column){//baslangýc kordinatlara ulasýr mý kontrolu
				printf("your word:%s is same with %s (in puzzle) and they westward range from your entered coordinates:\n\n ",word,dict[i]);	
				upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
					return;
				}
			}
		}
	printf("your word:%s NOT in WESTWARD range from your entered coordinates:\n\n ",word);
}

void searching_in_puzzle_east(int row,int column,char *dict[],char word[],int coord[][4]){//east kontrol
	int i,j,length;
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
			if(coord[i][0]==row&&coord[i][1]==column)//bir baslangýc koordinatý doguya dogrudur
			{
				
				for(j=1;j<length;j++){
					column=column+1;//doguya dogru kontrol 
					
				}
				if(coord[i][2]==row&&coord[i][3]==column){//kelimenin son koordinatýna ulasirsa dogrudur
				printf("your word:%s is same with %s (in puzzle) and they EASTWARD range from your entered coordinates:\n\n ",word,dict[i]);	
					upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
					return;
				}
			}
		}
	printf("your word:%s NOT in EASTWARD range from your entered coordinates:\n\n ",word);
}

void searching_in_puzzle_south_west(int row,int column,char *dict[],char word[],int coord[][4]){//south_west kontrol
	int i,j,length;
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
			if(coord[i][0]==row&&coord[i][1]==column)
			{
				for(j=1;j<length;j++){
					column=column-1;//batiya dogru kontrol 
					row=row+1;//guneye dogru kontrol
				}
				if(coord[i][2]==row&&coord[i][3]==column){//kelimenin son koordinatýna ulasirsa dogrudur
				printf("your word:%s is same with %s (in puzzle) and they SOUTHWESTWARD (SOUTH WEST DÝAGONAL) range from your entered coordinates:\n\n ",word,dict[i]);	
					upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
					return;
				}
			}
		}
	printf("your word:%s NOT in SOUTHWESTTWARD (SOUTH WEST DÝAGONAL) range from your entered coordinates:\n\n ",word);
}

void searching_in_puzzle_south_east(int row,int column,char *dict[],char word[],int coord[][4]){//south_east kontrol
	int i,j,length;
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
			if(coord[i][0]==row&&coord[i][1]==column)
			{
				for(j=1;j<length;j++){
					column=column+1;//DOGUYA dogru kontrol 
					row=row+1;//guneye dogru kontrol
				}
				if(coord[i][2]==row&&coord[i][3]==column){//kelimenin son koordinatýna ulasirsa dogrudur
				printf("your word:%s is same with %s (in puzzle) and they SOUTHEASTWARD(SOUTH EAST DÝAGONAL) range from your entered coordinates:\n\n ",word,dict[i]);	
					upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
					return;
				}
			}
		}
	printf("your word:%s NOT in SOUTHEASTTWARD(SOUTH EAST DÝAGONAL) range from your entered coordinates:\n\n ",word);
}

void searching_in_puzzle_north_west(int row,int column,char *dict[],char word[],int coord[][4]){//aï¿½aï¿½ï¿½ yï¿½nlï¿½ kontrol
	int i,j,length;
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
			if(coord[i][2]==row&&coord[i][3]==column)//bir bitis koordinatý kuzey doguya dogru range icinde olabilir
			{
				for(j=1;j<length;j++){
					column=column-1;//batýya dogru kontrol 
					row=row-1;//kuzeye dogru kontrol
				}
				if(coord[i][0]==row&&coord[i][1]==column){//kelimenin baslangýc koordinatýna ulasirsa dogrudur
				printf("your word:%s is same with %s (in puzzle) and they NORTHWESTWARD(NORTH WEST DÝAGONAL) range from your entered coordinates:\n\n ",word,dict[i]);	
					upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
					return;
				}
			}
		}
	printf("your word:%s NOT in NORTHWESTWARD(NORTH WEST DÝAGONAL) range from your entered coordinates:\n\n ",word);
}

void searching_in_puzzle_north_east(int row,int column,char *dict[],char word[],int coord[][4]){//kuzeydogu yonunde range kontrolu
		int i,j,length;
	length=find_length(word);
	for(i=0;i<DICT_SIZE;i++){
			if(coord[i][0]==row&&coord[i][1]==column)
			{
				for(j=1;j<length;j++){
					column=column-1;//batýya dogru kontrol 
					row=row-1;//kuzeye dogru kontrol
				}
				if(coord[i][2]==row&&coord[i][3]==column){//kelimenin baslangýc koordinatýna ulasirsa dogrudur
				printf("your word:%s is same with %s (in puzzle) and they NORTHEASTWARD (NORTH EAST DÝAGONAL) range from your entered coordinates:\n\n ",word,dict[i]);	
					upper(dict[i]);//dogrulanan kelimeyi uppercase'e ceviriyoruz 
					return;
				}
			}
		}
	printf("your word:%s NOT in NORTHEASTWARD (NORTH EAST DÝAGONAL) range from your entered coordinates:\n\n ",word);
}

int coordinate_check(int coord[][4],int row,int column){//girilen koordinatlari kontrol ediyoruz
		int i,j,check;
		for(i=0;i<DICT_SIZE;i++){
			if(coord[i][0]==row&&coord[i][1]==column){
		
			check=START;
			
			}
			if(coord[i][2]==row && coord[i][3]==column){
			
			check=START;
			
			}
		}
	return check;

}

int stringCompare(char str1[],char str2[])  // strcmp islevli fonksiyonumuz
	{
    int i = 0, flag = 0;
    while(str1[i] != '\0' && str2[i] != '\0') // stringin sonuna kadar
    {
        
        if(str1[i] != str2[i]) 
        {
            flag = 1;
            break;
        }
        i++;
    }
	if(flag == 0 && str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
	}
	
void printingmap(int map[][15],char *dict[],int coord[][4]){//puzzle map yazdirma 
	int a=0,randchar,i,j,lower_bound=97,upper_bound=123;
		//srand(time(NULL));
		for(i=0;i<15;i++){//MAPA RANDOM CHAR ATAMA
		for(j=0;j<15;j++){
			randchar=lower_bound+rand()%(upper_bound-lower_bound);
			map[i][j]=randchar;
				}
				}
		printf("\t\t  PUZZLE MAP\n\n");
		for(i=0;i<15;i++){//puzzle in  satirlari
				printf("\t");
			
			for(j=0;j<15;j++){//puzzle in satirlari
			
			if(9<=i && i<=13 && j==14){//serum 1s  c 
			
				if(i==9)	printf("%.1s ", dict[0]);
				if(i==10)	printf("%.1s ", dict[0]+1);
				if(i==11)	printf("%.1s ", dict[0]+2);
				if(i==12)	printf("%.1s ", dict[0]+3);
				if(i==13)	printf("%.1s ", dict[0]+4);
			}
			else if(11<=i && i<=14 && j==2){//lenf
				if(i==11)	printf("%.1s ", dict[1]);
				if(i==12)	printf("%.1s ", dict[1]+1);
				if(i==13)	printf("%.1s ", dict[1]+2);
				if(i==14)	printf("%.1s ", dict[1]+3);
			}
			else if(0<=i && i<=5 && j==4){//alveol
				if(i==0)	printf("%.1s ", dict[2]);
				if(i==1)	printf("%.1s ", dict[2]+1);
				if(i==2)	printf("%.1s ", dict[2]+2);
				if(i==3)	printf("%.1s ", dict[2]+3);
				if(i==4)	printf("%.1s ", dict[2]+4);
				if(i==5)	printf("%.1s ", dict[2]+5);

			}
			
			else if(i==11 && j<=12 && j>=8){//hucre
				if(j==8)	printf("%.1s ", dict[3]);
				if(j==9)	printf("%.1s ", dict[3]+1);
				if(j==10)	printf("%.1s ", dict[3]+2);
				if(j==11)	printf("%.1s ", dict[3]+3);
				if(j==12)	printf("%.1s ", dict[3]+4);
			}
			
			else if(3>=i&&i>=1 && j<12 && j>8){//kan
				
				if(j==9 && i==1)	printf("%.1s ", dict[4]);
				if(j!=9 && i==1)	printf("%c ",map[i][j]);
				if(j==10 && i==2)	printf("%.1s ", dict[4]+1);
				if(j!=10 && i==2)	printf("%c ",map[i][j]);
				if(j==11 && i==3)	printf("%.1s ", dict[4]+2);
				if(j!=11 && i==3)	printf("%c ",map[i][j]);
			}
			
			else if(7<=i && i<=9 && j==4){//kas
				if(i==7)	printf("%.1s ", dict[5]);
				if(i==8)	printf("%.1s ", dict[5]+1);
				if(i==9)	printf("%.1s ", dict[5]+2);
			
			}
		
			else if(i<=9 &&i>=3 &&j<=8 && j>=2){//dolasim
			
				if(j==2&&i==3)			printf("%.1s ", dict[6]);
				if(j!=2 && i==3&&j!=8)	printf("%c ",map[i][j-5]);
				if(j==8	&&	i==3)		printf("%.1s ", dict[10]+1);
				if(j==3&&i==4)			printf("%.1s ", dict[6]+1);
				if(j!=3 && i==4)		printf("%c ",map[i][j]);
				if(j==4&&i==5)			printf("%.1s ", dict[6]+2);
				if(j!=4 && i==5)		printf("%c ",map[i][j]);
				if(j==5&&i==6)			printf("%.1s ", dict[6]+3);
				if(j!=5 && i==6)		printf("%c ",map[i][j]);
				if(j==6&&i==7)			printf("%.1s ", dict[6]+4);
				if(j!=6 && i==7)		printf("%c ",map[i][j]);
				if(j==7&&i==8)			printf("%.1s ", dict[6]+5);
				if(j!=7 && i==8)		printf("%c ",map[i][j]);
				if(j==8&&i==9)			printf("%.1s ", dict[6]+6);
				if(j!=8 && i==9)		printf("%c ",map[i][j]);
			}
			
			else if(i<=10 &&i>=4 &&j==1){//akciger 4-1 10-1
			
				if(i==4)	printf("%.1s ", dict[9]);
				if(i==5)	printf("%.1s ", dict[9]+1);
				if(i==6)	printf("%.1s ", dict[9]+2);
        		if(i==7)	printf("%.1s ", dict[9]+3);
				if(i==8)	printf("%.1s ", dict[9]+4);
				if(i==9)	printf("%.1s ", dict[9]+5);
        		if(i==10)	printf("%.1s ", dict[9]+6);
			}
			
			else if(i<=13 &&i>=5 &&j==0){//atardamar 5-0 13-0
			  
				if(i==5)		printf("%.1s ", dict[11]);
				if(i==6)		printf("%.1s ", dict[11]+1);
        		if(i==7)		printf("%.1s ", dict[11]+2);
				if(i==8)		printf("%.1s ", dict[11]+3);
				if(i==9)		printf("%.1s ", dict[11]+4);
		        if(i==10)		printf("%.1s ", dict[11]+5);
		        if(i==11)		printf("%.1s ", dict[11]+6);
		        if(i==12)		printf("%.1s ", dict[11]+7);
		        if(i==13)		printf("%.1s ", dict[11]+8);
      		}
			else if(i==12 &&j<=11 && j>=5){//solunum 12-5 12-11
			  	if(j==5)	printf("%.1s ", dict[12]);
        		if(j==6)	printf("%.1s ", dict[12]+1);
        		if(j==7)	printf("%.1s ", dict[12]+2);
				if(j==8)	printf("%.1s ", dict[12]+3);
				if(j==9)	printf("%.1s ", dict[12]+4);
				if(j==10)	printf("%.1s ", dict[12]+5);
				if(j==11)	printf("%.1s ", dict[12]+6);
			}
			else if(i==0 &&j<=14 && j>=7){//kikirdak 0-7 0-14
        		if(j==7)	printf("%.1s ", dict[13]);
				if(j==8)	printf("%.1s ", dict[13]+1);
				if(j==9)	printf("%.1s ", dict[13]+2);
				if(j==10)	printf("%.1s ", dict[13]+3);
				if(j==11)	printf("%.1s ", dict[13]+4);
        		if(j==12)	printf("%.1s ", dict[13]+5);
        		if(j==13)	printf("%.1s ", dict[13]+6);
        		if(j==14)	printf("%.1s ", dict[13]+7);
      		}
			else if(i==13 &&j<=13 && j>=7){//bakteri 13-7 13-13
			
				if(j==7)	printf("%.1s ", dict[14]);
				if(j==8)	printf("%.1s ", dict[14]+1);
				if(j==9)	printf("%.1s ", dict[14]+2);
				if(j==10)	printf("%.1s ", dict[14]+3);
				if(j==11)	printf("%.1s ", dict[14]+4);
       			if(j==12)	printf("%.1s ", dict[14]+5);	
				if(j==13)	printf("%.1s ", dict[14]+6);
        	}
        	else if(i<=10 &&i>=7 &&j<=13 && j>=10){//kalp 7-10 10-13
			
				if(j==10&&i==7)				printf("%.1s ", dict[7]);
				if(j!=10 && i==7&&j!=12)	printf("%c ",map[i][j]);
				if(j==12&&i==7)				printf("%.1s ", dict[10]+5);
				if(j==11&&i==8)				printf("%.1s ", dict[7]+1);
				if(j!=11 && i==8&&j!=13)	printf("%c ",map[i][j]);
				if(j==13&&i==8)				printf("%.1s ", dict[10]+6);
				if(j==12&&i==9)				printf("%.1s ", dict[7]+2);
				if(j!=12 && i==9)			printf("%c ",map[i][j]);
				if(j==13&&i==10)			printf("%.1s ", dict[7]+3);
				if(j!=13 && i==10)			printf("%c ",map[i][j]);
				
			}
			else if(i<=8 &&i>=2 &&j<=13 && j>=7){//iskelet 2-7 8-13
			
				if(j==7&&	i==2)	printf("%.1s ", dict[10]);
				if(j!=7 && i==2)	printf("%c ",map[i][j]);
				if(j==8	&&	i==3)	printf("%.1s ", dict[10]+1);
				if(j!=8 && i==3)	printf("%c ",map[i][j]);
				if(j==9	&&	i==4)	printf("%.1s ", dict[10]+2);
				if(j!=9 && i==4)	printf("%c ",map[i][j]);
				if(j==10&&	i==5)	printf("%.1s ", dict[10]+3);
				if(j!=10 && i==5)	printf("%c ",map[i][j]);
				if(j==11&&	i==6)	printf("%.1s ", dict[10]+4);
				if(j!=11 && i==6)	printf("%c ",map[i][j]);
				if(j!=12 && i==7)	printf("%c ",map[i][j]);
				if(j!=13 && i==8)	printf("%c ",map[i][j]);
			}
			else if(i<=14 &&i>=10 &&j<=6 && j>=2){//kemik 10-2   14-6
			
				if(j==2&&i==10)					printf("%.1s ", dict[8]);
				if(j!=2 && i==10)				printf("%c ",map[i][j]);
				if(j==3&&i==11)					printf("%.1s ", dict[8]+1);
				if(j!=3 && i==11)				printf("%c ",map[i][j]);
				if(j==4&&i==12)					printf("%.1s ",dict[8]+2);
				if(j!=4 && i==12)				printf("%c ",map[i][j]);
				if(j==5&&i==13)					printf("%.1s ",dict[13]+3);
				if(j!=5 && i==13)				printf("%c ",map[i][j]);
				if(j==6&&i==14)					printf("%.1s ", dict[8]+4);
				if(j!=6 && i==14)				printf("%c ",map[i][j]);
				}
				
			else
			printf("%c ",map[i][j]);
			}
		printf("\n");
		}printf("\n");  
	}
	
	int get_line_size(char *line) {
		char *ch_iter = line; // so as not to lose beginning of line
		int counter = 0;
		// go until you see new line or null char
		while(*ch_iter != '\n' && *ch_iter != '\0') {
			ch_iter++; // next char
			counter++; // increment counter
		}
		
		return counter;
	}
	
	void copy_string(char *source, char *destination) {
		// get iterators over original pointers
		char *src_iter = source;
		char *dst_iter = destination;
		// until null char
		while (*src_iter != '\0') {
			// copy pointers
			*dst_iter = *src_iter;
			// advance to next char
			src_iter++;
			dst_iter++;
	   }
	   // terminate string
	   *dst_iter = '\0';
	}
	
	void remove_newline(char *line) {
		char *ch_iter = line;
		// go until you see new line
		while(*ch_iter != '\n') {
			ch_iter++; // next char
		}
		*ch_iter = '\0'; // overwrite new line
	}
	
	void print_dictionary(char *dict[]) {//dosyadaki isimleri yazdirma
		int i;
		for(i = 0 ; i < DICT_SIZE ; i++) {
			printf("%s\n", dict[i]);
		}
	}
	
	void print_coord(int coord[DICT_SIZE][4]) {//dosyadaki koordinatlarini yazdirma
		int i, j;
		for(i = 0 ; i < DICT_SIZE ; i++) {
			for(j = 0 ; j < 4 ; j++) {
				printf("%d ", coord[i][j]);
			}
			printf("\n");
		}
	}

int main(){
	char *dict[DICT_SIZE];//dosyadaki isimleri tutuyor
    int coord[DICT_SIZE][4];  //isimlerin koordinatlarini tutuyor  
    char line[LINE_LEN];
    int puzzlemap[15][15];
	FILE *fp = fopen("word_hunter.dat", "r");
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	fclose(fp);
	print_dictionary(dict);
	printf("Word coordinates\n");	
	print_coord(coord);
	printingmap(puzzlemap,dict,coord);
	char name[20];
	printf("Please enter word for search:(write exit to exit)\n");
	scanf("%s",name);
	int r,c,check;
	char exit1[5]={"exit"};
	if(stringCompare(name,exit1)==1){
		exit(0);
	}
	printf("Please enter r-c of word's first or last character  for search(r=row,c=column):\n");//satir ve sutunun koordinatlarini aliyoruz
	scanf("%d %d",&r,&c);
	
	while(r<0||r>14||c<0||c>14){//kullanicinin puzzle disindan koordinat girmesini engelledik
	printf("You must enter values between 0-14 for search(r=row,c=column)!!\n");
	printf("Please enter r-c of word's first or last character  for search(r=row,c=column):");//satï¿½r ve sï¿½tï¿½nun koordinatlarï¿½nï¿½ alï¿½yoruz
	scanf("%d %d",&r,&c);
	}
	printf("%s\n",name);
	printf("you entered r=%d c=%d\n",r,c);
	
	check=coordinate_check(coord,r,c);
	
	while(check!=1){//puzzleda bulunmayan bir kelime koordinatýný girerse hata verir
	printf("there is NOT word that have these coordinates\n");
	printf("Please enter another row-column of word's first or last character\n");
	scanf("%d %d",&r,&c);
	
	check=coordinate_check(coord,r,c);
	}
	int length=find_length(name);
	printf("there is a word that have these coordinates\n");
	
		//8 YONDE KONTROL
		searching_in_puzzle_south(r,c,dict,name,coord);
		searching_in_puzzle_north(r,c,dict,name,coord);
		searching_in_puzzle_west(r,c,dict,name,coord);
		searching_in_puzzle_east(r,c,dict,name,coord);
		searching_in_puzzle_north_east(r,c,dict,name,coord);
		searching_in_puzzle_north_west(r,c,dict,name,coord);
		searching_in_puzzle_south_east(r,c,dict,name,coord);
		searching_in_puzzle_south_west(r,c,dict,name,coord);
		
		printingmap(puzzlemap,dict,coord);
		// WRITE HERE...
	
	return 0;
	}





