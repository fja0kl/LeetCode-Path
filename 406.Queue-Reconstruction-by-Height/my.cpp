/**
 * 1. 排序：先对第二关键字升序排序，再按第一关键字升序排序；
 * 2. 循环，按照数目和高度调整位置
 */
class Solution {    
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        if(people.empty()) return res;
        sort(people.begin(), people.end(), myComp);//自定义的比较函数必须为static；否则sort算法会报错
        for(int i=1; i<people.size(); i++){
            if(people[i].second == people[i-1].second) continue;
            
            int cnt = 0, j = 0;
            
            for(;j<i;j++){//遍历之前的元素，计数：大于等于当前高度的个数；
                if(people[j].first >= people[i].first){
                    cnt++;
                    if(cnt == people[i].second)//等于了，退出循环
                        break;
                }
            }

            if(j+1 < i){//判断之后是还有大于的元素：如果j+1 == i，说明没有了；j在没有增加到i时，就退出了
                //后移
                pair<int,int> temp = people[i];
                int t = i;
                for(;t>j+1;t--){//确定移动位置
                    if(people[t-1].second != temp.second)//如果元素和当前元素的数目不相等时，移动
                        people[t] = people[t-1];
                    else //相等，退出循环，找到了移动的位置----当第二元素相同时，第一元素小的一定在前面
                        break;
                }
                    
                people[t] = temp;
            }
            
        }
        
        return people;
    }
    static bool myComp(pair<int,int> a,pair<int,int> b){//自定义比较函数：默认a在前，b在后；
        //先按第二关键字排序(升序)，再按第一关键字排序(升序)
        if(a.second < b.second) return true;
        else if(a.second == b.second){
	    return a.first < b.first;
            //if(a.first < b.first)
              //  return true;
            //return false;
        }
        else
            return false;
    }
};
