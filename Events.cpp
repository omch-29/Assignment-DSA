#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool can_attend_all(vector<pair<int, int>>& events) {

    sort(events.begin(), events.end());

    for (int i = 1; i < events.size(); i++) {

        // If event overlaps with current event
        if (events[i - 1].second > events[i].first) {
            return false;
        }
    }

    return true;
}
int min_rooms_required(vector<pair<int, int>>& events){
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> pq; //minHeap

    pq.push(events[0].second);

    for (int i = 1;i < events.size();i++){
        if (events[i].first >= pq.top()) {
            pq.pop();
        }
        pq.push(events[i].second);
    }
    return pq.size();
}

int main(){
    vector<pair<int, int>> events = {
        {9, 10},
        {10, 11},
        {11, 12}
    };

    if (can_attend_all(events)) {
        cout << "Can attend all events" << endl;
    } else {
        cout << "Cannot attend all events" << endl;
    }

    cout << "Minimum rooms required: "
         << min_rooms_required(events) << endl;

    return 0;
}