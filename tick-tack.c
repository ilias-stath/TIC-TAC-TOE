#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Tick-Tack-toe */

// Memory leak?
int Row, Column;

char welcoming(char *cSymbol, int i);
void board(char bPlace[9]);
void costumeB(char bPlace[Row][Column]);
void PvE(char pSymbol, char cSymbol);
void PvP(char pSymbol, char cSymbol, int Row, int Column, bool cG);
void CustomGame(int Row, int Column, char bPlace[Row][Column]);
bool check_place(int place, char bPlace[9]);
bool check_place_cos(int place, int k, char bPlace[Row][Column]);
int AI(char bPlace[9], int tturn, char pSymbol, char cSymbol);
int AIaboutWinLose(char Symbol, char virTable[9], int *tcount);
int AIchoice(char table[9], char pSymbol, char cSymbol);
bool Game_End(char bPlace[9], char *symb);
bool Game_End_Custome(char bPlace[Row][Column], char *symb);

int main(){
	bool cG;
	int i=0, j, k,e;
	char pSymbol, cSymbol;
	
	
	while(i != 5){
			
		printf("-----------Menu-----------\n");
		printf("1.PVE\n2.PVP\n3.CUSTOME GAME\n4.RULES\n5.EXIT\nType (1-5) to choose an action.\n\n");
		printf("--------------------------\n");
		printf("Choice:");
		scanf("%d",&i);
		
		if(i == 1){
			system("cls");
			pSymbol = welcoming(&cSymbol, i);
			printf("\nYour letter: %c \nComputers letter: %c\n\n", pSymbol, cSymbol);
			system("PAUSE");
			system("cls");
			PvE(pSymbol, cSymbol);
		}
		else if(i == 2){
			printf("Choose the size of the board.\n");
			printf("Row:");
			scanf("%d",&Row);
			printf("Column:");
			scanf("%d",&Column);
			printf("\n");
			char bPlace[Row][Column];
			
			system("cls");
			pSymbol = welcoming(&cSymbol, i);
			printf("\nP1 letter: %c \nP2 letter: %c\n\n", pSymbol, cSymbol);
			system("PAUSE");
			system("cls");
			cG = false;
			PvP(pSymbol, cSymbol, Row, Column, cG);
		}
		else if( i == 4){
			printf("Choose the size of the board.\n");
			printf("Row:");
			scanf("%d",&Row);
			printf("Column:");
			scanf("%d",&Column);
			printf("\n");
			char bPlace[Row][Column];
			
			system("cls");
			printf("-----------WELCOME TO TICK-TACK-TOE-------------\n\n\n\n");
			printf("--------------------------\n");
			printf("Rules of the game: \n1.The \"X\" always starts first.\n2.The first one to have 3 of his symbol in a consecutive row(horizontal,vertical,diagonal), wins.\n3.If all the brackets are filled and no row has formed, the game ends in a draw.\n4.You cannot place your symbol in an occupied bracket.\n"); 
			printf("--------------------------\n\n");
			
			k=1;
			for(j=0; j<Row; j++){
				for(e=0; e<Column; e++){
					if(Row > Column){
						bPlace[j][e] = 48 + k; //+ j*Row - j*(Row-Column);
					}
					else if(Row < Column){
						bPlace[j][e] = 48 + k; //+ j*Row + j*(Column-Row);
					}
					else{
						bPlace[j][e] = 48 + k; //+ j*Row;
					}
					//printf("%d , %d %d\n",j,i,k);
					//printf("%c\n",bPlace[j][i]);
					//printf("%d\n",bPlace[j][i]);
					//system("PAUSE");	
					if(k<9){
						k++;
					}
					else{
						k=0;
					}
				}
			}
			printf("\n\n");
			costumeB(bPlace);
			printf("\nThis is the board.You place your letter by typping the number of the place you want to put your letter. \nIf the place is occupied(Having the letter \"X\" or \"O\"), you cannot put yours there.\n\n");
			system("PAUSE");
			system("cls");
		}
		else if( i == 3){
			printf("Choose the size of the board.\n");
			printf("Row:");
			scanf("%d",&Row);
			printf("Column:");
			scanf("%d",&Column);
			printf("\n");
			char bPlace[Row][Column];
			
			system("cls");
			pSymbol = welcoming(&cSymbol, i);
			printf("\nP1 letter: %c \nP2 letter: %c\n\n", pSymbol, cSymbol);
			system("PAUSE");
			system("cls");
			cG = true;
			PvP(pSymbol, cSymbol, Row, Column , cG);
		}
		else if( i == 5){
			break;
		}
		else{
			system("cls");
			printf("Error.Choice does not exist.\n");
		}
	}
	
	
	return 0;
}


char welcoming(char *cSymbol, int i){
	char pSymbol;
	
	if(i == 1){
		printf("\nSelect if you want to have the \"X\" or \"O\", by typing the letter of your choice (English only).\n");
	}
	else{
		printf("\nP1, select if you want to have the \"X\" or \"O\", by typing the letter of your choice (English only).\n");
	}
	
	
	do{
		printf("Choice: ");
		scanf(" %c",&pSymbol);
		printf("\n");
		
		if(pSymbol == 'x' ){
			pSymbol = 'X';
		}
		else if(pSymbol == 'o'){
			pSymbol = 'O';
		}
		else if(pSymbol != 'X' && pSymbol != 'O'){
			printf("You must type only \"X\" or \"O\" in english.\n");
		}
		else{
			continue;
		}
		
	}while(pSymbol != 'X' && pSymbol != 'O');
	
	if(pSymbol == 'X'){
		*cSymbol = 'O';
	}
	else{
		*cSymbol = 'X';
	}
	
	
	return pSymbol;
	
}

void board(char bPlace[9]){
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",bPlace[0],bPlace[1],bPlace[2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",bPlace[3],bPlace[4],bPlace[5]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",bPlace[6],bPlace[7],bPlace[8]);
	printf("     |     |     \n");
}


void costumeB(char bPlace[Row][Column]){
	int i,j,k=0,e=0;
	
	for(i=0; i<Row; i++){
		for(j=0; j<Column; j++){
			printf("     ");
			if(j == Column-1) printf("\n");
			else printf("|");
		}
		for(j=0; j<Column; j++){
			if(e<9){
				e++;
			}
			else{
				e=0;
				k++;
			}
			if(bPlace[i][j] == 'X' || bPlace[i][j] == 'O'){
				printf("  %c  ",bPlace[i][j]);
			}
			/*else if(k == 0 && e==0){
				printf("  %c  ",bPlace[i][j]);
			}
			else if(k != 0 && e==0){
				printf("  %c%c ",a[k],bPlace[i][j]);
			}
			else{
				printf(" %c%c%c ",a[e],a[k],bPlace[i][j]);
			}*/
			else if(k==0){
				printf("  %c  ",bPlace[i][j]);
			}
			else{
				if(k<10){
					printf("  %d%c ",k,bPlace[i][j]);
				}
				else if(k<100){
					printf(" %d%c ",k,bPlace[i][j]);
				}
				else if(k<1000){
					printf(" %d%c",k,bPlace[i][j]);
				}
				else{
					printf("%d%c",k,bPlace[i][j]);
				}
			}
			
			if(j == Column-1){
				printf("\n");
			}
			else{
				printf("|");
			}
		}
		if(i == Row-1){
			for(j=0; j<Column; j++){
				printf("     ");
				if(j == Column-1) printf("\n");
				else printf("|");
			}
		}
		else{
			for(j=0; j<Column; j++){
				printf("_____");
				if(j == Column-1) printf("\n");
				else printf("|");
			}
		}
	}
	
	/*printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",bPlace[0][0],bPlace[0][1],bPlace[0][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",bPlace[1][0],bPlace[1][1],bPlace[1][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",bPlace[2][0],bPlace[2][1],bPlace[2][2]);
	printf("     |     |     \n");*/
	
	
}

void PvE(char pSymbol, char cSymbol){
	int turn=0, place, i, tturn=0;
	bool start = true, game_end = false, empty;
	char bPlace[9], symb;
	
	while(start){
		
		if(game_end == true){
			start = false;
			if(symb == 'D'){
				printf("\nThe match is a draw.\n");
				system("PAUSE");
				system("cls");
				break;
			}
			else{
				printf("\n%c is the winner.\n", symb);
				system("PAUSE");
				system("cls");
				break;
			}
		}
		else if(turn == 0){
			for(i=0; i<9; i++){
				bPlace[i] = 49 + i;
			}
			
			
			if(pSymbol == 'X'){
				printf("\n\nYou Have the letter \"X\", so you start first.\n");
				turn = 1;
			}
			else{
				printf("\n\nYou Have the letter \"O\", so the computer starts first.\n");
				turn = 2;
			}
			system("PAUSE");
			system("cls");
		}
		else{
			if(turn == 1){
				printf("\n\n");
				printf("-----------------------\n");
				printf("Your turn.\n");
				printf("Type a place you want to put your letter.\n");
				do{
					printf("Place: ");
					scanf("%d",&place);
					printf("\n");
					empty = check_place(place, bPlace);
					if(place < 1 || place > 9){
						printf("You can only type integers from the field [1,9].\n");
					}
					else if(!empty){
						printf("Position is not empty.Type a valid place.\n");
					}
					else{
						bPlace[place-1] = pSymbol;
						continue;
					}
					
				}while(!empty || place < 1 || place > 9);
				system("cls");
				turn = 2;
				tturn++;
			}
			else{
				printf("\n\n");
				printf("-----------------------\n");
				printf("Computers turn.\n");
				place = AI(bPlace, tturn, pSymbol, cSymbol);
				bPlace[place] = cSymbol;
				turn = 1;
				tturn++;
			}
		}
		
		board(bPlace);
		game_end = Game_End(bPlace, &symb);
		
			
	}
	
}

void PvP(char pSymbol, char cSymbol, int Row, int Column, bool cG){
	int turn = 0, i, place, k=0, j, pos;
	char symb, bPlace[Row][Column];
	bool start = true, game_end = false, empty;
	
	while(start){
		
		if(game_end == true){
			start = false;
			if(symb == 'D'){
				printf("\nThe match is a draw.\n");
				system("PAUSE");
				system("cls");
				break;
			}
			else{
				printf("\n%c is the winner.\n", symb);
				system("PAUSE");
				system("cls");
				break;
			}
			
		}
		else if(turn == 0){
			k=1;
			for(i=0; i<Row; i++){
				for(j=0; j<Column; j++){
					if(Row > Column){
						bPlace[i][j] = 48 + k; 
					}
					else if(Row < Column){
						bPlace[i][j] = 48 + k; 
					}
					else{
						bPlace[i][j] = 48 + k; 
					}
					//printf("%d , %d %d\n",j,i,k);
					//printf("%c\n",bPlace[j][i]);
					//printf("%d\n",bPlace[j][i]);
					//system("PAUSE");	
					if(k<9){
						k++;
					}
					else{
						k=0;
					}
				}
			}
			if(cG == true){
				CustomGame(Row,Column,bPlace);
			}
			
			if(pSymbol == 'X'){
				printf("\n\nP1 has the letter \"X\", so he starts first.\n");
				turn = 1;
			}
			else{
				printf("\n\nP2 has the letter \"X\", so he starts first.\n");
				turn = 2;
			}
			system("PAUSE");
			system("cls");
		}
		else{
			if(turn == 1){
				printf("\n\n");
				printf("-----------------------\n");
				printf("P1 turn.\n");
				printf("Type a place you want to put your letter.\n");
				do{
					printf("Place: ");
					scanf("%d",&place);
					printf("\n");
					pos = place;
					place--;
					k=0;
					i=0;
					if(place <= Column){
						//printf("bp=%c\n",bPlace[0][place]);
						k=place;
						i=0;
					}
					else {
						do{
							k += place - Column;
							i++;
							//printf("k=%d , p=%d, i=%d\n",k,place,i);
							//system("PAUSE");
							if(k <= Column){
								break;
							}
							else{
								place=k;
								k=0;
							}
						}while(place>Column);
					}
					//printf("k=%d , p=%d, i=%d\n",k,pos,i);
					//printf("\n%c\n",bPlace[i][k]);
					//system("PAUSE");
					empty = check_place_cos(i, k, bPlace);
					if(pos < 1 || pos > (Column*Row)){
						printf("You can only type integers from the field [1,%d].\n",(Column*Row));
					}
					else if(!empty){
						printf("Position is not empty.Type a valid place.\n");
					}
					else{
						bPlace[i][k] = pSymbol;
						continue;
					}
					
				}while(!empty || pos < 1 || pos > (Column*Row));
				system("cls");
				turn = 2;
				
			}
			else{
				printf("\n\n");
				printf("-----------------------\n");
				printf("P2 turn.\n");
				printf("Type a place you want to put your letter.\n");
				do{
					printf("Place: ");
					scanf("%d",&place);
					printf("\n");
					pos = place;
					place--;
					k=0;
					i=0;
					if(place <= Column){
						//printf("bp=%c\n",bPlace[0][place]);
						k=place;
						i=0;
					}
					else {
						do{
							k += place - Column;
							i++;
							//printf("k=%d , p=%d, i=%d\n",k,place,i);
							//system("PAUSE");
							if(k <= Column){
								break;
							}
							else{
								place=k;
								k=0;
							}
						}while(place>Column);
					}
					//printf("k=%d , p=%d, i=%d\n",k,pos,i);
					//printf("\n%c\n",bPlace[i][k]);
					//system("PAUSE");
					empty = check_place_cos(i, k, bPlace);
					if(pos < 1 || pos > (Column*Row)){
						printf("You can only type integers from the field [1,%d].\n",(Column*Row));
					}
					else if(!empty){
						printf("Position is not empty.Type a valid place.\n");
					}
					else{
						bPlace[i][k] = cSymbol;
						continue;
					}
					
				}while(!empty || pos < 1 || pos > (Column*Row));
				system("cls");
				turn = 1;
			}
			
		}
		
		costumeB(bPlace);
		game_end = Game_End_Custome(bPlace, &symb);
	}
}

void CustomGame(int Row, int Column, char bPlace[Row][Column]){
	int i,j,k=0,e=0,place;
	char symb='l';
	
	printf("Type X or O to select a symbol to place, or S to stop and start the game.\n");
	while(symb != 'S'){
		e=0;
		while(e==0){
			printf("1.Choice:");
			scanf(" %c",&symb);
			printf("\n");
			
			if(symb == 'x'){
				symb = 'X';
			}
			else if(symb == 'o'){
				symb = 'O';
			}
			else if(symb == 's'){
				symb = 'S';
			}
			
			if(symb!='X' && symb!='O' && symb!='S'){
				printf("Error.Type only X,O,S\n");
			}
			else{
				e=1;
			}
		}
		printf("\n\noke\n\n");
		system("PAUSE");
		
		place=0;
		if(symb != 'S'){
			while(place >= 0){
				system("cls");
				costumeB(bPlace);
				
				k=0;
				i=0;
				printf("Type a number between 1-%d to put the symbol you have chosen or type a negative number if you want to change symbol or quit\n",Row*Column);
				do{
					printf("Choice:");
					scanf("%d",&place);
					printf("\n");
					
					if(place > (Column*Row)){
						printf("Error.You must type a number lower than %d",Row*Column);
					}
					
				}while(place > (Column*Row));
				place = place-1;
				
				if(place >= 0){
					if(place <= Column){
						//printf("bp=%c\n",bPlace[0][place]);
						k=0;
						bPlace[k][place] = symb;
					}
					else {
						do{
							k = place - Column;
							i++;
							//printf("k=%d , p=%d\n",k,place);
							//system("PAUSE");
							if(k <= Column){
								bPlace[i][k] = symb;
								//printf("i=%d , k=%d, bPlace[i][k]=%c\n",i,k,bPlace[i][k]);
								break;
							}
							else{
								place=k;
								k=0;
							}
						}while(place>Column);
					}
				}
				else{
					system("cls");
					printf("Type X or O to select a symbol to place, or S to stop.\n");
				}
			}
		}	
	}
}

bool Game_End(char bPlace[9], char *symb){
	bool game_end = false;
	
	
	if(bPlace[0] == bPlace[1] && bPlace[1] == bPlace[2]){
		game_end = true;
		*symb = bPlace[2];
	}
	else if(bPlace[2] == bPlace[5] && bPlace[5] == bPlace[8]){
		game_end = true;
		*symb = bPlace[5];
	}
	else if(bPlace[0] == bPlace[3] && bPlace[3] == bPlace[6]){
		game_end = true;
		*symb = bPlace[3];
	}
	else if(bPlace[3] == bPlace[4] && bPlace[4] == bPlace[5]){
		game_end = true;
		*symb = bPlace[4];
	}
	else if(bPlace[6] == bPlace[7] && bPlace[7] == bPlace[8]){
		game_end = true;
		*symb = bPlace[7];
	}
	else if(bPlace[1] == bPlace[4] && bPlace[4] == bPlace[7]){
		game_end = true;
		*symb = bPlace[4];
	}
	else if(bPlace[0] == bPlace[4] && bPlace[4] == bPlace[8]){
		game_end = true;
		*symb = bPlace[4];
	}
	else if(bPlace[2] == bPlace[4] && bPlace[4] == bPlace[6]){
		game_end = true;
		*symb = bPlace[4];
	}
	else if(bPlace[0] != '1'&& bPlace[1] != '2' && bPlace[2] != '3' && bPlace[3] != '4' && bPlace[4] != '5'&& bPlace[5] != '6' && bPlace[6] != '7' && bPlace[7] != '8' && bPlace[8] != '9'){
		game_end = true;
		*symb = 'D';
	}
	
	
	return game_end;
}

bool Game_End_Custome(char bPlace[Row][Column], char *symb){
	bool end = false;
	int i,j,k=0;
	
	for(i=0; i<Row; i++){
		for(j=0; j<Column; j++){
			//printf("i=%d , row=%d , t/f=%d , bPlace[i][j]=%c\n",i,Row,((bPlace[i][j] == 'X' || bPlace[i][j]=='O') && i<Row-2),bPlace[i][j]);
			//printf("i=%d , row=%d ,       , bPlace[i+1][j]=%c\n",i,Row,bPlace[i+1][j]);
			//printf("i=%d , row=%d ,       , bPlace[i+2][j]=%c\n",i,Row,bPlace[i+2][j]);
			if((bPlace[i][j] == 'X' || bPlace[i][j] == 'O') && j<Column-2){
				//printf("%c , j+2=%d\n",bPlace[i][j+2],j+2);
				//system("PAUSE");
				
				//For horizontal
				if(bPlace[i][j+1] == bPlace[i][j] && bPlace[i][j+2] == bPlace[i][j]){
					*symb = bPlace[i][j];
					end = true;
					break;
				}
			}
			//den mpainei else if, dioti meta den poianei kapoiew periptwseis. Px se 3x3 den pianei gia i=0
			if((bPlace[i][j] == 'X' || bPlace[i][j] == 'O') && i<Row-2){
				//printf("i=%d , row=%d , bPlace[i+2][j]=%c, t/f=%d\n",i,Row,bPlace[i+2][j],(bPlace[i+1][j] == bPlace[i][j] && bPlace[i+2][j] == bPlace[i][j]));
				//system("PAUSE");
				
				//For Vertical
				if(bPlace[i+1][j] == bPlace[i][j] && bPlace[i+2][j] == bPlace[i][j]){
					*symb = bPlace[i][j];
					end = true;
					break;
				}
			}
			
			if((bPlace[i][j] == 'X' || bPlace[i][j] == 'O') && (i<Row-2 && j<Column-2)){
				//For diagonal left-top / right-bottom
				if(bPlace[i][j] == bPlace[i+1][j+1] && bPlace[i][j] == bPlace[i+2][j+2]){
					*symb = bPlace[i][j];
					end = true;
					break;
				}
			}
			
			if(((bPlace[i][j] == 'X' || bPlace[i][j] == 'O') && (i<Row-2 && j>1))){
				//For diagoal left-bottom / right-top
				if(bPlace[i][j] == bPlace[i+1][j-1] && bPlace[i][j] == bPlace[i+2][j-2]){
					*symb = bPlace[i][j];
					end = true;
					break;
				}
			}
		}
		if(end == true){
			break;
		}
	}
	
	if(end != true){
		for(i=0; i<Row; i++){
			for(j=0; j<Column; j++){
				if(bPlace[i][j]=='X' || bPlace[i][j]=='O'){
					k++;
				}
				else{
					break;
				}
			}
			if(k<Column*i){
				break;
			}
		}
	}
	
	//printf("\nsymb=%c\n",*symb);
	//system("PAUSE");
	
	if(k == Row*Column){
		end = true;
		*symb = 'D';
	}
	
	
	//printf("symb=%c\n",*symb);
	//printf("k=%d, ro*col=%d\n",k,Row*Column);
	//system("PAUSE");
	
	//printf("%d\n",end);
	//system("PAUSE");
	
	return end;
}

bool check_place(int place, char bPlace[9]){
	bool check;
	
	if(bPlace[place-1] == 'X' || bPlace[place-1] == 'O'){
		check = false;
	}
	else{
		check = true;
	}
	
	
	return check;
}

bool check_place_cos(int place, int pos, char bPlace[Row][Column]){
	bool check;
	
	//printf("k=%d , p=%d\n",place,pos);
	//printf("\n\nbP=%c\n",bPlace[place][pos]);
	//system("PAUSE");
	
	if(bPlace[place][pos] == 'X' || bPlace[place][pos] == 'O'){
		check = false;
	}
	else{
		check = true;
	}
	
	//printf("%d",check);
	//system("PAUSE");
	return check;
}

int AI(char bPlace[9], int tturn, char pSymbol, char cSymbol){
	int place, i, Ppos=10, Cpos=10, Symb, count;
	bool loss = false;
	
	
	if(tturn == 0){
		place = 2;
	}
	else if(tturn == 1){
		if(bPlace[0] == pSymbol){
			place = 4;
		}
		else if(bPlace[2] == pSymbol){
			place = 4;
		}
		else if(bPlace[6] == pSymbol){
			place = 4;
		}
		else if(bPlace[8] == pSymbol){
			place = 4;
		}
		else if(bPlace[4] == pSymbol){
			place = 0;
		}
		else if(bPlace[1] == pSymbol || bPlace[3] == pSymbol){
			place = 0;
		}
		else if(bPlace[5] == pSymbol || bPlace[7] == pSymbol){
			place = 8;
		}
		
	}
	else{
		Ppos = AIaboutWinLose(pSymbol, bPlace, &count); 
		Cpos = AIaboutWinLose(cSymbol, bPlace, &count);
		if(Cpos != 10){
			place = Cpos;
		}
		else if(Ppos != 10){
			place = Ppos;
		}
		else{
			place = AIchoice(bPlace, pSymbol, cSymbol);
		}
	}
	
	
	
	
	return place;
}

int AIaboutWinLose(char Symbol, char virTable[9], int *tcount){
	int i, j, k, pos=10, count=0, samepl = 10;
	char nSymbol;
	
	if(Symbol == 'X'){
		nSymbol = 'O';
	}
	else{
		nSymbol = 'X';
	}
	
	for(i=0; i<9; i++){
		if(virTable[i] == Symbol){
			for(j=0; j<9; j++){
				if(virTable[j] == Symbol && j > i){
					switch(j){
						case 1:
							if(virTable[2] != nSymbol){
								pos = 2;
							}
							else{
								continue;
							}
							break;
							
						case 2:
							if(virTable[1] == nSymbol || virTable[0] == nSymbol){
								continue;
							}
							else{
								if(virTable[1] == Symbol){
									pos = 0;
								}
								else if(virTable[0] == Symbol){
									pos = 1;
								}
								else{
									continue;
								}
							}
							break;
							
						case 3:
							if(virTable[0] == Symbol && virTable[6] == nSymbol){
								continue;
							}
							else if(virTable[0] == Symbol && virTable[6] != nSymbol){
								pos = 6;
							}
							else{
								continue;
							}
							break;
							
						case 4:
							for(k=0; k<4; k++){
								if(virTable[k] == Symbol && virTable[8-k] != nSymbol){
									pos = 8-k;
								}
								else{
									continue;
								}
							}
							break;
							
						case 5:
							if(virTable[2] == Symbol && virTable[8] != nSymbol){
								pos = 8;
							}
							else if(virTable[3] == nSymbol || virTable[4] == nSymbol){
								continue;
							}
							else{
								if(virTable[3] == Symbol){
									pos = 4;
								}
								else if(virTable[4] == Symbol){
									pos = 3;
								}
								else{
									continue;
								}
							}
							break;
							
						case 6:
							if(virTable[0] == Symbol && virTable[3] != nSymbol){
								pos = 3;
							}
							else if(virTable[3] == Symbol && virTable[0] != nSymbol){
								pos = 0;
							}
							else if(virTable[2] == Symbol && virTable[4] != nSymbol){
								pos = 4;
							}
							else if(virTable[4] == Symbol && virTable[2] != nSymbol){
								pos = 2;
							}
							else{
								continue;
							}
							break;
							
						case 7:
							if(virTable[6] == Symbol && virTable[8] != nSymbol){
								pos = 8;
							}
							else if(virTable[4] == nSymbol || virTable[1] == nSymbol){
								continue;
							}
							else{
								if(virTable[4] == Symbol){
									pos = 1;
								}
								else if(virTable[1] == Symbol){
									pos = 4;
								}
								else{
									continue;
								}
							}
							break;
							
						case 8:
							if(virTable[0] == Symbol && virTable[4] != nSymbol){
								pos = 4;
							}
							else if(virTable[2] == Symbol && virTable[5] != nSymbol){
								pos = 5;
							}
							else if(virTable[4] == Symbol && virTable[0] != nSymbol){
								pos = 0;
							}
							else if(virTable[5] == Symbol && virTable[2] != nSymbol){
								pos = 2;
							}
							else if(virTable[6] == Symbol && virTable[7] != nSymbol){
								pos = 7;
							}
							else if(virTable[7] == Symbol && virTable[6] != nSymbol){
								pos = 6;
							}
							else{
								continue;
							}
							
							break;
							
					}
				}
				
				if(pos != 10 && pos != samepl){
					count++;
					samepl = pos;
				}
				else{
					continue;
				}
			}
		}
	}
	
	*tcount = count;
	
	return pos;
}


int AIchoice(char table[9], char pSymbol, char cSymbol){
	char virTable[9];
	int i, j, pos=10, ppos[9], cpos[9], PPOS=10, CPOS=10, canpl[9][9], ptimes=0, ctimes=0, bestPos=0;
	
	//srand(time(0));
	
	
	for(i=0; i<9; i++){
		virTable[i] = table[i];
		if(virTable[i] == pSymbol){
			ppos[i] = i;
			cpos[i] = 10;
		}
		else if(virTable[i] == cSymbol){
			cpos[i] = i;
			ppos[i] = 10;
		}
		else{
			cpos[i] = 10;
			ppos[i] = 10;
		}
		for(j=0; j<9; j++){
			canpl[i][j] = 10;
		}
	}
	
	for(i=0; i<9; i++){
		/*for(j=0; j<9; j++){
			printf("ppos=%d , cpos=%d\n",ppos[j],cpos[j]);
		}
		printf("\n\n");*/
		if(i == ppos[i] || i == cpos[i]){
			continue;
		}
		else{
			cpos[i] = i;
			virTable[i] = cSymbol;
			CPOS = AIaboutWinLose(cSymbol,virTable,&ctimes);
			//printf("i=%d, CPOS=%d\n",i,CPOS);
			//system("PAUSE");
			if(ctimes > 1){
				pos = i;
				break;
			}
			else if(CPOS != 10){
				ppos[CPOS] = CPOS;
				virTable[CPOS] = pSymbol;
				PPOS = AIaboutWinLose(pSymbol,virTable,&ptimes);
				if(ptimes > 1){
					printf("in i=%d\n",i);
					cpos[i] = 10;
					ppos[CPOS] = 10;
					virTable[i] = i + '0';
					virTable[CPOS] = CPOS + '0';
					continue;
				}
				else if(PPOS != 10){
					canpl[i][0] = i;
					canpl[i][1] = 2;
					
					cpos[i] = 10;
					ppos[CPOS] = 10;
					virTable[i] = i + '0';
					virTable[CPOS] = CPOS + '0';
				}
				else{
					canpl[i][0] = i;
					canpl[i][1] = 3;
					cpos[i] = 10;
					ppos[CPOS] = 10;
					virTable[i] = i + '0';
					virTable[CPOS] = CPOS + '0';
				}
			}
			else{
				for(j=0; j<9; j++){
					if(j != ppos[j] && j != cpos[j]){
						ppos[j] = j;
						virTable[j] = pSymbol;
						PPOS = AIaboutWinLose(pSymbol,virTable,&ptimes);
						if(ptimes > 1){
							printf("else in i-%d\n",i);
							cpos[i] = 10;
							ppos[j] = 10;
							virTable[i] = i + '0';
							virTable[j] = j + '0';
							canpl[i][0] = 10;
							canpl[i][1] = 10;
							break;
						}
						else if(PPOS != 10){
							canpl[i][0] = i;
							canpl[i][1] = 2;
						
							cpos[i] = 10;
							ppos[j] = 10;
							virTable[i] = i + '0';
							virTable[j] = j + '0';
						}
						else{
							canpl[i][0] = i;
							canpl[i][1] = 1;
						
							cpos[i] = 10;
							ppos[j] = 10;
							virTable[i] = i + '0';
							virTable[j] = j + '0';
						}
					}
					printf("canpl[i][1]=%d ,i=%d",canpl[i][1],i);
				}
			}
		}
	}
	
	for(i=0; i<9; i++){
		printf("Before -- i=%d, canpl[i][1]=%d, bestPos=%d, pos=%d, canpl[i][0]=%d\n",i,canpl[i][1],bestPos,pos,canpl[i][0]);
		if(canpl[i][1] > bestPos && canpl[i][1] != 10){
			bestPos = canpl[i][1];
			pos = canpl[i][0];
		}
		printf("After -- i=%d, canpl[i][1]=%d, bestPos=%d, pos=%d, canpl[i][0]=%d\n",i,canpl[i][1],bestPos,pos,canpl[i][0]);
		system("PAUSE");
	}
	
	
	return pos;
}

