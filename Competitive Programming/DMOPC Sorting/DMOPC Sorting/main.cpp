#include <bits/stdc++.h>
using namespace std;
int N;
int ans, maxi;
unordered_set <string> dict;
int main (){
    cin.tie(0); cin.sync_with_stdio(0);
    vector<string> dict;
    cin >> N;
    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        dict.push_back (s);
    }
    for (int i = 0; i < 10; i++){
        string name;
        cin >> name;
        ans = 0;
        for (int j = 0; j < name.size(); j++){
            maxi = 0;
            for (int k = 0; k < dict.size(); k++){
                if (dict[k] == name.substr(j, dict[k].size())){
                    if (maxi < dict[k].size()){
                        maxi = dict[k].size();
                    }
                }
            }
            j += maxi-1;
            ans++;
        }
        cout << ans-1 << endl;
    }
    
}
