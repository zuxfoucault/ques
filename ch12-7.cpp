#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

class student{
	public:
		~student();
		int stu_size();
		void showdata();

	private:
		struct stu{
			char stu_id[12];
			int ScoreComputer;
			int ScoreMath;
			int ScoreEng;
			float ScoreAvg;
		};
		stu Entry;
};

student::~student(){
	cout << "deleting one object of student class\n";
}

int student::stu_size(){
	return sizeof(stu);
}

void student::showdata(){
	cout << Entry.stu_id << "\t" << Entry.ScoreComputer << "\t" \
		<< Entry.ScoreMath << "\t" << Entry.ScoreEng << "\t";
	cout << setprecision(4) << Entry.ScoreAvg << endl;
}

FILE *fp;

int main(){
	student *IM;
	IM = new student[10];
	int i;

	if((fp = fopen("data4", "rb")) == NULL){
		cout << "error!" << endl;
		exit(0);
	}

	int num = fread(IM, sizeof(student), 2, fp);
	fclose(fp);

	cout << "Binary file retrieved. First two students' data as following:\n";

	for(i = 0; i < 2; i++){
		IM[i].showdata();
	}
	delete [] IM;
}
