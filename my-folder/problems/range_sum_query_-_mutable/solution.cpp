class NumArray {
public:
    int n;
    int t[400400];
    int arr[100100];

    void build(int index, int l, int r){
        if(l>r) return;
        if(l==r){
            t[index] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(index*2, l, mid);
        build(index*2 + 1, mid+1, r);
        t[index] = t[2*index] + t[2*index + 1];
        return;
    }

    NumArray(vector<int>& nums) 
    {   // build segment tree
        n = nums.size();
        for(int i=0; i<n; i++)
            arr[i] = nums[i];
        //arr = nums;
        //t = vector<int>(4*n);

        build(1, 0 ,n-1);
    }
    
    void update2(int index, int l, int r, int x, int v){
        if(x<l || x>r)  return;
        if(l==r){
            t[index] = v;
            arr[l] = v;
            return;
        }
        int mid = (l+r)/2;
        update2(2*index, l, mid, x, v);
        update2(2*index + 1, mid+1, r, x, v);
        t[index] = t[2*index] + t[2*index + 1];
        return;
    }

    void update(int index, int val) {
        update2(1, 0, n-1, index, val);    // update the value
    }
    
    int query(int index, int l, int r, int lq, int rq)
    {
        if(rq<l || lq>r)    
            return 0;
        if(lq<=l && r<=rq)
        {
            return t[index];
        }
        int mid = (r+l)/2;

        return query(2*index, l, mid, lq, rq) + query(2*index+1, mid+1, r, lq, rq);
    }
    int sumRange(int left, int right) {     // query of l to r
        int ans = query(1,0,n-1,left,right);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */