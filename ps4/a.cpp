// Copy paste this C++ Template and save it as "BabyNames.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here:
// write your name here:
// write list of collaborators here:
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

class BabyName {
  public:
    string Name;
    int Gender;

    BabyName(string N,int G) {
      Name = N;
      Gender = G;
    }
    void setname(string N) {
      Name = N;
    }
    friend bool operator< (const BabyName &left, const BabyName &right) {
      return left.Name < right.Name;
    }
};


set<BabyName> nameset;
unordered_map<string,BabyName> linkmap;

void AddSuggestion(string babyName, int genderSuitability){
  // write your answer here
  BabyName bname = BabyName(babyName,genderSuitability);
  ::linkmap.insert(make_pair(babyName,bname));
  ::nameset.insert(bname);
}

void RemoveSuggestion(string babyName){
  // write your answer here
  unordered_map<string,BabyName>::iterator it = ::linkmap.find(babyName);
  ::nameset.erase(it->second);

}

int Query(string START, string END, int gender){
  int ans = 0;
  // write your answer here
  set<BabyName>::iterator low,high;
  unordered_map<string,BabyName>::iterator it;
  BabyName temp = BabyName(START,0);
  low = nameset.lower_bound(temp);
  temp.setname(END);
  high = nameset.upper_bound(temp);
  if(gender == 0) {
    ans = distance(low,high);
  } else if(gender == 1) {
    for(low = low; low != high; low++) {
      it = ::linkmap.find(low->Name);
      if(it->second.Gender < 2) {
        ans++;
      }
    }
  } else {
    for(low = low; low != high; low++) {
      it = ::linkmap.find(low->Name);
      if(it->second.Gender == 2) {
        ans++;
      }
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