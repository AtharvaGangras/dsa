int helper2(vector<int> &v, int target, int index)
{
    if(index>=v.size()) return -1;
    if(v[index] == target) return 1;
    return helper2(v,target,index+1);
}