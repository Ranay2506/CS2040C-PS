// Copy paste this C++ Template and save it as "BabyNames.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here:
// write your name here:
// write list of collaborators here:
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

int convertChar(char x) {
  switch(x) {
    case 'A':
      return 0;
    case 'B':
      return 1;
    case 'C':
      return 2;
    case 'D':
      return 3;
    case 'E':
      return 4;
    case 'F':
      return 5;
    case 'G':
      return 6;
    case 'H':
      return 7;
    case 'I':
      return 8;
    case 'J':
      return 9;
    case 'K':
      return 10;
    case 'L':
      return 11;
    case 'M':
      return 12;
    case 'N':
      return 13;
    case 'O':
      return 14;
    case 'P':
      return 15;
    case 'Q':
      return 16;
    case 'R':
      return 17;
    case 'S':
      return 18;
    case 'T':
      return 19;
    case 'U':
      return 20;
    case 'V':
      return 21;
    case 'W':
      return 22;
    case 'X':
      return 23;
    case 'Y':
      return 24;
    case 'Z':
      return 25;
  }
}

set<string> malename[26];
set<string> femalename[26];
map<string,int> linkmap;
void AddSuggestion(string babyName, int genderSuitability){
  // write your answer here
  int index = convertChar(babyName[0]);
  if(genderSuitability == 1) {
    ::malename[index].insert(babyName);
  } else {
    ::femalename[index].insert(babyName);
  }
  ::linkmap[babyName] = genderSuitability;
  
} 

void RemoveSuggestion(string babyName){
  int index = convertChar(babyName[0]);
  if(::linkmap[babyName] == 1) {
    ::malename[index].erase(babyName);
  } else {
    ::femalename[index].erase(babyName);
  }
  ::linkmap.erase(babyName);
}

int Query(string START, string END, int gender){
  int ans = 0;
  // write your answer here
  int first = convertChar(START[0]);
  int last = convertChar(END[0]);

  if(gender == 0) {
    if(first != last) {
      ans += distance(::malename[first].lower_bound(START),::malename[first].end());
      ans += distance(::femalename[first].lower_bound(START),::femalename[first].end());
      for(int i = first+1; i < last; i++) {
        ans += ::malename[i].size();
        ans += ::femalename[i].size();
      }
      ans += distance(::malename[last].begin(),::malename[last].lower_bound(END));
      ans += distance(::femalename[last].begin(),::femalename[last].lower_bound(END));
    } else {
      ans += distance(::malename[first].lower_bound(START),::malename[first].lower_bound(END));
      ans += distance(::femalename[first].lower_bound(START),::femalename[first].lower_bound(END));
    }
  } else if(gender == 1) {
    if(first != last) {
      ans += distance(::malename[first].lower_bound(START),::malename[first].end());
      for(int i = first+1; i < last; i++) {
        ans += ::malename[i].size();
      }
      ans += distance(::malename[last].begin(),::malename[last].lower_bound(END));
    } else {
      ans += distance(::malename[first].lower_bound(START),::malename[first].lower_bound(END));
    }
  } else {
    if(first != last) {
      ans += distance(::femalename[first].lower_bound(START),::femalename[first].end());
      for(int i = first+1; i < last; i++) {
        ans += ::femalename[i].size();
      }
      ans += distance(::femalename[last].begin(),::femalename[last].lower_bound(END));
    } else {
      ans += distance(::femalename[first].lower_bound(START),::femalename[first].lower_bound(END));
    }
  }
  return ans;
}

int main(){
  while(true) {
    int cmd = 0, genderSuitability;
    char babyName[32], START[32], END[32];
    scanf("%d", &cmd);
    if (cmd == 0) break;
    else if(cmd == 1) {
      scanf("%s%d", babyName, &genderSuitability);
      AddSuggestion(string(babyName), genderSuitability);
    }
    else if(cmd == 2) {
      scanf("%s", babyName);
      RemoveSuggestion(string(babyName));
    }
    else if(cmd == 3) {
      scanf("%s%s%d", START, END, &genderSuitability);
      int ans = Query(string(START), string(END), genderSuitability);
      printf("%d\n", ans);
    }
  }
  return 0;
}