bool byFirst(vector<int> &v1, vector<int> &v2){
    return v1[1] > v2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),byFirst);
        int units = 0;
        for(int i=0; i<(int)boxTypes.size() && truckSize > 0; i++){
            if(boxTypes[i][0] <= truckSize){
                units += (boxTypes[i][0]*boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
            else{
                units += (truckSize*boxTypes[i][1]);
                truckSize = 0;
            }
        }
        return units;
    }
};