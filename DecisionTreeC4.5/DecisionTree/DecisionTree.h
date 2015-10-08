#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

#include "Tree.h"
using namespace std;

class DecisionTree {
private:

	struct attrItem
	{
		std::vector<int>  itemNum;		//	itemNum[0] = itemLine.size()
										//	itemNum[1] = decision num	true的数目
		set<int>		  itemLine;		// 包含此属性的行号 [8/27/2015 wangxy]
	};

	struct attributes
	{
		string attriName;
		vector<double> statResult;
		map<string, attrItem*> attriItem;
	}; 

	vector<attributes*> m_vStatTree;
	vector<vector<string>> m_vInfos;		// srcdata [8/27/2015 wangxy]

	map<string, int> m_mAttr_clum;			// 存表头 string:列名 int:列号 [8/27/2015 wangxy]
	int m_nAttriNum;						// 属性有多少列 [8/27/2015 wangxy]
	
public:
	DecisionTree(){
		m_nAttriNum = 0;
	}
	vector<vector<string>>& getInfos()
	{
		return m_vInfos;
	}
	vector<attributes*>& getStatTree()
	{
		return m_vStatTree;
	}
	int pretreatment(string filename, set<int>& readLineNum, vector<int>& readClumNum);
	int statister(vector<vector<string>>& infos, vector<attributes*>& statTree, 
					set<int>& readLine, vector<int>& readClumNum);
	int compuDecisiNote(vector<attributes*>& statTree, int deciNum, int lineNum, vector<int>& readClumNum);
	double info_D(int deciNum, int sum);
	void resetStatTree(vector<attributes*>& statTree, vector<int>& readClumNum);
	double Info_attr(map<string, attrItem*>& attriItem, double& splitInfo, int lineNum);
	void CreatTree(TreeNode* treeHead, vector<attributes*>& statTree, vector<vector<string>>& infos,
				  set<int>& readLine, vector<int>& readClumNum, int deep);
};
