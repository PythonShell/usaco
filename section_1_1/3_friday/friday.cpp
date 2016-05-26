/*
ID: pythons1
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void AddYear(int year, int *days);
bool IsLeapYear(int year);
int DaysFromNewYear(int year, int month, int day);
int DaysBetweenDate(int y1, int m1, int d1, int y2, int m2, int d2);

int main() {
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int n;
  int days[7] = {0, 0, 0, 0, 0, 0, 0};
  fin >> n;
  for(int i=1900; i<1900+n; i++)
    AddYear(i, days);
  for(int i=0; i<6; i++)
    fout << days[i] << " ";
  fout << days[6] << endl;
  return 0;
}

void AddYear(int year, int *day) {
  for(int i=0; i<12; i++) {
    int days = DaysBetweenDate(1900, 1, 1, year, i+1, 13);
    int num = days % 7;
    switch(num) {
      case 0: day[2] +=1; break;
      case 1: day[3] +=1; break;
      case 2: day[4] +=1; break;
      case 3: day[5] +=1; break;
      case 4: day[6] +=1; break;
      case 5: day[0] +=1; break;
      case 6: day[1] +=1; break;
    }
  }
}

int DaysBetweenDate(int y1, int m1, int d1, int y2, int m2, int d2) {
  int days = DaysFromNewYear(y2, m2, d2) - DaysFromNewYear(y1, m1, d1);
  if(y1 == y2)
    return days;
  else if(y1 < y2) {
    for(int i=y1; i<y2; i++) {
      if(IsLeapYear(i))
        days += 366;
      else
        days += 365;
    }
    return days;
  }
  else {
    for(int i=y2; i<y1; i++) {
      if(IsLeapYear(i))
        days -= 366;
      else
        days -= 365;
    }
    return days;
  }
}

int DaysFromNewYear(int year, int month, int day) {
  int dayArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days = day-1;
  for(int i=0; i<month-1; i++)
    days += dayArr[i];
  if(IsLeapYear(year) && month>2)
    return days+1;
  else
    return days;
}

bool IsLeapYear(int year) {
  if(year%400 == 0)
    return true;
  else if(year%100 == 0)
    return false;
  else if(year%4 == 0)
    return true;
  else
    return false;
}
