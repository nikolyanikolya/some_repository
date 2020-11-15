#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

struct cmp
{
    bool operator() (const pair<unsigned long long, string>&a, const pair<unsigned long long, string> &b)
    {
        return a.first > b.first;
    }
};

int main()
{
    std::set<pair<unsigned long long, std::string>, cmp>my_set;
    int n;
    std::cin>>n;
    std::unordered_map<std::string, unsigned long long>cities; //город -> суммарный размер денег
    std::unordered_map<std::string, std::pair<std::string, unsigned long long>> billionaires(n);//Миллиардер-> город, состояние
    std::map<std::string, int> count;
    std::string person;
    std::string city;
    unsigned long long wealth;
    for(int i=0; i<n; i++){
        std::cin>>person>>city>>wealth;
        if(!(cities.count(city))){
            cities[city]=wealth;
        }
        else {
            cities[city] += wealth;
        }
        billionaires[person].first=city;
        billionaires[person].second=wealth;
        count[city]=0;
    }

    for(auto it =cities.begin(); it!=cities.end(); it++){
        my_set.insert(make_pair(it->second, it->first));
    }
    int m, k;
    std::cin>>m;
    std::cin>>k;
    int day_prev=0;
    int day_next=0;
    std::string dest_prev;
    std::string destination;
    unsigned long long sum_prev;
    std::string test;
    for(int i=0; i<k; i++){
        std::cin>>day_next>>person>>destination;
        if(count.count((my_set.begin())->second)) {
            count[my_set.begin()->second] += day_next - day_prev;
        }
        else{
            count[my_set.begin()->second] = day_next - day_prev;
        }
        dest_prev=billionaires[person].first;
        sum_prev=cities[dest_prev];
        my_set.erase(make_pair(sum_prev, dest_prev));
        my_set.insert(make_pair(sum_prev-billionaires[person].second, dest_prev));
        if(cities.count(destination)) {
            my_set.erase(make_pair(cities[destination], destination));
            my_set.insert(make_pair(cities[destination] + billionaires[person].second, destination));
        }
        else{
            my_set.insert(make_pair(billionaires[person].second, destination));
        }
        billionaires[person].first=destination;
        cout<<i<<"\n";
        for(auto it = my_set.begin(); it!=my_set.end(); it++){
            cout<<it->first<<" "<<it->second<<"\n";
        }
        cities[dest_prev]-=billionaires[person].second;
        if(cities.count(destination)) {
            cities[destination] += billionaires[person].second;
        }
        else{
            cities[destination]=billionaires[person].second;
        }
        day_prev=day_next;

    }


    return 0;
}
