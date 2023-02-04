
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int xc, yc;
    int ec = 0, nc = 0;
    char d;
    int east[50][2], north[50][2];
    vector <int> ni, ei;
    vector <vector <int>> world_time;
    vector <char> stopped_dir;
    int stopped_east[100], stopped_north[100];
    char fix[100];
    for (int i = 0; i < n; i++) {
        stopped_east[i] = INT_MAX;
        stopped_north[i] = INT_MAX;
        cin >> d >> xc >> yc;
        fix[i] = d;
        if (d == 'E'){ 
            east[ec][0] = xc; east[ec][1] = yc; ec++;
        }
        else{
            north[nc][0] = xc; north[nc][1] = yc; nc++;
        }
    }

    //find all possible intersections
    for (int i = 0; i < nc; i++) {
        for (int x = 0; x < ec; x++) {
            if (north[i][0] > east[x][0] && east[x][1] > north[i][1]) { // intersects
                if (north[i][0] - east[x][0] > east[x][1] - north[i][1]) {
                    world_time.push_back({ north[i][0] - east[x][0], east[x][1] - north[i][1] });
                    ni.push_back(i); ei.push_back(x);
                    stopped_dir.push_back('E');
                }
                else if (north[i][0] - east[x][0] < east[x][1] - north[i][1]) {
                    world_time.push_back({ east[x][1] - north[i][1], north[i][0] - east[x][0] });
                    ni.push_back(i); ei.push_back(x);
                    stopped_dir.push_back('N');
                }
            }
        }
    }
    /*for (int i = 0; i < world_time.size(); i++) {
        cout << world_time[i][0] << " " << world_time[i][1] << " " << ni[i] << " " << ei[i] << stopped_dir[i] << endl;
    }*/
    //cout << endl;
    //sort world_time and affilated values
    for (int i = 0; i < world_time.size(); i++) {
        for (int x = 0; x < world_time.size() - 1; x++) {
            if (world_time[x][0] > world_time[x + 1][0]) {
                swap(world_time[x][0], world_time[x + 1][0]);
                swap(world_time[x][1], world_time[x + 1][1]);
                swap(ni[x], ni[x + 1]); swap(ei[x], ei[x + 1]);
                swap(stopped_dir[x], stopped_dir[x + 1]);
            }
        }
    }
    /*for (int i = 0; i < world_time.size(); i++) {
        cout << world_time[i][0] << " " << world_time[i][1] << " " << ni[i] << " " << ei[i] << stopped_dir[i] << endl;
    }
    cout << endl;*/
    
    for (int i = 0; i < world_time.size(); i++) {
        //cout << ni[i] << " " << ei[i] << endl;
        //cout << stopped_north[ni[i]] << " " << stopped_east[ei[i]] << endl;
        //two cases
        if (stopped_dir[i] == 'E') {
            if (stopped_north[ni[i]] > world_time[i][1] && stopped_east[ei[i]] > world_time[i][0]) {
                stopped_east[ei[i]] = world_time[i][0];
            }
        }
        else {
            if (stopped_north[ni[i]] > world_time[i][0] && stopped_east[ei[i]] > world_time[i][1]) {
                stopped_north[ni[i]] = world_time[i][0];
            }
        }
    }
    
    //cout << endl;
    /*for (int i = 0; i < n; i++) {
        cout << stopped_north[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << stopped_east[i] << endl;
    }*/
    ec = 0; nc = 0;
    int temp;
    for (int i = 0; i < n; i++) {
        if (fix[i] == 'E') { temp = stopped_east[ec]; ec++; }
        else { temp = stopped_north[nc]; nc++; };
        if (temp == INT_MAX) { cout << "Infinity" << endl; }
        else { cout << temp << endl; }
    }
}

