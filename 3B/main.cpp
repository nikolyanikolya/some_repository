#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
struct mouse {
    string s="";
    mouse *next;
    mouse *prev;
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    unordered_map<string, mouse> mice;
    string party_maker;
    getline(cin, party_maker, ' ');
    mice[party_maker].s = party_maker;
    int n;
    cin >> n;
    string neighbour;
    string new_visitor;
    mice[party_maker].next=&mice[party_maker];
    mice[party_maker].prev=&mice[party_maker];
    char location;
    for (int i = 0; i < n; i++) {
        cin>> new_visitor;
        cin>> neighbour;
        cin >> location;
        if (location == 'l' && mice[neighbour].prev!= nullptr) {
            mice[new_visitor].s = new_visitor;
            (*mice[neighbour].prev).next = &mice[new_visitor];
            mice[new_visitor].prev = &(*mice[neighbour].prev);
            mice[new_visitor].next = &mice[neighbour];
            mice[neighbour].prev=&mice[new_visitor];
        }
         else if (location == 'r' && mice[neighbour].next!= nullptr) {
            mice[new_visitor].s = new_visitor;
            (*mice[neighbour].next).prev=&mice[new_visitor];
            mice[new_visitor].next = &(*mice[neighbour].next);
            mice[neighbour].next = &mice[new_visitor];
            mice[new_visitor].prev=&mice[neighbour];
        }
    }
    string str = party_maker;
    for (int i=0; i<n+1; i++){
        cout<<mice[str].s<<'\n';
        str = (*mice[str].next).s;
    }
    return 0;
}

