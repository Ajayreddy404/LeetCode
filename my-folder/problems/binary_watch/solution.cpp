int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;
    else
        return 1 + countSetBits(n & (n - 1));
}

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> output;
        if(turnedOn > 8 || turnedOn < 0) //invalid turnOn
            return output;
        for(int hours = 0; hours < 12; hours++){
            for(int minutes = 0; minutes<60; minutes++){
                if(countSetBits(hours) + countSetBits(minutes) == turnedOn){
                    string time = to_string(hours) + ':';
                    if(minutes<10)
                            time += "0";
                    time += to_string(minutes);
                    output.push_back(time);
                }
            }
        }
        return output;
    }
};