#include <iostream>
#include <vector>
#include <algorithm>
std::string to_str(int x){
    std::string s="";
    if (x>=10)
    {
        int h =x/10;
        int j =x%10;
        char s1=h+'0';
        char s2=j+'0';
        s+=s1;
        s+=s2;
    }
    else
    {
        int j =x%10;
        char s1='0';
        char s2=j+'0';
        s+=s1;
        s+=s2;
    }
    return s;
}
int main() {
    int num_clock;
    std::cin>>num_clock;
    int h, m, s;
    std::string str;
    std::vector<int> time(num_clock);
    for (int i=0; i<num_clock; i++){
        std::cin>>str;
        if(str[2]==':') {
            h = (str[0] - '0') * 10 + (str[1] - '0');
            m = (str[3] - '0') * 10 + (str[4] - '0');
            s = (str[6] - '0') * 10 + (str[7] - '0');
        }
        else
        {
            h =  str[0] - '0';
            m = (str[2] - '0') * 10 + (str[3] - '0');
            s = (str[5] - '0') * 10 + (str[6] - '0');
        }
        time[i]=s+60*m +3600*h;
    }
    std::sort(time.begin(), time.end());
    int difference_min=0;
    for(int i=1; i<num_clock; i++){
        difference_min+=(12*60*60 -(time[i]-time[0]));
    }
    int current_difference=0;
    int necessary_time;
    int last_difference=difference_min;
    for(int i=1; i<num_clock; i++){
        current_difference = last_difference + abs(time[i]-time[i-1])*(num_clock-1) - (12*60*60-abs(time[i]-time[i-1]));
        last_difference=current_difference;
        if(current_difference<difference_min) {
            difference_min = current_difference;
            necessary_time = time[i];
        }
    }
    int h_result, m_result, s_result;
    h_result=necessary_time/3600;
    m_result=(necessary_time - 3600*h_result)/60;
    s_result= necessary_time - 3600*h_result -60*m_result;
    std::string new_m =to_str(m_result);
    std::string new_s =to_str(s_result);
    std::cout<<h_result<<":"<<new_m<<":"<<new_s;
    return 0;
}
