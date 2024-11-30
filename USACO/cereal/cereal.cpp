#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int>> cerealOrder;
vector <int> pos, ans;
int curAns = 0;
/*void adjust(int i, int curCereal){
    //sayng that the foremost cow's first choice is already taken, must adjust
    //curCereal = cerealOrder[i].first (at first)
    if (curCereal == cerealOrder[pos[curCereal]].first){
        //if statment saying the already taken cow first choice aswell
        //then taken cow must choose 2nd choice
        //only taken action tho, if the position of the 2nd choice cow is after, not before
        if (pos[cerealOrder[pos[curCereal]].second] == -1) {
            curAns++;
            pos[cerealOrder[pos[curCereal]].second] = pos[curCereal];
            pos[curCereal] = i;
        }

        else if (pos[cerealOrder[pos[curCereal]].second] > pos[curCereal]){
            //sayiing that the position of the displaced cereal (from og) is less
            //than the cereal already at that position
            int temp = pos[curCereal];
            adjust(temp, cerealOrder[temp].second);
            pos[curCereal] = i;

        } else{
            pos[curCereal] = i;
        }
    } else if (curCereal == cerealOrder[pos[curCereal]].second){
        //taken cow is cooked, cant do anything execpt be sad ;(
        pos[curCereal] == i;
    }
}*/ //code not working and gave up
int main(){
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cerealOrder.resize(n);
    pos.resize(m + 1, -1);
    ans.resize(n);
    for (int i = 0; i < n; i++){
        cin >> cerealOrder[i].first >> cerealOrder[i].second;
    }
    //start from N cow, then just keep on adding
    //CANNOT be O(n^2) as every cow can atmost be adjusted 2x
    //so time complexity is around O(2n)
    /*for (int i = n - 1; i>= 0; i--){
        if (pos[cerealOrder[i].first] == -1){
            curAns++;
            pos[cerealOrder[i].first] = i;
        } else{
            adjust(i, cerealOrder[i].first);
        }
        ans[i] = curAns;
    }*/
    for (int i = n - 1; i >= 0; i--){
        //current cow will always get their first
        int curPos = cerealOrder[i].first;
        int j = i;
        //sets curPos = cow i's first choice
        //sets j = i
        while (true){
            if (pos[curPos] == -1){ //if unoccupied, then easy
                //updates ans and sets pos[curPos] = j;
                curAns++;
                pos[curPos] = j;
                break;
            } else if (pos[curPos] < j){ //checks priorty and sees if can kick out
                //cow j becomes after the cow at pos[curPos]
                break; 
            } else{
                int next = pos[curPos]; //index of previous cow, need to replace this
                pos[curPos] = j;
                if (cerealOrder[next].second == curPos){ //saying that this was 2nd choice, so this cow done
                    break;
                }
                j = next;
                curPos = cerealOrder[next].second;
                
            }
        }
        ans[i] = curAns;
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << "\n";
    }
}