#include<vector>
template<typename T>
struct SegTree
{
	//only change this function
	T calValue(T a, T b)
	{
		return a+b;
	}
	
	int size,root,mid,counter=0;
	struct node
	{
		T value;
		int low,high;
		int left=-1;
		int right=-1;
	};
	std::vector<node> tree;
	SegTree(T* in, T* inEnd)
	{
		size=inEnd-in;
		tree.resize(size);
		for(int i=0;i<size;i++)
		{
			tree[i].low=tree[i].high=i;
			tree[i].value=in[i];
		}
		counter=size-1;
		root=makeTree(0,size-1);
	}
	int makeTree(int start, int end)
	{
		mid=(start+end)/2;
		if(start!=end)
		{
			node temp;
			temp.low=start;
			temp.high=end;
			temp.left=makeTree(start,mid);
			temp.right=makeTree(mid+1,end);
			temp.value=calValue(tree[temp.left].value,tree[temp.right].value);
			tree.push_back(temp);
			counter++;
			return counter;
		}
		return start;
	}
	int low, high;
	T rget(int index)
	{
		if(tree[index].low==low&&tree[index].high==high)
			return tree[index].value;
		else
		{
			return calValue(rget(tree[index].left),rget(tree[index].right));
		}
	}
	T query(int start, int end)
	{
		low=start;
		high=end;
		return rget(root);
	}
};

