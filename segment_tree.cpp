#include<vector>
template<typename T>
struct SegTree
{
	//only change this function
	T calValue(T a, T b)
	{
		return max(a,b);
	}
	
	std::vector<T> tree;
	T* arr;
	int size,treeSize;
	SegTree(T* in, T* inEnd)
	{
		size=inEnd-in;
		arr=in;
		for(treeSize=1;treeSize<2*size;treeSize*=2);
		tree.resize(treeSize);
		makeTree(0,size-1,0);
	}
	void makeTree(int start, int end, int index)
	{
		
		if(start==end)
		{
			tree[index]=arr[start];
		}
		else
		{
			int mid=(start+end)/2;
			makeTree(start,mid,2*index+1);
			makeTree(mid+1,end,2*index+2);	
			tree[index]=calValue(tree[2*index+1],tree[2*index+2]);
		}
	}
	int low, high;
	bool inited;
	T ans;
	void rget(int start, int end, int index)
	{
		if(start>=low&&end<=high)
		{
			if(inited)
				ans=calValue(ans,tree[index]);
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
				rget(tempMid+1,end,2*index+2);
			}
			else if(high<=tempMid)
			{
				rget(start,tempMid,2*index+1);
			}
			else
			{
				rget(start,tempMid,2*index+1);
				rget(tempMid+1,end,2*index+2);
			}
		}
	}
	T query(int start, int end)
	{
		low=start;
		high=end;
		inited=false;
		rget(0,size-1,0);
		return ans;
	}
};
