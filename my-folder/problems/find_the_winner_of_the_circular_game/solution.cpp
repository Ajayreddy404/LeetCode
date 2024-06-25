class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> st;
        for(int i=1; i<=n; i++){
            st.insert(i);
        }
        auto itr = st.begin();

        while(st.size()>1){
            int t = k;
            while(--t){
                itr++;
                if(itr==st.end())   itr = st.begin();
            }
            auto temp = itr;
            itr++;
            if(itr==st.end())   itr = st.begin();
            st.erase(temp);
        }
        return *st.begin();
    }
};