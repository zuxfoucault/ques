#include <iostream>
#include <iomanip>
#include <stdio.h>

struct student{
	char stu_id[12];
	int ScoreComputer;
	int ScoreMath;
	int ScoreEng;
	float ScoreAvg;
};

void display(student tempStu);
void BubbleSort(student *arr, int arr_index);

void display(student tempStu){
	std::cout << tempStu.stu_id << "\t" << tempStu.ScoreComputer << "\t" << tempStu.ScoreMath \
		  << "\t" << tempStu.ScoreEng << "\t";
	std::cout << std::setprecision(4) << tempStu.ScoreAvg << std::endl;
}

void BubbleSort(student *arr, int arr_index){
	int k, times, i;
	student temp;
	k = arr_index - 1;
	while(k != 0){
		times=0;
		for(i = 0; i <= k-1; i++){
			if(arr[i].ScoreComputer > arr[i+1].ScoreComputer){
				temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp; //interchange arr[i] and arr[i+1]
				times = i;
			}
		}
		k = times;
	}
}

FILE *fp;

int main(){
	int score[3][3] = {{89, 84, 75}, 
			   {77, 69, 87}, 
			   {65, 68, 77}};
	struct student IM[3];
	int i, Total;

	strcpy(IM[0].stu_id, "S9103501");
	strcpy(IM[1].stu_id, "S9103502");
	strcpy(IM[2].stu_id, "S9103503");
	for(i=0; i<3; i++){
		Total=0;
		IM[i].ScoreComputer = score[i][0];
		IM[i].ScoreMath = score[i][1];
		IM[i].ScoreEng = score[i][2];
		Total = score[i][0] + score[i][1] + score[i][2];
		IM[i].ScoreAvg = float(Total)/3;
	}

	if((fp = fopen("data4", "w+b")) == NULL){
		std::cout << "file error\n";
		exit(0);
	}

	int num = fwrite(IM, sizeof(student), 3, fp);

	std::cout << "Binary code write up!\n";
	fclose(fp);
/*	
	std::cout << "ID\t   Computer\t Math\t English\t Average\t (pre-sorting)" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	for(i=0; i<3; i++){
		display(IM[i]);
	}

	BubbleSort(IM, 3);
	std::cout << "ID\t Computer\t Math\t English\t Average\t (post-sorting)" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	for(i=0; i<3; i++){
		display(IM[i]);
	}
*/
}
