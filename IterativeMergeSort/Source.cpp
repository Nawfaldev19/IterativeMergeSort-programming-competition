#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> MergeSorted(vector<int>& vect1, vector<int>& vect2)
{
	vector<int> resVect(vect1.size() + vect2.size());
	int i = 0, j = 0;
	bool vect1Completed = false, vect2Completed = false;
	for (int m = 0; m < resVect.size(); m++)
	{
		if (i == vect1.size())
		{
			vect1Completed = true;
		}
		else if (j == vect2.size())
		{
			vect2Completed = true;
		}
		if (vect2Completed || (!vect1Completed && vect1[i] <= vect2[j]))
		{
			resVect[m] = vect1[i++];
		}
		else
		{
			resVect[m] = vect2[j++];
		}
	}

	return resVect;
}

queue<vector<int>> SaparateVectorInSubVectors(vector<int>&vect)
{
	queue<vector<int>> queueVect;
	for (int i = 0; i < vect.size(); i++)
	{
		vector<int> tempVect;
		tempVect.push_back(vect[i]);
		queueVect.push(tempVect);
	}
	return queueVect;
}

void IterativeMergeSort(vector<int>& vect)
{
	queue<vector<int>> saparatedVects = SaparateVectorInSubVectors(vect);
	while (saparatedVects.size() != 1)
	{
		vector<int>vect1 = saparatedVects.front();
		saparatedVects.pop();
		vector<int>vect2 = saparatedVects.front();
		saparatedVects.pop();
		saparatedVects.push(MergeSorted(vect1, vect2));
	}
	vect.clear();
	vect=saparatedVects.front();
}

void PrintVector(vector<int>& vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;
}
 
int main()
{
	vector<int>arr { 10,2,4,7,6,5,8,9,0 };
	IterativeMergeSort(arr);
	PrintVector(arr);
}