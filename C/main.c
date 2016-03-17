#include <stdio.h>
#include <stdlib.h>
#define Size 30
//#define Empty -1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int ASCII0=48;
int Table[Size][Size],PntTable[Size],VSTable[Size][2];Result[Size];
int main(int argc, char *argv[]) {
	int i,gain,dif;
	open_file();
	modify_PntTable();
	open_file();
	modify_VSTable();

	for(i=0;i<=Size;i++){
		dif=0;gain=0;
		if(VSTable[i][0]!=NULL){
			dif=PntTable[VSTable[i][0]]-PntTable[VSTable[i][1]];

			if(dif<=0){
				dif=dif-2*dif;
				gain=lose(dif);
			}
			else gain=win(dif);
			Result[VSTable[i][0]]=Result[VSTable[i][0]]+gain;
			Result[VSTable[i][1]]=Result[VSTable[i][1]]-gain;
		}
		else break;
	}
	output_file();
	//restart();
	system("pause");
	return 0;
}
void open_file(void) {
	FILE *fp;
	int i,count=0;
	char fname[50],line[Size];
	/*Enter a file name*/
	printf("Enter a file:");
	gets(fname);
	/*convert txt to array*/
	fp = fopen(fname, "r");
	if(fp!=NULL) {
		printf("Opening file:[%s]\n", fname);
		while(fgets(line,Size,fp)!=NULL) {
			//printf("%s",line);
			for(i=0; i<Size; i++) {
				Table[count][i]=line[i];
			}
			count++;
		}
		fclose(fp);
	}
	else{
		printf("Open [%s] file fail.", fname);
		exit(1);
	}
	printf("\n");
}
void output_file(void){
	FILE *fp;
	char fname[20]="result.txt";
	int i;
	fp=fopen(fname, "w");
	if(fp!=NULL){
		for(i=1;i<Size;i++){
			fprintf(fp, "%d\n",Result[i]);
			printf("%d gain %d\n",i,Result[i]);
		}
		fclose(fp);
	}else printf("Open [%s] file fail.", fname);
}
void modify_PntTable(void){
	int i,j,n=1,sum=0;
	/*Convert ASCII to integer and remove the control characters*/
	for(i=0;i<Size;i++){
		for(j=0;j<Size;j++){
			if(Table[i][j]!=0){
				if(Table[i][j]>=ASCII0 && Table[i][j]<=ASCII0+9)
					sum=sum*10+Table[i][j]-ASCII0;	//For the value is bigger than 10
				else{
					PntTable[n]=sum;
					sum=0;
					n++;
				}
			}
			else break;
		}
	}
	for(;n<Size;n++)PntTable[n]=NULL;	//Fill "Empty" to unused space
	for(i=0;i<Size;i++)printf("%d.%d \n",i,PntTable[i]);
	//printf("\n");
}
void modify_VSTable(void){
	int i,j,n,sum=0;
	/*Convert ASCII to integer and remove the control characters*/
	for(i=0;i<Size;i++){
		n=0;
		for(j=0;j<Size;j++){
			if(Table[i][j]!=0){
				if(Table[i][j]>=ASCII0 && Table[i][j]<=ASCII0+9)
					sum=sum*10+Table[i][j]-ASCII0;	//For the value is bigger than 10
				else{
					VSTable[i][n]=sum;
					sum=0;
					n++;
				}
			}
			else break;
		}
		for(;n<Size;n++)VSTable[i][n]=NULL;	//Fill "Empty" to unused space
	}
	for(i=0;i<Size;i++){
		printf("%d.%d ",i,VSTable[i][0]);
		printf("%d \n",VSTable[i][1]);
	}
	printf("\n");
}
int win(int dif){
	int n;
	if(dif>=0 && dif<=12)n=8;
	if(dif>=13 && dif<=37)n=7;
	if(dif>=38 && dif<=62)n=6;
	if(dif>=63 && dif<=87)n=5;
	if(dif>=88 && dif<=112)n=4;
	if(dif>=113 && dif<=137)n=3;
	if(dif>=138 && dif<=162)n=2;
	if(dif>=163 && dif<=187)n=2;
	if(dif>=188 && dif<=212)n=1;
	if(dif>=213 && dif<=237)n=1;
	if(dif>=238)n=0;
	return n;
}
int lose(int dif){
	int n;
	if(dif>=0 && dif<=12)n=8;
	if(dif>=13 && dif<=37)n=10;
	if(dif>=38 && dif<=62)n=13;
	if(dif>=63 && dif<=87)n=16;
	if(dif>=88 && dif<=112)n=20;
	if(dif>=113 && dif<=137)n=25;
	if(dif>=138 && dif<=162)n=30;
	if(dif>=163 && dif<=187)n=35;
	if(dif>=188 && dif<=212)n=40;
	if(dif>=213 && dif<=237)n=45;
	if(dif>=238) n=50;
	return n;
}
