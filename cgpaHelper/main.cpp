#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <iterator>
using namespace std;
void postErrorToUser(string s){
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<s<<endl;
    cout<<"enter any key to continue"<<endl;
    string temp;
    cin>>temp;
    cout << "\033[2J\033[1;1H";

}
void printTotal(map<string,std::pair<int,int>> subjectsTotal){
    map<string,pair<int,int>>::iterator subjectsTotalIterator;
   for(subjectsTotalIterator=subjectsTotal.begin();subjectsTotalIterator!=subjectsTotal.end();subjectsTotalIterator++){
    cout<<"subjects name "<<subjectsTotalIterator->first<<endl;
    cout<<"subjects current marks "<<subjectsTotalIterator->second.first<<endl;  
    cout<<"subjects total marks "<<subjectsTotalIterator->second.second<<endl;
   }
}

void printMap(map<string,pair<int,int>> subject){
    map<string,pair<int,int>>::iterator subjectIterator;
 for(subjectIterator=subject.begin();subjectIterator!=subject.end();subjectIterator++){
        cout<<"      map first element "<<subjectIterator->first<<endl;
        cout<<"      map second element first p "<<subjectIterator->second.first<<endl;        
        cout<<"      map second element second p "<<subjectIterator->second.second<<endl;
    }
}
void printMap( map<string,map<string,std::pair<int,int>>> subjectsList){
    map<string,map<string,std::pair<int,int>>>::iterator subjectsListlIterator;
    for(subjectsListlIterator=subjectsList.begin();subjectsListlIterator!=subjectsList.end();subjectsListlIterator++){
        cout<<"Multidimentional map first element "<<subjectsListlIterator->first<<endl;
        printMap(subjectsListlIterator->second);
    }
}
int calculateGpa(map<string,map<string,std::pair<int,int>>> subjectsList){
    map<string,map<string,std::pair<int,int>>>::iterator subjectsListlIterator;
       int grade=0;
       int noOfSubjects=0;
    for(subjectsListlIterator=subjectsList.begin();subjectsListlIterator!=subjectsList.end();subjectsListlIterator++){
        map<string,pair<int,int>>::iterator subjectIterator;
        int total=0;
        int userMarks=0;
        int subjectsGrade=0;
        int noOfTets=0;
        for(subjectIterator=subjectsListlIterator->second.begin();subjectIterator!=subjectsListlIterator->second.end();subjectIterator++){
        float percentage=((float)subjectIterator->second.first/subjectIterator->second.second)*100;
        noOfTets++;
        if(percentage>=80.00){
            //o
            subjectsGrade+=10;
        }else if(percentage>=70.00){
            //o
            subjectsGrade+=9;
        }else if(percentage>=60.00){
            //o
            subjectsGrade+=8;
        }else if(percentage>=50.00){
            //o
            subjectsGrade+=7;
        }else if(percentage>=40.00){
            //o
            subjectsGrade+=6;
        }else if(percentage>=35.00){
            //o
            subjectsGrade+=5;
        }else{
            subjectsGrade+=0;
        }   
    }
    grade+=subjectsGrade/noOfTets;
    noOfSubjects++;
    }
    grade=grade/noOfSubjects;
    return grade;
}
int getDataFromUser(){
    cout<<"select 1 for offline conectivity"<<endl;
    cout<<"select 2 for database conectivity(not working)"<<endl;
    cout<<"Select 3 for ending this program"<<endl;
    int temp;
    cin>>temp;
    if(!cin){
        postErrorToUser("You have typed an non-numeric characted Please enter an number");
        return getDataFromUser();
    }
    if(temp!=1&&temp!=2){
        postErrorToUser("You number which is not an one of the mentioned choices Please enter an appropiate number");
        return getDataFromUser();
    }
    cout<<"Enter the number of subjects you have"<<endl;
    int n;
    cin>>n;
     if(!cin){
        postErrorToUser("You have typed an non-numeric characted Please enter an number");
        return getDataFromUser();
    }
    map<string,map<string,std::pair<int,int>>> subjectsList;
    for(int i=0;i<n;i++){
        cout<<"Enter subject no "<<i<<" name"<<endl;
        string subjectsName;
        cin>>subjectsName;
        cout<<"Enter the number of tests you have in "<<subjectsName<<endl;
        int m;
        cin>>m;
        map<string,std::pair<int,int>> subjectsData;
        for(int i=0;i<m;i++){
             cout<<"Enter the test no "<<i+1<<" name"<<endl;
             string currentsTestsName;
             cin>>currentsTestsName;
             cout<<"Enter "<<subjectsName<<" marks for "<<currentsTestsName<<" (enter -1 if not finished marking)"<<endl;
             int currentTestsMarks,currentTestsTotalMarks;
             cin>>currentTestsMarks;
             cout<<"Enter "<<subjectsName<<" total marks for "<<currentsTestsName<<endl;
             cin>>currentTestsTotalMarks;
             std::pair<int,int> pair(currentTestsMarks,currentTestsTotalMarks);
             subjectsData[currentsTestsName]=pair;
        }
        subjectsList[subjectsName]=subjectsData;  
   }
   cout<<calculateGpa(subjectsList);
}
int main(){
  getDataFromUser();   
}