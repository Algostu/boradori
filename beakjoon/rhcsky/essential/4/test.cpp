#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<ios>
#include<iomanip>
using namespace std;

typedef struct student_info{
string name;
double midterm, final;
vector<double> homework;
}info;

double median(vector<double> vec){
//중앙값을 구하는 함수
  typedef vector<double>::size_type vec_sz;
  vec_sz size =vec.size();
  if(size == 0)
    throw domain_error("median of an empty vector");
  sort(vec.begin(),vec.end());  
  vec_sz mid=size/2;
  return size%2==0 ? (vec[mid]+vec[mid-1])/2:vec[mid];
}
double grade(double midterm,double final,double homework){
 //종합점수를 구하는 grade 함수
    return 0.2*midterm+0.4*final+0.4*homework;
}

double grade(double midterm,double final, const vector<double>& hw){ // 벡터를 인수로가지는 두번째 grade
    if(hw.size()==0)
        throw domain_error("student has done no homework");
    // 과제 점수를 따로 구하는 오버로딩 grade함수
    return grade(midterm,final,median(hw)); // 마지막 으로 계산만 해주는 grade
}

double grade(info& s){ // 메인 함수에서 호출되는 grade 
 //종합점수를 구하는 grade 함수
    return grade(s.midterm,s.final,s.homework);
}

istream& read_hw(istream& in , vector<double>& hw){
     if(in){
         //이전 내용을 제거
       hw.clear(); 
       double x;
       while(in>>x)
       hw.push_back(x);
       in.clear(); // 계속 입력할수 있도록 오류 표시를 재설정 함
     }
     return in;
}
istream& read(istream& is , info& s){
    is>> s.name>>s.midterm>> s.final;
    read_hw(is,s.homework);
    return is;
}
bool compare (const info& x,const info& y){
    return x.name<y.name;
}
int main(){
    vector<info> students;
    info record;
    string::size_type maxlen =0;
    while(read(cin,record)){
       maxlen = max(maxlen,record.name.size());
       students.push_back(record);
    }
    sort(students.begin(),students.end(),compare);
    for(vector<info>::size_type i=0; i != students.size();++i){

        cout<< students[i].name<<string(maxlen+1-students[i].name.size(),' ');
        try{
            double final_grade =grade(students[i]);
            streamsize prec = cout.precision();
            cout<< setprecision(3)<< final_grade
            << setprecision(prec);

        }
        catch(domain_error e){
            cout<< e.what();
        }
        cout<<endl;
    }
  }