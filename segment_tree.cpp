#include<vector>
template<typename T>
struct SegmentTree
{
	//only change this function
	T calculateValue(T a, T b)
	{
		return max(a,b);
	}
	
	std::vector<T> tree;
	T* arr;
	int size,treeSize;
	SegmentTree(T* in, T* inEnd)
	{
		size=inEnd-in;
		arr=in;
		for(treeSize=1;treeSize<2*size;treeSize*=2);
		tree.resize(treeSize);
		recursionMake(0,size-1,0);
	}
	void recursionMake(int start, int end, int index)
	{
		
		if(start==end)
		{
			tree[index]=arr[start];
		}
		else
		{
			int mid=(start+end)/2;
			recursionMake(start,mid,2*index+1);
			recursionMake(mid+1,end,2*index+2);	
			tree[index]=calculateValue(tree[2*index+1],tree[2*index+2]);
		}
	}
	int low, high;
	bool inited;
	T ans;
	void recursionGet(int start, int end, int index)
	{
		if(start>=low&&end<=high)
		{
			if(inited)
				ans=calculateValue(ans,tree[index]);
			else
			{
				ans=tree[index];
				inited=true;
			}
		}
		else if(!(start>high||end<low))
		{
			int tempMid=(start+end)/2;
			if(low>=tempMid+1)
			{
				recursionGet(tempMid+1,end,2*index+2);
			}
			else if(high<=tempMid)
			{
				recursionGet(start,tempMid,2*index+1);
			}
			else
			{
				recursionGet(start,tempMid,2*index+1);
				recursionGet(tempMid+1,end,2*index+2);
			}
		}
	}
	T query(int start, int end)
	{
		low=start;
		high=end;
		inited=false;
		recursionGet(0,size-1,0);
		return ans;
	}
};
